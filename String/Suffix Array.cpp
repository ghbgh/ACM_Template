#include <bits/stdc++.h>
using namespace std;
#define REP(X,N) for(int X=0;X<(N);X++)
#define DEP(X,R,L) for(int X=R;X>=L;X--)
#define REP2(X,L,R) for(int X=L;X<=R;X++)

#define MAXN 100000

int wa[MAXN], wb[MAXN], wv[MAXN], ww[MAXN];
int cmp(int *r, int a, int b, int l) {
    return r[a]==r[b]&&r[a+l]==r[b+l];
}
void da(int *r, int *sa, int n, int m) {
    int j,k,p,*x=wa,*y=wb,*t;
    REP(i,m) ww[i]=0;
    REP(i,n) ww[x[i]=r[i]]++;
    REP(i,m-1) ww[i+1]+=ww[i];
    DEP(i,n-1,0) sa[--ww[x[i]]]=i;
    for(j=1,p=1;p<n;j*=2,m=p) {
        for(p=0,k=n-j;k<n;k++) y[p++]=k;
        REP(i,n) if(sa[i]>=j) y[p++]=sa[i]-j;
        REP(i,n) wv[i]=x[y[i]];
        REP(i,m) ww[i]=0;
        REP(i,n) ww[wv[i]]++;
        REP(i,m-1) ww[i+1]+=ww[i];
        DEP(i,n-1,0) sa[--ww[wv[i]]]=y[i];
        for(t=x,x=y,y=t,p=1,x[sa[0]]=0,k=1;k<n;k++)
            x[sa[k]]=cmp(y,sa[k-1],sa[k],j)?p-1:p++;
    }
}

#define F(x) ((x)/3+((x)%3==1?0:tb))
#define G(x) ((x)<tb?(x)*3+1:((x)-tb)*3+2)
//int wa[MAXN],wb[MAXN],wv[MAXN],ww[MAXN];
int c0(int *r, int a, int b) {
    return r[a]==r[b]&&r[a+1]==r[b+1]&&r[a+2]==r[b+2];
}
int c12(int k, int *r, int a, int b)
{
    if(k==2) return r[a]<r[b]||r[a]==r[b]&&c12(1,r,a+1,b+1);
    else return r[a]<r[b]||r[a]==r[b]&&wv[a+1]<wv[b+1];
}
void rsort(int *r, int *a, int *b, int n, int m) {
    REP(i,n) wv[i]=r[a[i]];
    REP(i,m) ww[i]=0;
    REP(i,n) ww[wv[i]]++;
    REP(i,m-1) ww[i+1]+=ww[i];
    DEP(i,n-1,0) b[--ww[wv[i]]]=a[i];
}

void dc3(int *r, int *sa, int n, int m) {
    int j,*rn=r+n,*san=sa+n,ta=0,tb=(n+1)/3,tbc=0,p;
    r[n]=r[n+1]=0;
    REP(i,n) if(i%3!=0) wa[tbc++]=i;
    rsort(r+2,wa,wb,tbc,m);
    rsort(r+1,wb,wa,tbc,m);
    rsort(r,wa,wb,tbc,m);
    for(p=1,rn[F(wb[0])]=0,j=1;j<tbc;j++)
        rn[F(wb[j])]=c0(r,wb[j-1],wb[j])?p-1:p++;
    if(p<tbc) dc3(rn,san,tbc,p);
    else REP(i,tbc) san[rn[i]]=i;
    REP(i,tbc) if(san[i]<tb) wb[ta++]=san[i]*3;
    if(n%3==1) wb[ta++]=n-1;
    rsort(r,wb,wa,ta,m);
    REP(i,tbc) wv[wb[i]=G(san[i])]=i;
    int i;
    for(i=j=p=0;i<ta&&j<tbc;p++)
        sa[p]=c12(wb[j]%3,r,wa[i],wb[j])?wa[i++]:wb[j++];
    for(;i<ta;p++) sa[p]=wa[i++];
    for(;j<tbc;p++) sa[p]=wb[j++];
}

int ra[MAXN], height[MAXN];
void calheight(int *r,int *sa,int n) {
    int i,j,k=0;
    for(i=1;i<=n;i++) ra[sa[i]]=i;
    for(i=0;i<n;height[ra[i++]]=k)
        for(k?k--:0,j=sa[ra[i]-1];r[i+k]==r[j+k];k++);
}

int str[MAXN];
int sa[MAXN];

int main()
{
    ios::sync_with_stdio(false);
    string s="aabaaaabaaa";
    REP(i,s.length()) {
        str[i]=s[i];
    }
    dc3(str, sa, s.length(), 255);
    calheight(str, sa, s.length());
    REP(i,s.length()) {
        cout<<s[i]<<' ';
    }
    cout<<endl;
    REP(i,s.length()) {
        cout<<sa[i]<<' ';
    }
    cout<<endl;
    REP(i,s.length()) {
        cout<<height[i]<<' ';
    }
    cout<<endl;
    da(str, sa, s.length(), 255);
    calheight(str, sa, s.length());
    REP(i,s.length()) {
        cout<<s[i]<<' ';
    }
    cout<<endl;
    REP(i,s.length()) {
        cout<<sa[i]<<' ';
    }
    cout<<endl;
    REP(i,s.length()) {
        cout<<height[i]<<' ';
    }
    cout<<endl;
    
    return 0;
}
