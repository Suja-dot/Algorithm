bool isPalindrome(int x){
    bool ans;
    int idx,i;
    char str[15];
    
    if(x < 0) ans = false;
    else{
        ans = true;
        idx = 0;
        while(x > 0){
            str[idx++] = x%10;
            x/=10;
        }
        for(i=0;i<idx/2;i++){
            if(str[i] != str[idx-i-1]){
                ans = false;
                break;
            }
        }
    }
    return ans;
}
