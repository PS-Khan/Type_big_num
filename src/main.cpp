#include <iostream>
#include "BigInteger.h"


int main() {
    
    // Create a BigInteger object with a hex value
    BigInteger num;
    std::string hexString = "1A2B3C4D5E6F7A8B9C0D1E2F3A4B5C6D7E8F9A0B1C2D3E4F5A6B7C8D9E0F";
    num.setHex(hexString);

    
    BigInteger inverted = num.INV();

    // Display the original and inverted values
    std::cout << "Original Hex String: " << hexString << std::endl;
    std::cout << "GetHex: " << num.getHex() << std::endl;


    //2


    std::cout << "Inverted Integer: " << inverted.getHex() << std::endl;
    std::cout << "\n";

    BigInteger numberA;
    BigInteger numberB;
    BigInteger numberC;
    numberA.setHex("51bf608414ad5726a3c1bec098f77b1b54ffb2787f8d528a74c1d7fde6470ea4");
    numberB.setHex("403db8ad88a3932a0b7e8189aed9eeffb8121dfac05c3512fdb396dd73f6331c");

    numberC = numberA.XOR(numberB);
    std::cout << "XOR Result: " << numberC.getHex() << std::endl;

    numberC = numberA.OR(numberB);
    std::cout << "OR Result: " << numberC.getHex() << std::endl;

    numberC = numberA.AND(numberB);
    std::cout << "AND Result: " << numberC.getHex() << std::endl;

    numberC = numberA.shiftR(2);
    std::cout << "Shift Right Result: " << numberC.getHex() << std::endl;

    numberC = numberA.shiftL(2);
    std::cout << "Shift Left Result: " << numberC.getHex() << std::endl;

    std::cout << "\n";
    //3

    BigInteger num1;
    BigInteger num2;
    BigInteger result;

    num1.setHex("36f028580bb02cc8272a9a020f4200e346e276ae664e45ee80745574e2f5ab80");  
    num2.setHex("70983d692f648185febe6d6fa607630ae68649f7e6fc45b94680096c06e4fadb"); 

    result = num1.ADD(num2);

    std::cout << "num1: " << num1.getHex() << std::endl;
    std::cout << "num2: " << num2.getHex() << std::endl;
    std::cout << "result: " << result.getHex() << std::endl;



    // Test >= operator
    BigInteger num3;
    BigInteger num4;

    num3.setHex("33ced2c76b26cae94e162c4c0d2c0ff7c13094b0185a3c122e732d5ba77efebc");
    num4.setHex("22e962951cb6cd2ce279ab0e2095825c141d48ef3ca9dabf253e38760b57fe03");

    if (num3 >= num4) {
        std::cout << "num3 is greater than or equal to num4" << std::endl;
    } else {
        std::cout << "num3 is less than num4" << std::endl;
    }

    // Test SUB function
    BigInteger resultSub;
    resultSub = num3.SUB(num4);
    std::cout << "Subtraction result: " << resultSub.getHex() << std::endl;
    
    BigInteger num7;
    num1.setHex("123456789ABCDEF0");

    
    BigInteger result7 = num7.shiftR(4);
    std::cout << "Shift Right result: " << result7.getHex() << std::endl;  // Should output "0123456789ABCDEF"

    
    BigInteger num8;
    num2.setHex("123456789ABCDEF0");

    
    BigInteger result8 = num8.shiftL(4);
    std::cout << "Shift Left result: " << result8.getHex() << std::endl;  // Should output "23456789ABCDEF00"


    return 0;
}
