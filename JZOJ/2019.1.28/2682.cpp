#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
const int N=100100*2;
int ans,mid,n;
int p[N],f[N],g[N];
char st[N];
int main()
{
	freopen("D:/LiuYuanHao/a.in","r",stdin);
//    scanf("%s",st+2);n=strlen(st+2)+1+1;st[1]='#',st[n]='#';
    st[n=1]='#';
    char ch=getchar();
    while(ch>='a'&&ch<='z') st[++n]=ch,ch=getchar(),st[++n]='#';
	fo(i,2,n)
    {
        p[i]=((p[mid]+mid>i)?(min(p[mid*2-i],p[mid]+mid-i)):(1));
        while(st[i-p[i]]==st[i+p[i]])
        {
            p[i]++;
            f[i+p[i]-1]=max(f[i+p[i]-1],p[i]);
            g[i-p[i]+1]=max(g[i-p[i]+1],p[i]);
        }
        if(p[i]+i>p[mid]+mid) mid=i;
    }
    fo(i,1,n)ans=max(ans,f[i]+g[i]);
    printf("%d\n",ans-2);
    return 0; 
}
