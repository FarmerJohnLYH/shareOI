#include <queue>
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
const int N = 200200;
bool vis[N];
int le[N],ri[N];
priority_queue<node> q;
struct node
{
    int x;
    node(int x_){x = x_;}
};
ll ans;
int a[N],n,m;
bool operator < (node x,node y)
{
    return a[x.x] < a[y.x];
}
int main()
{
    n = read(),m = read();
    fo(i,1,n) a[i] = read();
    fo(i,1,n)
    {
        le[i] = ((i == 1)?(n):(i - 1));
        ri[i] = ((i == n)?(1):(i + 1));
        q.push(i);
    }
    if (m > (n >> 1)) printf("Error!\n");
    else
    {
        fo(i,1,m)
        {
            node now = q.top();
            while (vis[now.x])
            {
                q.pop();
                now = q.top(); 
            }   
            int x = now.x;
            q.pop();
            ans += a[x];
            a[x] = a[le[x]] + a[ri[x]] - a[x];
            vis[le[x]] = vis[ri[x]] = 1;
            ri[x] = ri[ri[x]];
            le[ri[x]] = x;
            le[x] = le[le[x]];
            ri[le[x]] = x; 
            q.push(node(x));
        }
        printf("%lld\n",ans);
    }
}