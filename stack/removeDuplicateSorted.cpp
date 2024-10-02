 int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0 || nums.size() == 1) {
            return nums.size();
        }
        vector<int> nums1;
        int i = 0;
        int j = 0;
        int count = 0;
        for (; i < nums.size() && j < nums.size(); i++) {
  
            while (nums[i] == nums[j]) {
                cout << nums[j];
                j++;
                if (j == nums.size() - 1) {
                    cout << nums[j];
                    break;
                }
            }
            nums[i] = j;
            i = j;
            count++;
            
            // cout << count;
        }
        return count;
    }