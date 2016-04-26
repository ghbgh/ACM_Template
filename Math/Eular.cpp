/**********************************
	欧拉筛法	求素数表 & phi(i)
	2014.3.1
**********************************/


#define MAXN 1000000
int vis[MAXN]={1,1}, phi[MAXN];
int prime[MAXN], n_prime;
void Eular() {
	n_prime=0;
	phi[1]=1;
	for(int i = 2; i < MAXN; i++) {
		if(!vis[i]) {
			prime[n_prime++] = i;
			phi[i] = i-1;
		}
		for(int j = 0; j < n_prime && i * prime[j] < MAXN; j++) {
			vis[i * prime[j]] = 1;
			if(i % prime[j] == 0) {
				phi[i * prime[j]] = phi[i] * prime[j];
				break;
			}else
				phi[i * prime[j]] = phi[i] * phi[prime[j]];
		}
	}
}
