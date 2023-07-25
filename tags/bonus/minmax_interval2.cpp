// test in https://oj.eriktse.com/problem.php?id=1081
#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  
  vector<int> st;
  vector<int> ng(n, n); // ng[i] 表示下一个大于 a[i] 的最小位置。ng[i] show the min position j > i, a[j] > a[i]
  for (int i = 0; i < n; i++) {
    while (!st.empty() && a[st.back()] < a[i]) {
      ng[st.back()] = i;
      st.pop_back();
    }
    st.push_back(i);
  }
  
  vector<int>().swap(st);
  vector<int> nl(n, n); // nl[i] 表示下一个小于 a[i] 的最小位置。nl[i] show the min position j > i, a[j] < a[i]
  for (int i = 0; i < n; i++) {
    while (!st.empty() && a[st.back()] > a[i]) {
      nl[st.back()] = i;
      st.pop_back();
    }
    st.push_back(i);
  }
  
  vector<int>().swap(st);
  vector<int> pg(n, -1); // pg[i] 表示上一个大于 a[i] 的最大位置。pg[i] show the max position j < i, a[j] > a[i]
  for (int i = n - 1; i >= 0; i--) {
    while (!st.empty() && a[st.back()] < a[i]) {
      pg[st.back()] = i;
      st.pop_back();
    }
    st.push_back(i);
  }
  
  vector<int>().swap(st);
  vector<int> pl(n, -1); // pl[i] 表示上一个小于 a[i] 的最大位置。pl[i] show the max position j < i, a[j] < a[i]
  for (int i = n - 1; i >= 0; i--) {
    while (!st.empty() && a[st.back()] > a[i]) {
      pl[st.back()] = i;
      st.pop_back();
    }
    st.push_back(i);
  }
  
  vector<int> c(n, -1); // 树状数组。fenwick tree or binary index tree
  
  auto set_upper = [&](int p, int v) { // set position j >= p, tree[j] = max(tree[j], v)
    while (p >= 1) {
      c[p] = max(c[p], v);
      p -= p & -p;
    }
  };
  
  auto get_upper = [&](int p) { // get min(tree[j] for position j >= p)
    int ans = -1;
    while (p <= n - 1) {
      ans = max(ans, c[p]);
      p += p & -p;
    }
    return ans;
  };
  
  vector<int> suf(n); // suf[i] = max( min(pl[j], pg[j]) for j >= i )
  for (int i = n - 1; i >= 0; i--) {
    suf[i] = min(pl[i], pg[i]);
    if (i != n - 1) suf[i] = max(suf[i], suf[i + 1]);
  }
  for (int i = n - 1; i >= 1; i--) set_upper(i, suf[i]);
  
  // for debug
  // for (int i = 0; i < n; i++)
  //   cout << i << "," << pl[i] << " \n"[i == n - 1];
  // for (int i = 0; i < n; i++)
  //   cout << i << "," << pg[i] << " \n"[i == n - 1];
  // for (int i = 1; i < n; i++)
  //   cout << i << "," << get_upper(i) << " \n"[i == n - 1];
  
  for (int i = 0; i < n - 3; i++) {
    auto ri = max(nl[i], ng[i]); // >= ri is legal
    if (ri == n) continue;
    
    auto le = get_upper(ri); // <= le is legal
    if (le >= i) {
      for (int j = ri; j < n; j++)
        if (min(pl[j], pg[j]) >= i) {
          cout << i + 1 << " " << j + 1 << "\n";
          return;
        }
    }
  }
  
  cout << -1 << "\n";
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int T;
  cin >> T;
  
  while (T--) solve();
  
  return 0;
}
