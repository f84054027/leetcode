int lengthOfLongestSubstring(char * s){
    int n = 0, len = 0;
    int start = 0, end = 0, index;
    
    
    while(s[n] != '\0') {
        n++;
    }
    if (n == 0) {
        return 0;
    }
    int *table = calloc(95, sizeof(int));
    for (int i = 0; i < 95; i++) {
        table[i] = -1;
    }
    index = ((int) s[0]) - 32;
    table[index] = 0;
    for (int i = 1; i < n; i++) {
        if (end - start > len) {
            len = end - start;
        }
        index = ((int) s[i]) - 32;
        if (table[index] != -1) {
            if (start <= table[index]) {
                start = table[index] + 1;
            }
        }
        table[index] = i;
        end = i;
    }
    if (end - start > len) {
        len = end - start;
    }

    free(table);
    return len + 1;
}

// old solution

/*int lengthOfLongestSubstring(char * s){
    int n = 0, len = 0;
    int start = 0, end = 0, tmp;
    
    
    while(s[n] != '\0') {
        n++;
    }
    if (n == 0) {
        return 0;
    }
    int *table = calloc(95, sizeof(int));
    for (int i = 1; i < n; i++) {
        if (end - start > len) {
            len = end - start;
        }
        for (int j = start; j < end + 1; j++) {
            if (s[j] == s[i]) {
                start = j + 1;
            }
        }
        end = i;
    }
    if (end - start > len) {
        len = end - start;
    }
    return len + 1;
}a
*/
