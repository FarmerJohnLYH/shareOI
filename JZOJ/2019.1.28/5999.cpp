#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define fo(i,x,y) for(int i=(x);i<=(y);++i)
using namespace std;
const int N=1001000,M=65536+100,mo=998244353;
int n,k,s;
int a[N],ans;
int gcd(int x,int y)
{
	return(y==0)?x:(gcd(y,x%y));
}
void dfs(int x,int p,int g,int st)
{
	if(x==0)
	{
		if(st==0) ans=(ans+g>=mo)?(ans+g-mo):(ans+g);
		return;
	}
	fo(i,p+1,n)
		dfs(x-1,i,gcd(a[i],g),st^a[i]);
}
int main()
{
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
	freopen("choose.in","r",stdin);
	freopen("choose.out","w",stdout);
	scanf("%d%d%d",&n,&k,&s);
	fo(i,1,n) scanf("%d",&a[i]);
	fo(i,1,n) 
		dfs(k-1,i,a[i],s^a[i]);
	printf("%d\n",ans);
	return 0;
}







