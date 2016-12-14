# AdditionWithoutArithmeticOperators
Bit arithmetic

I wanted to figure out a practice problem that was, "Add two integers together. Do not use arithmetic operators." I used bit shifting to solve
it. Not as elegant as the solution they gave, but the same concept is at work. Their solution in the book was recursive, while mine is iterative.

I wanted to see if I could take it further with averages, so I did some hacky float to int back to float so I could
do some bit manipulation on a float. * ( int * ) &x where x is a float. It involves a decrement, so next thing I'll implement is a function for subtraction. 

The reason for the decrement is because bits 23-31 of a float are used for the exponent of the float. If you decrement the exponent of the float, it is essentially the same as dividing by 2, which is what was needed to average the 2 numbers whose sum is odd.

The error in case of the two numbers adding to an odd number to be averaged is solved using this method. 

The other function just returns solves a recursive problem about
how many paths can be taken from one corner of a NxN city block to another.
