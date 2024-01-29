#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str) {
  
  stringstream Extract_String(str); 
  vector<int> intResult ;
  size_t temp ; 
  char ch; // to store comma

  while(Extract_String >> temp){
    intResult.push_back(temp) ;
    Extract_String>>ch ; 
  } 
  return intResult; 


	// Complete this function
}

int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }
    
    return 0;
}