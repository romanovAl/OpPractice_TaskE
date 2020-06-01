#pragma once

using namespace std;

template <typename Number>
class Uniform

{

    std::mt19937 rng;

    std::uniform_real_distribution<Number> vg;


public:

    explicit Uniform(std::size_t seed = 5512943)

        : rng(seed), vg(Number(-1), Number(+1)) {}


    Number operator()() { 
        return vg(rng); 
    }

};