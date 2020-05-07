#include <iostream>
using namespace std;

// Defines values of single chars and returns value
int valueOf(char n) {
  if (n == 'I' || n == 'i') {
    return 1;
  }
  if (n == 'V' || n == 'v') {
    return 5;
  }
  if (n == 'X' || n == 'x') {
    return 10;
  }
  if (n == 'L' || n == 'l') {
    return 50;
  }
  if (n == 'C' || n == 'c') {
    return 100;
  }
}

// Converts string of roman numeral input #1 to integer
int convertRoman(string userInput) {
  int i;
  int n;
  int sumOne = 0;

  // Reads string from right to left.
  for (i = userInput.size() - 1; i >= 0; --i) {

    // Checks if user put in more than one numeral.
    if (userInput.size() > 1) {

      // If numeral is greater than numeral to its left, subtract and skip
      // numeral to left, then add to sumOne.
      if (valueOf(userInput[i]) > valueOf(userInput[i - 1])) {
        sumOne += (valueOf(userInput[i]) - valueOf(userInput[i - 1]));
        --i;

        // If value isn't larger than value to left, add value of numeral to
        // sumOne.
      } else if (valueOf(userInput[i]) <= valueOf(userInput[i - 1])) {
        sumOne += valueOf(userInput[i]);

      } // If user only inputs one numeral, add sumOne to value of that numeral.
    } else if (userInput.size() == 1) {
      sumOne += valueOf(userInput[0]);
    }
  }
  return sumOne;
}

// Converts integer to roman numeral.
int printRoman(int number) {
  // Array for arabicNumer.
  int arabicNumber[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500};

  // Array for string, which is called later to output
  string symbol[] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D"};

  int i = 10;

  // Checks to see if the ingeter which we are trying to convert is 0 yet
  while (number > 0) {

    // Sets an integer (in this case, g) to be the result of number
    // divided by the arabicNumber at i.
    int g = number / arabicNumber[i];

    // Sets number equal to the remainder of itself divided by the
    // arabicNumber at i.
    number = number % arabicNumber[i];

    // Iteratess through loop and outputs the symbol at i value
    for (g; g > 0; g--) {
      cout << symbol[i];
    }

    // Subtracts 1
    i--;
  }
}

// Checks if any part of an input string is a roman numeral or not.
bool checkIfRoman(string romanNumeral) {

  bool isRoman = true;
  // Loops through string and checks if anything is not a roman numeral.
  // If any character is not a roman, set bool isRoman to false.
  for (int i = romanNumeral.size() - 1; i >= 0; --i) {
    if (romanNumeral[i] != 'I' && romanNumeral[i] != 'i' &&
        romanNumeral[i] != 'V' && romanNumeral[i] != 'v' &&
        romanNumeral[i] != 'X' && romanNumeral[i] != 'x' &&
        romanNumeral[i] != 'L' && romanNumeral[i] != 'l' &&
        romanNumeral[i] != 'C' && romanNumeral[i] != 'c') {
      isRoman = false;
    }
  }
  return isRoman;
}

// Function prototypes
int valueOf(char n);
int convertRoman(string userInput);
bool checkIfRoman(string userInput);
int main() {

  string userInput1;
  string userInput2;
  int sumOfRomans;
  char calcAgain;

  do {
    // Take user input and store in userInput variables.
    cout << "Welcome to Roman Numeral Calculator!" << endl;
    cout << "Enter a roman numeral to begin: ";
    cin >> userInput1;

    // Check if input 1 has any non-numerals in it by calling checkIfRoman.
    while (checkIfRoman(userInput1) == false) {

      cout << "Error! Input was not valid roman numeral." << endl;
      cout << "Enter another roman numeral: ";
      cin >> userInput1;
    }
    cout << convertRoman(userInput1) << endl << endl;

    cout << "Enter a second roman numeral: ";
    cin >> userInput2;

    // Check if input 2 has any non-numerals in it by calling checkIfRoman.
    while (checkIfRoman(userInput2) == false) {

      cout << "Error! Input was not valid roman numeral." << endl;
      cout << "Enter another roman numeral: ";
      cin >> userInput2;
    }
    cout << convertRoman(userInput2) << endl << endl;

    // Sum of two roman numerals.
    sumOfRomans = convertRoman(userInput1) + convertRoman(userInput2);

    // Outputs sum of two numerals in integer form.
    cout << "Sum of " << userInput1 << " and " << userInput2
         << " is: " << sumOfRomans << endl;

    // Outputs sum in numeral form.
    cout << "In roman numeral form: ";
    printRoman(sumOfRomans);
    cout << endl << endl;

    // Asks if user wants to calculate again
    cout << "Would you like to calculate another sum? (y/n): ";
    cin >> calcAgain;

    // Checks for y or n answer. If not present, asks again.
    while ((calcAgain != 'y') && (calcAgain != 'Y') && (calcAgain != 'n') &&
           (calcAgain != 'N')) {
      cout << "Invalid input! Would you like to calculate another sum? (y/n): ";
      cin >> calcAgain;
    }
  } while ((calcAgain == 'y') || (calcAgain == 'Y'));

  return 0;
}