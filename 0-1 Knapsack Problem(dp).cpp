#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    // ===== 01背包模板核心变量 =====
    int n;  // 物品总数
    int C;  // 背包总容量
    cin >> n >> C;

    // 物品的重量数组（w[1]~w[n]）
    vector<int> w(n + 1, 0);
    // 物品的价值数组（v[1]~v[n]）
    vector<int> v(n + 1, 0);

    // 输入每个物品的重量和价值
    for (int i = 1; i <= n; ++i) {
        cin >> w[i] >> v[i];
    }

    // ===== 定义一维DP数组并初始化 =====
    // dp[j]：背包容量为j时，能装下的最大价值
    vector<int> dp(C + 1, 0);  // 初始全为0，符合要求

    // ===== 核心：填充一维DP数组（逆序遍历是关键！）=====
    for (int i = 1; i <= n; ++i) {  // 遍历每一个物品
        // 逆序遍历背包容量：从总容量C到当前物品重量w[i]
        // 目的：避免同一个物品被重复选取（保证用到的是上一轮未处理当前物品的dp值）
        for (int j = C; j >= w[i]; --j) {
            // 状态转移方程：选「不装该物品」或「装该物品」的最大值
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }

    // ===== 输出结果 =====
    cout << "背包的最大价值为：" << dp[C] << endl;

    return 0;
}
