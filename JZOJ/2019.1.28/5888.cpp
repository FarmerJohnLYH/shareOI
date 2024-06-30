#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
const int N=100100;
int n,a[N],c[N];
int main()
{
	freopen("D:/LiuYuanHao/","r",stdin);
	scanf("%d",&n);
	fo(i,1,n) 
	{
		scanf("%d",&a[i]);
		++c[a[i]];
	}
	
	return 0;
}








