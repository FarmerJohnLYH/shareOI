#include <bitset>
#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
const int N=2020;
int fa[N],n,m;
char ch;
int T,las[N];
bitset<N> b[N];
int gf(int x)
{
	return(fa[x]==x)?(x):(fa[x]=gf(fa[x]));
}
void comb(int x,int y)
{
	int fx=gf(x),fy=gf(y);
	if(fx!=fy) fa[fy]=fx;
}
int main()
{
	freopen("rect.in","r",stdin);
	freopen("rect.out","w",stdout);
	// freopen("D:/LiuYuanHao/b.in","r",stdin);
	scanf("%d\n",&T);
	while(T--)
	{
		scanf("%d%d\n",&n,&m);
		fo(i,1,n) fa[i]=i,b[i].reset();
		fo(i,1,m) las[i]=0;
		fo(i,1,n)
		{
			fo(j,1,m)
			{
				scanf("%c",&ch);
				if(ch=='#') 
				{
					b[i][j]=1;
					if(las[j]) comb(las[j],i);las[j]=i;
				}
			}
			scanf("\n");			
		}
		int flag=0;
		fo(i,1,n)
		if(gf(i)!=i)
		{
			int f=gf(i);
			if(b[f]!=b[i]) 
			{
				flag=1;
				break;
			}
		}
		if(flag)printf("No\n");
		else printf("Yes\n");
	}
	return 0;
}








