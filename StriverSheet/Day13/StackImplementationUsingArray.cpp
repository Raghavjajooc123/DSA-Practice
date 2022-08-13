// Stack class.
class Stack {
    int * MyStack;
    int e = 0;
    int c;
    
public:
    
    Stack(int capacity) {
        c = capacity;
        MyStack = new int [capacity];
    }

    void push(int num) {
        // Write your code here.
        if(e >= c){
            return;
        }
        MyStack[e] = num;
        e++;
    }

    int pop() {
        if(e==0){
            return -1;
        }
        int temp = MyStack[--e];
        return temp;
    }
    
    int top() {
        if(e==0){
            return -1;
        }
        return MyStack[e-1];
    }
    
    int isEmpty() {
        return e==0;
    }
    
    int isFull() {
        return e==c;
    }
    
};
