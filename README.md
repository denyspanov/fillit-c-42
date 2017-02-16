# fillit-c-42
The goal of this project is to arrange the Tetriminos among themselves to make the
smallest possible square, but in some cases, this square may have holes when some given
pieces won’t fit perfectly with others.
Each Tetrimino, even if presented on a 16 box grid, is only defined by its full boxes (his
’#’). The 12 remaining Tetriminos will be ignored for the arrangement of Tetriminos
among themselves.
The Tetriminos are ordered as they appear in the file. Among the different solutions
possible to make the smallest square, only the solution where Tetriminos is placed on
their most upper-left position, will be accepted/retained.
Example :
If we consider the two following Tetriminos (the ’#’ are replaced by digits for understanding
purposes) :
1... ....
1... ....
1... AND ..22
1... ..22
The smallest square formed by those 2 pieces is 4 boxes wide, but there is many
versions that you can see right below :
a) b) c) d) e) f)
122. 1.22 1... 1... 1... 1...
122. 1.22 122. 1.22 1... 1...
1... 1... 122. 1.22 122. 1.22
1... 1... 1... 1... 122. 1.22
g) h) i) j) k) l)
.122 .1.. .1.. 221. ..1. ..1.
.122 .122 .1.. 221. 221. ..1.
.1.. .122 .122 ..1. 221. 221.
.1.. .1.. .122 ..1. ..1. 221.
m) n) o) p) q) r)
22.1 .221 ...1 ...1 ...1 ...1
22.1 .221 22.1 .221 ...1 ...1
...1 ...1 22.1 .221 22.1 .221
...1 ...1 ...1 ...1 22.1 .221
According to the rule above, the right solution is then a)

Program output

Your program must display the smallest square solution on the standard output. To
identify each Tetriminos in the square solution, you will assign a capital letter (starting
with ’A’) to each Tetriminos in the order they appear in the file. A file will contain 26
Tetriminos maximum.
If the file contains at least one error, your program must display error on the standard
output and will exit properly.

Example :
$> cat sample.fillit | cat -e
....$
##..$
.#..$
.#..$
$
....$
####$
....$
....$
$
#...$
###.$
....$
....$
$
....$
##..$
.##.$
....$
$> ./fillit sample.fillit | cat -e
DDAA$
CDDA$
CCCA$
BBBB$
$>
