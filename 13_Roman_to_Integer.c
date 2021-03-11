
int romanToInt(char * s){
    int ans = 0;
    int idx = 0,ridx=0;
    char replace[4001];
    for(idx; s[idx]!='\0';idx++){
        if(s[idx+1]!='\0'){
            if(s[idx] == 'I')
            {
                if(s[idx+1]=='V') idx+=1, replace[ridx++] = 'A';  
                else if(s[idx+1]=='X') idx+=1, replace[ridx++] = 'B';
                else replace[ridx++] = s[idx];
            }else if(s[idx] == 'X'){
                if(s[idx+1]=='L') idx+=1, replace[ridx++] = 'E';  
                else if(s[idx+1]=='C') idx+=1, replace[ridx++] = 'F';
                else replace[ridx++] = s[idx];
            }else if(s[idx] == 'C'){
                if(s[idx+1]=='D') idx+=1, replace[ridx++] = 'G';  
                else if(s[idx+1]=='M') idx+=1, replace[ridx++] = 'H';
                else replace[ridx++] = s[idx];
            }else{
                replace[ridx++] = s[idx];
            }
        }else{
            replace[ridx++] = s[idx];
            replace[ridx] = '\0';
        }
    }
    for(idx = 0; idx<ridx; idx++){
        if(replace[idx] == 'A') ans += 4;
        else if(replace[idx] == 'B') ans += 9;
        else if(replace[idx] == 'C') ans += 100;
        else if(replace[idx] == 'D') ans += 500;
        else if(replace[idx] == 'E') ans += 40;
        else if(replace[idx] == 'F') ans += 90;
        else if(replace[idx] == 'G') ans += 400;
        else if(replace[idx] == 'H') ans += 900;
        else if(replace[idx] == 'I') ans += 1;
        else if(replace[idx] == 'V') ans += 5;
        else if(replace[idx] == 'X') ans += 10;
        else if(replace[idx] == 'L') ans += 50;
        else if(replace[idx] == 'M') ans += 1000;   
    }
    return ans;
}
