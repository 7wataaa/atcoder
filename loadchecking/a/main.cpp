#include <bits/stdc++.h>
using namespace std;
#define all(a) (a).begin(), (a).end()
int main() {
  vector<int> vec;
  for (int i = 0; i < 20; i++) {
    vec.push_back(i + 1);
  }
  std::random_device seed_gen;
  std::mt19937 engine(seed_gen());
  std::shuffle(all(vec), engine);
  for (auto a : vec) {
    cout << a << endl;
  }
}