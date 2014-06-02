//test the find method for map
#include <map>
#include <iostream>
#include <utility>
using namespace std;

int main()
{
    map<string, string> table;
    table.insert(make_pair("A", "A")) ;
    table.insert(make_pair("E", "3")) ;
    table.insert(make_pair("H", "H")) ;
    table.insert(make_pair("I", "I")) ;
    table.insert(make_pair("J", "L")) ;
    table.insert(make_pair("L", "J")) ;
    table.insert(make_pair("M", "M")) ;
    table.insert(make_pair("O", "O")) ;
    table.insert(make_pair("S", "2")) ;
    table.insert(make_pair("T", "T")) ;
    table.insert(make_pair("U", "U")) ;
    table.insert(make_pair("V", "V")) ;
    table.insert(make_pair("W", "W")) ;
    table.insert(make_pair("X", "X")) ;
    table.insert(make_pair("Y", "Y")) ;
    table.insert(make_pair("Z", "5")) ;
    table.insert(make_pair("1", "1")) ;
    table.insert(make_pair("2", "S")) ;
    table.insert(make_pair("3", "E")) ;
    table.insert(make_pair("5", "Z")) ;
    table.insert(make_pair("8", "8")) ;

    cout<< table.find("A")->second <<endl;
    return 0;
}

