#include <string>

struct Person {
    std::string NN;
    std::string VN;
    Person* next;
    Person* back;
} *head, *tail, *runner;

void initSorted() {
    head = new Person;
   tail = new Person;

   head->NN = "";
   head->VN = "";

   tail->NN = "";
   tail->VN = "";

   head->next = tail;
   head->back = NULL;

   tail->next = NULL;
   tail->back = head;

    runner = head;
}
void insertElement() {}
bool isEmpty() {
   return head->next == tail;
}

int main() {
    return 1:
}