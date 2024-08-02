class TextEditor {
public:
    string before, after;

    // Constructor
    TextEditor() {}

    // Appends the given text to the end of the 'before' string
    void addText(string text) {
        before.insert(end(before), begin(text), end(text));
    }

    // Deletes up to 'k' characters from the left of the cursor
    int deleteText(int k) {
        k = min(k, (int)before.size()); // Ensures 'k' does not exceed the length of 'before'
        before.resize(before.size() - k); // Resizes 'before', removing 'k' characters from the end
        return k; // Returns the number of characters actually deleted
    }

    // Moves the cursor 'k' positions to the left
    string cursorLeft(int k) {
        while(k-- && !before.empty()) {
            after.push_back(before.back()); // Moves the last character of 'before' to 'after'
            before.pop_back(); // Removes the last character from 'before'
        }
        return before.substr(before.size() - min((int)before.size(), 10)); // Returns the last 10 characters of 'before'
    }

    // Moves the cursor 'k' positions to the right
    string cursorRight(int k) {
        while(k-- && !after.empty()) {
            before.push_back(after.back()); // Moves the last character of 'after' to 'before'
            after.pop_back(); // Removes the last character from 'after'
        }
        return before.substr(before.size() - min((int)before.size(), 10)); // Returns the last 10 characters of 'before'
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */
