#include <iostream>
#include <string>

using namespace std;

struct Bier {
    string name;
    double preis;
    Bier *next;
} *head, *tail;

void initStack() {
    head = new Bier;
    tail = new Bier;

    head->preis = 0;
    head->name = "";

    tail->preis = 0;
    tail->name = "";

    head->next = tail;
}

void push(string name, double preis) {
    Bier *b = new Bier;

    b->name = name;
    b->preis = preis;

    b->next = head->next;
    head->next = b;
}

void pop() {
    if (head->next == tail) return;

    Bier *b = head->next;
    head->next = b->next;

    delete b;
}

Bier top() { return *head->next; }

void deleteStack() {
    Bier *runner = head;
    while (runner->next != NULL) {
        Bier *tmp = runner;
        runner = tmp->next;

        delete tmp;
    }
}

bool isEmpty() { return head->next == tail; }


// nicht gefordert
void showStack() {
    Bier *runner = head;
    while (runner->next != NULL) {
        if (runner != head && runner != tail) cout << runner->name << " - " << runner->preis << "\n";
        runner = runner->next;
    }
}

int main() {
    initStack();

    push("A", 1.5);
    showStack();
    cout << "\n";

    push("B", 0.5);
    showStack();
    cout << "\n";

    push("C", 2.0);
    showStack();
    cout << "\n";

    pop();
    showStack();
    cout << "\n";

    deleteStack();
    return 0;
}
