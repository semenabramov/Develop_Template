#include <polinoms.h>

using namespace std;




monom::monom(int _coeff, int x, int y, int z)
{
	if (x >= maxPower || y >= maxPower || z >= maxPower) throw logic_error("Power is greater than the maximum power");
	P = x * maxPower * maxPower + y * maxPower + z;
	coeff = _coeff;
}

monom::monom(int _coeff, int _P)
{
	if (_P > (maxPower - 1) * maxPower * maxPower + (maxPower - 1) * maxPower + (maxPower - 1)) throw logic_error("Power is greater than the maximum power");
	P = _P;
	coeff = _coeff;
}

int monom::getX() const
{
	return P / (maxPower * maxPower);
}

int monom::getY() const
{
	int tmpX = P / (maxPower * maxPower);
	return (P - tmpX * maxPower * maxPower) / maxPower;
}

int monom::getZ() const
{
	int tmpX = P / (maxPower * maxPower);
	int tmpY = (P - tmpX * maxPower * maxPower) / maxPower;
	return P - tmpX * maxPower * maxPower - tmpY * maxPower;
}

int monom::getS() const
{
	return P;
}

int monom::getCoeff() const
{
	return coeff;
}

bool monom::operator==(const monom& m) const
{
	return P == m.P;
}

bool monom::operator!=(const monom& m) const
{
	return P != m.P;
}

bool monom::operator>(const monom& m) const
{
	return P > m.P;
}

bool monom::operator>=(const monom& m) const
{
	return P >= m.P;
}

bool monom::operator<(const monom& m) const
{
	return P < m.P;
}

bool monom::operator<=(const monom& m) const
{
	return P <= m.P;
}

monom monom::operator*(const int& val)
{
	monom tmp = *this;
	tmp.coeff *= val;
	return tmp;
}

monom& monom::operator*=(const int& val)
{
	coeff *= val;
	return *this;
}

monom monom::operator+(const monom& m) const
{
	if (P != m.P) throw logic_error("Different power of monomials");
	monom tmp = *this;
	tmp.coeff += m.coeff;
	return tmp;
}

monom& monom::operator+=(const monom& m)
{
	if (P != m.P) throw logic_error("Different power of monomials");
	coeff += m.coeff;
	return *this;
}

monom monom::operator-(const monom& m) const
{
	if (P != m.P) throw logic_error("Different power of monomials");
	monom tmp = *this;
	tmp.coeff -= m.coeff;
	return tmp;
}

monom& monom::operator-=(const monom& m)
{
	if (P != m.P) throw logic_error("Different power of monomials");
	coeff -= m.coeff;
	return *this;
}

monom monom::operator*(const monom& m) const
{
	if (getX() + m.getX() >= maxPower) throw logic_error("The resulting power exceeds the maximum");
	if (getY() + m.getY() >= maxPower) throw logic_error("The resulting power exceeds the maximum");
	if (getZ() + m.getZ() >= maxPower) throw logic_error("The resulting power exceeds the maximum");
	monom tmp = *this;
	tmp.coeff *= m.coeff;
	tmp.P += m.P;
	return tmp;
}

monom& monom::operator*=(const monom& m)
{
	if (getX() + m.getX() >= maxPower) throw logic_error("The resulting power exceeds the maximum");
	if (getY() + m.getY() >= maxPower) throw logic_error("The resulting power exceeds the maximum");
	if (getZ() + m.getZ() >= maxPower) throw logic_error("The resulting power exceeds the maximum");
	coeff *= m.coeff;
	P += m.P;
	return *this;
}

monom monom::operator-() const
{
	monom tmp(*this);
	tmp.coeff = -tmp.coeff;
	return tmp;
}

void monom::print()
{
	cout<< getCoeff() << "*" << "x^" << getX() << "*y^" << getY() << "*z^" << getZ()<<endl;
}



ostream& operator<<(ostream& ostr, const monom& m) {
	ostr << m.getCoeff() << "*" << "x^" << m.getX() << "*y^" << m.getY() << "*z^" << m.getZ();
	return ostr;
}


// Реализация полиномов


polynom::polynom() {
    liMonom = new List<monom>;
    liMonom->push_back(monom(0, 0));
}

