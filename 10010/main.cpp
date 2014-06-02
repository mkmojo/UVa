//Qiyuan Qiu
//UVa 10010: Where is Waldorf?
#include<algorithm>
#include<iostream>
#include<stdio.h>
using namespace std;
char a[55][55];
int m,n;

bool has_line(int x,int y, string line)
{
    int len = line.size();
    string cand = "";
    //check hrizontal center to right
    cand = "";
    for( int i=0; i<len; i++)
        cand += a[x][y+i];
    if( cand == line )
        return true;

    //check hrizontal ceter to left
    cand = "";
    for( int i=0; i<len; i++)
        cand += a[x][y-i];
    if( cand == line )
        return true;
    
    //check vertical center to bottom
    cand = "";
    for( int i=0; i<len; i++)
        cand += a[x+i][y];
    if( cand == line )
        return true;
    
    //check vertical center to top
    cand = "";
    for( int i=0; i<len; i++)
        cand += a[x-i][y];
    if(cand == line)
        return true;
    //chek for diag center to top-left
    cand = "";
    for( int i=0; i<len; i++)
        cand += a[x-i][y-i];
    if( cand == line )
        return true;
    
    //chek for diag center to top-right
    cand = "";
    for( int i=0; i<len; i++)
        cand += a[x-i][y+i];
    if( cand == line )
        return true;

    //chek for diag center to bottom-left
    cand = "";
    for( int i=0; i<len; i++)
        cand += a[x+i][y-i];
    if( cand == line )
        return true;
    
    //chek for diag center to bottom-right
    cand = "";
    for( int i=0; i<len; i++)
        cand += a[x+i][y+i];
    if( cand == line )
        return true;

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
