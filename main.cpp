#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {

  string s1, s2;
  
  cout << "Enter first string: ";
  cin >> s1;
  
  cout << "Enter second string: ";  
  cin >> s2;
  
  int m = s1.length();
  int n = s2.length();
  
  vector<vector<int> > L(m+1, vector<int>(n+1, 0));
  
  int result = 0;
  string longestSubstr = "";
  
  for(int i=0; i<=m; i++) {
    for(int j=0; j<=n; j++) {
      if (i == 0 || j == 0)
        L[i][j] = 0;
      else if (s1[i-1] == s2[j-1]) {
        L[i][j] = L[i-1][j-1] + 1;
        if(L[i][j] > result) {
          result = L[i][j];
          longestSubstr = s1.substr(i-result, result);
        }
      }
      else
        L[i][j] = 0;
    }
  }
  
  cout << "Longest Common Substring is: " << longestSubstr << " of length " << result << "\n";

  return 0;
}
