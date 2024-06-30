#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
const int N=50050,M=27+10;
int n,a[M],b[M],t[M];
char s[N];
int check(int c,int n)
{
	--a[c];
	fo(i,0,25)
		if(a[i]+b[i]>n) 
		{
			++a[c];
			return 0;
		}
	return 1;
}
int main()
{
	freopen("D:/LiuYuanHao/a1.in","r",stdin);
	scanf("%s",s+1);n=strlen(s+1);
	int cnt=0;
	fo(i,1,n)
	{
		++t[s[i]-'a'];
		if(t[s[i]-'a']==1) ++cnt;
	}
	fo(i,0,25) a[i]=b[i]=t[i];
	if(cnt==1) return 0;
	if(cnt==2) 
	{
		int p=0;
		fo(i,0,25) if(p) p-=t[i];else p+=t[i];
		if(p) return 0;
		fo(i,1,n) 
		{
			fo(j,0,25)
			 if(t[j] && j+'a'!=s[i]) putchar(j+'a');
		}
		return 0;
	}
	fo(i,1,n)
	{
		int flag=0;
		--b[s[i]-'a'];
		fo(j,0,25) if(s[i]-'a'!=j && a[j] && check(j,n-i))
		{
			putchar(j+'a'),flag=1;
			break;
		}
		if(!flag) 
			return 0;
	}
	return 0;
}








