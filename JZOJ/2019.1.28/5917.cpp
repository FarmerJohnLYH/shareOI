#include <map>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#define fi first
#define se second
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define mp make_pair 
using namespace std;
typedef long long ll;
typedef long double db;
typedef pair<ll,ll> PI;
const int N=220;
const ll eps=1000000000;
int n,m;
PI a[N];
db f[16][N][N];
int du[N];
int fa[N*N],ct[N*N];
map<PI,int> mp;int tot;
int val(int x,int y)
{
	return((x-1)*n+y);
}
int vis[N*N];
int main()
{
	freopen("D:/LiuYuanHao/b.in","r",stdin);
	scanf("%d",&n);
	fo(i,1,n) scanf("%d%d",&a[i].fi,&a[i].se);
	fo(i,1,n) fo(j,i+1,n)
	{
		db k=(a[j].se-a[i].se)/(a[j].fi-a[i].fi),b=a[i].se-a[i].fi*k;
		PI c=mp(k*eps,b*eps);
		if(!mp[c]) mp[c]=++tot,ct[tot]=0;
		++ct[mp[c]];fa[val(i,j)]=fa[val(j,i)]=mp[c];
	}
	fo(i,1,n)
	{
		fo(j,1,tot) vis[j]=0; 
		du[i]=0;
		fo(j,1,n) if(j!=i)
		{
			int p=fa[val(i,j)];
			if(!vis[p]) vis[p]=1,++du[i];
		}
	}
	fo(i,1,n) fo(j,i+1,n)
	{
		
	}
	return 0;
}








