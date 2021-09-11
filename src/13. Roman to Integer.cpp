class Solution {
public:
    int romanToInt(string s) {
        int num = 0;
        char previousChar = '\0';
        
        for (string::iterator it = s.begin(); it != s.end(); it++) {
            switch(*it) {
                case 'I':
                    num += 1;
                    break;
                case 'V':
                    num += 5;
                    if (previousChar == 'I') {
                        num -= 2;
                    } 
                    break;
                case 'X':
                    num += 10;
                    if (previousChar == 'I') {
                        num -= 2;
                    } 
                    break;
                case 'L':
                    num += 50;
                    if (previousChar == 'X') {
                        num -= 20;
                    } 
                    break;
                case 'C':
                    num += 100;
                    if (previousChar == 'X') {
                        num -= 20;
                    } 
                    break;
                case 'D':
                    num += 500;
                    if (previousChar == 'C') {
                        num -= 200;
                    } 
                    break;
                case 'M':
                    num += 1000;
                    if (previousChar == 'C') {
                        num -= 200;
                    } 
                    break;
            }
            
            previousChar = *it;
        }
        
        return num;
    }
};
