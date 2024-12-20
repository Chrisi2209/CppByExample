1. Capacity and Size
size(): Returns the number of elements in the vector.

cpp
Code kopieren
std::vector<int> v = {1, 2, 3};
std::cout << v.size(); // Output: 3
capacity(): Returns the total number of elements the vector can hold before needing to allocate more memory.

cpp
Code kopieren
std::cout << v.capacity(); // Output: Platform-dependent
resize(new_size): Resizes the vector to contain new_size elements. Extra elements will be value-initialized, or existing elements truncated.

cpp
Code kopieren
v.resize(5, 0); // Vector now has 5 elements: {1, 2, 3, 0, 0}
empty(): Checks if the vector is empty.

cpp
Code kopieren
std::cout << v.empty(); // Output: 0 (false)
reserve(new_cap): Requests that the vector capacity be at least new_cap. Useful for avoiding repeated reallocations.

cpp
Code kopieren
v.reserve(10); // Reserves capacity for at least 10 elements.
shrink_to_fit(): Reduces the capacity of the vector to match its size.

cpp
Code kopieren
v.shrink_to_fit();
2. Element Access
operator[] or at(index): Access elements by index. at provides bounds checking.

cpp
Code kopieren
std::cout << v[1];      // Output: 2
std::cout << v.at(1);   // Output: 2
front(): Returns a reference to the first element.

cpp
Code kopieren
std::cout << v.front(); // Output: 1
back(): Returns a reference to the last element.

cpp
Code kopieren
std::cout << v.back();  // Output: 3
data(): Returns a pointer to the underlying array used by the vector.

cpp
Code kopieren
int* arr = v.data();
std::cout << arr[1];    // Output: 2
3. Modifiers
push_back(value): Adds an element to the end of the vector.

cpp
Code kopieren
v.push_back(4); // v becomes {1, 2, 3, 4}
pop_back(): Removes the last element.

cpp
Code kopieren
v.pop_back();   // v becomes {1, 2, 3}
insert(pos, value): Inserts an element or multiple elements at the specified position.

cpp
Code kopieren
v.insert(v.begin() + 1, 10); // v becomes {1, 10, 2, 3}
emplace(pos, args...): Constructs an element in-place at the specified position.

cpp
Code kopieren
v.emplace(v.begin(), 0); // v becomes {0, 1, 2, 3}
erase(pos): Removes an element at the specified position or a range of elements.

cpp
Code kopieren
v.erase(v.begin() + 1);  // Removes 2nd element
v.erase(v.begin(), v.begin() + 2); // Removes first two elements
clear(): Removes all elements from the vector.

cpp
Code kopieren
v.clear(); // v becomes empty
assign(count, value) or assign(begin, end): Replaces all elements with new values.

cpp
Code kopieren
v.assign(3, 5); // v becomes {5, 5, 5}
emplace_back(args...): Constructs an element in-place at the end of the vector.

cpp
Code kopieren
v.emplace_back(6); // v becomes {1, 2, 3, 6}
swap(other_vector): Swaps the contents of two vectors.

cpp
Code kopieren
std::vector<int> v2 = {4, 5, 6};
v.swap(v2); // v becomes {4, 5, 6}, v2 becomes {1, 2, 3}
4. Iterators
begin() and end(): Returns iterators to the beginning and end of the vector.

cpp
Code kopieren
for (auto it = v.begin(); it != v.end(); ++it) {
    std::cout << *it << " ";
}
rbegin() and rend(): Returns reverse iterators.

cpp
Code kopieren
for (auto it = v.rbegin(); it != v.rend(); ++it) {
    std::cout << *it << " ";
}
cbegin() and cend(): Returns constant iterators (read-only access).

cpp
Code kopieren
for (auto it = v.cbegin(); it != v.cend(); ++it) {
    std::cout << *it << " ";
}
5. Comparisons and Algorithms
std::sort(v.begin(), v.end()): Sorts the vector in ascending order.

cpp
Code kopieren
std::sort(v.begin(), v.end());
std::reverse(v.begin(), v.end()): Reverses the vector.

cpp
Code kopieren
std::reverse(v.begin(), v.end());
std::find(v.begin(), v.end(), value): Finds the first occurrence of a value in the vector.

cpp
Code kopieren
auto it = std::find(v.begin(), v.end(), 2);
if (it != v.end()) std::cout << "Found!";
std::count(v.begin(), v.end(), value): Counts occurrences of a value.

cpp
Code kopieren
int count = std::count(v.begin(), v.end(), 2);
Common Patterns
Iterating Over a Vector:

cpp
Code kopieren
for (const auto& elem : v) {
    std::cout << elem << " ";
}
Removing Elements Based on a Condition:

cpp
Code kopieren
v.erase(std::remove(v.begin(), v.end(), 2), v.end()); // Removes all 2s
These methods make std::vector versatile and efficient for dynamic array operations.