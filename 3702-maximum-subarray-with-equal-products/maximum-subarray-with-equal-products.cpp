#include <vector>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <set>
using namespace std;

class Solution {
public:
    int maxLength(vector<int>& A) {
        int N = A.size();
        int ans = 2;
        unordered_map<int, int> last; // Tracks the last occurrence of each prime
        int i = 0;

        for (int j = 0; j < N; ++j) {
            int x = A[j];
            vector<int> primes = primeDivisors(x);
            for (int p : primes) {
                i = max(i, last.count(p) ? last[p] + 1 : 0);
                last[p] = j;
            }
            ans = max(ans, j - i + 1);
        }

        return ans;
    }

private:
    vector<int> primeDivisors(int x) {
        vector<int> primes;
        int d = 2;

        // Check for divisors up to sqrt(x)
        while (d * d <= x) {
            if (x % d == 0) {
                primes.push_back(d);
                // Divide x by d until it's no longer divisible by d
                while (x % d == 0) {
                    x /= d;
                }
            }
            d += (d == 2 ? 1 : 2); // Move to the next odd number after 2
        }

        // If x is still greater than 1, it's a prime number
        if (x > 1) {
            primes.push_back(x);
        }

        return primes;
    }
};
