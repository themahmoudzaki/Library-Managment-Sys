# Library Management System

This document serves as a comprehensive guide to the Library Management System (LMS). The system is designed to efficiently manage books, members, and borrowing records, adhering to project guidelines and constraints. It is modular, scalable, and focused on functionality and usability.

---

## Table of Contents

1. [Introduction](#introduction)
2. [Memory Layout](#memory-layout)
   - [Books Data](#books-data)
   - [Members Data](#members-data)
   - [Borrowed Books Data](#borrowed-books-data)
   - [Borrowing Dates](#borrowing-dates)
   - [Data Counters](#data-counters)
3. [Functionality Overview](#functionality-overview)
   - [Core Functions](#core-functions)
   - [Command Descriptions](#command-descriptions)
4. [Getting Started](#getting-started)
   - [Data Input](#data-input)
   - [Commands](#commands)
5. [Project Guidelines](#project-guidelines)
6. [Sample Input/Output](#sample-inputoutput)
7. [Future Enhancements](#future-enhancements)

---

## Introduction

The Library Management System simulates the operations of a library, allowing users to manage books, members, and borrowing activities. It is implemented using structured programming principles to ensure clarity and maintainability. This project is designed as part of the CSE021 course requirements.

---

## Memory Layout

### Books Data
- **Description**: Tracks books by their unique IDs and available copies.
- **Structure**:
  - `books_data[MAX_BOOKS][2]`
    - Column 1: Book ID
    - Column 2: Copies Available
- **Example**:
  | **Book ID** | **Copies Available** |
  |-------------|-----------------------|
  | 101         | 3                    |
  | 102         | 5                    |

### Members Data
- **Description**: Stores library member IDs.
- **Structure**:
  - `members_id[MAX_MEMBERS]`
    - Each element: Member ID
- **Example**:
  | **Member IDs** |
  |----------------|
  | 201000, 202000 |

### Borrowed Books Data
- **Description**: Records borrowed book IDs and corresponding member IDs.
- **Structure**:
  - `borrowed_books_data[MAX_BORROWED_BOOKS][2]`
    - Column 1: Book ID
    - Column 2: Borrower ID
- **Example**:
  | **Book ID** | **Borrower ID** |
  |-------------|-----------------|
  | 101         | 201000          |

### Borrowing Dates
- **Description**: Tracks the borrowing dates for each transaction.
- **Structure**:
  - `borrowed_books_date[MAX_BORROWED_BOOKS][DATE_LENGTH]`
    - Each element: Borrowing Date ("DD/MM/YYYY")
- **Example**:
  | **Borrow Date** |
  |-----------------|
  | "12/12/2024"   |

### Data Counters
- **Description**: Summarizes key data metrics.
- **Structure**:
  - `data_count[4]`
    - Index 0: Total Distinct Books
    - Index 1: Total Book Copies
    - Index 2: Total Members
    - Index 3: Total Borrowed Books

---

## Functionality Overview

### Core Functions
1. **`get_books_data()`**
   - Collects and processes book information.
2. **`get_members_data()`**
   - Captures member IDs.
3. **`get_borrowed_data()`**
   - Records borrowed book details and dates.
4. **`get_data_handler`**
   - Calls the get_data helper function and clears the stdin stream
5. **`commands_handler()`**
   - Executes user commands based on input.

### Command Descriptions
| **Command**                | **Action**                                      |
|----------------------------|------------------------------------------------|
| `Number_Books`             | Print total books.                             |
| `Number_Members`           | Print total members.                           |
| `Book_ID_Min`              | Print minimum book ID.                         |
| `Books_Available`          | List books with available copies.              |
| `List_Book_Borrowers [ID]` | List members who borrowed a specific book.     |
| `List_Member_Books [ID]`   | List books borrowed by a specific member.      |
| `Most_Borrowed`            | Print book ID(s) with the highest borrow count.|
| `Members_Less [n]`         | List members who borrowed fewer than `n` books.|
| `Books_Unborrowed`         | List books not borrowed by anyone.             |
| `Books_Borrowed_Days`      | Calculate unique borrowing days.               |
| `Books_Per_Member`         | List members and their borrow counts.          |
| `Overlapping_Borrowers [ID]` | List members borrowing the same book on the same day. |
| `Quit`                     | End the program.                               |

---

## Getting Started

### Data Input
1. Enter book data (Book ID, Copies).
2. Enter member data (Member IDs).
3. Enter borrowed data (Book ID, Member ID, Borrow Date).
4. Commands can be entered after data input.

### Commands
- Commands are case-insensitive.
- Example: `number_books` or `Number_Books`.

---

## Project Guidelines

- **Team Requirements**:
  - Work in groups of 5-6 members.
  - Submit deliverables through the team leader.
- **Input Constraints**:
  - Max Books: 50
  - Max Members: 30
  - Max Borrowed Records: 150
- **Output Rules**:
  - Use "none" for empty results.
  - Ensure minimal extra text or whitespace in outputs.

---

## Sample Input/Output

### Example Input
```
Books:
101 5
102 3
103 7
Members:
201000
202000
Borrowed_Books:
101 201000 01/12/2024
102 202000 03/12/2024
```

### Example Output
```
Number_Books
3
Number_Members
2
Books_Available
101
102
Most_Borrowed
101
Quit
Thanks!
```

---

## Future Enhancements

1. **Dynamic Memory Allocation**:
   - Use dynamic arrays to overcome fixed-size limitations.
2. **Improved Date Handling**:
   - Leverage `<time.h>` for robust date management.
3. **Enhanced User Interface**:
   - Provide a menu-driven CLI.
4. **Advanced Reporting**:
   - Implement borrowing trends and analytics.

---

This guide outlines the design and operational details of the Library Management System, ensuring clarity and compliance with project standards.

