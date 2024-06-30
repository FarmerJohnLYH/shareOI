#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
inline int read() {
	int x=0,f=1;
	char c=getchar();
	for (;c<'0' || c>'9';c=getchar()) f=c=='-'?-1:1;
	for (;c>='0' && c<='9';c=getchar()) x=x*10+c-48;
	return f*x;
}
const ll N=2e3+50,p=998244353;
inline void add(ll &x,ll y) { x=x+y; if (x>=p) x-=p; }
ll f[N][N];
int main() 
{
    freopen("map.in", "r", stdin);
    freopen("map.out", "w", stdout);
    int i,j,k,n,cnt1=0,cnt2=0;
    n=read();
    for (i=1;i<=n;i++) {
    	int x=read();
    	if (x==1) cnt1++;
    	else cnt2++;
    }
    f[0][0]=1;
    for (i=0;i<=n;i++)
    {
        for (j=i;j>=0;j--)
        {
            k=i-j;
            if (k<0) continue;
            if (k==0 && j)
            	add(f[j+1][k],f[j-1][k]*j%p);
            if (j>=2) 
            	add(f[j][k+1],f[j-2][k]*((ll)j*(j-1)/2%p)%p);
            if (k>=2)
            	add(f[j][k+1],f[j+2][k-2]*((ll)k*(k-1)/2%p)%p);
            if (i*j) {
            	add(f[j][k+1],f[j][k-1]*j%p*k%p);
            }
        }
    }
    printf("%lld\n", f[cnt1][cnt2]);
    return 0;
}
