
#include<cstdio>
#include<cstring>
const unsigned long long mod=1000000000000ULL;const int ev=12;
int t,m;char s[10010];
struct B{int len;unsigned long long s[1010];}n,tmp,ans,aa,bb;
void pr(B&a)
{
    printf("%llu",a.s[a.len]);
    for(int i=a.len-1;i;i--)printf("%012llu",a.s[i]);
    puts("");
}
void getn()
{
    int len=strlen(s),i;
    for(i=0;i<=n.len;i++)n.s[i]=0;n.len=(len+ev-1)/ev;
    for(i=0;i<len;i++)n.s[(len+ev-1-i)/ev]=n.s[(len+ev-1-i)/ev]*10+s[i]-'0';
}
void inctmp()/*tmp++*/
{
    tmp.s[1]++;int i=1;
    while(tmp.s[i]>=mod)tmp.s[i]-=mod,tmp.s[i+1]++;
    if(tmp.s[tmp.len+1])tmp.len++;
}
void divn(int b)/*n>>=b*/
{
    int i;n.s[0]=0;unsigned long long aa=(1<<b)-1;
    for(i=n.len;i;i--)n.s[i-1]+=(n.s[i]&aa)*mod,n.s[i]>>=b;
    while(!n.s[n.len]&&n.len>1)n.len--;n.s[0]/=mod;
}
void divtmp()/*tmp/=2*/
{
    int i;tmp.s[0]=0;
    for(i=tmp.len;i;i--)tmp.s[i-1]+=(tmp.s[i]&1)*mod,tmp.s[i]>>=1;
    while(!tmp.s[tmp.len]&&tmp.len>1)tmp.len--;tmp.s[0]/=mod;
}
void plus()/*ans+=tmp*/
{
    if(ans.len<tmp.len)ans.len=tmp.len;int i;
    for(i=1;i<=ans.len;i++)ans.s[i]+=tmp.s[i],ans.s[i]>=mod?ans.s[i]-=mod,ans.s[i+1]++:1;
    if(ans.s[ans.len+1])ans.len++;
}
int main()
{
    int i;
    for (scanf("%d",&t);t --;)
    {
        scanf("%s%d", s, &m);
        for (getn(),divn(m - 1),i = 0;i <= ans.len;i ++) ans.s[i]=0;
        ans.len = 1;
        for(i = 0;tmp = n,inctmp(),divtmp(),!(tmp.len<=1&&tmp.s[1]==0);i++)plus(),divn(m);pr(ans);
    }
}
