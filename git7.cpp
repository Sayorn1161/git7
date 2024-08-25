#include <iostream>

class Fraction {
private:
    int numerator;
    int denominator;

    int gcd(int a, int b) const {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    void simplify() {
        int divisor = gcd(numerator, denominator);
        numerator /= divisor;
        denominator /= divisor;
    }

public:
    Fraction() : numerator(0), denominator(1) {}

    Fraction(int num, int denom) : numerator(num), denominator(denom) {
        if (denom == 0) {
            std::cerr << "Denominator cannot be zero, setting denominator to 1 by default." << std::endl;
            denominator = 1;
        }
        simplify();
    }

    void input() {
        std::cout << "Enter numerator: ";
        std::cin >> numerator;
        std::cout << "Enter denominator: ";
        std::cin >> denominator;
        if (denominator == 0) {
            std::cerr << "Denominator cannot be zero, setting denominator to 1 by default." << std::endl;
            denominator = 1;
        }
        simplify();
    }

    void output() const {
        std::cout << numerator << "/" << denominator << std::endl;
    }

    Fraction add(const Fraction& other) const {
        int num = numerator * other.denominator + other.numerator * denominator;
        int denom = denominator * other.denominator;
        return Fraction(num, denom);
    }

    Fraction subtract(const Fraction& other) const {
        int num = numerator * other.denominator - other.numerator * denominator;
        int denom = denominator * other.denominator;
        return Fraction(num, denom);
    }

    Fraction multiply(const Fraction& other) const {
        int num = numerator * other.numerator;
        int denom = denominator * other.denominator;
        return Fraction(num, denom);
    }

    Fraction divide(const Fraction& other) const {
        if (other.numerator == 0) {
            std::cerr << "Cannot divide by zero fraction, returning original fraction." << std::endl;
            return *this;
        }
        int num = numerator * other.denominator;
        int denom = denominator * other.numerator;
        return Fraction(num, denom);
    }

    Fraction operator+(const Fraction& other) const {
        return add(other);
    }

    Fraction operator-(const Fraction& other) const {
        return subtract(other);
    }

    Fraction operator*(const Fraction& other) const {
        return multiply(other);
    }

    Fraction operator/(const Fraction& other) const {
        return divide(other);
    }

    friend std::istream& operator>>(std::istream& in, Fraction& frac) {
        std::cout << "Enter numerator: ";
        in >> frac.numerator;
        std::cout << "Enter denominator: ";
        in >> frac.denominator;
        if (frac.denominator == 0) {
            std::cerr << "Denominator cannot be zero, setting denominator to 1 by default." << std::endl;
            frac.denominator = 1;
        }
        frac.simplify();
        return in;
    }

    friend std::ostream& operator<<(std::ostream& out, const Fraction& frac) {
        out << frac.numerator << "/" << frac.denominator;
        return out;
    }
};

int main() {
    Fraction f1(1, 2);
    Fraction f2(3, 4);

    Fraction f3 = f1 + f2;
    Fraction f4 = f1 - f2;
    Fraction f5 = f1 * f2;
    Fraction f6 = f1 / f2;

    std::cout << "f1: " << f1 << std::endl;
    std::cout << "f2: " << f2 << std::endl;
    std::cout << "f1 + f2: " << f3 << std::endl;
    std::cout << "f1 - f2: " << f4 << std::endl;
    std::cout << "f1 * f2: " << f5 << std::endl;
    std::cout << "f1 / f2: " << f6 << std::endl;

    return 0;
}
