//#pragma GCC optimize(2) 
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x),GG=(y);i<=GG;++i)
#define fd(i,x,y) for (int i=(x),GG=(y);i>=GG;--i)
using namespace std;
const int N=100100;
int n;
int fa[N],ans[N],v[N];
vector<int> to[N],d[N];int c[N];
int le,ri,mid,rt;
int d0,d1;
int mx[N];
// int l[N],r[N],;
void dfs(int x,int de)
{
	d[de].push_back(-1);
	c[de]=0;
	// d[de].reserve(n-de+10);
	fo(i,0,to[x].size()-1)
	{
		dfs(to[x][i],de+1);
		if(c[de+1]>c[de]) 
		{
			fo(l,c[de]+1,c[de+1])d[de].push_back(d[de+1][l]);
			swap(c[de],c[de+1]);
		}
		fo(l,1,c[de+1]) d[de][l]=min(d[de][l],d[de+1][l]);  
		c[de+1]=0;
		d[de+1].resize(1);
	}
	le=0,ri=c[de];
	while(le<=ri) 
	{
		mid=(le+ri)>>1;
		if(d[de][mid]<=v[x]) le=mid+1,rt=mid;
		else ri=mid-1;
	}
	ans[x]=rt+1;
	if(rt+1>(c[de])) ++c[de],d[de].push_back(v[x]);
	else d[de][rt+1]=min(v[x],d[de][rt+1]);
}
int read()
{
    char ch=' ';int q=0,w=1;
    for(;(ch!='-')&&((ch<'0')||(ch>'9'));ch=getchar());
    if(ch=='-')w=-1,ch=getchar();
    for(;ch>='0' && ch<='9';ch=getchar())q=q*10+ch-48;int n=q*w;return n;
}
int buf[30],b0;
void write(int x)
{
	b0=0;
	if(x==0)putchar('0');
	else while(x) buf[++b0]=x%10,x/=10;
	fd(i,b0,1) putchar(buf[i]+'0');
}
int main()
{
	// freopen("D:/LiuYuanHao/c2.in","r",stdin);
	// freopen("D:/LiuYuanHao/b2.out","w",stdout);
	scanf("%d",&n); 
	fo(i,1,n) 
	{ 
		fa[i]=read();
		if(i>1) to[fa[i]].push_back(i);
	}fa[1]=0;
	fo(i,1,n)v[i]=read();
	dfs(1,0);
	fo(i,1,n)write(ans[i]),putchar(' ');
//	printf("%d ",ans[i]);
	return 0;
}











