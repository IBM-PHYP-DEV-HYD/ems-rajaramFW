// Random.H
#pragma once
#include <string>
#include <random>

class Random {
public:
    // Arrays as static members
    static const std::string Name[10];
    static const std::string status[2];
    static const std::string agency[3];
    static const std::string branch[3];
    static const std::string collage[6];

    // Random number generator
    static int getRandomNumber(int start, int end);
};
