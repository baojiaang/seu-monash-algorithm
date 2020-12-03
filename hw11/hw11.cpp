// hw11.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct position_t {
    int x;
    int y;
} pos[100001], tpos[100001], swappos[100001];
int n;

double mydistance(int i, int j) {
    return 1.0 * (pos[i].x - pos[j].x) * (pos[i].x - pos[j].x) + 1.0 * (pos[i].y - pos[j].y) * (pos[i].y - pos[j].y);
}

double fun() {
    double mymin = ((long long int)2) << 60;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            double d = mydistance(i, j);
            if (mymin > d) {
                mymin = d;
            }
        }
    }
    return sqrt(mymin);
}

int cmp_xy(const void* a, const void* b) {
    position_t* p1 = (position_t*)a;
    position_t* p2 = (position_t*)b;
    if (p1->x != p2->x) {
        return p1->x - p2->x;
    }
    else {
        return p1->y - p2->y;
    }
}

int cmp_y(const void* a, const void* b) {
    position_t* p1 = (position_t*)a;
    position_t* p2 = (position_t*)b;
    return p1->y - p2->y;
}

double divide(int low, int high) {
    if (low >= high) {
        return ((long long int)2) << 60;
    }
    if (low + 1 == high) {
        return mydistance(low, high);
    }
    int mid = (low + high) / 2;
    int midx = pos[mid].x;
    double d1 = divide(low, mid);
    double d2 = divide(mid + 1, high);
    double mymin = d1 > d2 ? d2 : d1;

    int k = 0;
    for (int i = low; i <= high; i++) {
        if (abs(midx - pos[i].x) < mymin) {
            tpos[k].x = pos[i].x;
            tpos[k].y = pos[i].y;
            k++;
        }
    }
    qsort(tpos, k, sizeof(position_t), cmp_y);
    for (int i = 0; i < k - 6; i++) {
        for (int j = 1; j <= 6; j++) {
            double temp = 1.0 * (tpos[i].x - tpos[i + j].x) * (tpos[i].x - tpos[i + j].x) + 1.0 * (tpos[i].y - tpos[i + j].y) * (tpos[i].y - tpos[i + j].y);
            if (temp < mymin) {
                mymin = temp;
            }
        }
    }

    return mymin;
}

int solve() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &pos[i].x, &pos[i].y);
    }

    //printf("%.2lf\n", fun());

    qsort(pos, n, sizeof(position_t), cmp_xy);
    printf("%.2lf\n", sqrt(divide(0, n - 1)));
}

int main() {
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        solve();
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
