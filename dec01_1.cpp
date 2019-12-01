#include <iostream>
#include "range/v3/view/istream.hpp"
#include "range/v3/view/transform.hpp"
#include "range/v3/numeric/accumulate.hpp"

int main()
{
    using namespace ranges;
    auto input = istream_range<int>(std::cin);
    int fuel = accumulate(input | 
                    view::transform([](int m) {
                        return m/3 - 2; 
                    }), 
                0);
    std::cout << fuel << std::endl;
}
