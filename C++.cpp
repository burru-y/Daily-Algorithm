#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

// 定义方向数组：上下左右4个方向
const int dx[4] = { 0, 1, 0, -1 };
const int dy[4] = { 1, 0, -1, 0 };
// 最大坐标是300，为了保险开稍大一点；INF表示永远不会被摧毁
const int MAXN = 305;
const int INF = 0x3f3f3f3f;

// time[x][y]：格子(x,y)被摧毁的最早时间
int time_[MAXN][MAXN];
// visited[x][y]：标记格子(x,y)是否已经被访问过（避免重复入队）
bool visited[MAXN][MAXN];

// 队列中存储的是（x坐标，y坐标，到达该坐标的时间）
struct Node {
    int x, y, t;
    Node(int x_, int y_, int t_) : x(x_), y(y_), t(t_) {}
};

int main() {
    int M;
    cin >> M;

    // 步骤1：初始化摧毁时间矩阵，全部设为INF（永远不会被摧毁）
    memset(time_, 0x3f, sizeof(time_));

    // 步骤2：填充流星摧毁的格子及其相邻格的最早摧毁时间
    for (int i = 0; i < M; ++i) {
        int X, Y, T;
        cin >> X >> Y >> T;
        // 先更新当前流星撞击的格子(X,Y)
        if (T < time_[X][Y]) {
            time_[X][Y] = T;
        }
        // 再更新上下左右4个相邻格子
        for (int j = 0; j < 4; ++j) {
            int nx = X + dx[j];
            int ny = Y + dy[j];
            // 相邻格子必须满足x,y ≥ 0（才会被流星摧毁，负数坐标无意义）
            if (nx >= 0 && ny >= 0) {
                if (T < time_[nx][ny]) {
                    time_[nx][ny] = T;
                }
            }
        }
    }

    // 步骤3：BFS 搜索最短路径
    queue<Node> q;
    // 初始化访问数组
    memset(visited, false, sizeof(visited));

    // 特判：起点(0,0)在时刻0是否安全（time_[0][0] > 0）
    if (time_[0][0] > 0) {
        q.push(Node(0, 0, 0));
        visited[0][0] = true;
    }

    int ans = -1;
    while (!q.empty()) {
        Node curr = q.front();
        q.pop();

        int x = curr.x;
        int y = curr.y;
        int t = curr.t;

        // 关键：如果当前格子永远不会被摧毁，找到安全区域，返回当前时间
        if (time_[x][y] == INF) {
            ans = t;
            break;
        }

        // 遍历4个方向，尝试移动
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nt = t + 1; // 移动后时间加1

            // 条件1：坐标合法（x,y ≥ 0，无上限，因为可以走出300以外的安全区域）
            // 条件2：该格子未被访问过
            // 条件3：移动后的时间nt 小于 该格子的摧毁时间（即移动后在该格子是安全的）
            if (nx >= 0 && ny >= 0 && !visited[nx][ny] && nt < time_[nx][ny]) {
                visited[nx][ny] = true;
                q.push(Node(nx, ny, nt));
            }
        }
    }

    // 输出结果
    cout << ans << endl;

    return 0;
}