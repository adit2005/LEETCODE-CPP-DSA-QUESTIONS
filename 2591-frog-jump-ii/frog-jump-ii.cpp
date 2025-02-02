class Solution {
public:
    bool works(vector<int>& stones, int k) {
        int cur = 0;
        vector<int> newstones;
        set<int> chosen;
        while (cur + k < stones.back()) {
            auto it = upper_bound(stones.begin(), stones.end(), cur + k);
            it--;
            if (*it == cur)
                return false;
            cur = *it;
            chosen.insert(cur);
        }
        for (int i : stones) {
            if (chosen.count(i) == 0)
                newstones.push_back(i);
        }
        assert((int)newstones.size() >= 2);
        for (int i = 1; i < newstones.size(); i++) {
            if (newstones[i] - newstones[i - 1] > k)
                return false;
        }
        return true;
    }

    int maxJump(vector<int>& stones) {
        int lo = 0, hi = stones.back();
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (works(stones, mid))
                hi = mid;
            else
                lo = mid + 1;
        }
      //  assert(lo == hi);
        return lo;
    }
};