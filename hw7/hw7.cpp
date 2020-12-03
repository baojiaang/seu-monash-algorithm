// hw7.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector<int> result;
	for (int round = 0; round < n; round++) {
		int len;
		cin >> len;
		int k;
		cin >> k;
		vector<vector<int>> dp(k+1);
		for (int i = 0; i < k+1; i++) {
			dp[i].resize(len+1);
			cout << dp[i].size();
		}
		string str;
		cin >> str;
		int tmp = 0;
		for (int j = 1; j <= len; j++)
		{
			tmp = tmp * 10 + (str[j] - '0');
			//cout << dp[j].size();
			dp[j][0] = tmp;
			
		}
		for (int i = 1; i <= len; i++)
		{
			tmp = tmp * 10 + (str[i] - '0');
			dp[i][0] = tmp;
		}
		for (int i = 1; i <= len; i++)
		{
			for (int j = 1; j <= k; j++)
			{
				for (int w = 1; w < i; w++)
				{
					int tmp = 0;
					for (int jj = w + 1; jj <= i; jj++)
					{
						tmp = tmp * 10 + (str[jj] - '0');
					}
					dp[i][j] = max(dp[i][j], dp[w][j - 1] * tmp);
				}
			}
		}
		result[round] = dp[len][k];
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
