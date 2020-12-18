// hw31.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
海面上有一些船需要与陆地进行通信，需要在海岸线上布置一些基站。现将问题抽象为，在x轴上方，给出n条船的
坐标p1,p2,…,pn，其中pi=(xi,yi)，0≤yi≤d, 1≤i≤n，在x轴安放的基站可以覆盖半径为d的区域内的所有船只，
问在x轴至少要安放几个基站才可以将x轴上方的船只都覆盖到。

贪心 先将船坐标按横坐标排序，当点集非空时，每次选择最左边的点，确定到横坐标距离为d的x轴上的点，删除这个圆里的点


*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
struct pos_t {
    double x, y;
    double rsect;
} pos[10010];
int cover[10010];
int n;
double d;

const double minINF = 0.00000000001;//浮点误差

int cmp(const void* a, const void* b) {
    pos_t* ta, * tb;
    ta = (pos_t*)a;
    tb = (pos_t*)b;
    double temp = ta->rsect - tb->rsect;
    if (-minINF <= temp && temp <= minINF) {//浮点数比较注意预留一定的精度判断
    //if(temp == 0) {
        return 0;
    }
    else if (temp < 0) {
        return -1;
    }
    else {
        return 1;
    }
}

int solve() {
    scanf("%d%lf", &n, &d);
    for (int i = 0; i < n; i++) {
        scanf("%lf%lf", &pos[i].x, &pos[i].y);
        pos[i].rsect = pos[i].x + sqrt(d * d - pos[i].y * pos[i].y);
    }
    memset(cover, 0, sizeof(cover));
    qsort(pos, n, sizeof(pos_t), cmp);
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (cover[i] == 1) {
            continue;
        }
        count = count + 1;
        for (int j = i; j < n; j++) {
            if (pos[j].rsect - pos[i].rsect > 2 * d) {
                break;
            }
            if (cover[j] == 1) {
                continue;
            }
            //下面也需要注意浮点误差
            double temp = (pos[j].x - pos[i].rsect) * (pos[j].x - pos[i].rsect) + pos[j].y * pos[j].y - d * d;
            if (temp <= minINF) {
                cover[j] = 1;
            }
        }
    }
    printf("%d\n", count);
}

int main() {
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        solve();
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
