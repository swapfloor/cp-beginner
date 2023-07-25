// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_u
// 顺序dp 
// dp[i][j] 表示已经删除 (1, i) (j, n) 的最大值 remove (1, i) (j, n) get max value
#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
  int n;
  cin >> n;

  vector<int> p(n + 1), a(n + 1);
  for (int i = 1; i <= n; i++) cin >> p[i] >> a[i];

  vector<vector<int>> dp(n + 1, vector<int>(n + 1));
  for (int len = n - 1; len >= 1; len--) {
    for (int L = 1; L + len - 1 <= n; L++) {
      int R = L + len - 1;
      
      int cl = 0;
      if (L - 1 >= 1 && p[L - 1] >= L && p[L - 1] <= R) {
        cl = a[L - 1];
      }

      int cr = 0;
      if (R + 1 <= n && p[R + 1] >= L && p[R + 1] <= R) {
        cr = a[R + 1];
      }

      if (L - 1 >= 1 && R + 1 <= n) {
        dp[L][R] = max(dp[L - 1][R] + cl, dp[L][R + 1] + cr);
      } else if (L - 1 >= 1) {
        dp[L][R] = dp[L - 1][R] + cl;
      } else if (R + 1 <= n) {
        dp[L][R] = dp[L][R + 1] + cr;
      }
    }
  }

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans = max(ans, dp[i][i]);
  }

  cout << ans << "\n";
}

int main() {
  if (fopen("D:/treetree/work/treeAs.txt", "r")) {
    freopen("D:/treetree/work/treeAs.txt", "r", stdin);
  }

  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();

  return 0;
}
