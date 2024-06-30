#include<string.h>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<stdio.h>
using namespace std;
#define fo(i,a,b) for(i=a;i<=b;i++)
const int maxn=1e5+5;
typedef long long ll;
struct arr{
    int n,m,mx,bh;
}a[20005];
struct da{
    int f,pr;
}f[maxn];
bool cmp(arr x,arr y){return x.mx<y.mx;}
bool cmp1(da x,da y){return x.f<y.f;}
bool p[maxn];
int cas,n,m,i,j,k,mx,s[maxn],mu[maxn],t[maxn];
ll mo,ans[maxn];
void screen(int mx){
    int i,j,k;
    fo(i,2,mx){
        if(!p[i]) s[++s[0]]=i,mu[i]=-1;
        fo(j,1,s[0]){
            k=i*s[j];
            if(k>mx) break;
            p[k]=true;
            if(i%s[j]==0){
                mu[k]=0;
                break;
            }
            mu[k]=mu[i]*mu[s[j]];
        }
    }
    mu[1]=1;
    fo(i,1,mx){
        f[i].pr=i;
        for(j=i;j<=mx;j+=i) f[j].f+=i;
    }
}
void add(int x,int sum){
    for(x=x;x<=mx;x+=x&(-x)) t[x]+=sum;
}
int get(int x){
    int sum;
    sum=0;if(x==0) return 0;
    for(x=x;x;x-=x&(-x)) sum+=t[x];
    return sum;
}
void solve(int x)
{
    int n,m,bh,i,j;
    n=a[x].n,m=a[x].m,bh=a[x].bh;
    for(i=1;i<=n;i=j+1){
        j=min(n/(n/i),m/(m/i));
        ans[bh]+=(n/i)*(m/i)*(get(j)-get(i-1));
    }
}
int main(){
    freopen("table.in","r",stdin);
    freopen("table.out","w",stdout);
    mo=1;fo(i,1,31) mo=mo*2;
    scanf("%d",&cas);
    fo(i,1,cas){
        scanf("%d%d%d",&a[i].n,&a[i].m,&a[i].mx);
        if(a[i].n>a[i].m) swap(a[i].n,a[i].m);
        a[i].bh=i;mx=max(mx,a[i].n);
    }
    screen(mx);
    sort(a+1,a+cas+1,cmp);
    sort(f+1,f+mx+1,cmp1);
    j=0;
    fo(i,1,cas){
        while(j<mx&&f[j+1].f<=a[i].mx){
            j++;    
            for(k=f[j].pr;k<=mx;k+=f[j].pr){
                add(k,f[j].f*mu[k/f[j].pr]);
            }
        }
        solve(i);
    }
    fo(i,1,cas) printf("%lld\n",ans[i]%mo);
}