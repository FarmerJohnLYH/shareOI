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
const int N = 100005;
int a[N],b[N];
int n;
ll x,y,z,ans,pay;
priority_queue<ll> stack1,stack2;
int main()
{
    freopen("D:/LiuYuanHao/a.in");
    n = read(),x = read(),y = read(),z = read();
    fo(i,1,n) a[i] = read(),b[i] = read();
    fo(i,1,n)
    if (a[i] > b[i])
    {
        fo(j,1,a[i] - b[i])
        {
            if (stack1.empty() || (-stack1.top() + i * z >= y)) pay = y,ans += y;
            else pay = -stack1.top() + i * z,stack1.pop(),ans += pay;
            stack2.push(pay + i * z);
        }
        else
        fo(j,1,b[i] - a[i])
        {
            if (stack2.empty() || (-stack2.top() + i * z >= x)) pay = x,ans += x;
            else pay = -stack2.top() + i * z,stack2.pop(),ans += pay;
            stack1.push(pay + i * z);
        }
    }
    printf("%lld", ans);
}