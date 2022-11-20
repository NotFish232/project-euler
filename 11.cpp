#include <iostream>
#include <fstream>
#define dim 20
#define len 4

using namespace std;

int main(int argc, char **argv)
{
    fstream f;
    f.open("file.txt");
    int matrix[dim][dim];
    for (int i = 0; i < dim; ++i)
    {
        for (int j = 0; j < dim; j++)
        {
            f >> matrix[i][j];
        }
    }
    int max = 0;
    for (int row = 0; row < dim; ++row)
    {
        for (int col = 0; col < dim - len + 1; ++col)
        {
            int val = matrix[row][col] * matrix[row][col + 1] * matrix[row][col + 2] * matrix[row][col + 3];
            if (val > max)
                max = val;
        }
    }
    for (int col = 0; col < dim; ++col)
    {
        for (int row = 0; row < dim - len + 1; ++row)
        {
            int val = matrix[row][col] * matrix[row + 1][col] * matrix[row + 2][col] * matrix[row + 3][col];
            if (val > max)
                max = val;
        }
    }
    for (int row = 0; row < dim; ++row)
    {
        for (int col = 0; col < dim; ++col)
        {
            if (row >= dim - len + 1 || col >= dim - len + 1)
            {
                continue;
            }
            int val = matrix[row][col] * matrix[row + 1][col + 1] * matrix[row + 2][col + 2] * matrix[row + 3][col + 3];
            if (val > max)
                max = val;
        }
    }
    for (int row = 0; row < dim; ++row)
    {
        for (int col = dim - 1; col >= 0; --col)
        {
            if (row >= dim - len + 1 || col < len) {
                continue;
            }
            int val = matrix[row][col] * matrix[row + 1][col - 1] * matrix[row + 2][col - 2] * matrix[row + 3][col - 3];
            if (val > max)
                max = val;
        }
    }

    std::cout << "Result: " << max << std::endl;
    return 0;
}