#include <iostream>
#include <string>

using namespace std;

struct Bier {
    string name;
    double preis;
    Bier *next;
} *head, *tail, *runner;

void initQ() {
    head = new Bier;
    tail = new Bier;

    head->preis = 0;
    head->name = "";

    tail->preis = 0;
    tail->name = "";

    head->next = tail;

    runner = head;
}

void enQ(string name, double preis) {
    Bier *b = new Bier;

    b->name = name;
    b->preis = preis;

    b->next = tail;
    runner->next = b;

    runner = b;
}

void deQ() {
    if (head->next == tail) return;

    const Bier *b = head->next;
    head->next = b->next;

    delete b;
}

Bier first() { return *head->next; }

void deleteQ() {
    Bier *runner = head;
    while (runner->next != NULL) {
        Bier *tmp = runner;
        runner = tmp->next;

        delete tmp;
    }
}

bool isEmpty() { return head->next == tail; }


// nicht gefordert, nur zum visualisieren
void showQ() {
    Bier *runner = head;
    while (runner->next != NULL) {
        if (runner != head && runner != tail) cout << runner->name << " - " << runner->preis << "\n";
        runner = runner->next;
    }
}

int main() {
    initQ();

    enQ("A", 1.5);
    showQ();
    cout << "\n";

    enQ("B", 0.5);
    showQ();
    cout << "\n";

    enQ("C", 2.0);
    showQ();
    cout << "\n";

    deQ();
    showQ();
    cout << "\n";

    deleteQ();
    return 0;
}
