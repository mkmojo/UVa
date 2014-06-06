#include <iostream>
using namespace std;


int get_n_keywords(string line, string key_words[], int size)
{
    //convert into all lowercase
    for( int i = 0 ; i < line.size(); i++){
        if( line[i] <= 'Z' && line[i] >= 'A')
            line[i] = line[i] + 'a' - 'A';
    }

    int sum = 0;
    while(line != ""){
        size_t pos;
        pos = line.find(" ");
        string cnt_word = "";
        if(pos != -1){
            cnt_word = line.substr(0, pos);
            line = line.substr(pos+1, line.size() - cnt_word.size() - 1);
        }
        else{
            cnt_word = line;
            line = "";
        }
        for( int i = 0 ; i < size; i++) {
            //cout << cnt_word << " " << key_words[i] << endl;
            if( cnt_word == key_words[i] ) sum++;
        }
    }
    return sum;
}

int main()
{
    int k, e;
    int t = 0;
    string words[21];
    string lines[21];
    int line_num[20];
    
    while(cin >> k >> e){
        cin.ignore();

        for( int i= 0 ; i < e; i++){
            line_num[i] = 0;
        }

        for( int i = 0 ; i < k; i++){
            cin >> words[i];
            //cout << words[i] << endl;
        }
        cin.ignore();
        int max = -1;
        for( int i = 0 ; i < e; i++){
            getline(cin, lines[i]);
            string parsed_line = "";
            //get rid of punctuation
            bool in_word = false;
            for(int j = 0 ; j < lines[i].size(); j++) {
                if( (lines[i][j] >= 'a' && lines[i][j] <= 'z') || 
                        (lines[i][j] >= 'A' && lines[i][j] <= 'Z') ){
                    if(in_word == true)
                        parsed_line += lines[i][j];
                    else {
                        in_word = true;
                        parsed_line = parsed_line + " " +  lines[i][j];
                    }
                }
                else{
                    //sees punctuation
                    if(in_word == true){
                        in_word = false;
                    }
                }
            }
            //cout << parsed_line << endl;
            line_num[i] = get_n_keywords(parsed_line, words, k);
            //cout << lines[i] << " " << line_num[i] << endl;
            if( line_num[i]  > max){
                max =  line_num[i]; 
            }
        }
        //if(t!=0) cout << endl;
        cout << "Excuse Set #" << ++t << endl;
        for( int i = 0 ; i < e ; i++){
            if( line_num[i] == max) 
                cout << lines[i]  << endl;
        }
        cout << endl;
    }

    return 0;
}
