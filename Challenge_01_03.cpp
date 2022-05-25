#include <iostream>
#include <fstream>

int main()
{
    int i = 0, iSize, iHeigt, iWidth;
    unsigned char cByte;
    bool bByte = 1;
    std::ifstream fBMP;
    fBMP.open("pict32.bmp", std::ios::in);
    fBMP.seekg(2, std::ios::beg);
    for (int j = 5; j > 1; j--) {
        fBMP.seekg(j, std::ios::beg);
        fBMP >> cByte;
        i = i + cByte;
        if (j != 2) i = i << 8;
    }
    iSize = i - 1;
    i = 0;
    fBMP.seekg(19, std::ios::beg);
    fBMP >> cByte;
    i = i + cByte;
    i = i << 8;
    fBMP.seekg(18, std::ios::beg);
    fBMP >> cByte;
    i = i + cByte;
    iWidth = i;
    i = 0;
    fBMP.seekg(23, std::ios::beg);
    fBMP >> cByte;
    i = i + cByte;
    i = i << 8;
    fBMP.seekg(22, std::ios::beg);
    fBMP >> cByte;
    i = i + cByte;
    iHeigt = i;

    for (int y = 0; y < iHeigt; y++) {
        for (int x = iWidth - 1; x > -1; x--) {
            int iSeek = iSize - x * 3 - y * 3 * iWidth;
            fBMP.seekg(iSeek, std::ios::beg);
            fBMP >> cByte;
            if (cByte == 0) std::cout << "O "; else std::cout << ". ";
        }
        std::cout << std::endl;
    }

    fBMP.close(); 
    std::cout << "\n";
}
