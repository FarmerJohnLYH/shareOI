/*
 #pragma GCC optimize(2)
#include <map>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define fo(i,x,y) for (ll i=(x);i<=(y);++i)
#define fd(i,x,y) for (ll i=(x);i>=(y);--i)
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> PI;
typedef vector<ll> VE;
ll read()
{
    char ch=' ';ll q=0,w=1;
    for(;(ch!='-')&&((ch<'0')||(ch>'9'));ch=getchar());
    if(ch=='-')w=-1,ch=getchar();
    for(;ch>='0' && ch<='9';ch=getchar())q=q*10+ch-48;ll n=q*w;return n;
}
ll buf[30],b0;
void write(ll x)
{
	b0=0;
	if(x==0)putchar('0');
	else
	while(x) buf[++b0]=x%10,x/=10;
	fd(i,b0,1) putchar(buf[i]+'0');
}
const ll N=200200*28;
char s[N];
ll sa[N],tax[N],rk[N],se[N],rk2[N];
ll v[N],n;
ll m;
void gtsa()
{
	fo(i,1,m) tax[i]=0;
	fo(i,1,n) ++tax[rk[i]];
	fo(i,1,m) tax[i]+=tax[i-1];
	fd(i,n,1) sa[tax[rk[se[i]]]--]=se[i];
}
ll he[22][N],ct[N];
void SA()
{
	m=27;
	fo(i,1,n) rk[i]=s[i]-'a'+1,se[i]=i;
	gtsa();
	for(ll w=1;w<=n;w*=2)
	{
		ll ct=0;
		fd(i,n,n-w+1) se[++ct]=i; 
		fo(i,1,n) if(sa[i]-w>0) se[++ct]=sa[i]-w;
		gtsa();
		memcpy(rk2,rk,sizeof rk);
		rk[sa[1]]=1;ct=1;rk2[n+1]=-1;
		fo(i,2,n) 
			rk[sa[i]]=(rk2[sa[i]]==rk2[sa[i-1]]&&rk2[sa[i]+w]==rk2[sa[i-1]+w])?ct:(++ct);
		m=ct;
	}
	he[0][1]=0;
	fo(l,1,n)
	{
		ll i=rk[l];if(i==1)continue;
		ll ppp=0;
		he[0][i]=max(ppp,he[0][rk[l-1]]-1);
		while(s[l+he[0][i]]==s[sa[i-1]+he[0][i]]) ++he[0][i];
	}
	he[0][1]=oo;
	fo(l,1,20) fo(i,1,n)
	if(i+(1ll<<l)-1>n) break; 
	else he[l][i]=min(he[l-1][i],he[l-1][i+(1<<l)-1]);
	fo(i,1,n) ct[sa[i]]=ct[sa[i-1]]-((he[0][i]>=oo)?(0):(he[0][i]))+n-sa[i]+1;
}
ll gthe(ll l,ll r)
{
	++l;
	if(l>r)return oo;
	ll lg=log(r-l+1)/log(2);
	while((1ll<<(lg+1))<(r-l+1)) ++lg;
	return(min(he[lg][l],he[lg][r-(1ll<<lg)+1]));
}
ll getrank(ll l,ll r)
{
	ll p=rk[l],len=r-l+1;
	ll le=p,ri=n,tp=0;
	while(le<=ri)
	{
		ll mid=(le+ri)>>1,q=gthe(p,mid);
		if(q>=len) le=mid+1,tp=mid;
		else ri=mid-1; 
	}
	p=sa[tp];r=r-l+p,l=p;
	ll rt=(ct[sa[n]]-ct[p]+(n-l+1)-(r-l+1))+1;
	return rt;
}
PI ans[N];ll a0;
int main()
{
//	freopen("platform.in","r",stdin);
//	freopen("platform.out","w",stdout);
	freopen("D:/LiuYuanHao/a.in","r",stdin);
	freopen("D:/LiuYuanHao/a.out","w",stdout);
	scanf("%s",s+1);
	n=strlen(s+1);
	fo(i,1,n) v[i]=read(),v[i]+=v[i-1];
	SA();
	fo(i,1,n)
	{
		ll le=i,ri=n,rt=0;
		while(le<=ri)
		{
			ll mid=(le+ri)>>1,tp=getrank(i,mid);
			if(tp<v[mid]-v[i-1]) ri=mid-1;
			else if(tp>v[mid]-v[i-1]) le=mid+1;
			else 
			{
				rt=mid;	
				break;
			}
		}
 		if(rt)ans[++a0]=make_pair(i,rt);
	}
	write(a0),putchar('\n');
//	printf("%d\n",a0);
	fo(i,1,a0) write(ans[i].fi),putchar(' '),write(ans[i].se),putchar('\n');
//	printf("%d %d\n",ans[i].fi,ans[i].se);
	return 0;
}
*/




