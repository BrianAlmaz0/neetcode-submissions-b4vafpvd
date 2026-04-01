class TimeMap {
public:
    unordered_map<string, vector<pair<string, int>>> map;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        map[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        string result = "";
        if(map.find(key) == map.end()){
            return result;
        }
        auto& entries = map[key];
        int left = 0;
        int right = entries.size() - 1;
        
        while(left <= right){
            int middle = (left + right) / 2;

            if(entries[middle].second <= timestamp){
                result = entries[middle].first;
                left = middle + 1;
            } else{
                right = middle - 1;
            }
        }
        return result;
    }
};
