#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int countMagicalSubarrays(const vector<int>& arr, int k) {
    unordered_map<int, int> modCount;
    int prefixSum = 0;
    int magicalCount = 0;

    
    modCount[0] = 1;

    for (int num : arr) {
       
        prefixSum += num;

       
        int remainder = prefixSum % k;
        if (remainder < 0) {
            remainder += k;
        }

       
        magicalCount += modCount[remainder];

       
        modCount[remainder]++;
    }

    return magicalCount;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int result = countMagicalSubarrays(arr, k);
    cout << result << endl;

    return 0;
}