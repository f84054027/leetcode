class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        string result;
        
        int s = 201; // maximum string size
        char c; 
        for (vector<string>::iterator it = strs.begin(); it != strs.end(); it++) {
            if (s > (*it).size()) {
                s = (*it).size();
            }
        }
        
        for (int i = 0; i < s; i++) {
            c = strs[0][i]; 
            for (vector<string>::iterator it = strs.begin() + 1; it != strs.end(); it++) {
               if ((*it)[i] != c) {
                   return result;
               } 
            }
            result.push_back(c);
        }
        
        return result;
    }
};
