struct MinStackElement{
    int minVal;
    int val;
};

class MinStack {
public:
    /** initialize your data structure here. */
    vector<MinStackElement> minstack;
    int topIndex;
    
    MinStack() {
        topIndex = 0;
    }
    
    void push(int val) {
        if(minstack.size()<=topIndex){
            MinStackElement temp;
            temp.val = val;
            if(topIndex==0) temp.minVal = val;
            else temp.minVal = min(val, minstack[topIndex-1].minVal);
            minstack.push_back(temp);
        }else{
            minstack[topIndex].val = val;
            if(topIndex==0) minstack[topIndex].minVal = val;
            else minstack[topIndex].minVal = min(val, minstack[topIndex-1].minVal);
        }
        topIndex++;
    }
    
    void pop() {
        topIndex--;
    }
    
    int top() {
        return minstack[topIndex-1].val;
    }
    
    int getMin() {
        return minstack[topIndex-1].minVal;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
