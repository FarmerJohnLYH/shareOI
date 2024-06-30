#include<cstdio>
#include<iostream>
#include<algorithm>
#define N 200010
#define ll long long
using namespace std;
ll a[N],b[N],n,m,k;
ll read()
{
    ll num=0,flag=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')flag=-1;c=getchar();}
    while(c>='0'&&c<='9'){num=num*10+c-'0';c=getchar();}
    return num*flag;
}
bool check(ll mid)
{
    ll p=n,sum=0;
    for(ll i=1;i<=m;i++)
    {
        while(b[i]*a[p]>mid&&p)p--;
        sum+=p;
    }
    if(sum>=k)return true;
    return false;
}
int main()
{
        freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    n=read();m=read();k=read();
    for(ll i=1;i<=n;i++)a[i]=read();
    for(ll i=1;i<=m;i++)b[i]=read();
    sort(a+1,a+n+1);sort(b+1,b+m+1);
    ll l=0,r=a[n]*b[m],ans;
    while(l<=r)
    {
        ll mid=(l+r)>>1;
        if(check(mid))
        {
            ans=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    cout<<ans;
    return 0;
}
