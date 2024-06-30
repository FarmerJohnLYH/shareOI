#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
typedef long long ll;
const int N=500500;
char s[N];
int n,f[N],nex[N],ri[N];
int main()
{
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%s",s+1);
	n=strlen(s+1);
	int j=0;
	fo(i,2,n)
	{
		while(s[i]!=s[j+1]&&j) j=nex[j];
		nex[i]=(s[i]==s[j+1])?(++j):(j=0);
	}
	f[ri[1]=1]=1;
	fo(i,2,n)
	{
		if(i-nex[i]<=ri[nex[i][f]])f[i]=f[nex[i]];
		else f[i]=i;
		ri[f[i]]=i;
	}
	printf("%d\n",f[n]);
	return 0;
}
