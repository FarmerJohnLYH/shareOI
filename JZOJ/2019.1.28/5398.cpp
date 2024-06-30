#include <ctime>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define fo(i,x,y) for (int pq = (y),i = (x);i <= pq;++ i)
#define fd(i,x,y) for (int pq = (y),i = (x);i >= pq;-- i)
#define oo 2139062143
using namespace std;
typedef double db;
typedef long long ll;
int lowbit(int x) {return((x)&(-x));}
int min(int x,int y){return (x>y)?(y):(x);}
int max(int x,int y){return (x>y)?(x):(y);}
const int M=10100,K=11,K2=2020,Mo=998244353;
int m,k;
int f[2][K2],s[K2];
int a[K],b[K];
int read()
{
    char ch=' ';int q=0,w=1;
    for(;(ch!='-')&&((ch<'0')||(ch>'9'));ch=getchar());
    if(ch=='-')w=-1,ch=getchar();
    for(;ch>='0' && ch<='9';ch=getchar())q=q*10+ch-48;
    int n=q*w;return n;
}
int main()
{
	// freopen("adore.in","r",stdin);
	// freopen("adore.out","w",stdout);
	freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%d%d",&m,&k);
	int start = clock();
	int sta=0,F=(1<<k)-1;
	fo(j,1,k) sta|=((read())<<(j-1));
	fo(i,0,F) s[i]=s[i>>1]^(i&1);
	int o=0;
	f[o][sta]=1;	
	fo(l,2,m-2)
	{
		memset(a,0,sizeof a);
		memset(b,0,sizeof b);
		o^=1;
		memset(f[o],0,sizeof f[o]);
		fo(i,1,k) fo(j,1,k)
		{
			int n=read();
			a[i]|=(n<<(j-1));
			b[j]|=(n<<(i-1));
		}
		fo(i,0,F)
		if(f[o^1][i])
		{
			int sx=0,sy=0;
			fo(j,1,k)
			{
				sx|=(s[i&a[j]]<<(j-1));
				sy|=(s[i&b[j]]<<(j-1));
			}
			f[o][sx]=(f[o^1][i]+f[o][sx])%Mo;
			f[o][sy]=(f[o^1][i]+f[o][sy])%Mo;
		}
		int cost = clock()-start;
	}
	sta=0;
	fo(i,1,k)
		sta|=((read())<<(i-1));
	int ans=0;
	fo(i,0,F) ans=(ans+(s[sta&i]?0:f[o][i]))%Mo;
	for(int i=0;i<0.998*CLOCKS_PER_SEC;i=clock()-start);
	 // printf("%d\n", i);
	printf("%d\n", clock()-start);
	return 0;
}
