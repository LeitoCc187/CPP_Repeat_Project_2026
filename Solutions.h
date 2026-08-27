#pragma once
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
 *Question 12 & 13 - BarChart class declaration
 */
class BarChart {
    private:
    GraphElement* elements; // Dynamic array (Q12a)
    size_t elementCount;
    size_t capacity;
    string title; // Q12b

    void resize(); // Helper to grow dynamic array

    public:
    BarChart(); // Default constructor
    BarChart(const string& chartTitle); // Only Title constructor
    BarChart(const string& chartTitle, size_t initialCapacity); // Full constructor
    BarChart(const BarChart& other); // Copy constructor
    ~BarChart(); // Destructor
    BarChart& operator=(const BarChart& other); // Assignment operator

    // Getters & setters (Q12)
    string getTitle() const;
    size_t getSize() const;
    GraphElement getElement(size_t index) const;

    void setTitle(const string& newTitle);
    void setElement(size_t index, const GraphElement& ge);
    void addElement(const GraphElement& ge);

    // Draw function (Q13)
    void draw() const;
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
