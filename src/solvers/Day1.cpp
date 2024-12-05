#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdint>
#include <string>
#include <unordered_map>

#include "Day1.h"

void Day1::parse(const std::string &input)
{
    std::cout << input;

    std::stringstream ss(input);
    int leftValue, rightValue; // Variables temporaires pour la lecture

    while (ss >> leftValue >> rightValue) // On vérifie la lecture AVANT d'insérer
    {
        this->left.push_back(leftValue);
        this->right.push_back(rightValue);
    }

    for (size_t i = 0; i < this->left.size(); i++)
    {
        std::cout << this->left[i] << " => " << this->right[i] << std::endl;
    }
}

std::string Day1::part1()
{
    std::sort(this->left.begin(), this->left.end());
    std::sort(this->right.begin(), this->right.end());

    u_int32_t sum = 0;
    for (size_t i = 0; i < this->left.size(); i++)
    {
        sum += std::abs(this->left[i] - this->right[i]);
    }

    return std::to_string(sum);
}

std::string Day1::part2()
{
    std::unordered_map<int, int> counts;
    for (size_t i = 0; i < this->right.size(); i++)
    {
        counts[this->right[i]] += 1;
    }

    u_int32_t sum = 0;
    for (size_t i = 0; i < this->left.size(); i++)
    {
        sum += this->left[i] * counts[this->left[i]];
    }

    return std::to_string(sum);
}
