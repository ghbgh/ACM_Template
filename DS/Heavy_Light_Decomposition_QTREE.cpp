#include <bits/stdc++.h>
#include <ext/hash_map>
#include <ext/hash_set>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
#define XINF INT_MAX
#define INF 0x3F3F3F3F
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X,N) for(int X=0;X<N;X++)
#define REP2(X,L,R) for(int X=L;X<=R;X++)
#define DEP(X,R,L) for(int X=R;X>=L;X--)
#define CLR(A,X) memset(A,X,sizeof(A))
#define IT iterator
#define RIT reverse_iterator
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;
typedef tree<int, null_type, greater<int>, rb_tree_tag, tree_order_statistics_node_update > rb_tree_set;
typedef tree<int, int, greater<int>, rb_tree_tag, tree_order_statistics_node_update > rb_tree;
#define PQ std::priority_queue
#define HEAP __gnu_pbds::priority_queue
#define X first
#define Y second
#define lson(X) ((X)<<1)
#define rson(X) ((X)<<1|1)

#define MAXN 10010
VII Map[MAXN];
int vis[MAXN];
int fa[MAXN], dep[MAXN], sz[MAXN], son[MAXN], top[MAXN], w[MAXN];
int sgn[MAXN]; // 第i条边在线段树中位置 

int a[1<<14];
int b[1<<14]; // 线段树初值 
void dfs1(int u) {
	son[u]=-1;
	vis[u]=1;
	sz[u]=1;
	int mx = 0;
	REP(i,Map[u].size()) {
		int v=Map[u][i].X;
		if(!vis[v]) {
			dep[v]=dep[u]+1;
			dfs1(v);
			sz[u]+=sz[v];
			fa[v]=u;
			if(sz[v] > mx) {
				mx = sz[v];
				son[u] = v;
			}
		}
	}
}
int dfn;
void dfs2(int u) {
	if(son[u]!=-1) {
		top[son[u]] = top[u];
		w[son[u]]=dfn++;
		dfs2(son[u]);
	}
	REP(i,Map[u].size()) {
		int v=Map[u][i].X;
		int id=Map[u][i].Y;
		if(v!=fa[u]) {
			if(v!=son[u]) {
				top[v]=v;
				w[v]=dfn++;
				dfs2(v);
			}
			sgn[id]=w[v];
			b[w[v]]=a[id];
		}
	}
	
}

int c[1<<15];
int N;
void init(int n) {
	N=1;
	while(N<=n) N*=2;
	REP(i,N) {
		c[N+i] = b[i];
	}
	DEP(i,N-1,1) {
		c[i]=max(c[lson(i)], c[rson(i)]);
	}
}

void update(int t, int x) {
	t+=N;
	c[t]=x;
	while(t>>=1) {
		c[t]=max(c[lson(t)], c[rson(t)]);
	}
}

int query(int t, int L, int R, int l, int r) {
	l=max(l,L);
	r=min(r,R);
	if(l>r) return 0;
	if(l==L&&r==R) {
		return c[t];
	}
	int M=(L+R)>>1;
	return max(query(lson(t),L,M,l,r), query(rson(t),M+1,R,l,r));
}

int Scan()
{
	int res=0, ch;
	while(ch=getchar(), ch<'0'||ch>'9');
	res=ch-'0';
	while((ch=getchar())>='0'&&ch<='9')
		res=res*10+ch-'0';
	return res;
}
void Out(int a)
{
    if(a>9)
        Out(a/10);
    putchar(a%10+'0');
}

char s[20];

int main()
{
    int t,n,u,v;
	t=Scan();
	while(t--) {
		n=Scan();
		REP(i,n) Map[i].clear();
		REP(i,n-1) {
			u=Scan();
			v=Scan();
			a[i]=Scan();
			u--; v--;
			Map[u].PB(MP(v,i));
			Map[v].PB(MP(u,i));
		}
		CLR(vis,0);
		dfn=0;
		dfs1(0);
		dfs2(0);
		init(n-1);
		while(scanf("%s",&s) && s[0]!='D') {
			u=Scan();
			v=Scan();
			if(s[0]=='Q') {
				u--; v--;
				int ans = 0;
				while(top[u]!=top[v]) {
					if(dep[top[u]]<dep[top[v]]) swap(u,v);
					int q = query(1,0,N-1,w[top[u]],w[u]);
					ans = max(ans, q);
					u=fa[top[u]];
				}
				if(u!=v) {
					if(dep[u]>dep[v]) swap(u,v);
					int q = query(1,0,N-1,w[son[u]],w[v]);
					ans = max(ans, q);
				}
				Out(ans);
				putchar('\n');
			}else if(s[0]=='C') {
				update(sgn[u-1],v);
			}
		}
	}
    return 0;
}