#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<bitset>
#include<ctime>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define get_val(l,r) sumv[r]-sumv[l-1]
const int MAXN=400010;
struct O{
    int l,r;
    bool operator < (O const& a) const
    {
        return l<a.l;
    }
}ot[MAXN];
int t[MAXN<<2];
inline void pushup(int x)
{
    t[x]=t[x<<1]*(t[x<<1]==t[x<<1|1]);
}
inline void pushdown(int x,int l,int r)
{
    if(!t[x])
        return;
    t[x<<1]=t[x<<1|1]=t[x];
}
inline void change(int x,int l,int r,int ql,int qr,int val)
{
    if(ql>r||qr<l)
        return;
    if(ql<=l&&r<=qr){
        t[x]=val+1;
        return;
    }
    pushdown(x,l,r);
    int mid=(l+r)>>1;
    if(ql<=mid)
        change(x<<1,l,mid,ql,qr,val);
    if(qr>=mid+1)
        change(x<<1|1,mid+1,r,ql,qr,val);
    pushup(x);
}
inline int query(int x,int l,int r,int pos)
{
    if(t[x])
        return t[x]-1;
    pushdown(x,l,r);
    int mid=(l+r)>>1;
    if(pos<=mid)
        return query(x<<1,l,mid,pos);
    else
        return query(x<<1|1,mid+1,r,pos);
}
char str[MAXN];
ll Rank[MAXN],sa[MAXN];
ll sum[MAXN],tp[MAXN];
ll height[MAXN],h[MAXN];
ll val[MAXN],sumv[MAXN];
ll tmprank[MAXN],tot;
int n;
ll ans=0;
void get_sa(int n)
{
    int m=127;
    for(int i=1;i<=n;i++) Rank[i]=str[i],tp[i]=i;
    for(int i=0;i<=m;i++) sum[i]=0;
    for(int i=1;i<=n;i++) sum[Rank[tp[i]]]++;
    for(int i=1;i<=m;i++) sum[i]+=sum[i-1];
    for(int i=n;i>=1;i--) sa[sum[Rank[tp[i]]]--]=tp[i];
    int p=1;
    for(int len=1;p<n;len<<=1,m=p)
    {
        p=0;
        for(int i=n-len+1;i<=n;i++) tp[++p]=i;
        for(int i=1;i<=n;i++) if(sa[i]>len) tp[++p]=sa[i]-len;
        for(int i=0;i<=m;i++) sum[i]=0;  //Rank为第一关键字，tp为第二关键字
        for(int i=1;i<=n;i++) sum[Rank[tp[i]]]++;
        for(int i=1;i<=m;i++) sum[i]+=sum[i-1];
        for(int i=n;i>=1;i--) sa[sum[Rank[tp[i]]]--]=tp[i];
        swap(Rank,tp);Rank[sa[1]]=1;p=1;
        for(int i=2;i<=n;i++)
            Rank[sa[i]]=(tp[sa[i]]==tp[sa[i-1]]&&tp[sa[i]+len]==tp[sa[i-1]+len])?p:++p;
    }
    int lst=0,j;
    for(int i=1;i<=n;h[i]=lst,height[Rank[i++]]=lst)
        for(lst=lst?lst-1:lst,j=sa[Rank[i]-1];str[j+lst]==str[i+lst];++lst);
}
ll get_rank(int lpos,int pos)
{
    if(pos-lpos+1>height[Rank[lpos]]) return sum[n]-(sum[Rank[lpos]-1]+pos-lpos-height[Rank[lpos]]);
    else
    {
        ll pre=query(1,1,n,pos-lpos+1);
        return tmprank[pre]+pre-(pos-lpos+1);
    }
}
int tttt;
int main()
{
	freopen("platform.in","r",stdin);
	freopen("platform.out","w",stdout);
    scanf("%s",str+1);
    n=strlen(str+1);
    for(int i=1;i<=n;i++)
        scanf("%lld",&val[i]),sumv[i]=sumv[i-1]+val[i];
    get_sa(n);
    for(int i=1;i<=n;i++)
        sum[i]=n-sa[i]-height[i]+1+sum[i-1];
    for(int i=1;i<=n;i++) //枚举Rank
    {
        int L=sa[i],R=n,lpos=sa[i];
        while(L<R)
        {
            int mid=(L+R)>>1;
            if(get_val(lpos,mid)<get_rank(lpos,mid))
                L=mid+1;
            else R=mid;
        }

        if(get_val(lpos,L)==get_rank(lpos,L))
            ot[++ans]={lpos,L};
        if(i!=n&&height[i]<height[i+1])
            tmprank[height[i]+1]=get_rank(sa[i],sa[i]+height[i]),
            change(1,1,n,height[i]+1,height[i+1],height[i]+1);
    }
    sort(ot+1,ot+1+ans);
    printf("%lld\n",ans);
    for(int i=1;i<=ans;i++)
        printf("%d %d\n",ot[i].l,ot[i].r);
}





