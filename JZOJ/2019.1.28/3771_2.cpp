#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cassert>   // assert  
#include <string>    // string类  
#include <vector>    // vector类  
#define oo 2139062143
#define sqr(x) ((x)*(x))
#define lowbit(x) ((x)&(-x))
#define abs(x) (((x)>=0)?(x):(-(x)))
#define max(x,y) (((x)>(y))?(x):(y))
#define min(x,y) (((x)<(y))?(x):(y))
#define fo(i,x,y) for (int i = (x);i <= (y);++ i)
#define fd(i,x,y) for (int i = (x);i >= (y);-- i)
using namespace std;
typedef double db;
typedef long long ll;
const int M = 33;
int m;
struct bign {  
    typedef unsigned long long ULL;  

    static const int BASE = 100000000;  
    static const int WIDTH = 8;  
    static const int TOTDIT = 10100;//最多总共10000位 
    vector<int> s;  

    void write() {
        printf("%d", s.back());
        for (int i = s.size() - 2;i >= 0;-- i)
        {
            char buf[WIDTH + 2];
            sprintf(buf,"%08d", s[i]);
            for (int j = 0;j < strlen(buf);++ j) printf("%c", buf[j]);
        }
    }
    void read() {
        char buf[TOTDIT];//位数 最高位
        scanf("%s", buf + 1);
        s.clear();
        int len = (strlen(buf + 1) - 1) / WIDTH + 1;
        int num = 0,tmp = 0;
        for (int i = len - 1;i >= 1;-- i)
        {
            int en = strlen(buf + 1) - tmp,st = en - WIDTH + 1;
            tmp += WIDTH;
            num = 0;
            for (int i = st;i <= en;++ i)
                num = num * 10 + buf[i] - '0';  
            s.push_back(num);
        }  
        if (strlen(buf + 1) - tmp > 0)
        {
            num = 0;
            int en = strlen(buf + 1) - tmp,st = 1;
            for (int i = st;i <= en;++ i)
                num = num * 10 + buf[i] - '0';  
            s.push_back(num);
        } 
    }

    bign& clean(){while(!s.back()&&s.size()>1)s.pop_back(); return *this;}  
    bign(ULL num = 0) {*this = num;}  
    bign(string s) {*this = s;}  
    bign& operator = (long long num) {  
        s.clear();  
        do {  
            s.push_back(num % BASE);  
            num /= BASE;  
        } while (num > 0);  
        return *this;  
    }  
    bign& operator = (const string& str) {  
        s.clear();  
        int x, len = (str.length() - 1) / WIDTH + 1;  
        for (int i = 0; i < len; i++) {  
            int end = str.length() - i*WIDTH;  
            int start = max(0, end - WIDTH);  
            sscanf(str.substr(start,end-start).c_str(), "%d", &x);  
            s.push_back(x);  
        }  
        return (*this).clean();  
    }  
    bign operator + (const bign& b) const {  
        bign c; c.s.clear();  
        for (int i = 0, g = 0; ; i++) {  
            if (g == 0 && i >= s.size() && i >= b.s.size()) break;  
            int x = g;  
            if (i < s.size()) x += s[i];  
            if (i < b.s.size()) x += b.s[i];  
            c.s.push_back(x % BASE);  
            g = x / BASE;  
        }  
        return c;  
    }  
    bign operator - (const bign& b) const {  
        assert(b <= *this); // 减数不能大于被减数  
        bign c; c.s.clear();  
        for (int i = 0, g = 0; ; i++) {  
            if (g == 0 && i >= s.size() && i >= b.s.size()) break;  
            int x = s[i] + g;  
            if (i < b.s.size()) x -= b.s[i];  
            if (x < 0) {g = -1; x += BASE;} else g = 0;  
            c.s.push_back(x);  
        }  
        return c.clean();  
    }  
    bign operator * (const bign& b) const {  
        int i, j; ULL g;  
        vector<ULL> v(s.size()+b.s.size(), 0);  
        bign c; c.s.clear();  
        for(i=0;i<s.size();i++) for(j=0;j<b.s.size();j++) v[i+j]+=ULL(s[i])*b.s[j];  
        for (i = 0, g = 0; ; i++) {  
            if (g ==0 && i >= v.size()) break;  
            ULL x = v[i] + g;  
            c.s.push_back(x % BASE);  
            g = x / BASE;  
        }  
        return c.clean();  
    }  
    bign operator / (const bign& b) const {  
        assert(b > 0);  // 除数必须大于0  
        bign c = *this;       // 商:主要是让c.s和(*this).s的vector一样大  
        bign m;               // 余数:初始化为0  
        for (int i = s.size()-1; i >= 0; i--) {  
            m = m*BASE + s[i];  
            c.s[i] = bsearch(b, m);  
            m -= b*c.s[i];  
            }  
        return c.clean();  
    }  
    bign operator % (const bign& b) const { //方法与除法相同  
        bign c = *this;  
        bign m;  
        for (int i = s.size()-1; i >= 0; i--) {  
            m = m*BASE + s[i];  
            c.s[i] = bsearch(b, m);  
            m -= b*c.s[i];  
        }  
        return m;  
    }  
    // 二分法找出满足bx<=m的最大的x  
    int bsearch(const bign& b, const bign& m) const{  
        int L = 0, R = BASE-1, x;  
        while (1) {  
            x = (L+R)>>1;  
            if (b*x<=m) {if (b*(x+1)>m) return x; else L = x;}  
            else R = x;  
        }  
    }  
    bign& operator += (const bign& b) {*this = *this + b; return *this;}  
    bign& operator -= (const bign& b) {*this = *this - b; return *this;}  
    bign& operator *= (const bign& b) {*this = *this * b; return *this;}  
    bign& operator /= (const bign& b) {*this = *this / b; return *this;}  
    bign& operator %= (const bign& b) {*this = *this % b; return *this;}  

    bool operator < (const bign& b) const {  
        if (s.size() != b.s.size()) return s.size() < b.s.size();  
        for (int i = s.size()-1; i >= 0; i--)  
            if (s[i] != b.s[i]) return s[i] < b.s[i];  
        return false;  
    }  
    bool operator >(const bign& b) const{return b < *this;}  
    bool operator<=(const bign& b) const{return !(b < *this);}  
    bool operator>=(const bign& b) const{return !(*this < b);}  
    bool operator!=(const bign& b) const{return b < *this || *this < b;}  
    bool operator==(const bign& b) const{return !(b < *this) && !(b > *this);}  
}n,k,tw,ans,tmp; 
int main()
{
    freopen("D:/LiuYuanHao/c.in","r",stdin);
    int T;
    scanf("%d", &T);
    while (T --)
    {
        n.read();
        scanf("%d", &m);
        k = (m - 1),tw = 2;
        n /= k,ans = 0;
        tmp = n;
        for (;tmp = n,tmp += 1,tmp /= 2,(tmp > 0);) ans += tmp,n /= k;
        // for(i = 0;tmp = n,inctmp(),divtmp(),!(tmp.len<=1&&tmp.s[1]==0);i++)plus(),divn(m);pr(ans);
        ans.write();
    }
}





