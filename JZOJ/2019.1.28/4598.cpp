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
const int N=100100;
struct qy{
	int r,k,pos;
}p[N];
int n,q;
int a[N],ans[N];
bool gt(int x,int y)//x binary NO.y
{
	return(x&(1<<(y-1)));
}
bool cmpr(qy x,qy y)
{
	return(x.r<y.r);
}
int sz[N*30],chd[N*30][2],col[N*30];
int tot=1;
void insert(int now,int v,int p)
{
	++sz[now];
	if(!p) return;
	int tmp=gt(v,p);
	if(!chd[now][tmp]) chd[now][tmp]=++tot,col[tot]=tmp;
	insert(chd[now][tmp],v,p-1);
}
int query(int now,int v,int p,int xr)
{
	if(!sz[now]) 
		return 0;
	if(p==1) 
		return ((col[now]^gt(xr,p))>=gt(v,p))?sz[now]:0;
	if((col[now]^gt(xr,p))>gt(v,p)) 
 		return(sz[now]);
	if((col[now]^gt(xr,p))==gt(v,p)) 
		return(query(chd[now][0],v,p-1,xr)+query(chd[now][1],v,p-1,xr)); 
	if((col[now]^gt(xr,p))<gt(v,p))
		return 0;
}
int main()
{
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
	freopen("food.in","r",stdin);
	freopen("food.out","w",stdout);
	scanf("%d",&n);
	fo(i,1,n) scanf("%d", &a[i]),a[i]^=a[i-1];
	scanf("%d",&q);
	fo(i,1,q) 
	{
		scanf("%d%d",&p[i].r,&p[i].k);
		p[i].pos=i;
	}
	sort(p+1,p+1+q,cmpr);
	p[0].r=1;
	insert(1,0,30);
	fo(i,1,q)
	{
		fo(j,p[i-1].r,p[i].r-1) 
			insert(1,a[j],30);
		ans[p[i].pos]=query(chd[1][0],p[i].k,30,a[p[i].r])+query(chd[1][1],p[i].k,30,a[p[i].r]);	
		printf("");
	}
	fo(i,1,q) printf("%d\n",ans[i]);
	return 0;
}
