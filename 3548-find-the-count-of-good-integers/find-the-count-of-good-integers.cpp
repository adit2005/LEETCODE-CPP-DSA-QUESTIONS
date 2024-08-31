#define ll long long 
ll ans; // Variable to store the final answer
vector<ll> fact; // Vector to store factorials for combinatorial calculations
unordered_map<string, int> vis; // Map to keep track of digit frequency strings to avoid duplicates

// Function to generate a palindrome from the first half of the number
string genpal(ll num, ll val) {
    string s = to_string(num); // Convert the number to string
    string t = s.substr(0, val); // Take the first half of the string
    reverse(t.begin(), t.end()); // Reverse the substring to form the second half of the palindrome
    
    s += t; // Concatenate the reversed substring to form the full palindrome
    return s; // Return the generated palindrome
}

// Function to check if a number represented by a string is divisible by k
bool check(string &s, int k) {    
    ll val = 0; // Variable to store the number value
    for (char c : s) { // Iterate through each character of the string
        ll curr = c - '0'; // Convert character to its numeric value
        val = val * 10 + curr; // Build the number from its digits
    }
    
    return val % k == 0; // Check if the number is divisible by k
}

// Function to count permutations of the string s that do not start with zero
ll count(string &s) {
    vector<ll> fr(10, 0); // Frequency array for digits 0-9
    ll n = s.length(); // Length of the string
    
    if (n == 1) return 1; // If length is 1, there's only one permutation

    for (char c : s) { // Count frequency of each digit
        ll curr = c - '0'; // Convert character to its numeric value
        fr[curr]++;
    }
    
    ll tot = fact[n]; // Total permutations (n!)
    string str = ""; // Create a string representing the digit frequencies
    
    for (int i = 0; i < fr.size(); ++i) { // Build the frequency string
        ll curr = fr[i];
        str += ('a' + curr); // Append frequency count to the string
        if (curr != 0) tot = tot / fact[curr]; // Divide by factorial of digit counts to handle duplicates
    }
    
    if (vis.find(str) != vis.end()) return 0; // If digit frequency string is already seen, return 0
    vis[str] = 1; // Mark the digit frequency string as seen
    
    if (fr[0] == 0) return tot; // If there are no leading zeros, return total permutations

    // Count permutations with leading zeros removed
    ll a = fact[n - 1]; // (n-1)!
    a = a / fact[fr[0] - 1]; // Divide by (count of leading zeros - 1)!
    for (int i = 1; i < fr.size(); ++i) {
        ll curr = fr[i];
        if (curr != 0) a = a / fact[curr]; // Adjust for other digit counts
    }
    
    ll res = tot - a; // Subtract permutations with leading zeros from total
    return res; // Return the count of valid permutations
}

// Function to recursively generate all numbers of length len and check them
void find(int pos, int num, int len, int stat, int k) {
    if (pos == len) { // Base case: If position equals length, process the number
        ll val;
        if (stat == 1) val = len - 1; // If length is odd, exclude the middle digit
        else if (stat == 0) val = len; // If length is even, use full length
        
        string s = genpal(num, val); // Generate palindrome
        bool st = check(s, k); // Check if palindrome is divisible by k
        
        if (st) ans += count(s); // If divisible, add valid permutations count to answer
        
        return; // Return to previous state
    }

    if (pos == 0) { // If at the beginning, digits must be from 1 to 9 (no leading zeros)
        for (int i = 1; i <= 9; ++i) {
            int tnum = num * 10 + i; // Form new number
            find(pos + 1, tnum, len, stat, k); // Recursively generate the next digit
        }
    } else { // For other positions, digits can be from 0 to 9
        for (int i = 0; i <= 9; ++i) {
            int tnum = num * 10 + i; // Form new number
            find(pos + 1, tnum, len, stat, k); // Recursively generate the next digit
        }
    }

    return; // Return to previous state
}

class Solution {
public:
    long long countGoodIntegers(int n, int k) {
        ll len;
        ans = 0; // Initialize answer
        
        int stat;
        
       // fact.clear(); // Clear previous factorials
        vis.clear(); // Clear previous visited strings

        fact.push_back(1); // 0! = 1
        ll curr = 1;
        for (ll i = 2; i <= 11; ++i) { // Compute factorials up to 11!
            fact.push_back(curr);
            curr = curr * i;
        }

        if (n % 2 == 1) { // If n is odd, generate palindromes of length (n/2 + 1)
            len = n / 2 + 1;
            stat = 1; // Odd length
        } else { // If n is even, generate palindromes of length n/2
            len = n / 2;
            stat = 0; // Even length
        }

        find(0, 0, len, stat, k); // Start generating numbers
        return ans; // Return the count of good integers
    }
};
