//problem:https://www.luogu.com.cn/problem/P1825

#include<iostream>
#include<queue>
#include<string>
using namespace std;
#define N 350

struct point {
	int x;
	int y;
    int t;
};
queue<point>que;
char a[N][N];
bool vis[N][N];
int dx[5] = { 0,0,1,0,-1 };
int dy[5] = { 0,1,0,-1,0 };
int sx, sy;
int n, m;

void Go(int&cx,int&cy) {
	for (int i = 1;i <= n;i++)
	{
		for (int j = 1;j <= m;j++)
		{
			if (a[i][j] == a[cx][cy] && (i != cx || j != cy))//如果a[i][j]这个点的是一个与a[nx][ny]相同的传送门，并且a[i][j]与a[nx][ny]不是同一个点
			{
				cx = i;
				cy = j;
				return;
			}
		}
	}
}
int main() {
	
	cin >> n >> m;
	string s;

	for (int i = 1;i <= n;i++) {
		cin >> s;
		for (int j = 1;j <= m;j++) {
			a[i][j] = s[j - 1];
			if (a[i][j] == '@') {
				sx = i;sy = j;
			}
		}
	}
	point f = {sx,sy,0};
	que.push(f);
	while (!que.empty()) {
		f = que.front();
		que.pop();
		if (a[f.x][f.y] == '=') {
			cout << f.t;
			return 0;
		}
		if (a[f.x][f.y] >= 'A' && a[f.x][f.y] <= 'z') {
			Go(f.x, f.y);
		}
		for (int i = 1;i <= 4;i++) {
			int nx = f.x + dx[i];
			int ny = f.y + dy[i];
			if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && a[nx][ny] != '#' && vis[nx][ny] == false) {
				point g = { nx,ny,f.t + 1 };
				que.push(g);
				vis[nx][ny] = true;
			}
		}
	}

}
