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
const int N=4040,P=8080;
int n,p;
int to[N],nex[N],las[N];
struct node{
	int w,f,v;
}a[N];
int bz[N];
int sum;
int main()
{
//	freopen("medicine.in","r",stdin);
//	freopen("medicine.out","w",stdout);
	freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%d%d",&n,&p);
	fo(i,1,n)
		scanf("%d%d%d",&a[i].w,&a[i].f,&a[i].v),sum+=a[i].w;
	if(n<=10)
	{
		int ans=0,pp=0,sg=0;
		fo(i,1,(1<<(n+1))-1)
		if(i&1)
		{
			pp=0,sg=0;
			memset(bz,0,sizeof bz);
			bz[1]=1;
			fo(l,1,n)
			if(i&(1<<(l-1)))
				bz[l]=(bz[a[l].f]);
			fo(l,1,n)
			if(bz[l]) sg+=a[l].v,pp+=a[l].w;
			if(pp<=p) ans=max(ans,sg);
		}
		printf("%d\n",ans);
	}
	else
	printf("%d\n",sum);
	return 0;
}











