#include <map>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
typedef long long ll;
const int N=1001000;
int n,m,k;
int a[N];
int q,las[N],c[N];
int ans;
map<ll,int> my;
bool cmp(int x,int y)
{
	return(las[x]<las[y]);
}
int all;
void solve(int x,ll y)
{
	if(x>all)
	{
		int tp=my[y];
		if(!tp) my[y]=1,++ans;
		return;
	}
	solve(x+1,y*10ll+a[x]);
	solve(x+1,y);
}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
//	freopen("D:/LiuYuanHao/b.in","r",stdin);
	scanf("%d%d%d",&n,&m,&k);
	fo(i,1,n) scanf("%d",&a[i]),a[i][las]=i;
	fo(i,n+1,n+m) 
	{
		fo(l,1,k)
		if(!las[l]) 
		{
			las[l]=i;
			a[i]=l;
			break;
		}
		if(!a[i]) 
		{
			all=i-1;
			break;
		}
	}
	fo(i,1,k) c[i]=i;
	sort(c+1,c+1+k,cmp);
	fo(i,all+1,n+m)
		a[i]=c[(i-all-1)%k+1];
	all=n+m;
	my[0]=1;
	solve(1,0);
	printf("%d\n",ans);
	return 0;
}











