typedef pair<int,int> P;

ll operator*(P a, P b) {
	return a.X * b.Y - a.Y * b.X;
}

bool cmp(P a, P b) {
	if(a.X != b.X) return a.X < b.X;
	return a.Y < b.Y;
}

vector<P> convex_hull(P* ps, int n) {
	sort(ps, ps+n, cmp);
	int k = 0;
	vector<P> qs(n*2);
	REP(i,n) {
		while(k > 1 && (qs[k-1] - qs[k-2]) * (ps[i] - qs[k-1]) <= 0) k--;
		qs[k++] = ps[i];
	}
	for(int i = n-2, t = k; i >= 0; i--) {
		while(k > t && (qs[k-1] - qs[k-2]) * (ps[i] - qs[k-1]) <= 0) k--;
		qs[k++] = ps[i];
	}
	qs.resize(k-1);
	return qs;
}
