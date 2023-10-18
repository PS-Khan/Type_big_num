#include "BigInteger.h"


BigInteger::BigInteger() {
    

};

BigInteger::BigInteger(const std::string &hexString) {
    setHex(hexString);
};




void BigInteger::setHex(const std::string &hexString, char m) {
    if (hexString.empty()) {
        std::cout << "Hex string is empty";
        return;
    }
    data.clear();
    // Розділяємо рядок на блоки по 8 символів (32 біт)//error out of range with 64 bits(think how to solve in future)
    for (size_t i = 0; i < hexString.length(); i += 8) {
        std::string block = hexString.substr(i, 8);
        if (m == 't') {
            std::cout << block << std::endl;
        }
        // Remove "0x" prefix if it exists
        if (block.substr(0, 2) == "0x") {
            block = block.substr(2);
        }

        unsigned long block_int = std::stoul(block, 0, 16);
        data.push_back(block_int);
        if (m == 't') {
            std::cout << "Block " << i / 16 << ": " << block << " (as integer: " << block_int << ")" << std::endl;
        }
    }
    if (m == 't') {
        std::cout << "Original Hex String: " << hexString << std::endl;
    }
}


const std::string BigInteger::getHex() {
    std::string hexString = "";
    
    for (unsigned int block : data) {
        char hexChars[17] = "0123456789ABCDEF";
        std::string blockHex;
        while (block > 0) {
            int remainder = block % 16;
            blockHex = hexChars[remainder] + blockHex;
            block /= 16;
        }
        hexString += blockHex;
    }

    return hexString;
}


//2

BigInteger BigInteger::INV() const {
    BigInteger result;
    result.data.resize(data.size());
    
    for (size_t i = 0; i < data.size(); i++) {
        result.data[i] = ~data[i];
    }
    
    return result;
}


BigInteger BigInteger::XOR(const BigInteger &other) const {
    BigInteger result;
    result.data.resize(data.size());

    for (size_t i = 0; i < data.size(); i++) {
        result.data[i] = data[i] ^ other.data[i];
    }

    return result;
}

BigInteger BigInteger::OR(const BigInteger &other) const {
    BigInteger result;
    result.data.resize(data.size());

    for (size_t i = 0; i < data.size(); i++) {
        result.data[i] = data[i] | other.data[i];
    }

    return result;
}

BigInteger BigInteger::AND(const BigInteger &other) const {
    BigInteger result;
    result.data.resize(data.size());

    for (size_t i = 0; i < data.size(); i++) {
        result.data[i] = data[i] & other.data[i];
    }

    return result;
}
BigInteger BigInteger::shiftR(int n) const {
    BigInteger result;
    result.data = data;

    // Shift the individual blocks to the right
    for (size_t i = 0; i < result.data.size(); i++) {
        result.data[i] >>= n;

        if (i < result.data.size() - 1) {
            // For the first block (i == 0), fill with zeros on the left side
            result.data[i] |= (data[i + 1] & ((1ULL << n) - 1)) << (sizeof(data[i]) * 8 - n);
        }
    }

    return result;
}

BigInteger BigInteger::shiftL(int n) const {
    BigInteger result;
    result.data = data;

    // Shift the individual blocks to the left
    for (size_t i = 0; i < result.data.size(); i++) {
        result.data[i] <<= n;

        if (i > 0) {
            // For the last block (i == result.data.size() - 1), fill with zeros on the right side
            result.data[i] |= (data[i - 1] >> (sizeof(data[i]) * 8 - n));
        }
    }

    return result;
}

//3

BigInteger BigInteger::ADD(const BigInteger& other) const {
    BigInteger result;
    result.data.resize(std::max(data.size(), other.data.size()) + 1);  // Adding one extra block for potential carry.

    unsigned long carry = 0;
    for (size_t i = 0; i < result.data.size(); i++) {
        unsigned long sum = carry;
        if (i < data.size()) sum += data[i];
        if (i < other.data.size()) sum += other.data[i];
        result.data[i] = sum;
        carry = sum >> (sizeof(data[i]) * 8 - 1);  

        
        if (sum < data[i] && sum < other.data[i]) {
            carry = 1;  // If the sum is less than both input values, there's a carry.
        }
    }

    
    while (result.data.size() > 1 && result.data.back() == 0) {
        result.data.pop_back();
    }

    return result;
}

BigInteger BigInteger::SUB(const BigInteger& other) const {
    BigInteger result;
    result.data.resize(std::max(data.size(), other.data.size()));

    unsigned long borrow = 0;
    for (size_t i = 0; i < result.data.size(); i++) {
        long long difference = static_cast<long long>(data[i]) - borrow;

        if (i < other.data.size()) {
            if (static_cast<long long>(other.data[i]) <= difference) {
                difference -= other.data[i];
            } else {
                difference += 1LL << (sizeof(data[i]) * 8);
                borrow = 1;
            }
        }

        result.data[i] = static_cast<unsigned long>(difference);
    }

    
    if (result.data.empty()) {
        result.data.push_back(0);
    }

    return result;
}

bool BigInteger::operator>=(const BigInteger& other) const {
    if (data.size() > other.data.size()) {
        return true;
    }
    if (data.size() < other.data.size()) {
        return false;
    }

    for (int i = static_cast<int>(data.size()) - 1; i >= 0; i--) {
        if (data[i] > other.data[i]) {
            return true;
        }
        if (data[i] < other.data[i]) {
            return false;
        }
    }

    return true;  // If they are equal
}

bool BigInteger::isZero() const {
    for (size_t i = 0; i < data.size(); i++) {
        if (data[i] != 0) {
            return false;
        }
    }
    return true;
}


void BigInteger::printData() {
    for (unsigned long block : data) {
        std::cout << std::hex << block << ' ';
    }
    std::cout << std::endl;
}