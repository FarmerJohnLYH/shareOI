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
#define bit(x) (1<<(x-1))
using namespace std;
typedef double db;
typedef long long ll;
typedef pair<int,int> PI;
int abs(int x) {return(((x)>=0)?(x):(-(x)));}
int max(int x,int y) {return(((x)>(y))?(x):(y));}
int min(int x,int y) {return(((x)<(y))?(x):(y));}
int lowbit(int x) {return((x)&(-x));}
using namespace std;
const int N=22,S=1<<14;
int t[N],d[N],tim[N],md[N], sum[N], dj[N], s[N], w[N];
int f[S+10][N];
int n,m;
int main()
{
	while(1)
	{
		scanf("%d",&n);
		if(!n)break;
		fo(i,1,n)
		{
			scanf("%d%d", &t[i], &d[i]);
			tim[i]=t[i]/d[i] + 1;
		}
		scanf("%d",&m);
		fo(i,1,m)
		{
			int cnt, x;
			scanf("%d%d",&cnt,&sum[i]);
			s[i]=0,dj[i]=0,md[i]=m;
			fo(j,1,cnt)
			{
				scanf("%d", &x);
				s[i]|=bit(x),sum[i]+=t[x],dj[i]+=d[x],md[i]=min(md[i],tim[x]);
			}
		}	
		int all=(1<<n)-1,ans=0;
		memset(f,0,sizeof(f));
		fo(i,1,m)
			f[s[i]][1]=max(f[s[i]][1],sum[i]),ans=max(ans,sum[i]);
		fo(ss,1,all-1) fo(i,1,m) if(f[ss][i])
		fo(j,1,m) if((ss&s[j])==0&&md[j]>=i+1)
		{
			f[ss|s[j]][i + 1] = max(f[ss | s[j]][i + 1], f[ss][i] + sum[j] - dj[j] * i);
			ans=max(ans, f[ss | s[j]][i + 1]);
		}
		printf("%d\n", ans);
	}
	return 0;
}


