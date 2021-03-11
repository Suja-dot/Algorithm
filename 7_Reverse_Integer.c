int reverse(int x){
    int max_integer = 2147483647;
    int min_integer = -2147483648;
    int res = 0;
    if(x == max_integer || x == min_integer) return 0;
    int tmp = abs(x);
    while(tmp > 0){
        if(x > 0 && res > max_integer/10) return 0;
        if(x < 0 && -res < min_integer/10) return 0;
        
        res = res*10 + tmp%10;
        tmp/=10;
    }
    if(x<0) res*=-1;
    return res;
}
