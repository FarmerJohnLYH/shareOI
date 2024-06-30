#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define fd(i,x,y) for (int i=(x);i>=(y);--i)
using namespace std;
typedef long long ll;
const int N=500500,K=22,mo=1e9+7;
int n,m;
struct node{
	int l,r;
};
vector<node> c[K];
ll f[K][N];
ll jc[N],ny[N];
ll C(ll n,ll m)
{
	return(jc[n]*ny[m]%mo*ny[n-m]%mo);
}
ll qsm(ll x,ll y)
{
	ll rt=1;
	fo(i,0,30)
	{
		if((1<<i)&y) rt=rt*x%mo;
		x=x*x%mo;
	}
	return rt;
}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
	jc[0]=1;fo(i,1,N-100) jc[i]=jc[i-1]*i%mo;
	ny[N-100]=qsm(jc[N-100],mo-2);
	fd(i,N-101,0) ny[i]=ny[i+1]*(i+1)%mo;
	scanf("%d%d",&n,&m);
	fo(i,1,m)
	{
		int l,r,x;
		scanf("%d%d%d",&l,&r,&x);
		node t;t.l=l,t.r=r;
		c[x].push_back(t);
	}
	fd(i,20,0)
	{
//		printf("");
		fo(j,i,20)
		{
			ll d=j-i,v;
			for(int p=c[j].size()-1,l=0;l<=p;++l)
			{
				node q=c[j][l];
				v=C(q.r-q.l+d,d);
				(f[i][q.r+1]+=mo-v)%=mo;
				if(i==j) ++f[i][q.l];
			}
		}
		fo(j,1,n)
			f[i][j]=(f[i][j]+f[i+1][j]+f[i][j-1])%mo;
	}
	fo(i,1,n)
		printf("%lld\n",f[0][i]);
	return 0;
}








