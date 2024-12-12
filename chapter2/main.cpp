// Pascals triangle
// g++ -Wall --std=c++2a -o main.out main.cpp

#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include <iterator>
#include <set>
#include <thread>
#include <chrono>

// bad practice to override for normal types like vectors because it could clash with other libs
// better with own classes or use a named function
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
        // copy does essentially:
        /*
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

std::vector<int> get_next_row(const std::vector<int> &last_row)
{
    std::vector next_row{1};

    if (last_row.empty())
    {
        return next_row;
    }
    for (size_t idx = 0; idx + 1 < last_row.size(); ++idx)
    {
        next_row.emplace_back(last_row[idx] + last_row[idx + 1]);
    }
    next_row.emplace_back(1);

    return next_row;
}

auto generate_triangle(int rows)
{
    std::vector<int> data;
    std::vector<std::vector<int>> triangle{{1}};
    for (int row = 0; row < rows; ++row)
    {
        /* old
        data = get_next_row(data);
        triangle.push_back(data);
        */
        // triangle.push_back(get_next_row(triangle.back())); // better
        triangle.emplace_back(get_next_row(triangle.back())); // does not do unnecesary copies of the vector (even better9)
    }
    return triangle;
}

auto main() -> int
{
    auto triangle = generate_triangle(16);

    // Output all elements of the set, separated by commas
    // std::set<std::string> fruits = {"apple", "banana", "cherry", "date"};
    /*
    std::ostream_iterator<std::string> outIt(std::cout, ", ");
    for (const auto &fruit : fruits)
    {
        *outIt = fruit; // Write each element to the stream
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    */
    std::cout << triangle;

    return 0;
}