#include <iostream>
#include <stdexcept>
#include <stdio.h>
#include <fstream>

using namespace std;

unsigned int crc16(char *buffer, int size) {
	char j,aux=0;
	int i,crc=0;
	for (i=0; i<size; i++) {
		aux = buffer[i];
		for (j=0;j<8;j++) {
			if (((aux & 0x01) ^ (crc & 0x0001)) != 0) {
				crc = crc >> 1;
				crc = crc ^ 0xA001;
			}
			else {
				crc = crc >> 1;
			}
			aux >>= 1;
		}
	}
	return crc;
}

string read_file(string file_name) {
    
    ifstream file(file_name);
    string fileStr;

    istreambuf_iterator<char> inputIt(file), emptyInputIt;
    back_insert_iterator<string> stringInsert(fileStr);

    copy(inputIt, emptyInputIt, stringInsert);

    return fileStr;
}    

int main()
{    
    
    string out_str = read_file("teste.txt");    
    cout << out_str << endl;    
    
    return 0;
}