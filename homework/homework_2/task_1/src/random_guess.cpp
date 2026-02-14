#include <iostream>
#include <random>
#include <string>

int main(){
    int guess;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0,99);
    const int random_num = dist(rd);
    while (true){
        std::cout<<"Enter your guess: ";
        std::cin >> guess;
        if (std::cin.fail()) {
            std::cerr << "[WARNING] : Number must be between 0 and 99" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        if (guess < 0 || guess > 99) {
            std::cerr << "[WARNING] : Number must be between 0 and 99" << std::endl;
            continue;
        }

        if (guess == random_num) {
            std::cout << "You have won. The number was "
                      << random_num << std::endl;
            return EXIT_SUCCESS;
        }

        if (guess > random_num) {
            std::cout << "Its number is smaller." << std::endl;
        } else {
            std::cout << "Its number is larger." << std::endl;
        }
    }
    std::cout << "Error encountered, exiting... "
              << random_num << std::endl;

    return EXIT_FAILURE;

}