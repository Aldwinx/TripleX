#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty) {
    std::cout << "\n\nYou are a secret agent breaking into a level " << Difficulty << " secure server room... \nYou need to enter the correct codes to continue..." << std::endl << std::endl;
}

bool PlayGame (int LevelDifficulty) {

    PrintIntroduction(LevelDifficulty);


    const int CodeA = rand() % LevelDifficulty + LevelDifficulty, CodeB = rand() % LevelDifficulty + LevelDifficulty, CodeC = rand() % LevelDifficulty + LevelDifficulty;
    int CodeSum = CodeA + CodeB + CodeC;
    int CodeProduct = CodeA * CodeB * CodeC;

    std::cout << "+ There are 3 numbers in the code \n+ The codes add-up to: " << CodeSum << "\n+ The codes multiply to give: " << CodeProduct << std::endl;

    int GuessA, GuessB, GuessC;

    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    if(CodeSum == GuessSum && CodeProduct == GuessProduct) {
        std::cout << "\n*** Well done agent! You have extracted a file! Keep going! ***";
        return true;
    } else {
        std::cout << "\n*** You entered the wrong code! Careful agent! Try again! ***";
        return false;
    }

    std::cout << "You entered " << GuessA << GuessB << GuessC << std::endl;

}

int main() {
    srand(time(NULL));

    const int MaxLevelDifficulty = 5;
    int LevelDifficulty = 1;

    while (LevelDifficulty <= MaxLevelDifficulty) {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear();
        std::cin.ignore();

        if (bLevelComplete)
        {
            ++LevelDifficulty;
        }
        
    }

    std::cout << "\n*** Great work agent! You got all the files! Now let's get out of there! ***";
    return 0;
}