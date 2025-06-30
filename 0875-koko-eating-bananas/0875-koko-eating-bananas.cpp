class Solution {
public:
    bool speed(vector<int>& piles, int mid, int h){
        long long hour=0;
        for(int i=0;i<piles.size();i++){
            hour+=(piles[i]+mid-1)/mid;
        }
        return hour<=h;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=1e9;
        int ans;
        while(low<=high){
            int mid=(low+high)/2;
            if(speed(piles,mid,h)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};