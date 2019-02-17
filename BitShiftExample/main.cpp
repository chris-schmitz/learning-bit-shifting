#include <iostream>

enum printType {
    DECIMAL,
    HEXADECIMAL,
};

// declarations
void printNumber (long value, printType type);
long shift(long value);

class RFIDData {
public:
    static const uint8_t idLength = 10;
    
private:
    int idArray[idLength] = {0};
    uint8_t currentIndex = 0;
    
public:
    void addIdElement(int element) {
        this->idArray[this->currentIndex] = element;
        this->currentIndex++;
    }
    void printArray() {
        for (uint8_t i = 0 ; i < idLength; i ++){
            std::cout << std::hex << this->idArray[i];
        }
        std::cout << std::endl;
    }
};

int idArray[] = {0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff, 0x00, 0x11, 0x22, 0x33};

int main(int argc, const char * argv[]) {
//    long compiled = 0;
//
//    for (uint8_t i = 0; i < 8; i++){
//        compiled = shift(compiled);
//        compiled +=(long) idArray[i];
//    }
//
//    printNumber(compiled, HEXADECIMAL);
    
    
    RFIDData rfid;
    
    for (uint8_t i = 0; i < 10; i++){
        rfid.addIdElement(idArray[i]);
    }
    rfid.printArray();
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

