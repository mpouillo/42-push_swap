*This project has been created as a part of the 42 curriculum by mpouillo, chafonta.*

# Push_swap

### Description:

Push_swap is a group project that requires sorting data on a stack, with a limited set of instructions, using the lowest possible number of actions. This project is a great introduction to algorithmic complexity.

#### Rules

You have 2 stacks named `a` and `b`.
- At the beginning:
	- The stack `a` contains a random amount of negative and/or positive numbers without any duplicate.
	- The stack `b` is empty.
- The goal is to sort in ascending order numbers into stack `a`. To do so you have the following operations at your disposal:
	- `sa` (swap a): Swap the first two elements at the top of stack `a`. Do nothing if there is only one or no elements.
	- `sb` (swap b): Swap the first two elements at the top of stack `b`. Do nothing if there is only one or no elements.
	- `ss` : `sa` and `sb` at the same time.
	- `pa` (push a): Take the first element at the top of `b` and put it at the top of `a`. Do nothing if `b` is empty.
	- `pb` (push b): Take the first element at the top of `a` and put it at the top of `b`. Do nothing if `a` is empty.
	- `ra` (rotate a): Shift up all elements of stack `a` by one. The first element becomes the last one.
	- `rb` (rotate b): Shift up all elements of stack `b` by one. The first element becomes the last one.
	-  `rr` : `ra` and `rb` at the same time.
	- `rra` (reverse rotate a): Shift down all elements of stack `a` by one. The last element becomes the first one.
	- `rrb` (reverse rotate b): Shift down all elements of stack `b` by one. The last element becomes the first one.
	- `rrr` : `rra` and `rrb` at the same time.

Your project must comply with the following rules:
- You have to turn in a Makefile which will compile your source files. It must not
relink.
- Global variables are forbidden.
- You must write a program named `push_swap` that takes as arguments:
	- The stack a formatted as a list of integers (the first argument is the top of the
stack).
	- An optional strategy selector:
		- `--simple`: Forces the use of your O(n²) algorithm.
		- `--medium`: Forces the use of your O(n√n) algorithm.
		- `--complex`: Forces the use of your O(n log n) algorithm.
		- `--adaptive`: Forces the use of your adaptive algorithm based on disorder. This is the default behavior if no selector is given.
- The program must display the smallest list of Push_swap operations possible to sort stack `a`, the smallest number being at the top.
- Operations must be separated by a `\n` and nothing else.
- The complexity class claimed for each algorithm must be valid in this model.
- The strategy selection must work for all valid inputs. Any selector flag should work regardless of input size or disorder.
- If no parameters are specified, the program must not display anything and give the prompt back.
- In case of error, it must display "Error" followed by a `\n` on the standard error. Errors include, for example: arguments that are not integers, integers outside the valid range, or duplicate values.
- Your binary must embed all four strategies (Simple O(n2), Medium O(n√n), Complex O(n log n), and Adaptive). The selected strategy name and complexity class must be available in `--bench` mode.
- The optional benchmark mode (`--bench`) must display, after sorting:
	- The computed disorder (% with two decimals).
	- The name of the strategy used and its theoretical complexity class.
	- The total number of operations.
	- The count of each operation type (`sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`).
- The benchmark output must be sent to stderr and only appear when the flag is present.

#### Algorithms used

- `--simple`: Selection sort
	- A simple O(n²) sorting algorithm.
	- The goal is to keep looking for the smallest element in stack `a`, and push it to stack `b` until stack `a` is empty. The contents of stack `b` are then pushed back into stack `a`, resulting in a sorted state.
	- We picked this algorithm over other O(n²) sorting algorithms like bubble sort or insertion sort because it could be easily optimized by calculating the direction in which to rotate the stack, minimizing the effective number of push_swap operations.
- `--medium`: Butterfly algorithm
	- A fairly optimized O(n√n) sorting algorithm.
	- **TODO**: how it works
	- **TODO**: why we picked it
- **TODO**: complex algorithm
	- **TODO**: short description
	- **TODO**: how it works
	- **TODO**: why we picked it

#### Bonus

- Write a program named checker that takes as an argument the stack `a` formatted as a list of integers. The first argument should be at the top of the stack (be careful about the order). If no argument is given, it stops and displays nothing.
- It will then wait and read operations from the standard input, with each instruction followed by `\n`. Once all the instructions have been read, the program has to execute them on the stack received as an argument.
- If after executing those instructions, the stack a is actually sorted and the stack `b` is empty, then the program must display "OK" followed by a `\n` on the standard output.
- In every other case, it must display "KO" followed by a `\n` on the standard output.
- In case of error, you must display "Error" followed by a `\n` on the standard error. Errors include for example: some arguments are not integers, some arguments are bigger than an integer, there are duplicates, an instruction doesn’t exist and/or is incorrectly formatted.

### Instructions

Compile the program with the following command:
```shell
$> make all
```

To compile with bonuses, use:
```shell
$> make bonus
```

Run the program:
```shell
$> ./push_swap (--bench) (--simple|--medium|--complex|--adaptive) [args]
# "args" is a list of valid integers to be sorted
# given either as separate arguments or as a single string.
# By default, adaptive strategy is selected.

# Example use 1:
$> ./push_swap 2 1 3 6 5 8
# <push_swap operations>

# Example use 2:
$> ARG="4 67 3 87 23"; ./push_swap --complex $ARG
# <push_swap operations>
```

Run the checker (bonus):
```shell
$> ./checker [args]

# Example use:
$> shuf -i 0-9999 -n 500 > args.txt | ./push_swap $(cat args.txt) | ./checker $(args.txt)
# OK/KO
```

### Contribution

[<img src="https://contrib.rocks/image?repo=mpouillo/42-push_swap">](https://github.com/mpouillo/42-push_swap/graphs/contributors)

- **mpouillo**: main framework, simple algorithm (selection sort)
- **chafonta**: medium (butterfly) and complex (TODO) algorothms, checker

### Resources:

- [Project link](https://projects.intra.42.fr/projects/42next-push_swap) (requires access to the 42 intra)
- [Push swap visualizer](https://push-swap42-visualizer.vercel.app/)
- AI was used to help understand algorithming concepts, but not to generate any code.
