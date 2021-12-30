#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> differences;
        for(int i = 0; i < nums.size(); i++) {
            differences[target - nums[i]] = i;
        }
        
        for(int i = 0; i < nums.size(); i++) {
            if(differences.find(nums[i]) != differences.end() && differences[nums[i]] != i) {
                return vector<int>({i, differences[nums[i]]});
            }
        }
        return vector<int>();
    }
};
