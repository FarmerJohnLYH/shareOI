#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
typedef long long ll;
ll a,b,c;
int main()
{
	// freopen("a.in","r",stdin);
	// freopen("a.out","w",stdout);
	// freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%lld",&b);
	if(b==0)
		printf("A*B B*C");
	else
		if(b<0)
			printf("A*B");
	else 
		if(b>0)
			printf("B*C");
	return 0;
}








