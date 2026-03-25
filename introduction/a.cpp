/* 
  Chapter: Perkenalan Pemrograman Kompetitif
  Problem: Perkenalan Soal Implementasi (Matrix Rotation)
  Time limit: 1 s | Memory limit: 64 MB
  C++20 | GCC 15.2.0
*/

#include <bits/stdc++.h>
using namespace std;

// Define an alias for vector<int>
typedef vector<int> vi;

// Function to perform a transpose operation on a matrix
vector<vi> transpose(const vector<vi>& mat) {
    int r = mat.size();
    int c = mat[0].size();
    vector<vi> res(c, vi(r));

    for(int i = 0; i < c; i++) {
        for(int j = 0; j < r; j++) {
            res[i][j] = mat[j][i];
        }
    }

    return res;
}

// Function to rotate a matrix 90 degrees clockwise
vector<vi> rotate(const vector<vi>& mat) {
    int r = mat.size();
    int c = mat[0].size();
    vector<vi> res;

    vector<vi> transposed = transpose(mat);

    res = transposed;

    for(int i = 0; i < c; i++) {
        reverse(res[i].begin(), res[i].end());
    }

    return res;
}

// Main function
int main() {

    // Declaring variables
    int r, c;

    // Input
    cin >> r >> c;

    // Declaring a matrix
    vector<vi> mat(r, vi(c));

    // Enter matrix elements
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            cin >> mat[i][j];

    // Rotate the matrix
    vector<vi> rotated = rotate(mat);

    // Print the final matrix condition
    for(int i = 0; i < c; i++) {
        for(int j = 0; j < r; j++)
            cout << rotated[i][j] << " ";
        cout << "\n";
    }

    return 0;
}