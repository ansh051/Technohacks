#include <iostream>
#include <string>
#include <random>

std::string generateRandomPassword(int length) {
    // Characters to be used in the password
    const std::string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()";

    std::random_device rd; // Obtain a random number from hardware
    std::mt19937 eng(rd()); // Seed the random number generator
    std::uniform_int_distribution<> distr(0, characters.size() - 1); // Define the range

    std::string password;
    for (int i = 0; i < length; ++i) {
        password += characters[distr(eng)];
    }

    return password;
}

int main() {
    int passwordLength;

    std::cout << "Enter the desired length of the password: ";
    std::cin >> passwordLength;

    if (passwordLength <= 0) {
        std::cout << "Password length should be a positive integer." << std::endl;
        return 1;
    }

    std::string password = generateRandomPassword(passwordLength);
    std::cout << "Generated Password: " << password << std::endl;

    return 0;
}
