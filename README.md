# C++ Repeat Project 2026

A complete C++ console application demonstrating core programming concepts including STL containers, dynamic memory management, file I/O, operator overloading, recursion, and class design.

## Project Structure

```
CPP_Repeat_Project_2026/
├── CMakeLists.txt      # CMake build configuration (C++20)
├── main.cpp            # Menu-driven entry point (provided by lecturer)
├── Solutions.h         # Header with all class/struct declarations
├── Solutions.cpp       # Implementation of all 13 exercises
└── Data.csv            # Sample dataset (100 user records)
```

## Build Instructions

### Prerequisites
- CMake 3.10+
- A C++20 compatible compiler (GCC, Clang, MSVC)

### Build & Run

```bash
# Clone the repository
git clone https://github.com/LeitoCc187/CPP_Repeat_Project_2026
cd CPP_Repeat_Project_2026

# Generate build files
cmake -B build

# Compile
cmake --build build

# Run
./build/CPP_Repeat_Project_2026
```

On Windows (Visual Studio):
```cmd
cmake -B build
cmake --build build --config Release
.\build\Release\CPP_Repeat_Project_2026.exe
```

## Menu Navigation

After launching, enter a question number (1–13) to run that exercise, or `-1` to exit.

| Question | Topic |
|----------|-------|
| 1 | `std::list` reverse iterator |
| 2 | String array with star border & center alignment |
| 3 | `User` struct demonstration |
| 4 | CSV parsing → dynamic `User` objects → formatted table |
| 5 | Sort dynamic `User` data by field |
| 6 | Recursive ball bounce calculator |
| 7 | Most common character via pointer arithmetic |
| 8 | Caesar cipher encryption |
| 9 | Caesar cipher decryption |
| 10 | `Fraction` class — constructors, getters, setters |
| 11 | `Fraction` operator overloading (`+ - * /`, `<< >>`, `> < ==`) |
| 12 | `BarChart` class — deep copy, destructor, assignment |
| 13 | `BarChart::draw()` — ASCII bar chart visualization |

> **Note:** Run **Question 4** before **Question 5** so data is loaded into memory.

## Key Concepts Demonstrated

- **Iterators** — `std::list::const_reverse_iterator` (Q1)
- **Dynamic Memory** — `new`/`delete` for `User` structs and `char` arrays (Q4, Q7)
- **STL Algorithms** — `std::sort` with lambda comparators (Q5)
- **Recursion** — Base case + recursive step for bounce counting (Q6)
- **Pointer Arithmetic** — `*(arr + i)` instead of `arr[i]` (Q7)
- **Operator Overloading** — Friend functions, arithmetic, comparison, stream (Q11)
- **The Rule of Three** — Copy constructor, destructor, assignment operator for `BarChart` (Q12)
- **Deep Copy** — Manual allocation/copying to prevent double-free (Q12)
- **Encapsulation** — Private members, public getters/setters, input validation (Q10, Q12)

## Memory Management

| Allocation | Deallocation Location |
|------------|----------------------|
| `new User()` per CSV row | `delete u` in Q4 cleanup loop |
| `new char[size]` (Q7) | `delete[] arr` in `question7()` |
| `new GraphElement[capacity]` (BarChart) | `delete[] elements` in `~BarChart()` |
| `new GraphElement[capacity]` (resize) | `delete[] elements` old array after copy |
| `new GraphElement[capacity]` (copy/assign) | `delete[] elements` in `~BarChart()` |

## CSV Data Format

```csv
id,first_name,last_name,Username,Department,Location
```

The parser auto-detects and skips the header row.

## Sample Output

```
Please enter question number to run, -1 to end
4
ID           First Name       Last Name        Username             Department                   Location
-----------------------------------------------------------------------------------------------------------------------
2562172310   Britni           Khidr            bkhidr0              Marketing                    Sydney
5825210369   Gusella          Dozdill          gdozdill1            Sales                        Beijing
...
Loaded 100 users from Data.csv

Please enter question number to run, -1 to end
5
Sort by:
  1. Last Name
  2. Department
  3. Location
  4. Username
Enter choice (1-4): 1
Sorted by Last Name.
...

Please enter question number to run, -1 to end
13

Quarterly Sales
===============
Q1        |####################  (45)
Q2        |########################################  (80)
Q3        |###############  (35)
Q4        |##############################  (60)
```

## Author

- **Student:** Cole Cumiskey
- **Student Number:** D00281856
- **Module:** C++ Repeat Project 2026
- **Institution:** DKIT
