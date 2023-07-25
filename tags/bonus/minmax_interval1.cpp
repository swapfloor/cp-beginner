// test in https://oj.eriktse.com/problem.php?id=1081
#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  
  multiset<int> s(a.begin(), a.end()); // 将数组放入 set 中。array enter into set
  
  int L = 0, R = n - 1;
  while (L < R) {
    if (a[L] == *s.begin() || a[L] == *s.rbegin()) s.erase(s.find(a[L++])); // L 是最大或最小值，删除 L。L is max or min, delete L
    else if (a[R] == *s.begin() || a[R] == *s.rbegin()) s.erase(s.find(a[R--])); // R 是最大或最小值，删除 R。R is max or min, delete R
    else break;
  }
  
  if (L < R) cout << L + 1 << " " << R + 1 << "\n";
  else cout << -1 << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int T;
  cin >> T;
  
  while (T--) solve();
  
  return 0;
}
