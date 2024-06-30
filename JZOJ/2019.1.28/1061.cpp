#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo (1ll<<60)
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define fd(i,x,y) for (int i=(x);i>=(y);--i)
#define min(x,y) ((x)<(y)?(x):(y))
#define max(x,y) ((x)>(y)?(x):(y))
#define fi first 
#define se second
using namespace std;
typedef long long ll;
const int N=220,Q=100100;
int n,q,m;
ll f[N][N][N];
pair<int,int> c[N];
int read()
{
    char ch=' ';int q=0,w=1;
    for(;(ch!='-')&&((ch<'0')||(ch>'9'));ch=getchar());
    if(ch=='-')w=-1,ch=getchar();
    for(;ch>='0' && ch<='9';ch=getchar())q=q*10+ch-48;int n=q*w;return n;
}
int buf[33],b0;
void write(ll x)
{
	b0=0;
	if(x==0)putchar('0');
	else
	while(x) buf[++b0]=x%10,x/=10;
	fd(i,b0,1) putchar(buf[i]+'0');
	putchar('\n');
}
int main()
{
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
//	freopen("D:/LiuYuanHao/a.out","w",stdout);
	int T=0;
	T=read();
	while(T--)
	{
		n=read(),m=read();
		memset(f,127,sizeof f);
		fo(i,1,n) c[i].fi=read(),c[i].se=i;
		fo(i,1,n) f[0][i][i]=0;
		fo(i,1,m)
		{
			int x=read()+1,y=read()+1,c=read();
			f[0][x][y]=f[0][y][x]=min(f[0][x][y],c);
		}
		sort(c+1,c+1+n);
		fo(v,1,n)
		{
			fo(i,1,n) fo(j,1,n) 
				f[v][i][j]=f[v-1][i][j];
			int k=c[v].se;
			fo(i,1,n) if(i!=k) fo(j,1,n) if(i!=j && j!=k)
			if(f[v][i][k]<oo&&f[v][k][j]<oo)
				f[v][i][j]=min(f[v][i][j],f[v][i][k]+f[v][k][j]);
		}
		q=read();
//		printf("%d\n",q);
		while(q--)
		{
			int u=read()+1,v=read()+1,k=read();
			ll ans=oo;
			fd(i,n,0) if(c[i].fi<=k)
			{
				ans=f[i][u][v];
				break;
			}
			if(ans>=oo) puts("-1");
			else write(ans);
		}
		puts("");
	}
	return 0;
}








