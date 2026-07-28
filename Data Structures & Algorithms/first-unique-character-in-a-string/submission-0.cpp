class Solution {
public:
    int firstUniqChar(string s) {

        std::unordered_map<char, int> frequency_map;

        for(char character: s){
            frequency_map[character] ++;
        }

        for(int i = 0; i < s.size(); i++){
            if(frequency_map[s[i]] == 1){
                return i;
            }
        }
return -1;

        
    }
};