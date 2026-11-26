#include "RandomGenerator.h"

namespace miit::algebra {

    RandomGenerator::RandomGenerator(const int min, const int max)
        : distribution(min, max),
        generator(std::random_device{}()) {
    }

    int RandomGenerator::generate() {
        return distribution(generator);
    }

}
