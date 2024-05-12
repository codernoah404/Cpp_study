#include <iostream>
#include <vector>

void sort(std::vector<int> &arr, int &p, int &r);
void merge(std::vector<int> &arr, int &p, int q, int &r);

int main(){
    std::vector<int> numbers = {10, 1, 9, 2, 8, 3, 7, 4, 6, 5};
    int size = numbers.size();

    sort(&numbers, &numbers, &numbers + size);
    for (int num : numbers){
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
     
}

void sort(std::vector<int> &arr, int &p, int &r){
    if (p < r){ 
        int q = (r - p) / 2 ;
        sort(arr, p, p+q);
        sort(arr, p+q+1, r);
        merge(arr, p, q, r);
    }
}

void merge(std::vector<int> &arr, int &p, int q, int &r) {
    std::vector<int> temp{};
    int i = 0, j = 0;
    while ( i + j + 2 == (r-p) / 2){
        if (arr[p+i] >= arr[p+q+j]){
            temp.push_back(arr[p+i]);
            i++;
        }
        else {
            temp.push_back(arr[p+q+j]);
            i++;
        }
    }

    for (int k = 0; k < temp.size(); k++){
        arr[k] = temp[k];
    } 
}