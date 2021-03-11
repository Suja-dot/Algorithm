class Solution {
    public String addBinary(String a, String b) {
        int sum, upper;
        int pointA,pointB;
        String ans = "";
        pointA = a.length()-1;
        pointB = b.length()-1;
        upper = 0;
        for(int i=0;i<Math.min(a.length(),b.length());i++){
            sum = Character.getNumericValue(a.charAt(pointA--)) + Character.getNumericValue(b.charAt(pointB--)) + upper;
            upper = sum / 2;
            sum %= 2;
            ans = Integer.toString(sum) + ans;
        }
        if(a.length() > b.length()){
            while(pointA >= 0){
                sum = Character.getNumericValue(a.charAt(pointA--)) + upper;
                upper = sum / 2;
                sum %= 2;
                ans = Integer.toString(sum) + ans;
            }
        }else if(b.length() > a.length()){
            while(pointB >= 0){
                sum = Character.getNumericValue(b.charAt(pointB--)) + upper;
                upper = sum / 2;
                sum %= 2;
                ans = Integer.toString(sum) + ans;
            }
        }
        while(upper>0){
            ans = Integer.toString(upper%2) + ans;
            upper /= 2;
        }
        return ans;
    }
}
