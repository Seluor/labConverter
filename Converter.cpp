#include <iostream>
#include <string>

using namespace std;

void fromArabicToRoman(int inputArabicNumber) {
    const string unitsRoman[10] = { "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" },
        tensRoman[10] = { "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" },
        hundredsRoman[10] = { "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" };

    int units = inputArabicNumber % 10;
    int tens = inputArabicNumber % 100 / 10;
    int hundreds = inputArabicNumber % 1000 / 100;
    int thousands = inputArabicNumber / 1000;

    string thousandsRoman = "";

    for (int thousandsCounter = thousands; thousandsCounter > 0; --thousandsCounter) {
        thousandsRoman += "M";
    }
    cout << "\n Arabic " << inputArabicNumber << " in Roman: " << thousandsRoman << hundredsRoman[hundreds] << tensRoman[tens] << unitsRoman[units] << endl << '\n';
}

void convertRomanToArabic(string inputRomanNumber) {
    int number = int(inputRomanNumber.length());  // "lenght()" - определяет длину строки 
    int result = 0;
    for (int index = 0; index < number; ++index) {
        switch (inputRomanNumber[index]) {  // "switch" - конструкция, к-я сравнивает перем-ю с несколькими константными знач-ми
        case 'I':
            result += 1; break;
        case 'V':
            result += 5; break;
        case 'X':
            result += 10; break;
        case 'L':
            result += 50; break;
        case 'C':
            result += 100; break;
        case 'D':
            result += 500; break;
        case 'M':
            result += 1000; break;
        }
    }

    for (int index = 1; index < number; ++index) {
        if ((inputRomanNumber[index] == 'V' || inputRomanNumber[index] == 'X' || inputRomanNumber[index] == 'L' ||
            inputRomanNumber[index] == 'C' || inputRomanNumber[index] == 'D' || inputRomanNumber[index] == 'M') && inputRomanNumber[index - 1] == 'I') {
            result -= 1 + 1;
        }

        if ((inputRomanNumber[index] == 'X' || inputRomanNumber[index] == 'L' || inputRomanNumber[index] == 'C' ||
            inputRomanNumber[index] == 'D' || inputRomanNumber[index] == 'M') && inputRomanNumber[index - 1] == 'V') {
            result -= 5 + 5;
        }

        if ((inputRomanNumber[index] == 'L' || inputRomanNumber[index] == 'C' || inputRomanNumber[index] == 'D' ||
            inputRomanNumber[index] == 'M') && inputRomanNumber[index - 1] == 'X') {
            result -= 10 + 10;
        }

        if ((inputRomanNumber[index] == 'C' || inputRomanNumber[index] == 'D' || inputRomanNumber[index] == 'M') && inputRomanNumber[index - 1] == 'L') {
            result -= 50 + 50;
        }

        if ((inputRomanNumber[index] == 'D' || inputRomanNumber[index] == 'M') && inputRomanNumber[index - 1] == 'C') {
            result -= 100 + 100;
        }

        if ((inputRomanNumber[index] == 'M') && inputRomanNumber[index - 1] == 'D') {
            result -= 500 + 500;
        }
    }
    cout << "\n Roman " << inputRomanNumber << " in Arabic: " << result << endl;
}

int main() {
    int inputArabicNumber;
    string inputRomanNumber;
    string yourChoice;
    cout << " Enter <R>, if u want convert to Roman. Else enter <A>: ";
    cin >> yourChoice;

    if (yourChoice == "R" || yourChoice == "A") {
        if (yourChoice == "R") {
            cout << "\n What Arabic number do you want to convert: ";
            cin >> inputArabicNumber;
            fromArabicToRoman(inputArabicNumber);
        }
        if (yourChoice == "A") {
            cout << "\n What Roman number do you want to convert: ";
            cin >> inputRomanNumber;
            convertRomanToArabic(inputRomanNumber);
        }
    }
    else {
        cout << " Error of Enter;";
        return -1;
    }
}