class AuctionSystem {
    unordered_map<int, unordered_map<int,int>> useritem_to_amount;
    unordered_map<int, set<pair<int, int>, greater<pair<int, int>>>> item_to_user;
public:
    AuctionSystem() {
    }
    
    void addBid(int userId, int itemId, int bidAmount) {
        if (useritem_to_amount[itemId].count(userId)) {
            updateBid(userId, itemId, bidAmount);
        } else {
            useritem_to_amount[itemId][userId] = bidAmount;
            item_to_user[itemId].insert({bidAmount, userId});
        }
    }
    
    void updateBid(int userId, int itemId, int newAmount) {
        int bidAmount = useritem_to_amount[itemId][userId];
        useritem_to_amount[itemId][userId] = newAmount;
        item_to_user[itemId].erase({bidAmount, userId});
        item_to_user[itemId].insert({newAmount, userId});
    }
    
    void removeBid(int userId, int itemId) {
        int amnt = useritem_to_amount[itemId][userId];
        useritem_to_amount[itemId].erase(userId);
        item_to_user[itemId].erase({amnt, userId});
    }
    
    int getHighestBidder(int itemId) {
        if (item_to_user[itemId].size() == 0) return -1;
        return item_to_user[itemId].begin()->second;
    }
};

/**
 * Your AuctionSystem object will be instantiated and called as such:
 * AuctionSystem* obj = new AuctionSystem();
 * obj->addBid(userId,itemId,bidAmount);
 * obj->updateBid(userId,itemId,newAmount);
 * obj->removeBid(userId,itemId);
 * int param_4 = obj->getHighestBidder(itemId);
 */