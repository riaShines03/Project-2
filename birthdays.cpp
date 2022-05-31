/**
 * birthdays.cpp
 * Project UID: d27ac2f9d9ef51141f8207ca61bd9b22d96076f1
 * 
 * Adria Shines
 * adrias
 *
 * EECS 183: Project 2
 *
 * <#description#>
 */

#include <cmath>
#include <iostream>
#include <string>

using namespace std;


/**
 * REQUIRES: nothing
 * MODIFIES: cout
 * EFFECTS:  Prints out the initial heading for the program
 */
void printHeading();


/**
 * REQUIRES: nothing
 * MODIFIES: cout
 * EFFECTS:  Prints out the final greeting for the program
 */
void printCloser();


/**
 * REQUIRES: nothing
 * MODIFIES: cout 
 * EFFECTS:  Prints the menu text. Does not read from cin.
 */
void printMenu();

/**
 * Note:  write your test cases in test.cpp BEFORE you implement this function
 *
 * REQUIRES: nothing
 * MODIFIES: cout, cin
 * EFFECTS:  1. Prints the menu
 *           2. Reads the input from the user
 *           3. Checks to make sure the input is within range for the menu
 *              If not prints "Invalid menu choice"
 *           4. Continues to print the menu and read an input until 
 *              a valid one is entered
 *           5. Returns the user's choice of menu options
 *           This function must call printMenu().
 */
int getMenuChoice();

/**
 * Note:  write your test cases in test.cpp BEFORE you implement this function
 *
 * REQUIRES: month, day, year represent a valid date
 * MODIFIES: nothing
 * EFFECTS:  Returns true if the date is in the limits
 *           of the Gregorian calendar otherwise returns false
 *           See the spec for definition of "limits of the Gregorian calendar"
 */
bool isGregorianDate(int month, int day, int year);
/**
 * Note:  write your test cases in test.cpp BEFORE you implement this function
 *
 * REQUIRES: year is a Gregorian year
 * MODIFIES: nothing
 * EFFECTS:  returns true if the year is a leap year
 *           otherwise returns false.
 *           See the spec for definition of a leap year.
 */

bool isLeapYear(int year);
/**
 * Note:  write your test cases in test.cpp BEFORE you implement this function
 *
 * REQUIRES: month, day, year may represent a date
 * MODIFIES: nothing
 * EFFECTS:  returns true if the date is valid
 *           otherwise returns false
 *           See the spec for definition of "valid"
 
 
 */
bool isValidDate(int month, int day, int year);

/**
 * Note:  write your test cases in test.cpp BEFORE you implement this function
 *
 * REQUIRES: month, day, year is a valid date
 *           i.e., the date passed to this function has already passed
 *               isValidDate()
 * MODIFIES: nothing
 * EFFECTS:  returns the value f that Zeller's formula calculates
 */
int determineDay(int month, int day, int year);

/**
 * Note:  write your test cases in test.cpp BEFORE you implement this function
 *
 * REQUIRES: day is a value of f output by Zeller's formula
*            (0 represents Saturday, 1 Sunday, 2 Monday, 3 Tuesday, etc)
 * MODIFIES: cout
 * EFFECTS:  prints the day of the week corresponding to day, suchas
 *           "Sunday", "Monday", ..., "Saturday"
 */
void printDayOfBirth(int day);

/**
 * Note:  write your test cases in test.cpp BEFORE you implement this function
 *
 * REQUIRES: nothing
 * MODIFIES: cout, cin
 * EFFECTS:  Asks for the month / day / year of the user's birthday.
 *           If the date is valid, it will print the day
 *           of the week you were born on
 *           Otherwise, it will print "Invalid date" prompt.
 */
void determineDayOfBirth();

/**
 * Note:  write your test cases in test.cpp BEFORE you implement this function
 *
 * REQUIRES: nothing
 * MODIFIES: cin, cout
 * EFFECTS:  Asks for a Gregorian year and prints the
 *           10 leap years after (not including) the year entered.
 *           If the year is invalid, it prints nothing.
 */
void print10LeapYears();
/* 
 * EFFECTS: Main driver for the Birthdays program. See the
 *          "Putting it Together" section of the spec for what
 *          this function needs to accomplish.
 */
void birthdays() {    
    // TODO: implement

    printHeading();
    int choice = getMenuChoice();
    while (choice != 3)  {
        if (choice == 1)    {
            determineDayOfBirth();
        }
        else {
            print10LeapYears();
        }
        choice = getMenuChoice();
    }
    printCloser();
}


void printHeading() {
    cout << "*******************************" << endl
         << "      Birthday Calculator      " << endl
         << "*******************************" << endl << endl;
    return;
}


void printCloser() {
    cout << endl;
    cout << "****************************************************" << endl
         << "      Thanks for using the Birthday Calculator      " << endl
         << "****************************************************" << endl
         << endl;
    return;
}


