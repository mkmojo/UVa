//Qiyuan Qiu
//UVa 401: Palindromes
#include <vector>
#include <iostream>
#include <utility>
#include <map>
#include <typeinfo>
using namespace std;
map<char, char> table;

bool is_palindrome(string str)
{
    int i=0;
    int j=str.size() - 1;
    bool res = true;
    while(i<=j)
    {
       if(str[i] != str[j])
       {
           res = false;
       }
       i++;
       j--;
    }
   return res; 
}

bool is_mirrorred(string str)
{
    
    int i=0;
    int j=str.size() - 1;
    bool res = true;
    while(i<=j)
    {
        //cout<< "type of a str[i] is:" << typeid(str[i]).name()<<endl;
        //cout <<   table.find(str[i])->second << " " << str[j] <<endl;

        if( table.find(str[i])->second !=  str[j])
        {
            res = false;
            break;
        }
        i++;
        j--;
    }
    return res; 

}

int main()
{
    string str;
    string s = "ABCDEFGHIJKLMNOPQRSTUVWXYZ123456789";
    string r = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";
    for(int i=0;i<s.size();i++)
        table[s[i]] = r[i];
        while( cin >> str )
    {
        bool t1 = is_palindrome(str);
        bool t2 = is_mirrorred(str);
        //cout << str << " "<< t1 << " " << t2 <<  endl;
        if( t1 == 0 && t2 == 0)
            cout << str << " -- is not a palindrome.\n" <<endl;
        else if( t1 == 0 && t2 == 1)
            cout << str << " -- is a mirrored string.\n" <<endl;
        else if( t1 == 1 && t2 == 0)
            cout << str << " -- is a regular palindrome.\n" <<endl;
        else
            cout << str << " -- is a mirrored palindrome.\n" <<endl;
    }
    return 0;
}
