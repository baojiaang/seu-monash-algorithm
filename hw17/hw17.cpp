// hw17.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:

    int mergeCount(vector<int>& nums, int start, int end) {
        if (start >= end - 1) return 0;
        int mid = start + (end - start) / 2;
        int sum = 0;
        sum += mergeCount(nums, start, mid);
        sum += mergeCount(nums, mid, end);
        sum += mergeC(nums, start, mid, end);
        return sum;
    }

    int mergeC(vector<int>& nums, int start, int mid, int end) {
        vector<int> left, right;
        left.insert(left.begin(), nums.begin() + start, nums.begin() + mid);
        right.insert(right.begin(), nums.begin() + mid, nums.begin() + end);
        int p = start;
        int ans = 0;
        int l = 0, r = 0;
        while (l < left.size() && r < right.size()) {
            if (left[l] < right[r]) {
                nums[p++] = left[l++];
                ans += r;
            }
            else nums[p++] = right[r++];
        }
        while (l < left.size()) {
            nums[p++] = left[l++];
            ans += r;
        }
        while (r < right.size()) nums[p++] = right[r++];
        return ans;
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
        vector<int> pairs;
        for (int j = 1; j <=n; j++) {
            int num;
            cin >> num;
            pairs.push_back(num);
        }
        result.push_back(s.mergeCount(pairs,0,n));
    }
    
    for (auto i : result) {
        cout << i << endl;
    }
   
    return 0;
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
