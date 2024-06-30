#include<cstdio>
#include<cstring>
#include<algorithm>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define N 210
#define db double
#define cl(a) memset(a,0,sizeof(a))
using namespace std;
int n,e[15],line[N*N][N],tot,bz[N][N],cnt[N];
struct pts{
	int x,y;
	pts friend operator +(pts a,pts b){pts c;c.x=a.x+b.x;c.y=a.y+b.y;return c;}
	pts friend operator -(pts a,pts b){pts c;c.x=a.x-b.x;c.y=a.y-b.y;return c;}
	int friend operator /(pts a,pts b){return a.x*b.y-a.y*b.x;}
}a[N];
struct node{
	db a[N][N];
	node(){cl(a);};
	node friend operator *(node a,node b)
	{
		node c=node();
		fo(i,1,n) fo(j,1,n) fo(k,1,n)
					c.a[i][k]+=a.a[i][j]*b.a[j][k];
		return c;
	}
}f[14];
struct note{
	db a[N];
	note(){cl(a);};
}b;
note operator *(note a,node b)
{
	note c=note();
	fo(i,1,n)
	{
		fo(j,1,n)
		{
			c.a[j]+=a.a[i]*b.a[i][j];
		}
	}
	return c;
}
bool crossing(int i,int j,int k)
{
	return ((a[j]-a[i])/(a[k]-a[i]))==0;
}
void mi(int m)
{
	int x=0;
	fd(i,13,0)
	if(x+e[i]<=m)
	{
		x+=e[i];
		b=b*f[i];
	}
}
int main()
{
	freopen("moon.in","r",stdin);
	freopen("moon.out","w",stdout);
	e[0]=1;fo(i,1,14) e[i]=e[i-1]*2;
	scanf("%d",&n);
	fo(i,1,n) scanf("%d%d",&a[i].x,&a[i].y);
	fo(i,1,n)
	{
		fo(j,1,n)
		if(i!=j&&!bz[i][j])
		{
			tot++;
			fo(k,1,n) 
			if(crossing(i,j,k)) line[tot][++line[tot][0]]=k,cnt[k]++;
			fo(k,1,line[tot][0])
			{
				fo(l,1,line[tot][0]) bz[line[tot][k]][line[tot][l]]=bz[line[tot][l]][line[tot][k]]=1;
			}
		}
	}
	fo(i,1,tot)
	{
		fo(k,1,line[i][0])
		{
			fo(j,1,line[i][0])
			{
				f[0].a[line[i][k]][line[i][j]]+=1.0/cnt[line[i][j]]/line[i][0];
			}
		}
	}
	fo(j,1,13) f[j]=f[j-1]*f[j-1];
	int ac;scanf("%d",&ac);
	while(ac--)
	{
		int t,m;scanf("%d%d",&t,&m);
		memset(b.a,0,sizeof(b.a));
		b.a[t]=1;
		mi(m-1);
		db ans=0;
		fo(i,1,tot)
		{
			db jy=0;
			fo(k,1,line[i][0]) jy+=b.a[line[i][k]]/line[i][0];
			ans=max(ans,jy);
		}
		printf("%.8lf\n",ans);
	}
}