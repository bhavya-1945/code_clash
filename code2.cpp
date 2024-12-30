#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;


bool compare(int a, int b) {
    
    string binaryA = bitset<32>(a).to_string(); 
    string binaryB = bitset<32>(b).to_string();

    
    binaryA.erase(0, binaryA.find_first_not_of('0'));
    binaryB.erase(0, binaryB.find_first_not_of('0'));

    return binaryA < binaryB; 
}

int main() {
    int n;
    cin >> n;
    
    vector<int> nums(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    
    stable_sort(nums.begin(), nums.end(), compare);

    
    for (int num : nums) {
        cout << num << " ";
    }

    cout << endl;

    return 0;
}
