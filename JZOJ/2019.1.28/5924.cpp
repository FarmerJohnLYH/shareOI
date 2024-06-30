#pragma GCC optimize(2) 
#include <deque>
#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define fd(i,x,y) for (int i=(x);i>=(y);--i)
using namespace std;
const int N=100100,P=417,M=N/P+10;
int n,m,c[N];
deque<int> a[M];
int le[M],ri[M],d[N][M];
int po[N];
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
	else
	while(x) buf[++b0]=x%10,x/=10;
	fd(i,b0,1) putchar(buf[i]+'0');
}
int main()
{
	freopen("queue.in","r",stdin);
	freopen("queue.out","w",stdout);
	// freopen("D:/LiuYuanHao/c1.in","r",stdin);
	// freopen("D:/LiuYuanHao/c.out","w",stdout);
	// scanf("%d%d",&n,&m);
	n=read(),m=read();
	fo(i,1,n)
	{
		c[i]=read();
		// scanf("%d",&c[i]);
		int p=i/P+1;
		if(!le[p])le[p]=i;
		ri[p]=i;
		a[p].push_back(c[i]);
		++d[c[i]][p];po[i]=p;
	}
	while(m--)
	{
		int opt=read(),l=read(),r=read();
		// scanf("%d%d%d",&opt,&l,&r);
		int ql=l-le[po[l]],qr=r-le[po[r]];
		if(opt==1)
		{
			if(po[l]==po[r])
			{
				int p=po[l],w=a[p][qr];
				a[p].erase(a[p].begin()+qr);
				a[p].insert(a[p].begin()+ql,w);
			}
			else
			{
				int p=po[l],q=po[r],w=a[q][qr];
				a[q].erase(a[q].begin()+qr);--d[w][q];
				a[p].insert(a[p].begin()+ql,w);++d[w][p];
				fo(i,p,q-1)
				{
					w=(*(a[i].end()-1));
					a[i].erase(a[i].end()-1);--d[w][i];
					a[i+1].insert(a[i+1].begin(),w);++d[w][i+1];
				}
			}
		}
		else
		{
			int k=read();
			// scanf("%d",&k);
			int ans=0;
			if(po[l]==po[r])
			{
				fo(i,ql,qr) 
					ans+=(a[po[l]][i]==k);
			}
			else
			{
				int p=po[l],q=po[r];
				for(int pp=a[p].size()-1,i=ql;i<=pp;++i)
					ans+=(a[p][i]==k);
				for(int i=0;i<=qr;++i)
					ans+=(a[q][i]==k);
				fo(i,p+1,q-1) ans+=d[k][i];
			}
			write(ans);puts("");
			// printf("%d\n",ans);
		}
	}
	return 0;
}








