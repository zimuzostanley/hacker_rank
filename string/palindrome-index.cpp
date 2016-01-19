#include <iostream>

using namespace std;

bool check_palindrome(string&, int, int);
int palindrome_index(string&);

int main() {
  int count = 0;
  cin >> count;
  string word;

  while (count-- > 0) {
    cin >> word;
    cout << palindrome_index(word) << endl;
  }
}

bool check_palindrome(string &word, int start, int end) {
  while (start < end) {
    if (word[start++] != word[end--]) {
      return false;
    }
  }
  return true;
}

int palindrome_index(string &word) {
  for (unsigned int i = 0; i < word.size() / 2; i++) {
    int a = -2;
    int b = -2;
    if (word[i] != word[word.size() - i - 1]) {
      if (word[i + 1] == word[word.size() - i - 1]) {
	a = i;
      }
      if (word[word.size() - i - 2] == word[i]) {
	b = word.size() - i - 1;
      }
      if (a == -2 && b != -2) {
	return b;
      }
      else if (b == -2 && a != -2) {
	return a;
      }
      else {
	if (check_palindrome(word, a + 1, b)){
	  return a;
	}
	else {
	  return b;
	}
      }
    }
  }
  return -1;
}
