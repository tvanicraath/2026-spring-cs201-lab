<!-- ---
title: CS201 Lab 2 
subtitle: Data Structures and Algorithms
author: Shreya Agarwal & Rachit Nimavat
geometry: left=4cm,right=4cm,top=2cm,bottom=2cm # Adjust the page margins in pandoc
date: Spring 2026
--- -->

In addition to the assignment shared with you on the Google Classroom, you are encouraged to perform the following.

This lab builds on problem-2 from Lab-1.
If your implementation of `IntVector` was buggy, you may start fresh by downloading a copy from the [CS201 labs Github](https://github.com/tvanicraath/2026-spring-cs201-lab).

## Today’s Linux Command: `make`
- Create your personal directory at `~/<your-name>` and a sub-directory named `lab2` inside it for today’s lab
- Up until now, you have compiled manually: `gcc hello.c -o hello`. Large software projects have hundreds of files. We automate compilation using a build system.
- Type `man make` in your terminal.


## Part 1: Build Your Own Header File

A good programming practice is to separate the Interface (what it does) from the Implementation (how it does it). 

- Create a file `vector.h` that contains the definition of the struct `IntVector` and the prototypes of the functions you implemented in Lab-1.
```C
//vector.h
#ifndef VECTOR_H // This is called an include guard to prevent double-inclusion.
#define VECTOR_H // Start of the guard

typedef struct {
    int *data;
    int size;
    int capacity;
} IntVector;

IntVector create_vector(int capacity);
void append(IntVector *v, int value);
void free_data(IntVector *v);
#endif // End of the guard
```

- Create a file `vector.c` that contains the implementations of the functions declared in `vector.h`. Include `"vector.h"` along with `<stdlib.h>` and `<stdio.h>`.
```C
//vector.c
#include<stdio.h>
#include<stdlib.h>
#include "vector.h"

IntVector create_vector(int capacity) {
    /* Your code from Lab-1 */
}

void append(IntVector *v, int value) {
    /* Your code from Lab-1 */
}

void free_data(IntVector *v) {
    /* Your code from Lab-1 */
}
```


- Now, in subsequent `.c` files, you can simply write `#include "vector.h"` (note the double quotes).

## Part 2: Makefile
- Create a file named `main.c` with a `main` function to test your `IntVector` implementation.
```C
#include <stdio.h>
#include "vector.h"
int main(){
    IntVector v = create_vector(1);
    for(int i = 0; i < 1000; i++) append(&v, i);
    free_data(&v);
    return 0;
}
```

- Compile the program using `gcc -o lab2 main.c vector.c` and run it using `./lab2` to ensure everything works.

- Create a file named `Makefile` in the same directory with the following content **(note the tab before `gcc` commands)**:
```Makefile
lab2: main.o vector.o
	gcc main.o vector.o -o lab2

vector.o: vector.c vector.h
	gcc -c vector.c

main.o: main.c vector.h
	gcc -c main.c

clean:
	rm -f *.o lab2
```

The final file structure should look like this:
```text
./lab2/
├── main.c
├── vector.c
├── vector.h
└── Makefile
```

- Now, you can simply type `make` in the terminal to compile your program. If you make changes to `vector.c` or `main.c`, just run `make` again, and it will only recompile the necessary files.
- To clean up the compiled files, type `make clean`.
- You have built your first build system!

## Part 3: New Feature
Add a new feature to your `IntVector` implementation: a function `int search(IntVector *v, int val)` to search for a value in the vector and return the index of its first occurrence. 
If the value is not found, return `-1`.
Where should you put the new prototype and implementation? 
Update these files and test the new function in `main.c` by retrieving and printing some elements.
Recompile your program using `make` and run it to ensure everything works as expected.

## Common Errors
- Forgetting to include the header file in your `.c` files.
- Copy-pasting from a browser often turns Tabs into Spaces. If `make` gives you a `missing separator` error, delete the space(s) before `gcc` and hit the `Tab` key manually.
- If you get a `linker error` or an `undefined reference`, check that you saved `vector.c`.

## Questions to Ponder Over this Week

1. Why is it important to separate the interface from the implementation in programming? Hints:
    - Think about how easy it is to teach `printf()` without knowing how it works internally.
    - Think about how closed-source libraries and APIs work.

2. Understand how the dependencies work in the Makefile. Note that a large project has $100,000s$ of lines of code spread across $100s$ of files. 

3. The `search` function returns $-1$ on an invalid index. Is this a good design choice? Can you think of a better way to handle errors in C? Hint:
    - What does `strchr()` return? Type `man strchr` if the break after CS101 was too long! :-)