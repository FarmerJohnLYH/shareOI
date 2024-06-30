#include <cmath>
#include <ctime>
#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x),asdfgh=(y);i<=asdfgh;++i)
#define fd(i,x,y) for (int i=(x),asdfgh=(y);i>=asdfgh;--i)
#define fi first
#define se second
using namespace std;
typedef double db;
typedef long long ll;
typedef pair<int,int> PI;
int abs(int x) {return(((x)>=0)?(x):(-(x)));}
int max(int x,int y) {return(((x)>(y))?(x):(y));}
int min(int x,int y) {return(((x)<(y))?(x):(y));}
int lowbit(int x) {return((x)&(-x));}
const int N=11,L=100100*5;
int T;
char st[L];
int f[L],len;
int main()
{
	freopen("D:/LiuYuanHao/a1.in","r",stdin);
	scanf("%d",&T);
	while(T--)
	{
		memset(st,0,sizeof st);
		len=0;
		char ch=getchar();
		while(!(ch>='a'&&ch<='z')) ch=getchar();
		while(ch>='a'&&ch<='z')
		{
			st[++len]='$',st[++len]=ch;
			ch=getchar();
		}
		int n=strlen(st+1)/2;
		fo(i,1,len) st[i+len]=st[i];
		len=len<<1|1;
		st[len]='$';
		memset(f,0,sizeof f);
		f[1]=0;
		int mid=1,j=1,flag=0;
		fo(i,2,len)
		{
			if(mid+f[mid]>=i) 
			{
				f[i]=f[mid-(i-mid)];
				j=i+f[i];
				while(st[j+1]==st[i-(j+1-i)]) ++j,++f[i];
				if(j>mid+f[mid]) mid=i;
			}
			else
			{
				f[i]=0;
				j=i+f[i];
				while(st[j+1]==st[i-(j+1-i)]) ++j,++f[i];
				if(j>mid+f[mid]) mid=i;				
			}
			if((f[i]/2)>=(n/2)) 
			{
				flag=1;
				break;
			}
		}
		if(flag)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}











