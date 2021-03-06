/**  Problem Link: https://www.hackerrank.com/contests/security-challenge/challenges/decoding-and-encoding
*
*   @Aparna Goyal, 1911981092, 18/08/2021  */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

char ch_to_base32(char c) {
    if(c >= 'A' && c <= 'Z') {
        return c - 'A';
    }
    else if(c >= '2'&& c <= '7') {
        return c - '2' + 26;
    }
    else {
        //error? == pad
        return 32;
    }
}

char base64_to_ch( char b) {
    if(b >= 0 && b <= 25) {
        return b + 'A' - 0;
    }
    if(b >= 26 && b <= 51) {
        return b + 'a' - 26;
    }
    else if(b >= 52 && b <= 61) {
        return b+'0'-52;
    }
    else if(b == 62) {
        return '+';
    }
    else if(b == 63) {
        return '/';
    }
    else {
        return '$';
    }
}

int main() {
    int testcase;
    scanf("%d", &testcase);
    char str[1001];
    char orginal[1001];
    char output[1001];
    for(int i = 0; i < testcase; i++) {
        for(int j = 0; j < 1001; j++) {
            str[j] = 0;
            orginal[j] = 0;
            output[j] = 0;
        }
        scanf("%s", str);
        int len = strlen(str);
        int pad = 0;
        int po = 0;
        int pout = 0;
        for(int j = 0; j < len; j += 8) {
            long long temp = 0;
            for(int k = 0; k < 8; k++) {
                int ch = ch_to_base32(str[j+k]);
                if(ch == 32) {
                    pad++;
                    ch = 0;
                }
                temp = (temp<<5) + ch;
                
            }
            
            for(int k = 4; k >= 0; k--) {
                orginal[po+k] = temp&0xFF;
                temp = temp >> 8;
            }
            po += 5;
        }
        if(pad == 6) {
           po -= 4;
        }
        else if(pad == 4) { 
            po -= 3;
        }
        else if(pad == 3) {
            po -= 2;
        }
        else if(pad == 1) { 
            po -= 1;
        }
        pad = po % 3;
        if(pad!=0) { 
            pad = 3-pad;
        }
        for(int j = 0; j<po; j+=3) {
            long long temp = 0;
            for(int k = 0; k < 3; k++) {
                temp = (temp<<8) + orginal[j+k];
            }
            
            for(int k = 3; k >= 0; k--) {
                output[pout+k] = base64_to_ch(temp&0x3F);
                temp = temp>>6;
            }
            pout += 4;
        }
        for(int k = 1; k <= pad; k++) { 
            output[pout-k] = '=';
        }
        printf("%s\n",output);
    }
    return 0;
}