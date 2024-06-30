#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
typedef long long ll;
const int maxn=100050;
const int N=1e7+10;
const ll MOD=1e9+7;
int prime[N],pz,isprime[N];
void get_prime(){
    memset(isprime,true,sizeof isprime);
    isprime[0]=isprime[1]=false;
    for(int i = 2; i < N; ++i){
        if(isprime[i]) prime[pz++]=i;
        for(int j = 0; (ll)i*prime[j]<N&& j<pz;++j){
            isprime[i*prime[j]]=false;
            if(i%prime[j]==0) break;
        }
    }
}

vector<int> G[maxn];
int n,q,f[maxn][20],L[maxn],R[maxn],dep[maxn],tot;
void dfs(int x,int par=0){
    L[x]=++tot;
    dep[x]=dep[par]+1;
    f[x][0]=par;
    for(int i = 1; f[x][i-1]; ++i) f[x][i]=f[f[x][i-1]][i-1];
    for(auto y:G[x])
        if(y!=par) dfs(y,x);
    R[x]=tot;
}
vector<pair<int,int> > v1[N],v2[N];
int X[maxn],Y[maxn],Z[maxn];
int sum[maxn];
void add(int x,int val){
    while(x<=n) sum[x]+=val,x+=(x&-x);
}
int Query(int x){
    int ans=0;
    while(x) ans+=sum[x],x-=(x&-x);
    return ans;
}
int lca(int x,int y){
    if(dep[x]<dep[y]) swap(x,y);
    int h=dep[x]-dep[y];
    for(int i = 0; h ; ++i){
        if(h&(1<<i)){
            x=f[x][i];
            h^=(1<<i);
        }
    }
    if(x==y) return x;
    for(int i = 19; i >= 0; --i){
        if(f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
    }
    return f[x][0];
}
ll ans[maxn];
ll Pow(ll x,ll n){
    ll ans=1,base=x%MOD;
    while(n){
        if(n&1) ans=ans*base%MOD;
        base=base*base%MOD;
        n>>=1;
    }
    return ans;
}
int dt[maxn];
int main(){
    get_prime();
    scanf("%d", &n);
    for(int i = 1; i < n; ++i){
        int x,y;
        scanf("%d%d", &x,&y);
        G[x].push_back(y);
        G[y].push_back(x);
    }
    dfs(1);
    for(int i = 1; i <= n; ++i){
        int x;
        scanf("%d", &x);
        for(int j = 0; (ll)prime[j]*prime[j]<=x; ++j){
            if(x%prime[j]==0){
                int cnt=0;
                while(x%prime[j]==0) x/=prime[j],cnt++;
                v1[prime[j]].push_back({cnt,i});
            }
        }
        if(x>1) v1[x].push_back({1,i});
    }
    int q;
    scanf("%d", &q);
    for(int i = 1; i <= q; ++i){
        int x;
        scanf("%d%d%d", &X[i],&Y[i],&x);
        Z[i]=lca(X[i],Y[i]);
        for(int j = 0; (ll)prime[j]*prime[j]<=x; ++j){
            if(x%prime[j]==0){
                int cnt=0;
                while(x%prime[j]==0) x/=prime[j],cnt++;
                v2[prime[j]].push_back({cnt,i});
            }
        }
        if(x>1) v2[x].push_back({1,i});
        ans[i]=1;
    }
    for(int i = 0; i < pz; ++i){
        int p=prime[i];
        if(v1[p].empty()||v2[p].empty()) continue;
        sort(v1[p].begin(),v1[p].end());
        sort(v2[p].begin(),v2[p].end());
        vector<int> v(v1[p].size(),0);
        int cur=0,cur2=0,m=v2[p][v2[p].size()-1].first;
        for(int j = 1; j <= m; ++j){
            while(cur<v1[p].size()&&v1[p][cur].first<j) cur++;
            for(int k = cur; k < v1[p].size(); ++k){
                int x=v1[p][k].second;
                add(L[x],1);
                add(R[x]+1,-1);
                v[k]++;
            }
            while(cur2<v2[p].size()&&v2[p][cur2].first<j) cur2++;
            
            while(cur2<v2[p].size()&&v2[p][cur2].first==j){
            
                int idx=v2[p][cur2].second;
                int x=X[idx],y=Y[idx],z=Z[idx],w=f[z][0];
                int d=Query(L[x])+Query(L[y])-Query(L[z])-Query(L[w]);
                ans[idx]=ans[idx]*Pow(p,d)%MOD;
                cur2++;
            }
        }
        for(int j = 0; j < v.size(); ++j){
            int x=v1[p][j].second;
            add(L[x],-v[j]);
            add(R[x]+1,v[j]);
        }
    }
    for(int i = 1; i <= q; ++i){
        printf("%lld\n", (ans[i]%MOD+MOD)%MOD);
    }
    return 0;
}