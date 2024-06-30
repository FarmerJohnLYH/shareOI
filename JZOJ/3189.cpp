#include <map>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm> 
#define oo 2139062143
#define fo(i,x,a0) for (int i=(x);i<=(a0);++i)
using namespace std;
typedef long long ll;
const int mo1=1000000007,mo2=10007,mo3=9999991,mo4=1000007;
const int N=1001000;
map<ll,int>las;
int n,len2,len1,ans;
ll s,a[N],b[N],p2[N],p1[N];
char c[N];
ll get()
{
	int len=strlen(c);
	ll s=0; fo(i,0,len-1)s=(s*26+c[i]-'a')%mo1;
	ll s1=0;fo(i,0,len-1)s1=(s1*26+c[i]-'a')%mo2;
	return (s+s1*mo1);
}
void solve()
{
	ll ss=0;
	fo(i,1,len2)
	{
		ss=(ss*mo4)%mo1;
		if (a[i]) ss=(ss+p2[i-a[i]])%mo1;
	}
	if (ss==s)
	{
		ans=1;
		return;
	}
	fo(i,len2+1,len1)
	{
		int l=i-len2;
		if(b[l] && b[l]<i)
			ss=((ss-p2[b[l]-l]*p1[i-b[l]-1])%mo1+mo1)%mo1;
		ss=(ss*mo4)%mo1;
		if(a[i] && a[i]>l) ss=(ss+p2[i-a[i]])%mo1;
		if (ss==s)
		{
			ans=i-len2+1;
			return;
		}
	}
}
int main(){
	// freopen("a.in","r",stdin);
	// freopen("a.out","w",stdout);
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
	p2[0]=p1[0]=1;
	fo(i,1,N-10)
		p2[i]=p2[i-1]*mo3%mo1,p1[i]=p1[i-1]*mo4%mo1;
	ll x,a0=0,z;
	for(scanf("%s",c);(c[0]!='$');scanf(" %s",c))
		x=get(),a[++a0]=las[x],b[a[a0]]=a0,las[x]=a0;
	len1=a0;
	a0=0;
	las.clear();
	for(scanf("%s",c);c[0]!='$';scanf(" %s",c))
	{
		x=get();z=las[x];++a0;
		s=(s*mo4)%mo1;
		if(z)s=(s+p2[a0-z])%mo1;
		las[x]=a0;	
	}
	len2=a0;las.clear();
	solve();
	printf("%d\n",ans);
	return 0;
}









