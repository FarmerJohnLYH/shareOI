//#pragma GCC optimize(2)
#include <map>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define fo(i,x,y) for (ll pq = (y),i = (x);i <= pq;++ i)
#define fd(i,x,y) for (ll pq = (y),i = (x);i >= pq;-- i)
#define oo 2139062143
using namespace std;
typedef double db;
typedef long long ll;
ll lowbit(ll x) {
	return((x)&(-x));
}
ll min(ll x,ll y) {
	return (x>y)?(y):(x);
}
ll max(ll x,ll y) {
	return (x>y)?(x):(y);
}
const ll N=20200*4,M=200200*4,QN=5050*4;
struct node {
	ll fr,to,nex,fw;
} e[M*2];
ll lev[N];
ll las[N],mem[N]/*memory*/;
ll n,m,tot,s,t;
void link(ll u,ll v,ll c) {
	e[++tot].to=v,e[tot].nex=las[u],e[tot].fw=c;
	las[u]=tot;
	e[tot].fr=u;
	e[++tot].to=u,e[tot].nex=las[v],e[tot].fw=0;
	las[v]=tot;//反向
	e[tot].fr=v;
}
ll q[N];
bool bfs() {
	fo(i,s,t) lev[i]=-1,mem[i]=las[i];
	lev[s]=0,q[1]=s;
	ll hd=0,tl=1;
	while(hd++<tl) {
		ll now=q[hd];
		for(ll tmp=las[now]; tmp; tmp=e[tmp].nex)
			if(e[tmp].fw>0&&lev[e[tmp].to]==-1) {
				lev[e[tmp].to]=lev[now]+1;
				q[++tl]=e[tmp].to;
			}
	}
	return(lev[t]!=-1);
	//距离标号
}
ll dfs(ll now,ll fw/*应当流的大小*/) {
	if (now==t) return fw;
	ll cst=0;
	for(ll tmp=mem[now]; tmp; tmp=e[tmp].nex) {
		mem[now]=tmp;
		if (e[tmp].fw>0&&lev[e[tmp].to]==lev[now]+1) {
			ll fwt=dfs(e[tmp].to,min(e[tmp].fw,fw - cst));
			cst+=fwt,e[tmp].fw-=fwt,e[tmp^1].fw+=fwt;
			if(fw==cst) return cst;
		}
	}
	return cst;
}
ll ppp[2][N];
ll ida[3628888],idb[3628888];
ll qn,qk;
char qs[QN][5500];
ll hh[3628888],H[2][QN];
ll hash(char* x,ll y) {
	ll val=0;
	fo(l,1,y) val=(11ll*val+29ll*(x[l-1]-'A'+3))%998244353;
	ll rt=0;
	fo(l,1,y) rt=(19ll*val+37ll*(x[l-1]-'A'+7))%3628799;
	while(hh[rt]!=val&&hh[rt]!=0) rt=(rt+2)%3628799;
	hh[rt]=val;
	return rt;
}
ll bz[2][N],ans[2][N];
ll d[N];
ll pd[N];
void gtway() 
{
	ll hd=0,tl=1;
	d[1]=s,pd[s]=1;
	while(hd++<tl) {
		ll now=d[hd];
		for(ll tmp=las[now]; tmp; tmp=e[tmp].nex)
			if(e[tmp].fw>0) {
				ll to=e[tmp].to;
				if(!pd[to]) {
					pd[to]=1;
					d[++tl]=to;
				}
			}
	}
	fo(i,1,ans[0][0])
	if(!pd[ans[0][i]])
	if(pd[ans[1][i]])
		bz[0][i]=1;
	fo(i,1,ans[1][0])
		bz[1][i]=1;
	memset(pd,0,sizeof pd);
}
ll buf[N];
int main() {
//	freopen("group.in","r",stdin);
//	freopen("group.out","w",stdout);
	freopen("D:/LiuYuanHao/c3.in","r",stdin);
	freopen("D:/LiuYuanHao/c.out","w",stdout);
	tot=1;//便于寻找反向弧
	scanf("%lld%lld",&qn,&qk);
	s=1,t=1;
	ll en=20002;
	fo(i,1,qn) {
		scanf("%s",qs[i]);
		ll len=strlen(qs[i]),tmp=hash(qs[i],qk),xx,yy;
		H[0][i]=tmp; 
		if(!ida[tmp])
		{
			ida[tmp]=++t,link(s,t,1);
			ans[0][++ans[0][0]]=t;
			ppp[0][ans[0][0]]=i;
		}
		xx=ida[tmp];
		ll to=ida[tmp];
		H[1][i]=tmp=hash(qs[i]+len-qk,qk);
		if(!idb[tmp]) 
		{
			idb[tmp]=++t,link(t,en,1);
			ans[1][++ans[1][0]]=t;
			ppp[1][ans[1][0]]=i;
		}
		yy=idb[tmp];
		link(xx,yy,oo);
	}
	t=en;
	//构图
	ll sum=0;
	for(; bfs();)
		sum+=dfs(s,oo);
	gtway();
	printf("%lld\n",sum);
	int cnt=0;
	fo(i,1,ans[1][0])
	if(bz[1][i]) {
		buf[0]=0;
		fo(j,1,qn)
		if(!pd[j]&&H[1][j]==H[1][ppp[1][i]]) {
			pd[j]=1;
			buf[++buf[0]]=j;
		}
		cnt+=buf[0];
		printf("%lld ",buf[0]);
		fo(j,1,buf[0]) printf("%lld ",buf[j]);
		printf("\n");
	}
	fo(i,1,ans[0][0])
	if(bz[0][i]) {
		buf[0]=0;
		fo(j,1,qn)
		if(!pd[j])
			if(H[0][j]==H[0][ppp[0][i]]) {
				pd[j]=1;
				buf[++buf[0]]=j;
			}
		printf("%lld ",buf[0]);
		cnt+=buf[0];
		fo(j,1,buf[0]) printf("%lld ",buf[j]);
		printf("\n");
	}
	return 0;
}
