#include <iostream>

using namespace std;

struct Bier {
    double preis;
    Bier *next;
} *head, *tail;

void initStack() {
    head = new Bier;
    tail = new Bier;

    head->next = tail;
    tail->next = NULL;
}

void push(double preis) {
    Bier *dummy = new Bier;

    dummy->preis = preis;

    dummy->next = head->next;
    head->next = dummy;
}

void pop() {
    if (head->next == tail) return;

    Bier *dummy = head->next;

    head->next = dummy->next;

    delete dummy;
}

double top() {
    Bier *dummy = head->next;
    return dummy->preis;
}

bool isEmpty() { return head->next == tail; }

int main() {
    initStack();

    push(5.0);
    push(3.0);

    cout << top() << "\n";

    return 0;
}
