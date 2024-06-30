#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
const int N=200200;
int n,T;
int du[N];
int flag,ans;
vector<int> to[N];
int sz[N],rot,cp[N],vis[N];
int bz[N],all,nd[N];
int cnt=0,fa[N];/*
void init(int x,int f)
{
	nd[++cnt]=x,fa[x]=f;
	sz[x]=1,cp[x]=0;
	for(int p=to[x].size()-1,i=0;i<=p;++i)
	if(to[x][i]!=f&&!vis[to[x][i]])
	{
		init(to[x][i]);
		sz[x]+=sz[to[x][i]];
		cp[x]=max(cp[x],to[x][i][sz]);
	}
	cp[x]=max(cp[x],all-sz[x]);
	if(rot==0||cp[x]>cp[rot]) rot=x;
}
int ldp,tot,att;
void run(int x,int f,int d)
{
	++att;
	int ck=0;
	for(int p=to[x].size()-1,i=0;i<=p;++i)
	if(to[x][i]!=f&&!vis[to[x][i]])
	{
		if(ldp<0)return;
		ck=1;
		run(to[x][i]);
	}
	if(!ck)
	{
		if(ldp==0||ldp==d) ldp=d;
		else ldp=-1;
	}
}
int check(int x)
{
	fo(i,1,nd[cnt]) if(nd[i][bz]) 
	{
		ldp=att=0;
		run(i,0,0);
		if(ldp>=0&&att==tot) return 1; 
	}
	return 0;
}
void work(int x)
{
	if(x>cnt)
	{
		if(check(nd[1])) ++ans;
		return;
	}
	work(x+1);
	if(fa[nd[x]][bz])
	{
		bz[nd[x]]=1;
		++tot;
		work(x+1);	
		--tot;
		bz[nd[x]]=0;
	}
}
void solve(int x)
{
	vis[x]=1;cnt=0;
	init(x,0);
	bz[x]=1;
	work(2);
}*/
int main()
{
	freopen("homework.in","r",stdin);
	freopen("homework.out","w",stdout);
	// freopen("D:/LiuYuanHao/c.in","r",stdin);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		fo(i,1,n) 
		{
			du[i]=vis[i]=0;
			while(!to[i].empty()) to[i].pop_back();
		}
		fo(i,1,n-1)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			to[x].push_back(y),to[y].push_back(x);
			++du[x],++du[y];
		}
		flag=0,ans=0;
		// fo(i,1,n) 
			// if(du[x]!=2)
			// {
				// if(d/u[x]!=1)
				// {
					// flag=0;
					// break;
				// }else ++flag;
			// }
		// if(flag)
		{
			ans=n;
			fo(i,1,n) ans+=(n-i)/2;
			printf("%d\n",ans);
			continue;
		}
		// rot=1,all=n;
		// solve(1);
		// printf("%d\n",ans);
	}
	return 0;
}








