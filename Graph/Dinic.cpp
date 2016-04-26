/**********************************
	网络流 Dinic (hdu 1532) 
	邻接表 可包含重边
	2014.5.18
**********************************/

#define INF 0x3FFFFFFF
#define REP(X,N) for(int X=0;X<N;X++)
#define REP2(X,L,R) for(int X=L;X<=R;X++)
#define CLR(A,X) memset(A,X,sizeof(A))

#define MAXN 200
#define MAXE 200 * 2

int head[MAXN];
int last[MAXN];
int _next[MAXE];
int to[MAXE];
int cap[MAXE];
int flow[MAXE];

int n_edge;

void init()
{
	n_edge = 0;
	CLR(head,-1);
	CLR(_next,-1);
}

void addEdge(int u, int v, int c, int f)
{
	if(head[u] == -1)
		head[u] = n_edge;
	else
		_next[last[u]] = n_edge;
	to[n_edge] = v;
	cap[n_edge] = c;
	flow[n_edge] = f;
	last[u] = n_edge++;
}

void addArc(int u, int v, int c, int f)
{
	addEdge(u, v, c, f);
	addEdge(v, u, 0, -f);
}

int lev[MAXN];
int que[MAXN];
int bfs(int s, int t)
{
	CLR(lev,-1);
	que[0] = s;
	lev[s] = 1;
	int r = 0, f = 1;
	for(;r<f; r++)
	{
		int u = que[r];
		for(int e = head[u]; e != -1; e = _next[e])
		{
			int v = to[e];
			if(cap[e]==flow[e]) continue; // if is full
			if(lev[v] == -1)
			{
				lev[v] = lev[u]+1;
				que[f++] = v;
			}
		}
	}
	return lev[t]!=-1;
}

int vis[MAXN];
int dinic(int s, int t)
{
	ll sumflow = 0;
	
	while(bfs(s, t))
	{
		CLR(vis,0);
		vis[s]=1;
		int p=0;
		int stk[MAXN];
		stk[p++]=-1;
		while(p)
		{
			int u=p==1?s:to[stk[p-1]];
			if(u==t)
			{
				int f=INF;
				REP2(i,1,p-1)
				{
					int e=stk[i];
					f=min(f,cap[e]-flow[e]);
					vis[to[e]]=0;
				}
				sumflow+=f;
				int back=0;
				REP2(i,1,p-1)
				{
					int e=stk[i];
					flow[e]+=f;
					flow[e^1]-=f;
					if(flow[e]==cap[e] && !back)
						back=i;
					if(!back) vis[to[e]]=1;
				}
				p=back;
			}else{
				int f=0;
				for(int e = head[u]; e != -1; e = _next[e])
				{
					int v = to[e];
					if(lev[v]==lev[u]+1 && flow[e]<cap[e] && !vis[v])
					{
						stk[p++]=e;
						vis[v]=1;
						f=1;
						break;
					}
				}
				if(!f)
				{
					lev[u]=-1;
					p--;
				}
			}
		}
	}
	return sumflow;
}

int main()
{
	ios::sync_with_stdio(false);
	int n,m,u,v,f;
	while(cin>>n>>m)
	{
		init();
		REP(i,n)
		{
			cin>>u>>v>>f;
			u--; v--;
			addArc(u, v, f, 0);
		}
		cout<<dinic(0,m-1)<<endl;
	}
	return 0;
}


