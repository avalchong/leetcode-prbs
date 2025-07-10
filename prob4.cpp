#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    void heapSort(vector<int>& arr, int n, int i){
        int largest = i; // Initialize largest as root
        int left = 2 * i + 1; // Left child
        int right = 2 * i + 2; // Right child

        // If left child is larger than root
        if (left < n && arr[left] > arr[largest]) {
            largest = left;
        }

        // If right child is larger than largest so far
        if (right < n && arr[right] > arr[largest]) {
            largest = right;
        }

        // If largest is not root
        if (largest != i) {
            std::swap(arr[i], arr[largest]);
            // Recursively heapify the affected sub-tree
            heapSort(arr, n, largest);
        }  
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //create unsorted combined array between nums1 and nums2
        vector<int> arr = {};
        int x = 0;
        while(x < nums1.size()){
            arr.push_back(nums1[x]);
            x++;
        }
        while((x - nums1.size()) < nums2.size()){
            arr.push_back(nums2[x - nums1.size()]);
            x++;
        }

        int n = arr.size();

        // Build heap
        // Start from the last node and go up root
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapSort(arr, n, i);
        }

        // One by one extract an element from heap
        for (int i = n - 1; i > 0; i--) {
            // Move current root to end
            std::swap(arr[0], arr[i]);

            // Call max heapify on the reduced heap
            heapSort(arr, i, 0);
        }
        double median = -1;
        if(n % 2 == 0){
            int half = n/2;
            //median = (arr[half] + arr[half - 1])/2;
            median = arr[half] + arr[half - 1];
            median /= 2;
        }else{
            median = arr[n/2];
        }
        return median;
    }
};