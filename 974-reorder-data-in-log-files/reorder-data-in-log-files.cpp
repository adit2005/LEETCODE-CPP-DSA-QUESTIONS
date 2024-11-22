class Solution {
public:
	//compare function
    static bool compare(string s1,string s2){
		//get the substrings after the first white space character
        string aa = s1.substr(s1.find(' '));
        string bb = s2.substr(s2.find(' '));
        
		//if the substrings are equal, decide the order based on , else decide with respect to substrings
        return aa == bb ? s1 < s2 : aa < bb;
    }
	
	//main function
    vector<string> reorderLogFiles(vector<string>& logs) {
        
		//result vector
        vector<string> result;
        int count = 0;
        
		//iterate over the logs vector once
        for(auto log : logs){
			//if it's worded -> insert in front of the result
            if(log.back() <= 'z' and log.back() >= 'a') result.insert(result.begin(),log),count++;
			//else insert back
            else result.push_back(log);
        }
        
		//sort the first "count" number of elements
        sort(result.begin(),result.begin()+count,compare);
		//return the result
        return result;
    }
};