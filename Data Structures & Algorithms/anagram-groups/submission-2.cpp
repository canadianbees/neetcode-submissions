#include <ranges>
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> anagrams;
        vector<vector<string>> result;

        for(auto &word : strs){

            string original = word;
            ranges::sort(word);
            anagrams[word].push_back(original);
          
        }
        
        for (const auto &stuff: anagrams | views::values) {
            result.push_back(stuff);
        }
        
        return result;

    }
};
