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
const int N=20020;
int n;
struct edge{
	int to,nex,v;
}e[N*2];
int las[N];
int fa[N],dep[N],cnt[N][3];
int gcd(int x,int y)
{
	return((y==0)?(x):(gcd(y,x%y)));
}
int tot;
int ans;
void link(int x,int y,int v)
{
	e[++tot].to=y,e[tot].v=v%3,e[tot].nex=las[x];
	las[x]=tot;
}
void dfs(int x,int f)
{
	fa[x]=f;
	for (int tmp=las[x];tmp;tmp=e[tmp].nex)
	if(e[tmp].to!=fa[x])
	{
		int to=e[tmp].to,v=e[tmp].v;
		dfs(to,x);
		fo(i,0,2) cnt[x][i]+=cnt[to][(i-v+3)%3];
	}
	for (int tmp=las[x];tmp;tmp=e[tmp].nex)
	if(e[tmp].to!=fa[x])
	{
		int to=e[tmp].to,v=e[tmp].v;
		int p[3]={0,0,0};
		fo(i,0,2)p[i]=cnt[x][i]-cnt[to][(i-v+3)%3]; 
		fo(i,0,2)
		{
			ans+=cnt[to][(6-v-i)%3]*p[i];
		}
	}
	ans+=cnt[x][0]*2+1;
	++cnt[x][0];
}
int main()
{
	freopen("D:/LiuYuanHao/b2.in","r",stdin);
//	freopen("b.in","r",stdin);
//	freopen("b.ans","w",stdout);
	scanf("%d",&n);
	fo(i,1,n-1)
	{
		int x,y,v;
		scanf("%d%d%d",&x,&y,&v);
		link(x,y,v),link(y,x,v);
	}
	ans=0;
	dfs(1,0);
	int all=(n*n),tmp=gcd(all,ans);
	ans/=tmp,all/=tmp;
	printf("%d/%d\n",ans,all);
}











