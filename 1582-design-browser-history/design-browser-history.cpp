class BrowserHistory {
public:
    
    // declare an array
    
    vector<string> arr;
    
    // declare a pointer
    
    int pointer = -1;
    
    BrowserHistory(string homepage) {
        
        // push the homepage into the array
        
        arr.push_back(homepage);
        
        // initialize the pointer
        
        pointer = 0;
    }
    
    void visit(string url) {
        
        // erase all the next pages next to the current page
        
        arr.erase(arr.begin() + pointer + 1, arr.end());
        
        // push the url into array
        
        arr.push_back(url);
        
        // update pointer
        
        pointer = arr.size() - 1;
    }
    
    string back(int steps) {
        
        // move back the pointer accordingly
        
        if(pointer - steps < 0)
        {
            pointer = 0;
        }
        else
        {
            pointer -= steps;
        }
        
        // return the result
        
        return arr[pointer];
    }
    
    string forward(int steps) {
        
        // movce forward the pointer accordingly
        
        if(pointer + steps >= arr.size())
        {
            pointer = arr.size() - 1;
        }
        else
        {
            pointer += steps;
        }
        
        // return the res
        
        return arr[pointer];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */