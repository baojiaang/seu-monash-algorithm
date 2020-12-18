﻿// hw33.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool compare(pair<int,int> a,pair<int,int> b) {
    return a.second > b.second;
}
int main()
{
    int t;
    cin >> t;
    vector<long> result;
    for (int round = 0; round < t; round++) {
        long res = 0;
        int n;
        cin >> n;
        vector<pair<int,int>> record;
        int maxTime = 0;
        bool* used = new bool[n + 1];
        for (int i = 0; i < n + 1; i++) {
            used[i] = false;
        }
        for (int i = 0; i < n; i++) {
            int deadline;
            int value;
            cin >> deadline;
            cin >> value;
            maxTime = deadline;
            auto r = make_pair(deadline, value);
            record.push_back(r);
        }
        sort(record.begin(), record.end(),compare);
        for (int i = 0; i < n; i++) {
            int d = record[i].first;
            int v = record[i].second;
            for (int j = d; j > 0; j--) {
                if (used[j] == false) {
                    used[j] = true;
                    res += v;
                    break;
                }
            }
        }
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
