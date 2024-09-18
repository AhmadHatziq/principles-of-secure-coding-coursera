What To Do: Non-Programming Version

This is intended for those who are not comfortable in C or C++ programming. If you are comfortable in those languages, please do the programming version (below).

Suppose we change the create_queue function in the robust version of the queue library to allocate space for each queue dynamically; that is, so que in the struct queue is allocated dynamically and is not an array. The caller would pass an integer as the single argument for that function indicating the maximum size of that queue.

Next, let’s assume we do the same thing for the array of queues, queues. When more queues are needed, dynamically reallocate this space to obtain the extra room. This should be done automatically, when create_queue finds the array to be full (see the first for loop in that function).

What would be the benefit of doing this — specifically, what could I do with this modified library that I could not do with the fixed-size library? When would using this version avoid a failure of the version with fixed size allocations? What would we have to change in the design of the other functions, if anything, for this to work?

What To Do: Programming Version

This is intended for those who are comfortable in C or C++ programming. If you are not comfortable in those languages, or in a language that allows you to call C functions, please do the non-programming version (above).

For this activity, you can use any programming language that can call C functions. C and C++ will be the simplest ones, but other languages often provide ways to invoke C functions.

Change the create_queue function in the robust version of the queue library to allocate space for each queue dynamically; that is, so que in the struct queue is allocated dynamically and is not an array. The caller should pass an integer as the single argument for that function indicating the maximum size of that queue. Don’t forget to check that the parameter is positive!

Next, do the same for the array of queues, queues. When more queues are needed, dynamically reallocate this space to obtain the extra room. This should be done automatically, when create_queue finds the array to be full (see the first for loop in that function).

Discussion

This module presented a “robust” version of the queue library. But robustness is a question of degree; some code is more robust than others. Given the definition of “robust code” we have been using, is the dynamic version discussed in this scheduled activity more robust than the version that uses fixed limits?

When you modify robust code, you have to understand how the code works, including the parts you are not modifying. Why?