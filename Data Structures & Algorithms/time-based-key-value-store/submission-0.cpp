class TimeMap {
private:
    unordered_map<string,vector<pair<string,int>>> t_map;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        
        t_map[key].push_back({value,timestamp});
    }
    
    string get(string key, int timestamp) {
        if(t_map.find(key) == t_map.end()) return "";

        int low = 0;
        int high = t_map[key].size()-1;
        int mid = 0;
        string result = "";
        vector<pair<string,int>>& entries = t_map[key];

        while(low<=high){
            mid = (high + low) / 2;

            if(entries[mid].second <= timestamp){
                result = entries[mid].first;
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }

        
        return result;
    }
};

/*
* What is known: 
* There are no parameters passed to the TimeMap constructor so the hashmap is initialized to default 0 upon creation of the object.
* The set function can either add a new key-value pair or append a new value to an existing key.
* The value in the map is a vector<pair<string,int>> where the string represents the true value and the int is the timestamp the pair was entered.
* The get function takes in a key and a timestamp as parameters and returns the value string inside the value pair.
* If the timestamp passed as a parameter is not present in the pair then the latest timestamp such that timestamp_prev<=timestamp is called and its associated value is returned.
*
* 
*     
*/