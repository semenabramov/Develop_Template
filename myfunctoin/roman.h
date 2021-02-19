#pragma once
#include <iostream>

enum RomMatches { I = 1, V = 5, X = 10, L = 50, C = 100, D = 500, M = 1000 };


const int sizeAlph = 7;
const char arrRomNumber[] = { 'I', 'V', 'X', 'L', 'C', 'D', 'M' };

struct roman {
  std::string value;

  roman(std::string t) { value = t; };
  roman() { value = "0"; };
};

struct arabic {
  int value;

  arabic(int t) {value = t;};
  arabic() { value = 0; };
};

// I V X  -  M C

class Convertor {

  roman value_ro;
  arabic value_ar;

  bool isReadyArabic;
  bool isReadyRoman;

public:

  void toArabic();
  void toRoman();

  void set_arabic(const arabic& t) { value_ar = t; };
  void set_roman(const roman& t) { value_ro = t; };

  arabic get_arabic();
  roman get_roman();

  void print() ;
  //{ std::cout << "Data"; }
  bool check();

  void setArabic(const arabic& t);
  void setRoman(const roman& t);

  Convertor();
  Convertor(const arabic& t);
  Convertor(const roman& t);

  // оператор ввода-вывода, либо print

};

