class Solution {
public:
    string longestPalindrome(string s) {
        
        int Strsize = s.size();
        int start = 0, end = 0;
        int ** m = new int* [Strsize];
        int max = 1;
 
        for (int i = 0; i < Strsize - 1; i++) {
            m[i] = new int[Strsize];
            m[i][i] = 1;
            if (s[i] == s[i+1]) {
                m[i][i + 1] = 2;
                max = 2;
                start = i;
                end = i + 1;
            } else {
                m[i][i + 1] = 0;
            }
        }
        m[Strsize - 1] = new int[Strsize];
        m[Strsize - 1][Strsize - 1] = 1;
        
        for (int i = 2; i < Strsize; i++) {
            
            for (int j = 0; j < Strsize - i; j++) {
               if (s[i + j] == s[j] && m[j + 1][i + j - 1] > 0) {
                   m[j][i + j] = m[j + 1][i + j - 1] + 2;
               } else {
                   m[j][i + j] = 0;
               }
               if (m[j][i + j] > max) {
                   start = j;
                   end = i + j;
                   max = m[j][i + j];
               } 
            }
        }
        
       for (int i = 0; i < Strsize; i++) {
           delete [] m[i];
       }
       
       delete [] m;
       
       return s.substr(start, end - start + 1);
        
        
        
    }
};
