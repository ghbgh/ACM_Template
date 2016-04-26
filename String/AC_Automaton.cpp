// AC×Ô¶¯»ú
// 2015.2.6
// By Curs0r

int Next[500010][26];
int fail[500010];
int val[500010];
int n_node;
int root;

int newnode() {
    val[n_node] = 0;
    REP(i,26) Next[n_node][i] = -1;
    return n_node++;
}

void init() {
    n_node = 0;
    int p = newnode();
    REP(i,26) Next[p][i] = 1;
    root = newnode();
}

void insert(char s[]) {
    int now = root;
    for(int i = 0; s[i]; i++) {
        if(Next[now][s[i]-'a']==-1)
            Next[now][s[i]-'a'] = newnode();
        now = Next[now][s[i]-'a'];
    }
    val[now]++;
}

void build() {
    queue<int> q;
    fail[root] = 0;
    q.push(root);
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        REP(i,26) {
            if(Next[now][i] == -1) {
                Next[now][i] = Next[fail[now]][i];
            }else{
                fail[Next[now][i]] = Next[fail[now]][i];
                q.push(Next[now][i]);
            }
        }
    }
}

int query(char s[]) {
    int res = 0;
    int now = root;
    for(int i = 0; s[i]; i++) {
        now = Next[now][s[i]-'a'];
        int p = now;
        while(p != root) {
            res += val[p];
            val[p] = 0;
            p = fail[p];
        }
    }
    return res;
}

char s[1000010];

int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--) {
        init();
        scanf("%d",&n);
        REP(i,n) {
            scanf("%s",s);
            insert(s);
        }
        build();
        scanf("%s",s);
        printf("%d\n",query(s));
    }
    return 0;
}

