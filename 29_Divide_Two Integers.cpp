class Solution {
public:
    int divide(int dividend, int divisor) {
        double res;
        try{
            if(dividend == -2147483648 && divisor == -1){
                throw runtime_error("err");
            }
            res = dividend / divisor;
        }catch(runtime_error err){
            res = 2147483647;
        }
        return (int)res;
    }
};
