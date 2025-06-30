class Solution {
public:
    bool possible(const vector<int>&weights, int mid, int days){
        int currentLoad = 0;
        int dayCount = 1;

        for (int i = 0; i < weights.size(); i++) {
            if (currentLoad + weights[i] > mid) {
                dayCount++;
                currentLoad = weights[i];  // start new day
            } else {
                currentLoad += weights[i];  // add to current day
            }
        }

        return dayCount <= days;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int ans;
        int maximum=0;
        int least=0;
        for(int x : weights){
            least=max(least,x);
            maximum+=x;
        }
        while (least<=maximum){
            int mid=(least+maximum)/2;
            if(possible(weights,mid,days)){
                ans=mid;
                maximum=mid-1;
            }
            else{
                least=mid+1;
            }
        }
        return ans;


    }
};