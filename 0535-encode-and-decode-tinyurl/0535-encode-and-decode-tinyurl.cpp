class Solution {
public:

    map<string, string> encoding;
    map<string, string> decoding;
    string generateRandomString() {
        string s;
        for (int i=0;i<7;i++) {
            s += rand() % 26 + 'a';
        }
        return s;
    }
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string random_string = generateRandomString();
        while (decoding.count(random_string)) {
            random_string = generateRandomString();
        }
        encoding[longUrl] = random_string;
        decoding[random_string] = longUrl;
        
        return encoding[longUrl];
        
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return decoding[shortUrl];
        
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));