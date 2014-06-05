Neet to extract out numbers that has physical meanings from given lines.

The pattern we use to extract out physical numbers are that it has '=' in it

The challenge here is that
I want to find the '=' and then extract out the word that has '=' in it but how can I do that?
The reason I feel it is hard: there is no easy way to tokenize the entire line. 

The challenge after I can store two of U/I/P in  a map:
    How can I know the third one?
    After successfully parsed one input sentence, we have two of the three possible 
    pysical numbers.
    We need to know the third one.

My solution to this: 
    Take advantage of the map. 
    If the find method cannot find some element, then it must be the case where that 
    missing one needs to be calculated. 
