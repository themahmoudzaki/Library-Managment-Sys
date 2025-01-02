# Library Management System

This document serves as a comprehensive guide to understanding the functionality, memory layout, and usage of the Library Management System. The system efficiently manages books, members, and borrowing records using arrays and helper functions. It is designed with simplicity and extensibility in mind, providing a strong foundation for further development.

---

## Table of Contents

1. [Memory Layout](#memory-layout)
   - [Books Data](#1-books-data)
   - [Members Data](#2-members-data)
   - [Borrowed Books Data](#3-borrowed-books-data)
   - [Borrowing Dates](#4-borrowing-dates)
   - [Data Counters](#5-data-counters)
2. [Functionality Overview](#functionality-overview)
   - [Key Functions](#key-functions)
   - [Command Descriptions](#command-descriptions)
3. [Getting Started](#getting-started)
   - [Data Input](#data-input)
   - [Commands](#commands)
4. [Project Guidelines](#project-guidelines)
5. [Future Enhancements](#future-enhancements)

---

## Memory Layout

### 1. Books Data

The `books_data` array stores details of all books in the library, including their unique IDs and the number of available copies.

| **Book ID** | **Copies Available** |
|-------------|-----------------------|
| 101         | 3                    |
| 102         | 5                    |
| 103         | 2                    |
| 104         | 0                    |
| 105         | 0                    |
| ...         | ...                  |

- **Book ID**: A unique identifier for each book.
- **Copies Available**: Indicates the number of copies of the book currently available for borrowing. A value of `0` means no copies are available.

---

### 2. Members Data

The `members_id` array maintains a list of registered library members by their IDs.

| **Member IDs** |
|----------------|
| 201, 202, 203, 204, 205, 0, 0, ... |

- **Member ID**: A unique identifier for each member.
- Unused slots are initialized to `0`, indicating they are available for new members.

---

### 3. Borrowed Books Data

The `borrowed_books_data` array tracks books that have been borrowed and the corresponding member IDs.

| **Book ID** | **Borrower ID** |
|-------------|-----------------|
| 101         | 201             |
| 102         | 202             |
| 103         | 203             |
| 101         | 204             |
| ...         | ...             |

- **Book ID**: The ID of the borrowed book.
- **Borrower ID**: The ID of the member who borrowed the book.
- Unused rows are initialized to `0`.

---

### 4. Borrowing Dates

The `borrowed_books_date` array records the borrowing dates for each book.

| **Borrow Date** |
|-----------------|
| "12/12/2024"   |
| "13/12/2024"   |
| "14/12/2024"   |
| "12/12/2024"   |
| ...             |

- **Borrow Date**: Each entry contains the borrowing date in the format "DD/MM/YYYY".
- Unused entries are initialized with an empty string.

---

### 5. Data Counters

The `data_count` array stores summary information about the library's resources.

| **#Books** | **Total Books** | **Total Members** | **Total Borrowed Books** |
|------------|-----------------|-------------------|--------------------------|
| 50         | 150             | 30                | 200                      |

- **#Books**: The total number of distinct book titles.
- **Total Books**: The total number of all book copies.
- **Total Members**: The total number of registered members.
- **Total Borrowed Books**: The total number of books currently borrowed.

---

## Functionality Overview

### Key Functions

#### 1. `get_books_data(books_data: list, max_books: int) -> int`
- **Arguments**:
  - `books_data`: The array to store book IDs and their available copies.
  - `max_books`: The maximum number of books that can be stored.
- **Description**: 
  - Collects book IDs and the number of available copies from the user.
  - Updates the `books_data` array.
  - Returns the total number of books entered.

#### 2. `get_members_data(members_id: list, max_members: int) -> int`
- **Arguments**:
  - `members_id`: The array to store member IDs.
  - `max_members`: The maximum number of members that can be stored.
- **Description**: 
  - Collects member IDs from the user.
  - Updates the `members_id` array.
  - Returns the total number of members entered.

#### 3. `get_borrowed_data(borrowed_books_data: list, borrowed_books_date: list, max_records: int) -> int`
- **Arguments**:
  - `borrowed_books_data`: The array to store borrowed book IDs and member IDs.
  - `borrowed_books_date`: The array to store borrowing dates.
  - `max_records`: The maximum number of borrowing records.
- **Description**: 
  - Captures borrowed book details (book ID, member ID, and date).
  - Updates `borrowed_books_data` and `borrowed_books_date` arrays.
  - Returns the total number of borrowed books entered.

#### 4. `commands_handler() -> None`
- **Arguments**: None.
- **Description**: 
  - Processes user commands and invokes the appropriate functions.

---

### Command Descriptions

The following commands are supported:
1. **Number_Books**: Print the total number of books in the library.
2. **Number_Members**: Print the total number of library members.
3. **Book_ID_Min**: Print the minimum book ID.
4. **Books_Available**: List all books with at least one available copy.
5. **List_Book_Borrowers [ID]**: Given a book ID, list the IDs of members who borrowed it.
6. **List_Member_Books [ID]**: Given a member ID, list the IDs of books they borrowed.
7. **Most_Borrowed**: List the book ID(s) with the highest borrowing frequency.
8. **Members_Less [n]**: List members who borrowed fewer than `n` books.
9. **Books_Unborrowed**: List all book IDs that have not been borrowed by any member.
10. **Books_Borrowed_Days**: Calculate the total number of unique days during which books were borrowed.
11. **Books_Per_Member**: List all members along with the count of books each has borrowed.
12. **Overlapping_Borrowers [ID]**: Given a book ID, list all member IDs who borrowed the same book on the same day.
13. **Quit**: End the program.

---

## Getting Started

### Data Input
To initialize the library system:
1. Enter book IDs and their available copies.
2. Enter member IDs.
3. Enter borrowed book details, including the book ID, member ID, and borrowing date.

### Commands
Once the data is entered, interact with the system using the supported commands (listed above).

---

## Project Guidelines

### Objective
The objective is to simulate a library system where users manage books, members, and borrowing activities efficiently. The program must adhere to the following rules:

### Input Format
1. **Books**: Book ID and the total number of available copies.
2. **Members**: Member IDs.
3. **Borrowed Books**: Book ID, Member ID, and borrowing date (format: DD/MM/YYYY).

The input ends with an End-Of-File (EOF) marker.

### Constraints
1. A maximum of **50 books** and **30 members**.
2. A single member can borrow up to **5 books**.
3. Book ID length: **up to 3 characters**.
4. Member ID length: **up to 6 characters**.
5. Data should be directly read without prompts.
6. Empty outputs should print "none".

---

## Future Enhancements

1. **Dynamic Memory Allocation**:
   - Replace fixed-size arrays with dynamic memory for scalability.

2. **Data Validation**:
   - Implement stricter input validation to prevent invalid data entries.

3. **Enhanced CLI Interface**:
   - Provide a menu-driven user interface for easier interaction.

4. **Reporting Features**:
   - Add features for generating reports (e.g., borrowing trends, member activity).

5. **Date Management**:
   - Use a library like `<time.h>` for better date handling and validation.

---

This Library Management System offers a robust foundation for managing books, members, and borrowings, with ample room for further improvement and scalability.

