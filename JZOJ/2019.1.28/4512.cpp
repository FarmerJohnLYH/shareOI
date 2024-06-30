#include<iostream>  
#include<cstring>  
#include<ctime>  
#include<cmath>  
#include<algorithm>  
#include<iomanip>  
#include<cstdlib>  
#include<cstdio>  
#include<map>  
#include<bitset>  
#include<set>  
#include<stack>  
#include<vector>  
#include<queue>  
using namespace std;  
#define MAXN 2510  
#define MAXM 1010  
#define ll long long  
#define eps 1e-8  
#define MOD 1000000007  
#define INF 1000000000  
struct vec{  
    int to;  
    int fro;  
};  
vec mp[MAXN];  
int tai[MAXN],cnt;  
int a[MAXN],b[MAXN];  
int n,m;  
double f[MAXN][MAXN];  
double g[MAXN];  
double v[MAXN];  
int siz[MAXN];  
inline void be(int x,int y){  
    mp[++cnt].to=y;  
    mp[cnt].fro=tai[x];  
    tai[x]=cnt;  
}  
void build(double x){  
    int i,j;  
    for(i=0;i<=n;i++){  
        v[i]=a[i]-x*b[i];  
        for(j=0;j<=n;j++){  
            f[i][j]=-INF;  
        }  
    }  
}  
void update(int x,int y){  
    int i,j;  
    for(i=0;i<=siz[x]+siz[y];i++){  
        g[i]=-INF;  
    }  
    for(i=0;i<=siz[x];i++){  
        for(j=0;j<=siz[y];j++){  
            g[i+j]=max(g[i+j],f[x][i]+f[y][j]);  
        }  
    }  
    siz[x]+=siz[y];  
    for(i=0;i<=siz[x];i++){  
        f[x][i]=max(f[x][i],g[i]);  
    }  
}  
void dfs(int x){  
    int i,y;  
    siz[x]=0;  
    f[x][0]=0;  
    for(i=tai[x];i;i=mp[i].fro){   
        y=mp[i].to;  
        dfs(y);  
        update(x,y);  
    }  
    for(i=siz[x];~i;i--){  
        f[x][i+1]=f[x][i]+v[x];  
    }  
    siz[x]++;  
    f[x][0]=0;  
}  
int main(){  
    int i,x;  
    scanf("%d%d",&m,&n);  
    m++;  
    for(i=1;i<=n;i++){  
        scanf("%d%d%d",&b[i],&a[i],&x);  
        be(x,i);  
    }  
    double l=0,r=10000;  
    double ans;  
    while(fabs(l-r)>eps){  
        double mid=(l+r)/2;  
        build(mid);  
        dfs(0);  
        if(f[0][m]>0){  
            ans=mid;  
            l=mid;  
        }else{  
            r=mid;  
        }  
    }  
    printf("%.3lf\n",ans);  
    return 0;  
}  
