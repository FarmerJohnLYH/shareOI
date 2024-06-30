#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x),asdfgh=(y);i<=asdfgh;++i)
#define fd(i,x,y) for (int i=(x);asdfgh=(y);i>=asdfgh;--i)
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
const int N=60060,M=40040,V=120120;
int n,q;
int a[N];
struct tr{
	int son[5];//2 3
	int t;     //1 4 
}t[N*8];
char st[8];
int tot=1;
void insert(int x,int lx,int ly,int rx,int ry,int qx,int qy)
{
	if(lx==rx&&ly==ry)
	{
		++t[x].t;
		return;
	}
	if(lx>rx||ly>ry) 
		return;
	int midl=(lx+rx)>>1,midr=(ly+ry)>>1;
	if(qx<=midl&&qy<=midr) 
	{
		if(!t[x].son[1]) t[x].son[1]=++tot;
		insert(t[x].son[1],lx,ly,midl,midr,qx,qy);
		++t[x].t;
	}
	if(qx<=midl&&qy>midr) 
	{
		if(!t[x].son[2]) t[x].son[2]=++tot;
		insert(t[x].son[2],lx,midr+1,midl,ry,qx,qy);
		++t[x].t;
	}
	if(qx>midl&&qy<=midr) 
	{
		if(!t[x].son[3]) t[x].son[3]=++tot;
		insert(t[x].son[3],midl+1,ly,rx,midr,qx,qy);
		++t[x].t;
	}
	if(qx>midl&&qy>midr) 
	{
		if(!t[x].son[4]) t[x].son[4]=++tot;
		insert(t[x].son[4],midl+1,midr+1,rx,ry,qx,qy);
		++t[x].t;
	}
//	t[x].t=0;
//	fo(i,1,4) t[x].t+=t[t[x].son[i]].t;
}
int query(int x,int lx,int ly,int rx,int ry,int qlx,int qly,int qrx,int qry)
{
	if(!x)
		return(0);
	if(lx==qlx&&ly==qly&&rx==qrx&&ry==qry) 
		return(t[x].t);
	if(lx>rx||ly>ry) return(0);
	int midl=(lx+rx)>>1,midr=(ly+ry)>>1,rt=0;
	if(qlx<=midl&&qrx<=midr)
		rt+=query(t[x].son[1],lx,ly,midl,midr,max(qlx,lx),max(qly,ly),min(qrx,midl),min(qry,midr));
	if(qlx<=midl&&qry>midr)
		rt+=query(t[x].son[2],lx,midr+1,midl,ry,max(qlx,lx),max(qly,midr+1),min(qrx,midl),min(qry,ry));
	if(qly>midl&&qrx<=midr)
		rt+=query(t[x].son[3],midl+1,ly,rx,midr,max(qlx,midl+1),max(qly,ly),min(qrx,rx),min(qry,midr));
	if(qly>midl&&qry>midr)
		rt+=query(t[x].son[4],midl+1,midr+1,rx,ry,max(qlx,midl+1),max(qly,midr+1),min(qrx,rx),min(qry,ry));
	return rt;
}
int main()
{
	freopen("D:/LiuYuanHao/c.in","r",stdin);
	freopen("D:/LiuYuanHao/c.out","w",stdout);
	memset(t,0,sizeof t);
	scanf("%d%d",&n,&q);
	fo(i,1,n)
	{
		scanf("%d",&a[i]);
			insert(1,-120000,-120000,120000,120000,i-a[i],i+a[i]);
	}
	scanf("\n");
	while(q--)
	{
		int qx,qy;
		scanf("%s%d%d\n",st+1,&qx,&qy);
		if(st[1]=='M')
		{
			a[qx]=qy;
			insert(1,-120000,-120000,120000,120000,qx-a[qx],qx+a[qx]);
		}
		else
		if(st[1]=='Q')
		{
			int lx=(qx-a[qx])-qy,ly=(qx+a[qx])-qy,rx=(qx-a[qx])+qy,ry=(qx+a[qx])+qy;
			int ans=query(1,-120000,-120000,120000,120000,lx,ly,rx,ry);
			printf("%d\n",ans);
		}
	}
}











