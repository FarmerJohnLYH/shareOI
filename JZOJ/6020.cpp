#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
typedef long long ll;
const int N=2*524288+1e5,mo=998244353,inv2=499122177;
int n,a[N],tw;
int f[N],d[N],c[N];
void fwt(int *a,int l,int r)
{
	if (l==r) return;
	int mid=(l+r)>>1,len=mid-l+1;
	fwt(a,l,mid);fwt(a,mid+1,r);
	fo(i,l,mid)
	{
		int u=a[i],v=a[i+len];
		a[i]=1ll*(u+v)%mo;a[i+len]=1ll*(mo+u-v)%mo;
	}
}
void ifwt(int *a,int l,int r) 
{
	if (l==r) return;
	int mid=(l+r)>>1,len=mid-l+1;
	fo(i,l,mid)
	{
		int u=a[i],v=a[i+len];
		a[i]=1ll*(u+v)*inv2%mo;a[i+len]=1ll*(u-v+mo)*inv2%mo;
	}
	ifwt(a,l,mid);ifwt(a,mid+1,r);
}
int main()
{
	 freopen("nim.in","r",stdin);
	 freopen("nim.out","w",stdout);
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%d",&n);
	fo(i,1,n) scanf("%d",&a[i]),tw^=a[i],c[a[i]]=1;
	int ans=0,sz=524287;
	fwt(c,0,sz);
	f[0]=1;
	while(!f[tw])
	{
		++ans;
		fwt(f,0,sz);
		fo(i,0,sz) f[i]=1ll*f[i]*c[i]%mo;
		ifwt(f,0,sz);
		fo(i,0,sz) f[i]=(f[i]>0);
	}
	printf("%d\n",n-ans);
	return 0;
}








