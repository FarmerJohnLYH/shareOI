#include <bitset>
#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
const int N=100100,Q=1001000,V=8080;
int n,q;
bitset<7007> a[N],qq[V];
int bz[V],p[V],p0,miu[V];
void init(int n)
{
	bz[1]=1;miu[1]=1;
	fo(i,2,n)
	{
		if(!bz[i]) p[++p0]=i,miu[i]=-1;
		fo(j,1,p0)
		{
			if(i*p[j]>n) break;
			bz[i*p[j]]=1;
			if(i%p[j]==0)
			{
				miu[i*p[j]]=0;
				break;
			}else miu[i*p[j]]=miu[i]*(-1);
		}
	}
}
int main()
{
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
	init(8000);
	fo(i,1,7000)
	{
		fo(j,i,7000)
		if(j%i==0) 
			qq[i][j]=(miu[j/i]!=0)?1:0;
	}
	scanf("%d%d",&n,&q);			

	fo(i,1,q)
	{
		int t,x,y,z;
		scanf("%d%d%d",&t,&x,&y);
		if(t==1)
		{
			a[x]=0;
			fo(i,1,y)
			{
				if(y%i==0) a[x][i]=a[x][y/i]=1;
				if(i*i>=y)break;
			}
		}
		if(t==2)
		{
			scanf("%d",&z);
			a[x]=a[y]^a[z];
		}
		if(t==3)
		{
			scanf("%d",&z);
			a[x]=a[y]&a[z];
		}
		if(t==4)
		{
			int cnt=(qq[y]&a[x]).count()&1;
			printf("%d",cnt);
		}
	}
	return 0;
}








