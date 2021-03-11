typedef struct{
    int index;
    int flag;
} pair;

int lengthOfLongestSubstring(char * s){
    pair alpha[130];
    int i,j,res=0,len=0;
    for(i=0;i<130;++i) alpha[i].index = -1, alpha[i].flag = 0;
    for(i=0;s[i]!='\0';i++){
        int index = s[i];
        if(alpha[index].flag == 0){
            alpha[index].flag = 1;
            alpha[index].index = i;
            len++;
        }else{
            if(res < len) res = len;
            for(j=0;j<130;++j){
                if(alpha[j].flag == 1 && alpha[j].index < alpha[index].index){
                    alpha[j].flag = 0;
                    alpha[j].index = -1;
                    len--;
                }
            }
            alpha[index].index = i;
        }
    }
    if(res<len) res = len;
    return res;
}
