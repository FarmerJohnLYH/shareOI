 #pragma GCC optimize(2) 
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<map>
#include<vector>
#define cl(x) memset(x,0,sizeof(x))
using namespace std;
typedef pair<int,int> abcd;
inline char nc(){
  static char buf[100000],*p1=buf,*p2=buf;
  return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
inline void read(int &x){
  char c=nc(),b=1;
  for (;!(c>='0' && c<='9');c=nc()) if (c=='-') b=-1;
  for (x=0;c>='0' && c<='9';x=x*10+c-'0',c=nc()); x*=b;
}

const int N=140140;

struct edge{
  int u,v,next;
}G[N<<3];
int head[N],head2[N],inum;
inline void add(int u,int v,int *head){
  int p=++inum; G[p].u=u; G[p].v=v; G[p].next=head[u]; head[u]=p;
}
inline void link(int u,int v,int *head){
  add(u,v,head); add(v,u,head);
}
#define V G[p].v
int n;
int deg[N];
int pt[N][3];

map<abcd,int> ed;
inline void BT(){
  static int Q[N],l,r,rem[N];
  l=r=-1; cl(rem);
  for (int i=1;i<=n;i++) if (deg[i]==2) Q[++r]=i;
  for (int i=1;i<=n-2;i++){
    int u=Q[++l],a[3]; rem[u]=1;
    *a=0;
    for (int p=head[u];p;p=G[p].next)
      if (!rem[V])
    a[++*a]=V;
    pt[i][0]=u; pt[i][1]=a[1]; pt[i][2]=a[2];
    if ((--deg[a[1]])==2) Q[++r]=a[1];
    if ((--deg[a[2]])==2) Q[++r]=a[2];
  }
  for (int s=1;s<=n-2;s++){
    for (int i=0;i<3;i++)
      for (int j=0;j<i;j++){
    int u=pt[s][i],v=pt[s][j];
    if (u>v) swap(u,v);
    if (ed.count(abcd(u,v)))
      link(s,ed[abcd(u,v)],head2);
    else
      ed[abcd(u,v)]=s;
      }
  }
}

int del[N];

int sum,minv,rt;
int size[N];
inline void Root(int u,int fa){
  size[u]=1; int maxv=0;
  for (int p=head2[u];p;p=G[p].next)
    if (V!=fa && !del[V])
      Root(V,u),size[u]+=size[V],maxv=max(maxv,size[V]);
  maxv=max(maxv,sum-size[u]);
  if (maxv<minv) minv=maxv,rt=u;
}

int c[N],col=4;
int ins[N],clk;
int dis[3][N];

inline void bfs(int S,int *dis){
  static int Q[N],l,r;
  l=r=-1; ++clk;
  Q[++r]=S; dis[S]=0; ins[S]=clk;
  while (l<r){
    int u=Q[++l];
    for (int p=head[u];p;p=G[p].next)
      if (c[V]==c[u] && ins[V]!=clk){
    dis[V]=dis[u]+1;
    ins[V]=clk;
    Q[++r]=V;
      }
  }
}

int Col;
inline void color(int u,int fa){
  size[u]=1;
  for (int i=0;i<3;i++) c[pt[u][i]]=Col;
  for (int p=head2[u];p;p=G[p].next)
    if (V!=fa && !del[V])
      color(V,u),size[u]+=size[V];
}

struct event{
  int u,v,idx;
  event(int u=0,int v=0,int idx=0):u(u),v(v),idx(idx){ }
};

int Ans[N<<1];

inline void Divide(int u,vector<event> &que){
  if (que.empty()) return;
  del[u]=1;
  for (int i=0;i<3;i++)
    bfs(pt[u][i],dis[i]);
  Col=0;
  for (int p=head2[u];p;p=G[p].next)
    if (!del[V]){
      Col++;
      color(V,0);
    }
  for (int i=0;i<3;i++) c[pt[u][i]]=0;
  vector<event> vec[4];
  for (int i=0;i<(int)que.size();i++){
    int a=que[i].u,b=que[i].v,idx=que[i].idx;
    if (c[a]==0){
      for (int j=0;j<3;j++)
    if (a==pt[u][j])
      Ans[idx]=dis[j][b];
    }else if (c[b]==0){
      for (int j=0;j<3;j++)
    if (b==pt[u][j])
      Ans[idx]=dis[j][a];
    }else if (c[a]!=c[b]){
      Ans[idx]=1<<30;
      for (int j=0;j<3;j++)
    Ans[idx]=min(Ans[idx],dis[j][a]+dis[j][b]);
    }else{
      vec[c[a]].push_back(que[i]);
    }
  }
  for (int p=head2[u],i=0;p;p=G[p].next)
    if (!del[V]){
      Col=++col; color(V,0);
      sum=size[V]; minv=1<<30;
      Root(V,0);
      Divide(rt,vec[++i]);
    }
}

int main(){
  int iu,iv,Q;
  // freopen("D:/LiuYuanHao/a.in","r",stdin);
  freopen("bsh.in","r",stdin);
  freopen("bsh.out","w",stdout);
  read(n);
  for (int i=1;i<n;i++) link(i,i+1,head);
  link(n,1,head);
  for (int i=1;i<=n;i++) deg[i]=2; 
  for (int i=1;i<=n-3;i++)
    read(iu),read(iv),link(iu,iv,head),deg[iu]++,deg[iv]++;
  BT();
  read(Q);
  vector<event> vec;
  for (int i=1;i<=Q;i++)
    read(iu),read(iv),vec.push_back(event(iu,iv,i));
  sum=n-2; minv=1<<30;
  Root(1,0);
  for (int i=1;i<=n;i++) c[i]=col;
  Divide(rt,vec);
  for (int i=1;i<=Q;i++)
    printf("%d\n",Ans[i]);
  return 0;
}