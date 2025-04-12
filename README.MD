# Linked List in C

A simple implementation of a singly linked list in C.

This project exists because reading about manual memory management is cute—but writing code that doesn't segfault is where the real learning happens.

## Why?

Because malloc won't teach itself. I'm training my C skills by manually managing memory—no garbage collectors, no abstractions, just pointers and pain.

## Features

- Create nodes dynamically
- Push values to the front or back of the list
- Find nodes by value
- Remove nodes cleanly (leak-free or bust)
- Count nodes
- Print the list
- Free all nodes

## Build

```
gcc main.c linked_list.c -o linked_list
```

Assuming you have:

- `linked_list.h` - the header

- `linked_list.c` - the implementation

- `main.c` - where you test this beast

## License

MIT, probably. Use it, break it, improve it.
