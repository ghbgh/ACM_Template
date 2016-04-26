VI Map[MAXN], rMap[MAXN], vex;
int sgn[MAXN], scc;
void dfs(int u) {
	sgn[u] = 1;
	REP(i,Map[u].size()) {
		int v = Map[u][i];
		if(!sgn[v]) dfs(v);
	}
	vex.PB(v);
}
void rdfs(int u) {
	sgn[u] = scc;
	REP(i,rMap[u].size()) {
		int v = rMap[u][i];
		if(!sgn[v]) rdfs(v);
	}
}
void kosaraju() {
	CLR(sgn, 0);
	vex.clear();
	REP(i,n) if(!sgn[i]) dfs(i);
	CLR(sgn, 0);
	reverse(vex.begin(), vex.end());
	REP(i,vex.size()) if(!sgn[vex[i]]) {
		scc++;
		rdfs(vex[i]);
	}
}