polynom::polynom(const polynom& p) {
    liMonom = new List<monom>;
    *liMonom = *(p.liMonom);
}

polynom::~polynom() {
    delete liMonom;
}

polynom& polynom::operator=(const polynom& p) {
    *liMonom = *(p.liMonom);
    return *this;
}

polynom polynom::operator*(const int& val) {
    polynom tmp;
    if (val != 0) {
        tmp = *this;
        tmp.iter = tmp.liMonom->begin();
        while (tmp.iter.hasNext()) {
            tmp.iter.getValue() *= val;
            tmp.iter.next();
        }
    }
    return tmp;
}

polynom& polynom::operator*=(const int& val) {
    iter = liMonom->begin();
    if (val != 0) {
        while (iter.hasNext()) {
            iter.getValue() *= val;
            iter.next();
        }
    }
    else {
        listIterator<monom> tmpIter = liMonom->end();
        if (tmpIter.hasPrev()) tmpIter.prev();
        while (iter != tmpIter) {
            iter = liMonom->erase(iter);
        }
    }
    return *this;
}

polynom polynom::operator+(const monom& m) {
    polynom tmp(*this);
    tmp.iter = tmp.liMonom->begin();
    if (m.getCoeff() != 0) {
        while (tmp.iter.hasNext()) {
            monom& currM = tmp.iter.getValue();
            if (m > currM || !tmp.iter.hasNext()) {
                tmp.iter = tmp.liMonom->insert(tmp.iter, m);
                break;
            }
            else if (m == currM) {
                currM += m;
                break;
            }
            tmp.iter.next();
        }
    }
    return tmp;
}

polynom& polynom::operator+=(const monom& m) {
    iter = liMonom->begin();
    if (m.getCoeff() != 0) {
        while (iter.hasNext()) {
            monom& currM = iter.getValue();
            if (m > currM || !iter.hasNext()) {
                iter = liMonom->insert(iter, m);
                break;
            }
            else if (m == currM) {
                currM += m;
                break;
            }
            iter.next();
        }
    }
    return *this;
}

polynom polynom::operator-(const monom& m) {
    polynom tmp(*this);
    tmp.iter = tmp.liMonom->begin();
    if (m.getCoeff() != 0) {
        while (tmp.iter.hasNext()) {
            monom& currM = tmp.iter.getValue();
            if (m > currM || !tmp.iter.hasNext()) {
                tmp.iter = tmp.liMonom->insert(tmp.iter, -m);
                break;
            }
            else if (m == currM) {
                currM -= m;
                break;
            }
            tmp.iter.next();
        }
    }
    return tmp;
}

polynom& polynom::operator-=(const monom& m) {
    iter = liMonom->begin();
    if (m.getCoeff() != 0) {
        while (iter.hasNext()) {
            monom& currM = iter.getValue();
            if (m > currM || !iter.hasNext()) {
                iter = liMonom->insert(iter, -m);
                break;
            }
            else if (m == currM) {
                currM -= m;
                break;
            }
            iter.next();
        }
    }
    return *this;
}

polynom polynom::operator*(const monom& m) {
    polynom tmp;
    if (m.getCoeff() != 0) {
        tmp = *this;
        tmp.iter = tmp.liMonom->begin();
        while (tmp.iter.hasNext()) {
            tmp.iter.getValue() *= m;
            tmp.iter.next();
        }
    }
    return tmp;
}

polynom& polynom::operator*=(const monom& m) {
    iter = liMonom->begin();
    if (m.getCoeff() != 0) {
        while (iter.hasNext()) {
            iter.getValue() *= m;
            iter.next();
        }
    }
    else {
        listIterator<monom> tmpIter = liMonom->end();
        if (tmpIter.hasPrev()) tmpIter.prev();
        while (iter != tmpIter) {
            iter = liMonom->erase(iter);
            iter.next();
        }
    }
    return *this;
}

