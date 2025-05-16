#include <iostream>
#include <fstream>
#include <random>
using namespace std;

int main() {
    ofstream file("dataset.csv");

    if (!file.is_open()) {
        cout << "Cant open the file.\n";
        return 1;
    }

    const int rows = 1000000;  // 1 million rows
    const int cols = 1;        // 1 numbers per row

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(0, 1000);  // Range 0 to 1000

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            file << distrib(gen);
            if (j != cols - 1) file << ",";
        }
        file << "\n";
    }

    file.close();
    cout << "CSV generated.\n";

    return 0;
}
