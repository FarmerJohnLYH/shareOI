#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define fo(i,x,y) for (int pq = (y),i = (x);i <= pq;++ i)
#define fd(i,x,y) for (int pq = (y),i = (x);i >= pq;-- i)
#define oo 2139062143
using namespace std;
typedef double db;
typedef long long ll;
int lowbit(int x) {return((x)&(-x));}
int min(int x,int y){return (x>y)?(y):(x);}
int max(int x,int y){return (x>y)?(x):(y);}
const int N=7070;
int n;
int a[N],b[N];
struct node{
	int m,c;
}f[2][N*2];
void updt(node &x,node y,int m,int c)
{
	y.m+=m,y.c+=c;
	if(y.c<x.c||(y.c==x.c&&y.m<x.m)) x=y;	
} 
int main()
{
	// freopen("D:/LiuYuanHao/a1.in","r",stdin);
	scanf("%d",&n);
	memset(f[1],127,sizeof f[1]);
	int mx=0;
	fo(i,1,n) scanf("%d",&a[i]),mx=max(mx,a[i]);
	mx=min(mx,n);
	fo(i,1,n) scanf("%d",&b[i]);
	int o=0;
	fo(i,1,n)
	{
		o=1^o;
		memset(f[o],127,sizeof f[o]);
		updt(f[o][a[i]],f[o^1][a[i]-1],a[i]+b[i],0);
		fo(j,i,n+mx+1)
		{
			updt(f[o][j],f[o][j-1],0,0);
			updt(f[o][j],f[o^1][j-1],j,1);
		}
	}
	node ans;
	ans.m=ans.c=oo;
	fo(i,n,n+mx+1)
		updt(ans,f[o][i],0,0);
	ans.c=n-ans.c;
	printf("%d %d\n",ans.c,ans.m);
	return 0;
}
