//
// Created by floodd on 21/02/2024.
//
#include <vector>
#include <list>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <sstream>
#include <cmath>
#include <stdexcept>
using namespace std;
/*
 *Question 3 - User struct (also used in Q4 & Q5)
 */
struct User
{
    // long long to handle large IDs from CSV
    long long id;
    string first_name;
    string last_name;
    string username;
    string department;
    string location;
};

/*
 *Question 10 & 11 - Fraction class declaration
 */
class Fraction {
private:
    int numerator;
    int denominator;

    int gcd(int a , int b) const;
    void simplify();

public:
    Fraction();
    Fraction(int num, int den);

    int getNumerator() const;
    int getDenominator() const;

    void setNumerator(int num);
    void setDenominator(int den);

    // Arithmetic operators (Q11a)
    Fraction operator+(const Fraction& other) const;
    Fraction operator-(const Fraction& other) const;
    Fraction operator*(const Fraction& other) const;
    Fraction operator/(const Fraction& other) const;

    // Comparison operators (Q11c)
    bool operator>(const Fraction& other) const;
    bool operator<(const Fraction& other) const;
    bool operator==(const Fraction& other) const;

    // Stream operators (Q11b)
    friend ostream& operator<<(ostream& os, const Fraction& frac);
    friend istream& operator>>(istream& is, Fraction& frac);
};

/*
 *Question 12 & 13 - GraphElement struct
 */
struct GraphElement {
    string title;
    int value;

    GraphElement() : title(""), value(0) {};
    GraphElement(const string& t, int v) : title(t), value(v) {};
};


/*
 * Question function declaration
 */
void question1();
void question2();
void question3();
void question4();
void question5();
void question6();
void question7();
void question8();
void question9();
void question10();
void question11();
void question12();
void question13();

