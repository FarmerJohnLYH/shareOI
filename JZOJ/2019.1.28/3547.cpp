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
const int N=200200;
int n,m;
int a[N];
struct qry{
	int l,r;
	int pos;
}q[N];
int t[N*8];
bool cmp(qry x,qry y)
{
	return(x.r<y.r);
}
void insert(int x,int l,int r,int pos,int v)
{
	if(l==r)
	{
		t[x]=v;
		return;
	}
	int mid=(l+r)>>1;
	if(pos>mid) insert((x<<1)|1,mid+1,r,pos,v);
	else insert((x<<1),l,mid,pos,v);
	t[x]=min(t[(x<<1)],t[(x<<1)|1]);
}
int ans[N];
int solve(int x,int l,int r,int le)
{
	if(l==r) return(l);
	int mid=(l+r)>>1;
	if(t[x<<1]<le) return(solve(x<<1,l,mid,le));
	else return(solve((x<<1)|1,mid+1,r,le));
}
int main()
{
	freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%d%d",&n,&m);
	fo(i,1,n) scanf("%d",&a[i]),a[i]=min(a[i],n+1);
	fo(i,1,m)
		q[i].pos=i,scanf("%d%d",&q[i].l,&q[i].r);
	sort(q+1,q+1+m,cmp);
	int rem=1;
	fo(i,1,n)
	{
		insert(1,0,n+1,a[i],i);
		fo(j,rem,m)
		{
			if(q[j].r>i)
			{
				rem=j;
				break;
			}
			ans[q[j].pos]=solve(1,0,n+1,q[j].l);
		}
	}
	fo(i,1,n)
	{
		printf("%d\n",ans[i]);
	}
	return 0;
}
