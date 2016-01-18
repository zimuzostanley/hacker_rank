#include <iostream>
#include <cmath>

using namespace std;

int reduc(string&);

int main() {
  int count = 0;
  cin >> count;
  string word;
  while (count-- > 0) {
    cin >> word;
    cout << reduc(word) << endl; 
  }
}

int reduc(string &word) {
  int total = 0;
  int size = word.size() - 1;
  for (int i = 0; i < (size + 1) / 2; i++) {
    if (word[i] != word[size - i]) {
      total += abs((int) word[i] - (int)word[size - i]);
    }
  }
  return total;
}
