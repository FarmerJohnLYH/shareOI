#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define fi first
#define se second
using namespace std;
typedef pair<int,int> PI;
const int N=100100,mo=998244353;
typedef long long ll;
int n,m;
int a[N];
ll ans;
PI c[N];
int sz;priority_queue<int> qu;
ll tw[N];
int main()
{
	  freopen("ore.in","r",stdin);
	  freopen("ore.out","w",stdout);
//	freopen("D:/LiuYuanHao/b.in","r",stdin);
	scanf("%d%d",&n,&m);
	tw[0]=1;
	fo(i,1,n) tw[i]=tw[i-1]*2ll%mo;
	fo(i,1,n) scanf("%d%d",&c[i].fi,&c[i].se);
	fo(i,1,m) scanf("%d",&a[i]);
	sort(a+1,a+1+m);sort(c+1,c+1+n);
	int j=1;sz=0;
	int las=0;
	fo(i,1,m) 
	{
		while(!qu.empty()&&(-qu.top()<a[i])) 
			--sz,qu.pop();
		int sm=sz;
		while(j<=n&&c[j].fi<=a[i]) ++sz,qu.push(-c[j].se),++j;
		while(!qu.empty()&&(-qu.top()<a[i])) 
			--sz,qu.pop();
		ans=(ans+(tw[sm]*(tw[sz-sm]-1)%mo))%mo;
		if(ans<0)
			printf("");
	}
	printf("%lld\n",ans);
	return 0;
}








