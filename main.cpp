#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

int main(){

    std::ifstream inFile("/Users/chiragsharma/Downloads/name.csv");
    std::string line;
    if (!inFile.is_open()) {
        std::cerr << "Can't open file" << std::endl;
        return -1;
    }
    double total = 0.0;

    for (int i= 0; i < 5; i++) {
        std::getline(inFile, line);
    }

    while (std::getline(inFile, line)) {
        if (line.empty()) continue;
        std::stringstream ss(line);
        std::string cell;

        for (int col = 0; col <= 10; col++) {
            if (!std::getline(ss, cell, ',' )) break;

            if (col == 10) {
                try{
                    if (!cell.empty()) {
                        total += std::stod(cell);
                    }
                } catch (...) {

                } break;
            }


        }
    }
    inFile.close();

    std::cout << "The total for the Copay is: " << total << std::endl;
    return 0;
}