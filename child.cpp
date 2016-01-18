#include <iostream>
#include <map>

using namespace std;

int cache[10000][10000];
int next(string&, int, char, int);
int child_size(string&, string&, int, int);

int main() {
  string word1;
  string word2;
  cin >> word1 >> word2;

  for (int i = 0; i < word1.size(); i++) {
    for (int j = 0; j < word2.size(); j++) {
      cache[i][j] = -1;
    }
  }

  int larg = child_size(word1, word2, 0, 0);
  
  cout << larg << endl;
}

int next(string &word, int i, char c) {
  for (int j = i; j < word.size(); j++) {
    if (word[j] == c) {
      return j;
    }
  }
  return -1;
}

int child_size(string &word1, string &word2, int i1, int i2) {
  int largest = 0;
  for (int j = i1; j < word1.size(); j++) {
    for (int k = i2; k < word2.size(); k++) {
      int can_add = next(word2, k, word1[j]);
      if (can_add == -1) {
	break;
      }
      int a = 0;
      if (cache[j][can_add] == -1) {
	a = child_size(word1, word2, j + 1, can_add + 1) + 1;	
      }
      else {
      	a = cache[j][k];	
      }
      if (a > largest) {
	largest = a;
      }
    }
    
  }
  cache[i1][i2] = largest;
  return largest;
}
