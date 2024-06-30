#include <map>
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
typedef pair <ll,ll> Lpair;
int abs(int x) {return(((x)>=0)?(x):(-(x)));}
int max(int x,int y) {return(((x)>(y))?(x):(y));}
int min(int x,int y) {return(((x)<(y))?(x):(y));}
int lowbit(int x) {return((x)&(-x));}
const ll MOD1=1000000007;
const ll MOD2=55566677;
const ll BASE1=233;
const ll BASE2=109;
const int N=200005;

int rad[N],n,k,cnt;
char str[N],a[N];
ll hash1[N],hash2[N],pow1[N],pow2[N],m;
map <Lpair,bool> mp;
vector <PI> vec;

Lpair get_hash(int x,int y) {
    ll h1=(hash1[y]-hash1[x-1]*(ll)pow1[y-x+1]%MOD1+MOD1)%MOD1;
    ll h2=(hash2[y]-hash2[x-1]*(ll)pow2[y-x+1]%MOD2+MOD2)%MOD2;
    return Lpair(h1,h2);
}

bool cmp(PI a,PI b) {
    int lena=a.second-a.first+1;
    int lenb=b.second-b.first+1;
    if (lena!=lenb) return lena<lenb;
    int l=1,r=lena,rec=0;
    while (l<=r) {
        int mid=(l+r)>>1;
        Lpair ha=get_hash(a.first+1,a.first+mid);
        Lpair hb=get_hash(b.first+1,b.first+mid);
        if (ha==hb) l=mid+1;
        else r=mid-1;
    }
    return (str[a.first+r]<str[b.first+r]);
}
int main()
{
    freopen("D:/LiuYuanHao/c.in","r",stdin);
    scanf("%d%lld",&n,&m);
    scanf("%s",str);
    pow1[0]=pow2[0]=1;
    fo(i,1,n) 
    {
        hash1[i]=((ll)hash1[i-1]*(ll)BASE1+str[i-1])%MOD1;
        hash2[i]=((ll)hash2[i-1]*(ll)BASE2+str[i-1])%MOD2;
        pow1[i]=(ll)pow1[i-1]*(ll)BASE1%MOD1;
        pow2[i]=(ll)pow2[i-1]*(ll)BASE2%MOD2;
    }
    fo(i,0,n-1) 
    {
        a[i*2]='#';
        a[i*2+1]=str[i];
    }
    a[n*2]='#';
    int len=n*2+1,mx=0,pos=0;
    int ans=0;
    fo(i,0,len-1) 
    {
        if (i<mx) rad[i]=min(mx-i,rad[pos*2-i]);
        else rad[i]=0;
        while ((i-rad[i]>0)&&(i+rad[i]+1<len)&&(a[i-rad[i]-1]==a[i+rad[i]+1])) 
        {
            rad[i]++;
            Lpair h=get_hash((i-rad[i])/2+1,(i+rad[i]-1)/2+1);
            if ((!rad[i]&&a[i]=='#')||mp.count(h)) continue;
            mp[h]=1; ans++; vec.push_back(PI((i-rad[i])/2,(i+rad[i]-1)/2));
        }
        if (i+rad[i]>mx) 
        {
            mx=i+rad[i];
            pos=i;
        }
    }
    printf("%d\n", ans); k=m%ans+1;
    sort(vec.begin(),vec.end(),cmp);
    fo(i,vec[k-1].first,vec[k-1].second) putchar(str[i]);
    putchar('\n');
    return 0;
}