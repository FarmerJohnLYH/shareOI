#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
typedef long long ll;
const int N=22;
ll f[N],g[N];
int n,m;
ll dfs(int s1,int t1,int s2,int t2,int n,int k) 
{
	if(n==0)return 0;
	int m1=6-s1-t1,m2=6-s2-t2;
	if(k<=f[n-1]-1)
	{
			 if(s2==s1)return dfs(s1,m1,s2,t2,n-1,k);
		else if(m2==s1)return dfs(s1,m1,t2,s2,n-1,k)+g[n-1];
		else if(t2==s1)return dfs(s1,m1,s2,t2,n-1,k)+2*g[n-1];
	}
		else if(s2==t1)return dfs(m1,t1,s2,t2,n-1,k-f[n-1]);
		else if(m2==t1)return dfs(m1,t1,t2,s2,n-1,k-f[n-1])+g[n-1];
		else if(t2==t1)return dfs(m1,t1,s2,t2,n-1,k-f[n-1])+2*g[n-1];
	return 0;
}
int main()
{
//	freopen("D:/LiuYuanHao/a.in","r",stdin);	
	f[0]=g[0]=1;
	fo(i,1,20) f[i]=f[i-1]*2,g[i]=g[i-1]*3;
	scanf("%d%d", &n, &m);
	printf("%lld\n", dfs(1,3,1,3,n,m));
	return 0;
}
