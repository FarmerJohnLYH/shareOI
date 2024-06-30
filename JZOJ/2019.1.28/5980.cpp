#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
const int N=1010;
int n,T;
char s[N];
int main()
{
	freopen("chaine.in","r",stdin);
	freopen("chaine.out","w",stdout);
	// freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",s+1);n=strlen(s+1);
		int flag=0;
		fo(i,1,n-1)
			if(s[i]==s[i+1]) ++flag;
		if(flag<=1) printf("Zhangzj\n");
		else printf("Owaski\n");
	}
	return 0;
}








