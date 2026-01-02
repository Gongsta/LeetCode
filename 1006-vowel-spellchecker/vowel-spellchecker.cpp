class Solution {
public:
    static inline char lowerChar(char c) {
        return (char)std::tolower((unsigned char)c);
    }

    static inline bool isVowelLower(char c) {
        // c is assumed lowercase
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
    }

    static string toLowerStr(const string& s) {
        string t = s;
        for (char &c : t) c = lowerChar(c);
        return t;
    }

    static string devowel(const string& s) {
        string t = s;
        for (char &c : t) {
            c = lowerChar(c);
            if (isVowelLower(c)) c = '*';
        }
        return t;
    }

    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> exact;
        unordered_map<string, string> lowerMap;
        unordered_map<string, string> vowelMap;

        exact.reserve(wordlist.size() * 2);
        lowerMap.reserve(wordlist.size() * 2);
        vowelMap.reserve(wordlist.size() * 2);

        // build maps using FIRST occurrence only
        for (const string& w : wordlist) {
            exact.insert(w);

            string lw = toLowerStr(w);
            if (!lowerMap.count(lw)) lowerMap[lw] = w;

            string vw = devowel(w);
            if (!vowelMap.count(vw)) vowelMap[vw] = w;
        }

        vector<string> ans;
        ans.reserve(queries.size());

        for (const string& q : queries) {
            if (exact.count(q)) {
                ans.push_back(q);
                continue;
            }

            string lq = toLowerStr(q);
            auto it1 = lowerMap.find(lq);
            if (it1 != lowerMap.end()) {
                ans.push_back(it1->second);
                continue;
            }

            string vq = devowel(q);
            auto it2 = vowelMap.find(vq);
            if (it2 != vowelMap.end()) {
                ans.push_back(it2->second);
                continue;
            }

            ans.push_back("");
        }

        return ans;
    }
};
