#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define fo(i,x,y) for (register int asDfg = (y),i = (x);i <= asDfg;++ i)
#define fd(i,x,y) for (register int asDfg = (y),i = (x);i >= asDfg;-- i)
using namespace std;
typedef double db;
typedef long long ll;
int abs(int x) {return(((x)>=0)?(x):(-(x)));}
int max(int x,int y) {return(((x)>(y))?(x):(y));}
int min(int x,int y) {return(((x)<(y))?(x):(y));}
int lowbit(int x) {return((x)&(-x));}
const int N = 200200 * 2,Mo = 1e9 + 7;
int n,k,x;
int a[N];
struct node{
    int data,id;
    bool operator < (const node & temp) const {return abs(data) > abs(temp.data);}
};
priority_queue <node> q;
int flag=1;
int main()
{
    freopen("D:/LiuYuanHao/b.in","r",stdin);
    n = read(),k = read(),x = read();
    fo(i,1,n)
    {
        if ((a[i] = read())< 0) flag = -flag;
        q.push(node{a[i],i});
    }
    while (k --)
    {
        node now = q.top();q.pop();
        if (a[now.id] < 0)
        {
            a[now].id += x * flag;
            if (a[now.id] >= 0) flag = -flag;
        }
        else 
        {
            a[now.id] += x * (-flag);
            if (a[now.id] < 0) flag = -flag;
        }
        q.push(node{a[now.id],now.id});
    }
    ll ans = 1;
    fo(i,1,n) ans = (1ll * ans * a[i]) % Mo;
    printf("%lld", ans);
}