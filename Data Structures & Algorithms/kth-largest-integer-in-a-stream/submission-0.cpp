class KthLargest {
private:
    vector<int> els;
    int k;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k=k;
        this->els=nums;
        
    }
    
    int add(int val) {
        els.push_back(val);
        sort(els.begin(),els.end(),greater<int>());
        return els[k-1];
        
    }
};
