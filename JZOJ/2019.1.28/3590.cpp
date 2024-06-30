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
const int N=100100;
int n,l,r,s;
char st[N];
int pd(int m,int l,int r)
{
	int len=r-l+1,pp=len/m;
	fo(i,0,pp-1)
	{
		fo(j,i+1,pp-1)
		{
			fo(li,1,m)
			{
				int x=i*m+li,y=j*m+li;
				if(st[x+l-1]==st[y+l-1])
					return(0);
			}
		}
	}
	return 1;
}
int gt(int id,int en)
{
	int len=en-id;
	fo(m,l,r)
	if(len%m==0&&len/m>=s)
	{
		if(pd(m,id+1,en)) 
			return(1);
	}
	return(0);
}
int v[N];
int main()
{
	freopen("D:/LiuYuanHao/d.in","r",stdin);
	scanf("%d%d%d%d",&n,&l,&r,&s);
	v[1]=1;
	fo(i,2,n)
	{
		v[i]=2;
		fo(j,2,min(sqrt(i)+1,i-1))
			if(i%j==0) ++v[i];
	}
	fo(i,1,n) v[i]=v[i-1]+v[i];
	scanf("%s",st+1);
	int mx=-1;
	fo(L,1,n) fd(R,n,L)
	{
		if(gt(L-1,R))
			mx=max(mx,v[R]-v[L-1]);
	}
	printf("%d\n",mx);
	return 0;
}









