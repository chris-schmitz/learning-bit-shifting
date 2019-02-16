#include <iostream>

enum printType {
    DECIMAL,
    HEXADECIMAL,
};

// declarations
void printNumber (long value, printType type);
long shift(long value);

int idArray[] = {0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff, 0x00, 0x11};

int main(int argc, const char * argv[]) {
    long compiled = 0;

    for (uint8_t i = 0; i < 8; i++){
        compiled = shift(compiled);
        compiled +=(long) idArray[i];
    }
    
    printNumber(compiled, HEXADECIMAL);
    
}

long shift(long value) {
    return value << 8;
}

void printNumber (long value, printType type) {
    if (type == DECIMAL) {
        std::cout << value << std::endl;
    } else if (type == HEXADECIMAL) {
        std::cout << std::hex << value << std::endl;
    }
}
