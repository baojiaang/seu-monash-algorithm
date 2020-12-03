// hw18.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int fullPacket(vector<vector<int>>& jewel, int V) {
    vector<vector<int>> f(jewel.size() + 1, vector<int>(V + 1, -1));
    f[0][0] = 0;
    for (int i = 1; i <= jewel.size(); i++) {
        for (int j = 0; j <= V; j++) {
            int curr_weight = jewel[i - 1][0];
            int curr_val = jewel[i - 1][1];
            if (j >= curr_weight && f[i - 1][j - curr_weight] != -1)
                f[i][j] = max(f[i - 1][j], f[i - 1][j - curr_weight] + curr_val);
            else f[i][j] = f[i - 1][j];
        }
    }
    if (f[jewel.size()][V] == -1) return 0;
    return f[jewel.size()][V];
}

int intputNumLine(vector<vector<int>>& nums) {
    vector<int> tmp;
    int n_num;
    cin >> n_num;
    int weight;
    cin >> weight;
    while (n_num-- > 0) {
        int n;
        cin >> n;
        int n1;
        cin >> n1;
        nums.push_back({ n, n1 });
    }
    return weight;
}
int main(void) {
    int k_line;
    cin >> k_line;
    vector<int> ans;
    while (k_line-- > 0) {
        vector<vector<int>> nums;
        auto weight = intputNumLine(nums);
        ans.push_back(fullPacket(nums, weight));
    }
    for (auto i : ans)
        cout << i << endl;
    return 0;
}