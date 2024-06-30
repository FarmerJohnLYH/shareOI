#include <bitset>
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
const int N=500500,mo=1e9+7;
int n,k;
int qsm(int a,int b)
{
	int x=1;
	a%=mo,b%=(mo-1);
	while(b)
	{
		x=((b&1))?((1ll*x*(a))%mo):(x);
		b>>=1,a=(1ll*a*a)%mo;
	}
	return x;
}
int pt=0;
int f[N],p[N],q[N];
int gf(int x){return(f[x]==x)?(x):(f[x]=gf(f[x]));}
int cb(int x,int y)
{
	int fx=gf(x),fy=gf(y);
	f[fx]=fy;
}
void work(int x,int y,int val)
{
	if(x>y)swap(x,y);
	int st=y-x+1,ed=st+(min(n-y+1,x)-1)*2;
	st=max(st-2,0);
	if(val)cb(p[st],q[ed]),cb(q[st],p[ed]);
	else cb(p[st],p[ed]),cb(q[st],q[ed]);
}
int main()
{
	freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%d%d",&n,&k);
	fo(i,0,n) 
	{
		p[i]=++pt,f[pt]=pt;
		q[i]=++pt,f[pt]=pt;
	}
	fo(i,1,k)
	{
		int x,y;char c=' ';
		scanf("%d%d",&x,&y);
		while(c!='x'&&c!='o')c=getchar();
		work(x,y,(c=='o'));
	}
	fo(i,0,n)
	if(gf(p[i])==gf(q[i]))
	{
		printf("0\n");
		return 0;
	}
	int ans=0;
	fo(i,1,pt) ans+=(f[i]==i);
	printf("%d\n",qsm(2,(ans/2)-1));
	return 0;
}


