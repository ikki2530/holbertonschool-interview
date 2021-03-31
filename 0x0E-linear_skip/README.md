0x0E. Linear search in skip list

## Table of Content
* [Description](#description)
* [Learning Objectives](#learning-objectives)
* [File Description](#file-description)
* [Authors](#authors)

## Description
Technical interview questions


## Learning Objectives
### General

- Practice algorithms and data sctructures


## File Description

[0-linear_skip.c](0-linear_skip.c) - function that searches for a value in a sorted skip list of integers

- Prototype : skiplist_t *linear_skip(skiplist_t *list, int value);
- Where list is a pointer to the head of the skip list to search in
- A node of the express lane is placed every index which is a multiple of the square root of the size of the list (see example below)
- And value is the value to search for
- You can assume that list will be sorted in ascending order
- Your function must return a pointer on the first node where value is located
- If value is not present in list or if head is NULL, your function must return NULL
- Every time you compare a value in the list to the value you are searching, you have to print this value (see example below)


## Authors
* Diego Gomez- [Linkedin](https://www.linkedin.com/in/diego-g%C3%B3mez-8861b61a1/) / [Twitter](https://twitter.com/dagomez2530)
