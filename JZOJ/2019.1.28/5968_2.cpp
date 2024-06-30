#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
typedef long long ll;
const int N=100100,mo=1e9+7;
int n;
ll ans,a[N];
ll jc[N];
int bz[N];
int check(int va,int vb)
{
	if(va==vb) return 1;
	int c1=0,c2=0;
	fo(i,1,n)
	{
		if(!bz[i])
		{
			if(a[i]==va) ++c1;
		}
		if(a[i]>va&&a[i]<vb)	
			return 0;
	}
	if(c1==1) return 1;
	else return 0;
}
void dfs(int x)
{
	if(x==n)
	{
		++ans;
		return ;
	}
	fo(i,1,n) if(!bz[i])
	{
		fo(j,i+1,n) if(i!=j&&!bz[j]&&check(a[i],a[j]))
		{
			bz[i]=1;
			dfs(x+1);
			bz[i]=0;
		}
	}
}
ll p[N],q[N];
int main()
{
	// freopen("D:/LiuYuanHao/b.in","r",stdin);
	freopen("out.in","r",stdin);
	freopen("out.out","w",stdout);
	// freopen("D:/LiuYuanHao/b.out","w",stdout);
	scanf("%d",&n);
	if(n<=5)
	{
		jc[0]=1;
		fo(i,1,n)
			scanf("%lld",&a[i]),jc[i]=jc[i-1]*i%mo;
		sort(a+1,a+1+n);
		memset(bz,0,sizeof bz);
		ans=0;
		dfs(1);
		printf("%lld\n",ans);	
		return 0;
	}
	fo(i,1,n) p[i]=(p[i-1]+i)%mo;
	ans=1;
	fo(i,1,n-1)
		ans=ans*p[i]%mo;
	printf("%lld\n",ans);
	return 0;
}








