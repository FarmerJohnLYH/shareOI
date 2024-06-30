#include<cstdio>
#include<iostream>
using namespace std;
struct data{
int to,next;
}e[50001],d[50001];
int head[10001];
int n,m,cnt,top;
int dfn[10001],low[10001],q[10001];
int scc,h[10001],belong[10001],hav[10001];
bool vis[10001],inq[10001];
int ans;
void dfs(int a)
{
	int now; 
	vis[a]=inq[a]=1;
	low[a]=dfn[a]=++cnt;
	q[++top]=a;
	int c=head[a];
	while(c)
	{
		if(!vis[e[c].to])
		{
			dfs(e[c].to);
			low[a]=min(low[a],low[e[c].to]);
		}
		else if(inq[e[c].to])low[a]=min(low[a],dfn[e[c].to]);//??????
		c=e[c].next;
	}
	if(low[a]==dfn[a])
	{
	    scc++;
	    while(now!=a)
        {
            now=q[top--];
            inq[now]=0;
            belong[now]=scc;
            ++hav[scc];
        }
	}
}
void rebuild()
{
	cnt=0;
	for(int i=1;i<=n;i++)
	{
		int c=head[i];
		while(c)
		{
			if(belong[i]!=belong[e[c].to])
		    {
		    	d[++cnt].to=belong[e[c].to];
		    	d[cnt].next=h[belong[i]];
		    	h[belong[i]]=cnt;
		    }
		    c=e[c].next;
		}
	}
}
void tarjan()
{
	for(int i=1;i<=n;i++)if(!vis[i])dfs(i);
    rebuild();
}
void work()
{
	for(int i=1;i<=scc;i++)
	   if(!h[i])
	   {
	   	   if(ans)
	   	   {
	   	   	  ans=0;return;
	   	   }
	   	   else ans=hav[i];
	   }
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
    {
    	int x,y;
    	scanf("%d%d",&x,&y);
    	e[i].to=y;
    	e[i].next=head[x];
    	head[x]=i;
    }
    tarjan();
    work();
    printf("%d",ans);
	return 0;
}