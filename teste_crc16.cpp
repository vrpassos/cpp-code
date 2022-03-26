#include <stdio.h>
#include <iostream>
#include <fstream>

using namespace std;

int crc16(const char *buffer, int size) {
	unsigned char j,aux=0;
	int i,crc=0;
	for (i=0; i<size; i++){
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

int main() {
    string file_str = read_file("teste.txt");
    const char *file_char = file_str.c_str();    	
    int crc_file = crc16((char*)file_char, file_str.length());

	cout << file_str << endl;
	cout << crc_file << endl;

    return 0;
}