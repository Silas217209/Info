#include <iostream>
#include <string>

struct Bier {
    std::string name;
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

void push(const std::string &name, const double &preis) {
    Bier *b = new Bier;

    b->name = name;
    b->preis = preis;

    b->next = head->next;
    head->next = b;
}

int pop() {
    if (head->next == tail) return 1;

    const Bier *b = head->next;
    head->next = b->next;

    delete b;

    return 0;
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

void showStack() {
    Bier *runner = head;
    while (runner->next != NULL) {
        if (runner != head && runner != tail) std::cout << runner->name << " - " << runner->preis << "\n";
        runner = runner->next;
    }
}

int main() {
    initStack();

    push("A", 1.5);
    showStack();
    std::cout << "\n";

    push("B", 0.5);
    showStack();
    std::cout << "\n";

    push("C", 2.0);
    showStack();
    std::cout << "\n";

    pop();
    pop();
    showStack();
    std::cout << "\n";

    deleteStack();
    return 0;
}
