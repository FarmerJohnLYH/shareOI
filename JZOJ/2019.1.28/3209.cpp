#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
typedef long long ll;
const ll N=100100,mo=1e6+3;
int n,m;
ll sum,sa,t[N];
int a[N];
void dfs(int x,int y,ll z)
{
	if(y<0)return;
	sum+=z,sa+=z*z;
	fo(i,1,9) 
	{
		a[x]=i;
		dfs(x+1,y-i,z+i*t[x-1]);
	}
}
ll d[N],e[N];
int main()
{
	freopen("D:/LiuYuanHao/a.in","r",stdin);
	freopen("D:/LiuYuanHao/a.ans","w",stdout);
	fo(n,1,12)
	{
//		scanf("%d",&n);
		sum=sa=0;
		t[0]=1;
		fo(i,1,n) t[i]=t[i-1]*10;
		dfs(1,n,0);
		d[n]=sum,e[n]=sa;
//		printf("%lld %lld\n",sum,sa);
	}
	fo(n,1,10) printf("%lld,",d[n]);puts("");
	fo(n,1,10) printf("%lld,",e[n]);
	return 0;
}









