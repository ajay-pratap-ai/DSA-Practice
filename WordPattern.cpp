class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> mp;
        unordered_set<string> used;

        stringstream ss(s);
        string word;
        int i = 0;

        while (ss >> word) {
            // More words than pattern characters
            if (i >= pattern.size())
                return false;

            char ch = pattern[i];

            // Character already has a mapping
            if (mp.count(ch)) {
                if (mp[ch] != word)
                    return false;
            }
            // New character
            else {
                // Word is already mapped to another character
                if (used.count(word))
                    return false;

                mp[ch] = word;
                used.insert(word);
            }

            i++;
        }

        // Pattern has more characters than words
        return i == pattern.size();
    }
};