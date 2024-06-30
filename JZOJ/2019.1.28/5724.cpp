#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#define one 1.0000000000000
#define oo 2139062143
#define ldb db
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
//typedef __float128 ldb;
typedef double db;
typedef long long ll;
const ll M=1000000000000000000;
int T,n,m;
struct mt{
	ldb c[9][9];
}f,a,g;
ldb p[9];
db mp;
void chg(int c,mt &a,mt &b)
{
	fo(i,1,n) fo(j,1,n) g.c[i][j]=0.000000000;
//	g.c[1][1]=0.00000;
printf("");
	fo(i,1,c) fo(j,1,n) fo(k,1,n)
		g.c[i][j]+=a.c[i][k]*b.c[k][j];
	fo(i,1,c) fo(j,1,n) a.c[i][j]=g.c[i][j];
}
void qsm(mt &a,mt &b,ll v)
{
	while(v)
	{
		if(v&1) chg(1,a,b);
		chg(n,b,b);
		v/=2;
	}
}
int main()
{
	// freopen("socialman.in","r",stdin);
	// freopen("socialman.out","w",stdout);
	freopen("D:/LiuYuanHao/b.in","r",stdin);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%lf",&n,&m,&mp);mp=1-mp;
		p[0]=one,p[1]=mp;
		fo(i,2,8) p[i]=p[i-1]*mp;
		fo(i,1,n) fo(j,i,n)
		f.c[i][j]=f.c[j][i]=p[j-i+1];
		a.c[1][1]=one;
		fo(i,2,n) a.c[1][i]=a.c[1][i-1]*p[1];
		qsm(a,f,m);
		mp=a.c[1][n];
		printf("%.7lf\n",mp);
	}
	return 0;
}











