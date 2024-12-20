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
v.push_back(val) // akzeptiert keine RValues, kopiert den Wert einfach immer.
v.emplace_back(val) // akzeptiert RValues und baut sie direkt in den Vektor ein (val wird nicht gebaut und dann in den Vektor kopiert)

// insert at index
v.insert(index, val)
//v.emplace_back(index, val)  // gibts ja gar nicht oder?

v.back() // get last element
v.first() // get first element
v.size() // get length of vector

// iterator to apply + operation to each element (numeric header)
template< class InputIt, class T >
T accumulate( InputIt first, InputIt last, T init);
// instead of + operation, you can give a function with 2 parameters here
template< class InputIt, class T, class BinaryOperation >
T accumulate( InputIt first, InputIt last, T init, BinaryOperation op );
```

# RValue and LValue
Ein LValue ist z.B. eine Variable, sie steht bei der Zuweisung links. Ein RValue wird gebaut. Wo dieser RValue gebaut wird ist durch den alleinigen RValue nicht sichtbar.
```cpp
// RValues werden direkt in die Variable geschrieben
int a = 8
std::string b = "Hallo" 
// LValues müssen kopiert werden, da ihr Wert noch verwendet werden könnte
std::string b2 = b  // Der Wert in a muss kopiert werden. Wenn a nicht mehr verwendet wird, ist das schlecht, weil  b2 ja auch einfach auf b zeigen könnte.
```
Ein RValue wird mit dem Referenz übergeben
```cpp
std::string&& ichBinEinRightValueReference
```
# Format
Zum formattieren gibt es eine library `#include <format>`. Ist neu und damit nicht in allen compilern enthalten.
Basis funktioniert so:
```cpp
std::format("formatString", in1, in2, in3);
// formatString examples
"{}", data // -> fügt data an der Position von {} ein. data kann jeder Datentyp sein : kann nur bei einfachen Anweisungen ausgelassen werden
"{0:}", data // -> Vor dem : kommt der index des Parameters, der an der Stelle eingefügt werden soll
"{:}", data // -> dasselbe (kein Index bedeutet Index 0)
"{1:}", data, data2 // -> data2 wird eingefügt

// INTEGER Formatierung (FUNKTIONIERT AUCH MIT STRINGS)
"{:+}", data // Optionales + gibt an, ob auch + signs angezeigt werden soll (5 oder +5), 
"{:4}", data // Zahl ist die Breite, die die Zahl immer mindestens einnimmt (mit spaces aufgefüllt). Wenn Zahl größer ist ist es größer. Default ist rechtsbündig
"{:^4}", data // Zahl wird zentriert ausgegeben
"{:<4}", data // Zahl wird linksbündig ausgegeben
":{>4}", data // Zahl wird rechtsbündig ausgegeben

"{: ^{}}", data, 6  // nested, die innere {} wird mit 6 eingesetzt, somit werden 6 Plätze reserviert

// FLOAT (wenn integer übergeben dann Fehler)
"{:.2}", data // ohne dem f gibt man die signifikaten Stellen an, die angezeigt werden sollen (scientific: EinerDezimalzahle+Potenz)
"{:.2f}", 5.2  // nach dem komma kommen 2 Stellen (mit 0 aufgefüllt)
"{:7.2f}", 5.2  // insgesamt bekommt die Zahl 7 Stellen (mit spaces aufgefüllt), 2 davon nach dem Komma und 1 für das Komma selbst.
// Wenn die Zahl mehr Nachkommastellen hat, wird gerundet!
```

# Unit tests
Fürs assert (Präprozessor Makro) braucht man die `#include <cassert>` library (c steht dafür, dass eine c Standardbibliothek benutzt wird). Nur für kleine tests. Für richtige wird Catch2, Google Test, and Boost verwendet.
```c++
assert(0 == 1);
>>> Assertion failed: 0 == 1, file main.cpp, line 119
```
Das Programm wird sofort beendet.

