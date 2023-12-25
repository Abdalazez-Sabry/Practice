#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <iomanip>

using namespace std;

class Solution {
public:
    vector<int> numbers = {-2,1,4, -9, 32, 4, -32, 4, 5, 2, -4, 5,4 ,6, 4,3,4,5,6,7,8,5,4,3,2,1,1};

    int crossingMaxi(int low, int mid, int high){
        int maxLeft(-9999999), maxRight(-999999);

        int current = 0;
        for (int i = mid; i >= low; i--){
            current += numbers[i];
            maxLeft = max(maxLeft, current);
        }

        current = 0;
        for (int i = mid + 1; i <= high; i++){
            current += numbers[i];
            maxRight = max(maxRight, current);
        }

        return maxLeft + maxRight;
    }
    int recMaxi(int low, int high){
        if(low == high){
            return numbers[low];
        }

        int mid = ((low + high) / 2);

        int leftSum = recMaxi(low, mid) ;
        int rightSum = recMaxi(mid + 1, high);
        int crossSum = crossingMaxi(low, mid, high);
        
        return max(max(leftSum, rightSum), crossSum);

    }
};


int maximumSubArrayBruteForce(vector<int> numbers){
    int maxi = -999999;
    for (int i = 0; i < numbers.size(); i++){
        int current = 0;
        for (int j = i; j < numbers.size(); j++){
            current += numbers[j];
            maxi = max(maxi, current);
        }
    }
    return maxi;
}

// nest algorithms, takes linear time and very samrt and simple to be honest
int kadanesAlgo(vector<int> numbers){
    int maxSoFar = -99999;
    int maxEndsHere = 0;
    for (int i = 0; i < numbers.size(); i++){
        maxEndsHere += numbers[i];
        maxSoFar = max(maxSoFar, maxEndsHere);
        maxEndsHere = max(maxEndsHere, 0);
    }
    return maxSoFar;
}

vector<int> generateInts(int n){
    vector<int> result;
    for (int i = 0; i < n; i++){
        result.push_back(i);
    }
    return result;
}

int main(){
    Solution lol;
    clock_t recFirst, recLast, bruteFirst, bruteLast;
    lol.numbers ;

    recFirst = clock();
    cout << "result is: " << lol.recMaxi(0, lol.numbers.size() - 1) << endl;
    recLast = clock();
    
    bruteFirst = clock() ;
    cout << "result from brute force is: " <<maximumSubArrayBruteForce(lol.numbers) << endl;
    bruteLast = clock();

    cout << "result from Kadane's algo: " << kadanesAlgo(lol.numbers) << endl;

    double resultRec = double(recLast - recFirst) / double(CLOCKS_PER_SEC);
    double resultBrute = double(bruteLast - bruteFirst) / double(CLOCKS_PER_SEC);
    cout << "time for divde and conq= " << fixed << resultRec << setprecision(10) << endl;
    cout << "time for brute force= " << fixed << resultBrute << setprecision(10) << endl;
}
