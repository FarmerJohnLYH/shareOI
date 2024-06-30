#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
const int N=220*2,mo=1e9+7;
int m,a,b,c;
int o;
int f[3][11][N][N];
int h(int x,int y)
{
	return(x*3+y);
}
int main()
{
	freopen("D:/LiuYuanHao/b.in","r",stdin);
	scanf("%d%d%d%d",&m,&a,&b,&c);
	if(b>c)swap(b,c);if(a>b)swap(a,b);if(a>c)swap(a,c);
	o=0;
	fo(s,0,8)
	{
		int x=s%3,y=s/3;
		if(x!=y)
			f[o][s][a-(x==0||y==0)][b-(x==1||y==1)]=1;
	}
	fo(i,2,m)
	{
		o=1^o;
		memset(f[o],0,sizeof f[o]);
		fo(s,0,8)//las
		if(s%3!=s/3)
		{
			fo(x,0,2) fo(y,0,2) //now
			if((s%3)!=x && (s/3)!=y && x!=y)
			fo(aa,0,a) fo(bb,0,b)//now
			{
				int cc=2*(m-i)-aa-bb;
				int aaa=aa+(x==0||y==0),bbb=bb+(x==1||y==1),ccc=cc+(x==2||y==2);              
				if(cc>=0&&aaa<=a&&bbb<=b&&ccc<=c) 
				{
					if(f[o^1][s][aaa][bbb])
						(f[o][h(x,y)][aa][bb]+=f[o^1][s][aaa][bbb])%=mo;
				}
			}
		}
	}
	int ans=0;
	fo(s,0,8) 
	if(f[o][s][0][0])
		ans=(ans+f[o][s][0][0])%mo;
	printf("%d\n",ans);
	return 0;
}











