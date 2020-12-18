// hw25.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
Description

给定一个长度为N的整数数组, 请计算该数组中最长非降了序列长度。

Input

第一行输入M(M<=10)表示有M组数据。每组数据输入N(N<=10000), 接下来输入N个整数。

Output

输出M行正整数，第i行表示第i组数据的长非降了序列长度。


动态规划，用dp数组来记录在第i个数字时，前多少个数字比nums[i] 小或等于, 遍历完i-1个 i前面的数字后，如果dp[i]>length， 则更新length
初始化dp = 1
如果nums[i] >= nums[j] 时
dp[i] = max(dp[i],dp[j]+1)

*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int m;
    cin >> m;
    vector<int> result;
    for (int round = 0; round < m; round++) {
        int n;
        cin >> n;
        int length = 0;
        int dp[10001]{}; // 有多少个数比第i个数小或等
        for (int i = 0; i < 10001; i++) {
            dp[i] = 1;
        }
        int nums[10001]{};
        for (int i = 0; i < n; i++) {
            int num;
            cin >> num;
            nums[i] = num;
        }
        for (int i = 0; i < n; i++) {
            for (int j = i-1 ; j >= 0; j--) {
                if (nums[i] >= nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            if (dp[i] > length) {
                length = dp[i];
            }
        }
        result.push_back(length);
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
