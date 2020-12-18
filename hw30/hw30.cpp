// hw30.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
给定直线上2n个点的序列P[1,2,… ,2n]，每个点P[i]要么是白点要么是黑点，其中共有n个白点和n个黑点，
相邻两个点之间距离均为1，请设计一个算法将每个白点与一黑点相连，使得连线的总长度最小。例如，图中有
4个白点和4个黑点，以图中方式相连，连线总长度为1+1+1+5=8。

双栈，一个记录黑，一个记录白  加入时，若为黑点，白栈非空，弹出白栈里的点，算距离   白点同理
*/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int main()
{
    int m;
    cin >> m;
    vector<int> result;
    for (int round = 0; round < m; round++) {
        int n;
        cin >> n;
        stack<int> black;
        stack<int> white;
        int res = 0;
        for (int i = 0; i < 2 * n; i++) {
            int num;
            cin >> num;
            if (num == 0) {
                white.push(i);
                if (!black.empty()) {
                    int index = black.top();
                    int len = i - index;
                    res += len;
                    black.pop();
                    white.pop();
                }
            }
            else {
                black.push(i);
                if (!white.empty()) {
                    int index = white.top();
                    int len = i - index;
                    res += len;
                    black.pop();
                    white.pop();
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
