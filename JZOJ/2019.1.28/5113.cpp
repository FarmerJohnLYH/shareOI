#include <cstdio> 
#include <iostream> 
#include <cstring>
#define maxn 110
#define mo 1000000007ll
typedef long long ll;
typedef ll Expre[maxn];
typedef ll Mat[maxn][maxn];

using namespace std;
char s[500];
char t[20];
char vars[maxn][11];
ll mi[maxn];
Mat f[maxn];


ll point,tot,len,vtot;
void getName(char *name) {
    memset(name,0,11);
    ll lent=0;
    while (s[point]!=' ') 
        name[++lent]=s[point++];
}
ll getNum() {
    ll ret=0;
    while (s[point]!=' ') ret=ret*10+s[point++]-'0';
    return ret;
}
ll getVar(const char *name) {
    for (ll i=1; i<=vtot; i++) {
        ll suc=1;
        for (ll j=1; j<=10; j++) 
            if (name[j]!=vars[i][j]) {suc=0;break;}
        if (suc) return i;
    }
    return 0;
}
char t2[20];
void getExpre(Expre c) {
    for (; point<len;) {
        while (( s[point]==' ' || s[point]=='(' || s[point]==')' || s[point]=='+' || s[point]=='=') && point<len) point++;
        if (point==len) break;
        if (isdigit( s[point] )) c[0]=( c[0]+getNum() )%mo; else {
            getName(t2);
            ll k=getVar(t2);
            for (ll i=0; i<=vtot; i++) c[i]=(c[i]+f[tot][i][k])%mo;
        }
    }
}
void set(ll k,Expre ex) {
    for (ll i=0; i<=vtot; i++) f[tot][i][k]=ex[i];
}
Mat rez2;
void mult(const Mat a,const Mat b) {
    memset(rez2,0,sizeof rez2);
    for (ll i=0; i<=vtot; i++) 
        for (ll j=0; j<=vtot; j++) 
            for (ll z=0; z<=vtot; z++) {
                rez2[i][j]=(rez2[i][j]+a[i][z]*b[z][j])%mo;
            }
}
Mat rez;
void quickPower(const Mat a,ll y) {
    if (y==1) {
        memcpy(rez,a,sizeof rez);
        return;
    }
    quickPower(a,y/2);
    mult(rez,rez);
    memcpy(rez,rez2,sizeof rez);
    if (y&1==1) {
        mult(rez,a);
        memcpy(rez,rez2,sizeof rez);
    }
}
ll readStr() {
    memset(s,0,sizeof s);
    char c; point=0;
    while (scanf("%c",&c),c!='\n') s[++point]=c;
    len=point;
    return 0;
}
Expre e;
int main() {
    //freopen("cowbasic.in","r",stdin);
    freopen("cb.in","r",stdin);
    //freopen("cowbasic.out","w",stdout);
    tot=0;
    f[0][0][0]=1;
    while (readStr()==0) {
        point=1;
        while (s[point]==' ') point++;
        s[++len]=' ';
        if (s[point]=='R') {
            point+=7; getName(t);
            //printf("%d\n",getVar(t));
            printf("%d\n",f[tot][0][getVar(t)]);
            return 0;
        }
        if (s[point]>='a' && s[point]<='z') {
            getName(t);
            memset(e,0,sizeof e);  getExpre(e);
            ll k=getVar(t);
            if (k==0)  {
                //printf("%lld %s\n",vtot+1,t+1);
                memcpy(vars[++vtot],t,11);
                for (int i=0; i<tot; i++) f[i][vtot][vtot]=1;
                set(vtot,e);
            } else set(k,e);
            continue;
        }
        if (isdigit(s[point])) { //MOO BEGIN 
            mi[++tot]=getNum();
            memset(f[tot],0,sizeof f[tot]);
            for (ll i=0; i<=vtot; i++) f[tot][i][i]=1;
            continue;
        }
        if (s[point]=='}') { //MOO EN
            quickPower(f[tot],mi[tot]);
            memcpy(f[tot],rez,sizeof rez);
            mult(f[tot-1],f[tot]);
            memcpy(f[tot-1],rez2,sizeof f[tot-1]);
            tot--;
        }
    }
}