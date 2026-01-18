class AuctionSystem {
    map<pair<int,int>, int> useritem_to_amount;
    map<int, priority_queue<pair<int, int>>> item_to_user; 
public:
    AuctionSystem() {
        }
    
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
        int highest_user = -1;
        while (!item_to_user[itemId].empty()) {
            auto [amnt, user] = item_to_user[itemId].top();
            if (useritem_to_amount[{user, itemId}] == amnt) {
                highest_user = user;
                break;
            }
            item_to_user[itemId].pop();
        }
        return highest_user;
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