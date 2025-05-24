#include <vector>
#include <algorithm>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h> 
using namespace std;

typedef long long ll;
typedef long double ld;
const ll MOD = 1e9+7;
#define all(x) (x).begin(), (x).end()

class Solution{
public:
    bool canJump(vector<int>& nums){
        const int n = nums.size();
        if(n <= 2 and nums[0] != 0) return true; 
            

        int maxReach = 0;
        for(int i=0; i<n; i++){
            if(maxReach < i) return false;
            maxReach = max(maxReach, i+nums[i]);
        }
        return true;
    }
};

int main()
{
    Solution st;
    return 0;
}
