#include <iostream>

namespace babylon{
  bool ReadSeq(char *Seq, int n){
    for(int i = 0; i < n; i++){
      if(!(std::cin >> Seq[i])){
        return false;
      }
    }
    return true;
  }

  bool IsItSubsequence(const char *Seq, int n, const char *SubSeq,  int m){
    int count = 0;
    for (int i = 0; i < n; i++) {
      if(Seq[i] == SubSeq[count]) {
        count++;
      }
    } 
    if(count == m ){
      return true;
    }else return false;
  }

  void ItsShowTime(const char *Seq, int n){
    for(int i = 0; i < n; i++) {
      std::cout << Seq[i];
    }
  } 

  void Vview (const char* Seq, int n, const char* SubSeq, int m){
    std::cout << std::endl << "s = \"";
    babylon::ItsShowTime(Seq, n);
    std::cout << "\", t = \"";
    babylon::ItsShowTime(SubSeq, m);
    std::cout << "\"" << std::endl;
    std::cout << "is t a subsequence of s?" << std::endl;
  }
}