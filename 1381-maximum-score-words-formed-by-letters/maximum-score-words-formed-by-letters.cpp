class Solution {
public:
    int helper(vector<string>& words, int curr, vector<char> letters, vector<int>& score){
		//base case: there is no element
        if(curr<0)return 0;
		//using unordered_maps as they have better time complexity than normal  map by a factor of log(N)
        unordered_map<char, int>curr_dict, curr_word, remaining;
		//converting the  current word in consideration and the letter vector in key value format:
		// where keys are alphabets and values are their frequency
        for(int i=0;i<letters.size();i++){
            curr_dict[letters[i]]++;
        }
        for(int i=0;i<words[curr].size();i++){
            curr_word[words[curr][i]]++;
        }		
        vector<char>letters_rem;
        remaining=curr_dict;
        int flag=1;
		//checking if curr_word can be constructed using the letters vectorby comparing frequency of alphabets
        for(auto temp:curr_word){
            if(curr_dict[temp.first]<temp.second){
                flag=0;
                break;
            }
            remaining[temp.first]-=temp.second;
        }
		//if the current word cannot be constructed, we will simply pass it
        if(flag==0){
            return helper(words, curr-1, letters, score);
        }
		//now comes the case where the current word can be constructed. We have 2 options either construct the
		//word(receive some score, and reduce the letters vector) or simply pass it
		//calculating the score received for constructing the word
        int curr_score=0;
        for(int i=0;i<words[curr].size();i++){
            curr_score+=score[words[curr][i]-'a'];
        }
		//creating a new vector after reducing the alphabets used for making the current word
        for(auto temp:remaining){
            for(int i=0;i<temp.second;i++)
                letters_rem.emplace_back(temp.first);
        }
		//calling on the next word with reduced letters vector and adding the score 
        int ans2=helper(words, curr-1, letters_rem, score)+curr_score;        
		//returning the maximum value for the two options we had if current wor can be constructed
        return max(helper(words, curr-1, letters, score), ans2);
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
		//will iterate from last element to first.
        return helper(words, words.size()-1, letters, score);        
    }
};