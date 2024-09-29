// Die folgenden Informatiker sollen in eine einfach verkettete, dynamische sortierte Liste eingepflegt werden:
// Entwerfen Sie einen passenden Datentyp und die notwendigen Verwaltungselemente
// Implementieren Sie:
// initSorted
// insertElement
// searchForElement
// deleteElement
// showElement
// left, right, first, last
//
// Hier ist eine Liste von Informatikern mit ihren Errungenschaften und Geburtsjahren:
//
// 1. Alan Turing
//    Errungenschaft: Begründer der theoretischen Informatik und der Künstlichen Intelligenz. Entwickelte die
//    Turing-Maschine. Geburtsjahr: 1912
//
// 2. Grace Hopper
//    Errungenschaft: Entwicklerin des ersten Compilers und Pionierin für Programmiersprachen.
//    Geburtsjahr: 1906
//
// 3. John von Neumann
//    Errungenschaft: Entwickelte die Von-Neumann-Architektur, Grundlage für moderne Computer.
//    Geburtsjahr: 1903
//
// 4. Tim Berners-Lee
//    Errungenschaft: Erfinder des World Wide Web.
//    Geburtsjahr: 1955
//
// 5. Donald Knuth
//    Errungenschaft: Autor von *The Art of Computer Programming* und Schöpfer der TeX-Satzsysteme.
//    Geburtsjahr: 1938
//
// 6. Ada Lovelace
//    Errungenschaft: Erste Programmiererin, schrieb den ersten Algorithmus für die Analytical Engine von Charles
//    Babbage. Geburtsjahr: 1815
//
// 7. Vint Cerf
//    Errungenschaft: Einer der "Väter des Internets", Co-Entwickler des TCP/IP-Protokolls.
//    Geburtsjahr: 1943
//
// 8. Linus Torvalds
//    Errungenschaft: Schöpfer des Linux-Kernels.
//    Geburtsjahr: 1969
//
// 9. Edsger W. Dijkstra
//    Errungenschaft: Entwickelte den kürzesten Pfad-Algorithmus (Dijkstra-Algorithmus) und trug zur strukturierten
//    Programmierung bei. Geburtsjahr: 1930
//
// 10. Barbara Liskov
//     Errungenschaft: Entwicklerin des Liskov-Substitutionsprinzips, Pionierin der Objektorientierung und verteilten
//     Systeme. Geburtsjahr: 1939

#include <iostream>
#include <string>

struct Informatiker {
    std::string vn;
    std::string nn;
    std::string errungenschaft;
    int geburtsjahr;
    Informatiker *next;
} *head, *tail, *now;

void initSorted() {
    head = new Informatiker;
    head->vn = "";
    head->nn = "";
    head->errungenschaft = "";
    head->geburtsjahr = 0;

    tail = new Informatiker;
    tail->vn = "";
    tail->nn = "";
    tail->errungenschaft = "";
    tail->geburtsjahr = 0;

    now = head;
    head->next = tail;
}

// 0 left == right
// 1 left > right
// 2 left < right
int strcmp(std::string left, std::string right) {
    unsigned long nleft = left.length();
    unsigned long nright = right.length();

    unsigned long nstr = nleft > nright ? nright : nleft;

    for (unsigned int i = 0; i < nstr; i++) {
        char cleft = left[i];
        char cright = right[i];

        if (cleft > cright) {
            return 1;
        }
        if (cleft < cright) {
            return 2;
        }
    }

    if (nleft > nright) {
        return 1;
    }

    if (nleft < nright) {
        return 2;
    }

    return 0;
}


