class CustomStack {
private:
    // Vector to store stack elements
    vector<int> stackArray;

    // Vector to store increments for lazy propagation
    vector<int> incrementArray;

    // Current top index of the stack
    int topIndex;

public:
    CustomStack(int maxSize) {
        stackArray.resize(maxSize);
        incrementArray.resize(maxSize);
        topIndex = -1;
    }

    void push(int x) {
        if (topIndex < (int)(stackArray.size()) - 1) {
            stackArray[++topIndex] = x;
        }
    }

    int pop() {
        if (topIndex < 0) {
            return -1;
        }

        // Calculate the actual value with increment
        int result = stackArray[topIndex] + incrementArray[topIndex];

        // Propagate the increment to the element below
        if (topIndex > 0) {
            incrementArray[topIndex - 1] += incrementArray[topIndex];
        }

        // Reset the increment for this position
        incrementArray[topIndex] = 0;

        topIndex--;
        return result;
    }

    void increment(int k, int val) {
        if (topIndex >= 0) {
            // Apply increment to the topmost element of the range
            int incrementIndex = min(topIndex, k - 1);
            incrementArray[incrementIndex] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */