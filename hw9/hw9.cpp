// hw9.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Soltution {
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
    int LIS(vector<int> arr)
    {
        int n = arr.size();
        int* temp = new int[n];//存放当前遍历位置最长序列 
        for (int i = 0; i < n; ++i)
        {
            temp[i] = 1;   //初始化默认长度 
            for (int j = 0; j < i; ++j) //找出前面最长的序列 
            {
                // 当前值 array[i] 跟已经遍历的值比较，
                //大于已经遍历的值且已知递增序列+1 大于当前值则 更新当前最长递增序列值 
                if (arr[i] < arr[j] && temp[j] + 1 > temp[i])
                {
                    temp[i] = temp[j] + 1;
                }

            }
        }

        int max = temp[0];
        for (int k = 0; k < n; ++k)//找出整个数组中最长的子序列 
        {
            if (max < temp[k])
                max = temp[k];
        }

        return max;

    }
};

int main()
{
    Soltution s;
    int n_line;
    cin >> n_line;
    vector<int> result;
    for (int i = 0; i < n_line; i++) {
        int n_item;
        cin >> n_item;
        vector<int> line = s.oneLine(n_item);
        int res = s.LIS(line);
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
