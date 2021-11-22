#include <bits/stdc++.h>

using namespace std;
using ll = long long int;

template <class T> using V = std::vector<T>;

template <typename T>
std::ostream &operator<<(std::ostream &stream, const vector<T> v) {
  for (ll i = 0; i < v.size(); i++) {
    stream << v[i];

    if (i != v.size() - 1) {
      stream << ' ';
    }
  }

  return stream;
}

template <typename T, typename V>
std::ostream &operator<<(std::ostream &stream, const pair<T, V> p) {
  stream << "(" << p.first << ", " << p.second << ")";

  return stream;
}

#define _GLIBCXX_DEBUG

#define rep(i, m, n) for (ll i = (m); (i) < (ll)(n); ++(i))

#define endl '\n'
#define all(a) (a).begin(), (a).end()
#define fs first
#define sc second
#define pb push_back
#define ins insert

const ll NUMBER = 1000000007;
const int d[5] = {0, 1, 0, -1, 0};

int ctoi(char c) {
  if (c >= '0' && c <= '9') {
    return c - '0';
  }
  return 0;
}

bool isSameCharAll(string str) {
  return (str.find_first_not_of(str[0]) == string::npos);
}

template <class T> inline bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

template <class T> inline bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

int main() {
  ll n;
  cin >> n;
  string s;
  cin >> s;

  // 0のときはIを探す
  // 1のときはIが見つかっていてOを探す
  // 2のときはOが見つかっていてIを探す
  // 3のときはすべての条件を満たしている
  ll state = 0;

  for (ll i = 0; i < s.size(); i++) {
    if (state == 0 && s[i] == 'I') {
      state = 1;
    } else if (state == 1 && s[i] == 'O') {
      state = 2;
    } else if (state == 2 && s[i] == 'I') {
      state = 3;
      cout << "Yes" << endl;
      return 0;
    }
  }

  cout << "No" << endl;
}