#include <bitset>
#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define fd(i,x,y) for (int i=(x);i>=(y);--i)
using namespace std;
const int N=2020,LN=2002000,M=100100;
int read(int *s)
{
	char c=getchar();
	while(!(c>='a'&&c<='z')) c=getchar();
	int p=1;
	s[1]=c;c=getchar();
	while(c>='a'&&c<='z') s[++p]=c-'a',c=getchar();
	s[p+1]=-1;
	return p;
}
struct trie{
	int son[LN][2],cnt,ct[LN],f[LN],fa[LN];
	int en[N];
	bitset<2020> a[N*2];
	int insert(int x,int y)
	{
		if(!son[x][y]) son[x][y]=++cnt;
		fa[son[x][y]]=x,x=son[x][y];
		return(x);
	}
	int d[LN];
	void init()
	{
		int hd=0,tl=1;d[1]=1;
		while(hd++<tl)
		{
			int now=d[hd];
			fo(i,0,25) 
			if(son[now][i]) 
			{
				d[++tl]=son[now][i];
				++siz[now];
			}		
		}
		fo(i,1,tl) 
		{
			if(i==1||siz[fa[i]]>1||ct[fa[i]]) f[i]=++cnt;
			else num[i]=num[fa[i]];
		}
		fo(i,1,n) a[]	
	}
	void Tu() {
		d[0] = d[1] = 1;
		fo(i, 1, d[0]) {
			int x = d[i];
			fo(j, 0, 25) if(son[x][j])
				d[++ d[0]] = son[x][j], fa[son[x][j]] = x;
		}
		fo(i, 1, tot) fo(j, 0, 25) siz[i] += son[i][j] > 0;
		fo(i, 1, tot) {
			if(i == 1 || siz[fa[i]] > 1 || ct[fa[i]]) {
				num[i] = ++ tn;
			} else num[i] = num[fa[i]];
		}
		fo(i, 1, n) a[num[ed[i]]][i] = 1;
		fd(i, d[0], 1) if(num[fa[d[i]]] != num[d[i]])
			a[num[fa[d[i]]]] |= a[num[d[i]]];
	}
}t1,t2;
int ans;
int main()
{
	freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%d\n",&n);
	t1.cnt=t2.cnt=1;
	fo(i,1,n) 
	{
		len=read(st);int x=1;
		fo(j,1,len) x=t1.insert(x,st[j]);++t1[t1[i].en=x].ct;x=1;
		fd(j,len,1) x=t2.insert(x,st[j]);++t2[t2[i].en=x].ct;x=1;
	}
	t1.cnt=t2.cnt=0;
	t1.init(),t2.init();
	scanf("%d\n",&m);
	while(m--)
	{
		len=read(st);
		int x=1,y=1;
		fo(i,1,len) 
		{
			st[i]=(st[i]-'a'+ans)%26;
			if(t1.son[x][st[i]]) x=t1.son[x][st[i]];
			else 
			{
				x=0;
				break;
			}
		}
		fd(i,len,1)
		{
			if(t2.son[y][st[i]]) y=t2.son[y][st[i]];
			else
			{
				y=0;
				break;
			}
		}
		if(!x||!y) ans=0; else ans=(t1.a[x]&t2.a[y]).count();
		printf("%d\n",ans);
	}
	fo(i,1,m)
	return 0;
}











