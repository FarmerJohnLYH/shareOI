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
const int N = 100100,M = 100100,T = 11,TOT = 1001000;
const int P1 = 40319,P2 = 10007,P3 = 998244353;
struct node{
	int len;
	int l,r;
}a[N];
char st[TOT];
int cd[TOT];
int st0;
int n,m;
void readstr(int i)
{
	scanf("%s",st+st0);
	a[i].len=strlen(st+st0);
	a[i].l=st0;
	st0=st0+a[i].len;
	a[i].r=st0-1;
	fd(l,a[i].r,a[i].l)
		cd[l] = (1ll * cd[l+1] * P1 + (st[l] * P2)) % P3;
}
int main()
{
	freopen("biology.in","r",stdin);
	freopen("biology.out","w",stdout);
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
	// freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%d%d", &n, &m);
	st0=1;
	fo(i,1,n)
	{
		readstr(i);
	}
	fo(i,1,m)
	{
		int type;
		scanf("%d", &type);
		if(type==1)
		{
			readstr(++ n);
		}
		if (type==2)
		{
			int t,p[T],mn=oo;
			scanf("%d",&t);
			fo(i,1,t)scanf("%d",&p[i]),mn=min(mn,a[p[i]].len);
			int l = 1,r = mn,ans=0;
			while(l<=r)
			{
				int mid=(l+r)>>1;
				bool flag = 0;
				int tmp = cd[a[p[1]].r - mid + 1];
				fo(i,2,t)
				{
					if(cd[a[p[i]].r - mid + 1]!=tmp)
					{	
						flag = 1;
						break;
					}	
				}
				if(!flag) ans=mid,l=mid+1;
				else r=mid-1;
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
