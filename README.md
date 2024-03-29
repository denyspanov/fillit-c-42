# fillit - dpanov (Denys Panov)
Can you feel it?

After finishing [libft](https://github.com/denyspanov/libft-c-42), fillit is the
second mandatory project before [get_next_line](https://github.com/denyspanov/get_next_line-c-42),
and after that, you branch out. The purpose is to make the
smallest possible "square" (which can contain holes) with a given list of
tetriminos, but the disposition must be as such that it returns the first
possible solution when placing them recursively from the top left.

## Compiling
Run `make`, an executable called `fillit` should compile directly. Please submit
an issue if you run into any.

## Usage
`./fillit [file]`

Example:
```
~ ./fillit samples/test_8

.AABB..
AACCB..
.CC.BDD
.EE.DD.
EEFFGG.
.FFGGHH
....HH.
```
