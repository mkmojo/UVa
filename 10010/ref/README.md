I modified my code based on the reference here:
    http://saicheems.wordpress.com/2014/01/05/uva-10010-wheres-waldorf/

Reference does a better job in turns of searching for eight direcitons. 
It uses two arrays to track the next direction to search. one for the x axis and the other for y axis to do the dfs.


int x[] = { 0, -1, -1, 1, 0, 1, 1,  1}
int y[] = {-1, -1,  0, 1, 1, 1, 0, -1}
search position (r, c):
     for each direction i :
          tr = r, tc = c , k;
          for (k=0; k<word.size();k++)
               if (tr >= m || tr < 0 || tc < 0 || tc >= n) break // this line check for border
               if( !equal(a[tr][tc], word[k]) break // this line check for word
               tr += x[i]
               tc += y[i]
         
          if k == word.size()
               return true
    return false 
