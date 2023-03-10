
#include <iostream>
#include<cstring>
using namespace std;

void IP(unsigned char plaintext[]){
    unsigned char c[8];
    memset(c, 0, sizeof(c));
    char temp = 0;
    short part[8] = {64,16,4,1,128,32,8,2};

    for (int i = 0; i < 8; i++){
        for (int j = 7; j >= 0; j--){
            if ((plaintext[j] & part[i]) == 0)
            c[i] = (c[i] << 1) | 0;
            else c[i] = (c[i] << 1) | 1;
        }
    }

    for (int i =0;i<8;i++){
        plaintext[i] = c[i];        
    }
}

void FP(unsigned char plaintext[]){
    short checkBit = 1;
    short order[8] = {4,0,5,1,6,2,7,3};
    unsigned char c[8];
    memset(c,0,sizeof(c));

    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            if ((plaintext[order[j]] & checkBit) == 0)
                c[i] = (c[i] << 1) | 0;
            else c[i] = (c[i] << 1) | 1;
        }
        checkBit = checkBit * 2;
    }

    for (int i =0;i<8;i++){
        plaintext[i] = c[i];        
    }
}

int main() {
    unsigned char p[] = "hcmusfit";
    printf("Plain-text: ");
    
    for (size_t i =0; i < sizeof(p) -1; i++) printf("%02x ", p[i]);
    printf("\n");
    
    
    // for (size_t i =0; i < sizeof(p) -1; i++){
    //     print_bin(p[i]);
    // }
    
    IP(p);
    printf("IP(Plain-text):\t");
    
    for (size_t i =0; i < sizeof(p) -1; i++) printf("%02x ", p[i]);
    printf("\n");
    
    
    FP(p);
    printf("FP(Plain-text):\t");
    
    for (size_t i =0; i < sizeof(p) -1; i++) printf("%02x ", p[i]);
    printf("\n");
    
    
    // for (size_t i =0; i < sizeof(p) -1; i++){
    //     print_bin(p[i]);
    // }
    
    return 0;
}



// 1   2  3  4  5  6  7  8 
// 9  10 11 12 13 14 15 16 
// 17 18 19 20 21 22 23 24 
// 25 26 27 28 29 30 31 32 
// 33 34 35 36 37 38 39 40
// 41 42 43 44 45 46 47 48
// 49 50 51 52 53 54 55 56
// 57 58 59 60 61 62 63 64

// 57, 49, 41, 33, 25, 17, 9,  1
// 58,50, 42, 34, 26, 18, 10,  2
// 59, 51, 43, 35, 27, 19, 11, 3 
// 60, 52, 44, 36, 28, 20, 12, 4 
// 61, 53, 45, 37, 29, 21, 13, 5 
// 62, 54, 46, 38, 30, 22, 14, 6 
// 63, 55, 47, 39, 31, 23, 15, 7
// 64, 56, 48, 40, 32, 24, 16, 8 

// {58,50, 42, 34, 26, 18, 10, 2} 
// {60, 52, 44, 36, 28, 20, 12, 4} 
// {62, 54, 46, 38, 30, 22, 14, 6} 
// {64, 56, 48, 40, 32, 24, 16, 8} 
// {57, 49, 41, 33, 25, 17, 9,  1} 
// {59, 51, 43, 35, 27, 19, 11, 3} 
// {61, 53, 45, 37, 29, 21, 13, 5} 
// {63, 55, 47, 39, 31, 23, 15, 7}
