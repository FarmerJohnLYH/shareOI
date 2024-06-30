#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define fo(i,x,y) for (int pq = (y),i = (x);i <= pq;++ i)
#define fd(i,x,y) for (int pq = (y),i = (x);i >= pq;-- i)
#define oo 2139062143
#define max(x,y) (((x)>(y))?(x):(y))
using namespace std;
typedef double db;
typedef long long ll;
int lowbit(int x) {return((x)&(-x));}
const int N=30030;
db f[N];
db c,s[3],t;
db p[N];
int n;
ll dc(db x,db y)
{
	ll p=x/y/100;
	p*=100ll;
	if(p*y>x) return(p-100);
	else return p;
}
db tax(db x) // x 级别的交易 税收
{
	db tmp=((db)x*t+(max((db)x*s[1],(db)s[2])));
	return(x*t+(max(x*s[1],s[2])));
}
int main()
{
	// freopen("D:/LiuYuanHao/d.in","r",stdin);
	// freopen("D:/LiuYuanHao/d.out","w",stdout);
	freopen("stock.in","r",stdin);
	freopen("stock.out","w",stdout);
	int _;
	scanf("%d",&_);
	while(_--)
	{
		scanf("%lf%lf%lf%lf",&c,&s[1],&s[2],&t);
		scanf("%d",&n);
		fo(i,1,n) scanf("%lf",&p[i]);
		db mony=c,stok=0,stm=c;
		fo(i,1,n)
		{
			db x=stok,y=stm;
			ll tmp=dc(mony,p[i]);
			db remm=mony-tmp*p[i]-tax(tmp*p[i]);
			while(remm<0) tmp-=100,remm=mony-tmp*p[i]-tax(tmp*p[i]);
			if(tmp>stok||(tmp==stok&&remm>stm))
			{
				stok=tmp,stm=remm;
			}
			y=y+x*p[i]-tax(x*p[i]);
			if(y>mony) mony=y;
		}
		printf("%.3lf\n",mony);
	}
	return 0;
}
