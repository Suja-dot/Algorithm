class Solution {
private:
    int modulo = 1000000007;
public:
    int threeSumMulti(vector<int>& arr, int target) {
        int ans = 0, adv_target;
        int l, r, lRepit, rRepit;
        sort(arr.begin(),arr.end());
        // a + b + c = target
        // => b + c = target - a
        for(int i=0;i<arr.size()-1;i++){
            adv_target = target - arr[i];
            //printf("i = %d, Target sum value : %d\n",i,adv_target);
            l = i+1;
            r = arr.size()-1;
            while(l < r){
                //printf("[%d, %d]\n",l,r);
                if(arr[l]+arr[r] == adv_target){
                    lRepit = rRepit = 1;
                    while((l+1)<r && arr[l] == arr[l+1]){l++; lRepit++;}
                    while(l<(r-1) && arr[r] == arr[r-1]){r--; rRepit++;}
                    if(arr[l] == arr[r]){ ans = (ans+((lRepit+rRepit)*(lRepit+rRepit-1))/2)%modulo; }
                    else{ ans = (ans+lRepit*rRepit)%modulo; }
                    //printf("Answer : %d\n",ans);
                    l++; r--;
                }
                while(l<r && arr[l]+arr[r] < adv_target){ l++; }
                while(l<r && arr[l]+arr[r] > adv_target){ r--; }
            }
        }
        return ans;
    }
};
