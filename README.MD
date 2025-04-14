# Data structures in C

A simple implementation of data structures in C

This project exists because reading about manual 
memory management is cute—but writing code that 
doesn't segfault is where the real learning happens.

## Why?

Because malloc won't teach itself. I'm training 
my C skills by manually managing memory—no garbage 
collectors, no abstractions, just pointers and pain.

## Implemented:

### Linked List

#### Build

```
gcc main.c linkedlist.c -o linkedlist
```

Assuming you have:

- `linkedlist.h` - the header

- `linkedlist.c` - the implementation

- `main.c` - where you test this beast

### Hash Map

#### Build

```
gcc main.c hashmap.c -o hashmap
```

That means you should have:

- `hashmap.h` - the header

- `hashmap.c` - the implementation

- `main.c` - test of this monster

## License

MIT, probably. Use it, break it, improve it.
