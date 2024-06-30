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
const int N=100100,C=303;
int n,m,k,a0;
struct node{
	int x,y;
}a[N*C];
bool cmp(node a,node b)
{
	return(a.x<b.x||(a.x==b.x&&a.y<b.y));
}
int f[N*C];
int main()
{
	freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%d%d%d",&n,&m,&k);
	fo(i,1,k)
	{
		int x,y,v;
		scanf("%d%d%d",&x,&y,&v);
		fo(l,1,v) a[++a0].x=x+1,a[a0].y=y+1;
	}
	sort(a+1,a+1+a0,cmp);
	memset(f,127,sizeof f);
	f[0]=0;int tl=0;
	fo(i,1,a0)
	{
		int le=0,ri=tl,rt=0;
		while(le<=ri)
		{
			int mid=(le+ri)>>1;
			if(a[i].y>=a[mid].y)
			{
				rt=mid;
				le=mid+1;
			}
			else ri=mid-1;
		}
		f[rt+1]=min(f[rt+1],a[i].y);
		tl=max(tl,rt+1);
	}
	printf("%d\n",tl);
	return 0;
}











