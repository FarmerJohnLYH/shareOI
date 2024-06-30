#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define fd(i,x,y) for (int i=(x);i>=(y);--i)
#define fi first
#define se second
using namespace std;
typedef pair<int,int> PI;
typedef unsigned long long ll;
const int N=100100;
const ll p=29;
int n,m,s[N],t[N];
char st[N];
ll h[N],ha[27][N],w[N];
int pt[27];PI d[27];int d0;
int pd(int sl,int sr,int len)
{
	ll sv=0,tv=0;
	fo(i,1,26) 
		if(pt[i])tv=tv+ha[pt[i]][len]*(ll)i;
	sv=h[sr]-h[sl]*w[sr-sl];
	return(sv==tv);
}
int solve(int st)
{
	memset(pt,0,sizeof pt);
	fo(i,1,d0)
	{
		if(d[i].fi+st>n) break;
		if(pt[d[i].se]!=s[d[i].fi+st]&&pt[d[i].se]!=0) break;
		if(pt[s[d[i].fi+st]]!=d[i].se&&pt[s[d[i].fi+st]]!=0) break;
		pt[d[i].se]=s[d[i].fi+st];
		pt[s[d[i].fi+st]]=d[i].se;
	}
	int le=1,rt=0,ri=min(m,n-st),mid;
	while(le<=ri)
	{
		mid=(le+ri)>>1;
		if(pd(st,st+mid,mid)) rt=mid,le=mid+1;
		else ri=mid-1;
	}
	return rt;
}
int main()
{
	 freopen("key.in","r",stdin);
	 freopen("key.out","w",stdout);
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
//	freopen("D:/LiuYuanHao/a.out","w",stdout);
	scanf("%d%d",&n,&m);
	w[0]=1;
	fo(i,1,max(n,m)) w[i]=w[i-1]*p;
	scanf("%s",st+1);
	fo(i,1,n) 
		h[i]=h[i-1]*p+(s[i]=st[i]-'a'+1);
	scanf("%s",st+1);
	fo(i,1,m)
	{
		t[i]=st[i]-'a'+1;
		if(!pt[t[i]])
		{
			pt[t[i]]=i;
			d[++d0]=make_pair(i,t[i]);
		}
		fo(j,1,26) ha[j][i]=ha[j][i-1]*p;
		++ha[t[i]][i];
	}
	fo(i,1,n)
		printf("%d\n",solve(i-1));	
	return 0;
}








