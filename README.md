# pipex
42 School - Level02

A program to mimic the behaviour of piping in shells

## Usage

`make` compiles the program.

The first argument is the input file and the last argument is the output file. There has to be at least one command in between.
```
$ ./pipex <input.file> <cmd1> <...> <output.file>
```

It behaves like
```
$ < <input.file> <cmd1> <| <...>> < <output.file>
```
