# Detronade Programming Language

## Introduction
Detronade is a programming language designed for parsing mathematical expressions. It is a specialized programming language designed to act as input field for GUI layout system. Although the specialized nature, this programming language has enough features that it can be extended to serve general purposes.

This document is **not a beginners tutorial to programming**. Readers are encouraged to learn programming before proceeding. Do not ask basic programming questions. This document provides information of this programming language in details, not as much as to consider it a formal specification either. It is for those who already know programming.

## Features
Below are a list of features with very brief explanation and simple example(s). The details are provided in their respective sections.
- **Mathematical Expression Parsing**: Designed for this task, it can handle and parse basic mathematical expressions.
    Example:
    ```dtn
    1 + 1 # This evaluates to 3, of course!
    ```
    The expression is evaluated using the operator's precedence.
    Use the syntax `# Comment` to insert a comment in the code.
    More about Mathematical Expression Parsing:
    ```dtn
    3 + 4 * 5 + (6 + 7) * (8 - (9 + 10)) # Parenthesis
    ```
    ```dtn
    sqrt(11) + log(12, 2) # Functions
    ```
    Note: All the numerical literals are of type `real`, and assigning to variable of type `int` will implicitly convert it.
- **Variables and Constants**: Since it is a multi-statement language, meaning it can execute statements line-by-line, which allows sequential execution. What's the one thing that makes sequential execution a billion times useful? Variables.
    Example:
    ```dtn
    real x = 3 # real is for real numbers, aka float
    const int y = x + 2 # y is now 5
    x + y # Results in 8
    ```
    Note: Uncaptured expression causes it to exit scope, or if it is in global scope, causes it to end the program with a result.
- **Basic Operations**: Including addition, subtraction and multiplication that you just saw, there is also:
    - Division (`/`): Does division
    ```dtn
    7 / 2 # Results in 3.5
    ```
    Note: Even when using `int` variables for division, it will convert it to `real` when performing the division.
    Oh and, `1 / 0` is infinity and `-1 / 0` is negative infinity. Casting this to `int` will result in the largest number in either ends.
    - Exponentiation (`**`): Raise the first number to the power of the second number.
    ```dtn
    3 ** 2 # Results in 9
    ```
    - Flooring Division (`//`): Flooring division divides the number but also does flooring.
    ```dtn
    7 // 2 # Result is 3
    ```
- **Basic Types**: Along with `real` and `int`, there is
    - `bool`: Stores either `true` or `false`.
    ```dtn
    bool is_division_by_zero = false
    ```
    - `char`: Stores a single character enclosed in two single quotes (`'`).
    ```dtn
    char convert_to_number = '2'
    ```
    - Strings: If there is `char`, there is `string`? No. It is a character array (`char[]`)
    ```dtn
    char[] string = "21455"
    ```
    Note: Implicit conversion is supported, and conversion from `real` to `int`, `bool` or `char` will perform flooring.
- **Simple Control Flow**:
    - `if` statements:
    ```dtn
    if (b != 0)
        c = a / b
    ```
    - `else` statement:
    ```dtn
    if (a > 0)
        c = a - b
    else
        c = b - a
    ```
    - laddered:
    ```dtn
    if (d == 0)
        c = 0
    else if (d > 0)
        c = sqrt(d)
    else
        c = d * d
    ```
    - `while` statement:
    ```dtn
    while (a > 0)
        b = a * a
        a--
    ```
    - `for` statement:
    ```dtn
    for (int i = 0; i < 10; i++)
        j = i * i + 2 * i + 3
    ```
- **Functions**: If we have control flow, we do want to control them, we want to keep things modular and reuse them for different inputs. Right? Here comes Functions.
    Defining a function:
    ```dtn
    int add(int a, int b)
        a + b # Uncaptured expression returns from function
    ```
    Using the function:
    ```dtn
    int result = add(2, 4)
    ```
    The function can be defined in single line as well
    ```dtn
    int sub(int a, int b) a - b
    ```
