#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;

  int ans = min({(a + b + c) - a, (a + b + c) - b, (a + b + c) - c});

  cout << ans << endl;
}
