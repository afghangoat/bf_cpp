#Brainfuck interpreter in C++

##Mechanics
It abuses operator overloading. Creating a class instance named "_" will allow you to make instructions like this:

`_*0x68; +_; ~_; _>0;`

##Usage

Run:
`g++ brainfuck_interpreter.cpp -o brainfuck_interpreter`
`./brainfuck_interpreter`