class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        //1. O(n^3) case
        /*
        for(int i=0; i<nums.size();i++){
            for(int j=i;j<nums.size();j++){
                for(int k=j;k<nums.size();k++){
                    if(nums[i] < nums[k] && nums[k] < nums[j]) return true;
                }
            }
        }
        return false;
        */
        //2. O(n^2) case
        /*
        vector<int> left_min;
        left_min.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            left_min.push_back(min(nums[i],left_min[i-1]));
        }
        for(int i=1;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(left_min[i] < nums[j] && nums[j] < nums[i]) return true;
            }
        }
        return false;
        */
        //3. O(2*n) case
        vector<int> left_min;
        vector<int> stack;
        left_min.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            left_min.push_back(min(nums[i],left_min[i-1]));
        }
        stack.push_back(nums[nums.size()-1]);
        for(int i=nums.size()-2;i>=0;i--){
            while(stack.size()>0 && nums[i] > stack[stack.size()-1]){
                //pop and check
                int comp = stack[stack.size()-1];
                stack.pop_back();
                //nums[i] = j, comp = k, left_min[i] = i
                if(left_min[i] < comp && comp < nums[i]) return true;
            }
            stack.push_back(nums[i]);
        }
        return false;
    }
};
