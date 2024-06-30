#pragma GCC optimize(2)
#include <cmath> 
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define fo(i,x,y) for (ll i=(x);i<=(y);++i)
#define fd(i,x,y) for (ll i=(x);i>=(y);--i)
using namespace std;
typedef double db;
typedef long long ll;
const ll N=2222,SZ=(1048576+10)*2;
const db pi=acos(-1);
struct com{
	db x,y;
	com(db _x=0,db _y=0)
	{
		x=_x,y=_y;
	}
};
com operator+(com a,com b){return com(a.x+b.x, a.y+b.y);}
com operator-(com a,com b){return com(a.x-b.x, a.y-b.y);}
com operator*(com a,com b){return com(a.x*b.x-a.y*b.y, a.x*b.y+b.x*a.y);}
ll n,m,w,h,M;
com v[2][SZ],W[SZ];
ll wz[SZ];
com a[N*N/2],b[N*N/2];
ll A[N/2][N/2],B[N/2][N/2];
void init(ll x)
{
	for (M=1;M<x;M<<=1);
	fo(i,1,M-1) wz[i]=(wz[i>>1]>>1)+((i&1)*(M>>1));
	W[0]=1,W[1]=com(cos(pi*2.0/M),sin(pi*2.0/M));
	fo(i,2,M) W[i]=W[i-1]*W[1];
}
com c[N*N];
void dft(com *a)
{
	fo(i,0,M-1) c[wz[i]]=a[i]; com tp;
	for(ll vw=2,hf=1;vw<=M;hf=vw,vw<<=1)
	fo(i,0,hf-1) for (ll j=i;j<M;j+=vw)
	tp=W[i*M/vw]*c[j+hf],c[j+hf]=c[j]-tp,c[j]=c[j]+tp;
	fo(i,0,M-1) a[i]=c[i];
}
ll X,Y;
ll sq[N/2][N/2],su[N/2][N/2];
struct ast{
	ll x,y,v;
}qu[N*N/2];
ll read()
{
    char ch=' ';ll q=0,w=1;
    for(;(ch!='-')&&((ch<'0')||(ch>'9'));ch=getchar());
    if(ch=='-')w=-1,ch=getchar();
    for(;ch>='0' && ch<='9';ch=getchar())q=q*10ll+ch-48;int n=q*w;return n;
}
bool cmp(ast a,ast b)
{
	if(a.v!=b.v)return(a.v<b.v);
	return(a.x<b.x||(a.x==b.x&&a.y<b.y));
}
ll g[N*N],tot;
int main()
{
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
//	freopen("D:/LiuYuanHao/a.out","w",stdout);
	n=read(),m=read();
	fo(i,0,n-1) fo(j,0,m-1) A[i][j]=read(),a[i*m+j].x=A[i][j];
	h=read(),w=read();
	ll sqv=0,suv=0;
	fo(i,0,h-1) fo(j,0,w-1) B[i][j]=read(),b[(h-i-1)*m+w-j-1].x=B[i][j],sqv+=B[i][j]*B[i][j],suv+=B[i][j];
	X=read(),Y=read();
	--X,--Y;
	fd(i,n-1,0) fd(j,m-1,0) sq[i][j]=sq[i+1][j]+sq[i][j+1]-sq[i+1][j+1]+A[i][j]*A[i][j],su[i][j]=su[i+1][j]+su[i][j+1]-su[i+1][j+1]+A[i][j];
	init(n*m*4);

	dft(a),dft(b);
	fo(i,0,M-1) a[i]=a[i]*b[i];
	fo(i,1,M>>1) swap(a[i],a[M-i]);
	dft(a);
	fo(i,0,M-1) g[i]=ll(round(a[i].x/M));
	fo(i,0,n-h) fo(j,0,m-w)
	{
		ll p=i+h-1,q=j+w-1,x=i+X,y=j+Y;
		ll rt=sq[i][j]-sq[i][q+1]-sq[p+1][j]+sq[p+1][q+1]
		+(A[x][y]*A[x][y]*h*w+sqv)
		-(2*(su[i][j]-su[i][q+1]-su[p+1][j]+su[p+1][q+1])*A[x][y])
		+(2*(suv*A[x][y]-g[p*m+q]));
		qu[++tot].v=rt,qu[tot].x=i,qu[tot].y=j;
	}
	sort(qu+1,qu+1+tot,cmp);
	ll k;
	scanf("%lld",&k);
	fo(i,1,k) printf("%lld %lld %lld\n",qu[i].x+1,qu[i].y+1,qu[i].v);
	return 0;
}