- **Arrays**: An array is a collec- you know it already, right? But here's what you are required to guess but don't need to, syntax:
    ```dtn
    int[5] array # 5 Elements
    array[0] = 4 # 0-indexed

    int[] auto_sized_array = [1, 2, 3, 4, 5] # Initialize values and automatically determine the size of array
    ```
    They are not fixed size, so they have some member functions for manipulation:
    ```dtn
    int size = array.count() # Get the number of elements
    int inserted = array.insert(index, element) # Insert an element at the index, it returns the inserted element
    int removed = array.remove(index) # Remove an element from the index, it returns the removed element
    ```
- **Structures**: A structure is a collection of variables and function to form a user-defined data type.
    Defining a structure:
    ```dtn
    struct vec2 # Vector 2
        real x # Data
        real y

        # Method
        real magnitude() sqrt(x * x + y * y)

        vec2 rotated(real angle)
            # Note: allowed to split it only if it is a list `(...)` or `[...]`
            vec2(x * cos(angle) - y * sin(angle),
                 x * sin(angle) + y * cos(angle))
    ```
    For initializing,
    ```dtn
    vec2 position = vec2(1, 5) # Default constructor requires either zero parameters or all the parameters in the struct
    position.x += 2 # position.x is now 3
    position.y -= 1 # position.y is now 4
    real distance_from_center = position.magnitude() # 5
    ```
    Constructors? Yes, with destructors
    ```dtn
    struct vec2
        real x, y

        # The below two constructors are default generated if you don't specify them
        construct()
            void # This will cause the function (constructor) to be left empty

        construct(real _x, real _y)
            x = _x
            y = _y

        # This is a custom constructor
        construct(real z)
            x = z
            y = z

        destruct()
            void
    ```
- **Operator Overloading**: A super simple syntax for operator overloading:
    ```dtn
    # Operator overloading must always be outside struct
    real operator(vec2 a + vec2 b) vec2(a.x + b.x, a.y + b.y)

    # Just gonna add another one
    real operator(vec2 a - vec2 b) vec2(a.x - b.x, a.y - b.y)

    vec2 a = vec2(3, 5)
    vec2 b = vec2(1, 7)
    vec2 c = a + b # c is now vec2(4, 12)
    ```
    Oh and, with this, you can invent your own operator! Just make sure that your operator uses only of these characters: `~`, `!`, `%`, `^`, `&`, `*`, `-`, `+`, `=`, `[`, `]`, `\`, `|`, `:`, `/`, `?`.
    ```dtn
    real operator(^-^vec2 v) return v.magnitude()

    vec2 velocity = vec2(20, 21)
    real speed = ^-^velocity # 29
    ```
    Note that custom operators do not have defined precedence. It will always be evaluated after regular operators. And, when using two custom operators in the expression, it prioritize the one which was processed earlier.
    ```dtn
    # Projection operation
    vec2 operator(vec2 a |/ vec2 b) some_function_that_projects_vectors(a, b)

    vec2 operator(vec2 v /* real a) some_function_to_rotate_vector(v, a)

    vec2 a = vec2(2, 4)
    vec2 b = vec2(3, 0)

    # Evaluates 90 / 360 * pi first
    # Then evaluates a |/ b to project a to b
    # Then evaluates /* to rotate the vector
    vec2 result = a |/ b /* 90 * pi / 360 # The result is vec2(0, 2) (hopefully)
    ```
    The flexibility does not end there, you can also have multiple operators, but let's get a real example this time:
    ```dtn
    struct int_arr
        int[] array

        construct(int count)
            array = int[5]()

        void count() array.count()

        void insert(int index, int element) array.insert(index, element)

        void remove(int index) array.remove(index)

    # Subscript operator
    int operator(int_arr array [ int index ]) array.array[index]
    ```
    Usage:
    ```
    int_arr array = int_arr()
    int length = array.count()
    array[length - 1]
    ```

## Usage
...

