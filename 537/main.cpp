#include <iostream>
#include <map>
#include <iomanip>
using namespace std;

map <char, double> concepts;
map <char, double>::iterator it;
map <char, double> prefix;
map <char, char> units;

void init_prefix()
{
    prefix['m'] = 0.001;
    prefix['k'] = 1000.0;
    prefix['M'] = 1000000.0;
}

void init_concepts()
{
    concepts.clear();
}

void init_units()
{
    units['U'] = 'V';
    units['I'] = 'A';
    units['P'] = 'W';
}

double str_2_num(string in)
{
    //cout << "in fr str_2_num is: " << in << endl;
    size_t pos = 0;
    pos  = in.find(".");
    if(pos == -1) {
        //simple calse no decimal point
        //cout << "does not have decimal point" << endl;
        double ans = 0.0;
        for(int i=0;i<in.size();i++){
           ans = ans * 10 + (in[i] - '0') ;
        }
        //cout<< "ans is "<< ans << endl;
        return ans;
    }
    else {
        //there is decimal point
        string left = in.substr(0, pos);
        string right = in.substr(pos+1, in.size() - left.size() - 1 );

        //cout << "left is " << left << endl;
        //cout << "right is " << right << endl;
        double l_val = 0.0;
        for(int i = 0 ; i<left.size(); i++) {
            l_val = l_val*10 + (left[i] - '0');
        }

        double r_val = 0.0;
        for(int i = right.size() - 1 ; i >= 0; i--){
            r_val = r_val/10 + (right[i] - '0');
        }
        
        return l_val + r_val/10;
    }
}

double get_val(string in)
{
    int n = in.size();
    char prx = in[n-1];
    //cout << "prx is " << prx << endl;
    if( prx <= '9' && prx >= '0' ) {
        //there is no prefix
        //convert to number 
        string str_num = in;
        //cout<< "There is no prefix" << endl;
        //cout << "the str of str_num is: " << str_num << endl;
        //cout << "the value of  str_num is : " << str_2_num(str_num) << endl;
        return str_2_num(str_num);
    }
    else{
        // there is prefix
        double dou_prx = prefix[prx]; 
        string str_num = in.substr(0, n-1);
        double str_val = str_2_num(str_num);
        return str_val * dou_prx;
    }

}

int main()
{
    int t;
    init_prefix();
    init_units();
    cin >> t; 
    cin.ignore();
    for(int i = 0; i < t; i++ ){
        string line;
        getline(cin, line);
        //cout << line <<endl;

        init_concepts();
        //parsing the sentence
        while(true){
            size_t pos;
            string word;
            pos = line.find(" ");
            if(pos != -1){
                word = line.substr(0, pos);
                line = line.substr(pos+1, line.size() - word.size() - 1);
            }
            else{
                word = line;
            }
            //cout << word << endl;

            if( word.find("=") != -1){
                pos = word.find("=");
                char concept = word[pos-1];
                size_t unit_pos = word.find(units[concept]);
                double num = 0.0;
                string str_num = word.substr(pos+1, unit_pos - pos -1 );
                //cout<< "string passed in for get_val is: " << str_num <<endl;
                num = get_val(str_num);
                //cout << "num is : " << num <<endl;
                concepts[concept] = num;
                //cout << "concept: " <<concept << " is: " <<concepts[concept] <<endl;
            }
            
            if(pos == -1)
                break;
        }

        cout << "Problem #" << i + 1 <<endl;
        

        if(concepts.find('U') == concepts.end()){
            // U not found 
            if ( concepts['I'] != 0)
                cout<< "U=" << setprecision(2) << fixed << concepts['P'] / concepts['I'] << "V\n" <<endl;
        }
        else if(concepts.find('I') == concepts.end()){
            // I not found 
                cout<< "I="<<  setprecision(2) << fixed<< concepts['P'] / concepts['U'] <<"A\n"<< endl;
        }
        else{
            //P not found 
                cout<< "P="<<setprecision(2) << fixed<< concepts['U'] * concepts['I'] <<"W\n"<< endl;
        }

    }
    return 0;
}
