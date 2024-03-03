class Solution {
public:
    
    int countSubmatrices(vector<vector<int>>& v, int k) {
        int r = v.size(), c = v[0].size();
        
	for(int i=1;i<c;i++) {
		v[0][i] += v[0][i-1];
	}

	for(int i=1;i<r;i++) {
		v[i][0] += v[i-1][0];
	}


	for(int i=1;i<r;i++) {
		for(int j=1;j<c;j++) {
			v[i][j] += v[i-1][j]+v[i][j-1]-v[i-1][j-1];
		}
	}
        int ans =0;
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(v[i][j]<=k) ans++;
            }
        }
        return ans;
    }
};