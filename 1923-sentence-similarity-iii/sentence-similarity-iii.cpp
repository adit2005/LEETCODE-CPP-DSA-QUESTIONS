class Solution {
public:
    bool areSentencesSimilar(std::string s1, std::string s2) {
        std::istringstream iss1(s1);
        std::deque<std::string> deque1(
            (std::istream_iterator<std::string>(iss1)),
            std::istream_iterator<std::string>());
        std::istringstream iss2(s2);
        std::deque<std::string> deque2(
            (std::istream_iterator<std::string>(iss2)),
            std::istream_iterator<std::string>());
        // Compare the prefixes or beginning of the strings.
        while (!deque1.empty() && !deque2.empty() &&
               deque1.front() == deque2.front()) {
            deque1.pop_front();
            deque2.pop_front();
        }
        // Compare the suffixes or ending of the strings.
        while (!deque1.empty() && !deque2.empty() &&
               deque1.back() == deque2.back()) {
            deque1.pop_back();
            deque2.pop_back();
        }
        return deque1.empty() || deque2.empty();
    }
};