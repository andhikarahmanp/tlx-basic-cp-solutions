#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

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

int main() {
    int r, c;

    cin >> r >> c;

    vector<vi> mat(r, vi(c));

    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            cin >> mat[i][j];

    vector<vi> rotated = rotate(mat);

    for(int i = 0; i < c; i++) {
        for(int j = 0; j < r; j++)
            cout << rotated[i][j] << " ";
        cout << "\n";
    }

    return 0;
}