#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define NO_OF_CHARS 256

void badCharHeuristic(string pattern, int size, int badchar[NO_OF_CHARS]) {
    for (int i = 0; i < NO_OF_CHARS; i++)
        badchar[i] = -1;
    
    for (int i = 0; i < size; i++)
        badchar[(int)pattern[i]] = i;
}

void search(string text, string pattern) {
    int m = pattern.size();
    int n = text.size();
    
    int badchar[NO_OF_CHARS];
    badCharHeuristic(pattern, m, badchar);
    
    int shift = 0;
    while (shift <= (n - m)) {
        int j = m - 1;
        
        while (j >= 0 && pattern[j] == text[shift + j])
            j--;
        
        if (j < 0) {
            cout << "Pattern found at index " << shift << endl;
            shift += (shift + m < n) ? m - badchar[text[shift + m]] : 1;
        } else {
            shift += max(1, j - badchar[text[shift + j]]);
        }
    }
}

int main() {
    string text = "ABAAABCDBBABCDDEBCABC";
    string pattern = "ABC";
    
    cout << "Text: " << text << endl;
    cout << "Pattern: " << pattern << endl;
    search(text, pattern);
    return 0;
}
