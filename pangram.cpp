#include <iostream>

using namespace std;

int main() {
  string sentence;
  bool isNotPangram = false;
  int alphabets[26] = {};
  
  getline(cin, sentence);

  for (string::iterator it = sentence.begin(); it < sentence.end(); it++) {
    cout << *it << endl;
    if (islower(*it)) {
      alphabets[(int)*it - 97]++;
    }
    else if (isupper(*it)) {
      alphabets[(int)*it - 65]++;
    }
  }

  for (int i = 0; i < 26; i++) {
    if (alphabets[i] == 0) {
      isNotPangram = true;
      break;
    }
  }
  
  if (isNotPangram) {
    cout << "not pangram";
  }
  else {
    cout << "pangram"; 
  }
  return 0;
}
