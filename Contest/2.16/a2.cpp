#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
int a,b,c;
int main()
{
	freopen("a.in","r",stdin);
	freopen("a.ans","w",stdout);
	scanf("%d",&b);
	int flag=0;
	fo(a,-m,b-1) fo(c,b+1,m)
		if(a*b>a*c && a*b>b*c && !flag)
		{
			flag=1;
			printf("A*B");
		}
	return 0;
}








