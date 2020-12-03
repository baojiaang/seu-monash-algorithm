// hw4.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	void merge(vector<int>& arr, int L, int mid, int R)
	{
		vector<int> help(R - L + 1, 0);
		int p1 = L, p2 = mid + 1, i = 0;
		while (p1 <= mid && p2 <= R)
		{
			help[i++] = arr[p1] > arr[p2] ? arr[p2++] : arr[p1++];
		}
		while (p1 <= mid)
			help[i++] = arr[p1++];
		while (p2 <= R)
			help[i++] = arr[p2++];

		for (int i = 0; i < R - L + 1; i++)
		{
			arr[L + i] = help[i];
		}
	}
	void sortprocess(vector<int>& arr, int L, int R,int layer)
	{
		if (L < R)
		{
			int mid = (L+R)/2;  //  (L+R)/2
			sortprocess(arr, L, mid,layer+1);
			sortprocess(arr, mid + 1, R,layer+1);
			if (layer <3) return;
			merge(arr, L, mid, R);
		}
	}

	void MergeSort(vector<int>& arr, int L, int R)
	{
		if (arr.size() < 2)
			return;
		sortprocess(arr, L, R,1);
	}

};
int main() {
	int m;
	cin >> m;
	vector<vector<int>> result;
	Solution s;
	for (int i = 0; i < m; i++) {
		int n;
		cin >> n;
		vector<vector<int>> needPrint;
		vector<int> arr;
		vector<int> res(n);
		for (int j = 0; j < n; j++) {
			int num;
			cin >> num;
			arr.push_back(num);
		}
		s.MergeSort(arr, 0, n - 1);
		result.push_back(arr);
	}
	for (auto i : result) {
		for (auto num : i) {
			cout << num << " ";
		}
		cout << endl;
	}

}
