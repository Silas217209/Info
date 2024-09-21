#include <iostream>
using namespace std;

struct Person {
    string NN;
    string VN;
    Person *next;
    Person *back;
} *head, *tail, *runner, *now;

void initSorted();
void insertElement(string Nachname, string Vorname);
bool isEmpty();

bool deleteElement(string Nachname);
string searchElement(string Nachname);
string backward();
string forward();
string first();
string last();
string current();
string ausgabe();


int main(int argc, const char *argv[]) {
    initSorted();
    insertElement("Funke", "Anton");
    insertElement("Seifert", "Nils");
    insertElement("Ramm", "Johann");
    insertElement("Runge", "Emma");
    insertElement("Dahl", "Torben");
    insertElement("Hinz", "Max");
    insertElement("Klitza", "Rouven");
    insertElement("Pachali", "Silas");

    insertElement("Formaniak", "Brooke");
    insertElement("Schubert", "Lars");
    insertElement("Theodor", "Tritthart");
    insertElement("Uszpelkat", "Felix");

    cout << searchElement("Formaniak");
    cout << forward() << endl;
    cout << forward() << endl;
    deleteElement("Formaniak");
    cout << backward() << endl;
    cout << backward() << endl;
    cout << last() << endl;
    cout << first() << endl;
    cout << searchElement("Formaniak");


    return 0;
}
bool deleteElement(string Nachname) {
    runner = head->next;
    while (runner->NN != Nachname && runner != tail) {
        runner = runner->next;
    }
    if (runner->NN == Nachname) {
        runner->back->next = runner->next;
        runner->next->back = runner->back;
        delete runner;
        return true;
    } else {
        return false;
    }
};

string searchElement(string Nachname) {
    runner = head->next;
    string merke;
    while (runner->NN != Nachname && runner != tail) {
        runner = runner->next;
    }
    if (runner->NN == Nachname) {
        merke = runner->VN;
        return merke;
    } else {
        return "nicht drin";
    }
};
string backward() {
    if (now->back != head) {
        now = now->back;
        return ausgabe();
    } else {
        return "ist erstes Element";
    }
};
string forward() {
    if (now->next != tail) {
        now = now->next;
        return ausgabe();
    } else {
        return "ist letztes Element";
    }
};
string first() {
    now = head->next;
    if (now != tail) {
        return ausgabe() + " ist am Anfang";
        ;
    } else {
        return "Liste leer";
    }
};
string last() {
    now = tail->back;
    if (now != head) {
        return ausgabe() + " ist am Ende";
        ;
    } else {
        return "Liste leer";
    }
};
string current() {
    if (now != head && now != tail) {
        return ausgabe();
    } else {
        return "Liste leer";
    }
};
string ausgabe() { return now->NN + " ; " + now->VN; };


void initSorted() {
    // Speicher
    head = new Person;
    tail = new Person;
    // Werte
    head->NN = "AAAnfang";
    head->VN = "AAAnfang";
    tail->NN = "zzzuEnde";
    tail->VN = "zzzuEnde";
    // Verknüpfungen
    head->next = tail;
    tail->back = head;
    now = head;
}
void insertElement(string Nachname, string Vorname) {
    // Speicher
    Person *dummy = new Person;
    // Werte
    dummy->NN = Nachname;
    dummy->VN = Vorname;
    if (isEmpty()) {
        dummy->next = tail;
        dummy->back = head;
        head->next = dummy;
        tail->back = dummy;
    } else {
        runner = head->next;
        while (Nachname > runner->NN && runner != tail) {
            runner = runner->next;
        }
        dummy->next = runner;
        dummy->back = runner->back;
        dummy->back->next = dummy;
        runner->back = dummy;
    }
    now = dummy;
}

bool isEmpty() {
    if (head->next == tail) {
        return true;
    } else {
        return false;
    }
}
