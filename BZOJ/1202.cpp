#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
const int N=110,M=1010;
int T;
int n,m;
int f[N],c[N];
int gf(int x)
{
	if(f[x]==x) return x;
	else
	{
		int p=gf(f[x]);
		c[x]+=c[f[x]];f[x]=p;
		return f[x];
	}
}
int main()
{
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		++n;
		fo(i,1,n) f[i]=i,c[i]=0;
		int flag=0;
		fo(i,1,m)
		{
			int x,y,v;
			scanf("%d%d%d",&x,&y,&v);
			++y;
			if(!flag)
			{
				int fx=gf(x),fy=gf(y);
				if(fx==fy)
				{
					if(v!=c[x]-c[y]) flag=1;
				}else
				{
					c[fy]=-c[y]+c[x]-v;
					f[fy]=fx;
				}
			}
		}
		if(!flag)printf("true\n");
		else printf("false\n");
	}
	return 0;
}











