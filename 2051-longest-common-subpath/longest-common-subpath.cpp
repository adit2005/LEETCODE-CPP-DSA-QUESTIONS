class Solution
{
public:
    // Function to check if there exists a common subpath of length L
    bool isValid(int L, vector<vector<int>> &paths)
    {
        const long long MODULO = 1e11 + 7; // Large prime for modulo
        const long long X = 133331;       // Base for rolling hash
        long long hashMultiplier = 1;

        // Precompute the multiplier for hash removal
        for (int i = 0; i < L - 1; ++i)
            hashMultiplier = (hashMultiplier * X) % MODULO;

        map<long long, int> hashCounts; // Hash map to track subpath hashes

        // Process the first path
        auto &firstPath = paths[0];
        long long currentHash = 0;

        for (int i = 0; i < firstPath.size(); ++i)
        {
            // Compute rolling hash
            currentHash = (currentHash * X + firstPath[i]) % MODULO;

            // When we reach a subpath of length L, start hashing
            if (i >= L - 1)
            {
                hashCounts[currentHash] = 1; // Mark this hash as seen in path 0

                // Remove the oldest element from the hash
                currentHash = (currentHash - firstPath[i - L + 1] * hashMultiplier % MODULO + MODULO) % MODULO;
            }
        }

        // Process remaining paths
        for (int pathIndex = 1; pathIndex < paths.size(); ++pathIndex)
        {
            auto &currentPath = paths[pathIndex];
            currentHash = 0;
            map<long long, int> currentHashCounts;

            for (int i = 0; i < currentPath.size(); ++i)
            {
                // Compute rolling hash for current path
                currentHash = (currentHash * X + currentPath[i]) % MODULO;

                if (i >= L - 1)
                {
                    // Only consider hashes that exist in previous paths
                    if (hashCounts.find(currentHash) != hashCounts.end() && hashCounts[currentHash] == pathIndex)
                        currentHashCounts[currentHash] = pathIndex + 1;

                    // Remove the oldest element from the hash
                    currentHash = (currentHash - currentPath[i - L + 1] * hashMultiplier % MODULO + MODULO) % MODULO;
                }
            }

            // Update the global hashCounts map for valid hashes
            for (auto &entry : currentHashCounts)
                hashCounts[entry.first] = entry.second;
        }

        // Check if any hash is common across all paths
        for (auto &entry : hashCounts)
        {
            if (entry.second == paths.size())
                return true;
        }

        return false;
    }

    // Comparator to sort paths by length
    static bool compare(const vector<int> &a, const vector<int> &b)
    {
        return a.size() < b.size();
    }

    // Function to find the longest common subpath
    int longestCommonSubpath(int n, vector<vector<int>> &paths)
    {
        int left = 0, right = paths[0].size() + 1; // Binary search bounds
        int bestLength = 0;

        // Sort paths by length to optimize search range
        sort(paths.begin(), paths.end(), compare);

        // Binary search on the length of the common subpath
        while (right - left > 1)
        {
            int mid = (left + right) / 2; // Test length
            if (isValid(mid, paths))
            {
                bestLength = mid; // Update best length
                left = mid;       // Search in the larger range
            }
            else
            {
                right = mid; // Search in the smaller range
            }
        }

        return bestLength;
    }
};
