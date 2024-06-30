#include <cstdio>
#include <cstring>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define fd(i,x,y) for (int i=(x);i>=(y);--i)
using namespace std;
const int N=100100*4,M=50500,E=22,mo=998244353;
int sa[N],rnk[N],se[N];
int tn[N],he[N],p[N];
char s[N],T[N];
int n,m,_;
bool cmp(int *r,int a,int b,int l)
{
	return r[a]==r[b]&&r[a+l]==r[b+l];
}
void gtsa(int *x,int *y,int m)
{
	fo(i,0,m) tn[i]=0;
	fo(i,1,n) ++tn[x[y[i]]];
	fo(i,1,m) tn[i]+=tn[i-1];
	fd(i,n,1) 
		sa[tn[x[y[i]]]--]=y[i];		
}
void solve(char *r,int *sa,int n,int m)
{
	int *x=rnk,*y=se,*t;
	r[n+1]=-1;
	fo(i,1,n)x[i]=r[i]-'0'+1,y[i]=i;
	gtsa(x,y,m);
	int ct=0;
	for(int len=1;len<=n;len<<=1)
	{
		ct=0;
		fo(i,n-len+1,n) y[++ct]=i;
		fo(i,1,n)if(sa[i]>len) y[++ct]=sa[i]-len;
		gtsa(x,y,m);
		t=x,x=y,y=t;x[sa[ct=1]]=1;
		fo(i,2,n) x[sa[i]]=cmp(y,sa[i-1],sa[i],len)?(ct):(++ct);
		m=ct;
	}
}
int min(int x,int y){return(x<y)?x:y;}
int max(int x,int y){return(x>y)?x:y;}
void gthe(char *r,int *sa,int n)
{
	fo(i,1,n) rnk[sa[i]]=i;
	int k=0;
	fo(i,1,n)
	{
		k=max(k-1,0);
		while(r[i+k]==r[sa[rnk[i]-1]+k]) ++k;
		he[rnk[i]]=k;
	} 
}
int root[N];
struct seg{
	int a[N*E],to[N*E][2];
	int tot;
	void nwadd(int x,int l,int r,int p)
	{
		if(l==r) 
		{
			++a[x];
			return;
		}
		int mid=(l+r)>>1;
		if(p<=mid)
		{
			++tot;fo(j,0,1) to[tot][j]=to[to[x][0]][j];
			a[tot]=a[to[x][0]];
			to[x][0]=tot;
			nwadd(to[x][0],l,mid,p);
		} 
		else 
		{
			++tot;fo(j,0,1) to[tot][j]=to[to[x][1]][j];
			a[tot]=a[to[x][1]];
			to[x][1]=tot;
			nwadd(to[x][1],mid+1,r,p);
		}
		a[x]=to[x][0][a]+to[x][1][a];
	}
	int query(int x,int l,int r,int ql,int qr)
	{
		if(!x)return 0;
		if(ql<=l&&r<=qr)return(a[x]);
		int mid=(l+r)>>1,rt=0;
		if(ql<=mid)rt+=query(to[x][0],l,mid,ql,qr);
		if(qr>mid) rt+=query(to[x][1],mid+1,r,ql,qr);
		return rt;
	}
	void build()
	{
		tot=0;
		fo(i,1,n)
		{
			root[i]=++tot;fo(l,0,1)to[root[i]][l]=to[root[i-1]][l];
			nwadd(root[i],1,n,rnk[i]);
		}
//		printf("");
	}
}t;
int hs[N];
int str(int l,int r)
{
	return(((hs[r]-1ll*hs[l-1]*p[r-l+1])%mo+mo)%mo);
}
int le[N],ri[N];
int judge(int x,int v)
{
	fo(i,1,v)if(s[x+i-1]!=T[i]) return(s[x+i-1]<T[i]);
	return 2;
}
int find(int le,int ri,int sta,int len)
{
	int rt=sta?(-oo):oo;
	while(le<=ri)
	{
		int mid=(le+ri)>>1,pd=judge(sa[mid],len);
		if(pd>1) 
		{
			rt=mid;
			if(sta) le=mid+1;else ri=mid-1;
		}
		else
		if(pd)le=mid+1;else ri=mid-1;
	}
	return rt;
}
int main()
{
	freopen("slasticar.in","r",stdin);
	freopen("slasticar.out","w",stdout); 
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
//	freopen("D:/LiuYuanHao/a.out","w",stdout);
	scanf("%d",&n);
	scanf("%s",s+1);
	solve(s,sa,n,11);
	gthe(s,sa,n);
	p[0]=1,p[1]=13;fo(i,2,n+1) p[i]=(1ll*p[i-1]*p[1])%mo;
	hs[0]=0;fo(i,1,n+M) hs[i]=(1ll*hs[i-1]*p[1]+(s[i]-'0'+1))%mo;
	t.build();
	scanf("%d",&_);
  	while(_--)
	{
		scanf("%s",T+1);m=strlen(T+1);m=min(m,n);
		int val=0;fo(i,1,m) val=(1ll*val*p[1]+(T[i]-'0'+1))%mo;
		le[0]=1,ri[0]=n;
		fo(i,1,m+1)
		{
			le[i]=find(le[i-1],ri[i-1],0,i-1);
			ri[i]=find(le[i-1],ri[i-1],1,i-1);
		}
		int en=0;
		if(le[m+1]<=ri[m+1]) 
		{
			int mn=oo;
			fo(i,le[m+1],ri[m+1])
			if(sa[i]<mn) mn=sa[i];
			en=mn;
		}
		else en=n;
		int ans=0;
		fo(i,1,m)
		if(le[i]<=ri[i])
			ans+=t.query(root[en],1,n,le[i],ri[i]);
		else break;
		printf("%d\n",ans);
	}
}





