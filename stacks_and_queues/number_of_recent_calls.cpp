class RecentCounter {
private:
    queue<int> requestQueue;

public:
    RecentCounter() {
        
    }
    
    int ping(int t) {
        requestQueue.push(t);
        while(!requestQueue.empty() && requestQueue.front() < t - 3000) {
            requestQueue.pop();
        }
        return requestQueue.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
