#include <iostream>
#include <vector>

void sort(std::vector<int> &array);
void swap(int &a, int &b);

int main(){
    std::vector<int> numbers = {10, 1, 9, 2, 8, 3, 7, 4, 6, 5};

    sort(numbers);

    for (int num : numbers){
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}

void sort(std::vector<int> &array){
    int size = array.size();
    for (int i = size - 1; i > 0; i--){
        int maxIndex = 0;
        for (int j = 1; j <= i; j++){
            if (array[j] > array[maxIndex]){
                maxIndex = j;
            }
        }
        swap(array[maxIndex], array[i]);
    }
}

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}