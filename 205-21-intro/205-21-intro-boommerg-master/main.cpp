#include "babylon.hpp"
#include <iostream>
#include <string>

#define ERROR_OUT -1;
#define OK_OUT 0;

int main()
{

    int n;
    int m;
    char control;

    if ((!(std::cin >> n)) || (n < 1)) {
        return ERROR_OUT;
    }
    if ((!(std::cin >> m)) || (m < 1)) {
        return ERROR_OUT;
    }
    if (m > n) {
        return ERROR_OUT;
    }

    char *Seq = new char[n];
    char *SubSeq = new char[m];

    if ((!babylon::ReadSeq(Seq, n)) || (!babylon::ReadSeq(SubSeq, m))) {
        delete[] Seq;
        delete[] SubSeq;
        return ERROR_OUT;
    }
    if (std::cin >> control) {
        delete[] Seq;
        delete[] SubSeq;
        return ERROR_OUT;
    }

    babylon::Vview(Seq, n, SubSeq, m);

    if (babylon::IsItSubsequence(Seq, n, SubSeq, m)) {

        std::cout << "True" << std::endl;
    } else {
        std::cout << "False" << std::endl;
    }

    delete[] Seq;
    delete[] SubSeq;
    return OK_OUT;
}