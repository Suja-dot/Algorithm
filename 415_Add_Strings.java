class Solution {
    public String addStrings(String num1, String num2) {
        String ans = "";
        int upper = 0, sum = 0;
        int position1 = num1.length()-1;
        int position2 = num2.length()-1;
        for(int i=0;i<Math.min(num1.length(),num2.length());i++){
            sum = Character.getNumericValue(num1.charAt(position1--)) + Character.getNumericValue(num2.charAt(position2--)) + upper;
            upper = sum/10;
            sum %= 10;
            ans = Integer.toString(sum) + ans;
        }
        if(num1.length() > num2.length()){
            while(position1 >= 0){
                sum = Character.getNumericValue(num1.charAt(position1--)) + upper;
                upper = sum/10;
                sum %=10;
                ans = Integer.toString(sum) + ans;
            }
        }else if(num1.length() < num2.length()){
            while(position2 >= 0){
                sum = Character.getNumericValue(num2.charAt(position2--)) + upper;
                upper = sum/10;
                sum %=10;
                ans = Integer.toString(sum) + ans;
            }
        }
        while(upper>0){
            ans = Integer.toString(upper%10) + ans;
            upper /= 10;
        }
        return ans;
    }
}
