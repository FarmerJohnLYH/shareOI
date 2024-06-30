#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
const int N=10010;
int len,n,ans;
char s[N];
int nex[N],las[27];
int d[N],d0;
int bz[27];
int main()
{
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%s",s+1);len=strlen(s+1);
	fo(i,1,len) 
	{
		s[len+i]=s[i];
		nex[i]=las[s[i]-'a'];
		las[s[i]-'a']=i;
	}n=len*2;
	fo(i,0,25)
	{
		d0=0;
		for(int j=las[i];j;j=nex[j]) d[++d0]=j;
		int mx=0,cnt;
		fo(a,0,len-1) 
		{
			cnt=0;
			memset(bz,0,sizeof bz);
			int flag=1;
			fo(j,1,d0) ++bz[s[d[j]+a]-'a'];
			fo(i,0,25)if(bz[i]==1) ++cnt;
			mx=max(mx,cnt);
		}
		ans+=mx;
	}
	printf("%.9lf",(double)ans/len);
	return 0;
}











