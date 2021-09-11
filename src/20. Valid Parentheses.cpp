class Solution {
public:
    bool isValid(string s) {
         
        stack<char> brackets;
        map<char ,char> table;
        table['('] = ')';
        table['['] = ']';
        table['{'] = '}';
        for (string::iterator it = s.begin(); it != s.end(); it++) {
             if (brackets.empty() || *it == '(' || *it == '[' || *it == '{') {
                 brackets.push(*it);
             } else {
                 if (table[brackets.top()] != *it) {
                     return false;
                 } else {
                     brackets.pop();
                 }
             }
        }
        
        return brackets.empty(); 
    }
};
