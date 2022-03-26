#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>

std::string read_file(std::string file_name) {
    
    std::ifstream file(file_name);
    std::string fileStr;

    std::istreambuf_iterator<char> inputIt(file), emptyInputIt;
    std::back_insert_iterator<std::string> stringInsert(fileStr);

    copy(inputIt, emptyInputIt, stringInsert);

    return fileStr;
}

int write_file(std::string file_name, int count) {

    std::ofstream file;
    file.open(file_name);
    file << std::to_string(count);
    file.close();
  return 0;
}

int main(int argc, char const *argv[])
{

    std::string file_str = read_file("count.txt");

    int file_count = stoi(file_str);
    file_count++;
    
    write_file("count.txt", file_count);   
    
    return 0;
}