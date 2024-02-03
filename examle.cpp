#include <iostream>
#include <random>

enum class Choice {
    Rock,
    Paper,
    Scissors
};

Choice getUserChoice() {
    char choice;
    while (true) {
        std::cout << "Enter your choice (r/p/s): ";
        std::cin >> choice;
        if (choice == 'r') {
            return Choice::Rock;
        } else if (choice == 'p') {
            return Choice::Paper;
        } else if (choice == 's') {
            return Choice::Scissors;
        } else {
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }
}

Choice getComputerChoice() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<> dis(0, 2);
    return static_cast<Choice>(dis(gen));
}

const char* choiceToString(Choice choice) {
    switch (choice) {
        case Choice::Rock:
            return "Rock";
        case Choice::Paper:
            return "Paper";
        case Choice::Scissors:
            return "Scissors";
    }
    return "";
}

bool isUserWin(Choice userChoice, Choice computerChoice) {
    if (userChoice == computerChoice) {
        return false;
    } else if (userChoice == Choice::Rock) {
        return computerChoice == Choice::Scissors;
    } else if (userChoice == Choice::Paper) {
        return computerChoice == Choice::Rock;
    } else {
        return computerChoice == Choice::Paper;
    }
}

int main() {
    while (true) {
        Choice userChoice = getUserChoice();
        Choice computerChoice = getComputerChoice();
        std::cout << "User chose " << choiceToString(userChoice) << std::endl;
        std::cout << "Computer chose " << choiceToString(computerChoice) << std::endl;
        if (isUserWin(userChoice, computerChoice)) {
            std::cout << "User wins!" << std::endl;
        } else if (isUserWin(computerChoice, userChoice)) {
            std::cout << "Computer wins!" << std::endl;
        } else {
            std::cout << "It's a tie!" << std::endl;
        }
        std::cout << "Do you want to play again? (y/n): ";
        char choice;
        std::cin >> choice;
        if (choice != 'y') {
            break;
        }
    }
    return 0;
}