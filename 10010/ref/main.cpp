//Qiyuan Qiu
//UVa 10010: Where is Waldorf?
#include<algorithm>
#include<iostream>
#include<stdio.h>
using namespace std;
char a[55][55];
int m,n;

int dr[] = { 0, -1, -1, 1, 0, 1, 1,  1};
int dc[] = {-1, -1,  0, 1, 1, 1, 0, -1};

bool has_line(int x,int y, string line)
{
    for( int i = 0; i < 8; i++ ){
        int tr = x, tc = y, k = 0;
        for( int k = 0; k < line.size(); k++) {
            if( tr >= m || tr < 0 || tc >= n || tc <0 ) break;
            if( a[tr][tc] != line[k] ) break;
            tr += dr[i], tc += dc[i];
        } 
        if( k == line.size() ){
            return true;
        }
    }
    return false;
}

int main()
{
    int t;
    cin >> t;
    while(t--){
        cin >> m >> n;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cin >> a[i][j];
                if(a[i][j]>='A' && a[i][j]<='Z')
                    a[i][j] = a[i][j] - ('A'-'a');
                //            cout << a[i][j];
            }
            //       cout<<endl;
        }

        int nq;
        string line;
        cin >> nq;

        while(nq--)
        {
            cin >> line;
            //Converte to lower case
            for( int i=0; i<line.size();i++)
                if(line[i] >= 'A' && line[i] <='Z')
                    line[i] = line[i] - ('A' - 'a');
            bool found = false;
            for(int i=0;i<m;i++)
                for(int j=0;j<n;j++)
                {
                    if(has_line(i,j, line) && !found)
                    {
                        cout << i+1 << " " << j+1 << endl;
                        found = true;
                    }
                }
        }
        if(t > 0)
            cout<<endl;
    }

    return 0;
}
