char * convert(char * s, int numRows){
    
    int size = strlen(s);
    int period = numRows * 2 - 2;
    int pos = 0;
    
    if (size == 0 || numRows == 1) {
        return s;
    }
    
    char *result = malloc((size + 1) * sizeof(char));
    
    for (int i = 0; i < numRows; i++) {
        if (i == 0 || i == numRows - 1) {
            for (int j = i; j < size; j += period) {
                result[pos++] = s[j];
            }
        } else {
            for (int j = i; j < size; j += period) {
                result[pos++] = s[j];
                if ((j + period - i * 2) < size) {
                    result[pos++] = s[j + period - i * 2];
                }
            }
        }
    }
    
    result[pos] = '\0';
    return result;

}
