#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define fo(i,x,y) for (int pq = (y),i = (x);i <= pq;++ i)
#define fd(i,x,y) for (int pq = (y),i = (x);i >= pq;-- i)
#define oo 2139062143
using namespace std;
typedef double db;
typedef long long ll;
int lowbit(int x) {return((x)&(-x));}
int min(int x,int y){return (x>y)?(y):(x);}
int max(int x,int y){return (x>y)?(x):(y);}
const int V=55,MX=5050*5050,P=5000000;
int n,m,cl;
int a,b,c,d,k;
int to[MX],nex[MX],las[P];
int tot;
int f[P];
void link(int x,int y)
{
	to[++tot]=y,nex[tot]=las[x];
	las[x]=tot;
}
int get(int id,int n,int k)
{
	memset(f,0,sizeof f);
	if(n==1&&k>0) return(0);
	int p=1%n+1;
	fo(i,1,n)
	if(f[i]<k)
	{
		int gg=k-f[i];
		int flag=0;
		for (int c=p-1;f[i]<k&&!flag;p=p%n+1)
		{
			if(p==c)flag=1;
			if(p==i||f[p]==k) continue;
			link(i+id,p+id);
			++f[i],++f[p];
		}
		if(f[i]<k) return 0;
	}
	return 1;
}
int gcd(int x,int y){return(y==0)?(x):(gcd(y,x%y));}
int main()
{
//	freopen("D:/LiuYuanHao/b2.in","r",stdin);
//	freopen("D:/LiuYuanHao/b.out","w",stdout);
	scanf("%d%d%d%d",&a,&b,&c,&d);
	int ppp=gcd(b,c);
	n=c,m=b;
	int tmp=0;
	for (;;)
	{
		tmp+=b;
		while(tmp%c) tmp+=b;
		n=tmp/b,m=tmp/c;
		if(((n>a)&&(n>=c)&&(m>d)&&(m>=b)&&((n*a)%2==0)&&((m*d)%2==0))) break;
	}
	for (k=1;;k++)
	{
		tot=0;
		memset(las,0,sizeof las);
		if(get(0,n,a)&&get(n,m,d))
		{
			printf("%d %d\n",n,m);
			fo(i,1,n+m)
			{
				for (int tmp=las[i];tmp;tmp=nex[tmp])
				{
					printf("%d %d\n",i,to[tmp]);
				}
			}
			int y=1;
			fo(i,1,n) 
			{
				int k=0;
				while(k<b)
				{
					++k;
					printf("%d %d\n",i,y+n);
					y=(y%m)+1;
				}
			}
			return 0;
		}
	}
	return 0;
}





















