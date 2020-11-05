//
//  main.cpp
//  longestPalinSubstr
//
//  Created by Yichen Zhou on 11/5/20.
//  Copyright © 2020 Yichen Zhou. All rights reserved.
//

#include <iostream>
#include <cassert>
#include <string>
using namespace std;

string longestPalindrome(string s);
string expand(string s, int low, int high);

int main() {
    
    assert(longestPalindrome("") == "");
    assert(longestPalindrome("a") == "a");
    assert(longestPalindrome("abbc") == "bb");
    assert(longestPalindrome("babad") == "bab");
    
    cout << "Passed all tests." << endl;
    return 0;
}


string longestPalindrome(string s)
{
    string result = "";
    for (int i = 0; i <= s.size() ; i++) {
        string c1 = expand(s, i, i);
        string c2 = expand(s, i, i+1);
        if (result.size() < c1.size()) result = c1;
        if (result.size() < c2.size()) result = c2;
    }
    return result;
}

string expand(string s, int low, int high)
{
    while (low >= 0 && high < s.size() && s[low] == s[high]) {
        low --;
        high ++;
    }
    return s.substr(low+1, high - low + 1);
}
