ll exgcd(ll a, ll b, ll &x, ll &y) {
    if(b==0) {
        x=1;y=0;
        return a;
    }else{
        ll r=exgcd(b,a%b,y,x);
        y-=x*(a/b);
        return r;
    }
}

ll CRT(ll a[], ll m[], int n) {
    ll M=1;
    REP(i,n) M*=m[i];
    ll ret = 0;
    REP(i,n) {
        ll x,y;
        ll tm=M/m[i];
        exgcd(tm,m[i],x,y);
        ret=(ret+tm*x*a[i])%M;
    }
    return (ret+M)%M;
}
