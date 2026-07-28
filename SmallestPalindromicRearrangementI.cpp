class Solution {
public:
    string smallestPalindrome(string s) {

        string l, mid;

        map<char,int> mp;

        for(char c : s)
            mp[c]++;

        for(auto &it : mp){

            l.append(it.second/2, it.first);

            if(it.second % 2 && mid.empty())
                mid.push_back(it.first);
        }

        string ans = l + mid;

        for(int i=l.size()-1;i>=0;i--)
            ans.push_back(l[i]);

        return ans;
    }
};