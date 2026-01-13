#include <bits/stdc++.h>

int main() {
  std::ifstream inputFile("input.txt");
  long long ans = 0;
  std::string line;
  std::vector<std::vector<std::string>> nums;

  // figure out how many columns there are and sort each number into that
  while (getline(inputFile, line)) {
    std::vector<std::string> words;
    std::istringstream iss(line);
    std::string word;

    while (iss >> word) {
      words.push_back(word);
    }

    if (nums.size() == 0) {
      for (const auto& w : words) {
        std::vector<std::string> num = {w};
        nums.push_back(num);
      }
    } else {
      for (size_t i =0; i < words.size(); ++i){
        nums[i].push_back(words[i]);
      }
    }

  }

  // loop through columns and add or multiply them
  for (const auto& col : nums){
    bool op = (col.back() == "*");
    long long count = op;
    for (size_t i = 0; i < col.size() -1; ++i){
      if (op) {
        count *= std::stoll(col[i]);
      } else {
        count += std::stoll(col[i]);
      }
    }
    ans += count;
  }

  std::cout << ans << '\n';
}