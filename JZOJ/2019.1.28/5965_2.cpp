#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
const int N=11,A=521,mo=1e9+7;
int n,m;
int ans[N][N];
int a[10001000];
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
	ans[1][1]=2;ans[1][2]=4;ans[1][3]=8;ans[1][4]=16;ans[1][5]=32;ans[1][6]=64;ans[1][7]=128;ans[1][8]=256;ans[1][9]=512;
	ans[2][1]=4;ans[2][2]=12;ans[2][3]=36;ans[2][4]=108;ans[2][5]=324;ans[2][6]=972;ans[2][7]=2916;ans[2][8]=8748;ans[2][9]=26244;
	ans[3][1]=8;ans[3][2]=36;ans[3][3]=112;ans[3][4]=336;ans[3][5]=1008;ans[3][6]=3024;ans[3][7]=9072;ans[3][8]=27216;ans[3][9]=81648;
	ans[4][1]=16;ans[4][2]=108;ans[4][3]=336;ans[4][4]=912;ans[4][5]=2688;ans[4][6]=8064;ans[4][7]=24192;ans[4][8]=72576;ans[4][9]=217728;
	ans[5][1]=32;ans[5][2]=324;ans[5][3]=1008;ans[5][4]=2688;ans[5][5]=7136;ans[5][6]=21312;ans[5][7]=63936;ans[5][8]=191808;ans[5][9]=575424;
	ans[6][1]=64;ans[6][2]=972;ans[6][3]=3024;ans[6][4]=8064;ans[6][5]=21312;ans[6][6]=56768;ans[6][7]=170112;ans[6][8]=510336;ans[6][9]=1531008;
	ans[7][1]=128;ans[7][2]=2916;ans[7][3]=9072;ans[7][4]=24192;ans[7][5]=63936;ans[7][6]=170112;ans[7][7]=453504;ans[7][8]=1360128;ans[7][9]=4080384;
	ans[8][1]=256;ans[8][2]=8748;ans[8][3]=27216;ans[8][4]=72576;ans[8][5]=191808;ans[8][6]=510336;ans[8][7]=1360128;ans[8][8]=3626752;ans[8][9]=10879488;
	ans[9][1]=512;ans[9][2]=26244;ans[9][3]=81648;ans[9][4]=217728;ans[9][5]=575424;ans[9][6]=1531008;ans[9][7]=4080384;ans[9][8]=10879488;ans[9][9]=29011456;scanf("%d%d",&n,&m);
	if(n>m) swap(n,m);
	a[0]=1;
	fo(i,1,m+1) a[i]=a[i-1]*3ll%mo;
	if(n==1)
	{
		a[0]=1;
		fo(i,1,m) a[i]=a[i-1]*2ll%mo;
		printf("%d\n",a[m]);
		return 0;
	}
	if(m>9)
	{
		int q=1ll*ans[n][9]*a[m-9]%mo;
		printf("%d\n",q);
	}
	else printf("%d\n",ans[n][m]);
	return 0;
}

/*
#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
const int N=11,A=521,mo=1e9+7;
int n,m;
int f[N][N][A],all;
int find(int a,int b,int c)
{
	int rt=m;
	fo(k,0,m-2)
	{
		int x=((1<<k)&b)?1:0,y=((1<<(k+1))&a)?1:0;
		if(y<x) return -1;
		if(x==y) rt=min(rt,k+1);
		if(k>c && x!=y) return -1;
	}
	return min(rt,c+1);
}
void add(int &a,int b)
{
	a=(a+b)%mo;
}
int ans;
int wri[N][N];
int main()
{
	freopen("D:/LiuYuanHao/a.in","r",stdin);
	freopen("D:/LiuYuanHao/a.out","w",stdout);
	for(m=1;m<=9;++m)
	for(n=m;n<=9;++n)
	{
		memset(f,0,sizeof f);
		if(n<m)swap(n,m);
		all=(1<<m)-1;
		fo(s,0,all)
			f[1][m][s]=1;
		fo(i,2,n)
			fo(jj,1,m)
			fo(s,0,all) fo(sp,0,all)
			if(f[i-1][jj][sp])
			{
				int j=find(sp,s,jj-1);
				if(j==-1) continue;
				add(f[i][j][s],f[i-1][jj][sp]);
			}
		ans=0;
		fo(j,1,m) fo(s,0,all)
			add(ans,f[n][j][s]);
//		printf("%d\n",ans);
		wri[n][m]=ans;
	}
	fo(i,1,9) 
	{
		putchar('\n');
		fo(j,1,9)
		{
			if(i<j) wri[i][j]=wri[j][i];
			printf("ans[%d][%d]=%d;",i,j,wri[i][j]);
		}
	}
	return 0;
}







*/







