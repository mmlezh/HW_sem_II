#include "temp.hpp"

using namespace std;

int main()
{
    list A;
    list B;
    int valuetodelete;
    cin >> valuetodelete;
    cin >> A;
    list C(A);
    B = A;
    A.deleteItems(valuetodelete);
    B.bubbleSort();
    cout << endl << "исходный linked list\n" << C;
    cout << endl
         << "\nпосле удаления элемента со значением " << valuetodelete << endl
         << A;
    cout << endl << "\nотсортированный\n" << B;
    return 0;
}