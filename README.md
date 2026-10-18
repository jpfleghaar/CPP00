# C++ Module 00 — Namespaces, classes, I/O streams

First steps in C++: classes, member functions, `std::string` and formatted output with iostreams.

*This project was created as part of the 42 curriculum by jpflegha.*

## Exercises

| Exercise | Program | What it does |
|:---|:---|:---|
| `ex00` | `megaphone` | Prints all arguments in uppercase. Without arguments it prints `* LOUD AND UNBEARABLE FEEDBACK NOISE *`. |
| `ex01` | `MyAwesomePhoneBook` | Interactive phone book for up to 8 contacts (`ADD`, `SEARCH`, `EXIT`). When it is full, the oldest contact is replaced. `SEARCH` shows a table with columns 10 characters wide (longer text is cut and ends with `.`), then the full contact for a chosen index. |
| `ex02` | `TheJobOfYourDreams` | Re-creates the missing `Account.cpp` from a header, a test file and a log, so that the output matches the log (static members, timestamps). |

## Key concepts

- Classes, constructors, member functions, `const` correctness
- Encapsulation with private members and getters/setters
- `std::string`, `std::getline`, `std::setw` for column formatting
- Static member variables and functions

## Build and run

Each exercise has its own Makefile (compiled with `c++ -Wall -Wextra -Werror -std=c++17`; ex02 uses `-std=c++98`).

```bash
git clone https://github.com/jpfleghaar/CPP00.git
cd CPP00/ex00 && make
./megaphone "shhhhh... I think the students are asleep..."
# SHHHHH... I THINK THE STUDENTS ARE ASLEEP...
```

```bash
cd ../ex01 && make && ./MyAwesomePhoneBook
Welcome to the Awesome Phone Book!!!
Enter ADD to add a new contact, SEARCH to look one up, or EXIT to quit.
SEARCH
     Index | First Name |  Last Name |   Nickname
         0 |        Ada |   Lovelace |        ada |
Enter index: 0
```

```bash
cd ../ex02 && make && ./TheJobOfYourDreams
```

## Project structure

```
ex00/  megaphone.cpp
ex01/  main.cpp, phoneBook.{hpp,cpp}, contact.{hpp,cpp}
ex02/  Account.{hpp,cpp}, tests.cpp, 19920104_091532.log (reference log from the subject)
```

## What I learned

- The difference between C-style code and object-oriented C++: data and behaviour belong together in a class.
- Formatting output with stream manipulators instead of `printf`.
- Reading input robustly: empty fields are not accepted and end of input (Ctrl-D) ends the program.
- Static members are shared by all objects of a class, which is useful for counters like in `Account`.
