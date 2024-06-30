/*
ø¥¥ÌÃ‚¡ÀQAQ 
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define mx (M-111)
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
typedef long long ll;
const int N=1001000,M=10001000;
int n,tot;
int p[N],bz[M];
ll a[N];int b[N],cnt,c[N];
int main()
{
//	freopen("bread.in","r",stdin);
//	freopen("bread.out","w",stdout);
	bz[1]=1;
	fo(i,2,mx)
	{
		if(!bz[i])p[++tot]=i;
		fo(j,1,tot)
		{
			if(p[j]*i>mx)break;
			bz[p[j]*i]=1;
			if(i%p[j]==0)break;
		}
	}
	cnt=0;
	scanf("%d",&n);
	fo(i,1,n) 
	{
		scanf("%lld",&a[i]);
		a[0]=max(a[0],a[i]);	
		c[i]=1;
	}
	sort(a+1,a+1+n);
	int q=0;
	fo(i,1,n-1) 
	{
		if(a[i-q]==a[i+1]) 
		{
			c[i-q]+=c[i+1],c[i+1]=0;
			a[i+1]=-1;
			++q;
		}
		else a[i-q+1]=a[i+1],swap(c[i-q+1],c[i+1]);
	}
	n=n-q;
	fo(i,1,tot)
	{
		int m=0;ll v=p[i];
		while(m<n)
		{
			v=v*p[i];
			if(!(v<=a[0])) break;
			int nw=lower_bound(a+1+m,a+1+n,v)-a;
			if(a[nw]==v)
				if(!b[nw])b[nw]=1,cnt+=c[nw];	
		}
	}
	printf("%d\n",cnt);
	return 0;
}


*/
 
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<map>
using namespace std;

typedef long long LL;

map<LL , bool> Map;

const int pri[13] = {3,5,7,11,13,17,19,23,29,31,37,41,43};
const int Lim[13] = {1e5,1000,100,18,11,6,5,4,3,2,2,2,2};
const LL maxN = 1e14;
const int N = 1e5 + 7;

int n,ans;
LL F[N],Cur[N];

void Pre()
{
	for (int i = 1 ; i <= 100000 ; i ++) F[i] = i , Cur[i] = 1;
	for (int i = 0 ; i <= 13 ; i ++)
		for (int j = 2 ; j <= Lim[i] ; j ++)
		{
			for (int k = 1 ; k <= pri[i] - Cur[j] ; k ++) F[j] = F[j] * j;
			if (F[j] > maxN) break;
			Cur[j] = pri[i];
			Map[F[j]] = 1;
		}
}

bool Check(LL x)
{
	if (x == 1) return 0;
	LL tmp = sqrt(x);
	if (tmp * tmp == x) return 1;
	return Map[x];
}

int main()
{
	freopen("bread.in" , "r" , stdin);freopen("bread.out" , "w" , stdout);
	
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
	Pre();
	scanf("%d\n" , &n);
	ans = 0;
	for (int i = 1 ; i <= n ; i ++)
	{
		LL x;scanf("%lld" , &x);
		if (Check(x)) ans ++;
	}
	
	printf("%d\n" , ans);
	return 0;
}






