#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define fo(i,x,y) for (ll i=(x),asdfgh=(y);i<=asdfgh;++i)
#define fd(i,x,y) for (ll i=(x),asdfgh=(y);i>=asdfgh;--i)
#define fi first
#define se second
using namespace std;
typedef double db;
typedef long long ll;
typedef pair<ll,ll> PI;
ll abs(ll x) {return(((x)>=0)?(x):(-(x)));}
ll max(ll x,ll y) {return(((x)>(y))?(x):(y));}
ll min(ll x,ll y) {return(((x)<(y))?(x):(y));}
ll lowbit(ll x) {return((x)&(-x));}
const ll N=300300;
ll n,tot;
char st[N];
ll son[N][26],fail[N],cnt[N],len[N];
ll it,ans,tl;
ll getfail(ll p)
{
	while(st[tl]!=st[tl-p[len]-1]) 
		p=fail[p];
	return p; 
}
void ins(ll x)
{
	ll p=getfail(it),c=st[x]-'a';	
	if(!son[p][c])
	{
		++tot;
		fail[tot]=son[getfail(fail[p])][c];
		len[tot]=len[p]+2;
		son[p][c]=tot;	
	}
	it=son[p][c];
	++it[cnt];
}
void solve()
{
	fd(i,tot,1)
	{
		i[fail][cnt]+=i[cnt];
		ans=max(ans,i[cnt]*i[len]);
	}
	printf("%lld\n",ans);
}
int main()
{
	freopen("palindrome.in","r",stdin);
	freopen("palindrome.out","w",stdout);
//	freopen("D:/LiuYuanHao/d1.in","r",stdin);
	scanf("%s",st+1);n=strlen(st+1);
	tot=1;it=0;
	fail[1]=0,fail[0]=1;
	len[1]=-1,len[0]=0;
	fo(i,1,n) tl=i,ins(i);
	solve();
	return 0;
}











	
