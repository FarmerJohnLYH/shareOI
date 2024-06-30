#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define fo(i,x,y) for (int pq = (y),i = (x);i <= pq;++ i)
#define fd(i,x,y) for (int pq = (y),i = (x);i >= pq;-- i)
#define oo 2139062143
using namespace std;
typedef double db;
typedef long long ll;
int lowbit(int x) {return((x)&(-x));}
int min(int x,int y){return (x>y)?(y):(x);}
int max(int x,int y){return (x>y)?(x):(y);}
const int N=250250,R=2525;
int mp[R][R];
int n;
struct node{
	int x,y;
}a[N];
int cnt(int ax_,int ay_,int bx_,int by_)
{
	int ax=min(ax_,bx_),ay=min(ay_,by_);
	int bx=max(ax_,bx_),by=max(ay_,by_);
	return(mp[bx][by]-mp[ax-1][by]-mp[bx][ay-1]+mp[ax-1][ay-1]);
}
int mnc[N],mnr[N],mxc[N],mxr[N];
int ul[R][R],dr[R][R];
int le=oo,up,ri,dn=oo;
int main()
{
	freopen("D:/LiuYuanHao/b.in","r",stdin);
	freopen("D:/LiuYuanHao/b.out","w",stdout);
	scanf("%d",&n);
	fo(i,0,2501) mxc[i]=mxr[i]=1;
	fo(i,0,2501) mnc[i]=mnr[i]=2500;
	memset(mnc,127,sizeof mnc);
	fo(i,1,n)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		a[i].x=x,a[i].y=y;
		mp[x][y]++;
		mxc[x]=max(mxc[x],y);
		mnc[x]=min(mnc[x],y);
		mxr[y]=max(mxr[y],x);
		mnr[y]=min(mnr[y],x);
		le=min(le,x);
		dn=min(dn,y);
		ri=max(ri,x);
		up=max(up,y);
	}
//	--le,--dn,++ri,++up;
	le=dn=1;
mnc[0]=up+1;
	fo(i,le,ri)	mnc[i]=min(mnc[i],mnc[i-1]);
	fo(i,dn,up)	mnr[i]=min(mnr[i],mnr[i-1]);
	fd(i,ri,le)	mxc[i]=max(mxc[i],mxc[i+1]);
	fd(i,up,dn)	mxr[i]=max(mxr[i],mxr[i+1]);
	fo(i,le,ri) fo(j,dn,up)
	{
		mp[i][j]=mp[i][j]+mp[i-1][j]+mp[i][j-1]-mp[i-1][j-1];
	}
	fo(i,le,ri) fd(j,up,dn) 
	{
		int tx=min(mnr[j-1],i),ty=max(mxc[i+1],j);
		ul[i][j]=ul[tx][ty]+cnt(le,up,i,j);
	}
	fd(i,ri,le) fo(j,dn,up) 
	{
		int tx=max(i,mxr[j+1]),ty=min(j,mnc[i-1]);
		dr[i][j]=dr[tx][ty]+cnt(i,j,ri,dn);
	}
	fo(i,1,n)
	{
		int ans;
		ans=n+ul[a[i].x][a[i].y]+dr[a[i].x][a[i].y]-3;
		printf("%d\n",ans);
	}
	return 0;
}
