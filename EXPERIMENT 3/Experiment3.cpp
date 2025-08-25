class Solution {
  public:
    vector<vector<int>> countFreq(vector<int>& arr) {
        // code here
        unordered_map<int,int> mp;
        for(int i=0;i<arr.size();i++) mp[arr[i]]++;
        vector<vector<int>> ans(mp.size(),vector<int>(2));
        int index=0;
        for(auto it:mp){
            ans[index][0]=it.first;
            ans[index][1]=it.second;
            index++;
        }
        return ans;
        
    }
};