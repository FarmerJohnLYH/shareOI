#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define add(x,y) (x=(x+(y))%mo)
using namespace std;
const int M=110,MX=120120,N=22,mo=998244353;
int f[2][MX][2][M];
int bz[2][MX][2][M];
int m,n;
int d[2][MX*M][4];
char s[N];
int mx,c[11],w[11];
int a[11],pw[N];
int hsh()
{
	int rt=0;
	fo(i,0,9) 
	if(a[i])
		rt=rt+a[i]*((i==0)?1:w[i-1]);
	return rt;
}
void gt(int st)
{
	memset(a,0,sizeof a);
	fo(i,0,9)
		a[i]=(st%w[i])/((i>0)?w[i-1]:1);
}
int check()
{	
	fo(i,0,9)
		if(a[i]>c[i]) return 0;
	return 1;
}
int main()
{
//	freopen("number.in","r",stdin);
//	freopen("number.out","w",stdout);
	freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%s %d\n",s+1,&m);
	n=strlen(s+1);
	pw[1]=1;
	fo(i,1,n) ++c[s[i]-'0'];
	fo(i,2,n) pw[i]=10ll*pw[i-1]%m;
	int cnt=0;
	w[0]=c[0]+1;mx=c[0]+1;
	fo(i,1,9) 
	{
		mx=mx+(c[i]+1)*w[i-1];
		w[i]=w[i-1]*(c[i]+1);
	}
	mx=w[9];
	f[0][0][0][0]=1;
	int o=1;
	int d0[2];d0[o]=1;
	d[o][1][1]=0,d[o][1][2]=0,d[o][1][3]=0;
	fo(i,1,n)
	{
		memset(f[o],0,sizeof f[o]);
		d0[1^o]=0;
		fo(st,0,mx-1)
		{
			gt(st);
			fo(kk,1,d0[o])
			{
				int st=d[o][kk][1],p=d[o][kk][2],j=d[o][kk][3];
				fo(k,0,9)
				if(c[k])
				{
					++a[k];int jj=(j+(1ll*k*pw[i]%m))%m;
					if(check())
					{
							int q=hsh();
						if(k==0)
						{
							add(f[o][q][1][jj],f[o^1][st][p][j]);
							if(f[o][q][1][jj]&&!bz[o^1][q][1][jj]) 
								d[o^1][++d0[o^1]][1]=q,d[o^1][++d0[o^1]][2]=1,d[o^1][++d0[o^1]][3]=jj,bz[o^1][q][1][jj]=1;
						}
						else 
						{
							add(f[o][q][0][jj],f[o^1][st][p][j]);
							if(f[o][q][0][jj]&&!bz[o^1][q][0][jj]) 
								d[o^1][++d0[o^1]][1]=q,d[o^1][++d0[o^1]][2]=0,d[o^1][++d0[o^1]][3]=jj,bz[o^1][q][0][jj]=1;	
						}
					}
					--a[k];
				}
			}
		}
		fo(kk,1,d0[o]) bz[o][d[o][kk][1]][d[o][kk][2]][d[o][kk][3]]=0; 
		o=1^o;
	}
	fo(i,0,9) a[i]=c[i];
	printf("%d\n",f[o^1][hsh()][0][0]);
	return 0;
}











