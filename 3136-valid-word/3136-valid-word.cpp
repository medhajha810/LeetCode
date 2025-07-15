class Solution {
public:
    bool isValid(string word) {
        if (word.size() < 3) return false;

        bool hasVowel = false;
        bool hasConsonant = false;

        for (char ch : word) {
            if (!std::isalnum(static_cast<unsigned char>(ch))) {
                return false; // Contains invalid characters
            }

            if (std::isalpha(ch)) {
                char lower = std::tolower(ch);
                if (lower == 'a' || lower == 'e' || lower == 'i' ||
                    lower == 'o' || lower == 'u') {
                    hasVowel = true;
                } else {
                    hasConsonant = true;
                }
            }
        }

        return hasVowel && hasConsonant;
    }
};
