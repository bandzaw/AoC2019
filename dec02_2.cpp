#include <iostream>
#include <vector>
#include <range/v3/getlines.hpp>
#include <range/v3/view/transform.hpp>
#include <range/v3/view/chunk.hpp>
#include <range/v3/view/take_while.hpp>

int run(std::vector<int> /*yes, by copy to get fresh data*/ ints, int noun, int verb)
{
    using namespace ranges;

    ints[1] = noun;
    ints[2] = verb;

    auto chunks = 
        ints | 
        view::chunk(4) | 
        view::take_while([](const auto& chunk) { 
            return chunk[0] != 99; 
        });

    for (auto chunk : chunks)
    {
        int op = chunk[0];
        int v1 = ints[chunk[1]];
        int v2 = ints[chunk[2]];
        ints[chunk[3]] = (op == 1 ? (v1 + v2) : (v1 * v2));  
    }
    return ints[0];
}

int main()
{
    using namespace ranges;
    std::vector<int> ints = 
        ranges::getlines(std::cin, ',') | 
        view::transform([](std::string const& s) { 
            return std::stoi(s); 
        }) |
        to_vector;
    
    ints.resize(2*ints.size()); // Make sure there is room for writing what otherwise would be out-of-bounds. And hope for the best...

    for (int noun = 0; noun < 100; ++noun)
    {
        for (int verb = 0; verb < 100; ++verb)
        {
            int result = run(ints, noun,verb);
            if (result == 19690720)
            {
                std::cout << "[noun,verb] = " << "[" << noun << "," << verb << "] => " << 100 * noun + verb << ", Apollo 11 moon landing day!" << std::endl;
                return 0;
            }
        }
    }
}