#include <iostream>
#include <climits>
using namespace std;

int maxOfThree(int a, int b, int c) {
    return max(a, max(b, c));
}
int maxCrossingSum(int arr[], int left, int mid, int right) {
    int sum = 0;
    int left_sum = INT_MIN;

  for (int i = mid; i >= left; i--) {
        sum += arr[i];
        left_sum = max(left_sum, sum);
    }

    sum = 0;
    int right_sum = INT_MIN;

    for (int i = mid + 1; i <= right; i++) {
        sum += arr[i];
        right_sum = max(right_sum, sum);
    }

    return left_sum + right_sum;
}

int maxSubArraySum(int arr[], int left, int right) {
    if (left == right)
        return arr[left];

    int mid = (left + right) / 2;

    return maxOfThree(
        maxSubArraySum(arr, left, mid),
        maxSubArraySum(arr, mid + 1, right),
        maxCrossingSum(arr, left, mid, right)
    );
}

int main() {
    int arr[] = {-2, -5, 6, -2, -3, 1, 5, -6};
    int n = sizeof(arr) / sizeof(arr[0]);

    int maxSum = maxSubArraySum(arr, 0, n - 1);
    cout << "Maximum Subarray Sum = " << maxSum << endl;

    return 0;
}
