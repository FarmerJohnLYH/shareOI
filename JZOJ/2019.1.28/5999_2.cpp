#pragma GCC optimize(2) 
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define fo(i,x,y) for(int i=(x);i<=(y);++i)
#define fd(i,x,y) for(int i=(x);i>=(y);--i)
#define max(x,y) ((x)>(y)?(x):(y)) 
using namespace std;
const int N=1010,M=65536+100,mo=998244353;
int n,k,s;
typedef long long ll;
int a[N],ans;
int gcd(int x,int y)
{
	return(y==0)?x:(gcd(y,x%y));
}
int t[M],q[M][N];
inline void add(int &x,ll y)
{
	x=(x+y)%mo;
}
void dfs(int x,int p,int g,int st)
{
	if(x<=1)
	{
		if(x==0)add(ans,g);
		else add(ans,1ll*gcd(g,st)*q[st][p+1]);
		return;
	}
	fo(i,p+1,n)
		dfs(x-1,i,gcd(a[i],g),st^a[i]);
}
int read()
{
	int rt=0;char ch=getchar(); 
	while(!(ch>='0'&&ch<='9'))	ch=getchar();
	while((ch>='0'&&ch<='9')) rt=rt*10+ch-'0',ch=getchar();
	return rt;
}
int main()
{
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
	freopen("choose.in","r",stdin);
	freopen("choose.out","w",stdout);
	n=read(),k=read(),s=read();
	int mx=0;
	fo(i,1,n) 
	{
		a[i]=read();
		++q[a[i]][i];	
		mx=max(mx,a[i]);
	}
	fo(i,0,mx)
		fd(j,n,1) q[i][j]+=q[i][j+1];
	fo(i,1,n) 
		dfs(k-1,i,a[i],s^a[i]);
	printf("%d\n",ans);
	return 0;
}







