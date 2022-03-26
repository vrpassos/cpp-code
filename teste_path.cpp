//#include "pstream.h"
#include <string>
#include <iostream>
#include <fstream>
//#include <stdexcept>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <cmath>


std::string decrypt_str(std::string msg, int key) {

    int len_str = msg.length();
    std::string out_str;
	
	for (int i=0; i<len_str; i=i+std::to_string(key).length()) {
        
        for (int j=0; (j<(std::to_string(key).length()))&&((i+j)<len_str); j++) {

            int power = std::pow(10, (std::to_string(key).length())-j);            
            int digit_key = (key % power)/(power/10);            
                        
            char letter = (char)((int)msg[i+j] - (digit_key));
            out_str.push_back(letter);            
        }        
    }
    return out_str;
}

std::string getexepath()
{
    char result[ PATH_MAX ];
    // str = "/proc/self/exe"
    ssize_t count = readlink(decrypt_str("7t{pf4wmpo0h}i",8491354).c_str(), result, PATH_MAX);
    
    return std::string(result, (count > 0) ? count : 0);    
}

int main(int argc, char const *argv[])
{

    // Toma o caminho onde o programa está sendo executado
    std::string path = getexepath();
    std::cout << path << std::endl;    

    // Se o crc ou o caminho conflitarem, desliga o sistema
    // str = "/etc/mount-on-boot"
    // (path != decrypt_str("4eyl0npzny6po.got}",5059111))
    //     system("echo Erro no path");
    
    return 0;
}