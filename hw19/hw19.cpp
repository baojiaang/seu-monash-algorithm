// hw19.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int zeroOnePack(vector<pair<int, int>>& items,int n,int capacity) {
        int dp[501]{};
        for (int i = 1; i <= n; i++) {
            for (int j = capacity; j >= items[i - 1].first; j--) { //自顶向下
                dp[j] = max(dp[j], dp[j - items[i - 1].first] + items[i - 1].second);
            }
        }
        return dp[capacity];
    }
};
int main()
{
    int m;
    cin >> m;
    vector<int> result;
    Solution s;
    for (int i = 0; i < m; i++) {
        int n;
        cin >> n;
        int capacity;
        cin >> capacity;
        vector<pair<int, int>> items;
        for (int j = 0; j < n; j++) {
            int size;
            cin >> size;
            int value;
            cin >> value;
            items.push_back(make_pair(size, value));
        }
        int res = s.zeroOnePack(items, n, capacity);
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
