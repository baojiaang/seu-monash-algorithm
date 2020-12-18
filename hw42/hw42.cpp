// hw42.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
在一个火车旅行很受欢迎的国度，你提前一年计划了一些火车旅行。在接下来的一年里，你要旅行的日子将以一个名为 days 的数组给出。每一项是一个从 1 到 365 的整数。

火车票有三种不同的销售方式：

一张为期一天的通行证售价为 costs[0] 美元；
一张为期七天的通行证售价为 costs[1] 美元；
一张为期三十天的通行证售价为 costs[2] 美元。
通行证允许数天无限制的旅行。 例如，如果我们在第 2 天获得一张为期 7 天的通行证，那么我们可以连着旅行 7 天：第 2 天、第 3 天、第 4 天、第 5 天、第 6 天、第 7 天和第 8 天。

返回你想要完成在给定的列表 days 中列出的每一天的旅行所需要的最低消费。


dp[i] 表示到第i天最低消费

如果第i天要出行：
dp[i] = min(dp[i-1]+ cost[0],dp[i-7]+cost[1],dp[i-30]+cost[2])
不用出行：
dp[i]=dp[i-1]


*/
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
int main()
{
    int nums;
    cin >> nums;
    vector<int> result;
    for (int round = 0; round < nums; round++) {
        int m;
        set<int> days;
        int dp[366]{};
        cin >> m;
        for (int i = 0; i < m; i++) {
            int day;
            cin >> day;
            days.insert(day);
        }
        int cost[3]{};
        for (int i = 0; i < 3; i++) {
            int v;
            cin >> v;
            cost[i] = v;
        }
        for (int i = 1; i <= 365; i++) {
            int v1=0x7fffffff;
            if (i - 1 >= 0) {
                 v1 = dp[i - 1] + cost[0];
            }
            int v2 = 0x7fffffff;
            if (i - 7 >= 0) {
                 v2 = dp[i - 7] + cost[1];
            }
            else {
                v2 = dp[0] + cost[1];
            }
            int v3 = 0x7fffffff;
            if (i - 30 >= 0) {
                 v3 = dp[i - 30] + cost[2];
            }
            else {
                v3 = dp[0] + cost[2];
            }
            if (days.find(i) != days.end())
                dp[i] = min(min(v1, v2), v3);
            else
                dp[i] = dp[i - 1];
        }
        result.push_back(dp[365]);
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
