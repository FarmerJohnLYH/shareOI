#pragma GCC optimize(2)
#include <ctime>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define fd(i,x,y) for (int i=(x);i>=(y);--i)
#define oo 2139062143
using namespace std;
typedef long long ll;
typedef double db;
const int N=501000,C=27;
int T,n;
int ans;
char dic[55],str[1100000];
struct AcAutoMation{
    int d[N];
    int chd[N][C];
    int ot[N];
    int fail[N],next[N],last[N];
    int bz[N];
	int sz;
    void del(int x)
    {
    	next[last[x]]=next[x],last[next[x]]=last[x];
    	bz[x]=1;
	}
    void init()
    {
    	memset(bz,0,sizeof bz);
        memset(chd[0],0,sizeof chd[0]);
        memset(ot,0,sizeof ot);
        memset(fail,0,sizeof fail);
        sz=0;
    }
    void insert(char *p)
    {
        int tmp=0;
        int len=strlen(p+1);
        fo(i,1,len)
        {
            int now=p[i]-'a';
            if(!chd[tmp][now])
            {	
                chd[tmp][now]=++sz;
                memset(chd[sz],0,sizeof(chd[sz]));  
			}
            tmp=chd[tmp][now];
        }
        ++ot[tmp];
    }
    void Getfail()
    {
        int tmp=0;
        int hd=0,tl=0;
        fo(i,0,25)
        {
            if(chd[0][i]) 
            {
                d[++tl]=chd[0][i];
                fail[chd[0][i]]=0;    
            }
        }
        while(hd++<tl)
        {
            tmp=d[hd];
            fo(i,0,25)
            if(chd[tmp][i])
            {
                d[++tl]=chd[tmp][i];
                int to=fail[tmp];
                while(to!=0&&!chd[to][i]) to=fail[to];
                fail[chd[tmp][i]]=chd[to][i];
//				next[chd[tmp][i]]=fail[chd[tmp][i]];
                next[chd[tmp][i]]=(ot[fail[chd[tmp][i]]])?(fail[chd[tmp][i]]):(next[fail[chd[tmp][i]]]);
                last[next[chd[tmp][i]]]=chd[tmp][i];
			}
        }
    }
    void solve(char *p)
    {
    	int tmp=0;
        int len=strlen(p+1);
        fo(i,1,len)
        {
            int now=p[i]-'a',to=tmp;
            while(!chd[to][now]&&to) to=fail[to];
            tmp=chd[to][now];
            if(ot[tmp]) ans+=ot[tmp],ot[tmp]=0,del(tmp);
			for (int pp=fail[tmp];pp;pp=next[pp])
		    {
				if(ot[pp])
		 		{ 
		            ans+=ot[pp],ot[pp]=0;            
		        }
				if(!bz[pp]&&!ot[pp]) del(pp);	
			}    
		}
    }
}ac;
int main()
{
	freopen("D:/LiuYuanHao/a.in","r",stdin);
	int TT=clock();
    scanf("%d\n",&T);
    while(T--)
    {
        ac.init();
        scanf("%d\n",&n);
        fo(i,1,n)
        {
            scanf("%s\n",dic+1);    
            ac.insert(dic);
        }
        ac.Getfail();
        ans=0;
        scanf("%s\n",str+1);
        ac.solve(str);
        printf("%d\n",ans);
    }
    return 0;
}

