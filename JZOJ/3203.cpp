#include <bitset>
#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
const int N=510;
int n,m,T;
bitset<N> a[N];
int main()
{
	// freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		fo(i,1,n) a[i]=0;
		fo(i,1,m)
		{
			int x,y;
			scanf("%d%d",&x,&y);++x,++y;
			a[x][y]=1;
		}
		int ans=0;
		fo(i,1,n) fo(j,1,n)
		{
			if(ans) break;
			int flag=0;
			fo(k,1,n) if(a[i][k]&&a[j][k]) 
			{
				flag=1;
				break;
			}
			if(flag)
				fo(k,1,n) if((a[i][k]+a[j][k])==1)
				{
					printf("No\n");
					ans=1;
					break;
				}
		}
		if(!ans) printf("Yes\n");
	}
	return 0;
}















