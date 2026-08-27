#include "Solutions.h"
/*
 * Global data store for Questions 4 & 5
 * (persists between menu selections so Q5 can sort Q4's data)
 */
static vector<User*> userDatabase;

/*
 *  1.	Write a function that accepts a std::list of integers and display the elements
 *      in reverse order using an appropriate iterator.
 *
 */
void displayReverse(const list<int>& lst)
{
    cout << "Elements in reverse order: ";
    for (list<int>::const_iterator it = lst.rbegin(); it != lst.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

void question1()
{
    cout << "Question 4" << endl;
    list<int> numbers = {10,20,30,40,50,60};
    displayReverse(numbers);
}

/*
 *
 *  2.	Write a function that will accept an array of strings and *  display them,
 *      one per line, in a border of stars ‘*’, with the text center-aligned. *
 */
void displayInBorder(const string* arr, size_t size)
{
    if (size == 0 || arr == nullptr)
    {
        cout << "Empty array provided." << endl;
        return;
    }

    // Find the longest string to determine box width
    size_t maxLen = 0;
    for (size_t i = 0; i < size; i++)
    {
        if (arr[i].length() > maxLen) maxLen = arr[i].length();
    }

    // Inner width includes 1 space padding on each side minimum
    size_t innerWidth = maxLen + 2;
    // +2 for the side stars
    string border(innerWidth + 2, '*');

    cout << border << endl;
    for (size_t i = 0; i < size; i++)
    {
        size_t totalPadding = innerWidth - arr[i].length();
        size_t leftPad = totalPadding / 2;
        size_t rightPad = totalPadding - leftPad;
        cout << '*' << string(leftPad, ' ') << arr[i] << string(rightPad, ' ') << '*' << endl;
    }
    cout << border << endl;
}

void question2()
{
    cout << "Question 4" << endl;
    string phrases[] = {"Hello", "World", "C++ Programming", "Assignment"};
    displayInBorder(phrases, 4);
}

/*
*   3.	Create a struct to represent a User with the following fields.
            a.	Username
            b.	Identifier
            c.	First Name
            d.	Last Name
            e.	Department
            f.	Location

 */
void question3() {
    cout << "Question 3" << endl;
    User u;
    u.id = 1001;
    u.first_name = "John" ;
    u.last_name = "Smith";
    u.username = "jsmith";
    u.department = "Engineering";
    u.location = "Dublin";

    cout << "User struct created with the following fields: " << endl;
    cout << "  ID:          " << u.id << endl;
    cout << "  First Name:  " << u.first_name << endl;
    cout << "  Last Name:   " << u.last_name << endl;
    cout << "  Username:    " << u.username << endl;
    cout << "  Department:  " << u.department << endl;
    cout << "  Location:    " << u.location << endl;
}

/*
 *  4.	Read data from the CSV file “Data.csv” and for each row create a new instance of the
 *      struct created in part 3 in the dynamic area of memory, store all the data, and then display
 *      the data from storage as a neatly formatted table.
 */
void question4()
{
    cout << "Question 4" << endl;
    //Good memory management: clear and previously loaded data first
    for (User* u : userDatabase)
    {
        delete u;
    }
    userDatabase.clear();

    ifstream file("Data.csv");
    if (!file.is_open())
    {
        cerr << "Error: Could not open Data.csv" << endl;
        return;
    }

    string line;
    bool firstLine = true;
    while (getline(file, line))
    {
        if (line.empty()) continue;

        stringstream ss(line);
        string token;
        vector<string> tokens;
        while (getline(ss, token, ','))
        {
            tokens.push_back(token);
        }

        if (tokens.size() < 6) continue;

        // Skip header row
        if (firstLine)
        {
            firstLine = false;
            try
            {
                stoll(tokens[0]);
            }
            catch (...)
            {
                continue; // This line is a header
            }
        }

        // Create User in dynamic memory (heap)
        User* newUser = new User();
        newUser->id = stoll(tokens[0]);
        newUser->first_name = tokens[1];
        newUser->last_name = tokens[2];
        newUser->username = tokens[3];
        newUser->department = tokens[4];
        newUser->location = tokens[5];
        userDatabase.push_back(newUser);
    }
    file.close();

    // Display neatly formatted table
    cout << left << setw(15) << "ID"
        << setw(18) << "First Name"
        << setw(18) << "Last Name"
        << setw(20) << "Username"
        << setw(30) << "Department"
        << setw(18) << "Location" << endl;
    cout << string(119, '-') << endl;

    for (const User* u : userDatabase)
    {
        cout << left << setw(15) << u->id
        << setw(18) << u->first_name
        << setw(18) << u->last_name
        << setw(20) << u->username
        << setw(30) << u->department
        << setw(18) << u->location << endl;
    }
    cout << "\nLoaded " << userDatabase.size() << " users from Data.csv" << endl;
}

/*
*   5.	Write a function that will allow the user to sort the data from question 4 by any of the following:
            a.	Last Name
            b.	Department
            c.	Location
            d.	Username

 */
void question5() {
    cout << "Question 5" << endl;
}
/*
 *  6.    Write a recursive function to determine how many times a ball will bounce if it is dropped
 *      from a height X m, and  *reaches 2/3 of its previous height each bounce. (You may assume the ball
 *      has stopped when it reaches a height of less than 0.5m).
 */

void question6() {
    cout << "Question 6" << endl;
}

/*
 *  7.	Write a function that will accept a pointer to a Dynamic array of characters and find the most
 *      common character. Pointer arithmetic MUST be used.
 */
void question7() {
    cout << "Question 7" << endl;
}

/*
 *8.	Write a function to encrypt a string using the Caesar cipher. You only need to consider
 *      the lower-case characters a-z. All other characters will remain as is.
 */
void question8() {
    cout << "Question 8" << endl;
}

/*
 *   9.	Write a function to decrypt a string using the Caesar cipher. You only need to consider the
 *      lower-case characters a-z. All other characters will remain as is.
 */
void question9() {
    cout << "Question 9" << endl;
}
/*
 *  10.	Create a class to represent a fraction. Each fraction should have a numerator and denominator.
 *      In this class you should add full and default constructor, getters and setters for all fields.
 *
 *      Test your class here.
 */
void question10() {
    cout << "Question 10" << endl;
}
/*
*  11.	For the class fraction overload the following operators:
        a.	Add, subtract, multiply, divide operators
        b.	Stream insertion and stream extraction operators.
        c.	Greater than, Less than, and comparison operators.

        Test your class here.

 */

void question11() {
    cout << "Question 11" << endl;
}

/*
*   12.	Create a class Called “BarChart” the contains the fields listed below. In this class you should
*   add full and default constructor, getters and setters for all fields, Copy Constructor, Destructor
*   and overload the equals (“=”) operator.
            a.	a dynamic array of GraphElements
            b.	Title

    Use the struct defined below and test class here.

 */
struct GraphElement {
    string title;
    int value;
};
void question12() {
    cout << "Question 12" << endl;
}


/*
 *  13.	Add a function to the class “BarChart” that will draw a visual representation of
 *  the data in the array. See Below for a sample output.
 */

void question13() {
    cout << "Question 13" << endl;
}