

bool isValid(char * s){
    bool flag = true;
    char stack[10001];
    int i,head,tail;
    head = tail = 0;
    for(i=0;s[i]!='\0';i++){
        if(s[i] == '(' || s[i] == '{' || s[i] == '['){
            stack[tail++] = s[i];
        }
        else{
            if(tail <= 0) return false; 
            else if(s[i]==')'){
                if(stack[--tail] == '(');
                else flag = false;
            }
            else if(s[i]=='}'){
                if(stack[--tail] == '{');
                else flag = false;
            }
            else if(s[i]==']'){
                if(stack[--tail] == '[');
                else flag = false;
            }
        }
    }
    if(head != tail) flag = false;
    return flag;
}
