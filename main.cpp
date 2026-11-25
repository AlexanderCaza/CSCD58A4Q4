#include <iostream>
#include <random>
#include <vector>
#include <string>
#include <cmath>

int main(int argc, char* argv[]) {
    // Default: 1.0
    double avgSpacing = 1.0;
    // Default seed: Meaning of Life
    unsigned int seed = 42; 
    // Default num Trials: 10000
    int numTrials = 10000;
    // Process args if specified
    if (argc >= 2) {
        avgSpacing = std::stod(argv[1]);
    }
    if (argc >= 3) {
        numTrials = std::stoi(argv[2]);
    }
    if (argc >= 4) {
        seed = static_cast<unsigned int>(std::stoul(argv[3]));
    }
    // Set up random num generator: 
    // Uses 32-bit Mersenne Twister pseudo-random number generator algorithm
    std::mt19937 rng(seed);

    double totalSuccessfulTransmissionTime = 0;

    for (int i = 1; i <= numTrials; i++) {
        double prevAttempt = -2.0;
        std::uniform_real_distribution<double> dist(0, 1);
        double rngNumber = 0.0;
        while (rngNumber == 0.0) rngNumber = dist(rng);
        double currentAttempt = -(avgSpacing * log(rngNumber));
        double nextAttempt;

        bool successfulTransmission = false;
        while (successfulTransmission == false) {
            rngNumber = 0.0;
            while (rngNumber == 0.0) rngNumber = dist(rng);
            nextAttempt = currentAttempt + (-(avgSpacing * std::log(rngNumber)));
            
            if (currentAttempt - prevAttempt > 1 && nextAttempt - currentAttempt > 1) {
                successfulTransmission = true;
                totalSuccessfulTransmissionTime += currentAttempt;
            } else {
                // Collision
                prevAttempt = currentAttempt;
                currentAttempt = nextAttempt;
            }
        }
    }
    
    std::cout << "Average Slots to Success: " << totalSuccessfulTransmissionTime / numTrials << "\n";
    return 0;
}