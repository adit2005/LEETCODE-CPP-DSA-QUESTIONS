class Solution {
public:
	// Returns the set bit for a character.
    int getHash(char &c) {
        return 1<<(c-'a');
    }
    long long wonderfulSubstrings(string word) {
		// Stores prefix parities.
        unordered_map<int,int> count={{0,1}};
		int running=0;
        long long result=0;
        for(char &w:word) {
			// Update the running parity
            running^=getHash(w);
			
			// Add counts of substrings with at most character `c` of odd counts.
			// As seen in observation we need count of prefix parities with opposite parity of character we are considering for odd count.
			// The rest remains same as we want even count for all other characters.
			// Here we are checking all possible characters, however it can be obtimized to check characters only present in the input word.
            for(char c='a';c<='j';c++)
                result+=count[running^getHash(c)];
				
			// Add counts of substrings with all characters with even counts.
			// As seen in observation we need count of prefix parities with same parities as current running parity.
            result+=count[running];
			
			// Update the counts for next future iterations.
            count[running]++;
        }
        return result;
    }
};