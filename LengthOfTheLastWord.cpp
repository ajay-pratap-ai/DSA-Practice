class Solution {
public:
    int lengthOfLastWord(string s) {
        bool l = false;
        int length = 0;
        for(int i=s.length()-1;i>=0;i--){
            if(s[i] !=' '){
                l = true;
            }
            if(s[i] == ' ' && l== true){
                return length;
            }if(l == true){
                length++;
            }if(i==0){
                return length++;
            }
        }
        return -1;
    }
};