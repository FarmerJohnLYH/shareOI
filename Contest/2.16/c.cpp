#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
const int N=200200;
int n,k;
int du[N],ans;
int p[N],a[N][2];
int main()
{
	//freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%d%d",&n,&k);
	fo(i,1,n-1)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		a[i][0]=x,a[i][1]=y;
		++du[x],++du[y];
		p[x]=y,p[y]=x;
	}
	int f1=0;
	fo(i,1,n-1)
		if(a[i][0][du]>=3&&a[i][1][du]>=3) 
			f1=1;
	if(f1 && k==1) ans-=2;
	int flag=0;
	fo(i,1,n) 
		if(du[i]==1) 
		{
			++ans;
			if(p[i][du]>=3) flag=1;
		}
	// if(!f1 && flag && k==1)--ans;
	printf("%d\n",ans);
	return 0;
}








