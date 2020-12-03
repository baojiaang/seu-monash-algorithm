// hw20.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int matrixChain(int n, vector<int>& p) {
        int dp[501][501]{};
        for (int r = 2; r <= n; r++) { //矩阵链长度
            for (int i = 1; i <= n - r + 1; i++) { //控制矩阵链起点
                int j = i + r - 1; // 矩阵链右端点
                dp[i][j] = dp[i + 1][j] + p[i - 1] * p[i] * p[j];
                for (int k = i + 1; k < j; k++) { // i+1 j-1区间之间遍历
                    int t = dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j];
                    if (t < dp[i][j]) // 如果小于dp[i][j]则更新
                        dp[i][j] = t;
                }
            }
        }
        return dp[1][n];
    }
private:

};


int main()
{
    Solution s;
    vector<int> result;
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int n;
        cin >> n;
        vector<int> p;
        int first;
        cin >> first;
        p.push_back(first);
        for (int j = 0; j < n-1; j++) {
            int num;
            cin >> num;
            p.push_back(num);
            int second;
            cin >> second;
        }
        int last;
        cin >> last;
        p.push_back(last);
        int res = s.matrixChain(n, p);
        result.push_back(res);
    }
    for (auto i : result) {
        cout << i << endl;
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
