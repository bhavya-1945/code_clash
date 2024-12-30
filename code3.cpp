#include <iostream>
#include <vector>

using namespace std;

bool isValidSchedule(int n, int w, const vector<vector<int>>& schedule) {

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            bool met = false;

            for (int k = 0; k < w; ++k) {
                if (schedule[k][i] != schedule[k][j]) {
                    met = true;
                    break;
                }
            }
            if (!met) return false; 
        }
    }
    return true;
}

void generateSchedule(int n, int w) {
    vector<vector<int>> schedule(w, vector<int>(n, 0));

    
    int maxIsolation = 0;
    for (int week = 0; week < w; ++week) {
        for (int team = 0; team < n; ++team) {
            schedule[week][team] = (week + team) % 2 + 1; 
        }
    }

    if (isValidSchedule(n, w, schedule)) {

        cout << maxIsolation << endl;
        for (int i = 0; i < w; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << schedule[i][j];
            }
            cout << endl;
        }
    } else {
        cout << "infinity" << endl;
    }
}

int main() {
    int n, w;
    cin >> n >> w;

    generateSchedule(n, w);

    return 0;
}
