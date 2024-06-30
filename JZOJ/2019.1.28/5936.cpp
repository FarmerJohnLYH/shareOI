 #pragma GCC optimize(2) 
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define fo(i,x,y) for(int i=(x);i<=(y);++i)
#define fd(i,x,y) for(int i=(x);i>=(y);--i)
#define fi first
#define se second
#define mp make_pair
#define pb push_back
using namespace std;
typedef pair<int,int> PI;
const int N=40400,M=233,P=N/M+100;
int n,q,m;
int c[N],lm[N];
int le[P],ri[P];
vector<PI> pre[P],suf[P],a[P]; 
bool cmp(PI a,PI b)
{
	return(a.fi>b.fi||(a.fi==b.fi&&a.se>b.se));
}
int read()
{
    char ch=' ';int q=0,w=1;
    for(;(ch!='-')&&((ch<'0')||(ch>'9'));ch=getchar());
    if(ch=='-')w=-1,ch=getchar();
    for(;ch>='0' && ch<='9';ch=getchar())q=q*10+ch-48;int n=q*w;return n;
}
int cnt;
void init(vector<PI> &a)
{
	sort(a.begin(),a.end(),cmp);
	int sz=a.size()-1,de=1;
	cnt+=sz;
	fo(i,1,sz)
	{
		a[i-de+1]=a[i];
		if(a[i].se<=a[i-de].se) ++de;
	}
	fo(i,1,de-1) a.pop_back();
}
int be[N];
int find(int v,vector<PI> &a)
{
	int le=0,ri=a.size()-1,rt=-1;
	while(le<=ri)
	{
		int mid=(le+ri)>>1;
		rt=max(rt,min(a[mid].fi,a[mid].se+v));
		if(a[mid].fi>=a[mid].se+v) le=mid+1;
		else ri=mid-1;
	}
	return rt;
}
int vg[P],vs[P];
int main()
{
//	freopen("D:/LiuYuanHao/a2.in","r",stdin);
//	freopen("D:/LiuYuanHao/a.out","w",stdout);
	 freopen("park.in","r",stdin);
	 freopen("park.out","w",stdout);
	n=read(),q=read();
	fo(i,1,n) 
	{
		c[i]=read()+c[i-1];
		if(!le[(i/M)+1])le[(i/M)+1]=i;
		ri[(i/M)+1]=i;
		be[i]=(i/M)+1;
	}
	m=n/M+1;
	fo(i,1,n) lm[i]=read();
	fo(i,1,m)
	{
		fo(j,le[i],ri[i])
		{
			int g=lm[j],s=0;
			fo(k,j,ri[i])
			{
				s=c[k]-c[j-1];
				g=min(g+(c[k]-c[k-1]),lm[k]);
				a[i].pb(mp(g,s));
				if(j==le[i]) pre[i].pb(mp(g,s));
				if(k==ri[i]) suf[i].pb(mp(g,s));
				if(j==le[i]&&k==ri[i]) vg[i]=g,vs[i]=s;
			}
		}
		init(a[i]);
		init(pre[i]);
		init(suf[i]);
	}
 	while(q--)
	{
		int l=read(),r=read(),x=read();
		if(be[l]>=be[r]-1)
		{
			int nw=x,ans=x;
			fo(i,l,r)
			{
				nw=max(x,min(nw+c[i]-c[i-1],lm[i]));
				ans=max(ans,nw);
			}	
			printf("%d\n",ans);
		}
		else
		{
			int en=x,ans=x;
			fo(i,l,ri[be[l]]) 
			{
				en=max(x,min(en+c[i]-c[i-1],lm[i]));
				ans=max(ans,en);	
			}
			fo(i,be[l]+1,be[r]-1)
			{
				ans=max(ans,find(x,a[i]));
				ans=max(ans,find(en,pre[i]));
				en=max(max(min(en+vs[i],vg[i]),x),find(x,suf[i]));
			}
			fo(i,le[be[r]],r)
			{
				en=max(x,min(en+c[i]-c[i-1],lm[i]));
				ans=max(ans,en);
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
