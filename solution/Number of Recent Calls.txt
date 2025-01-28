class RecentCounter {
public:

std::queue<int> ans;
    RecentCounter() {
        //no additional initialization required
    }
    
    int ping(int t) {

        ans.push(t);//add the new request time to the queue

       // Remove all requests that are outside the range [t - 3000, t]
        while(ans.front() < t - 3000){
            ans.pop();
        }

        return ans.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */