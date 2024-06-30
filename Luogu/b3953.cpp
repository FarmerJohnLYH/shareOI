#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <algorithm>
#include <utility>
#define mp(A,B) make_pair(A,B)
using namespace std;
const int maxn=100010;
const int maxm=200010;
int n,m,cnt,K,P,tot,ans;
int to[maxm],next[maxm],val[maxm],head[maxn],dis[maxn],vis[maxn],d[maxn],q[maxn<<1],f[51][maxn];
int to2[maxm],next2[maxm],val2[maxm],head2[maxn],dis2[maxn];
priority_queue<pair<int,int> > pq;
inline int rd()
{
    int ret=0;  char gc=getchar();
    while(gc<'0'||gc>'9') gc=getchar();
    while(gc>='0'&&gc<='9')   ret=ret*10+gc-'0',gc=getchar();
    return ret;
}
inline void add(int a,int b,int c)
{
    to[cnt]=b,val[cnt]=c,next[cnt]=head[a],head[a]=cnt;
    to2[cnt]=a,val2[cnt]=c,next2[cnt]=head2[b],head2[b]=cnt++;
    //to 正 
    //to2 反
}
inline void upd(int &x,int y)
{
    x=(x+y)%P;
}
void work()
{
    n=rd(),m=rd(),K=rd(),P=rd();
    int i,j,k,a,b,c,u;
    memset(head,-1,sizeof(head)),memset(head2,-1,sizeof(head2)),cnt=tot=ans=0;
    for(i=1;i<=m;i++)    a=rd(),b=rd(),c=rd(),add(a,b,c);
    //1
    memset(vis,0,sizeof(vis)),memset(dis,0x3f,sizeof(dis)),memset(d,0,sizeof(d));
    pq.push(mp(0,1)),dis[1]=0;
    while(!pq.empty())
    {
        u=pq.top().second,pq.pop();
        if(vis[u])  continue;
        vis[u]=1;
        for(i=head[u];i!=-1;i=next[i])  if(dis[to[i]]>dis[u]+val[i]) dis[to[i]]=dis[u]+val[i],pq.push(mp(-dis[to[i]],to[i]));
    }
    //2
    memset(dis2,0x3f,sizeof(dis2)),memset(vis,0,sizeof(vis));
    pq.push(mp(0,n)),dis2[n]=0;
    while(!pq.empty())
    {
        u=pq.top().second,pq.pop();
        if(vis[u])  continue;
        vis[u]=1;
        for(i=head2[u];i!=-1;i=next2[i])    if(dis2[to2[i]]>dis2[u]+val2[i]) dis2[to2[i]]=dis2[u]+val2[i],pq.push(mp(-dis2[to2[i]],to2[i]));
    }
    //3
    for(i=1;i<=n;i++)    for(j=head[i];j!=-1;j=next[j])  if(dis[i]+val[j]==dis[to[j]])   d[to[j]]++;
    for(i=1;i<=n;i++)    if(!d[i])   q[++tot]=i;
    for(j=1;j<=tot;j++)
    {
        u=q[j];
        for(i=head[u];i!=-1;i=next[i])  if(dis[u]+val[i]==dis[to[i]])
        {
            d[to[i]]--;
            if(!d[to[i]])   q[++tot]=to[i];
        }
    }
    for(i=1;i<=n;i++)    if(d[i]&&dis[i]+dis2[i]<=dis[n]+K)
    {
        printf("-1\n");
        return ;
    }
    //DP
    memset(f,0,sizeof(f));
    f[0][1]=1;
    for(k=0;k<=K;k++)
    {
        for(i=1;i<=tot;i++)  for(u=q[i],j=head[u];j!=-1;j=next[j])   if(dis[u]+val[j]==dis[to[j]])
        {
            upd(f[k][to[j]],f[k][u]);
        }
        for(i=1;i<=n;i++)    for(j=head[i];j!=-1;j=next[j])  if(dis[i]+val[j]!=dis[to[j]]&&k+dis[i]+val[j]-dis[to[j]]<=K)
        {
            upd(f[k+dis[i]+val[j]-dis[to[j]]][to[j]],f[k][i]);
        }
    }
    for(i=0;i<=K;i++)    upd(ans,f[i][n]);
    printf("%d\n",ans);
}
int main()
{
    //freopen("park.in","r",stdin);
    //freopen("park.out","w",stdout);
    int T=rd();
    while(T--)  work();
    return 0;
}