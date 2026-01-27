class Solution {
public:
    int FirstOccurence(vector<int>& arr, int target) {
        int left = 0;
        int right = arr.size() - 1;
        int first = -1; // initialize to -1
        while (left <= right) {
            int mid = (left + right) / 2;
            if (arr[mid] == target) {
                first = mid;
                right = mid - 1; // keep searching to the left
            } else if (arr[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return first;
    }

    int LastOccurence(vector<int>& arr, int target) {
        int left = 0;
        int right = arr.size() - 1;
        int last = -1; // initialize to -1
        while (left <= right) {
            int mid = (left + right) / 2;
            if (arr[mid] == target) {
                last = mid;
                left = mid + 1; // keep searching to the right
            } else if (arr[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return last;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int i = FirstOccurence(nums, target);
        int j = LastOccurence(nums, target);
        return {i, j};
    }
};
