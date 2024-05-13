#include <iostream>
#include <vector>

void sort(int arr[], int start, int end);
int partition(int arr[], int start, int end);

int main(){
    int numbers[] = {10, 1, 9, 2, 8, 3, 7, 4, 6, 5};
    int size = sizeof(numbers)/sizeof(numbers[0]);

    sort(numbers, 0, size - 1);
    for (int num : numbers){
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
     
}

void sort(int arr[], int start, int end){
    int pvt = partition(arr, start, end);
    if (end - start > 2){
        sort(arr, start, pvt);
        sort(arr, pvt+1, end);
    }
}

int partition(int arr[], int start, int end){
    std::vector<int> temp = {arr[(end - start)/2]}; //피봇을 미리 넣어둔다.
    int pvt = 0;

    // 피봇 기준으로 정렬
    for (int i = 0; i < end; i++){
        if (i == (end - start)/2){
            continue;
        }
        if (arr[i] > temp[pvt]){
            temp.push_back(arr[i]);
        }
        else {
            temp.insert(temp.begin()+pvt, arr[i]);
            pvt++;
        }
    }

    for (int j = 0; j < temp.size()-1; j++){
        arr[j] = temp[j];
    }

    return pvt; //피봇의 인덱스 값을 반환
}