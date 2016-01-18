#include <iostream>
#include <map>

using namespace std;

int check_word(string&);
bool check_sub(string&, unsigned int, unsigned int, unsigned int, unsigned int);

int main() {
  int count = 0;

  cin >> count;
  string word;
  while (count-- > 0) {
    cin >> word;
    cout << check_word(word) << endl;
  }
}

int check_word (string &word) {
  int count = 0;
  // Check length 1
  for (unsigned int l = 0; l < word.size() - 1; l++) {
    for (unsigned int i = 0; i < word.size() - l; i++) {
      for (unsigned int j = i + 1; j < word.size() - l; j++) {
	//cout << i << "\t" << i + l + 1 << "\t" << j << "\t" << j + l + 1 << endl;
	if (check_sub(word, i, i + l + 1, j, j + l + 1)) {
	  count++;
	}
      }
    }
  }

  return count;
}



bool check_sub(string &word, unsigned int start1, unsigned int end1, int unsigned start2, unsigned int end2) {
  map<char, int> word_map;
  
  for (unsigned int i = start1; i < end1; i++) {

    if (word_map.find(word[i]) != word_map.end()) {
      word_map[word[i]] += 1;
    }
    else {
      word_map[word[i]] = 1;
    }
  }
  for (unsigned int i = start2; i < end2; i++) {
    if (word_map.find(word[i]) != word_map.end()) {
      word_map[word[i]] -= 1;
    }
    else {
      word_map[word[i]] = -1;
    }
  }


  for (map<char, int>::iterator it = word_map.begin(); it != word_map.end(); it++) {
    if (it->second != 0) {
      return false;
    }
  }
  return true;
}
