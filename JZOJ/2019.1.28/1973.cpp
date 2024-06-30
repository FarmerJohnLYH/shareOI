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
const int N=1001000;
struct rec{
	int l,r,d,u;
	rec(int l_=0,int r_=0,int d_=0,int u_=0)
	{
		l=l_,r=r_,u=u_,d=d_;
	}
}f[N],cur[N];
int ans[N][2];
int n,m;
int d[N],u[N];
struct node{
	int x,y;
	node(int x_=0,int y_=0)
	{
		x=x_,y=y_;
	}
}p[N];
void mix(rec &a,rec b)
{
	rec p=rec(max(a.l,b.l),min(a.r,b.r),max(a.d,b.d),min(a.u,b.u));
	a=p;
}
int main()
{
	freopen("D:/LiuYuanHao/c1.in","r",stdin);
	scanf("%d%d",&n,&m);
	fo(i,1,n) f[i]=rec(-2000000,2000000,-2000000,2000000);
	fo(i,1,n) scanf("%d",&d[i]);
	fo(i,1,m)
	{
		scanf("%d%d%d",&u[i],&p[i].x,&p[i].y);
		mix(f[u[i]],rec(p[i].x-p[i].y-d[u[i]],p[i].x-p[i].y+d[u[i]],p[i].x+p[i].y-d[u[i]],p[i].x+p[i].y+d[u[i]]));
	}
	cur[n]=f[n];
	fd(i,n-1,1)
	{
		int r=d[i+1]-d[i];
		mix(cur[i]=f[i],rec(cur[i+1].l-r,cur[i+1].r+r,cur[i+1].d-r,cur[i+1].u+r));
	}
	fo(i,1,n)
	{
		if(i>1)
		{
			int r=d[i]-d[i-1];
			mix(cur[i],rec(ans[i-1][0]-r,ans[i-1][0]+r,ans[i-1][1]-r,ans[i-1][1]+r));
		}
		int flag=1;
		for (ans[i][0]=cur[i].l;ans[i][0]<=cur[i].r;++ans[i][0])
		{
			for (ans[i][1]=cur[i].d;ans[i][1]<=cur[i].u;++ans[i][1])
				if((ans[i][0]+ans[i][1])%2==0)
				{
					flag=0;
					break;
//					goto Done;
				}		
			if(!flag)break;
		}
		Done:
		printf("%d %d\n",(ans[i][0]+ans[i][1])/2,(-ans[i][0]+ans[i][1])/2);
	}
	return 0;
}








