#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
int main()
{
    std::ifstream file("input.txt");
    if (!file.is_open()) {
        std::cout << "failed to open" << std::endl;
        return 1;
    }
    std::unordered_map<std::string, std::string> m;
    std::string line;
    getline(file, line);
    while (!line.empty()) {
        m[line.substr(0, 2)] += line.substr(3, 2) + ',';
        getline(file, line);
    }
    int s = 0;
    while (getline(file, line)) {
        int lineSize = line.size();
        int i = 3;
        bool v = false;
        while (i < lineSize) {
            std::string index = line.substr(i, 2);
            for (int j = 0; j < i; j += 3) {
                if (m[index].find(line.substr(j, 2)) != std::string::npos) {
                    v = true;
                }
            }
            i += 3;
        }
        if (v == false)
        {
            s += stoi(line.substr(lineSize / 2 - 1, 2));
        }
    }
    std::cout << s << std::endl;
}