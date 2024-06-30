#include<cstdio>
#include<algorithm>
#include<cstring>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
typedef long long ll;
const int N=3e5+5;
int n,m;
ll ans[N];
struct node
{
    ll x,y;
    int id;
}a[N],b[N],c[N];
int q[N],l,r;
bool cmp1(node a,node b)
{
    return a.x>b.x;
}
bool cmp2(node a,node b)
{
    return a.x<b.x;
}
inline double pd(node a,node b)
{
    return (double)(a.y-b.y)/(double)(a.x-b.x);
}
inline ll find(node A)
{
    int l1=2,r1=r,ans=1;
    while (l1<=r1)
    {
        int mid=(l1+r1)>>1;
        if (pd(b[q[mid]],b[q[mid-1]])<=(double)A.y)ans=mid,l1=mid+1;
        else r1=mid-1;
    }
    int x=b[q[ans]].id;
    return a[x].y-abs(A.x-a[x].x)*A.y;
}
int main()
{
    freopen("gas.in","r",stdin);
    freopen("gas.out","w",stdout);
    scanf("%d%d",&n,&m);
    fo(i,1,n)scanf("%lld%lld",&a[i].x,&a[i].y),a[i].id=i;
    fo(i,1,m)scanf("%lld%lld",&c[i].x,&c[i].y),c[i].id=i;
    fo(i,1,n)b[i]=a[i],b[i].x=-b[i].x;
    sort(b+1,b+n+1,cmp1);
    sort(c+1,c+m+1,cmp2);
    int x=0;
    memset(ans,0,sizeof(ans));
    fo(i,1,m)
    {
        //while (r2<n&&t1[r2+1].a<=c[i])r2++;
        while (x<n&&-b[x+1].x<=c[i].x)
        {
            ++x;
            while (r>1&&pd(b[q[r]],b[q[r-1]])>=pd(b[x],b[q[r-1]]))r--;
            q[++r]=x;
        }
        ans[c[i].id]=max(ans[c[i].id],find(c[i]));  
    }
    r=0;
    fo(i,1,n)b[i]=a[i];
    sort(b+1,b+n+1,cmp1);
    sort(c+1,c+1+m,cmp1);
    x=0;
    fo(i,1,m)
    {
        while (x<n&&b[x+1].x>=c[i].x)
        {
            ++x;
            while (r>1&&pd(b[q[r]],b[q[r-1]])>=pd(b[x],b[q[r-1]]))r--;
            q[++r]=x;
        }
        ans[c[i].id]=max(ans[c[i].id],find(c[i]));  
    }
    fo(i,1,m)printf("%lld\n",ans[i]);
}