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
const int N=18;
int bt[N];
int n,m;
int f[20002000];
int a[N],c[N],b[N],ans;
int main()
{
	freopen("D:/LiuYuanHao/a.in","r",stdin); 
//	freopen("arg.in","r",stdin);
//	freopen("arg.out","w",stdout);
	bt[1]=1;fo(i,2,17)bt[i]=bt[i-1]*3;
	scanf("%d%d",&n,&m);
	fo(i,1,m)scanf("%d",&a[i]),a[i][c]=i;
	f[0]=1;
	fo(x,0,bt[n+1]-1)
	if(f[x])
	{
		int mx=0,j=1;
		b[0]=0;
		fo(i,1,n)
		{
			if(((x/bt[i])%3)==1)b[++b[0]]=i;
			if(((x/bt[i])%3))mx=max(mx,c[i]);
		}
		fo(i,1,n)
		if(!((x/bt[i])%3))
		{
			while(i>b[j]&&j<=b[0])++j;
			if(c[i]&&c[i]!=mx+1)continue;
			if(i<b[j]&&j<=b[0])f[x+b[j][bt]+i[bt]]+=f[x];
				else f[x+bt[i]]+=f[x];
		}
	}
	fo(i,1,bt[n+1]-1)
	{
		int flag=0,c1=0,c2=0;
		if(!flag)fo(j,1,m)
			if(!((i/a[j][bt])%3)){flag=1;break;}
		if(!flag)
		{
			fo(j,1,n)if(((i/bt[j])%3)==1)c1++;
				else if(((i/bt[j])%3)==2)c2++;
			if(c1==m&&c1+c2==n)ans+=f[i];
		}
	}
	printf("%d",ans);
	return 0;
}
