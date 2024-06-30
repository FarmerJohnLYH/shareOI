#include <map>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
const int N=100100,M=200200;
int n,m;
int sz[N];
map< pair<int,int> ,int> mp;
vector<int> to[N];
bool cmp(int x,int y)
{
	return(sz[x]<sz[y]||(sz[x]==sz[y]&&x<y));
}
int q,d[N],d0;
int f[N],ck[N],cnt[N];
int find(int a,int le,int ri,int pv)
{
	int rt=0;
	while(le<=ri)
	{
		int mid=(le+ri)>>1;
		if(to[a][mid][sz]>=pv) rt=mid,ri=mid-1;
		else le=mid+1;
	}
	return rt;
}
int fa[N];
int gf(int x)
{
	return(fa[x]==x)?x:(fa[x]=gf(fa[x]));
}
void combine(int x,int y)
{
	int fx=gf(x),fy=gf(y);
	if(fx!=fy)
		fa[fx]=fy;
}
int vis[N];
int main()
{
//	freopen("connect.in","r",stdin);
//	freopen("connect.out","w",stdout);
	freopen("D:/LiuYuanHao/b.in","r",stdin);
	freopen("D:/LiuYuanHao/b.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	fo(i,1,m)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		to[x].push_back(y),to[y].push_back(x);
		++sz[x],++sz[y];
		mp[make_pair(x,y)]=mp[make_pair(y,x)]=1;
	}
	fo(x,1,n)
		sort(to[x].begin(),to[x].end(),cmp);
	memset(cnt,128,sizeof cnt);
	while(q--)
	{
 		scanf("%d",&d0);
		fo(i,1,d0) scanf("%d",&d[i]);
		sort(d+1,d+1+d0,cmp);
		fo(i,1,d0) fa[d[i]]=d[i],ck[d[i]]=q,vis[d[i]]=0;
		int ans=0;
		if(1ll*d0*d0<=500000)
		{
			fo(i,1,d0)
			{
				int x=d[i];
				fo(j,i+1,d0)
				if(gf(d[i])!=gf(d[j]))
				{
					int y=d[j];
					if(!mp[make_pair(x,y)]) combine(x,y); 
				}
			}
		}
		else
		{
		}
			ans=0;
			fo(i,1,d0) 
			{
				int pi=gf(d[i]);
				if(cnt[pi]!=q) cnt[pi]=q,++ans;
			}
		printf("%d\n",ans);	
	}
	return 0;
}








