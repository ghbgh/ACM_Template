
ll ex_gcd(ll a,ll b,ll &x,ll &y){  
    if (a==0&&b==0) return -1;  
    if (b==0){x=1;y=0;return a;}  
    ll d=ex_gcd(b,a%b,y,x);
    y-=a/b*x;
    return d;
}

ll inv(ll a,ll n){  
    ll x,y;  
    ll d = ex_gcd(a,n,x,y);  
    return (x%n+n)%n;  
}

