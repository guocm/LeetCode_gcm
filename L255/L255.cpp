class Stack {
public:
    // Push element x onto stack.
    queue<int>first;
    queue<int>second;
    void push(int x) {
        if (first.size() == 0){
            first.push(x);
        }else{
            while (first.size() > 0){
                second.push(first.front());
                first.pop();
            }
            first.push(x);
            while (second.size() > 0){
                first.push(second.front());
                second.pop();
            }
        }
    }

    // Removes the element on top of the stack.
    void pop() {
        first.pop();
    }

    // Get the top element.
    int top() {
        return first.front();
    }

    // Return whether the stack is empty.
    bool empty() {
        return first.empty();
    }
};