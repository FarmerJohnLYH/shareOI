//µãË« 
void dfs(ll x,ll f)
{
	dfn[x]=low[x]=++cnt;
	sta[++s0]=x;vis[x]=1;	
	for(ll tp=las[x];tp;tp=tp[nex])
	if(tp!=f)
	{
		ll tt=to[tp];
		if(!dfn[tt])
		{
			dfs(tt,tp^1);	
			low[x]=min(low[x],low[tt]);
			if(low[tt]==dfn[x])
			{
				ll mn=x,mx=x;
				while(sta[s0]!=x&&s0>0) 
				{
					mn=min(mn,sta[s0]),mx=max(mx,sta[s0]);
					sta[s0][vis]=0;
					--s0;
				}
				if(mn!=mx)
					ri[mn]=min(ri[mn],mx-1);
			}
			else if(low[tt]>dfn[x]) --s0;
		}else 
			if(vis[tt])low[x]=min(low[x],dfn[tt]);
	}
}


//强连通分量
void dfs(ll x)
{
	dfn[x]=++cnt,low[x]=cnt;
	st[++s0]=x;vis[x]=1;
	for(ll tp=las[x];tp;tp=tp[nex])
	{
		if(!dfn[to[tp]])
		{
			dfs(to[tp]);
			low[x]=min(low[x],low[to[tp]]);
		}
		else if(vis[to[tp]]) low[x]=min(low[x],dfn[to[tp]]);
	}
	if(low[x]==dfn[x])
	{
		while(st[s0]!=x) vis[st[s0]]=0,t[st[s0]]=x,--s0;
		--s0;t[x]=x;
		vis[x]=0;
	}
}