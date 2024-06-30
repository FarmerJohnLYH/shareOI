#pragma GCC optimize(3)
#include <map>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define fo(i,x,y) for(int i=(x);i<=(y);++i)
using namespace std;
typedef long long ll;
typedef unsigned int iut;
const int P=31/*41729*/,N=4000400;
ll ans;
iut qm[N],h[N];
int s0,t0,n,m,d;
char s[N],t[N];
map <iut,int> ht,bz;
iut encd(int l,int r)
{
	return h[r]-h[l-1]*qm[r-l+1];
}
iut sh(char *x)
{
	iut rt=0;
	fo(i,1,m) rt=rt*P+x[i];
	return rt;
}
int main()
{
	
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%d%d%d%d",&s0,&t0,&n,&m);d=(n+m)>>1;
	qm[0]=1;fo(i,1,n*s0+m*t0) qm[i]=qm[i-1]*P;
	fo(i,1,s0)scanf("%s",s+(i-1)*n+1);
	fo(i,1,t0)scanf("%s",t+(i-1)*m+1);
	fo(i,1,s0*n) s[i]-='a'-1;
	fo(i,1,t0*m) t[i]-='a'-1; 
	if(n<m) swap(s,t),swap(s0,t0),swap(n,m);
	fo(i,1,t0) ++ht[sh(t+(i-1)*m)];
	fo(i,1,s0)
	{
		bz.clear();
		fo(j,1,n) h[j]=h[j-1]*P+s[(i-1)*n+j];
		fo(j,1,d)
		{
			iut h=encd(j,d)*qm[j-1]+encd(1,j-1);
			if(!bz[h])
			{
				bz[h]=1;
				ans+=ht[h-encd(d+1,n)*qm[m]];
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}
