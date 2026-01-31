
#include<iostream>
using namespace std;

// 数组大小定义为201（下标1~200），满足题目需求
const int MAX_SIZE = 201;
int aa[MAX_SIZE];  // 记录每个位置到达的最少步数，-1表示未访问
int cc[MAX_SIZE];  // 记录每个位置的移动步长

int main() {
    int n, a, b;
    cin >> n >> a >> b;

    // 1. 初始化数组
    for (int i = 1; i <= MAX_SIZE - 1; i++) {  // 避免越界，只初始化到200
        aa[i] = -1;
    }
    for (int i = 1; i <= n; i++) {  // 输入n个位置的移动步长（1~n）
        cin >> cc[i];
    }

    // 2. BFS队列初始化（用数组模拟队列，head=队头，tail=队尾）
    int queue[MAX_SIZE];
    int head = 1, tail = 1;
    // 起点入队，标记步数为0（已访问）
    queue[tail++] = a;
    aa[a] = 0;

    // 3. 核心BFS逻辑
    int res = -1;
    while (head < tail) {  // 队列不为空（head < tail 表示队列有元素）
        int current = queue[head++];  // 取出队头元素，队头后移

        // 终止条件：找到终点b，直接记录结果并退出循环
        if (current == b) {
            res = aa[current];
            break;
        }

        // 计算两种移动方向：+cc[current] 和 -cc[current]
        int next1 = current + cc[current];
        int next2 = current - cc[current];

        // 处理方向1：next1在1~n范围内，且未被访问过
        if (next1 >= 1 && next1 <= n && aa[next1] == -1) {
            aa[next1] = aa[current] + 1;  // 步数+1
            queue[tail++] = next1;        // 入队
        }

        // 处理方向2：next2在1~n范围内，且未被访问过
        if (next2 >= 1 && next2 <= n && aa[next2] == -1) {
            aa[next2] = aa[current] + 1;  // 步数+1
            queue[tail++] = next2;        // 入队
        }
    }

    // 4. 输出结果
    cout << res << endl;
    return 0;
}