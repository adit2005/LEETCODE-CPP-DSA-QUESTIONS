class LUPrefix {
    private:
vector<int> v;
int i;

public:
    LUPrefix(int n) {
         v.resize(n+1);
	//take i from start
    i=0;
    }
    
    void upload(int video) {
        //upload it to the previous index so we can track it
    v[video-1]=1;

    }
    
    int longest() {
        // increase the index until we get the empty slot
    while(v[i]==1){
        i++;
    }
    return i;

    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */