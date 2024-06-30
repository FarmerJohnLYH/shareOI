#include <map>
#include <cmath>
#include <ctime>
#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x),asdfgh=(y);i<=asdfgh;++i)
#define fd(i,x,y) for (int i=(x),asdfgh=(y);i>=asdfgh;--i)
#define fi first
#define se second
using namespace std;
typedef double db;
typedef long long ll;
typedef pair<int,int> PI;
int abs(int x) {return(((x)>=0)?(x):(-(x)));}
int max(int x,int y) {return(((x)>(y))?(x):(y));}
int min(int x,int y) {return(((x)<(y))?(x):(y));}
int lowbit(int x) {return((x)&(-x));}
const int N=100100;
map <ll,int> mp;
int n,m;
char s[N],t[N];
ll v()
{
	int rt1=0;
	fo(i,1,n) rt1=(1ll*rt1*17+(t[i]-'a'+3)*5)%998224353;
	int rt2=0;
	fo(i,1,n) rt2=(1ll*rt2*7+(t[i]-'a'+2)*13)%1000000007;
	ll rt=100000000ll*rt1+rt2;
	return rt;
}
int main()
{
	freopen("lcs.in","r",stdin);
	freopen("lcs.out","w",stdout);
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%d%d\n",&n,&m);
	scanf("%s",s+1);
	fo(i,1,n) t[i]=s[i];
	mp[v()]=1;
	int ans=0;
	fo(i,1,n) fo(j,1,m) fo(l,1,n)
	{
		int wc=0;
		ll o;
		fo(k,1,n)
		{
			if(k+wc==i) ++wc;
			if(k==l) 
			{
				--wc,
				t[k]=(j+'a'-1);
			}
			else t[k]=s[k+wc];
		}
		int tp=mp[o=v()];
		if(!tp) 
		{
			mp[o]=1,++ans;
		}
	}
	printf("%d\n",ans);
	return 0;
}











