#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define f2(i,x,y) for (int i=(x);i<=(y);i+=2)
using namespace std;
const int N=9,M=5005000,mo=1e9+7;
int n,k,m,p;
char s[M];int a[M];
int f[M][N];
int main()
{
	freopen("D:/LiuYuanHao/","r",stdin);
	scanf("%d%d",&n,&k);
	scanf("%s",s+1);p=strlen(s+1);
	fo(i,1,k) fo(j,1,p) a[++m]=s[j]-'0';
	f[0][0]=1;
	fo(i,0,m-1)
	if(a[i+1]==0)
	{
		fo(j,0,n)
		if(f[i][j])
		{
			f2(k,0,j)
				add(f[i+1][j],f[i][j]*C(j,k));
		}
	}
	else
	{
		fo(j,0,n) if(f[i][j])
		fo(k,0,n-j) 
		{
			int rt=0;
			f2(l,(n-j-k)&1,j)
				add(rt,C(j,l));
			add(f[i+1][j+k],rt*C(n-j,k)%mo*f[i][j]%mo)
		}
	}

	return 0;
}











