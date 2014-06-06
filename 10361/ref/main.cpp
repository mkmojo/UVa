//Qiyuan Qiu
//UVa 10361:  Automatic Poetry 
#include<iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    cin.ignore(); // use geline after cin will need this work-around.
    char tokens[] = {'<', '>', '<', '>'};

    while(t--){
        string line1 = "";
        string line2 = "";
        getline(cin, line1);
        getline(cin, line2);
    
        //cout << line1 << endl;
        //cout << line2 << endl;

        string tline = line1;
        string s[5];
        for( int i=0; i<5; i++){
            s[i] = "";
        }

        //here when constructing new strings
        for( int i=0; i<4; i++){
            size_t pos = tline.find(tokens[i]);
            s[i] = tline.substr(0, pos + 1 - 1);
            tline = tline.substr(pos+1, tline.size() - s[i].size() - 1);
            if(i == 3)
                s[4] = tline;
            //cout<< "s[" << i<< "] is: " << s[i] << endl;
            //cout<< "tline is: " << tline << endl;
        }

        string newline1 = "";
        for ( int i = 0 ; i<5; i++)
            newline1 += s[i];
        cout << newline1 << endl;

        string newline2 = line2;
        size_t pos = newline2.find("...");
        newline2.erase(pos, 3);
        newline2 += ( s[3] + s[2] + s[1] + s[4]);
        
        cout<<newline2<<endl;

    }
    return 0;
}
