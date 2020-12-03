// hw13.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<vector>
using namespace std;
class Solution {
public:
public:
    vector<int> oneLine(int num) {
        vector<int> line;
        for (int i = 0; i < num; i++) {
            int temp;
            cin >> temp;
            line.push_back(temp);
        }
        return line;
    }
    int InversePairs(vector<int> data) {
        if (data.size() == 0) {
            return 0;
        }
        // 排序的辅助数组
        vector<int> copy;
        for (int i = 0; i < data.size(); ++i) {
            copy.push_back(data[i]);
        }
        return InversePairsCore(data, copy, 0, data.size() - 1) % 1000000007;
    }
    long InversePairsCore(vector<int>& data, vector<int>& copy, int begin, int end) {
        // 如果指向相同位置，则没有逆序对。
        if (begin == end) {
            copy[begin] = data[end];
            return 0;
        }
        // 求中点
        int mid = (end + begin) >> 1;
        // 使data左半段有序，并返回左半段逆序对的数目
        long leftCount = InversePairsCore(copy, data, begin, mid);
        // 使data右半段有序，并返回右半段逆序对的数目
        long rightCount = InversePairsCore(copy, data, mid + 1, end);

        int i = mid; // i初始化为前半段最后一个数字的下标
        int j = end; // j初始化为后半段最后一个数字的下标
        int indexcopy = end; // 辅助数组复制的数组的最后一个数字的下标
        long count = 0; // 计数，逆序对的个数，注意类型

        while (i >= begin && j >= mid + 1) {
            if (data[i] > data[j]) {
                copy[indexcopy--] = data[i--];
                count += j - mid;
            }
            else {
                copy[indexcopy--] = data[j--];
            }
        }
        for (; i >= begin; --i) {
            copy[indexcopy--] = data[i];
        }
        for (; j >= mid + 1; --j) {
            copy[indexcopy--] = data[j];
        }
        return leftCount + rightCount + count;
    }

};
int main()
{
    Solution s;
    int n_line;
    cin >> n_line;
    vector<int> result;
    for (int i = 0; i < n_line; i++) {
        int n_item;
        cin >> n_item;
        vector<int> line = s.oneLine(n_item);
        int res = s.InversePairs(line);
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
