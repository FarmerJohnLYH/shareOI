#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
const int N=50500,M=1010,MK=66;
int n,m,k,g;
struct node{
	int x,y,tpx,tpy;
}a[N];
struct qry{
	int l,r,op;
}q[N];
int L[M],R[M],tl[M][K],tr[M][K];
bool cmp(node a,node b)
{
	return(a.tpx!=b.tpx)?(a.y<b.y):(a.tpx<b.tpx);
}
int main()
{
	freopen("D:/LiuYuanHao/a.in","r",stdin);
	n=read(),m=read(),k=n/M+1;
	fo(i,1,n) 
	{
		a[i].x=i,a[i].y=read();
		a[i].tpx=i/M+1;
		if(!a[i].tpx[L])a[i].tpx[L]=i;
		a[i].tpx[R]=i;
	}
	sort(a+1,a+1+n,cmp);

	return 0;
}











