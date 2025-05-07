#include <iostream>
#include "data_process.hpp"

int main() {
    std::vector<std::string> words = {"apple", "ant", "banana", "bear", "cat"};
    DataProcessor processor(words);

    auto sorted_words = processor.sort_by_length();
    std::cout << "original sequence :" << std::endl;
    for (const auto &word : processor.data_)
        std::cout << word << std::endl;
    

    std::cout << "Sorted by length:" << std::endl;    
    for (const auto &word : sorted_words)
        std::cout << word << std::endl;

    return 0;
        
}