/**********************************
	并查集模板 
	2014.3.18
**********************************/

int pa[MAXN], ra[MAXN];
void init(int n) {
	REP(i,n)  {
		pa[i] = i;
		ra[i] = 0;
	}
}
int find(int x) {
	if(pa[x]!=x) pa[x] = find(pa[x]);
	return pa[x];
}
// 0: already united;  1: successfully united;
int unite(int x, int y) {
	x = find(x);
	y = find(y);
	if(x==y) return 0;
	if(ra[x] < ra[y]) {
		pa[x] = y;
	}else{
		pa[y] = x;
		if(ra[x] == ra[y]) ra[x]++;
	}
	return 1;
}

