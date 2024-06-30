#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
typedef unsigned long long ull;
typedef pair<int,int> PI;
const int N=200200;
ull A,B,C,ans;
int n,m;
vector<int> a[N],b[N];
ull f[N],g[N],c[N],d[N];
PI e[N];
bool cmp(PI a,PI b){return(a.fi!=b.fi)?(a.fi<b.fi):(a.se<b.se);}
int main()
{
	freopen("D:/LiuYuanHao/a1.in","r",stdin);
	scanf("%d%d%llu%llu%llu",&n,&m,&A,&B,&C);
	fo(i,1,m)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		++x,++y;
		if(x>y) swap(x,y);
		e[i]=make_pair(x,y);
	}
	sort(e+1,e+1+m,cmp);
	fo(i,1,m)if(e[i].fi!=e[i+1].fi&&e[i].se!=e[i+1].se)
	{
		int x=e[i].fi,y=e[i].se;
		a[x].push_back(y),b[y].push_back(x);
	}
	fo(i,1,n) 
	{
		f[i]=f[i-1]+(i-1-c[i]);
		for(int p=a[i].size()-1,j=0;j<=p;++j) ++c[a[i][j]];
	}
	fd(i,n,1) 
	{
		g[i]=g[i+1]+(n-i-d[i]);
		for(int p=b[i].size()-1,j=0;j<=p;++j) ++d[b[i][j]];
	}
	fo(i,1,n) 
	{
		
	}
	return 0;
}











