#include<cmath>
#include<cstdio>
#include<algorithm>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

typedef long long LL;

const int maxn=(1e5)+5, MX=18;

struct TR{
    int x,y;
    LL len;

    TR(int X=0,int Y=0,LL LEN=0) {x=X, y=Y, len=LEN;}
};

int n;

int tot,go[2*maxn],next[2*maxn],f1[maxn];
LL val[2*maxn];
void ins(int x,int y,LL z)
{
    go[++tot]=y;
    val[tot]=z;
    next[tot]=f1[x];
    f1[x]=tot;
}

int fa[2*maxn][MX+5],deep[maxn],ap[2*maxn],fir[2*maxn],Log[2*maxn],er[MX+5];
void rmq_pre()
{
    fo(i,1,ap[0]) fa[i][0]=ap[i], Log[i]=log(i)/log(2);
    fo(i,0,MX) er[i]=1<<i;
    fo(j,1,MX)
        fo(i,1,ap[0])
        {
            fa[i][j]=fa[i][j-1];
            if (i+er[j-1]<=ap[0] && deep[fa[i+er[j-1]][j-1]]<deep[fa[i][j]])
                fa[i][j]=fa[i+er[j-1]][j-1];
        }
}
int lca(int x,int y)
{
    x=fir[x], y=fir[y];
    if (x>y) swap(x,y);
    int t=Log[y-x+1];
    return (deep[fa[x][t]]<deep[fa[y-er[t]+1][t]]) ?fa[x][t] :fa[y-er[t]+1][t] ;
}

int st[maxn],en[maxn],sum,Tbh[maxn];
LL dis[maxn];
void dfs_pre(int k,int last,LL s)
{
    deep[k]=deep[last]+1;
    dis[k]=s;
    ap[++ap[0]]=k, fir[k]=ap[0];
    Tbh[++sum]=k, st[k]=sum;
    for(int p=f1[k]; p; p=next[p]) if (go[p]!=last)
    {
        dfs_pre(go[p],k,s+val[p]);
        ap[++ap[0]]=k;
    }
    en[k]=sum;
}

TR tr[4*maxn];
LL DIS(int x,int y) {return dis[x]+dis[y]-dis[lca(x,y)]*2;}
TR merge(TR a,TR b)
{
    TR re= (a.len>b.len) ?a :b;
    if (DIS(a.x,b.x)>re.len) re=TR(a.x,b.x,DIS(a.x,b.x));
    if (DIS(a.x,b.y)>re.len) re=TR(a.x,b.y,DIS(a.x,b.y));
    if (DIS(a.y,b.x)>re.len) re=TR(a.y,b.x,DIS(a.y,b.x));
    if (DIS(a.y,b.y)>re.len) re=TR(a.y,b.y,DIS(a.y,b.y));
    return re;
}
void tr_js(int k,int l,int r)
{
    if (l==r)
    {
        tr[k].x=tr[k].y=Tbh[l];
        tr[k].len=0;
        return;
    }
    int t=k<<1, t1=(l+r)>>1;
    tr_js(t,l,t1), tr_js(t+1,t1+1,r);
    tr[k]=merge(tr[t],tr[t+1]);
}
TR tr_cx(int k,int l,int r,int x,int y)
{
    if (l==x && r==y) return tr[k];
    int t=k<<1, t1=(l+r)>>1;
    if (y<=t1) return tr_cx(t,l,t1,x,y);
        else if (x>t1) return tr_cx(t+1,t1+1,r,x,y);
            else return merge(tr_cx(t,l,t1,x,t1),tr_cx(t+1,t1+1,r,t1+1,y));
}

LL ans;
void dfs(int k,int last)
{
    for(int p=f1[k]; p; p=next[p]) if (go[p]!=last)
    {
        int St=st[go[p]], En=en[go[p]];
        if (St==1)
        {
            ans=max(ans,tr_cx(1,1,n,St,En).len+tr_cx(1,1,n,En+1,n).len);
        } else if (En==n)
        {
            ans=max(ans,tr_cx(1,1,n,1,St-1).len+tr_cx(1,1,n,St,En).len);
        } else
        {
            TR t=merge(tr_cx(1,1,n,1,St-1),tr_cx(1,1,n,En+1,n));
            ans=max(ans,t.len+tr_cx(1,1,n,St,En).len);
        }

        dfs(go[p],k);
    }
}

int main()
{
    scanf("%d",&n);
    fo(i,1,n-1)
    {
        int x,y; LL d;
        scanf("%d %d %lld",&x,&y,&d);
        ins(x,y,d), ins(y,x,d);
    }

    dfs_pre(1,0,0);
    rmq_pre();
    tr_js(1,1,n);

    dfs(1,0);

    printf("%lld\n",ans);
}
