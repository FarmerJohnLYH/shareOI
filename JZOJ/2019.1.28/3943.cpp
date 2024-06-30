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
const int N=1001000;
int n,s0;
int d[N],fa[N],tim[N];
int sta[N/2];
void gf(int x)
{
	int s0=1;sta[1]=fa[x];
	while(sta[s0]-x<n&&s0[sta][fa]!=s0[sta])	
		sta[s0+1]=(s0++)[sta][fa];
	int en=sta[s0--];
	while((--s0)>0) fa[sta[s0]]=en,s0[sta][tim]+=sta[s0+1][tim];
	fa[x]=en,tim[x]+=tim[sta[1]];
}
int main()
{
	freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%d%d",&n,&s0);
	fo(i,1,n) scanf("%d",&d[i]);
	// d[i+n]=d[i],d[i]+=d[i-1];
	// fo(i,n+1,2*n) d[i]+=d[i-1];
	while(s0--)
	{
		memset(fa,0,sizeof fa);
		int v;
		scanf("%d",&v);
		int tl=1,cnt=0;
		fo(i,1,n*2)
		{
			cnt-=d[i-1];
			while(tl+1<=n*2&&(d[tl]+cnt)<=v) cnt+=d[tl],++tl;
			fa[i]=tl,tim[i]=1;
		}
		int ans=oo;
		fo(i,1,n) 
		{
			if(fa[i]-i<i)gf(i);
			if((fa[i]-i)>=n)ans=min(tim[i],ans);
		}
		if(ans==oo)printf("NO\n");
		else printf("%d\n",ans);
	}
	return 0;
}

