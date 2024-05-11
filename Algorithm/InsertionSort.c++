#include <iostream>
#include <vector>

void sort(std::vector<int> &array);

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
    int temp;
    for (int i = 1; i < size ; i++){
        temp = array[i];
        int loc = i-1;
        while (loc >= 0 && temp < array[loc]){
            array[loc+1] = array[loc];
            loc--;
        }
        array[loc+1] = temp;
    }
}
