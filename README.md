# pathfinder

finds all the shortest ways in a graph from one vertex to other using transpositions.
When algorithm is finished it prints all the shortest ways in the standard output.


# How to use it?

After cloning the repository use `make reinstall` command from `Makefile` to compile the project 
and get a `pathfinder` file in the same directory. 

```
~$ git clone git@github.com:serdekh/pathfinder.git
~$ cd pathfinder/
~$ make reinstall
~$ ./pathfinder [filepath]

```

Pathfinder works with a file and it must be well structured in the following way
`D` is distance between them 

```
city1-city2,D
city1-city3,D
city2-city2,D
...
cityN-cityM,D

```

There are also files `example1.txt` and `example2.txt` for you to see how it works. 
There is also a folder with test cases to handle errors and you can test them
with pathfinder, too.

