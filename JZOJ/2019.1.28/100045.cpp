#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;

int d[10000000];
int gcd(int x,int y)
{
	return(y==0)?(x):(gcd(y,x%y));
}
int check(int x)
{
	int d0=0;
	fo(i,1,x-1) if(gcd(i,x)==1)
		d[++d0]=i;
	fo(i,1,d0-1) if(d[i+1]-d[i]!=d[2]-d[1])
		return 0;
	return 1;
}
int main()
{
	freopen("D:/LiuYuanHao/a.out","w",stdout);
	fo(i,2,n)
	{
		if(check(i)) 
			// if(i%2!=0)
				printf("%d\n",i);
	}
	return 0;
}








