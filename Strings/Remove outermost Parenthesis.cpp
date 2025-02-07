Leetcode - 1021: https://leetcode.com/problems/remove-outermost-parentheses/

#include <iostream>
#include <string>
using namespace std;

string removeOuterParentheses(string s) {
    string result;
    int openCount = 0; // Keeps track of the depth of parentheses
    
    for (char c : s) {
        if (c == '(') {
            if (openCount > 0) result += c; // Add only if it's not the outermost '('
            openCount++;
        } else {
            openCount--;
            if (openCount > 0) result += c; // Add only if it's not the outermost ')'
        }
    }
    
    return result;
}

int main() {
    // Test cases
    cout << removeOuterParentheses("(()())(())") << endl; // Expected: "()()()"
    cout << removeOuterParentheses("(()())(())(()(()))") << endl; // Expected: "()()()()(())"
    cout << removeOuterParentheses("()()") << endl; // Expected: ""
    return 0;
}
