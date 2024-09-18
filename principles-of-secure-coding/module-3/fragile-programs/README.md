# What To Do: Non-Programming Version

This version is intended for those who are not comfortable in C or C++ programming. If you are comfortable in those languages, please do the programming version (below).

Find a sequence of calls to put_on_queue and take_off_queue that demonstrate that decreasing the size field in the header structure of a queue can cause elements previously added to the queue to become invisible. What value of size did you begin with, what value did you change it to, and what was the sequence of function calls you came up with?

Next, show how to invoke the library functions to make one of the library functions crash. This can be due to an illegal memory reference or any other reason.

# What To Do: Programming Version

This is intended for those who are comfortable in C or C++ programming. If you are not comfortable in those languages, or in a language that allows you to call C functions, please do the non-programming version (above).

For this activity, you can use any programming language that can call C functions. C and C++ will be the simplest ones, but other languages often provide ways to invoke C functions.

Write a short program that uses the interface that the fragile implementation provides to write a program that creates queues, adds integers to those queues, and deletes numbers from those queues.

Then find a sequence of calls to put_on_queue and take_off_queue that demonstrate that decreasing the size field in the header structure of a queue can cause elements previously added to the queue to become invisible. What value of size did you begin with, what value did you change it to, and what was the sequence of function calls you came up with?

Next, write a second program to invoke the library functions to make one of the library functions crash. This can be due to an illegal memory reference or any other reason.

## Note 

We used C functions because it is easiest to demonstrate what should not, and should, be done using that language. Many system libraries are written in C. Other languages, such as Java and Python, have methods and other interfaces allowing programs to call C functions.

# Discussion

Fragile programming can cause problems not only in the code that is fragile but also in any code that relies on it. How do the above demonstrate this problem?

Can these problems arise when a program written in some language other than C, like Java or Python, calls a library written in C?

# Compilation commands
`gcc -o normal-implementation normal-implementation.c fqlib.c`

# Summary 
What Is Going On?

As the module you just did shows, programs that are not well written may not work as expected. This is even more insidious with libraries, where many programs may rely on the library. If the library is fragile, so are the programs they depend on.

The first part, which had you call functions in a way that makes some elements become invisible, works because initially the length of the allocated queue is in the header, in the field “size”. But that field changes, the actual space allocated for the queue does not change. So if, for example, the initial queue length is 100, then size is 100; change it to 50, and only the first 50 are now accessible.

Being able to crash the program by a sequence of calls demonstrates what can happen when fragile code is used. Crashing the program is not the worst thing that could happen, in fact; worse would be a corruption that is not detected until another point in the program. Then tracing it back to the library becomes complicated.

It doesn’t matter what language the program calling the library is written in. What matters is how thelibrary functions are called: in what sequence and with what parameters.