vector<pair<int> > Map[MAXN];
vector<pair<PII> > bri;
int low[MAXN], dfn[MAXN], cut[MAXN];
int dep;
void tarjan(int u, int fa=-1)
{
	low[u] = dfn[u] = dep++;
	for(auto it = Map[u].begin(); it != Map[u].end(); it++)
	{
		int v = it->X;
		if(v==fa) continue;
		int son = 0;
		if(dfn[v] == -1)
		{
			tarjan(v, u);
			son++;
			low[u] = min(low[u], low[v]);
			//cut point
			if((fa<0 && son>1) || (fa >=0&&low[v]>=dfn[v])) cut[u]=1;
			//bridge
			if(low[v] > dfn[u])
				bri.push_back(make_pair(u,v));
		}else{
			low[u] = min(low[u], dfn[v]);
		}
	}
}