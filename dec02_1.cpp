#include <iostream>
#include <vector>
#include <range/v3/getlines.hpp>
#include <range/v3/view/transform.hpp>
#include <range/v3/view/chunk.hpp>
#include <range/v3/view/take_while.hpp>

int main()
{
    using namespace ranges;
    std::vector<int> ints = 
        ranges::getlines(std::cin, ',') | 
        view::transform([](std::string const& s) { 
            return std::stoi(s); 
        }) |
        to_vector;
    
    ints.resize(2*ints.size()); // Make sure there is room for writing what otherwise would be out-of-bounds
    for(auto i : ints)
    {
        std::cout << i << std::endl;
    };

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
        ints[chunk[3]] = op ==
    }
    
}