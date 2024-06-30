#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#define fo(p,q,r) for(p=q;p<=r;p++)
#define fow(p,q,r) for(p=q;p>=r;p--)
#define maxn 1000005
using namespace std;

long long sa[maxn],rank[maxn],tc[maxn],tsa[maxn],tail,n,i,j,m,stot,t,l;
long long cnt,sum,h[maxn],x,qu[maxn],y;
char s[maxn];

void jishu()
{
    arclr(tc,0);
    memset(tc,0,sizeof tc);
    fo(i,0,n-1) tc[rank[tsa[i]]]++;
    fo(i,1,m) tc[i]+=tc[i-1];
    fow(i,n-1,0) sa[--tc[rank[tsa[i]]]]=tsa[i];
}

void buildsa()
{
    memset(sa,0,sizeof sa),memset(rank,0,sizeof rank);
    // arclr(sa,0); arclr(rank,0); 
    fo(i,0,n-1) rank[i] = s[i] - 'a' + 1;
    fo(i,0,n-1) tsa[i] = i;
    m=maxn+1;
    
    jishu();
    
    for (j=1;j<=n;j<<=1)
    {
        stot=0;
        fo(i,n-j,n-1) tsa[stot++]=i;
        fo(i,0,n-1) if (sa[i]>=j) tsa[stot++]=sa[i]-j;
        
        jishu(); 
        
        swap(rank,tsa);
        stot=0;
        rank[sa[0]]=++stot; 
        fo(i,1,n-1)
            if ((tsa[sa[i-1]]==tsa[sa[i]])&&(tsa[sa[i-1]+j]==tsa[sa[i]+j]))
            rank[sa[i]]=stot;
            else rank[sa[i]]=++stot;
        m=stot;
        if (m==n) break;
    }
}

void buildh()
{
    arclr(h,0);
    j=0; i=0;
    if (rank[i]==1) i++; 
    while (s[i+j]==s[sa[rank[i]-2]+j]) j++; 
    h[rank[i]-1]=j;
    
    i++;
    while (i<=n-1)
    {
        if (rank[i]!=1)
        {
            if (j>0) j--;
            while (s[i+j]==s[sa[rank[i]-2]+j]) j++;
            h[rank[i]-1]=j;
        }
        i++;
    }
}

void solve()
{
    arclr(qu,0);
    tail=0; qu[0]=0; cnt=0; sum=0; h[n]=0;
    fo(i,1,n)
    {
        while ((tail>0)&&(h[qu[tail]]>=h[i]))
        {
            x=i-qu[tail-1];
            y=h[qu[tail]]-max(h[i],h[qu[tail-1]]);
            cnt+=x*y;
            sum+=x*x*y;
            tail--;
        }
        tail++;
        qu[tail]=i;
    }
    sum=sum+n*(n+1)/2-cnt;
}

int main()
{
    scanf("%lld", &t);
    fo(l,1,t)
    {
        scanf("%s",s);
        n=strlen(s);
        
        buildsa();
        
        buildh();
    
        solve();
        printf("%lld\n",sum);
    }
}