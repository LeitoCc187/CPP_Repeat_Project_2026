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
    for (list<int>::const_reverse_iterator it = lst.crbegin(); it != lst.crend(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

void question1()
{
    cout << "Question 1" << endl;
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
    cout << "Question 2" << endl;
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

    ifstream file("..\\Data.csv");
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
    if (userDatabase.empty()) {
        cout << "No data loaded. Please run Question 4 first." << endl;
        return;
    }

    cout << "Sort by:" << endl;
    cout << "  1. Last Name" << endl;
    cout << "  2. Department" << endl;
    cout << "  3. Loaction" << endl;
    cout << "  4. Username" << endl;
    cout << "Enter choice (1-4): ";

    int choice;
    string input;
    getline(cin, input);
    stringstream(input) >> choice;

    switch (choice) {
        case 1:
            sort(userDatabase.begin(), userDatabase.end(), [](User* a, User* b) {return a->last_name < b->last_name;});
            cout << "Sorted by Last Name." << endl;
            break;
        case 2:
            sort(userDatabase.begin(), userDatabase.end(), [](User* a, User* b) {return a->department < b->department;});
            cout << "Sorted by Department." << endl;
            break;
        case 3:
            sort(userDatabase.begin(), userDatabase.end(), [](User* a, User* b) {return a->location < b->location;});
            cout << "Sorted by Location." << endl;
            break;
        case 4:
            sort(userDatabase.begin(), userDatabase.end(), [](User* a, User* b) {return a->username < b->username;});
            cout << "Sorted by Username." << endl;
            break;
        default:
            cout << "Invalid choice." << endl;
            return;
    }

    // Display sorted table
    cout << left << setw(15) << "ID"
    << setw(18) << "First Name"
    << setw(18) << "Last Name"
    << setw(20) << "Username"
    << setw(30) << "Department"
    << setw(18) << "Location" << endl;
    cout << string(119, '-') << endl;

    for (const User* u : userDatabase) {
        cout << left << setw(15) << u->id
        << setw(18) << u->first_name
        << setw(18) << u->last_name
        << setw(20) << u->username
        << setw(30) << u->department
        << setw(18) << u->location << endl;
    }
}
/*
 *  6.    Write a recursive function to determine how many times a ball will bounce if it is dropped
 *      from a height X m, and  *reaches 2/3 of its previous height each bounce. (You may assume the ball
 *      has stopped when it reaches a height of less than 0.5m).
 */
int countBounces(double height) {
    // Base case: ball has stopped bouncing
    if (height < 0.5) {
        return 0;
    }
    // Recursive case: this bounce counts, plus future bounces from new height
    return 1 + countBounces(height * 2.0 / 3.0);
}

void question6() {
    cout << "Enter drop height (m): ";
    double height;
    string input;
    getline(cin, input);
    stringstream(input) >> height;

    if (height <= 0) {
        cout << "Height must be positive." << endl;
        return;
    }

    int bounces = countBounces(height);
    cout << "Ball dropped from " << height << "m will bounce "
    << bounces << " times before reaching < 0.5m." << endl;
}

/*
 *  7.	Write a function that will accept a pointer to a Dynamic array of characters and find the most
 *      common character. Pointer arithmetic MUST be used.
 */
char mostCommonChar(const char* arr, size_t size) {
    if (arr == nullptr || size == 0) {
        return '\0';
    }

    int frequency[256] = {0}; // ASCII frequency table

    // Pointer arithmetic used here: *(arr +i)
    for (size_t i = 0; i < size; ++i) {
        unsigned char c = static_cast<unsigned char>(*(arr + i));
        frequency[c]++;
    }

    int maxFreq = 0;
    char mostCommon = *arr;

    for (size_t i = 0; i < size; ++i) {
        unsigned char c = static_cast<unsigned char>(*(arr + i));
        if (frequency[c] > maxFreq) {
            maxFreq = frequency[c];
            mostCommon = static_cast<char>(c);
        }
    }

    return mostCommon;
}

void question7() {
    cout << "Question 7" << endl;
    size_t size;
    string input;
    cout << "Enter number of characters: ";
    getline(cin, input);
    stringstream(input) >> size;

    if (size <= 0) {
        cout << "Size must be greater than 0." << endl;
        return;
    }

    // Dynamic array of characters
    char* arr = new char[size];
    cout << "Enter " << size << " Characters (no spaces): ";
    for (size_t i = 0; i < size; ++i) {
        cin >> arr[i];
    }
    cin.ignore(); // Clear newline after cin >>

    char result = mostCommonChar(arr, size);
    cout << "Most common character: '" << result << "'" << endl;

    delete[] arr; // Good memory management
}

/*
 *8.	Write a function to encrypt a string using the Caesar cipher. You only need to consider
 *      the lower-case characters a-z. All other characters will remain as is.
 */
string caesarEncrypt(const string& text, int shift) {
    string result = text;
    for (size_t i = 0; i < text.length(); ++i) {
        if (result[i] >= 'a' && result[i] <= 'z') {
            result[i] = 'a' + (result[i] - 'a' + shift) % 26;
        }
    }
    return result;
}

void question8() {
    cout << "Question 8" << endl;
    cout << "Enter text to encrypt (a-z only shifted): ";
    string text;
    getline(cin, text);

    string encrypted = caesarEncrypt(text, 3);
    cout << "Encrypted: " << encrypted << endl;
}

/*
 *   9.	Write a function to decrypt a string using the Caesar cipher. You only need to consider the
 *      lower-case characters a-z. All other characters will remain as is.
 */
string caesarDecrypt(const string& text, int shift) {
    string result = text;
    for (size_t i = 0; i < text.length(); ++i) {
        if (result[i] >= 'a' && result[i] <= 'z') {
            // Add 26 before modulo to avoid negtive numbers
            result[i] = 'a' + (result[i] - 'a' - shift + 26) % 26;
        }
    }
    return result;
}

void question9() {
    cout << "Question 9" << endl;
    cout << "Enter text to decrypt (a-z only shifted): ";
    string text;
    getline(cin, text);

    string decrypted = caesarDecrypt(text, 3);
    cout << "Decrypted: " << decrypted << endl;
}
/*
 *  10.	Create a class to represent a fraction. Each fraction should have a numerator and denominator.
 *      In this class you should add full and default constructor, getters and setters for all fields.
 *
 *      Test your class here.
 */
// Fraction class implementation

int Fraction::gcd(int a, int b) const {
    a = abs(a);
    b = abs(b);
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void Fraction::simplify() {
    // Ensure denominator is always positive
    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }
    int g = gcd(numerator, denominator);
    if (g != 0) {
        numerator /= g;
        denominator /= g;
    }
    if (numerator == 0) {
        denominator = 1;
    }
}

Fraction::Fraction() : numerator(0), denominator(1) {}

Fraction::Fraction(int num, int den) : numerator(num), denominator(den) {
    if (den == 0) {
        throw invalid_argument("Denominator cannot be zero.");
    }
    simplify();
}

int Fraction::getNumerator() const {return numerator;}
int Fraction::getDenominator() const {return denominator;}

void Fraction::setNumerator(int num) {
    numerator = num;
    simplify();
}

void Fraction::setDenominator(int den) {
    if (den == 0) {
        throw invalid_argument("Denominator cannot be zero.");
    }
    denominator = den;
    simplify();
}

void question10() {
    cout << "Question 10" << endl;
    cout << "--- Testing Fraction Class --" << endl;

    // Default constructor
    Fraction f1;
    cout << "Default fraction: " << f1 << endl;

    // Full constructor
    Fraction f2(6, 8); // Should simplify to 3/4
    cout << "Fraction(6, 8) simplified: " << f2 << endl;

    // Getters
    cout << "Numerator: " << f2.getNumerator() << endl;
    cout << "Denominator: " << f2.getDenominator() << endl;

    // Setters
    f2.setNumerator(9);
    cout << "After setNumerator(9): " << f2 << endl;
    f2.setDenominator(12);
    cout << "After setDenominator(12): " << f2 << endl;
}
/*
*  11.	For the class fraction overload the following operators:
        a.	Add, subtract, multiply, divide operators
        b.	Stream insertion and stream extraction operators.
        c.	Greater than, Less than, and comparison operators.

        Test your class here.

 */
Fraction Fraction::operator+(const Fraction& other) const {
    return Fraction(numerator * other.denominator + other.numerator * denominator, denominator * other.denominator);
}

Fraction Fraction::operator-(const Fraction& other) const {
    return Fraction(numerator * other.denominator - other.numerator * denominator, denominator * other.denominator);
}

Fraction Fraction::operator*(const Fraction& other) const {
    return Fraction(numerator * other.numerator, denominator * other.denominator);
}

Fraction Fraction::operator/(const Fraction& other) const {
    if (other.numerator == 0) {
        throw invalid_argument("Cannot divide by a fraction with numerator zero.");
    }
    return Fraction(numerator * other.denominator, denominator * other.numerator);
}

bool Fraction::operator>(const Fraction& other) const {
    return numerator * other.denominator > other.numerator * denominator;
}

bool Fraction::operator<(const Fraction& other) const {
    return numerator * other.denominator < other.numerator * denominator;
}

bool Fraction::operator==(const Fraction& other) const {
    return numerator == other.numerator && denominator == other.denominator;
}

ostream& operator<<(ostream& os, const Fraction& frac) {
    os << frac.numerator << "/" << frac.denominator;
    return os;
}

istream& operator>>(istream& is, Fraction& frac) {
    char slash;
    is >> frac.numerator >> slash >> frac.denominator;
    if (frac.denominator == 0) {
        throw invalid_argument("Denominator cannot be zero.");
    }
    frac.simplify();
    return is;
}

void question11() {
    cout << "Question 11" << endl;
    cout << "--- Testing Fraction operators ---" << endl;

    Fraction f1(3, 4);
    Fraction f2(1, 3);

    cout << "f1 = " << f1 << ", f2 = " << f2 << endl;
    cout << "f1 + f2 = " << (f1 + f2)<< endl;
    cout << "f1 - f2 = " << (f1 - f2)<< endl;
    cout << "f2 * f1 = " << (f2 * f1)<< endl;
    cout << "f1 / f2 = " << (f1 / f2)<< endl;
    cout << "f1 > f2 = " << (f1 > f2 ? "true" : "false")<< endl;
    cout << "f1 < f2 = " << (f1 < f2 ? "true" : "false")<< endl;
    cout << "f1 == f2 = " << (f1 == f2 ? "true" : "false")<< endl;

    // Stream extraction test
    stringstream ss("5/8");
    Fraction f3;
    ss >> f3;
    cout << "Stream extracted: " << f3 << endl;
}

/*
*   12.	Create a class Called “BarChart” the contains the fields listed below. In this class you should
*   add full and default constructor, getters and setters for all fields, Copy Constructor, Destructor
*   and overload the equals (“=”) operator.
            a.	a dynamic array of GraphElements
            b.	Title

    Use the struct defined below and test class here.

 */
void BarChart::resize() {
    size_t newCapacity = (capacity == 0) ? 2 : capacity * 2;
    GraphElement* newArray = new GraphElement[newCapacity];
    for (size_t i = 0; i < elementCount; i++) {
        newArray[i] = elements[i];
    }
    delete[] elements; // Good memory management: delete old array
    elements = newArray;
    capacity = newCapacity;
}

BarChart::BarChart() : elements(nullptr), elementCount(0), capacity(0), title("") {
    capacity = 2;
    elements = new GraphElement[capacity];
}

BarChart::BarChart(const string& chartTitle) : elements(nullptr), elementCount(0), capacity(2), title(chartTitle) {
    elements = new GraphElement[capacity];
}

BarChart::BarChart(const string& chartTitle, size_t initialCapacity) : elements(nullptr), elementCount(0), capacity(initialCapacity), title(chartTitle) {
    if (capacity == 0) capacity = 2;
    elements = new GraphElement[capacity];
}

// Copy constructor (deep copy)
BarChart::BarChart(const BarChart& other) : elements(new GraphElement[other.capacity]), elementCount(other.elementCount), capacity(other.capacity), title(other.title) {
    for (size_t i = 0; i < elementCount; i++) {
        elements[i] = other.elements[i];
    }
}

BarChart::~BarChart() {
    delete[] elements; // Good memory management
}

// Assignment operator (deep copy)
BarChart& BarChart::operator=(const BarChart& other) {
    if (this != &other) { // Self-assignment check
        delete[] elements;
        capacity = other.capacity;
        elementCount = other.elementCount;
        title = other.title;
        elements = new GraphElement[capacity];
        for (size_t i = 0; i < elementCount; i++) {
            elements[i] = other.elements[i];
        }
    }
    return *this;
}

string BarChart::getTitle() const {
    return title;
}

size_t BarChart::getSize() const {
    return elementCount;
}

GraphElement BarChart::getElement(size_t index) const {
    if (index >= elementCount) {
        throw out_of_range("Index out of bounds.");
    }
    return elements[index];
}

void BarChart::setTitle(const string& newTitle) {
    title = newTitle;
}

void BarChart::setElement(size_t index, const GraphElement& ge) {
    if (index >= elementCount) {
        throw out_of_range("Index out of bounds.");
    }
    elements[index] = ge;
}

void BarChart::addElement(const GraphElement& ge) {
    if (elementCount >= capacity) {
        resize();
    }
    elements[elementCount++] = ge;
}

void question12() {
    cout << "Question 12" << endl;
    cout << "--- Testing BarChart class ---" << endl;

    // Default
    BarChart chart1;
    chart1.setTitle("Default Chart");
    chart1.addElement(GraphElement{"A", 10});
    chart1.addElement(GraphElement{"B", 20});

    cout << "Chart 1 title: " << chart1.getTitle() << endl;
    cout << "Chart 1 size: " << chart1.getSize() << endl;
    cout << "Element 0: " << chart1.getElement(0).title << " = " << chart1.getElement(0).value << endl;

    // Full constructor
    BarChart chart2("Full Constructir Chart", 5);
    chart2.addElement(GraphElement{"X", 30});
    cout << "Chart 2 title: " << chart2.getTitle() << endl;

    // Copy constructor (deep copy)
    BarChart copyChart = chart1;
    cout << "Copy chart title: " << copyChart.getTitle() << endl;
    cout << "Copy chart size: " << copyChart.getSize() << endl;

    // Assignment operator (deep copy)
    BarChart assignedChart;
    assignedChart = chart1;
    cout << "Assigned chart title: " << assignedChart.getTitle() << endl;
    cout << "Assigned chart size: " << assignedChart.getSize() << endl;

    // Test setter
    assignedChart.setElement(0, GraphElement{"Modified", 99});
    cout << "After setElement(0) on assignedChart:" << endl;
    cout << "  assignedChart[0]: " << assignedChart.getElement(0).title << " = " << assignedChart.getElement(0).value << endl;
    cout << "  chart1[0] (unchanged): " << chart1.getElement(0).title << " = " << chart1.getElement(0).value << endl;
}

/*
 *  13.	Add a function to the class “BarChart” that will draw a visual representation of
 *  the data in the array. See Below for a sample output.
 */
void BarChart::draw() const {
    if (elementCount == 0) {
        cout << "Empty BarChart. Noting to draw." << endl;
        return;
    }

    // find max value and longest label from formatting
    int maxValue = 0;
    size_t maxLabelLen = 0;
    for (size_t i = 0; i < elementCount; i++) {
        if (elements[i].value > maxValue) maxValue = elements[i].value;
        if (elements[i].title.length() > maxLabelLen) maxLabelLen = elements[i].title.length();
    }

    cout << "\n" << title << endl;
    cout << string(title.length(), '=') << endl;
    const int Max_BAR_WIDTH = 40;
    for (size_t i = 0; i < elementCount; i++) {
        cout << left << setw(maxLabelLen + 2) << elements[i].title << "|";
        int barLength = (maxValue > 0) ? (elements[i].value * Max_BAR_WIDTH / maxValue) : 0;
        cout << string(barLength, '#') <<  " (" << elements[i].value << ")" << endl;
    }
    cout << endl;
}

void question13() {
    cout << "Question 13" << endl;
    cout << "--- Testing BarChart::draw() ---" << endl;

    BarChart chart("Quarterly Sales");
    chart.addElement(GraphElement("Q1", 45));
    chart.addElement(GraphElement("Q2", 80));
    chart.addElement(GraphElement("Q3", 35));
    chart.addElement(GraphElement("Q4", 60));
    chart.draw();

    // Demonstrate copy constructor works with draw
    BarChart copiedChart = chart;
    copiedChart.setTitle("Copied Chart (copy Constructor)");
    copiedChart.draw();

    // Demonstrate assignment operator works with draw
    BarChart assignedChart;
    assignedChart = chart;
    assignedChart.setTitle("Assigned Chart (= Operator)");
    assignedChart.draw();
}