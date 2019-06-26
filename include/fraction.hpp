
#ifndef PROJECT_INCLUDES_fraction_HPP_
#define PROJECT_INCLUDES_fraction_HPP_

class Fraction
{
    mpz_class num;
    mpz_class den;

    void reduce();

public:
    /**
     *  Constructors
     * 
     */
    Fraction()
        : num { 0 }, den { 0 }
    {
        reduce();
    }

    Fraction(int a, int b)
        : num { a }, den { b }
    {
        reduce();
    }

    Fraction(mpz_class a, mpz_class b)
        : num { a }, den { b }
    {
        reduce();
    }

    Fraction(const char* a, const char* b)
        : num { a }, den { b }
    {
        reduce();
    }

    /**
     *  Operators
     * 
     */
    Fraction& operator=(const Fraction& other);
    Fraction operator+(const Fraction& other) const noexcept;
    Fraction operator*(const Fraction& other) const noexcept;
    bool operator==(const Fraction& other) const noexcept;
    bool operator!=(const Fraction& other) const noexcept;

    std::string str() const noexcept;

    friend std::ostream& operator<<(std::ostream& outputStream, const Fraction& f)
    {
        return outputStream << f.str();
    }
};

#endif // PROJECT_INCLUDES_fraction_HPP_
