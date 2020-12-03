// hw24.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
class Solution {
public:
    /*
    double bestBinarySearchTree(vector<double>& p,vector<double>& q, int n) {
        vector<vector<double>> e (n+2,vector<double>(n+2,0));
        vector <vector<double>> w(n + 2,vector<double>(n + 2,0));
        for (int i = 1; i <= n+1; i++) {
            e[i][i - 1] = q[i - 1];
            w[i][i - 1] = q[i-1];
        }

        // 从下到上 从左到右计算
        for (int l = 1; l <= n; l++) {
            for (int i = 1; i <= n - l + 1; i++) {
                int j = i + l - 1;
                e[i][j] = 9999999;
                w[i][j] = w[i][j - 1] + p[j] + q[j];
                for (int k = i; k <= j; k++) {
                    double temp = e[i][k - 1] + e[k + 1][j] + w[i][j];
                    if (temp < e[i][j])
                        e[i][j] = temp;
                }
            }
        }

        return e[1][n];
    }
    */

    double OptimalBinarySearchTree(vector<double> a, vector<double> b, int n)
    {
        vector<vector<double>> m(n + 2, vector<double>(n + 2, 0));
        vector <vector<double>> w(n + 2, vector<double>(n + 2, 0));
        //初始化构造无内部节点的情况
        for (int i = 0; i <= n; i++)
        {
            w[i + 1][i] = a[i];
            m[i + 1][i] = 0;
        }

        for (int r = 0; r < n; r++)//r代表起止下标的差
        {
            for (int i = 1; i <= n - r; i++)//i为起始元素下标
            {
                int j = i + r;//j为终止元素下标

                //构造T[i][j] 填写w[i][j],m[i][j],s[i][j]
                //首选i作为根，其左子树为空，右子树为节点
                w[i][j] = w[i][j - 1] + a[j] + b[j];
                m[i][j] = m[i + 1][j];

                //不选i作为根，设k为其根，则k=i+1，……j
                //左子树为节点：i,i+1……k-1,右子树为节点：k+1,k+2,……j
                for (int k = i + 1; k <= j; k++)
                {
                    double t = m[i][k - 1] + m[k + 1][j];

                    if (t < m[i][j])
                    {
                        m[i][j] = t;
                    }
                }
                m[i][j] += w[i][j];
            }
        }
        return m[1][n];
    }

};

int main()
{
    Solution s;
    int m;
    cin >> m;
    vector<double> result;
    for (int i = 0; i < m; i++) {
        int n;
        cin >> n;
        vector<int> data;
        vector<double> p;
        vector<double> q;
        for (int j = 0; j < n; j++) {
            int num;
            cin >> num;
            data.push_back(num);
        }
        p.push_back(-1);
        for (int j = 0; j < n; j++) {
            double num;
            cin >> num;
            p.push_back(num);
        }
        for (int j = 0; j < n+1; j++) {
            double num;
            cin >> num;
            q.push_back(num);
        }
        double res = s.OptimalBinarySearchTree(q, p, n);
        result.push_back(res);
    }
    for (auto i : result) {
        cout << fixed << setprecision(6) << i << endl;
    }
}


// https://blog.csdn.net/liufeng_king/article/details/8694652
// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
