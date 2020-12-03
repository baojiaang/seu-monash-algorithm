// hw15.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct build_t {
    int a, b, h;
} build[50001];
struct height_t {
    int a, h;
} ht[50001 * 2], temp[50001 * 2];
int n;

int cmp_build(const void* a, const void* b) {
    return ((build_t*)a)->a - ((build_t*)b)->a;
}
int cmp_height(const void* a, const void* b) {
    build_t* c = (build_t*)a;
    build_t* d = (build_t*)b;
    if (c->a != d->a) {
        return c->a - d->a;
    }
    else {
        return c->h - d->h;
    }
}

int remove(int s, int e) {
    int k = s;
    for (int i = s + 1; i < e; i++) {
        if (ht[i].a == ht[k].a) {
            if (ht[k].h < ht[i].h) {
                ht[k] = ht[i];
            }
        }
        else if (ht[k].h != ht[i].h) {
            k++;
            ht[k] = ht[i];
        }
    }
    return k - s + 1;
}

int merge(int low, int lenleft, int mid, int lenright) {
    int i = low;
    int j = mid;
    int k = low;
    int curh = 0;
    int lh = 0;
    int rh = 0;
    for (; i < low + lenleft; i++) {
        for (; j < mid + lenright; j++) {
            if (ht[i].a == ht[j].a) {
                temp[k] = ht[i].h > ht[j].h ? ht[i] : ht[j];
                k++;
                lh = ht[i].h;
                rh = ht[j].h;

                i++;
                if (i >= low + lenleft) {
                    j++;
                    break;
                }
            }
            else if (ht[i].a < ht[j].a) {
                temp[k].a = ht[i].a;
                temp[k].h = ht[i].h > rh ? ht[i].h : rh;
                k++;
                lh = ht[i].h;
                break;
            }
            else {
                temp[k].a = ht[j].a;
                temp[k].h = ht[j].h > lh ? ht[j].h : lh;
                k++;
                rh = ht[j].h;
            }
        }
        if (j >= mid + lenright) {
            break;
        }
    }
    for (; i < low + lenleft; i++) {
        temp[k].a = ht[i].a;
        temp[k].h = ht[i].h;
        k++;
    }
    for (; j < mid + lenright; j++) {
        temp[k].a = ht[j].a;
        temp[k].h = ht[j].h;
        k++;
    }
    for (i = low; i < k; i++) {
        ht[i] = temp[i];
    }
    return remove(low, k);
}

int divide(int low, int high, int depth) {
    if (low > high) {
        return 0;
    }
    if (low == high) {
        ht[2 * low].a = build[low].a;
        ht[2 * low].h = build[low].h;
        ht[2 * low + 1].a = build[low].b;
        ht[2 * low + 1].h = 0;
        return 2;
    }
    int mid = (low + high) / 2;
    int lenleft = divide(low, mid, depth + 1);
    int lenright = divide(mid + 1, high, depth + 1);
    qsort(&ht[2 * low], lenleft, sizeof(height_t), cmp_height);
    qsort(&ht[2 * (mid + 1)], lenright, sizeof(height_t), cmp_height);

    int res = merge(2 * low, lenleft, 2 * (mid + 1), lenright);

    return res;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d", &build[i].a, &build[i].b, &build[i].h);
    }
    qsort(build, n, sizeof(build_t), cmp_build);
    int len = divide(0, n - 1, 0);
    for (int i = 0; i < len; i++) {
        printf("%d %d\n", ht[i].a, ht[i].h);
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
