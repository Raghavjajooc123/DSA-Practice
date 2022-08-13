class MyStack {
public:
    // queue<int> q1;
    // queue<int> q2;
    
    queue<int> q;
    int n = 0;
    
    MyStack() {
        
    }
    
    void push(int x) {
        //using 2 queues
        // while(!q1.empty()){
        //     q2.push(q1.front());
        //     q1.pop();
        // }
        // q1.push(x);
        // while(!q2.empty()){
        //     q1.push(q2.front());
        //     q2.pop();
        // }
        
        //using single queue
        q.push(x);
        for(int i=0; i<n; i++){
            q.push(q.front());
            q.pop();
        }
        n++;
        return;
    }
    
    int pop() {
        // int temp = q1.front();
        // q1.pop();
        // return temp;
        
        int temp = q.front();
        q.pop();
        n--;
        return temp;
    }
    
    int top() {
        // return q1.front();
        
        return q.front();
    }
    
    bool empty() {
        // return q1.empty();
        
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
