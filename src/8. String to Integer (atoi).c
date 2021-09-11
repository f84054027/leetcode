bool mystrcmp(string s, bool isNegative) {
    string pos = "2147483647";
    string neg = "2147483648";
    bool encounter = false;
    if (isNegative) {
        for (int i = 0; i < neg.size(); i++) {
            if(s[i] > neg[i]) {
                if (!encounter) {
                    return true;
                }
            } else {
                if (s[i] < neg[i]) {
                    encounter = true;
                }
            }
        }
    } else {
        for (int i = 0; i < pos.size(); i++) {
            if(s[i] > pos[i]) {
                if (!encounter) {
                    return true;
                }
            } else {
                if (s[i] < pos[i]) {
                    encounter = true;
                }
            }
        }
    }
    
    return false;
}

class Solution {
public:
    int myAtoi(string s) {
        string toInt;
        bool encounter = false;
        bool isNegative = false;
        int start = 0, result;
        
        for (string::iterator it = s.begin(); it !=s.end(); it++) {
            if (!encounter) {
                if(*it == '-' || *it == '+' || (*it >= 48 && *it <= 57)) {
                    encounter = true;
                    toInt.push_back(*it);
                } else {
                    if (*it != ' ') {
                        return 0;
                    }
                }
            } else {
                if (*it >= 48 && *it <= 57) {
                    toInt.push_back(*it);
                } else {
                    break;
                }
            }
        }
        
        if (toInt[start] == '-') {
            isNegative = true;
            start++;
        } 
        if (toInt[start] == '+') {
            start++;
        }
        for (; start < toInt.size(); start++) {
            if (toInt[start] != '0') {
               break; 
            }
        }
        toInt = toInt.substr(start);
        if (toInt.size() > 10) {
            return (isNegative) ? INT_MIN : INT_MAX;
        } else if (toInt.size() == 10) {
            if (mystrcmp(toInt, isNegative)) {
                return (isNegative) ? INT_MIN : INT_MAX;
            } 
        }
        result = 0;
        for (string::iterator it = toInt.begin(); it != toInt.end(); it++) {
            result *= 10;
            if (isNegative) {
                result -= *it - 48;
            } else {
                result += *it - 48;
            }
        }
        
        return result;
    }
};