polynom polynom::operator+(const polynom& m) {
    polynom tmp(*this);
    listIterator<monom> iterM = m.liMonom->begin();
    tmp.iter = tmp.liMonom->begin();
    while (iterM.hasNext()) {
        while (tmp.iter.hasNext()) {
            monom m1 = iterM.getValue();
            monom& m2 = tmp.iter.getValue();
            if (m1.getCoeff() != 0) {
                if (m1 > m2 || !tmp.iter.hasNext()) {
                    tmp.iter = tmp.liMonom->insert(tmp.iter, m1);
                    tmp.iter.next();
                    break;
                }
                else if (m1 == m2) {
                    m2 += m1;
                    tmp.iter.next();
                    break;
                }
            }
            tmp.iter.next();
        }
        iterM.next();
    }
    return tmp;
}

polynom& polynom::operator+=(const polynom& m) {
    listIterator<monom> iterM = m.liMonom->begin();
    iter = liMonom->begin();
    while (iterM.hasNext()) {
        while (iter.hasNext()) {
            monom m1 = iterM.getValue();
            monom& m2 = iter.getValue();
            if (m1.getCoeff() != 0) {
                if (m1 > m2 || !iter.hasNext()) {
                    iter = liMonom->insert(iter, m1);
                    iter.next();
                    break;
                }
                else if (m1 == m2) {
                    m2 += m1;
                    iter.next();
                    break;
                }
            }
            iter.next();
        }
        iterM.next();
    }
    return *this;
}

polynom polynom::operator-(const polynom& m) {
    polynom tmp(*this);
    listIterator<monom> iterM = m.liMonom->begin();
    tmp.iter = tmp.liMonom->begin();
    while (iterM.hasNext()) {
        while (tmp.iter.hasNext()) {
            monom m1 = iterM.getValue();
            monom& m2 = tmp.iter.getValue();
            if (m1.getCoeff() != 0) {
                if (m1 > m2 || !tmp.iter.hasNext()) {
                    tmp.iter = tmp.liMonom->insert(tmp.iter, -m1);
                    tmp.iter.next();
                    break;
                }
                else if (m1 == m2) {
                    m2 -= m1;
                    tmp.iter.next();
                    break;
                }
            }
            tmp.iter.next();
        }
        iterM.next();
    }
    return tmp;
}

polynom& polynom::operator-=(const polynom& m) {
    listIterator<monom> iterM = m.liMonom->begin();
    iter = liMonom->begin();
    while (iterM.hasNext()) {
        while (iter.hasNext()) {
            monom m1 = iterM.getValue();
            monom& m2 = iter.getValue();
            if (m1.getCoeff() != 0) {
                if (m1 > m2 || !iter.hasNext()) {
                    iter = liMonom->insert(iter, -m1);
                    iter.next();
                    break;
                }
                else if (m1 == m2) {
                    m2 -= m1;
                    iter.next();
                    break;
                }
            }
            iter.next();
        }
        iterM.next();
    }
    return *this;
}

polynom polynom::operator*(const polynom& m) {
    polynom tmp1(*this);
    polynom tmp2;
    listIterator<monom> iterM = m.liMonom->begin();
    while (iterM.hasNext()) {
        tmp2 += tmp1 * iterM.getValue();
        iterM.next();
    }
    return tmp2;
}

polynom& polynom::operator*=(const polynom& m) {
    polynom tmp1(*this);
    polynom tmp2;
    listIterator<monom> iterM = m.liMonom->begin();
    while (iterM.hasNext()) {
        tmp2 += tmp1 * iterM.getValue();
        iterM.next();
    }
    *this = tmp2;
    return *this;
}

void polynom::print()
{
    listIterator<monom> iter = this->liMonom->begin();
        while (iter.hasNext()) {
            monom monom = iter.getValue();
            if (monom.getCoeff() > 0) {
                cout << "+" << monom;
            }
            else if (monom.getCoeff() < 0) {
                cout << monom;
            }
            iter.next();
        }
        cout << endl;
}

ostream& operator<<(ostream& ostr, const polynom& m) {
    listIterator<monom> iter = m.liMonom->begin();
    while (iter.hasNext()) {
        monom monom = iter.getValue();
        if (monom.getCoeff() > 0) {
            cout << "+" << monom;
        }
        else if (monom.getCoeff() < 0) {
            cout << monom;
        }
        iter.next();
    }
    return ostr;
}