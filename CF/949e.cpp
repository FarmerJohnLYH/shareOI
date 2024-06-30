#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
const int N=200005,M=22;
int n;
int a[N],f[M][N],ans[M];
int tot[M],top,st[M];
void solve(int cs,int cnt)
{
    if (cs>=19) return;
    sort(f[cs]+1,f[cs]+tot[cs]+1);
    tot[cs]=unique(f[cs]+1,f[cs]+tot[cs]+1)-f[cs]-1;
    int s1=0,s0=0;
    fo(i,1,tot[cs])
             if(f[cs][i]!=0&&((f[cs][i]&1)^1))++s0;
        else if(f[cs][i]&1)++s1;
    if(!s0&&!s1)
    {
        if (cnt<ans[0])
        {
            ans[0]=cnt;
            fo(i,1,cnt) ans[i]=st[i];
        }
    }
    else
    if (!s1)
    {
        tot[cs+1]=0;
        fo(i,1,tot[cs])
            if ((f[cs][i]/2)) f[cs+1][++tot[cs+1]]=f[cs][i]/2;
        solve(cs+1,cnt);
    }
    else
    {
        tot[cs+1]=0;st[++top]=1<<cs;
        for (int i=1;i<=tot[cs];i++)
            if (f[cs][i]%2==0&&f[cs][i]/2!=0) f[cs+1][++tot[cs+1]]=f[cs][i]/2;
            else if (f[cs][i]%2!=0) f[cs+1][++tot[cs+1]]=(f[cs][i]-1)/2;
        solve(cs+1,cnt+1);--top;
        tot[cs+1]=0;st[++top]=-(1<<cs);
        for (int i=1;i<=tot[cs];i++)
            if (f[cs][i]%2==0&&f[cs][i]/2!=0) f[cs+1][++tot[cs+1]]=f[cs][i]/2;
            else if (f[cs][i]%2!=0) f[cs+1][++tot[cs+1]]=(f[cs][i]+1)/2;
        solve(cs+1,cnt+1);--top;
    }
}
int main()

{
    // freopen("D:/LiuYuanHao/a.in","r",stdin);
    scanf("%d",&n);
    fo(i,1,n) scanf("%d",&a[i]);
    sort(a+1,a+n+1);n=unique(a+1,a+n+1)-a-1;
    tot[0]=n;
    fo(i,1,n) f[0][i]=a[i];
    ans[0]=M;solve(0,0);
    printf("%d\n",ans[0]);
    fo(i,1,ans[0]) printf("%d ",ans[i]);
    return 0;
}