void printMenu() {
    cout << endl;
    cout << "Menu Options" << endl
         << "------------" << endl;
    cout << "1) Determine day of birth" << endl;
    cout << "2) Print the next 10 leap years" << endl;
    cout << "3) Finished" << endl << endl;
    
    cout << "Choice --> ";
    return;
}

int getMenuChoice() {
    printMenu();
        int userNumChoice;
        //reads the input from user
        cin >> userNumChoice;
            //checks to make sure input is within range
            //int userNumChoice;
            while ((userNumChoice != 1) && (userNumChoice != 2) && (userNumChoice != 3) )   {
                cout << "\nInvalid menu choice";
                cout << endl;
                printMenu();
                cin >> userNumChoice;
            }
    // returning 0 to avoid compile error
    cout << endl;
    return userNumChoice;
}

bool isGregorianDate(int month, int day, int year) {
    if (year > 1752)   {
        return true;
    }
    
    if (year == 1752)  {
        if (month == 9)  {
            if ((day >= 14) && (day <= 30)) {
                return true;
            }
        }
        else if (month > 9)     {
            if ((day >= 0) && (day <=31))   {
                return true;
            }
        }
        
    }
    
    else    {
        return false;
    }
    // returning false to avoid compile error
    return false;
}

bool isLeapYear(int year) {
    if ((year % 4) == 0)  {
        if ((year % 100) == 0)   {
            if ((year % 400) != 0)  {
                return false;
            }
        }
        return true;
    }
    else {
        return false;
    }
}

bool isValidDate(int month, int day, int year) {
    if (isGregorianDate (month, day, year)) {
        if ((month == 1) || (month == 3) || (month == 5) || (month == 7) || (month == 8)
            || (month == 10)|| (month == 12)){
            if ((day >= 1) && (day <=31))   {
                return true;
            }
        }
        else if ((month == 4) || (month == 6) || (month == 9)|| (month == 11)) {
            if ((day>=1) && (day <=30)) {
                return true;
        }
    }
        else if (month == 2){
            if ((day>=1) && (day <=28))   {
                return true;
            }
            else if (isLeapYear(year)) {
                if ((day >= 1) && (day <= 29))  {
                    return true;
                }
            }
                
        }
        
    }

    // returning false to avoid compile error
    return false;
}


int determineDay(int month, int day, int year) {

    if (month == 1) {
        month = 13;
        year--;
    }
    else if (month == 2) {
        month = 14;
        year--;
    }
       
   
    int exp1 = floor((13*(month+1))/5);
    int h = year % 100;
    int c = year / 100;
    int exp2 = floor(h/4) + floor(c/4);
    int exp3 = (5*c);
    
    int f = (day + exp1 + h + exp2 + exp3) % 7;
    
    return f;
    
}


void printDayOfBirth(int day) {
    // TODO: implement
    
    if (day == 0)    {
        cout << "Saturday" << endl;
    }
    if (day == 1)    {
        cout << "Sunday" << endl;
    }
    if (day == 2)    {
        cout << "Monday" << endl;
    }
    if (day == 3)    {
        cout << "Tuesday" << endl;
    }
    if (day == 4)    {
        cout << "Wednesday" << endl;
    }
    if (day == 5)    {
        cout << "Thursday" << endl;
    }
    if (day == 6)    {
        cout << "Friday" << endl;
    }

    return;
}


void determineDayOfBirth() {
    int month;
    int day;
    int year;
    int zday;
    char slash;
    
    cout << "Enter your date of birth" << endl;
    cout << "format: month / day / year  -->";
    // they get value here
    cin >> month >> slash >> day >> slash >> year;
    cout << endl;
    if (isValidDate(month, day, year) == false) {
        cout << "Invalid date" << endl;
    }
        else {
            zday = (determineDay(month, day, year));
            cout << "You were born on a: ";
            printDayOfBirth(zday);
            cout << endl;
        cout << "Have a great birthday!!!" << endl;
        
    }
    
    
    return;
}

void print10LeapYears() {
    cout << "Enter year --> ";
    int possible_Leap;
    cin >> possible_Leap;
    cout << endl;
    
    if(possible_Leap < 1752)   {
        return;
    }
    if(isLeapYear(possible_Leap))   {
        for( int i = 0; i < 10; i++)    {
            possible_Leap += 4;
            cout << "Leap year is " << possible_Leap << endl;
        }
    }
        
    else {
        while (!isLeapYear(possible_Leap))  {
            possible_Leap += 1;
        }
        if (isLeapYear(possible_Leap))  {
            for(int i = 0; i < 10; i++) {
                cout << "Leap year is " << possible_Leap << endl;
                possible_Leap += 4;
            }
        }
    }
}
