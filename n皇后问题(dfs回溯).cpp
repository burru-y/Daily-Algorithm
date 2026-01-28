#include <iostream>
#include<vector>
using namespace std;
void put_queen(int x, int y, vector<vector<int>>& attack) {
	static const int dx[] = { -1,1,0,0,-1,-1,1,1 };
	static const int dy[] = { 0,0,-1,1,-1,1,-1,1 };
	attack[x][y] = 1;
	for (int i = 1;i < attack.size();i++) {
		for (int j = 0;j < 8;j++) {
			int nx = x + i * dx[j];
			int ny = y + i * dy[j];
			if (nx >= 0 && nx < attack.size() && ny >= 0 && ny < attack.size()) {
				attack[nx][ny] = 1;
			}
		}
	}
}
void backtrack(int k, int n, vector<string>& queen,
	vector<vector<int>>& attack,
	vector<vector<string>>& solve) {
	if (k == n) {
		solve.push_back(queen);
		return; 
	}
	for (int i = 0;i < n;i++) {
		if (attack[k][i] == 0) {
			vector<vector<int>>tmp = attack;
			queen[k][i] = 'Q';
			put_queen(k, i, attack);
			backtrack(k + 1, n, queen, attack, solve);
			attack = tmp;
			queen[k][i] = '.';
		}
	}
}
vector<vector<string>>solveNQueens(int n) {
	vector<vector<string>>solve;
	vector<vector<int>>attack;
	vector<string>queen;
	for (int i = 0;i < n;i++) {
		attack.push_back((std::vector<int>()));
		for (int j = 0;j< n;j++) {
			attack[i].push_back(0);  
		}
		queen.push_back("");
		queen[i].append(n, '.');
	}
	backtrack(0, n, queen, attack, solve);
	return solve;
}
int main() {
	vector<vector<string>>result;
	int n;scanf_s("%d", &n);
	result = solveNQueens(n);
	printf("%d皇后共有%zd种解法：\n\n",n, result.size());

	for (int i = 0;i < result.size();i++) {
		printf("解法%d:\n", i + 1);
		for (int j = 0;j < result[i].size();j++) {
			printf("%s\n", result[i][j].c_str());
		}
		printf("\n");
	}
	return 0;

}
