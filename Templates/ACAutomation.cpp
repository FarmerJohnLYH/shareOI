//HDU2222  
#include <queue>    
#include <cstdio> 
#include <cstring>
#include <iostream> 
#include <algorithm>
using namespace std;  
const int N=500500;  
struct ACautomachine
{  
    int chd[N][26];//孩子节点编号
    int cnt[N];//当前结点 表示字符串个数
    int fail[N];//失配指针
    int last[N],sz,ans;//题目需要  
    void init()  
    {  
        sz=1,ans=0;  
        memset(cnt,0,sizeof(cnt));  
        memset(fail,0,sizeof(fail));  
        memset(chd[0],0,sizeof(chd[0]));  
    }  
    void insert(char* p)//构建trie  
    {  
        int cur=0;  
        for(;*p;p++)  
        {  
            if(!chd[cur][*p-'a'])  
            {  
                memset(chd[sz],0,sizeof(chd[sz]));  
                chd[cur][*p-'a']=sz++;  
            }  
            cur=chd[cur][*p-'a'];  
        }  
        cnt[cur]++;  
    }  
    bool query(char* p)//题目需要
    {  
        int cur=0;  
        for(;*p;p++)  
        {  
            if(!chd[cur][*p-'a']) break;  
            cur=chd[cur][*p-'a'];  
        }  
        return cnt[cur]&&(!(*p));  
    }  
    int getFail()  
    {  
        queue<int> q;  
        fail[0]=0;  
        for(int c=0;c<26;c++)  
        {  
            int u=chd[0][c];  
            if(u)  
            {  
                fail[u]=0/*Null*/;
                q.push(u); 
                last[u]=0;  
            }  
        }  
        while(!q.empty())  
        {  
            int r=q.front();
            q.pop();
            for(int c=0;c<26;c++)  
            {  
                int u=chd[r][c];  
                if(!u)
                {
                	//直接指向 fail 
                	//也就是 把 trie树 的 chd[fail[r]][c]及其子孙 全部 “复制” 作r点的子孙
                	chd[r][c]=chd[fail[r]][c];
                	continue;
                }
                q.push(u);  
                int v=fail[r]; 
                while(v&&!chd[v][c]) v=fail[v];
                //1. 令指针为 fail[fa[u]]
                //2. 若指针的一级儿子中存在一点（代表字符）与 u 相同 
                //  则令fail[u] 指向 当前指针的该儿子
                //3. 否则 指针指向 fail[指针] 并重复 2 操作、

                //目的：使得当前点及其到根的路径（即一个字典串） 与 fail 和fail[fail]... 所代表字典串 后缀相同
                // 从而实现重新匹配

                fail[u]=chd[v][c];  
                last[u]=cnt[fail[u]] ? fail[u] : last[fail[u]];  
            }  
        }  
    }  
    void solve(int j)  //题目需要
    {  
        if(!j) return;  
        if(cnt[j])  
        {  
            ans+=cnt[j];  
            cnt[j]=0;  
        }  
        solve(last[j]);  
    }  
    void find(char* T)  //题目需要
    {  
        int n=strlen(T),j=0;  
        getFail();  
        for(int i=0;i<n;i++)  
        {  
            j=chd[j][T[i]-'a'];  
            if(cnt[j]) solve(j);  
            else if(last[j]) solve(last[j]);  
        }  
    }  
}ac;  
  
int main()  
{  
	freopen("D:/LiuYuanHao/a.in","r",stdin);
    int t,n;  
    char dic[100],str[1100000];  
    scanf("%d",&t);  
    while(t--)  
    {  
        ac.init();  
        scanf("%d",&n);  
        while(n--)  
        {  
            scanf("%s",dic);  
            ac.insert(dic);  
        }  
        scanf("%s",str);  
        ac.find(str);  
        printf("%d\n",ac.ans);  
    }  
    return 0;  
}  
