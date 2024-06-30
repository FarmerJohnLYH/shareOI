#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define fo(i,x,y) for(int i=(x);i<=(y);++i)
#define fd(i,x,y) for(int i=(x);i>=(y);--i)
#define sqr(x) (1ll*x*x%mo)
#define hf 9630409
using namespace std;
typedef long long ll;
int read()
{
	int rt=0,fg=1;char ch=getchar();
	while(!(ch=='-'||(ch>='0'&&ch<='9'))) ch=getchar();
	if(ch=='-') fg=-1,ch=getchar();
	while((ch>='0'&&ch<='9'))rt=rt*10+ch-'0',ch=getchar();
	return rt*fg;
}
const int N=666666+10,mo=19260817;
ll a[N];int n,m,c;
vector<int> ve[N];
int sz[N],p[N];
bool cmp(int x,int y)
{
	return(sz[x]>sz[y]);
}
ll all,cn[N];
ll C2(ll m)
{
	return(m*(m-1)%mo*hf%mo);
}
int main()
{
	freopen("everytime.in","r",stdin);
	freopen("everytime.out","w",stdout);
	n=read();
	fo(i,1,n) 
	{
		a[i]=read();
		ve[a[i]].push_back(i);
		p[a[i]]=a[i];++sz[a[i]];
	}
	all=1;
	sort(p+1,p+1+n,cmp);
	fo(i,1,n)if(sz[p[i]]==0) c=i-1;
	else all=all*C2(sz[p[i]])%mo;
	m=min(888,c);
	fo(i,1,n)
	{
		cnt=(cnt+cn[a[i]]);
		++cn[a[i]];
	}
	return 0;
}






