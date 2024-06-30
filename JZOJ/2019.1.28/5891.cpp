#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
const int N=100100;
int a[N],b[N],n,m,a0;
int bz[N],q[N];
int main()
{
	freopen("patrol.in","r",stdin);
	freopen("patrol.out","w",stdout);
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%d%d",&n,&m);
	fo(i,1,m) scanf("%d",&b[i]),bz[b[i]]=1;
	fo(i,1,n) if(!bz[i]) a[++a0]=i;
	int h1=1,h2=1;
	fo(i,1,n)
	{
		if(h2>m||(a[h1]<b[h2]&&h1<=a0)) q[i]=a[h1],++h1;
		else q[i]=b[h2++];
	}
	fo(i,1,n) printf("%d\n",q[i]);
	return 0;
}








