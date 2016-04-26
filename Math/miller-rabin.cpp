ll mul(ll a, ll b, ll m) {
	ll ret = a * (b & 0x1fff) % m;
	(ret += ((a <<= 13) %= m) * ((b >>= 13) & 0x1fff)) %= m;
	(ret += ((a <<= 13) %= m) * ((b >>= 13) & 0x1fff)) %= m;
	(ret += ((a <<= 13) %= m) * ((b >>= 13) & 0x1fff)) %= m;
	return ret;
}

ll power(ll a, ll e, ll m) {
	ll y = 1;
	for(; e; e >>= 1, a = mul(a, a, m)) if(e & 1) y = mul(y, a, m);
	return y;
}

// n < 341550071728321 < 2^49
ll MillerRabin[] = {2, 3, 5, 7, 11, 13, 17, -1};
bool isPrime(ll n) {
	if (n <= 1 || n % 2 == 0) return (n == 2);
	int r, s = 0;
	ll d, *a, ad;
	for(d = n - 1; d % 2 == 0; d >>= 1, ++s);
	for(a = MillerRabin; ~*a && *a < n; ++a) {
		ad = power(*a, d, n);
		if(ad == 1) continue;
		REP(r, s) {
			if(ad == n-1) break;
			ad = mul(ad, ad, n);
		}
		if(r == s) return 0;
	}
	return 1;
}
