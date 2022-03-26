#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cmath>

using namespace std;

string decrypt_str(string msg, int key) {

    int len_str = msg.length();
    string out_str;
	
	for (int i=0; i<len_str; i=i+to_string(key).length()) {
        
        for (int j=0; (j<(to_string(key).length()))&&((i+j)<len_str); j++) {

            int power = pow (10, (to_string(key).length())-j);            
            int digit_key = (key % power)/(power/10);            
                        
            char letter = (char)((int)msg[i+j] - (digit_key));
            out_str.push_back(letter);            
        }        
    }
    return out_str;

}

int main()
{    
    int key = 849135;

    string out_dec_str = decrypt_str("mt", 1);    

    system(out_dec_str.c_str());

    return 0;
}