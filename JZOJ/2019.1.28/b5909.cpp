#include<cstring>
#include<cstdio>
#include<algorithm>
#include<set>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;i++)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;i--)
#define ll long long
#define link(x,y)(ne[++js]=la[x],la[x]=js,to[js]=y)
#define link2(x,y)(pf[y]=x,ne2[++js]=la2[x],la2[x]=js,to2[js]=y)
#define ff(x)for(int i=la[x];i;i=ne[i])
#define ff2(x)for(int i=la2[x];i;i=ne2[i])
#define min(a,b)(a<b?a:b)
using namespace std;
const int N=2e5+5,mo=1e9+7;
int n,nn,m,Q,x,y,la[N],ne[N],to[N],js,a[N];
int la2[N],ne2[N],to2[N],d[N];
int dn[N],lo[N],z[N],zs,pf[N];
int ld[N],hv[N],t[N*3],M,ans,dy[N],pl,pr;
multiset<int>A[N];
bool bz[N];
void R(int &n){
	char c;for(n=0;(c=getchar())<'0'||c>'9';);
	for(;c<='9'&&c>='0';c=getchar())n=n*10+c-48;
}
void tar(int x){
	z[dn[x]=lo[x]=++zs]=x;int y;
	ff(x)if(dn[y=to[i]])!bz[i]?lo[x]=min(lo[x],dn[y]):0;
	else{
		bz[i^1]=1;tar(y);lo[x]=min(lo[x],lo[y]);
		if(lo[y]>dn[x])link2(x,y),zs--;
		if(lo[y]==dn[x])for(++nn,link2(x,nn);z[zs]!=x;zs--)A[nn].insert(a[z[zs]]),link2(nn,z[zs]);
	}
}
void go(int x){
	ld[x]=1;d[x]=d[pf[x]]+1;
	ff2(x)go(to2[i]),ld[x]+=ld[to2[i]],(ld[to2[i]]>ld[hv[x]]?hv[x]=to2[i]:0);
}
void go2(int x,int st){
	ld[x]=st;dn[x]=++js;dy[js]=x;
	if(!hv[x])return;
	go2(hv[x],st);
	ff2(x)if(to2[i]!=hv[x])go2(to2[i],to2[i]);
}
void ch(int x,int y){
	for(t[x=M+x]=y;x>>=1;)t[x]=min(t[x*2],t[x*2|1]);
}
void qu(){
	for(pl+=M-1,pr+=M+1;pl^pr^1;pl>>=1,pr>>=1){
		if(~pl&1)ans=min(ans,t[pl^1]);
		if(pr&1)ans=min(ans,t[pr^1]);
	}
}
void get(int x,int y){
	for(;ld[x]!=ld[y];x=pf[ld[x]]){
		if(d[ld[x]]<d[ld[y]])swap(x,y);
		pl=dn[ld[x]];pr=dn[x];qu();
	}
	if(d[x]>d[y])swap(x,y);
	pl=dn[x];pr=dn[y];qu();
	if(x>n&&pf[x]&&pf[x]<=n)ans=min(ans,a[pf[x]]);
}
int main(){
	freopen("paoshang.in","r",stdin);
	freopen("paoshang.out","w",stdout);
	R(n);R(m);js=1;nn=n;
	fo(i,1,n)R(a[i]);
	fo(i,1,m)R(x),R(y),link(x,y),link(y,x);
	js=0;tar(1);
	fo(i,n+1,nn)a[i]=*A[i].begin();
	go(1);js=0;go2(1,1);
	for(M=1;M<=nn+1;M<<=1);
	fo(i,M+1,M+nn)t[i]=a[dy[i-M]];
	fd(i,1,M-1)t[i]=min(t[i*2],t[i*2|1]);
	for(R(Q);Q--;){
		scanf("\n");
		if(getchar()=='C'){
			R(x);R(y);
			ch(dn[x],y);
			if((pr=pf[x])>n){
				A[pr].erase(A[pr].find(a[x]));A[pr].insert(y);
				if(a[pr]!=(pl=*A[pr].begin()))ch(dn[pr],pl),a[pr]=pl;
			}
			a[x]=y;
		}else{
			ans=1e9;
			R(x);R(y);
			get(x,y);
			printf("%d\n",a[x]-ans);
		}
	}
}