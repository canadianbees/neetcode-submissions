class Solution {
public:
 vector<int> topKFrequent(vector<int>& nums, int k) {

        // hash map to track the frequency of each digit
        // once the tracking is done, sort keys by frequency

        unordered_map<int, int> frequencies;

        for(auto &digit : nums){
            frequencies[digit] ++;
        }


        priority_queue<pair<int,int>> pq;
        vector<int> ans;

        for (auto& [digit, frequency] : frequencies) {
            pq.emplace(frequency, digit);
        }


        while (k > 0) {
            auto [frequency, digit] = pq.top();
            ans.push_back(digit);
            pq.pop();
            k--;
        }
    
        return ans;
    }
};
