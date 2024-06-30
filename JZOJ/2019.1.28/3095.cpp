#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const int N = 110;
int len,f[N][N],bz[N][N];
string ans[N][N]; char s[N];

int count(int x)
{
	int rest = 0;
	for(;x;x /= 10) ++rest;
	return rest;
}

string get(int x)
{
	string rest = "";
	for(;x;x /= 10) rest = char(x % 10 + '0') + rest;
	return rest;
}

int check(int L,int R,int l,int r)
{
	if((R - L + 1) % (r - l + 1)) return 0;
	for(int i = L;i <= R; ++ i)
		if(s[i] != s[(i - L) % (r - l + 1) + l]) return 0;
	return 1;
}
void solve(int l,int r)
{
	if(bz[l][r]) return;
	bz[l][r] = 1, f[l][r] = r - l + 1;
	if(l == r) { ans[l][r] = s[l]; return; }
	ans[l][r] = "";
	int fr=0;
	for(int i = l,x;i < r; ++ i)
	{
		solve(l,i), solve(i + 1,r);
		if(f[l][i] + f[i + 1][r] < f[l][r])
		{
			f[l][r] = f[l][i] + f[i + 1][r];
			fr=i;
			// ans[l][r] = ans[l][i] + ans[i + 1][r];
		}
		if(check(l,i,i + 1,r))
		{
			x = f[i + 1][r] + count((r - l + 1) / (r - i)) + 2;
			if(x < f[l][r]) f[l][r] = x,fr=-i;
				// ans[l][r] = ;
		}
	}
	if(fr==0)
		for(int i = l;i <= r; ++ i) ans[l][r] += s[i];
	else if(fr<0) ans[l][r]=get((r - l + 1) / (r - (-fr))) + '(' + ans[(-fr) + 1][r] + ')';
	else ans[l][r] = ans[l][fr] + ans[fr + 1][r];
}

int main()
{
	// freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf(" %s",s + 1);
	len = strlen(s + 1), solve(1,len);
	cout << ans[1][len] << endl;
	return 0;
}

