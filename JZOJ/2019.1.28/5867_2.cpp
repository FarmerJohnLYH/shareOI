#include <ctime>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
const int N=22;
int n,m;
int T,a[N][N];
int rle[N],rri[N];
int pd(int x,int y)
{
	return(a[rle[x]][rri[y]]==a[rle[n-x+1]][rri[m-y+1]]);
}
int check()
{
	fo(i,1,n) fo(j,1,m>>1)
	if(!pd(i,j)) return 0;
	return 1;
}
int p[2][N];
int ckall(int tp,int x,int y)
{
	if(tp==0)
	{
		fo(i,1,m) p[0][i]=a[x][i],p[1][i]=a[y][i];
		sort(p[0]+1,p[0]+1+m);sort(p[1]+1,p[1]+1+m);
		fo(i,1,m) if(p[0][i]!=p[1][i]) return 0;
		return 1;
	}
		fo(i,1,n) p[0][i]=a[i][x],p[1][i]=a[i][y];
		sort(p[0]+1,p[0]+1+n);sort(p[1]+1,p[1]+1+n);
		fo(i,1,n) if(p[0][i]!=p[1][i]) return 0;
		return 1;
}
int vle[N],flag,vri[N],ble[N][N],bri[N][N];
void dfsri(int x)
{
	if(flag)return;
	if(x==0)
	{
		if(check()) flag=1;
		return;
	}

	fo(i,1,m)if(!vri[i])fo(j,i+1,m)if(!vri[j])
	if(bri[i][j])
	{
		rri[x]=i,rri[m-x+1]=j;
		vri[i]=vri[j]=1;
		dfsri(x-1);
		rri[x]=rri[m-x+1]=vri[i]=vri[j]=0;
	}
}
void dfsle(int x)
{
	if(flag)return;
	if(x==0)
	{
		dfsri(m/2);
		return;
	}
	fo(i,1,n)if(!vle[i])fo(j,i+1,n)if(!vle[j])
	if(ble[i][j])
	{
		rle[x]=i,rle[n-x+1]=j;
		vle[i]=vle[j]=1;
		dfsle(x-1);
		rle[x]=rle[n-x+1]=vle[i]=vle[j]=0;
	}
}
int main()
{
	 freopen("fragment.in","r",stdin);
	 freopen("fragment.out","w",stdout);
//	freopen("D:/LiuYuanHao/b3.in","r",stdin);
	scanf("%d",&T);scanf("%d\n",&T);
	while(T--)
	{
		scanf("%d%d\n",&n,&m);
		fo(i,1,n) 
		{
			fo(j,1,m)
			{
				char ch;
				scanf("%c",&ch);
				a[i][j]=ch-'A';
			}
			scanf("\n");		
		}
		fo(i,1,n) fo(j,i+1,n)
				ble[i][j]=ckall(0,i,j);
		fo(i,1,m) fo(j,i+1,m)
				bri[i][j]=ckall(1,i,j); 
		flag=0;
		dfsle(n/2);
		if(flag)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}











