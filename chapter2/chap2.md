# Initialization

```cpp
std::vector<int> data(1); // wäre Vektor mit Länge 1
int x{3} also works as initialization as example
std::vector data{1};
auto data = std::vector<int>{ 1 } // gleichgültig (mit auto)

std::vector data // erschafft einen leeren Vektor
```

a wise man once said: **ALWAYS USE AUTO**! Using auto is better because if vector type changes, this doesn't have to

# Pascal triangle
2 Parents aufsummieren

# Get max value
`std::numeric_limits<int>::max()` with the *limits* header.

# Vectors
## Add values
```cpp
// emplace takes params to construct an item in place (does not have to then copy it into the vector)
// push_back takes a fully constructed item copied into the vect (does have to copy it)
// Add to end of vector
v.push_back(val)
v.emplace_back(val)

// insert at index
v.insert(index, val)
v.emplace_back(index, val)

v.back() // get last element
```
