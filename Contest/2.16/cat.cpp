#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define fd(i,x,y) for (int i=(x);i>=(y);--i)
using namespace std;
const int N=300300;
//19
int n,c[N],d[N],b[N];
int f[22][N],ans[N];
int run(int x)
{
	if(b[x]) return 0;
	int rt=1;
	fd(i,19,0) if(!b[f[i][x]]) rt+=(1<<i),x=f[i][x];
	b[x]=1;
	return rt;
}
int main()
{
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%d",&n);
	fo(i,1,n) scanf("%d",&f[0][i]);
	b[0]=1;
	fo(l,1,19) fo(i,1,n) f[l][i]=f[l-1][f[l-1][i]];
	fo(i,1,n) scanf("%d",&c[i]);
	fo(i,1,n) 
		printf("%d\n",ans[c[i]]=run(c[i]));
	return 0;
}








