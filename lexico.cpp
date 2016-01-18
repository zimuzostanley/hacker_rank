#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

vector<char> merge_sort(vector<char>, int, int);

vector<char> merge(vector<char>, vector<char>);

void quick_sort(vector<char>&, int, int);
void swap(vector<char>&, int, int);

string rearrange(string);

void heap_sort(vector<char>&);

void sink(vector<char>&, unsigned int);
void swim(vector<char>&, unsigned int);

int main () {
  int count;
  cin >> count;
  string word;
  while (count-- > 0) {
    cin >> word;
    char *word_arr = new char[word.length() + 1]; 
    strcpy(word_arr, word.c_str());

    cout << rearrange(word_arr) << endl;
  }

 //vector<char> temp1 = vector<char>(3, 'c');
 //vector<char> temp2 = vector<char>(3, 'b');

 //vector<char> result = merge(temp1, temp2);
 

 //vector<char> res = merge_sort(vector<char>(word_arr, word_arr + sizeof(word_arr)/sizeof(char)), 0, word.length() - 1);
 //vector<char> res = vector<char>(word_arr, word_arr + 5);
 //heap_sort(res);
 
 //for (vector<char>::iterator it = res.begin() + 1; it != res.end(); it++) {
   //cout << *it << endl;
      //}
 //cout << res.size();
}

vector<char> merge_sort(vector<char> arr, int lo, int hi) {
  if (lo == hi) {
    vector<char> result(1, arr[lo]);
    return result;
  }

  int mid = (hi + lo ) / 2;

  vector<char> left = merge_sort(arr, lo, mid);
  vector<char> right = merge_sort(arr, mid + 1, hi);
  vector<char> result = merge(left, right);

  return result;
  
}

void swap(vector<char> &arr, int i, int j) {
  char temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}


void sink(vector<char> &arr, unsigned int i, unsigned int end) {
  while(i * 2 < end) {
    if (i * 2 + 1 < end && arr[i * 2] > arr[i * 2 + 1]) {
      swap(arr, i, i * 2 + 1);
      i = i * 2 + 1;
    }
    else if (arr[i] > arr[i * 2]) {
      swap(arr, i, i * 2);
      i *= 2;
    }
    else {
      break;
    }
  }
}

void swim (vector<char> &arr, unsigned int i) {
  while ( i / 2 > 0) {
    if (arr[i/2] > arr[i]) {
      swap(arr, i, i/2);
      i /= 2;
    }
    else {
      break;
    }
  } 
}

void heap_sort(vector<char> &arr) {
  unsigned int i = arr.size() - 1;
  unsigned int j = 2;
  while (j < arr.size()) {
    swim(arr, j++);
  }
  
  while (i > 1) {
    swap(arr, i, 1);
    sink(arr, 1, i--);
  }
}

void quick_sort(vector<char> &arr, int lo, int hi) {
  if (lo >= hi) {
    return;
  }
  int start = lo;
  int end = hi;
  int mid = (hi + lo) / 2;
  
  // Swap with first element;
  swap(arr, lo, mid);
  
  // Sort
  while(lo < hi) {
    if (arr[lo] >= arr[start]) {
      while (hi > lo && arr[hi] > arr[start]) {
	hi--;
      }
      if (hi > lo) {
	swap(arr, lo, hi);
      }
    }
    else {
      lo++;
    }
  }
  swap(arr, start, lo);
  quick_sort(arr, start, lo - 1);
  quick_sort(arr, lo + 1, end);
}

vector<char> merge(vector<char> arr1, vector<char> arr2) {
  vector<char> merged;
  unsigned int count1 = 0;
  unsigned int count2 = 0;
  for (unsigned int i = 0; i < arr1.size() + arr2.size(); i++) {
    if ((count1 < arr1.size() && arr1[count1] < arr2[count2]) || count2 >= arr2.size()) {
      //cout << arr1[count1] << endl;
      merged.push_back(arr1[count1++]);
    }
    else {
      //cout << arr2[count2] << endl;
      merged.push_back(arr2[count2++]);
    }
  }
  return merged;
}

string rearrange(char word[]) {
  unsigned int size = strlen(word);
  
  string arranged;
  char less;
  int less_pos = -1;

  char great;
  int great_pos = -1;
  for (unsigned int i = size; i > 0; i--) {
    if (word[i - 1] < word[i]) {
      less_pos = i - 1;
      less = word[less_pos];
      break;
    }
  }

  if (less_pos == -1) {
    return "no answer";
  }
  else {
    unsigned int i = less_pos + 1;
    great_pos = i;
    great = word[i];
    i++;
    
    while (i <= size) {
      if (word[i] > less && word[i] < great) {
	great_pos = i;
	great = word[i];
      }
      i++;
    }

    word[less_pos] = great;
    word[great_pos] = less;
    sort(word + less_pos + 1, word + size);
    arranged = string(word);
    return arranged;
  }  
}
