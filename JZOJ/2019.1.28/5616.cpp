#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define p1 727
#define p2 311
#define mo 1109
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
typedef long double db;
const int N=2525;
const db eps=1e-16;
int n;
int s[N],p[N][N];
db q[N][N],a[2][N];
int A,B,C;
int pre;
db randi()
{
	db rt=pre=(pre*p1+p2)%mo;
	return((rt+1)/(db)mo);
}
int check(int o)
{
	fo(i,1,n) 
		if(!((-eps<=a[o][i]-a[o^1][i])&&(a[o][i]-a[o^1][i]<=eps)))
		return(0);
	return 1;
}
void mul(int o)
{
	fo(i,1,n) a[o][i]=0;
	fo(i,1,n) fo(j,1,n)
		a[o][j]+=a[o^1][i]*q[i][j];
}
int main()
{
	freopen("dust.in","r",stdin);
//	freopen("D:/LiuYuanHao/c.in","r",stdin);
	freopen("dust.out","w",stdout);
	scanf("%d%d%d%d",&n,&A,&B,&C);
	pre=0727;
	fo(i,1,n)
	{
		s[i]=1;
		s[i]+=(p[i][1]=(1ll*p[i-1][n]*A+B)%C);
		fo(j,2,n)
		{
			p[i][j]=(1ll*p[i][j-1]*A+B)%C;
			s[i]+=p[i][j]+1;
		}
	}
	fo(i,1,n) fo(j,1,n)
		q[i][j]=((db)p[i][j]+1)/(db)s[i];
	a[0][1]=1;
	int o=0;
	while(!check(o))
		mul(o=1^o);
	fo(i,1,n) printf("%.18Lf ",a[o][i]);
	return 0;
}








