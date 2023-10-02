class Solution {
public:
    bool winnerOfGame(string colors) {
        int alice_score = 0, bob_score = 0;

        for(int i = 1; i<colors.size()-1; i++){
            char curr_color = colors[i];
            char prev_color = colors[i-1];
            char next_color = colors[i+1];

            if(curr_color == 'A' && prev_color == 'A' && next_color == 'A'){
                alice_score++;
            } 
            else if(curr_color == 'B' && prev_color == 'B' && next_color == 'B'){
                bob_score++;
            } 

            
        }

        return alice_score > bob_score;
    }
};