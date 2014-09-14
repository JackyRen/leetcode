# LeetCode

## reverse words in a string

### Time
O(n)

### Space
O(1)

##python code
### main.py
the starting point  
    `python2 main.py`
### tests.py
testcases stores here  
using `yield` to push your testcases
### libs.py
some libs

### Details

  1. reverse the whole stripped string
     for convient add two space at beginning and end
  2. reverse every word
     maintaining current word counts and space counts, saying `wc` and `sc`
     when a word was found in range [i,j) , 
     1. locally reverse it in [i,j)
     2. move [i,j) to [i - (sc-wc), j - (sc-wc) )
     thus we can range the words from starting to end sperated by one space
     the two steps are both O(n) and it' not difficult to reduce into one step
  3. the result is in [0,wc-sc-1)
     
     
    


