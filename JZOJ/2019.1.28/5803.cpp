#include <bitset>
#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
typedef unsigned long long ull;
const int N=2020;
ull A,B,C,ans;
int n,m;
int s[N][N];
int main()
{
	// freopen("girls.in","r",stdin);
	// freopen("girls.out","w",stdout);
	freopen("D:/LiuYuanHao/a1.in","r",stdin);
	scanf("%d%d%llu%llu%llu",&n,&m,&A,&B,&C);
	if(m==0)
	{
		ans=0;
		fo(i,1,n)
		{
			ans=(ans+A*((n-i)*(n-i-1)/2));
			ans=(ans+B*(i-1)*(n-i));
			ans=(ans+C*((i-1)*(i-2)/2));
		}
		printf("%llu\n",ans);
		return 0;
	}
	fo(i,1,m)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		++x,++y;
		if(x>y) swap(x,y);
		s[x][y]=1;
	}
	fo(i,1,n) fo(j,i+1,n) if(!s[i][j])
	fo(l,j+1,n) if(!s[i][l]&&!s[j][l])
		ans=(ans+A*(i-1)+B*(j-1)+C*(l-1));
	printf("%llu\n",ans);
	return 0;
}











