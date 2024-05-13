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
    if (end > start){ //수정
        int pvt = partition(arr, start, end);
        sort(arr, start, pvt-1);
        sort(arr, pvt+1, end);
    }
}

int partition(int arr[], int start, int end){
    int pivot = arr[end]; // 피봇을 배열의 마지막 요소로 선택
    int i = start - 1;     // 좌측 배열의 마지막 요소

    for (int j = start; j < end; j++) {
        if (arr[j] < pivot) { // 피봇보다 작으면 i를 한칸 전진하고, 바꾼다. 만일 피봇보다 크다면 j만 전진한다.
            std::swap(arr[++i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[end]); // 피봇의 위치를 바꾸어 작은 요소와 큰 요소를 나눔
    return i + 1;                    // 피봇의 최종 위치 반환
}