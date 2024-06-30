#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
const int N=100100*8;
int n,q,a[N];
int t[20][N];
int lg[N];
int query(int x,int y)
{
	int p=lg[(y-x+1)];
	return(min(t[p][x],t[p][y-(1<<p)+1]));
}
int abs(int x)
{
	return(x<0)?(-x):x;
}
int main()
{
	freopen("cusor.in","r",stdin);
	freopen("cusor.out","w",stdout);
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
//	freopen("D:/LiuYuanHao/a.out","w",stdout);
	scanf("%d",&n);
	lg[0]=lg[1]=0;
	fo(i,2,N-100)
		lg[i]=lg[i/2]+1;
	fo(i,1,n) 
	{
		scanf("%d",&a[i]);
		t[0][i]=a[i];
	}
	fo(i,1,18) fo(x,1,n) t[i][x]=min(t[i-1][x],t[i-1][x+(1<<(i-1))]);
	scanf("%d",&q);
	while(q--)
	{
		int xa,xb,ya,yb;
		scanf("%d%d%d%d",&xa,&ya,&xb,&yb);
		if(xa>xb) swap(xa,xb),swap(ya,yb);
		int v=query(xa,xb);
		int ans=0;
		if(ya<=v&&yb<=v)
		{
			ans=abs(ya-yb)+xb-xa;
		}
		else
		{
			ans=abs(ya-v)+abs(yb-v)+xb-xa;
		}
		printf("%d\n",ans);
	}
	return 0;
}











