#pragma GCC optimize(2) 
#include <complex>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define fo(i,x,y) for (ll i=(x);i<=(y);++i)
using namespace std;
typedef double db;
typedef long long ll;
typedef complex<db> com;
const ll N=524288+10;
const db pi=acos(-1);//cos 180=-1
com v[2][N],w[N]/*单位根*/;
ll ans[N];
ll n,wz[N],m;
void init(ll x)
{
	for (m=1;m<x;m<<=1);
	fo(i,0,m-1) wz[i]=(wz[i>>1]>>1)+((i&1)*(m>>1));
	w[0]=1,w[1]=com(cos(pi*2.0/m),sin(pi*2.0/m));
	fo(i,2,m) w[i]=w[i-1]*w[1]; 
}
com a[N]; 
void dft(com *c)
{
	fo(i,0,m-1) a[wz[i]]=c[i];com tp; 
	for (ll wh=2,hf=1;wh<=m;hf=wh,wh<<=1)
	fo(i,0,hf-1) for (ll l=i;l<m;l+=wh)
		tp=a[l+hf]*w[m*i/wh],a[l+hf]=a[l]-tp,a[l]+=tp;
	fo(i,0,m-1) c[i]=a[i];
}
int main()
{
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%lld",&n);init(2*n/*只需要开答案需要的大小*/);
	fo(i,0,n-1) scanf("%lf",&v[0][i]);
	fo(i,0,2*n-2) v[1][i]=(i==n-1)?(0.0):((db)((i<n-1)?-1:1)/(i-n+1)/(i-n+1));
	dft(v[0]),dft(v[1]);
	fo(i,0,m-1) v[0][i]*=v[1][i];
	fo(i,1,m>>1) swap(v[0][i],v[0][m-i]);
	dft(v[0]);
	fo(i,n-1,2*n-2) printf("%lf\n",v[0][i].real()/(1.0*m));
	return 0;
}










