class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int num_zeros = 0;
        for(int number: nums){

            if(number == 0){
                num_zeros ++;
            }
        }


        std::erase(nums, 0);

        while(num_zeros > 0){
            nums.push_back(0);
            num_zeros --;
        }
        
    }
};