#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

const int N=300005;

int n,m,A,B,cnt,last[N],tot,low[N],dfn[N],stack[N],top,a[N],val[N],bel[N],deg[N],tim,mx[N];
bool ins[N];
pair<int,int> pts[N],s[N];
struct edge{int to,from,next;}e[N*12];
priority_queue<int> que;
vector<int> vec[N];
queue<int> que1;
bool vis[N];

int read()
{
    int x=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

void addedge(int u,int v)
{
    e[++cnt].from=u;e[cnt].to=v;e[cnt].next=last[u];last[u]=cnt;
}

void tarjan(int x)
{
    dfn[x]=low[x]=++tim;
    stack[++top]=x;ins[x]=1;
    for (int i=last[x];i;i=e[i].next)
        if (!dfn[e[i].to])
        {
            tarjan(e[i].to);
            low[x]=min(low[x],low[e[i].to]);
        }
        else if (ins[e[i].to]) low[x]=min(low[x],dfn[e[i].to]);
    if (low[x]==dfn[x])
    {
        tot++;int y=0;
        while (y!=x)
        {
            y=stack[top];top--;ins[y]=0;bel[y]=tot;
            if (val[y]) vec[tot].push_back(y),mx[tot]=max(mx[tot],pts[y].second);
        }
    }
}

void topusort()
{
    for (int i=1;i<=tot;i++) if (!deg[i]) que1.push(i);
    int a1=0;
    while (!que1.empty())
    {
        int u=que1.front();que1.pop();a[++a1]=u;
        for (int i=last[u];i;i=e[i].next)
        {
            deg[e[i].to]--;
            if (!deg[e[i].to]) que1.push(e[i].to);
        }
    }
}

void get_mx(int x)
{
    if (vis[x]) return;
    vis[x]=1;
    for (int i=0;i<vec[x].size();i++) que.push(pts[vec[x][i]].second);
    for (int i=last[x];i;i=e[i].next)
    {
        if (!vis[e[i].to]) get_mx(e[i].to);
        mx[x]=max(mx[x],mx[e[i].to]);
    }
}

int main()
{
    n=read();m=read();A=read();B=read();
    for (int i=1;i<=n;i++) pts[i].first=read(),pts[i].second=read(),mx[i]=-1;
    for (int i=1;i<=m;i++)
    {
        int x=read(),y=read(),z=read();
        if (z==1) addedge(x,y);
        else addedge(x,y),addedge(y,x);
    }
    int s1=0;
    for (int i=1;i<=n;i++)
        if (pts[i].first==A) val[i]=1;
        else if (pts[i].first==0) s[++s1]=make_pair(pts[i].second,i);
    sort(s+1,s+s1+1);
    for (int i=1;i<=n;i++) if (!dfn[i]) tarjan(i);
    for (int i=1;i<=n;i++) last[i]=0;
    int tmp=cnt;
    for (int i=1;i<=tmp;i++)
    {
        int x=bel[e[i].from],y=bel[e[i].to];
        if (x!=y) addedge(x,y),deg[y]++;
    }
    topusort();
    for (int i=s1;i>=1;i--)
    {
        int x=s[i].second;
        get_mx(bel[x]);
        if (mx[bel[x]]<0) {printf("%d\n",0);continue;}
        while (!que.empty()&&que.top()>mx[bel[x]]) que.pop();
        printf("%d\n",que.size());
    }
    return 0;
}