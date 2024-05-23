#include "temp.hpp"
using namespace std;
litem::litem(int value, litem *next = nullptr) : value(value), next(next) {}
list::list() : head(nullptr), tail(nullptr) {}
list::list(const list &other) : head(nullptr), tail(nullptr)
{
    if (other.head == nullptr) {
        return;
    }
    try {
        head = new litem(*other.head);
        head->next = nullptr;
        const litem *otheritem = other.head;
        litem *item = head;
        while (otheritem->next != nullptr) {
            item->next = new litem(*otheritem->next);
            item->next->next = nullptr;
            otheritem = otheritem->next;
            item = item->next;
        }
        tail = item;
    } catch (bad_alloc &e) {
        clear();
        throw;
    }
}
list &list::operator=(const list &other)
{
    if (&other != this) {
        clear();
        if (other.head == nullptr) {
            return *this;
        }
        try {
            head = new litem(*other.head);
            head->next = nullptr;

            const litem *otheritem = other.head;
            litem *item = head;

            while (otheritem->next != nullptr) {
                item->next = new litem(*otheritem->next);
                item->next->next = nullptr;

                otheritem = otheritem->next;
                item = item->next;
            }
            tail = item;
        } catch (bad_alloc &e) {
            clear();
            throw;
        }
    }
    return *this;
}
void list::pushback(int value)
{
    if (head != nullptr) {
        tail->next = new litem(value, tail);
        tail = tail->next;
    } else {
        head = new litem(value);
        tail = head;
    }
    tail->next = NULL;
}
int list::length()
{
    if ((this->head != nullptr) && (this->tail != nullptr)) {
        int leng = 1;
        litem *i = this->head;
        while (i != this->tail) {
            leng++;
            i = i->next;
        }
        return leng;
    }
    return 0;
}
void list::bubbleSort()
{
    int length = this->length();
    for (int i = 0; i < length; i++) {
        litem *cur = head;
        litem *prev = head;
        for (int j = 0; j < length - i - 1; j++) {
            if (cur->value > cur->next->value) {
                litem *temp = cur->next;
                cur->next = cur->next->next;
                temp->next = cur;
                if (cur == head) {
                    head = temp;
                    prev = head;
                } else {
                    prev->next = temp;
                }
                cur = temp;
            }
            prev = cur;
            cur = cur->next;
        }
    }
    litem *indx = head;
    for (int k = 0; k < length - 1; k++) {
        indx = indx->next;
    }
    tail = indx;
}
void list::deleteItems(const int value)
{
    if ((head != NULL) && (tail != NULL)) {
        litem *cur = head;
        while (cur != tail) {
            cur = cur->next;
        }
        while ((head->value == value) && (head != tail)) {
            litem *todel = head;
            head = head->next;
            delete todel;
        }
        cout << endl;
        if ((head == tail) && (tail->value == value)) {
            litem *todel = head;
            head = head->next;
            delete todel;
            head = nullptr;
            tail = nullptr;
        } else {
            cur = head;
            while (cur->next != tail) {
                if (cur->next->value == value) {
                    litem *todel = cur->next;
                    cur->next = cur->next->next;
                    delete todel;
                } else {
                    cur = cur->next;
                }
            }
            if ((cur->next == tail) && (tail->value == value)) {
                litem *todel = tail;
                tail = cur;
                delete todel;
            }
        }
    }
}
istream &operator>>(istream &input, list &unit)
{
    int tmp;
    if (unit.head != nullptr) {
        unit.~list();
    }
    while (input >> tmp) {
        unit.pushback(tmp);
    }
    return input;
}
ostream &operator<<(ostream &output, list &unit)
{
    if ((unit.head == nullptr) && (unit.tail == nullptr)) {
        cout << "Empty list" << endl;
    } else {
        litem *i = unit.head;
        while (i != unit.tail) {
            cout << i->value << " ";
            i = i->next;
        }
        cout << i->value << endl;
    }
    return output;
}
void list::clear()
{
    litem *current = head;
    while (current != tail) {
        litem *todel = current;
        current = current->next;
        delete todel;
    }
    delete tail;
}
list::~list()
{
    clear();
}