/* 
  Chapter: Perkenalan Pemrograman Kompetitif
  Problem: Operasi Matriks
  Time limit: 1 s | Memory limit: 16 MB
  C++20 | GCC 15.2.0
*/

#include <bits/stdc++.h>
using namespace std;

// Define aliases
typedef vector<int> vi;
typedef vector<vi> vvi;

// Function to perform a transpose operation on a matrix
vvi transpose(const vvi& mat) {
    int r = mat.size();
    int c = mat[0].size();
    vvi res(c, vi(r));

    for(int i = 0; i < c; i++) {
        for(int j = 0; j < r; j++) {
            res[i][j] = mat[j][i];
        }
    }

    return res;
}

// Function to rotate a matrix 90 degrees clockwise
vvi rotate(const vvi& mat) {
    int r = mat.size();
    int c = mat[0].size();
    vvi res = transpose(mat);

    for(int i = 0; i < c; i++) {
        reverse(res[i].begin(), res[i].end());
    }

    return res;
}

// Function to reflect a matrix horizontally
vvi horizontalReflect(const vvi& mat) {
    int r = mat.size();
    int c = mat[0].size();
    vvi res = mat;

    for(int i = 0; i < c; i++) {
        for(int j = 0; j < r / 2; j++) {
            swap(res[j][i], res[r - j - 1][i]);
        }
    }

    return res;
}

// Function to reflect a matrix vertically
vvi verticalReflect(const vvi& mat) {
    int r = mat.size();
    int c = mat[0].size();
    vvi res = mat;

    for(auto &row : res) {
        reverse(row.begin(), row.end());
    }

    return res;
}

int main() {
    int n, m, x;

    cin >> n >> m >> x;

    vvi mat(n, vi(m));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }

    while(x--) {
        string opt;

        cin >> opt;

        if(opt == "_") {
            mat = horizontalReflect(mat);
        } else if(opt == "|") {
            mat = verticalReflect(mat);
        } else if(opt == "90") {
            mat = rotate(mat);
        } else if(opt == "180") {
            for(int i = 0; i < 2; i++) {
                mat = rotate(mat);
            }
        } else if(opt == "270") {
            for(int i = 0; i < 3; i++) {
                mat = rotate(mat);
            }
        }
    }

    for(auto row : mat) {
        for(auto el : row) {
            cout << el << " ";
        }
        cout << "\n";
    }

    return 0;
}
