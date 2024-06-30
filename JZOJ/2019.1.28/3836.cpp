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
const int N=110;
char t[N],s[N];
int n,ans=0,l;
int cmp(int x,int y)
{
	int p=min(l,n);
	fo(i,1,p)
	if(s[x+i-1]!=t[y+i-1])
		return(i-1);
	return(p);
}
int check()
{
	int rt=0;
	for (int i=1;i<=n;++rt)
	{
		int cp=0;
		fo(j,1,l)
			cp=max(cp,cmp(i,j));
		i+=cp;
	}
	return rt;
}
void dfs(int x)
{
	if(x>n)
	{
		ans=max(ans,check());
		return;
	}
	fo(i,0,3) 
	{
		s[x]=i+'A';
		dfs(x+1);
	}
	s[x]=0;
}
int main()
{
	freopen("D:/LiuYuanHao/c2.in","r",stdin);
	scanf("%d\n%s",&n,t+1);l=strlen(t+1);
	dfs(1);	
	printf("%d\n",ans);
	return 0;
}











