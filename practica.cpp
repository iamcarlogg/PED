#include <iostream>
#include <fstream>
#include <vector>

int main() {
    std::ofstream file("notas.txt");
    if (file.is_open()) {
        file << "85\n90\n78\n92\n88";
        file.close();
    }

    std::ifstream infile("notas.txt");
    if (infile.is_open()) {
        int sum = 0, count = 0, grade;
        while (infile >> grade) {
            sum += grade;
            count++;
        }
        infile.close();

        double average = static_cast<double>(sum) / count;

        std::ofstream outfile("notas.txt", std::ios::app);
        if (outfile.is_open()) {
            outfile << "\nPromedio: " << average;
            outfile.close();
        }

        std::cout << "Promedio calculado y guardado." << std::endl;
    }

    return 0;
}
