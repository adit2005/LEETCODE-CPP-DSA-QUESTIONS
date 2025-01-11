#include <vector>
#include <algorithm>
#include <unordered_set>
#include <map>

using namespace std;

class DSU {
    vector<int> parent, rank;
public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i) parent[i] = i;
    }
    
    int find(int x) {
        if (x != parent[x]) 
            parent[x] = find(parent[x]);
        return parent[x];
    }
    
    void unite(int x, int y) {
        int px = find(x), py = find(y);
        if (px != py) {
            if (rank[px] < rank[py]) {
                parent[px] = py;
            } else if (rank[px] > rank[py]) {
                parent[py] = px;
            } else {
                parent[py] = px;
                rank[px]++;
            }
        }
    }
    
    void reset(int x) {
        parent[x] = x;
    }
    
    bool connected(int x, int y) {
        return find(x) == find(y);
    }
};

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        // Sort meetings by time
        sort(meetings.begin(), meetings.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2];
        });

        DSU dsu(n);
        dsu.unite(0, firstPerson); // Person 0 shares the secret with firstPerson at time 0

        int i = 0;
        while (i < meetings.size()) {
            int currentTime = meetings[i][2];
            vector<pair<int, int>> currentMeetings;
            
            // Gather all meetings happening at the current time
            while (i < meetings.size() && meetings[i][2] == currentTime) {
                currentMeetings.push_back({meetings[i][0], meetings[i][1]});
                i++;
            }
            
            // Unite all people meeting at the current time
            unordered_set<int> participants;
            for (const auto& meeting : currentMeetings) {
                dsu.unite(meeting.first, meeting.second);
                participants.insert(meeting.first);
                participants.insert(meeting.second);
            }
            
            // Check which participants are connected to person 0
            for (int person : participants) {
                if (!dsu.connected(0, person)) {
                    dsu.reset(person);
                }
            }
        }
        
        // Collect all people connected to person 0
        vector<int> result;
        for (int person = 0; person < n; ++person) {
            if (dsu.connected(0, person)) {
                result.push_back(person);
            }
        }
        
        return result;
    }
};
