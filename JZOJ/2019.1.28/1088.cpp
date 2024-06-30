#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define abs(x) ((x<0)?(-(x)):(x))
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
const int N=22,M=122,mo=45989;
int n,m,t,st,ed;
int al[2*M][2],fr[N][2*M];
struct node{int a[M][M];};
node ti(node a,node b)
{
    node c;
    fo(i,1,2*m)
        fo(j,1,2*m)
        {
            c.a[i][j]=0;
            fo(k,1,2*m)
                c.a[i][j]=(c.a[i][j]+a.a[i][k]*b.a[k][j])%mo;
        }
    return c;   
}
node s;
node ksm(node k,int n)
{
    if(n==1) return k;
    node s=ksm(k,n/2);
    return (n%2)?ti(s,ti(s,k)):ti(s,s);
}
int main()
{
 	scanf("%d%d%d%d%d",&n,&m,&t,&st,&ed);
    fo(i,1,m) 
    {
        int x,y;
        scanf("%d%d",&x,&y);
        al[2*i-1][0]=al[2*i][1]=x;
        al[2*i-1][1]=al[2*i][0]=y;
        fr[x][++fr[x][0]]=2*i-1;
        fr[y][++fr[y][0]]=2*i;
    }
    fo(i,1,2*m)
    {
        int x=al[i][0],y=al[i][1];
        fo(j,1,fr[y][0])
            if(!(abs((fr[y][j]>>1)-(i>>1))==1&&abs(fr[y][j]-i)==1))
            	s.a[i][fr[y][j]]=1;
    }
    s=ksm(s,t-1);
    int ans=0;
    fo(i,1,2*m)
        fo(j,1,2*m)
            if(al[i][0]==st&&al[j][1]==ed) ans=(ans+s.a[i][j])%mo;
    printf("%d\n",ans);
}





