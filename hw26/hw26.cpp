// hw26.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int m;
	cin >> m;
	for (int round = 0; round < m; round++) {
		int n, k;
		cin >> n;
		cin >> k;
		vector<int> a(n + 1);
		long long sum[100][100];
		long long dp[100][100];
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		for (int i = 1; i <= n; i++) {
			for (int j = i; j <= n; j++) {
				int s = 0;
				for (int k = i; k <= j; k++)
					s += a[k];  
				sum[i][j] = s; // 初始化sum[i][j]为数组i到j的和
			}
		}
		for (int i = 1; i <= n; i++)
			dp[i][0] = sum[1][i]; // dp[i][0]为1到i中，乘号个数为0时，数组最大的结果
		for (int j = 1; j <= k; j++) { // j:乘号的数目
			for (int i = j + 1; i <= n; i++) { // 1 到 第i 个数
				dp[i][j] = -1;                  
				for (int k = j; k < i; k++)
					dp[i][j] = max(dp[i][j], dp[k][j - 1] * sum[k + 1][i]); //位置k处加入乘号
			}
		}
		cout << dp[n][k] << endl;
	}
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
