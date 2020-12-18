// hw27.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
Description

给定n个活动，活动ai表示为一个三元组(si,fi,vi)，其中si表示活动开始时间，fi表示活动的结束时间，vi表示活动的权重,
si<fi。带权活动选择问题是选择一些活动，使得任意被选择的两个活动ai和aj执行时间互不相交，即区间[si,fi)与[sj,fj)
互不重叠，并且被选择的活动的权重和最大。请设计一种方法求解带权活动选择问题。


Input

第一行输入M(M<=10)表示有M组数据。每组数据输入整数N(N<=10000), 接下来输入N个活动。

Output

输出M行正整数，第i行表示第i组数据的能够选择活动最大权值和。

动态规划
先对活动结束时间进行排序

dp[i] 表示第i时刻的最大值
从第一(i: 0 - n-1)个活动开始，再从0(j: 0 - 最晚时间)时刻开始


if j >= a[i].end
dp[j] = max(dp[j],dp[a[i].start]+a[i].val

*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Activity {
public:
    int start;
    int end;
    int value;

    Activity(int start,int end, int value) {
        this->start = start;
        this->end = end;
        this->value = value;
    }
};
bool compare(Activity a, Activity b) {
    return a.end < b.end;
}
int main()
{
    int m;
    cin >> m;
    vector<int> result;
    for (int round = 0; round < m; round++) {
        vector<Activity> activites;
        int n;
        cin >> n;
        int f=0;
        for (int i = 0; i < n; i++) {
            int start, end, value;
            cin >> start >> end >> value;
            Activity a{ start,end,value };
            activites.push_back(a);
            f = max(f, end);
           
        }
        sort(activites.begin(), activites.end(), compare);
        int dp[10000]{};
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= f; j++)
            {
                if (j >= activites[i].end)
                    dp[j] = max(dp[j], dp[activites[i].start] + activites[i].value);
            }
        }
        result.push_back(dp[f]);
    }
    for (auto i : result) {
        cout<<i<<endl;
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
