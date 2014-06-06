I can across an issue where I think I can get the size of string array.

Turned out I was wrong. If I directly call lines->size it is going to give me the size of the first entry in the array. 

So work-around is to pass in the size of that array from outside the function. 


The problem I am faced with is how to turn continuous punctuations into only one space.
    Use the in_wrod state machine to solve this problem. 

First wrong answer comes from the case where there is puncuations separating the words like this:
    Dog,ate!homework!canary!died!!!

the program should be able to parse this line into someting like:
    Dog ate homework canary died
