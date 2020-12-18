// hw21.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
Description

两个矩阵A(r行s列)和B(s行t列)相乘, 乘法代价为r*s*t. 现给定N(N<=500)个矩阵连乘问题, 请计算最小乘法代价。

Input

第一行输入M(M<=10)表示有M组数据。每组数据第一行输入N，表示矩阵个数；接下来一行输入N个矩阵的行数和列数。

Output

输出M行正整数，第i行表示第i组数据的最小乘法代价。

和01背包问题一样，完全背包也可以用一维数组来保存数据。算法样式和01背包的很相似，唯一不同的是对V遍历时变为正序，而01背包为逆序。01背包中逆序是因为F[i][]只和F[i-1][]有关，且第i件的物品加入不会对F[i-1][]状态造成影响。而完全背包则考虑的是第i种物品的出现的问题，第i种物品一旦出现它势必应该对第i种物品还没出现的各状态造成影响。也就是说，原来没有第i种物品的情况下可能有一个最优解，现在第i种物品出现了，而它的加入有可能得到更优解，所以之前的状态需要进行改变，故需要正序。

状态方程为：dp[j] = max(dp[j],dp[j-items.size]+items.value)

完全背包问题
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
        int n, k;
        cin >> n >> k;
        vector<int> dp(n + 1, 0);
        vector<pair<int, int>> items;
        for (int i = 0; i < k; i++) {
            int l, p;
            cin >> l >> p;
            items.push_back(make_pair(l, p));
        }
        for (int i = 0; i < k; i++) {
            for (int j = items[i].first; j <= n; j++) {
                dp[j] = max(dp[j], dp[j - items[i].first] + items[i].second);
            }
        }
        result.push_back(dp[n]);
    }
    for (auto i : result)
        cout << i << endl;
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
