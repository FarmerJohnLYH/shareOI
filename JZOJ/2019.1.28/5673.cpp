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
const int N=200200;
int n;
int x[N],y[N],a[N]/*有序序列中序号*/,f[N]/*原序列中指向凸包*/;
int jd(int a,int b,int c)
{
	int k1=(a[y]-c[y])/(a[x]-c[x]),k2=(b[y]-c[y])/(b[x]-c[x]);
	return(k2<k1);
}
void tb_find()
{
	int F[N],st[N];
	int tl=1;st[1]=1;
	memset(F,0,sizeof F);		
	F[1]=1;//le
	fo(i,2,n)
	{
		st[++tl]=i;
		while(tl>2 && jd(st[tl],st[tl-1],st[tl-2])) st[tl-1]=st[tl],--tl;
		F[i]=st[tl-1];
		if(tl==2)if(st[1][y]<st[2][y]) st[tl-1]=st[tl],--tl,F[i]=i;
	}
	memset(f,0,sizeof f);		
	memset(st,0,sizeof st);
	tl=n;st[n]=n;
	f[n]=n;//ri
	fd(i,n-1,1)
	{
		st[--tl]=i;
		while(tl+2<=n && jd(st[tl],st[tl+1],st[tl+2]) ) st[tl+1]=st[tl],++tl;
		f[i]=st[tl+1];
		if(tl+1==n)if(st[n][y]<st[n-1][y]) st[tl+1]=st[tl],++tl,f[i]=i;
	}
	fo(i,1,n) 
	if(F[i][y]>f[i][y]) f[i]=F[i];
}
bool cmp(int a,int b)
{
	return(a[f][y]<b[f][y])||(a[f][y]==b[f][y]&&a[f][x]<b[f][x]);
}
int main()
{
	freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%d",&n);
	fo(i,1,n) 
	{
		scanf("%d%d",&x[i],&y[i]);
		a[i]=i;
	}
	tb_find();
	sort(a+1,a+1+n,cmp);
	
	return 0;
}











