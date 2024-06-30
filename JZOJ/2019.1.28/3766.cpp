#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define sqr(x) ((x)*(x))
#define lowbit(x) ((x)&(-x))
#define abs(x) (((x)>=0)?(x):(-(x)))
#define max(x,y) (((x)>(y))?(x):(y))
#define min(x,y) (((x)<(y))?(x):(y))
#define fo(i,x,y) for (int i = (x);i <= (y);++ i)
#define fd(i,x,y) for (int i = (x);i >= (y);-- i)
using namespace std;
typedef double db;
typedef long long ll;
const int N = 100100;
int n,q;
int c[N];//以i为端点简单路径条数

int main()
{
    freopen("D:/LiuYuanHao/","r",stdin);
    scanf("%d%d\n", &n, &q);
    fo(i,1,q)
    {
        char ch;
        int x,y;
        scanf("%c%d%d\n", &c, &x, &y);
        if (c == 'A')
    {
        int t = c[x];  
        c[x] += c[y] + 1;
        c[y] += t + 1;
    }
        if (c == 'Q')
    {
        printf("%d", c[x] * c[y] + 1);
    }

    }
}





