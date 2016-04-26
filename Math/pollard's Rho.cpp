ll mul(ll a, ll b, ll m) {
	ll ret = a * (b & 0x1fff) % m;
	(ret += ((a <<= 13) %= m) * ((b >>= 13) & 0x1fff)) %= m;
	(ret += ((a <<= 13) %= m) * ((b >>= 13) & 0x1fff)) %= m;
	(ret += ((a <<= 13) %= m) * ((b >>= 13) & 0x1fff)) %= m;
	return ret;
}

ll pollard(ll n) {
	if(n % 2 == 0) return 2;
	ll x, y, d, c;
	for(c = 1; ;++c) {
		for(x = y = 2, d = 1; d == 1; d = __gcd(abs(x - y), n)) {
			x = mul(x, x, n) + c;
			y = mul(y, y, n) + c;
			y = mul(y, y, n) + c;
		}
		if(d < n) return d;
	}
}
