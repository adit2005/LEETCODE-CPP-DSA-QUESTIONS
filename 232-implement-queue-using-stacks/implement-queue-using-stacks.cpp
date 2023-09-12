class MyQueue {
public:
stack < int > input, output;
    MyQueue() {
        
    }
    
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
      if (output.empty())
      while (input.size())
      output.push(input.top()), input.pop();

      int x = output.top();
      output.pop();
      return x;
    }
    
    int peek() {
        if (output.empty())
      while (input.size())
        output.push(input.top()), input.pop();
    return output.top();
  }

    int size() {
    return (output.size() + input.size()); 
    }
    
    bool empty() {
        return input.empty() && output.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */