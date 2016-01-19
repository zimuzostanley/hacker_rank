#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

bool isFunny(string);

int main() {
  int count = 0;
  cin >> count;
  string word;
  while (count > 0) {
    cin >> word;
    if (isFunny(word)) {
      cout << "True" << endl;
    }
    else {
      cout << "False" << endl;
    }
    count--;
  }
  return 0;
}

bool isFunny(string s) {
  int s_ascii = 0;
  int r_ascii = 0;
  for (unsigned int i = 1; i < s.size(); i++) {
    s_ascii = abs((int)s[i] - (int)s[i - 1]);
    r_ascii = abs((int)s[s.size() - i] - (int)s[s.size() - i - 1]);

    if (s_ascii != r_ascii) {
      return false;
    }
  }
  return true;
}
