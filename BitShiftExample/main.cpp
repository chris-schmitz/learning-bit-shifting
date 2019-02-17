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
    int idArray[idLength] = {0};

private:
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
    

    bool compare( RFIDData payload2){
        for (uint8_t i = 0 ; i < this->currentIndex; i++){
            if (this->idArray[i] != payload2.idArray[i]) {
                return false;
            }
        }
        return true;
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
    
    
    RFIDData rfid1;
    RFIDData rfid2;

    for (uint8_t i = 0; i < 10; i++){
        rfid1.addIdElement(idArray[i]);
    }
    rfid1.printArray();
    
    for (uint8_t i = 0; i < 9; i++){
        rfid2.addIdElement(idArray[i]);
    }
    rfid2.printArray();
    
    std::cout << rfid1.compare(rfid2) << std::endl;
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

