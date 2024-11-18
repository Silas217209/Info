#include <iostream>

using namespace std;

const int größe = 4;

int anfang, ende = 0;

double stack[größe];

void push(double preis) {
    stack[ende % größe] = preis;
    ende++;

    if (ende - anfang > größe) {
        anfang = ende - größe;
    }
}

void pop() {
    if (anfang < ende) anfang++;
}

double top() { return stack[anfang]; }

void show_stack() {
    for (int i = anfang; i < ende; i++) {
        int index = i % größe;
        cout << stack[index] << ", ";
    }

    cout << "\n";
}


int main() {
    push(2.0);
    show_stack();
    push(5.2);
    show_stack();
    push(8.3);
    show_stack();
    push(4.9);
    show_stack();
    pop();
    show_stack();
    return 0;
}
