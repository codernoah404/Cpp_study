#include <iostream>

void sort(int arr[], int size);

int main(){
    int numbers[] = {10, 1, 9, 2, 8, 3, 7, 4, 6, 5};
    int size = sizeof(numbers)/ sizeof(int);

    sort(numbers, size);
    for (int num : numbers){
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
     
}

void sort(int array[], int size){
    for(int i; i < size - 1; i++){
        for (int j=0; j < size - i - 1; j++){
            if (array[j] > array[j+1]){
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}
