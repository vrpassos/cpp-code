#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

std::string decrypt_str(std::string msg, int key) {

    int str_len = msg.length();
    std::string out_str;    
	
	for (int i=0; i<str_len; i+=8) {
        
        for (int j=0; (j<4)&&((i+2*j)<str_len); j++) {

            std:string msg_byte = msg.substr(i+(2*j),2);
            
            int digit = ((int)strtol(msg_byte.c_str(), NULL, 16) - ((key >> 8*(3-j)) & 0xff)) &0xff;
            
            out_str.push_back((char)digit);
        }        
    }
    return out_str;

}

int main()
{    
    int key = 1348606072;

    string in_str = "7fca87e5b59188e17fd98fef7fd57beab9d28ceb7fd58cd9c2d677ebb3d481e8c4d5";    

    cout << in_str << endl;    

    string out_dec_str = decrypt_str(in_str, key);    
    
    cout << out_dec_str << endl;

    return 0;
}