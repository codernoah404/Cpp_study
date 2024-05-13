#include <iostream>
#include <vector>

void sort(std::vector<int> &arr, int p, int r);
void merge(std::vector<int> &arr, int p, int q, int r);

int main(){
    std::vector<int> numbers = {10, 1, 9, 2, 8, 3, 7, 4, 6, 5};
    int size = numbers.size();

    sort(numbers, 0, size - 1);
    for (int num : numbers){
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
     
}

void sort(std::vector<int> &arr, int p, int r){
    if (p < r){ 
        int q = (p+r) / 2 ;
        sort(arr, p, q);
        sort(arr, q+1, r);
        merge(arr, p, q, r);
    }
}

void merge(std::vector<int> &arr, int p, int q, int r) {
    std::vector<int> temp{};
    int i = p, j = q + 1;
    while (i <= q && j <= r) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i++;
        } else {
            temp.push_back(arr[j]);
            j++;
        }
    }

    while (i <= q) {
        temp.push_back(arr[i]);
        i++;
    }

    while (j <= r) {
        temp.push_back(arr[j]);
        j++;
    }

    for (int k = p; k <= r; k++) {
        arr[k] = temp[k - p];
    }
}