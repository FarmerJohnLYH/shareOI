#include <map>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo ((1ll<<31))
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define fi first
#define se second
using namespace std;
typedef pair<int,int> PI;
const int N=20002000;
int f[50];
int n;
map<int,int> mp;
int main()
{
	freopen("D:/LiuYuanHao/a.in","r",stdin);
	f[1]=1,f[2]=2;
	n=45;mp[1]=1,mp[2]=1;
	fo(i,3,n) 
		f[i]=f[i-1]+f[i-2],mp[f[i]]=1;
	for(;;)
	{
		scanf("%d",&n);
		if(n==0)break;
		if(mp[n]!=1)
			printf("First win\n");
		else printf("Second win\n");
	}
	return 0;
}








