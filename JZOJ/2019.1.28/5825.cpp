#include <map>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define fd(i,x,y) for (int i=(x);i>=(y);--i)
#define fi first
#define se second
using namespace std;
typedef pair<int,int> PI;
typedef vector<int> VE;
const int N=200200*10;
map<int,VE> mp;
int n,v[N],sz[N];
char s[N];
int a0,tot=1;
PI ans[N];
int to[N][26];
vector<PI> a[N];
int cnt,di[N];
void add(int l)
{
	int x=1;
	fo(r,l,n)
	{
		if(!to[x][s[r]-'a'])to[x][s[r]-'a']=++tot;
		x=to[x][s[r]-'a'];
		++sz[x];
		a[x].push_back(make_pair(l,r));
	}
}
void dfs(int x)
{
	fd(i,25,0)
		if(to[x][i]) 
			dfs(to[x][i]);	
	++cnt;
	for(int p=a[x].size()-1,i=0;i<=p;++i)
	if(cnt==v[a[x][i].se]-v[a[x][i].fi-1]) 
		ans[++a0]=a[x][i];
}
int main()
{
	freopen("platform.in","r",stdin);
	freopen("platform.out","w",stdout);
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%s",s+1);
	n=strlen(s+1);
	fo(i,1,n) scanf("%d",&v[i]),v[i]+=v[i-1];
	if(n<=2020)
	{
		fo(i,1,n) add(i);
		cnt=0;
		dfs(1);
	}
	else
	{
		fd(i,n,1)
		{
			int tp=v[i-1]+i-1+n+1;
			if(!mp[tp].empty())
			for(int p=mp[tp].size()-1,j=0;j<=p;++j)
				ans[++a0]=make_pair(i,mp[tp][j]);
			mp[v[i]+i].push_back(i);
		}
	}
		sort(ans+1,ans+1+a0);
		printf("%d\n",a0);
		fo(i,1,a0) printf("%d %d\n",ans[i].fi,ans[i].se);
	return 0;
}











