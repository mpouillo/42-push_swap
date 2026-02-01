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
**Reminder:** `n` is referring to the number of items that are given to sort.
- `--simple`: Selection sort
	- A simple O(n²) sorting algorithm.
	- The goal is to keep looking for the smallest element in stack `a`, and push it to stack `b` until stack `a` is empty. The contents of stack `b` are then pushed back into stack `a`, resulting in a sorted state.
	- Optimizations were made by finding the shortest path to the smallest element (i.e., picking whether to rotate with `ra` or `rra`) and checking if the stack is sorted at every step.
	- We picked this algorithm over other O(n²) sorting algorithms like bubble sort or insertion sort because it showed the best results after optimizations, getting about half and a quarter of the operations of insertion and bubble sort respectively.
- `--medium`: Butterfly algorithm
	- A greatly optimized O(n√n) sorting algorithm.
	- How it works:
		1. <u>Pushing to `b`:</u>
		Sorts the `a` stack into an array. Then goes through stack `a` and searches for items that are within the first `√n + i` elements of the sorted stack, `i` being an index starting at 0. If so, pushes them to `b` and increments `i` by one. Repeats until `a` is empty. If an item is only within the `i` range, it rotates `b` after pushing it. This condition makes the `b` stack looking like an "hourglass", or, a **"butterfly"**. The butterfly shape is very useful as the biggest values, rather than all sitting at the top in a triangle shape, are now sitting at both extremities of the `b` stack, making pushing them back to `a` much more efficient.
		2. <u>Pushing back to `a`:</u>
		Now that the `a` stack is empty and that the `b` stack looks like a pretty **butterfly**, the algorithm simply searches for the biggest item of `b`; if it is near the top, rotates until it's the `head` and then pushes it to `a`, if it's near the bottom, revers rotates until it's the `head`, and then pushes it `b`: `a` is then sorted!
	- We picked this algorithm as looking for solutions, we understood that a "range-based" algorithm was the overall dominating strategy for a `√n` complexity. The only real choice was how do we implement it, and this is the way that worked and made the most sense for us.
- `--complex`: Radix sort
	- An optimized O(nlogn) sorting algorithm.
	- Radix sort operates by comparing each digit of numbers one by one and assigning the numbers to groups based on their digit, by each iterations, the digits within the groups are sorted by their previous digits. Once the final digit is reached, everything is in order. It is not the smartest, as it will always take the same number of operations whether the stack is roughly ordered or not, but it's advantage is that it thrives in sorting large quantities, being our most optimized algorithm around 1000 items.
	- As we only have two stacks to compare ten digits, the implementation of the radix logic to push_swap pretty much begged us to use base two _(aka binary)_, this was possible by using two of the bitwise operators available in C: **`>>` (right shift)** and **`&` (bitwise AND)**.
		- `x >> i`:
		Shifts the integer `x` from `i` bits to the right, i.e converts an integer into binary and literally removes the first n digits of the number, starting from the right; e.g.
		```
		for x = 25, i = 2,
			25 (base 10) = 11001 (base 2)
			11001 >> 2 = 110

		-> 25 >> 2 = 110
		```
		- `x & (0/1)`: Simply the logic comparator `AND`, using the last bit of an integer; e.g.
		```
		0 & 0 = 0		10 & 0 = 0
		1 & 0 = 0		11 & 0 = 0
		0 & 1 = 0		10 & 1 = 0 
		1 & 1 = 1		11 & 1 = 1
		
		(note that everything is in base 2 in this exemple)
		```
		Our usage:
		```
		1001 & 1 = 1	-> rotate a
		1010 & 1 = 0	-> push to b
		
		(note that everything is in base 2 in this exemple)
		```
		To achieve this, we used both of these operators in the same condition, here is what would be the simplified logic of the algorithm:
		```c
		int	i;
		int	j;

		i = 0;
		while (i < bits_of_max)	// number of bits of the biggest item to sort
		{
			j = 0;
			while (j < length_a)	// goes through all the items of stack a
			{
				if ((stack_a->head >> i) & 1)	// looks whether the i-th bit is 1 or 0
					ra;	// keeps the 1s in a
				else
					pb;	// pushes the 0s to b
				j++:	// goes to next item
			}
			push_b_back_to_a;	// every item was compared, put b back on top of a
			i++;	// goes to the next bit of the items
		}
		```
	- We initially aimed to go for a "quick sort" algorithm, sadly we did NOT understand how to implement it to the push_swap problem. We heard about the radix solution by our peers, and after researches, while the bitwise operators were intimidating and new concepts for us, we were too deep to step back, so we embraced the radix logic and found great ways to implement it to our project and even to optimize it.

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

- **mpouillo**:
	- main framework: main, parsing, basic program behavior, makefile, header files, bench mode, etc.
	- simple algorithms: selection sort, insertion sort, bubble sort
- **chafonta**:
	- disorder computing function
	- medium algorithm: butterfly sort
	- complex algorithm: radix sort
	- checker

### Resources:

- [Project link](https://projects.intra.42.fr/projects/42next-push_swap) (requires access to the 42 intra)
- [Push swap visualizer](https://push-swap42-visualizer.vercel.app/)
- [Push_Swap Tutorial](https://medium.com/nerd-for-tech/push-swap-tutorial-fa746e6aba1e)
- AI was used to help understand algorithming concepts, but not to generate any code.
