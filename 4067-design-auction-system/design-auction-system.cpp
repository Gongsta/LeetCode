class AuctionSystem {
    using Key = pair<int,int>; // (userId, itemId)

    map<Key, int> useritem_to_amount;
    map<int, priority_queue<pair<int,int>>> item_to_user; // (amount, userId)

public:
    void addBid(int userId, int itemId, int bidAmount) {
        useritem_to_amount[{userId, itemId}] = bidAmount;
        item_to_user[itemId].push({bidAmount, userId});
    }

    void updateBid(int userId, int itemId, int newAmount) {
        useritem_to_amount[{userId, itemId}] = newAmount;
        item_to_user[itemId].push({newAmount, userId});
    }

    void removeBid(int userId, int itemId) {
        useritem_to_amount.erase({userId, itemId});
    }

    int getHighestBidder(int itemId) {
        auto itItem = item_to_user.find(itemId);
        if (itItem == item_to_user.end()) return -1;

        auto &pq = itItem->second;
        while (!pq.empty()) {
            auto [amt, user] = pq.top();

            auto it = useritem_to_amount.find({user, itemId});
            if (it != useritem_to_amount.end() && it->second == amt) {
                return user; // valid top
            }
            pq.pop(); // stale
        }
        return -1;
    }
};
