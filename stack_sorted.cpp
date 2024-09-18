#include <iostream>
#include <string>

struct Element {
    int value;
    Element *next;
} *head, *tail;

void initStack() {
    head = new Element;
    tail = new Element;

    head->value = 0;
    tail->value = 0;

    head->next = tail;
}

void push(const int value) {
    Element *runner = head;
    Element *b = new Element;
    b->value = value;

    while (true) {
        Element* tmp = runner->next;
        if (tmp == tail || tmp->value < value) break;
        runner = tmp;
    }

   b->next = runner->next;
   runner->next = b;
}

int pop() {
    if (head->next == tail) return 1;

    const Element *b = head->next;
    head->next = b->next;

    delete b;

    return 0;
}

Element top() { return *head->next; }

void deleteStack() {
    Element *runner = head;
    while (runner->next != NULL) {
        Element *tmp = runner;
        runner = tmp->next;

        delete tmp;
    }
}

bool isEmpty() { return head->next == tail; }

void showStack() {
    Element *runner = head;
    while (runner->next != NULL) {
        if (runner != head && runner != tail) std::cout << runner->value << "\n";
        runner = runner->next;
    }
}

int main() {
    initStack();

    push(1);
    showStack();
    std::cout << "\n";

    push(5);
    showStack();
    std::cout << "\n";

    push(2);
    showStack();
    std::cout << "\n";

    pop();
    showStack();
    std::cout << "\n";

    deleteStack();
    return 0;
}
