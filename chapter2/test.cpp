#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

template <typename T>
std::ostream &operator<<(std::ostream &s, const std::vector<std::vector<T>> &triangle)
{
    // use const reference to avoid a copy (it would copy the values in triangle (unnecessary))
    // (const means we cannot change the content)
    for (const auto &row : triangle)
    {
        // can also
        // std::copy(row.begin(), row.end(), std::ostream_iterator<T>(s, " "));
        std::ranges::copy(row, std::ostream_iterator<T>(s, " "));

        /* // copy does essentially:
        std::ostream_iterator<T> it(s, " ");  // this it gets as a parameter
        for (auto cell : row)  // loops over container
        {  // when *it, you get a object that has the = operator overriden to add the object to the stream
            // the ++ moves it to the next iteration, for cout stream, this is a no-op because it only outputs
            // to the console so it doesn't need to track an index or something
            *it++ = cell;
        }
        */
        // std::cout << std::ranges::copy()
        s << '\n';
    }
    return s;
}