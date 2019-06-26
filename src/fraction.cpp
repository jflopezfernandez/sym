
#include "sym.hpp"

void Fraction::reduce()
{
    mpz_class frac_gcd = gcd(num, den);

    if (frac_gcd == 1) {
        return;
    }

    num /= frac_gcd;
    den /= frac_gcd;
}

/**
 *  Operators
 * 
 */
Fraction& Fraction::operator=(const Fraction& other)
{
    num = other.num;
    den = other.den;

    return *this;
}

Fraction Fraction::operator+(const Fraction& other) const noexcept
{
    return Fraction((num * other.den) + (den * other.num), (den * other.den));
}

Fraction Fraction::operator*(const Fraction& other) const noexcept
{
    return Fraction((num * other.num), (den * other.den));
}

bool Fraction::operator==(const Fraction& other) const noexcept
{
    if ((num == other.num) && (den == other.den)) {
        return true;
    }

    return false;
}

bool Fraction::operator!=(const Fraction& other) const noexcept
{
    return !(*this == other);
}

std::string Fraction::str() const noexcept
{
    std::ostringstream oss;

    oss << num;

    // TODO: Remove these debugging functions
    // std::cout << "mpz_cmp_ui(num.get_mpz_t(), 0) == 0 ?? " << std::boolalpha << (mpz_cmp_ui(num.get_mpz_t(), 0) == 0) << std::endl;
    // std::cout << "mpz_cmp_ui(den.get_mpz_t(), 1) == 0 ?? " << std::boolalpha << (mpz_cmp_ui(den.get_mpz_t(), 1) == 0) << std::endl;

    if (num == 0) {
        return oss.str();
    }

    if (den != 1) {
        oss << "/" << den;
    }

    return oss.str();
}
