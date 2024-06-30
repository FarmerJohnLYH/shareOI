#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
typedef long long ll;
const int N=1010,mo=1000109107;
ll T,n,m,k;
ll ans;
int a[N];
int v(int x,int y)
{
	return(((n-x-y)*2ll)<n);
}
int check()
{
	int c0=0;
	fo(i,1,m-1)
		if(v(a[i],a[i+1])) ++c0;
	if(v(a[m],a[1])) ++c0; 
	if(c0==k) return(a[1]);
	else return 0;
}
void dfs(int x,int y)
{
	if(y==m)
	{
		if(x==0)return;
		a[y]=x;
		ans+=check();
		return ;
	}
	fo(i,1,x)
		a[y]=i,dfs(x-i,y+1);
}
ll f[N][N];
int main()
{
	// freopen("polygon.in","r",stdin);
	// freopen("polygon.out","w",stdout);
	// freopen("D:/LiuYuanHao/a.in","r",stdin);
	freopen("D:/LiuYuanHao/a.ans","w",stdout);
	// scanf("%lld",&T);
	fo(mm,3,19) fo(nn,mm,19)  
	if(nn&1)
	{
		fo(kk,0,mm)
		{
			n=nn,m=mm,k=kk;	
		
			// scanf("%lld%lld%lld",&n,&m,&k);
			ans=0;
			dfs(n,1); 
			if(k==0&&ans)
			{
				printf("%lld %lld:",n,m);
				printf("%lld\n",ans%mo);
			
			}
		}
		// if(f[n][m]) printf("%d %d %d\n",n,m,f[n][m]);
	}
	return 0;
}








