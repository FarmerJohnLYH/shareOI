#include <map>
#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define fd(i,x,y) for (int i=(x);i>=(y);--i)
using namespace std;
typedef long long ll;
const int N=1001000,mo=1e9+7;
char s[N];
int a[N],d[N],d0;
ll f[N];
map<ll,int> p;
int n;
ll ans,hv,te[N];
int main()
{
	 freopen("bracket.in","r",stdin);
	 freopen("bracket.out","w",stdout);
//	freopen("D:/LiuYuanHao/c.in","r",stdin);
	scanf("%s",s+1);n=strlen(s+1);
	fo(i,1,n)a[i]=s[i]-'a';
	d0=0;
	te[0]=1;
	fo(i,1,n) te[i]=te[i-1]*998244353ll;
	fo(k,1,n)
	{
		if(d0==0||d[d0]!=s[k]) d[++d0]=s[k],hv+=d[d0]*te[d0];
		else hv-=d[d0]*te[d0],--d0;
		f[k]=hv;
	}
	p[0]=1;
	ans=0;
	fo(i,1,n)
	{
		ans=(ans+p[f[i]]);
		++p[f[i]];
	}
	printf("%lld\n",ans);
	return 0;
}








