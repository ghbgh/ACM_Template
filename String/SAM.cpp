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

// suffix automaton
// http://wenku.baidu.com/link?url=YTgnZQuEcG3vVk0H6oHaYAnJI86PfElIPlyMBUIl9_3Z4PCzRWykb1SY9a992dKFW2kbHZtbUqIcx2fTEdNa3_WSK4mxnFj8_iJajgTGRcW

struct State {
	State *par, *go[26];
	int val;
	State(){};
	State(int _val) : par(NULL), val(_val) {
		memset(go,0,sizeof(go));
	}
}* root, * last, buffer[200000];
int p;
State* newState(int val) {
	return &(buffer[p++] = State(val));
}

void init() {
	p = 0;
	root = last = newState(0);
}

void extend(int w) {
	State *p = last;
	State *np = newState(p->val + 1);
	while(p && p->go[w] == 0)
		p->go[w] = np, p = p->par;
	if(p == 0)
		np->par = root;
	else {
		State *q = p->go[w];
		if(p->val + 1 == q->val) {
			np->par = q;
		} else {
			State *nq = newState(p->val + 1);
			memcpy(nq->go, q->go, sizeof q->go);
			nq->par = q->par;
			q->par = nq;
			np->par = nq;
			while(p && p->go[w] == q)
				p->go[w] = nq, p = p->par;
		}
	}
	last = np;
}

char s1[100010], s2[100010];

int main()
{
	while(~scanf("%s%s",s1,s2)) {
		init(); // 初始化后缀自动机(SAM)
		int i;
		//构造SAM
		for(i=0;s1[i];i++) {
			extend(s1[i]-'a');
		}
		State* now = root;
		//直接用副串跑SAM
		for(i=0;s2[i] && now->go[s2[i]-'a'];i++) {
			now = now->go[s2[i]-'a']; 
		}
		printf("%d\n",i);
	}
    return 0;
}

