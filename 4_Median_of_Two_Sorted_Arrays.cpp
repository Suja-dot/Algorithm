class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double res=0.0;
        int index1=0,index2=0;
        int prev_val=-1, cur_val=-1;
        int size = nums1.size()+nums2.size();
        while(1){
            if(index1+index2 > size/2) break;
            prev_val = cur_val;
            if(index1 >= nums1.size()){
                cur_val = nums2[index2];
                index2++;
            }
            else if(index2 >= nums2.size()){
                cur_val = nums1[index1];
                index1++;
            }
            else{
                if(nums1[index1]<nums2[index2]){
                    cur_val = nums1[index1];
                    index1++;
                }else{
                    cur_val = nums2[index2];
                    index2++;
                }
            }
        }
        if(size%2==0) res = (prev_val+cur_val)/2.0;
        else res = cur_val;
        return res;
    }
};
