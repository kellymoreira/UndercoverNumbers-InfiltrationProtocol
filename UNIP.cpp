#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty) {
    std::cout << "\n\nYou are a secret agent from the FBI infiltrating LEVEL " << Difficulty; 
    std::cout << " security server room. \nYou need to enter the RIGHT numbers to continue!\n\n";

}

bool PlayGame(int Difficulty) {

    PrintIntroduction(Difficulty);

    const int CodeA = rand() % Difficulty + 1;
    const int CodeB = rand() % Difficulty + 1;
    const int CodeC = rand() % Difficulty + 1;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    // Print CodeSum CodeProduct to the terminal
    std::cout << "\n* There are 3 numbers in the code.";
    std::cout << "\n* The codes add-up to: " << CodeSum;
    std::cout << "\n* The codes multiply to give: " << CodeProduct << std::endl;

    // Store Player guess
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    // Check if the Player guess is correct
    if (GuessSum == CodeSum && GuessProduct == CodeProduct) {
        std::cout << "\n*** WELL DONE, AGENT. KEEP GOING! ***";
        return true;
    } else {
        std::cout << "\n*** YOU ENTERED THE WRONG CODE, BE CAREFUL, AGENT. TRY AGAIN! ***";
        return false;
    }
}

int main() {

    srand(time(NULL)); // Create new random sequence based on time of day

    int LevelDifficulty = 1;
    int const MaxDifficulty = 5;

    // Loop the game until all levels are completed
    while (LevelDifficulty <= MaxDifficulty) {

        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); // Clear erros in relation to input
        std::cin.ignore(); // If a Player enter a bad character instead of a number, it'll discard the buffer

        if (bLevelComplete) {
            ++LevelDifficulty;
        }   
    }

    std::cout << "\n*** Great job, Agent. You got all the archives. Now, GET OUT OF THERE! ***\n";
    return 0;
} 
