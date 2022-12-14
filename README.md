# holbertonschool-monty
C - Stacks, Queues - LIFO, FIFO
Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

Monty byte code files

Files containing Monty byte codes usually have the .m extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument:
## MONTY DESCRIPTION :
The monty mirroring the real monty in a simple version of himself.

## PROTOTYPES :
`int main(int argc, char **argv);`  
`instruction_t *get_function(char *line);`  
`void _push(stack_t **stack, unsigned int line_number);`  
`void _pall(stack_t **stack, unsigned int line_number);`  
`void _pint(stack_t **stack, unsigned int line_number);`  
`void _pop(stack_t **stack, unsigned int line_number);`  
`void _swap(stack_t **stack, unsigned int line_number);`  
`void _add(stack_t **stack, unsigned int line_number);`  
`void _nop(stack_t **stack, unsigned int line_number);`  

## COMPILATION :
You need to type `$ gcc -Wall -Werror -Wextra -pedantic *.c -o "NameOfTheScriptFile"` to compile your code to an executable file.

## EXECUTION :
You need to type `./NameOfTheScriptFile ./NameOfTheFile` to execute your file.

## COMMAND LINE - .m :

| CL           | Descriptions                                                                |
| ------------------------- | ------------------------------------------------------------------ |
| `push `  | The opcode push pushes an element to the stack.
| `pall` | The opcode pall prints all the values on the stack, starting from the top of the stack.
| `pint` | The opcode pint prints the value at the top of the stack, followed by a new line.
| `pop` | The opcode pop removes the top element of the stack.
| `swap` | The opcode swap swaps the top two elements of the stack.
| `add` | The opcode add adds the top two elements of the stack.
| `nop` | The opcode nop doesn’t do anything.

## FILES & DIRECTORIES DESCRIPTIONS :

| Files Names             | Descriptions                                                                |
| ----------------- | ------------------------------------------------------------------ |
| README.md | Contains all the informations of the Simple Shell project |
| monty.h | Contains the libraries, struct and the prototypes of our functions |
| main.c | Main Function and the get_function |
| 0-opcodes.c | Contains scripts of the opcode push and pall |
| 1-opcodes.c | Contains scripts of the opcode pint |
| 2-opcodes.c | Contains scripts of the opcode pop |
| 3-opcodes.c | Contains scripts of the opcode swap |
| 4-opcodes.c | Contains scripts of the opcode add |
| 5-opcodes.c | Contains scripts of the opcode nop |


| Directories Names             | Descriptions
| ----------------- | ------------------------------------------------------------------ |
| bytecodes | Contains all the test files to understand how monty work

## EXAMPLE OF USING THE MONTY SCRIPT :

If you use the `monty` script with `bytecodes/09.m` test :

```
julien@ubuntu:~/holberton-monty$ cat bytecodes/09.m 
push 1
push 2
push 3
pall
swap
pall
julien@ubuntu:~/holberton-monty$ ./monty bytecodes/09.m 
3
2
1
2
3
1
julien@ubuntu:~/holberton-monty$
```


## ORGANISATION TOOLS :

| Tools             | Tools Links                                                                |
| ----------------- | ------------------------------------------------------------------ |
| Trello | [![Trello](https://img.shields.io/badge/Trello-%23026AA7.svg?style=for-the-badge&logo=Trello&logoColor=white)](https://trello.com/b/9Knotcwi/shell) |

### AUTHORS :

| Authors Names             | Linkedin Links                                                                |
| ----------------- | ------------------------------------------------------------------ |
| 👩 Vanessa TESSIER | [![linkedin](https://img.shields.io/badge/linkedin-white?style=for-the-badge&logo=linkedin&logoColor=black)](https://www.linkedin.com/in/vanessa-tessier-601794252/) |
| 👦 Kyllian TERRASSON | [![linkedin](https://img.shields.io/badge/linkedin-white?style=for-the-badge&logo=linkedin&logoColor=black)](https://www.linkedin.com/in/redginald-godeau-04ab8a254/)


### SCHOOL :

Holberton School - TOULOUSE
C19 Cohort
Dec. 2022