#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define fo(i,x,y) for(int i=(x);i<=(y);++i)
#define fd(i,x,y) for(int i=(x);i>=(y);--i)
using namespace std;
typedef long long ll;
const int N=22,mo=998244353;
int n,m;
struct node{
	int x,y,c;
}a[N*N];
ll f[1<<N],g[1<<N];
int to[N][N],v[N][N],t0[N];
void dfs(int cs,int k,int v)
{
	dfs(cs+1,);
}
int all;
int main()
{
	freopen("fair.in","r",stdin);
	freopen("fair.out","w",stdout);
	scanf("%d%d",&n,&m);
	all=(1<<n)-1;
	fo(i,1,m)
	{
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].c);
		if(a[i].x>a[i].y) swap(a[i].x,a[i].y);
		to[a[i].x][++t0[a[i].x]]=a[i].y;v[a[i].x][t0[a[i].x]]=a[i].c;
	}
	fo(i,1,all)
	{
		if(low(i)==i) f[i]=1,g[i]=;
	}
	return 0;
}




