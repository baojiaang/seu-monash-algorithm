// hw8.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
using namespace std;
class Solution{
public:
pair<int, int> maxDecli(vector<int>& nums) {
    int sum = 0;
    vector<int> visited(nums.size(), 0);
    int max_v = maxDecline(nums, visited);
    int cnt = 1;
    sum += max_v;
    while (sum < nums.size()) {
        sum += maxDecline(nums, visited);
        cnt++;
    }
    return { max_v, cnt };
}

int maxDecline(vector<int>& nums, vector<int>& visited) {
    vector<int> f(nums.size(), 0);
    vector<int> pr_v(nums.size(), -1);
    int num_cnt = 0;
    int max_v = 0;
    int max_p = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (visited[i]) continue;
        int pre = findFirstBigger(nums, i, f, visited);
        if (pre == -1) {
            f[i] = 1;
            pr_v[i] = -1;
        }
        else {
            f[i] = f[pre] + 1;
            pr_v[i] = pre;
        }
        if (f[i] > max_v) {
            max_v = f[i];
            max_p = i;
        }
    }
    markVisited(visited, pr_v, max_p);
    return max_v;
}

int findFirstBigger(vector<int>& nums, int pos, vector<int>& f, vector<int>& visited) {
    int target = nums[pos], min_pos = -1, min_bigger = 0;
    pos--;
    while (pos >= 0) {
        if (visited[pos]) {
            pos--;
            continue;
        };
        if (nums[pos] >= target) {
            if (f[pos] > min_bigger) {
                min_pos = pos;
                min_bigger = f[pos];
            }
        }
        pos--;
    }
    return min_pos;
}

void markVisited(vector<int>& visited, vector<int>& pr_v, int pos) {
    while (pos != -1) {
        visited[pos] = 1;
        pos = pr_v[pos];
    }
}

void intputNumLine(vector<int>& nums) {
    int row_num;
    cin >> row_num;;
    int n = 0;
    for (int j = 0; j < row_num; j++) {
        cin >> n;
        nums.push_back(n);
    }
}
};

int main()
{
    Solution s;
    int k;
    cin >> k;
    vector<pair<int, int>> ans;
    for (int i = 0; i < k; i++) {
        vector<int> nums;
        s.intputNumLine(nums);
        ans.push_back(s.maxDecli(nums));
    }
    for (auto i : ans) {
        cout << i.first << " " << i.second << endl;
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
