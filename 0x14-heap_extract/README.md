# 0x14. Heap Extract

## Table of Content
* [Description](#description)
* [Learning Objectives](#learning-objectives)
* [File Description](#file-description)
* [Authors](#authors)

## Description
Technical interview questions


## Learning Objectives

- Practice algorithms.


### General

- Write a function that extracts the root node of a Max Binary Heap.


## File Description

[0-heap_extract.c](0-heap_extract.c) - Write a function that extracts the root node of a Max Binary Heap:

- Prototype: int heap_extract(heap_t **root);
- root is a double pointer to the root node of the heap
- Your function must return the value stored in the root node
- The root node must be freed and replace with the last level-order node of the heap
- Once replaced, the heap must be rebuilt if necessary
- If your function fails, return 0



## Authors
* Diego Gomez- [Linkedin](https://www.linkedin.com/in/diego-g%C3%B3mez-8861b61a1/) / [Twitter](https://twitter.com/dagomez2530)
