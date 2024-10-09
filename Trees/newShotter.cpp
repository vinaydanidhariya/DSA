#include <iostream>
#include <vector>

void printRound(const std::vector<int>& people, int round) {
    std::cout << "Round " << round << ": ";
    for (int person : people) {
        std::cout << person << " ";
    }
    std::cout << std::endl;
}

int josephus(int n) {
    std::vector<int> people(n);
    for (int i = 0; i < n; ++i) {
        people[i] = i + 1;
    }

    int index = 0;
    int round = 1;

    while (people.size() > 1) {
        // Print the current round
        printRound(people, round);

        // Calculate the index of the next person to be eliminated
        index = (index + 1) % people.size();

        // Print who kills whom
        std::cout << "Person " << people[(index - 1 + people.size()) % people.size()]
                << " kills Person " << people[index] << std::endl;

        // Remove the person from the vector
        people.erase(people.begin() + index);

        // If the index is at the end of the vector, wrap it around to the beginning
        if (index == people.size()) {
            index = 0;
        }

        // Increment the round
        round++;
    }

    // Print the final round
    printRound(people, round);

    // The last person remaining
    return people.front();
}

int main() {
    int n = 10;
    int last_person_standing = josephus(n);
    std::cout << "The last person standing is Person " << last_person_standing << std::endl;
    return 0;
}
