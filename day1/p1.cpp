#include <bits/stdc++.h>

// basic template for reading input in c++
int main() {
    int ans = 0;
    int dial = 50;
    std::string line;
    while (getline(std::cin, line)) {
        std::string rotations = line.substr(1);
        int num = std::stoi(rotations);
        if (line[0] == 'R') {
            dial += num;
        } else {
            dial -= num;
        }
        dial %= 100;

        if (dial == 0) {
            ans++;
        }
    }
    std::cout << ans << "\n";
}