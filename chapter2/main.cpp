// Pascals triangle
// g++ -Wall --std=c++2a -o main.out main.cpp

#include <iostream>
#include <vector>
#include <numeric>
#include <limits>
#include <algorithm>
#include <iterator>
#include <set>
#include <thread>
#include <chrono>
#include <cassert>

// generische Addition
template <typename T, typename U>
auto simple_plus(T lhs, U rhs) -> decltype(lhs + rhs)
{
    return lhs + rhs;
}

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
        triangle.emplace_back(get_next_row(triangle.back())); // does not do unnecesary copies of the vector (even better)
    }
    return triangle;
}

void show_vectors(std::ostream &s,
                  const std::vector<std::vector<int>> &v)
{
    size_t final_row_size = v.back().size();
    std::string spaces(final_row_size * 3, ' ');
    for (const auto &row : v)
    {
        s << spaces;
        if (spaces.size() > 3)
            spaces.resize(spaces.size() - 3);
        for (const auto &data : row)
        {
            s << std::format("{: ^{}}", data, 6);
        }
        s << '\n';
    }
}

void check_properties(
    const std::vector<std::vector<int>> &triangle)
{
    for (const auto &row : triangle)
    {
        assert(row.front() == 1);
        assert(row.back() == 1);
    }

    size_t row_number = 1;
    for (const auto &row : triangle)
    {
        assert(row.front() == 1);
        assert(row.back() == 1);
        assert(row.size() == row_number++);
    }

    int expected_total = 1;
    for (const auto &row : triangle)
    {
        assert(std::accumulate(row.begin(),
                               row.end(),
                               0) == expected_total);
        expected_total *= 2;
    }
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
    // auto does_not_compile = std::format("I am not a number {:f}", 3);

    show_vectors(std::cout, triangle);
    check_properties(triangle);

    return 0;
}