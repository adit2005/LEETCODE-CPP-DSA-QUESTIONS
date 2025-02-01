#include <set>
#include <iterator>
using namespace std;

class ExamRoom {
public:
    int n;            // Total number of seats.
    set<int> seats;   // Sorted set to maintain occupied seats.

    ExamRoom(int n) : n(n) {
        // No further initialization required.
    }
    
    int seat() {
        // If the room is empty, seat the student at seat 0.
        if (seats.empty()) {
            seats.insert(0);
            return 0;
        }
        
        int candidate = 0;
        // Maximum distance initialized with the left edge distance.
        int maxDistance = *seats.begin();
        
        // Check the intervals between adjacent occupied seats.
        auto prev = seats.begin();
        for (auto it = next(seats.begin()); it != seats.end(); ++it) {
            // The potential seat is in the middle of two occupied seats.
            int d = (*it - *prev) / 2;
            if (d > maxDistance) {
                maxDistance = d;
                candidate = *prev + d;
            }
            prev = it;
        }
        
        // Check the right edge (distance from the last occupied seat to n-1).
        if (n - 1 - *seats.rbegin() > maxDistance) {
            candidate = n - 1;
        }
        
        // Insert the candidate seat into the set of occupied seats.
        seats.insert(candidate);
        return candidate;
    }
    
    void leave(int p) {
        // Remove the seat p from the set. It's guaranteed that p is occupied.
        seats.erase(p);
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */
