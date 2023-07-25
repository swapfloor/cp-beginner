// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_u
#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int N = 2e3 + 5;

int n;
int p[N], a[N];
int dp[N][N];

int dfs(int L, int R) {
  if (dp[L][R] != -1) return dp[L][R];

  return dp[L][R] = max(dfs(L + 1, R) + (p[L] >= L + 1 && p[L] <= R) * a[L], dfs(L, R - 1) + (p[R] >= L && p[R] <= R - 1) * a[R]);
}

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> p[i] >> a[i];

  for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) dp[i][j] = -1;
  for (int i = 1; i <= n; i++) dp[i][i] = 0;

  cout << dfs(1, n) << "\n";
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();

  return 0;
}
