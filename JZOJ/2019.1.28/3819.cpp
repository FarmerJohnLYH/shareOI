#pragma GCC optimize(2) 
#include <cmath>
#include <ctime>
#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x),asdfgh=(y);i<=asdfgh;++i)
#define fd(i,x,y) for (int i=(x),asdfgh=(y);i>=asdfgh;--i)
#define fi first
#define se second
using namespace std;
typedef double db;
typedef long long ll;
typedef pair<int,int> PI;
int abs(int x) {return(((x)>=0)?(x):(-(x)));}
int max(int x,int y) {return(((x)>(y))?(x):(y));}
int min(int x,int y) {return(((x)<(y))?(x):(y));}
int lowbit(int x) {return((x)&(-x));}
const int N=55,A=1010;
int n,f[N][N*A];
int read()
{
    char ch=' ';int q=0,w=1;
    for(;(ch!='-')&&((ch<'0')||(ch>'9'));ch=getchar());
    if(ch=='-')w=-1,ch=getchar();
    for(;ch>='0' && ch<='9';ch=getchar())q=q*10+ch-48;int n=q*w;return n;
}
int dfs(int x,int y)
{
    if(x==0)return(y&1);
    if(y==1)return(dfs(x+1,0));
    if(f[x][y]>=0)return(f[x][y]);
    if((x>=2&&!dfs(x-2,y+2+((bool)y)))||(y&&!dfs(x-1,y+1))||((y&&!dfs(x,y-1)))||(!dfs(x-1,y))) return(f[x][y]=1);
    return(f[x][y]=0);
}
int main()
{
    freopen("D:/LiuYuanHao/a1.in","r",stdin);
    freopen("D:/LiuYuanHao/a.out","w",stdout);
    memset(f,255,sizeof f);
    for (int T=read();T;T--)
    {
        n=read();
        int x,p=0,q=0;
        fo(i,1,n)
        {
            int x=read();
            if(x>4) x=x%2+4;
            if(x==1)++p;
            else q+=x+1;
        }
        q=(q>1)?(q-1):0;
        if(dfs(p,q))putchar('Y'),putchar('E'),putchar('S');
        else putchar('N'),putchar('O');
        putchar('\n');
    }
    return 0;
}
