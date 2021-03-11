class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area = 0;
        int l, r;
        int left_height, right_height;
        l = 0;
        r = height.size()-1;
        while(l<r){
            left_height = height[l];
            right_height = height[r];
            max_area = max(max_area,min(left_height,right_height)*(r-l));
            
            if(left_height > right_height) r--;
            else l++;
        }
        return max_area;
    }
};