void insertElement(const std::string &vorname, const std::string &nachname, const std::string &errungenschaft,
                   int geburtsjahr) {
    Informatiker *el = new Informatiker;
    el->vn = vorname;
    el->nn = nachname;
    el->errungenschaft = errungenschaft;
    el->geburtsjahr = geburtsjahr;

    Informatiker *runner = head;
    while (true) {
        if (runner->next == tail) {
            break;
        }

        Informatiker *next = runner->next;

        int cmp = strcmp(nachname, next->nn);

        if (cmp == 0) {
            cmp = strcmp(vorname, next->vn);
        }

        if (cmp == 0) {
            cmp = strcmp(errungenschaft, next->errungenschaft);
        }

        if (cmp == 2) {
            break;
        }

        runner = next;
    }

    el->next = runner->next;
    runner->next = el;
}

Informatiker searchForElement(const std::string &nachname, int *res) {
    Informatiker *runner = head;

    while (runner->next != tail) {
        Informatiker *next = runner->next;

        if (next->nn == nachname) {
            *res = 0;
            return *next;
        }
        runner = next;
    }

    *res = 1;
    Informatiker el;
    el.vn = "";
    el.nn = "";
    el.errungenschaft = "";
    el.geburtsjahr = 0;
    el.next = NULL;

    return el;
}

int deleteElement(const std::string &nachname) {
    Informatiker *runner = head;

    bool found = false;
    while (runner->next != tail) {
        Informatiker *next = runner->next;

        if (next->nn == nachname) {
            found = true;
            break;
        }
        runner = next;
    }

    if (!found) {
        return -1;
    }

    Informatiker *el = runner->next;
    runner->next = el->next;

    delete el;

    return 0;
}

void showElement() {
    std::cout << now->vn << " " << now->nn << ", " << now->errungenschaft << ", " << now->geburtsjahr << "\n";
}

int left() {
    Informatiker *runner = head;
    while (runner->next != tail) {
        Informatiker *next = runner->next;

        if (next->next == now) {
            now = next;
            return 0;
        }
        runner = next;
    }

    return -1;
}
int right() {
    if (now->next == tail) {
        return 1;
    }

    now = now->next;

    return 0;
}

Informatiker first() { return *head->next; }

Informatiker last() {
    Informatiker *runner = head;

    while (runner->next != tail) {
        Informatiker *next = runner->next;

        runner = next;
    }

    return *runner;
}

void showAll() {
    Informatiker *runner = head;
    while (runner->next != tail) {
        Informatiker *next = runner->next;

        std::cout << next->vn << " " << next->nn << ", " << next->errungenschaft << ", " << next->geburtsjahr << "\n";
        runner = next;
    }
}

int main() {
    initSorted();

    insertElement(
            "Alan", "Turing",
            "Begründer der theoretischen Informatik und der Künstlichen Intelligenz. Entwickelte die Turing-Maschine.",
            1912);
    insertElement("Grace", "Hopper", "Entwicklerin des ersten Compilers und Pionierin für Programmiersprachen.", 1906);
    insertElement("John", "von Neumann", "Entwickelte die Von-Neumann-Architektur, Grundlage für moderne Computer.",
                  1903);
    insertElement("Tim", "Berners-Lee", "Erfinder des World Wide Web.", 1955);
    insertElement("Donald", "Knuth", "Autor von 'The Art of Computer Programming' und Schöpfer der TeX-Satzsysteme.",
                  1938);
    insertElement(
            "Ada", "Lovelace",
            "Erste Programmiererin, schrieb den ersten Algorithmus für die Analytical Engine von Charles Babbage.",
            1815);
    insertElement("Vint", "Cerf", "Einer der 'Väter des Internets', Co-Entwickler des TCP/IP-Protokolls.", 1943);
    insertElement("Linus", "Torvalds", "Schöpfer des Linux-Kernels.", 1969);
    insertElement("Edsger", "Dijkstra",
                  "Entwickelte den kürzesten Pfad-Algorithmus (Dijkstra-Algorithmus) und trug zur strukturierten "
                  "Programmierung bei.",
                  1930);
    insertElement(
            "Barbara", "Liskov",
            "Entwicklerin des Liskov-Substitutionsprinzips, Pionierin der Objektorientierung und verteilten Systeme.",
            1939);

    showAll();

    return 0;
}
