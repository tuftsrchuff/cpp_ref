#include <iostream>

int main()
{
    int* array = new int[50];

    //Integer assigned
    array[0] = 1;

    //2D array, pointer to int pointer
    int** a2d = new int*[50];

    //Allocate underlying arrays - 2D
    for (int i = 0; i < 50; i++)
        a2d[i] = new int[50];
    
    //Memory leak, need to individually delete pointers
    // delete[] a2d;

    //Proper way to fully delete 2D array with no mem leak
    for (int i = 0; i < 50; i++){
        delete [] a2d[i];
    }
    delete[] a2d;
    
    //Creation of 3D array
    // int*** a3d = new int**[50];
    // for (int i = 0; i < 50; i++){
    //     a3d[i] = new int*[50];
    //     for (int j = 0; j < 50; j++)
    //         a3d[i][j] = new int[50];
    // }

    //Optimize so 2D stored as 1D array, better performance
    const int ROW = 5, COL = 5; 
    int* optArray = new int[ROW * COL];
    for (int y = 0; y < COL; y++){
        for (int x = 0; x < ROW; x++){
            optArray[x + y * ROW] = 2;
        }
    }

    std::cin.get();
}