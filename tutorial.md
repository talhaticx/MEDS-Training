# Bash Shell Scripting Tutorial - By Talha Ayyaz

## Table of Contents

1. [What is Bash?](#what-is-bash)
2. [Basic Script Structure](#basic-script-structure)
3. [Variables](#variables)
4. [User Input](#user-input)
5. [Conditionals (if-else)](#conditionals-if-else)
6. [Loops](#loops)
7. [Functions](#functions)
8. [Command-line Arguments](#command-line-arguments)
9. [Arrays](#arrays)
10. [Basic Commands](#basic-commands)

---

## What is Bash?

**Bash = Bourne Again Shell**  
Default shell on most Linux distros.  
Used to automate tasks via scripts.

---

## Basic Script Structure

```bash
#!/bin/bash
# This is a comment

echo "Hello, World!"
```

Make it executable:

```bash
chmod +x script.sh
./script.sh
```

or

```bash
chmod 777 script.sh
./script.sh
```

---

## Variables

```bash
name="Talha"
echo "Hello, $name"
```

Use curly braces for clarity:

```bash
echo "Hello, ${name}!"
```

---

## User Input

```bash
echo "Enter your name:"
read username
echo "Welcome, $username!"
```

---

## Conditionals (if-else)

```bash
if [ $age -ge 18 ]; then
    echo "Adult"
elif [ $age -gt 13 ]; then
    echo "Teenager"
else
    echo "Child"
fi
```

String comparison:

```bash
if [ "$name" == "Talha" ]; then
    echo "Access granted"
fi
```

---

## Loops

**For loop**:

```bash
for i in {1..5}; do
    echo "Number: $i"
done
```

**While loop**:

```bash
count=1
while [ $count -le 5 ]; do
    echo "Count: $count"
    ((count++))
done
```

---

## Functions

```bash
say_hello() {
    echo "Hello, $1!"
}

say_hello "Talha"
```

Return values:

```bash
add() {
    return $(($1 + $2))
}

add 3 5
echo $?  # Return value
```

---

## Command-line Arguments

```bash
echo "Script name: $0"
echo "First arg: $1"
echo "Total args: $#"
echo "All args: $@"
```

---

## Arrays

```bash
arr=(one two three)
echo ${arr[1]} # First element
echo ${arr[@]} # All elements
echo ${#arr[@]} # Length
```

---

## Basic Commands

```bash
pwd           # Show current directory
ls            # List files
cd dir/       # Change directory
touch file    # Create file
mkdir folder  # Create folder
rm file       # Delete file
cp src dst    # Copy file
mv src dst    # Move/rename file
cat file      # Show file contents
echo "Text" > file   # Write to file
echo "Text" >> file  # Append to file
clear         # Clear terminal
```

---
