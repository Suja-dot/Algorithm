class Solution {
    public boolean wordPattern(String pattern, String s) {
        boolean ans = true;
        boolean[] using = new boolean[27];
        HashMap<String, Character> map = new HashMap<String, Character>();
        String[] words = s.split(" ");
        
        if(words.length != pattern.length()) return false;
        
        for(int i=0;i<pattern.length();i++){
            if(map.containsKey(words[i]) == false){
                if(using[pattern.charAt(i)-'a'] == false){
                    using[pattern.charAt(i)-'a'] = true;
                    map.put(words[i],pattern.charAt(i));
                }else{
                    ans = false;
                    break;
                }
            }else{
                if(map.get(words[i])!=pattern.charAt(i)) {
                    ans = false;
                    break;
                }
            }
        }
        return ans;
    }
}
