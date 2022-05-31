/**
 * test.cpp
 * Project UID: d27ac2f9d9ef51141f8207ca61bd9b22d96076f1
 * 
 * Adria
 * adias
 *
 * EECS 183: Project 2
 *
 * Testing functions for your birthdays.cpp implementation.
 * Holds the definitions of required testing functions.
 * We have stubbed all required functions for you.
 */

#include <cassert>
#include <cctype>
#include <iostream>
#include <limits>
#include <string>

using namespace std;


//************************************************************************
// You should have implemented the following functions in birthdays.cpp
//************************************************************************
int getMenuChoice();
bool isLeapYear (int year);
bool isGregorianDate(int m, int d, int y);
bool isValidDate(int month, int day, int year);
int determineDay (int month, int day, int year);
void printDayOfBirth(int day);
void determineDayOfBirth();
void print10LeapYears();

//************************************************************************
// Testing function declarations. Function definition is below main.
// Tests not run by these functions will not be run by the autograder.
//************************************************************************
void test_getMenuChoice();
void test_isGregorianDate();
void test_isLeapYear();
void test_isValidDate();
void test_determineDay();
void test_printDayOfBirth();
void test_determineDayOfBirth();
void test_print10LeapYears();

void startTests()
{
    // Write calls to your test functions here, e. g.,
    //test_getMenuChoice();
    test_isLeapYear();
    test_isGregorianDate();
    test_isValidDate();
    
    // Add more calls as you implement more functions.
    // While you're working on a function, it can be useful to comment
    //  out the calls to other functions' tests.

    // Make sure the only function you test in a test function
    //  like test_isGregorianDate is that function (isGregorianDate),
    //  or it may cause issues with the autograder.
}

void test_getMenuChoice()
{
    // getMenuChoice reads from cin, so you will need to
    // provide directions to the user for each test case
    cout << "Now testing funtion getMenuChoice()\n";
    
    //test 1 --valid
    cout << "Please enter 3:" << endl;
    int choice1 = getMenuChoice();
    cout << "Test result: expected: 3, actual: " << choice1 << endl;

    //test 2 --invalid
    cout << "Please enter 5 then 1:";
    int choice2 = getMenuChoice();
    cout << "Test result: " << endl;
    cout << "Expected: \"Invalid menu choice\", then 1." << endl;
    cout << "Actual: " << choice2 << endl;

    // Write additional tests here
    
    //test 3 --invalid
    cout << "Please enter 7:";
    int choice3 = getMenuChoice();
    cout << "Test result: " << endl;
    cout << "Expected: \"Invalid menu choice\"" << endl;
    cout << "Actual: " << choice3 << endl;
    
    //test 4 -- valid
    cout << "Please enter 3:" << endl;
    int choice4 = getMenuChoice();
    cout << "Test result: expected: 2, actual: " << choice4 << endl;
    
    //test 5-- valid
    cout << "Please enter 1:" << endl;
    int choice5 = getMenuChoice();
    cout << "Test result: expected: 1, actual: " << choice5 << endl;

    
}

void test_isGregorianDate()
{
    
    cout << "Now testing function isGregorianDate()\n";
    cout << "9/2/2019:  Expected: 1, Actual: " 
         << isGregorianDate(9, 2, 2019) << endl;
    cout << "1/31/1001: Expected: 0, Actual: "
         << isGregorianDate(1, 31, 1001) << endl;

    //is Gregorian
        cout << "Expected: 1, actual: "
             << isGregorianDate(8, 19, 2016) << endl;
        cout << "Expected: 0, actual: "
             << isGregorianDate(3, 15, 2030) << endl;
        cout << "Expected: 0, actual: "
             << isGregorianDate(9, 29, 2001) << endl;
        cout << "Expected: 0, actual: "
             << isGregorianDate(2, 12, 2005) << endl;
    
    //is not Gregorian
        cout << "Expected: 0, actual: "
             << isGregorianDate(3, 12, 1234) << endl;
        cout << "Expected: 0, actual: "
             << isGregorianDate(3, 2, 1009) << endl;
        cout << "Expected: 0, actual: "
             << isGregorianDate(33, 12, 1221) << endl;
        cout << "Expected: 0, actual: "
             << isGregorianDate(8, 1, 1750) << endl;
        cout << "Expected: 0, actual: "
             << isGregorianDate(4, 12, 1500) << endl;
    
    //edge case
        cout << "Expected: 0, actual: "
             << isGregorianDate(9, 13, 1752) << endl;
    
    
    cout << "Finished testing -- isGregorianDate()" << endl
         << endl;
}

void test_isLeapYear()
{

    cout << "Testing -- isLeapYear()" << endl;

    bool isLeapYear(int year);
    cout << "Expected: 1, actual: "
         << isLeapYear(int (2008)) << endl;
    cout << "Expected: 1, actual: "
         << isLeapYear(int (2002)) << endl;
    cout << "Expected: 1, actual: "
         << isLeapYear(int (2021)) << endl;
    cout << "Expected: 1, actual: "
         << isLeapYear(int (2004)) << endl;
    cout << "Expected: 1, actual: "
         << isLeapYear(int (2000)) << endl;
    cout << "Expected: 1, actual: "
         << isLeapYear(int (1900)) << endl;
    cout << "Finished testing -- isLeapYear()" << endl;
}

void test_isValidDate()
{
    cout << "Testing -- isValidDate()" << endl;
    
    cout << "Expected: 1, actual: "
         << isValidDate(4,29,2004) << endl;
    cout << "Expected: 1, actual: "
         << isValidDate(4,29,2004) << endl;
    cout << "Expected: 1, actual: "
         << isValidDate(1,10,1751) << endl;
    cout << "Expected: 1, actual: "
         << isValidDate(1,10,1978) << endl;
    cout << "Expected: 1, actual: "
         << isValidDate(9,14,1752) << endl;
    cout << "Expected: 1, actual: "
         << isValidDate(1,31,2002) << endl;
    cout << "Expected: 1, actual: "
         << isValidDate(6,30,2014) << endl;
    cout << "Expected: 1, actual: "
         << isValidDate(6,31,2004) << endl;
    cout << "Expected: 1, actual: "
         << isValidDate(4,29,2004) << endl;
    cout << "Expected: 1, actual: "
         << isValidDate(2,29,2008) << endl;
    
    
    
}

void test_determineDay()
{
    cout << "Expected: Monday, actual: "
         << determineDay(1, 14, 2008) << endl;
    cout << "Expected: Tuesday, actual: "
         << determineDay(2, 13, 1968) << endl;
    cout << "Expected: Friday, actual: "
         << determineDay(7, 2, 2021) << endl;
}

void test_printDayOfBirth()
{
    cout << "Now testing function printDayOfBirth()\n";
    cout << "1: Expected: Sunday, Actual: ";
    printDayOfBirth(1);
    cout << endl;

}

void test_determineDayOfBirth()
{
    // Write your tests here
}

void test_print10LeapYears()
{
    // Write your tests here
}
