#include <algorithm>
#include <cctype>
#include <climits>
#include <ios>
#include <iostream>
#include <limits>
#include <string>
#include <utility>

using namespace std;

int countWords(string sentence);
string uppercaseVowels(string sentence);

string reverseString(string str);

int main() {
  //

  int option;

  cout << "OPTION\n1 - String Manipulation\n2 - Array Manipulation\n\nEnter "
          "your option: ";

  cin >> option;

  // Invalid Option Handler
  if (cin.fail()) {
    cout << "Please enter a valid option!\n";

    return 1;
  }

  switch (option) {
    // String Manipulation Option
  case 1: {
    string sentence;

    cout << "Enter a sentence: ";

    // Clear input buffer before retrieving the line entered by the user
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, sentence);

    cout << "STRING MANIPULATION\n\n";

    int words = countWords(sentence);

    cout << "Number of words in the sentence: " << words << "\n\n";

    cout << "Sentence with uppercase vowels: " << uppercaseVowels(sentence)
         << "\n\n";

    cout << "Reversed sentence: " << reverseString(sentence) << "\n";

    break;
  }

  case 2: {
    int size;
    cout << "How many elements: ";
    cin >> size;

    int arr[size]; // If allowed by compiler

    // Otherwise, use:
    // int *arr = new int[size];
    // or
    // int *arr = (int *)malloc(size * sizeof(int));

    int largest = INT_MIN;

    for (int i = 0; i < size; i++) {
      int n;
      cout << "Enter an element of the array: ";
      cin >> n;

      arr[i] = n;

      largest = max(largest, n);
    }

    // Display the original array
    cout << "Original Array: ";
    for (int i = 0; i < size; i++)
      cout << arr[i] << " ";

    cout << "\n";

    // Display the reversed array
    cout << "Reversed Array: ";
    for (int i = 0; i < size; i++)
      cout << arr[(size - 1) - i] << " ";

    cout << "\n";

    // Display the largest element of the array
    cout << "Largest Element: " << largest << "\n";

    // Display the sorted array
    cout << "Sorted Array: ";

    for (int i = 0; i < size; i++) {
      int lowest = i;

      for (int j = i + 1; j < size; j++) {
        if (arr[j] < arr[lowest])
          lowest = j;
      }

      swap(arr[i], arr[lowest]);

      cout << arr[i] << " ";
    }

    cout << "\n";

    break;
  }

  defaut:
    cout << "Please enter a valid option!\n";

    return 1;
  }

  return 0;
}

int countWords(string sentence) {
  // Word counter for minimum word count validation
  string prevWord;
  int wordCount = 0;

  for (char ch : (sentence + ' ')) {
    // If the character is a whitespace
    if (ch == ' ') {

      // If the previous word is not an empty string, increment the word
      // counter
      if (!prevWord.empty()) {
        wordCount++;

        prevWord = "";
      }

      continue;
    }

    // If the character is not a whitespace, append it to the previous word
    // storage for the counter
    prevWord += ch;
  }

  return wordCount;
}

string uppercaseVowels(string sentence) {
  string newSentence = sentence;

  for (int i = 0; i < sentence.size(); i++) {
    char ch = sentence[i];

    // If the character is a vowel, convert to uppercase
    char upper = toupper(ch);
    if (upper == 'A' || upper == 'E' || upper == 'I' || upper == 'O' ||
        upper == 'U') {
      newSentence[i] = upper;
    }
  }

  return newSentence;
}

string reverseString(string str) {
  string newString = str;

  // Faster traversal and reversing of strings
  int leftPtr = 0, rightPtr = str.size() - 1;

  while (leftPtr < rightPtr) {
    int ch = newString[leftPtr];
    newString[leftPtr] = newString[rightPtr];
    newString[rightPtr] = ch;

    leftPtr++;
    rightPtr--;
  }

  return newString;
}
