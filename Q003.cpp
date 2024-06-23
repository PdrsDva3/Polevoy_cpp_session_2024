#include <iostream>

int binarySearch(int arr[], int l, int r, int x) {
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;


        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);


        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}

int main(){
    int array[10] = {1, 2, 4, 5, 10, 11, 123, 200, 210, 1000};
    int ans = binarySearch(array, 0, 9, 11);
    std::cout << ans;
}