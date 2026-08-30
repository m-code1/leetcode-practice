char* longestCommonPrefix(char** strs, int strsSize) {
    int i = 0;

    while (strs[0][i] != '\0') {
        for(int j = 1; j < strsSize; j++) {
            if(strs[j][i] != strs[0][i]) {
                strs[0][i] = '\0';
                return strs[0];
            }
        }
        i++;
    }
    return strs[0];
}