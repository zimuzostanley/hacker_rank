#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

struct map_count_t {
  map<char, int> count;
  map<char, int> count2;
} word_count;


map_count_t* get_map(string&);
string get_string(string&);
int next_smallest(string&, int, map_count_t&);
bool check_map(map<char,int>&, map<char,int>&, char);


int main() {
  string word;
  cin >> word;
  cout << get_string(word) << endl;
}

int next_smallest(string &word, int cur, map_count_t &map_count) {
  int next = cur;
  char smallest = word[cur];

  for (int i = cur; i >= 0; i--) {
    bool check = check_map(map_count.count, map_count.count2, word[i]);
    if (word[i] < smallest && check) {
      next = i;
      smallest = word[i];
    }
    map_count.count2[word[i]]--;
  }
  for (unsigned int i = 0; i < next; i++) {
    map_count.count2[word[i]]++;
  }
  map_count.count[smallest]--;

  return next;
}

bool check_map(map<char, int> &pat, map<char, int> &text, char a) {
  for(map<char, int>::iterator it = pat.begin(); it != pat.end(); it++) {
    if (text[it->first] < it->second || pat[a] <= 0) {
      return false;
    }
  }
  return true;
}

map_count_t* get_map(string &word) {
  map<char, int> count;
  map<char, int> count2;
  for (string::iterator it = word.begin(); it != word.end(); it++) {
    if (count.find(*it) == count.end()) {
      count2[*it] = 1;
      count[*it] = 1;
    }
    else {
      count2[*it]++;
      count[*it]++;
    }
  }
  
  for (map<char, int>::iterator it = count.begin(); it != count.end(); it++) {
    it->second /= 2;
  }
  map_count_t *map_count = &word_count;
  map_count->count = count;
  map_count->count2 = count2;
  return map_count;
}

string get_string(string &word) {
  map_count_t *map_count = get_map(word);
  
  string A = "";

  int i = word.size() - 1;
  while (i >= 0) {
    if (map_count->count[word[i]] > 0) {
      int next = next_smallest(word, i, *map_count);
      A.push_back(word[next]);
      i = next - 1;
    }
    else {
      //cout << map_count->count[word[i]] << "\t" << word[i] << endl;
      map_count->count2[word[i]]--;
      i--;
    }
  }
  return A;
}
