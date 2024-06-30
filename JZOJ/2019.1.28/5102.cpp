#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
#define fo(i,a,b) for(i=a;i<=b;i++)
#define fod(i,a,b) for(i=a;i>=b;i--)
using namespace std;
const int maxn=2007;
int i,j,k,l,t,n,m,ans,pan,o,x,y,hou;
int f[maxn][maxn],g[maxn][maxn][2],cas,se[27][maxn];
char s[maxn],st[maxn];
int a[maxn][26],b[maxn][26],an[maxn][2],c[maxn];
int main(){
    freopen("chinese.in","r",stdin);
    freopen("chinese.out","w",stdout);
    for(scanf("%d",&cas);cas;cas--){
        scanf("%s",s+1);scanf("%s",st+1);n=strlen(s+1);
        memset(f,127,sizeof(f));memset(g,0,sizeof(g));
        pan=f[0][0];fod(i,n+1,1)f[n+1][i]=n+1-i;
        memset(a,0,sizeof(a));memset(b,0,sizeof(b));
        fod(i,n,1){
            fo(j,0,25)a[i][j]=a[i+1][j],b[i][j]=b[i+1][j];
            a[i][s[i]-'a']++,b[i][st[i]-'a']++;
        }
        fod(i,n,1){
            fod(j,n,1){
                if(f[i+1][j]!=pan&&f[i][j]>f[i+1][j]&&b[j][s[i]-'a']-a[i+1][s[i]-'a']>0){
                    f[i][j]=f[i+1][j];
                    g[i][j][0]=i+1,g[i][j][1]=j;
                }
                if(f[i+1][j+1]!=pan&&f[i][j]>f[i+1][j+1]&&s[i]==st[j]){
                    f[i][j]=f[i+1][j+1];
                    g[i][j][0]=i+1,g[i][j][1]=j+1;
                }
            }
            fod(j,n,1){
                if(f[i][j+1]!=pan&&f[i][j]>f[i][j+1]+1){
                    f[i][j]=f[i][j+1]+1;
                    g[i][j][0]=i,g[i][j][1]=j+1;
                }
            }
        }
        printf("%d\n",f[1][1]);
        x=1,y=1;o=0;memset(se,0,sizeof(se));memset(c,0,sizeof(c));hou=n;
        while(x!=n+1){
            while(g[x][y][0]==x)y=g[x][y][1];
            if(g[x][y][1]!=y)c[y]++,y++;
            x++;
        }
        fo(i,1,n){c[i]=1-c[i];if(c[i])se[st[i]-'a'][++se[st[i]-'a'][0]]=i;}
        fod(i,n,1){
            if(!hou)break;
            if(!c[i]){
                while(s[hou]!=st[i]){
                    an[++o][0]=se[s[hou]-'a'][se[s[hou]-'a'][0]--],an[o][1]=i+1;
                    hou--;
                }
                hou--;
            }
        }
        fod(j,hou,1){
            i=s[j]-'a';
            an[++o][0]=se[i][se[i][0]--],an[o][1]=1;
        }
        fo(i,1,o){
            fo(j,i+1,o){
                if(an[i][0]>=an[j][0]&&an[j][0]>=an[i][1])an[j][0]++;
                if(an[i][0]>an[j][1]&&an[j][1]>an[i][1])an[j][1]++;
            }
        }
        fo(i,1,o)printf("%d %d\n",an[i][0],an[i][1]);
    }
}