# AdditionWithoutArithmeticOperators
Bit arithmetic

I wanted to figure out a practice problem that was, "Add two integers together. Do not use arithmetic operators." I used bit shifting to solve
it. Not as elegant as the solution they gave, but the same concept is at work. Their solution in the book was recursive, while mine is iterative.
I wanted to see if I could take it further with averages, but I believe I would have to do some hacky float to int back to float so I could
do some bit manipulation on a float. * ( int * ) &x where x is a float. It would involve some constants to make sure there would not be a rounding
error in case of the two numbers adding to an odd number to be averaged. 

The other function just returns solves a recursive problem about
how many paths can be taken from one corner of a NxN city block to another.