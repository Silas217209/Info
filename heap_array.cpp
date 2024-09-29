#include <iostream>
#include <string>

// 96 Bytes
struct Person {
    std::string vorname;
    std::string nachname;
    std::string budnesland;
};

Person *liste;


int main() {
    // 16 777 216 = 2^24
    // ~1,6GB Speicher auf dem Heap (könnte fehlschlagen wenn nicht genug verfügbar ist)
    liste = new Person[16777216];

    liste[1000].vorname = "Silas";
    liste[1000].nachname = "Pachali";
    liste[1000].budnesland = "Brandenburg";

    std::cout << liste[1000].vorname << " " << liste[1000].nachname << ", " << liste[1000].budnesland << "\n";

    delete[] liste;
    return 0;
}
