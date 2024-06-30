#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define fd(i,x,y) for (int i=(x);i>=(y);--i)
using namespace std;
const int N=2388790/*100100*33*/,mo=1e9+7,D=30;
int a[N],n;
long long ans,cnt;
int tot,sn[N][2],dp[N];
vector<int> d[N];
void add(int x)
{
	int w=1;
	fd(i,D,0)
	{
		int ch=((x&(1<<i))?1:0);	
		if(!sn[w][ch]) dp[sn[w][ch]=++tot]=dp[w]+1;
		w=sn[w][ch];
		d[w].push_back(x);
	}
}
void calc(int x,int y)
{
	if(d[x].size()>d[y].size()) swap(x,y);
	int fx=d[x].size();
	int mn=oo,ct=0;
	int cho=oo;
	fo(i,0,fx-1)
	{
		int p=d[x][i],q=y;
		fd(j,D-dp[x],0)
		{
			int ch=(p&(1<<j))?(1):(0);
			if(sn[q][ch]) q=sn[q][ch];
			else q=sn[q][1^(ch)];
		}
		if(((p^d[q][0]))<mn)cho=min(p,d[q][0]),mn=(p^d[q][0]),ct=d[q].size();
		else if(((p^d[q][0]))==mn) ct=(ct+d[q].size())%mo;
	}
	ans=(0ll+ans+(mn));
	cnt=1ll*cnt*ct%mo;
}
#define ll long long
ll qsm(ll x,ll y)
{
	ll rt=1;
	fo(i,0,D) 
	{
		if(y&(1<<i)) rt=rt*x%mo;
		x=x*x%mo; 
	}
	return rt;
}
void solve(int x)
{
	fo(x,1,tot)
		if(sn[x][0]&&sn[x][1])
			calc(sn[x][0],sn[x][1]);
}
int main()
{
//	freopen("jst.in","r",stdin);
//	freopen("jst.out","w",stdout);
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
	tot=1;
	scanf("%d",&n);
	fo(i,1,n) scanf("%d",&a[i]),add(a[i]);
	cnt=1;
	solve(1);
	fo(i,1,tot) if(dp[i]==D+1&&d[i].size()>2) 
		cnt=1ll*cnt*qsm(d[i].size(),d[i].size()-2)%mo;
	printf("%lld\n%lld\n",ans,cnt);
	return 0;
}








