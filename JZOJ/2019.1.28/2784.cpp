#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#define oo 2139062143
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
typedef pair<int,int> PI;
const int N=100100*8;
int n,m,len;
PI a[N];
int w[N];
char st[N];
struct tree{
	int to[N],nex[N],las[N];
	int tot,fa[N],sz[N],cnt;
	int dfn[N];
	void link(int x,int y)
	{
		to[++tot]=y,tot[nex]=las[x];
		las[x]=tot;
	}
	void dfs(int x)
	{
		dfn[x]=++cnt;
		for (int tp=las[x];tp;tp=tp[nex])
		if(tp[to]!=fa[x])
		{
			int tt=tp[to];tt[fa]=x;
			dfs(tt);
			sz[x]+=sz[tt];
		}
		++sz[x];
	}
}t;
int tr[N];
void add(int x,int y)
{
	while(x<N) 
	{
		tr[x]+=y;
		x+=lowbit(x);
	}
}
int query(int x)
{
	int rt=0;
	while(x)
	{
		rt+=tr[x];
		x-=lowbit(x);
	}
	return rt;
}
int ans[N];
struct acmachine{  
	int son[N][26];
	int cnt;
	int fail[N],fa[N];
	void build()
	{
		int x=0;fa[0]=0;
		fo(i,1,len)
		{
			if(i[st]=='B') x=fa[x];
			else 
			if(i[st]=='P') w[++n]=x;
			else
			{
				if(!son[x][st[i]-'a'])
				{
					son[x][st[i]-'a']=++cnt;fa[cnt]=x;	
					fail[cnt]=0;memset(son[cnt],0,sizeof son[cnt]);
				}
				x=son[x][st[i]-'a'];
			}
		}
	}
	void getfail()  
	{  
		queue<int> q;  
		fail[0]=0;  
		fo(c,0,25)
		{  
			int u=son[0][c];  
			if(u)  
			{  
				fail[u]=0;
				q.push(u);
			}  
		}  
		while(!q.empty())  
		{  
			int r=q.front();
			q.pop();
			fo(c,0,25)
			{  
				int u=son[r][c];  
				if(!u)son[r][c]=son[fail[r]][c];
				else
				{
					q.push(u);  
					int v=fail[r]; 
					while(v&&!son[v][c]) v=fail[v];
					fail[u]=son[v][c];
				}
			}  
		}
		fo(i,1,cnt)
			t.link(fail[i],i);	
	}
	int to[N],las[N],nex[N],tot,id[N];
	void link(int x,int y,int v)
	{
		to[++tot]=y,nex[tot]=las[x],las[x]=tot;
		id[tot]=v;
	}
	void solve()
	{
		int x=0;
		add(t.dfn[0],1);
		fo(i,1,len)
		{
			if(i[st]=='B') 
			{
				add(t.dfn[x],-1);
				x=fa[x];
			}
			else 
			if(i[st]=='P')
			{
				for (int tp=las[x];tp;tp=tp[nex])
				{
					int p=tp[to][w];
					ans[id[tp]]+=query(t.dfn[p]+t.sz[p]-1)-query(t.dfn[p]-1);
				}
			}
			else
			{
				x=son[x][st[i]-'a'];
				add(t.dfn[x],1);
			}
		}
	}
}ac;  
int main()
{
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%s",st+1);len=strlen(st+1);
//	ac.sz=1;
//	ac.cnt=1;
	ac.build();
	ac.getfail();
	t.cnt=0;t.dfs(0);
	scanf("%d",&m);
	fo(i,1,m)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		ac.link(w[y],x,i);
	}
	ac.solve();
	fo(i,1,m)
		printf("%d\n",ans[i]);
	return 0;
}











