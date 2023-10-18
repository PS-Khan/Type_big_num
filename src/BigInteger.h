
#ifndef BIGINTEGER_H  
#define BIGINTEGER_H

#include <string>
#include <vector>
#include <iostream>

class BigInteger {
public:
    BigInteger(); 
    BigInteger(const std::string& hexString);
    void setHex(const std::string &hexString, char m = '\0');
    const std::string getHex();
    BigInteger INV() const;
    BigInteger XOR(const BigInteger &other) const;
    BigInteger OR(const BigInteger &other) const;
    BigInteger AND(const BigInteger &other) const;
    BigInteger shiftR(int n) const;
    BigInteger shiftL(int n) const;
    BigInteger ADD(const BigInteger& other) const;
    BigInteger MOD(const BigInteger& other) const;
    BigInteger SUB(const BigInteger& other) const;
    void printData();
    bool isZero() const;

    bool operator>=(const BigInteger& other) const;

private:
    std::vector<unsigned long> data;

};

#endif