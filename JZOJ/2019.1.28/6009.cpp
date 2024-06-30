#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define min(x,y) ((x)<(y)?(x):(y))
using namespace std;
const int N=110,mo=998244353;
int an[N],f[2][N][N];//edge len_longlian edge_fei
int n;
#define add(x,y) (x=(x+(y))>=mo?((x+(y))-mo):(x+(y)))
int main()
{
	freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%d",&n);int all=n*(n-1);
	int o=1;
	f[0][0][0]=1;
	fo(k,1,all)
	{
		memset(f[o],0,sizeof f[o]);
				
		o^=1;
	}
	fo(i,1,all) printf("%d ",an[i]);
	return 0;
}








