class Twitter {
public:
    unordered_map<int,unordered_set<int>>friends;  // userid->set of people he follow
    priority_queue<vector<int>> newsfeed;
    // newsfeed={count,tweetid,userid}
    int count;
    
    Twitter() {
    count=0;
    friends.clear();
    newsfeed=priority_queue<vector<int>>();    
    }
    
    void postTweet(int userid, int tweetid) {
        newsfeed.push({count++,tweetid,userid});
    }
    
    vector<int> getNewsFeed(int userid) {
        priority_queue<vector<int>> pq=this->newsfeed;    //copy of newsfeed
        int k=0;
        vector<int> ans;
        while(k<10 and !pq.empty())
        {
            vector<int> temp=pq.top();
            pq.pop();
            if(temp[2]==userid or friends[userid].count(temp[2]))
            {
                ans.push_back(temp[1]);
                k++;
            }
        }
        return ans;
    }
    
    void follow(int followerid, int followeeid) {
        friends[followerid].insert(followeeid);
    }
    
    void unfollow(int followerid, int followeeid) {
        friends[followerid].erase(followeeid);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */