#include <algorithm>
#include <functional>
#include <iostream>
#include <random>
#include "library.hpp"

constexpr unsigned int N_ITERS = 250000;
constexpr unsigned int NOTIF_STEP = 10000;

int main(int argc, char *argv[])
{

    std::default_random_engine generator;
    std::uniform_int_distribution<unsigned int> vect_size_dist(4,32);
    std::uniform_real_distribution<float> component_dist(-64.f, 64.f);

    unsigned int notif = 0;

    for (unsigned int i = 0; i < N_ITERS; ++i, ++notif)
    {
        std::vector<float> v;
        unsigned int vect_size = vect_size_dist(generator);
        std::generate_n(std::back_inserter(v), vect_size, std::bind(component_dist, std::ref(generator)));
        process(v, "test_data" + std::to_string(i));
        if (notif >= NOTIF_STEP)
        {
            notif = 0;
            std::cout << "Processed " << i << " vectors.\n";
        }
    }
    std::cout << "Finished\n";
}
