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
const int N=77,mo=10086;
typedef int mt[77][77];
int A[N],h[N],n,m,t;
mt f,st,p,F;
int x,y;
void Dp()
{
	F[0][1] = 1;
	fo(i,1,70)fo(j,1,n)fo(k,1,n)
		if (f[k][j]&&i>=h[j]) F[i][j]=(0ll+F[i][j]+F[i-1][k]*f[k][j])%mo;
}
void mul(mt &a,mt &b, mt &c)
{
	memset(p,0,sizeof p);
	fo(k,1,n) fo(i,1,n) fo(j,1,n)
		p[i][j]=(p[i][j]+a[i][k]*b[k][j])%mo;
	memcpy(c,p,sizeof c);
}
int main()
{
	freopen("D:/LiuYuanHao/b.in","r",stdin);
	scanf("%d%d%d",&n,&m,&t);
	fo(i,1,n)f[i][i]=1,scanf("%d",&h[i]); 
	fo(i,1,m)scanf("%d%d",&x,&y),++f[x][y];
	Dp();
	if(t<=70)printf("%d\n",F[t][n]);else
	{
		t-=70;
		fo(i,1,n) 
		{
			F[1][i]=F[70][i];
			fo(j,2,76) F[j][i]=0;
		}
		fo(i,1,n)st[i][i]=1;
		for(;t;t>>=1)
		{
			if(t&1)mul(st,f,st);
			mul(f,f,f);
		}
		mul(F,st,F);
		printf("%d\n",F[1][n]);
	}
	return 0;
}
