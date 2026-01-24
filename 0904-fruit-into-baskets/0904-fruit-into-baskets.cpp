class Solution {
public:
    int totalFruit(vector<int>& s) {
        int k=2;
        int i=0;
       int j=0;
       unordered_map<int,int>mp;
       int mx=0;
       while(j<s.size()){
            mp[s[j]]++;
            if(mp.size()<k){
                j++;
            }
            else if(mp.size()==k){
                mx=max(mx,j-i+1);
                j++;
            }
            else if(mp.size()>k){
                while(mp.size()>k){
                   mp[s[i]]--;
                   if(mp[s[i]]==0){
                       mp.erase(s[i]);
                   }
                   i++;
                }
            j++;
            }
        }

        return mx;
        
    }
};