#include<cstdio>
#include<iostream>
#include<cstring>
#define low(x) (x&(-x))
using namespace std;
const int N=2e5+10,M=6e5+10,mxy=1e6;
int w[M],ne[M],la[N],fa[N],fr[N];
int dep[N],ld[N],size[N],dfn[N],hs[N];
int a[N],vis[N],mrk[N];
int q[N],nq[N],lq[N],tp[N],ans[N];
int n,m,Q,t;
void link(int x,int y){
	w[++t]=y;
	ne[t]=la[x];
	la[x]=t;
}
void pre(int x){
	vis[x]=1;
	for (int y=la[x];y;y=ne[y]){
		if (mrk[y])continue;
		int z=w[y];
		if (vis[z]){
			for (int p=x;p-z;p=fr[p])
			fa[p]=z;
		}
		else {
			fr[z]=x;
			mrk[y]=mrk[y^1]=1;
			pre(z);
		};
	}
	if (!fa[x])fa[x]=fr[x];
	vis[x]=0;
}
int tr[N*10][2],ct[N*10]; 
void flip(int x,int v){
	int k=(ct[x]+=v)&1,a0=1,a1=-1;
	if (k&1)a1=1,a0=-1;
	if (ct[x]==1&&v==1||ct[x]==0&&v==-1)a0=0;
	for (;x<=mxy;x+=low(x))tr[x][0]+=a0,tr[x][1]+=a1;
}
int que(int x,int v){
	int ans=0;
	for (;x;x-=low(x))ans+=tr[x][v];
	return ans;
}
void go(int x,int v){
	for (int y=la[x];y;y=ne[y])go(w[y],v);
	flip(a[x],v);
}
void dfs0(int x){
	for (int y=la[x];y;y=ne[y]){
		int z=w[y];
		dfs0(z);
		size[x]+=size[z];
		if (!hs[x]||size[z]>size[hs[x]])hs[x]=z;
	}
	size[x]++;
}
void dfs(int x){
	for (int y=la[x];y;y=ne[y])if (w[y]!=hs[x])dfs(w[y]);
	if (hs[x])dfs(hs[x]);
	for (int y=la[x];y;y=ne[y])if (w[y]!=hs[x])go(w[y],1);
	flip(a[x],1);
	for (int y=lq[x];y;y=nq[y])ans[y]=que(q[y],tp[y]);
	if (hs[fa[x]]!=x)go(x,-1);
}
int main(){
	freopen("map.in","r",stdin);
	freopen("map.out","w",stdout);
	cin>>n>>m;t=1;
	for (int i=1;i<=n;i++)scanf("%d",&a[i]);
	for (int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		link(x,y);
		link(y,x);
	}
	pre(1);
	memset(la,0,sizeof la);t=0;
	for (int i=2;i<=n;i++)link(fa[i],i);t=0;
	cin>>Q;
	for (int i=1;i<=Q;i++){
		int ty,x,y;
		scanf("%d%d%d",&ty,&x,&y);
		q[i]=y;tp[i]=ty;
		nq[i]=lq[x];
		lq[x]=i;
	}
	dfs0(1);
	dfs(1);
	for (int i=1;i<=Q;i++)printf("%d\n",ans[i]);
}