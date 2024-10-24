#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    const int TOTAL_TRIES = 100000000;
    int switch_wins = 0;
    int stay_wins = 0;

    // Seed the random number generator
    std::srand(std::time(0));

    for (int i = 0; i < TOTAL_TRIES; ++i) {
        // Randomly place the car behind one of the 3 doors
        int car_door = std::rand() % 3;  // 0, 1, or 2

        // Player randomly picks a door
        int player_choice = std::rand() % 3;

        // Host opens a door with a goat (it can't be the player's choice or car's door)
        int host_opens;
        do {
            host_opens = std::rand() % 3;
        } while (host_opens == car_door || host_opens == player_choice);

        // If player switches, they choose the other remaining door
        int switch_choice;
        do {
            switch_choice = std::rand() % 3;
        } while (switch_choice == player_choice || switch_choice == host_opens);

        // Check the outcomes
        if (switch_choice == car_door) {
            ++switch_wins;
        } else {
            ++stay_wins;
        }
    }

    // Display the results
    std::cout << "Total tries: " << TOTAL_TRIES << "\n";
    std::cout << "Switch wins: " << switch_wins << "\n";
    std::cout << "Stay wins: " << stay_wins << "\n";
    std::cout << "Switch win rate: " << (static_cast<double>(switch_wins) / TOTAL_TRIES) * 100 << "%\n";
    std::cout << "Stay win rate: " << (static_cast<double>(stay_wins) / TOTAL_TRIES) * 100 << "%\n";

    return 0;
}
