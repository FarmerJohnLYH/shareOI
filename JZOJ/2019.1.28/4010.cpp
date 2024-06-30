#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
const int N=110,M=1e9;
int le,ri,p;
int ans;
int c[10001000],c0;
int check(int x)
{
	return(le<=x&&x<=ri);
}
void dfs(int st,int a,int b)
{
	c[++c0]=a;
	if(st>p||a>ri)return;
	dfs(st+1,a,b+1);
	dfs(st+1,a*b,b);
}
int main()
{
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%d%d%d",&le,&ri,&p);
	dfs(1,1,0);
	sort(c+1,c+1+c0);
	c[0]=-1;
	fo(i,1,c0)
	if(c[i]!=c[i-1]&&check(c[i]))
		++ans;
	printf("%d\n",ans);
	return 0;
}











