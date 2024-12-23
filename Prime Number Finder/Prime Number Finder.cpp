#include <iostream>
#include <cmath>

using namespace std;

bool checkPrime(uint64_t num) {
    // If input num is 1 or smaller, then it is not a prime
    if (num <= 1) {
        return false;
    }

    // If input num is 2 or 3 then it is a prime
    if (num == 2 || num == 3) {
        return true;
    }

    // If the remainder or the num / 2 or 3 is 0 then it is not a prime
    if (num % 2 == 0 || num % 3 == 0) {
        return false;
    }

    // Loops through every number up to the sqrt of num checking if any number can devide by it withought a remainder
    for (uint64_t i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main()
{
    uint64_t startNum;
    uint64_t endNum;
    uint64_t interval;
    bool printNonPrimes;
    string answer;

    cout << "What number would you like to start at: ";
    cin >> startNum;

    cout << "\nWhat number would you like to end at: ";
    cin >> endNum;

    cout << "\nHow many numbers would you like to go every iteration: ";
    cin >> interval;

    cout << "\nWould you like to print non-prime numbers (y/n): ";
    cin >> answer;

    if (answer == "y") {
        printNonPrimes = true;
    }
    else {
        printNonPrimes = false;
    }

    if (printNonPrimes) {
        for (uint64_t i = startNum; i <= endNum; i += interval) {
            if (checkPrime(i)) {
                cout << i << " is a prime number\n";
            }
            else {
                cout << i << " is not a prime number\n";
            }
        }
    }
    else {
        for (uint64_t i = startNum; i <= endNum; i += interval) {
            if (checkPrime(i)) {
                cout << i << " is a prime number\n";
            }
        }
    }
}

