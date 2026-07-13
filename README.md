# C++ Repeat Project 2026

A complete C++ console application demonstrating core programming concepts including STL containers,
dynamic memory management, file I/O, operator overloading, recursion, and class design.

## Project Structure
```
CPP_Repeat_Project_2026/
├── CMakeLists.txt      # Cmake build configuration (C++20)
├── main.cpp            # Menu-driven entry point (provided by lecturer)
├── Solutions.cpp       # Header with all class/struct declarations
├── Solutions.h         # Implementation of all 13 exercises
└── Data.csv            # Sample dataset (100 user records)
```

## Menu Navigation

After launching, enter a question number (1-13) to run that exercise, or '-1' to exit.

| QUestion | Topic |
|----------|-------|
| 1 | `std::list` reverse iterator |
| 2 | String array with star border & center aligment |
| 3 | `User` struct demonstration |
| 4 | CSV paring -> dynamic `User` objects -> formatted table |
| 5 | Sort dynamic `User` data by field |
| 6 | fill in |
| 7 | fill in |
| 8 | fill in |
| 9 | fill in |
| 10 | fill in |
| 11 | fill in |
| 12 | fill in |
| 13 | fill in |

> **Note: ** Run **Question 4** before **Question 5** so data is loaded into memory.

## Key Concepts Demonstrated

- **Iterators** - `std::list::const_reverse_iterator` (Q1)

## Memory Management

| Allocation | Deallocation Location |
| `new User()` per CSV row | `delete u` in Q4 cleanup loop |

## CSV Data Format

## Sample Output

## Author

- **Student:** D00281856
- **Module:** C++
- **Institution:** DKIT