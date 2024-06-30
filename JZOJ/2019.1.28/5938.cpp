#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2000000000
#define fo(i,x,y) for(int i=(x);i<=(y);++i)
#define fd(i,x,y) for(int i=(x);i>=(y);--i)
using namespace std;
int read()
{
	char c=getchar();int rt=0,f=1;
	while(c!='-'&&(!(c>='0'&&c<='9'))) c=getchar();
	if(c=='-') f=-1,c=getchar();
	while(c>='0'&&c<='9') rt=rt*10+c-48,c=getchar();
	return rt*f;
}
const int N=2020;
int mx,mn,n,m;
int a[4][N][N];
int le,ri,mid;
int pre[4][N][N],suf[4][N][N];
void rotate(int x,int y)
{
	a[y][m][1]=a[x][1][1];
	a[y][m][n]=a[x][n][1];
	fo(i,1,n) fo(j,1,m)
		a[y][m-j+1][i]=a[x][i][j];
	swap(n,m);
	memset(pre[y],128,sizeof pre[y]);
	memset(suf[y],127,sizeof suf[y]);
	fo(i,1,n)
	{
		fo(j,1,m) pre[y][i][j]=max(pre[y][i][j-1],a[y][i][j]);
		fd(j,m,1) suf[y][i][j]=min(suf[y][i][j+1],a[y][i][j]);
	}
}
int solve(int p,int va,int vb)
{
	int las=m;
	fo(i,1,n)
	{
		while(pre[p][i][las]>va&&las>0) --las;	
		if(suf[p][i][las+1]<vb) return 0; 
	}
	return 1;
}
int check(int va)
{
	int o=0,flag=0;
	fo(k,0,3)
	{
		if(!flag&&solve(k,mn+va,mx-va)) flag=1;
		if(flag)
		{
			if(k&1) swap(n,m);
			return flag;
		}
		swap(n,m);
	}
	return flag;
}
int main()
{
//	freopen("D:/LiuYuanHao/a2.in","r",stdin);
	 freopen("separate.in","r",stdin);
	 freopen("separate.out","w",stdout);
	mx=-oo,mn=oo;
	n=read(),m=read();
	fo(i,1,n)
		fo(j,1,m)
			a[0][i][j]=read(),mn=min(mn,a[0][i][j]),mx=max(mx,a[0][i][j]);
	rotate(0,1),rotate(1,2),rotate(2,3),rotate(3,0);
	le=0,ri=mx-mn-1;int ans=ri+1;
	while(le<=ri)
	{
		mid=(le+ri)>>1;
		if(check(mid)) ri=mid-1,ans=mid;
		else le=mid+1;
	}
	printf("%d\n",ans);
	return 0;
}

