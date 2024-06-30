#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define sqr(x) ((x)*(x))
#define lowbit(x) ((x)&(-x))
#define abs(x) (((x)>=0)?(x):(-(x)))
#define max(x,y) (((x)>(y))?(x):(y))
#define min(x,y) (((x)<(y))?(x):(y))
#define fo(i,x,y) for (int i = (x);i <= (y);++ i)
#define fd(i,x,y) for (int i = (x);i >= (y);-- i)
using namespace std;
typedef double db;
typedef long long ll;
const int N = 100100;
int n,d[N * 4],a[N],q;
int type,l,r;
void build(int n)
{
    for(bit=1;bit<=n+1;bit<<=1);//bit = 总节点数目 - 叶子节点数目
    for(int i=bit+1;i<=bit+n;i++) d[i] = a[i - bit + 1] - a[i - bit];
        // scanf("%d",&d[i]);
    for(int i=bit-1;i;i--)
        d[i]=max(d[i<<1],d[i<<1|1]);
}
void updata(int x,int y)//修改 d[x] 为 y
{
    for(d[x+=bit]=y,x>>=1;x;x>>=1)
        d[x]=max(d[x<<1],d[x<<1|1]);
}
int query(int s,int t)//区间 [s,t] 最大值
{
    int ans=-1;
    for(s+=bit-1,t+=bit+1;s^t^1;s>>=1,t>>=1)
    {
        if(~s&1) ans=max(ans,d[s^1]);
        if(t&1) ans=max(ans,d[t^1]);
    }
    return ans;
}
int main()
{
    // freopen("lipschitz.in","r",stdin);
    // freopen("lipschitz.out","w",stdout);
    freopen("D:/LiuYuanHao/c.in","r",stdin);
    scanf("%d", &n);
    fo(i,1,n) scanf("%d", &a[i]);
    build(n - 1);
    scanf("%d", &q);
    while (q --)
    {
        scanf("%d%d%d", &type, &l, &r);
        if (type == 0)
        {
            a[l] = r;
            updata(l,a[l + 1] - a[l]);
            updata(l - 1,a[l] - a[l - 1]);
            continue;
        }
        ans = query(l,r);
        printf("%d\n", ans);
    }
}