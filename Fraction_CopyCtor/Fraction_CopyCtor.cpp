

#include <iostream>
#include<string>
using namespace std;

class Fraction {
private:
    int numerator;
    int denominator;
    static int instanceCount;


public:

    Fraction() : Fraction(1, 1) {
        instanceCount++;
    }

   
    Fraction(int numerator, int denominator) {
        setNumerator(numerator);
        setDenominator(denominator);
        instanceCount++;
    }

    ~Fraction() {
        instanceCount--;
    }

    static int getInstanceCount() {
        return instanceCount;
    }


    int getNumerator()const
    {
        return this->numerator;
    }

    int getDenominator()const
    {
        return this->denominator;
    }

    void setNumerator(const int& numerator)
    {
        if (numerator == 0)
        {
            cout << "Error! Numerator = 0" << endl;
        }
        else {
            this->numerator = numerator;
        }
    }

    void setDenominator(const int& denominator)
    {
        if (denominator == 0)
        {
            cout << "Error! Denominator cannot be 0" << endl;
        }
        else {
            this->denominator = denominator;
        }
    }

    void input()
    {
        cout << "\t Numerator::   "; cin >> this->numerator;
        cout << "\t Denominator:: "; cin >> this->denominator;

        while (this->denominator == 0) {
            cout << "Denominator cannot be 0. Please re-enter: ";
            cin >> this->denominator;
        }

    }

    void print() const {
        cout << "\t" << numerator << " / " << denominator << endl;

    }

    void simplify() {
        int min = (numerator < denominator) ? numerator : denominator;

        for (int i = min; i > 1; i--) {
            if (numerator % i == 0 && denominator % i == 0) {
                numerator /= i;
                denominator /= i;
                break;
            }
        }
    }

    Fraction addFraction(const Fraction& other) const {
        int commonDenominator = this->denominator * other.getDenominator();
        int commonNumerator = (this->numerator * other.getDenominator()) + (other.getNumerator() * this->denominator);
        Fraction result(commonNumerator, commonDenominator);
        result.simplify();
        return result;
    }

    Fraction subtractFraction(const Fraction& other) const {
        int commonDenominator = this->denominator * other.getDenominator();
        int commonNumerator = (this->numerator * other.getDenominator()) - (other.getNumerator() * this->denominator);

        Fraction result(commonNumerator, commonDenominator);
        result.simplify();
        return result;
    }


    Fraction multiplyFraction(const Fraction& other) const {
        int newNumerator = this->numerator * other.getNumerator();
        int newDenominator = this->denominator * other.getDenominator();

        Fraction result(newNumerator, newDenominator);
        result.simplify();
        return result;
    }


    Fraction divideFraction(const Fraction& other) const {
        int newNumerator = this->numerator * other.getDenominator();
        int newDenominator = this->denominator * other.getNumerator();

        if (newDenominator == 0) {
            cout << "Error! Division by zero." << endl;
            return Fraction(0, 1);
        }

        Fraction result(newNumerator, newDenominator);
        result.simplify();
        return result;
    }

};

int Fraction::instanceCount = 0;

int main()
{
    Fraction fraction1;
    cout << "Input Fraction1:" << endl;
    fraction1.input();

    Fraction fraction2(3, 5);
    fraction2.setNumerator(2);
    fraction2.setDenominator(3);
    cout << "****** Print Fraction1 *********" << endl;
    fraction1.print();
    cout << "****** Print Fraction2 *********" << endl;
    fraction2.print();
    cout << endl;

    cout << "=============== Summ Fraction ==============" << endl;
    Fraction sum = fraction1.addFraction(fraction2);
    sum.print();

    cout << "=============== Subtract Fraction ==============" << endl;
    Fraction difference = fraction1.subtractFraction(fraction2);
    difference.print();


    cout << "=============== Multiply Fraction ==============" << endl;
    Fraction product = fraction1.multiplyFraction(fraction2);
    product.print();


    cout << "=============== Divide Fraction ==============" << endl;
    Fraction quotient = fraction1.divideFraction(fraction2);
    quotient.print();

    cout << "Number of Fraction instances: " << Fraction::getInstanceCount() << endl;






}


