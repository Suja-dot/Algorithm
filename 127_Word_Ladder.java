class Solution {
    public List<String> getNeighbors(char[] chars, Set<String> wordDic){
        List<String> neighbor = new ArrayList<>();
        for(int i=0;i<chars.length;i++){
            char curChar = chars[i];
            for(char c='a';c<='z';c++){
                if(c==curChar) continue;
                chars[i]=c;
                String curString = new String(chars);
                if(wordDic.contains(curString)){
                    neighbor.add(curString);
                }
            }
            chars[i] = curChar;
        }
        return neighbor;
    }
    
    public int bfs(String beginWord, String endWord, Set<String> wordDic){
        Queue<String> que = new LinkedList<>();
        Set<String> isVisit = new HashSet<>();
        que.offer(beginWord);
        isVisit.add(beginWord);
        int dep = 1;
        
        while(!que.isEmpty()){
            int size = que.size();
            for(int i=0;i<size;i++){
                String curStr = que.poll();
                char[] chars = curStr.toCharArray();
                for(String neighbor : getNeighbors(chars,wordDic)){
                    if(!isVisit.contains(neighbor)){
                        if(neighbor.equals(endWord)) return dep+1;
                        que.offer(neighbor);
                        isVisit.add(neighbor);
                    }
                }
            }
            dep++;
        }
        return 0;
    }
        
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        Set<String> wordDic = new HashSet<>(wordList);
        
        if(!wordDic.contains(endWord)){
            return 0;
        }
        return bfs(beginWord,endWord,wordDic);
    }
}
