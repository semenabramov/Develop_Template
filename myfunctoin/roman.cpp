#include "roman.h"

using namespace std;

void Convertor::toArabic() {
    if (!check()) throw logic_error("Invalid value");
    int tmpArabic = 0;
    string tmp = value_ro.value;
    int count = 0;
    string twoC;
    while (count < (int)tmp.length() - 1)
    {
        twoC = tmp.substr(count, 2);
        if (twoC == "IV") {
            tmp.replace(count, 2, "");
            tmpArabic += 4;
            count--;
        }
        if (twoC == "IX") {
            tmp.replace(count, 2, "");
            tmpArabic += 9;
            count--;
        }
        if (twoC == "XL") {
            tmp.replace(count, 2, "");
            tmpArabic += 40;
            count--;
        }
        if (twoC == "XC") {
            tmp.replace(count, 2, "");
            tmpArabic += 90;
            count--;
        }
        if (twoC == "CD") {
            tmp.replace(count, 2, "");
            tmpArabic += 400;
            count--;
        }
        if (twoC == "CM") {
            tmp.replace(count, 2, "");
            tmpArabic += 900;
            count--;
        }
        count++;
    }

    for (int i = 0; i < tmp.length(); i++) {
        if (tmp[i] == 'I') {
            tmpArabic += 1;
        }
        if (tmp[i] == 'V') {
            tmpArabic += 5;
        }
        if (tmp[i] == 'X') {
            tmpArabic += 10;
        }
        if (tmp[i] == 'L') {
            tmpArabic += 50;
        }
        if (tmp[i] == 'C') {
            tmpArabic += 100;
        }
        if (tmp[i] == 'D') {
            tmpArabic += 500;
        }
        if (tmp[i] == 'M') {
            tmpArabic += 1000;
        }
    }
    value_ar.value = tmpArabic;
    isReadyArabic = true;
}

void Convertor::toRoman() {
    arabic tmp = value_ar;
    string tmpRoman = "";

    if (tmp.value / M > 0) {
        for (int i = 0; i < tmp.value / M; i++) {
            tmpRoman += "M";
        }
        tmp.value = tmp.value % M;
    }
    if (tmp.value >= 900) {
        tmpRoman += "CM";
        tmp.value -= 900;
    }

    if (tmp.value / D > 0) {
        for (int i = 0; i < tmp.value / D; i++) {
            tmpRoman += "D";
        }
        tmp.value = tmp.value % D;
    }
    if (tmp.value >= 400) {
        tmpRoman += "CD";
        tmp.value -= 400;
    }

    if (tmp.value / C > 0) {
        for (int i = 0; i < tmp.value / C; i++) {
            tmpRoman += "C";
        }
        tmp.value = tmp.value % C;
    }
    if (tmp.value >= 90) {
        tmpRoman += "XC";
        tmp.value -= 90;
    }

    if (tmp.value / L > 0) {
        for (int i = 0; i < tmp.value / L; i++) {
            tmpRoman += "L";
        }
        tmp.value = tmp.value % L;
    }
    if (tmp.value >= 40) {
        tmpRoman += "XL";
        tmp.value -= 40;
    }

    if (tmp.value / X > 0) {
        for (int i = 0; i < tmp.value / X; i++) {
            tmpRoman += "X";
        }
        tmp.value = tmp.value % X;
    }
    if (tmp.value >= 9) {
        tmpRoman += "IX";
        tmp.value -= 9;
    }

    if (tmp.value / V > 0) {
        for (int i = 0; i < tmp.value / V; i++) {
            tmpRoman += "V";
        }
        tmp.value = tmp.value % V;
    }
    if (tmp.value >= 4) {
        tmpRoman += "IV";
        tmp.value -= 4;
    }

    if (tmp.value / I > 0) {
        for (int i = 0; i < tmp.value / I; i++) {
            tmpRoman += "I";
        }
    }

    value_ro.value = tmpRoman;
    isReadyRoman = true;
}
void Convertor::print()
{
	//std::cout << "Data";
	std::cout << "Arabic:" << value_ar.value << "\n";
	std::cout << "Roman:" << value_ro.value << "\n";
}

bool Convertor::check() {
    for (int i = 0; i < value_ro.value.length(); i++) {
        value_ro.value[i] = toupper(value_ro.value[i]);
        bool b = false;
        for (int j = 0; j < sizeAlph; j++) {
            if (value_ro.value[i] == arrRomNumber[j]) {
                b = true;
                break;
            }
        }
        if (!b) return false;
    }
    return true;
}


void Convertor::setArabic(const arabic& t) {
    value_ar = t;
    isReadyArabic = true;
    isReadyRoman = false;
    toRoman();
}

void Convertor::setRoman(const roman& t) {
    value_ro = t;
    isReadyRoman = true;
    isReadyArabic = false;
    check();
    toArabic();
}

Convertor::Convertor() {
    isReadyRoman = false;
    isReadyArabic = false;
}

Convertor::Convertor(const arabic& t) {
    value_ar = t;
    isReadyArabic = true;
    isReadyRoman = false;
    toRoman();
}

Convertor::Convertor(const roman& t) {
    value_ro = t;
    isReadyRoman = true;
    isReadyArabic = false;
    check();
    toArabic();
}

arabic Convertor::get_arabic() {
    if (!isReadyArabic) throw logic_error("This value is not set");
    return value_ar;
}

roman Convertor::get_roman() {
    if (!isReadyArabic) throw logic_error("This value is not set");
    return value_ro;
}