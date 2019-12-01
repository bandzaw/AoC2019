#include <iostream>
#include "range/v3/view/istream.hpp"
#include "range/v3/view/transform.hpp"
#include "range/v3/view/generate.hpp"
#include "range/v3/numeric/accumulate.hpp"
#include "range/v3/view/take_while.hpp"

int main()
{
    using namespace ranges;
    auto input = istream_range<int>(std::cin);
    int totFuel = accumulate(input |
        view::transform([](int m) {
            return accumulate(
                view::generate([fpm = m]() mutable {
                    fpm = fpm / 3 - 2;
                    return fpm;
                }) |
                view::take_while([](int fpm) {
                    return fpm > 0;
                }),
                0
            );
        }),
        0
    );
    std::cout << totFuel << std::endl;
}