// hw12.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct position_t {
    int x;
    int y;
    double angle;
    double len;
} pos[2001], stack[2001];
int n;
int top;


int cmp_yx(const void* a, const void* b) {
    position_t* p1 = (position_t*)a;
    position_t* p2 = (position_t*)b;
    if (p1->y != p2->y) {
        return p1->y - p2->y;
    }
    else {
        return p1->x - p2->x;
    }
}

int cmp_angle(const void* a, const void* b) {
    position_t* p1 = (position_t*)a;
    position_t* p2 = (position_t*)b;
    if (p1->angle - p2->angle > 0) {
        return 1;
    }
    else if (p1->angle - p2->angle < 0) {
        return -1;
    }
    else {
        if (p1->len - p2->len > 0) {
            return 1;
        }
        else if (p1->len - p2->len < 0) {
            return -1;
        }
        else {
            return 0;
        }
    }
}

int push(int i) {
    stack[top].x = pos[i].x;
    stack[top].y = pos[i].y;
    stack[top].angle = pos[i].angle;
    top++;
    return top;
}

int initstack() {
    top = 0;
}

int pop() {
    top--;
    return top;
}

int isright(int a, int b, int x, int y) {
    if (a * y - b * x > 0) {
        return 0;
    }
    return 1;
}
int canpop(int i) {
    if (top <= 2) {
        return 0;
    }
    if (isright(stack[top - 1].x - stack[top - 2].x, stack[top - 1].y - stack[top - 2].y, pos[i].x - stack[top - 2].x, pos[i].y - stack[top - 2].y)) {
        return 1;
    }
    return 0;
}
int isonline(int a, int b, int x, int y) {
    if (a * y - b * x == 0) {
        return 1;
    }
    return 0;
}

int findp0() {
    int minx = 2147483647;
    int miny = 2147483647;
    int idx = 0;
    for (int i = 0; i < n; i++) {
        if (pos[i].y < miny) {
            miny = pos[i].y;
            idx = i;
        }
    }
    for (int i = 0; i < n; i++) {
        if (pos[i].y == miny && pos[i].x < minx) {
            minx = pos[i].x;
            idx = i;
        }
    }
    return idx;
}

void sortangle() {
    for (int i = 1; i < n; i++) {
        pos[i].len = sqrt((pos[i].y - pos[0].y) * (pos[i].y - pos[0].y) + (pos[i].x - pos[0].x) * (pos[i].x - pos[0].x));
        pos[i].angle = acos((pos[i].x - pos[0].x) / pos[i].len);

    }
    qsort(&pos[1], n - 1, sizeof(position_t), cmp_angle);
}

void removesame() {
    qsort(pos, n, sizeof(position_t), cmp_yx);
    int k = 0;
    for (int i = 1; i < n; i++) {
        if (pos[i].x == pos[k].x && pos[i].y == pos[k].y) {
        }
        else {
            k++;
            pos[k].x = pos[i].x;
            pos[k].y = pos[i].y;
        }
    }
    n = k + 1;
}

int solve() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &pos[i].x, &pos[i].y);
    }

    removesame();

    int idx = findp0();

    position_t temppos = pos[idx];
    for (int i = idx; i > 0; i--) {
        pos[i] = pos[i - 1];
    }
    pos[0] = temppos;

    sortangle();

    initstack();
    push(0);
    int k = 2;
    for (; k < n; k++) {
        if (!isonline(pos[k].x - pos[0].x, pos[k].y - pos[0].y, pos[1].x - pos[0].x, pos[1].y - pos[0].y)) {
            break;
        }
    }
    push(k - 1);
    push(k);
    for (int i = k + 1; i < n; i++) {
        while (canpop(i)) {
            pop();
        }
        push(i);
    }

    for (int i = 0; i < top; i++) {
        printf("%d %d\n", stack[i].x, stack[i].y);
    }

    return 0;
}

int main() {
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        printf("case %d:\n", i + 1);
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
