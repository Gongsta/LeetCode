class Solution {
public:
    string predictPartyVictory(string senate) {
        int r_alive = 0;
        int d_alive = 0;
        queue<char> q;
        for (char c: senate) {
            if (c == 'R') {
                r_alive++;
            } else {
                d_alive++;
            }
            q.push(c);
        }
        int r_votes = 0;
        int d_votes = 0;
        while (d_alive > 0 && r_alive > 0) {
           auto c = q.front();q.pop();
           if (c == 'R') {
            if (d_votes > 0) {
                r_alive--;
                d_votes--;
            } else {
                r_votes++;
                q.push(c);
            }
           } else {
            if (r_votes > 0) {
                d_alive--;
                r_votes--;
            } else {
                d_votes++;
                q.push(c);
            }
           }
        }
        if (d_alive > 0) return "Dire";
        return "Radiant";

        
    }
};