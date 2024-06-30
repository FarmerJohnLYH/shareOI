#include <cmath>
#include <ctime>
#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x),asdfgh=(y);i<=asdfgh;++i)
#define fd(i,x,y) for (int i=(x),asdfgh=(y);i>=asdfgh;--i)
#define fi first
#define se second
using namespace std;
typedef double db;
typedef long long ll;
typedef pair<int,int> PI;
int abs(int x) {return(((x)>=0)?(x):(-(x)));}
int max(int x,int y) {return(((x)>(y))?(x):(y));}
int min(int x,int y) {return(((x)<(y))?(x):(y));}
int lowbit(int x) {return((x)&(-x));}
const int N=10001000,T=1000100,mo=998244353;
int n,m;
int bz[N],tot,p[T],mob[N];
void mobius()  
{  
	memset(bz,1,sizeof bz);
    mob[1]=1;
    fo(i,2,N-1000)
    {  
        if(bz[i])  
        {  
            p[++tot]=i;  
            mob[i]=-1;  
        }  
        fo(j,1,tot)  
        {  
			if(1ll*i*p[j]>N) break;
            bz[i*p[j]]=0;  
            if(i%p[j]==0)  
            {  
                mob[i*p[j]]=0;  
                break;  
            }  
            mob[i*p[j]]=-mob[i];  
        }  
    }  
} 
int qsm(int a,int b)
{
	int x=1;
	a%=mo,b%=(mo-1);
	while(b)
	{
		x=((b&1))?((1ll*x*(a))%mo):(x);
		b>>=1,a=(1ll*a*a)%mo;
	}
	return x;
}
int main()
{
	freopen("calc.in","r",stdin);
	freopen("calc.out","w",stdout);
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%d%d",&n,&m);
	mobius();
	int ans=0;
	fo(i,1,n)
		ans=(1ll*mob[i]*qsm(i,m)+ans)%mo;
	printf("%d\n",ans);
	return 0;
}











