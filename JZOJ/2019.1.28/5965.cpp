#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
const int N=11,A=521,mo=1e9+7;
int n,m;
int f[N][N][A],all;
int find(int a,int b,int c)
{
	int rt=m;
	fo(k,0,m-2)
	{
		int x=((1<<k)&b)?1:0,y=((1<<(k+1))&a)?1:0;
		if(y<x) return -1;
		if(x==y) rt=min(rt,k+1);
		if(k>c && x!=y) return -1;
	}
	return min(rt,c+1);
}
void add(int &a,int b)
{
	a=(a+b)%mo;
}
int ans;
int wri[N][N];
int main()
{
	freopen("D:/LiuYuanHao/a.in","r",stdin);
	freopen("D:/LiuYuanHao/a.out","w",stdout);
	for(m=1;m<=9;++m)
	for(n=m;n<=9;++n)
	{
		memset(f,0,sizeof f);
		if(n<m)swap(n,m);
		all=(1<<m)-1;
		fo(s,0,all)
			f[1][m][s]=1;
		fo(i,2,n)
			fo(jj,1,m)
			fo(s,0,all) fo(sp,0,all)
			if(f[i-1][jj][sp])
			{
				int j=find(sp,s,jj-1);
				if(j==-1) continue;
				add(f[i][j][s],f[i-1][jj][sp]);
			}
		ans=0;
		fo(j,1,m) fo(s,0,all)
			add(ans,f[n][j][s]);
//		printf("%d\n",ans);
		wri[n][m]=ans;
	}
	fo(i,1,9) 
	{
		putchar('\n');
		fo(j,1,9)
		{
			if(i<j) wri[i][j]=wri[j][i];
			printf("ans[%d][%d]=%d;",i,j,wri[i][j]);
		}
	}
	return 0;
}








