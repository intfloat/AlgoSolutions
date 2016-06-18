typedef pair<int, int> pii;
class Twitter {
private:
    map<int, set<pii> > tweets;
    map<int, set<int> > follow_map;
    int time;
public:
    /** Initialize your data structure here. */
    Twitter() {
        this->time = 0;
    }

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        tweets[userId].insert({-(this->time), tweetId});
        ++(this->time);
        follow_map[userId].insert(userId);
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        set<pii> res;
        set<int>& st = follow_map[userId];
        for (auto it = st.begin(); it != st.end(); ++it) {
            set<pii> tws = tweets[*it];
            int n = min(10, (int)tws.size());
            auto ptr = tws.begin();
            for (int i = 0; i < n; ++i) {
                res.insert(*ptr);
                while (res.size() > 10) {
                    res.erase(*res.rbegin());
                }
                ++ptr;
            }
        }
        vector<int> ret;
        for (auto e : res) {
            ret.push_back(e.second);
        }
        return ret;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        follow_map[followerId].insert(followeeId);
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if (followerId == followeeId) {
            return;
        }
        follow_map[followerId].erase(followeeId);
    }
};
