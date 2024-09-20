class Solution {
public:
    int dist(int x1, int y1, int x2, int y2) {
        return ((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2));
    }

    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<pair<int, int>> p;
        p.push_back({p1[0], p1[1]});
        p.push_back({p2[0], p2[1]});
        p.push_back({p3[0], p3[1]});
        p.push_back({p4[0], p4[1]});
        sort(p.begin(), p.end());

        int d1 = dist(p[0].first, p[0].second, p[1].first, p[1].second);
        int d2 = dist(p[1].first, p[1].second, p[3].first, p[3].second);
        int d3 = dist(p[3].first, p[3].second, p[2].first, p[2].second);
        int d4 = dist(p[2].first, p[2].second, p[0].first, p[0].second);

        int d5 = dist(p[0].first, p[0].second, p[3].first, p[3].second);
        int d6 = dist(p[1].first, p[1].second, p[2].first, p[2].second);

        return (d1 == d2) && (d2 == d3) && (d3 == d4) && (d4 == d1) && (d5 == d6) && (d1 != 0);
    }
};