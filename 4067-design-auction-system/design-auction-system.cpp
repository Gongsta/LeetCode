// Dan4Life
// O(log n) per operation
#include <bits/stdc++.h>
using namespace std;

class AuctionSystem {
    unordered_map<int, unordered_map<int,int>> mp;
    unordered_map<int, set<pair<long long,int>>> st;

public:
    AuctionSystem() {}

    void addBid(int userId, int itemId, int bidAmount) {
        if (mp[itemId].count(userId)) {
            long long old = mp[itemId][userId];
            st[itemId].erase({old, userId});
        }
        mp[itemId][userId] = bidAmount;
        st[itemId].insert({bidAmount, userId});
    }

    void updateBid(int userId, int itemId, int newAmount) {
        long long old = mp[itemId][userId];
        st[itemId].erase({old, userId});
        mp[itemId][userId] = newAmount;
        st[itemId].insert({newAmount, userId});
    }

    void removeBid(int userId, int itemId) {
        long long old = mp[itemId][userId];
        st[itemId].erase({old, userId});
        mp[itemId].erase(userId);
    }

    int getHighestBidder(int itemId) {
        if (!st.count(itemId) || st[itemId].empty()) return -1;
        return prev(st[itemId].end())->second;
    }
};