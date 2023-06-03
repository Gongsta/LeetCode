class UndergroundSystem {
public:
    map<int, pair<string, int>> check_ins;
    map<pair<string, string>, vector<int>> averageTime;
    
    UndergroundSystem() {
    }
    
    void checkIn(int id, string stationName, int t) {
        check_ins[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        pair<string, int> p = check_ins[id];
        averageTime[{p.first, stationName}].push_back(t - p.second);
    }
    
    double getAverageTime(string startStation, string endStation) {
        vector<int>& times = averageTime[{startStation, endStation}];
        double n = times.size();
        double sum = 0;
        for (int time : times) {
            sum += time;
        }
        return sum / n;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */