class Solution {

    bool isVowel(char c) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }

public:
    int maxVowels(string s, int k) {
        int n = s.length();
        int count = 0, maxCount = 0;

        
        for (int i = 0; i < k; i++)
            if (isVowel(s[i])) count++;
        maxCount = count;

        
        for (int i = k; i < n; i++) {
            if (isVowel(s[i])) count++;
            if (isVowel(s[i-k])) count--;
            maxCount = max(maxCount, count);
        }
        
        return maxCount;
    }
};
