// SEE: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_B
// 再帰を用いた実装

#include<stdio.h>
#include<stack>

#define MAX 100

enum SATE {
    NOT_VISIT,
    DISCOVER,
    FOUND
};

int G[MAX+1][MAX+1], d[MAX+1], f[MAX+1], STATE[MAX+1];
int n, tt;
std::stack<int> S;

void dfs(int i) {
    S.push(i);
    STATE[i] = DISCOVER;
    d[i] = ++tt;

    for (int j = 1; j <= n; ++j) {
        if (G[i][j] != 1 || STATE[j] != NOT_VISIT) continue;
        dfs(j);
    }
    STATE[i] = FOUND;
    f[i] = ++tt;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        d[i] = f[i] = 0;
        STATE[i] = NOT_VISIT;
        for (int j = 1; j <= n; ++j) {
            G[i][j] = 0;
        }
    }
    for (int i = 0; i < n; ++i) {
        int u,k;
        scanf("%d %d", &u, &k);
        for (int j = 0; j < k; ++j) {
            int t;
            scanf("%d", &t);
            G[u][t] = 1;
        }
    }

    tt = 0;
    for (int i = 1; i <= n; ++i) {
        if (STATE[i] == NOT_VISIT) dfs(i);
    }
    for (int i = 1; i <= n; ++i) {
        printf("%d %d %d\n", i, d[i], f[i]);
    }

}
