#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define fd(i,x,y) for (int i=(x);i>=(y);--i)
using namespace std;
typedef long long ll;
const int N=550,K=110,Q=50050;
int n,k,w,q;
int a[K];
ll v[K];
int b[K][N];
ll f[N];
int main()
{
	freopen("qinggong.in","r",stdin);
	freopen("qinggong.out","w",stdout);
//	freopen("D:/LiuYuanHao/a1.in","r",stdin);
	scanf("%d%d%d",&n,&k,&w);
	fo(i,1,k)
		scanf("%d%d",&a[i],&v[i]);
	scanf("%d",&q);
	fo(i,1,q)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		b[y][x]=-1;
	}
	fo(i,1,k)
	{
		int tmp=0;
		fd(j,n,0)
		{
			if(b[i][j]==-1) tmp=0;
			else 
			{
				b[i][j]=tmp/a[i];
				++tmp;
			}
		}
	}
	memset(f,127,sizeof f);
	f[0]=0;
	fo(i,0,n-1)
		fo(j,1,k)
			fo(l,1,b[j][i]) 
				f[i+l*a[j]]=min(f[i+l*a[j]],f[i]+v[j]*l+w);
	if(f[N-1]==f[n]) printf("-1\n");
	else printf("%lld\n",f[n]-w);
	return 0;
}








