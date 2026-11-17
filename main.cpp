#include <iostream>
#include <random>
#include <vector>
#include <string>

int main(int argc, char* argv[]) {
    // Default: 100
    double avgSpacing = 1.0;
    // Default seed: Meaning of Life
    unsigned int seed = 42; 
    // Process args if specified
    if (argc >= 2) {
        avgSpacing = std::stof(argv[1]);
    }
    if (argc >= 3) {
        seed = static_cast<unsigned int>(std::stoul(argv[2]));
    }
    // Set up random num generator: 
    // Uses 32-bit Mersenne Twister pseudo-random number generator algorithm
    std::mt19937 rng(seed);

    double nextAttemptTimeA;
    double nextAttemptTimeB;
    
    
    
    std::cout << "Average Time: " << totalTime / 100.0 << "\n";
    return 0;
}