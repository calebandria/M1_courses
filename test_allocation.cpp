#include <iostream>

int main() {
    // Dynamically allocate an array of integers and initialize all elements to 0
    int size = 5; // Change the size as per your requirement
    int **arr = new int*[size](); // Note the () to initialize to 0

     for (int i = 0; i < size; ++i) {
        arr[i] = new int[size](); 
    }
    // Now arr points to dynamically allocated memory with all elements initialized to 0
    for (int i = 0; i < size; ++i) {
        for(int j=0; j< size; j++){
            std::cout << arr[i][j]<< " ";
        }
        std::cout << std::endl;
    }

    // Don't forget to delete dynamically allocated memory to avoid memory leaks
    delete[] arr;

    return 0;
}
