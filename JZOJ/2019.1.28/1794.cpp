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
const int N=1010,mo=10007;
int n,C[N][N];
int e[N][N],sz[N],f[N];
int read()
{
	int rt=0,p=1;char c=getchar();
	while(c!='-'&&!(c>='0'&&c<='9')) c=getchar();
	if(c=='-')c=getchar(),p=-1;
	while(c>='0'&&c<='9') rt=rt*10+c-'0',c=getchar();
	return rt;
}
void dfs(int x)
{
	fo(i,1,e[x][0])
	{
		int to=e[x][i];
		dfs(to);
		f[x]=(f[x]*f[to]%mo)*C[sz[to]+sz[x]-1][sz[to]-1]%mo;
		sz[x]+=sz[to];
	}
	++sz[x];
}
int main()
{
	freopen("D:/LiuYuanHao/c.in","r",stdin);
	C[0][0]=1;
	fo(i,1,N-10) 
	{
		fo(j,1,i) C[i][j]=(C[i-1][j-1]+C[i-1][j])%mo;
		C[i][0]=1;
	}
	for (int tt=read();tt--;)
	{
		n=read();
		fo(i,1,n)
		{
			e[i][0]=read();
			fo(j,1,e[i][0]) e[i][e[i][0]-j+1]=read();
			sz[i]=0;f[i]=1;
		}
		dfs(1);
		printf("%d\n",f[1]);
	}
	return 0;
}











