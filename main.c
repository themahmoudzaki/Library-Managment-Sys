/* Libraries */
/*
    Functions used from stdio.h:
    - printf
    - scanf
    - fgets
    - strcspn
    - clearerr
*/
#include <stdio.h>
/*
    Functions used from stdlib.h:
    - atoi
*/
#include <stdlib.h>
/*
    Functions used from string.h:
    - strcmp
*/
#include <string.h>
/*
    Functions used from ctype.h:
    - tolower
    - isspace
*/
#include <ctype.h>

/*
    The commented out printf's where used to test and debug the code,
    However have been commented out per the project guidelines
*/

/* ---------------------------- DATA SECTION ---------------------------- */

// General constraints
// Set by the project guidline
#define MAX_BOOKS 50
#define MAX_MEMBERS 30
#define MAX_BORROWED_BOOKS MAX_MEMBERS * 5
#define DATE_LENGTH 11 // 10 characters for date (DD/MM/YYYY) + null-terminator ( \0 )

/* ---------------------------------------------------------------------- */


/* ---------------------------- HELPER FUNCTIONS SECTION ---------------------------- */
/*
    This section contains the "helper" functions that will be called by the handlers to perform
    a specified task
*/
/*
    This allows us to break down the code into "pieces" that function independantly from each
    other allowing for easy debugging and easy project managment
*/

/*
    This is the start of the helper functions of the get_data_handler() they return 3 values and modify the pointing address of
    one variable
*/
int get_books_data(int books_data[MAX_BOOKS][2], int *books_count)
{
    int counter = 0;
    int total_books = 0; // We will return this as it will contain the total number of books

    printf("Enter Book's ID & the Number of Copies: \n");
    while (counter < MAX_BOOKS)
    {
        if ( scanf("%d %d", &books_data[counter][0], &books_data[counter][1]) == EOF ) break;
        total_books += books_data[counter][1]; // Total number of books
        counter++; // Count of books
    }

    /*
        Modifies books_count to contain the number of books
    */
    *books_count = counter;

    return total_books;
};

int get_members_data(int member_id[MAX_MEMBERS])
{
    int counter = 0; // We will return this as it will contain the total number of members

    printf("Enter member's ID: \n");
    while (counter < MAX_MEMBERS)
    {
        if ( scanf("%d", &member_id[counter]) == EOF ) break;
        counter++; // count of members
    }

    return counter;
};

int get_borrowed_data(int borrowed_books_data[MAX_BORROWED_BOOKS][2], char borrowed_books_date[MAX_BORROWED_BOOKS][DATE_LENGTH])
{
    int counter = 0;

    printf("Enter borrowed Book's ID & borrower's ID & borrow date (DD/MM/YYYY): \n");
    while (counter < MAX_BORROWED_BOOKS)
    {
        if ( scanf("%d %d %s", &borrowed_books_data[counter][0], &borrowed_books_data[counter][1], borrowed_books_date[counter]) == EOF ) break;
        counter++; // Borrow counter
    };

    return counter;
};

/*
    Starting from here is the helper functions of the command_handler()
    These functions dont return anything they just output the required
    data and return
*/
void number_books(int data_count_1)
{
    if (data_count_1 == 0){ printf("None\n"); }

    else { printf("%d\n", data_count_1); }
    return;
};

void number_members(int data_count_2)
{
    if ( data_count_2 == 0 ){ printf("None\n"); }

    else { printf("%d\n", data_count_2); }
    return;
};

void book_id_min(int books_data[MAX_BOOKS][2], int data_count_0)
{
    int min_book_id = books_data[0][0]; // set the min_id to the first book_id

    for ( int i = 1; i < data_count_0; i++ ) // i = 1 to skip the first book_id of index 0
    {
        if ( min_book_id > books_data[i][0] ) { min_book_id = books_data[i][0]; }
    };
    // printf("Min Book ID: %d\n", min_book_id);
    printf("%d\n", min_book_id);
};

void books_available(int books_data[MAX_BOOKS][2], int borrowed_books_data[MAX_BORROWED_BOOKS][2], int data_count_0, int data_count_3)
{
    int books_available; // Will store the number of copies of a certain book
    int availability_bool = 1; // Will store 0 if the are available books and 1 if there is no available books

    // printf("Available books: \n");
    for ( int i = 0; i < data_count_0; i++ )
    {
        books_available = books_data[i][1]; // stores the intial number of copies
        for ( int j = 0; j < data_count_3; j++ )
        {
            if ( books_data[i][0] == borrowed_books_data[j][0] ) { books_available--; }; // decrement the copies number with each time a member borrowed that book
        };

        if ( books_available != 0 )
        {
            printf("%d\n", books_data[i][0]);
            availability_bool = 0;
        };
    };
    if ( availability_bool == 1 ){ printf("None\n"); };
};

void list_book_borrowers(int command_argument, int borrowed_books_data[MAX_BORROWED_BOOKS][2], int data_count_3)
{
    int book_borrowers[data_count_3];
    int counter = 0;

    // printf("Book ID: %d Borrowers: \n", command_argument);

    for ( int i = 0; i < data_count_3; i++ )
    {
        if ( command_argument == borrowed_books_data[i][0] )
        {
            book_borrowers[counter] = borrowed_books_data[i][1];
            counter++;
        };
    };

    if ( counter == 0 )
    {
        printf("None\n");
        return;
    };

    for ( int i = 0; i < counter; i++ )
    {
        printf("%d\n", book_borrowers[i]);
    };

};

void list_member_books(int command_argument, int borrowed_books_data[MAX_BORROWED_BOOKS][2], int data_count_3)
{
    int borrowed_counter = 0;

    // printf("Member ID: %d Books Borrowed: \n", command_argument);
    for ( int i = 0; i < data_count_3; i++ )
    {
        if ( borrowed_books_data[i][1] == command_argument )
        {
            printf("%d\n", borrowed_books_data[i][0]);
            borrowed_counter++;
        };
    };
    if ( borrowed_counter == 0 ) { printf("None\n"); };
};

void most_borrowed(int books_data[MAX_BOOKS][2], int borrowed_books_data[MAX_BORROWED_BOOKS][2], int data_count_0, int data_count_3)
{
    if ( data_count_3 == 0) { printf("None\n"); return; };

    int counter[data_count_0];
    int most_borrowed_index;

    for ( int i = 0; i < data_count_0; i++ )
    {
        counter[i] = 0;
        for ( int j = 0; j <= data_count_3; j++ )
        {
            if ( books_data[i][0] == borrowed_books_data[j][0] )
            {
                counter[i]++;
            };
        };

        if ( i != 0 && counter[i] > counter[i - 1] ){ most_borrowed_index = i; };
    }
    // printf("Most borrowed Book ID: %d Borrow Amount: %d\n", books_data[most_borrowed_index][0], counter[most_borrowed_index]);
    printf("%d\n", books_data[most_borrowed_index][0]);

};

void members_less(int command_argument, int members_id[MAX_MEMBERS], int borrowed_books_data[MAX_BORROWED_BOOKS][2], int data_count_2, int data_count_3)
{
    int borrow_counter = 0;

    // printf("Members who borrowed less than %d book(s): \n", command_argument);
    for ( int i = 0; i < data_count_2; i++ )
    {
        for ( int j = 0; j < data_count_3; j++ )
        {
            if ( members_id[i] == borrowed_books_data[j][1] ) { borrow_counter++; };
        };

        if ( borrow_counter < command_argument  ) { printf("%d\n", members_id[i]); }
        borrow_counter = 0;
    };
};

void books_unborrowed(int books_data[MAX_BOOKS][2], int borrowed_books_data[MAX_BORROWED_BOOKS][2], int data_count_0, int data_count_3)
{
    int borrowed_flag = 1; //  1 = unborrowed, 0 = borrowed
    int counter_of_borrow = 0;

    // printf("Unborrowed books ID: \n");
    for ( int i = 0; i < data_count_0; i++ )
    {
        for ( int j = 0; j < data_count_3; j++ )
        {
            if ( books_data[i][0] == borrowed_books_data[j][0] )
            {
                borrowed_flag = 0;
                counter_of_borrow++;
            };
        };

        if ( borrowed_flag == 1 ) { printf("%d\n", books_data[i][0]); };
        borrowed_flag = 1;
    };

    if ( counter_of_borrow == 0 ){ printf("None\n"); };
};

void books_borrowed_days(char borrowed_books_date[MAX_BORROWED_BOOKS][DATE_LENGTH], int data_count_3)
{
    int unique_days[2];
    int uniqueness_check = 0; // 1 = not unique, 0 = unique
    int uniqueness_counter = 0;

    // printf("Number of unique days: \n");
    for ( int i = 0; i < data_count_3; i++ )
    {
        unique_days[0] = borrowed_books_date[i][0];
        unique_days[1] = borrowed_books_date[i][1];
        for ( int j = 0; j < data_count_3; j++ )
        {
            if ( j != i )
            {
                if
                (
                    unique_days[0] == borrowed_books_date[j][0] &&
                    unique_days[1] == borrowed_books_date[j][1]
                )
                { uniqueness_check = 1; };
            }
        };
        if ( uniqueness_check == 0 ) { uniqueness_counter++; }
        uniqueness_check == 0;
    }
    printf("%d\n", uniqueness_counter);

};

void books_per_member(int members_id[MAX_MEMBERS], int borrowed_books_data[MAX_BORROWED_BOOKS][2], int data_count_2, int data_count_3)
{
    int counter = 0;

    for ( int i = 0; i < data_count_2; i++ )
    {
        for ( int j = 0; j < data_count_3; j++ ) { if ( members_id[i] == borrowed_books_data[j][1] ) { counter++; } };
        if ( counter == 0 )
        {
            // printf("Member: %d Borrow Amound: None\n", members_id[i]);
            printf("%d None\n", members_id[i]);
        } else
        {
            // printf("Member: %d Borrow Amount: %d\n", members_id[i], counter);
            printf("%d %d\n", members_id[i], counter);
        }


        counter = 0;
    }
};

void overlapping_borrowers(int command_argument, int borrowed_books_data[MAX_BORROWED_BOOKS][2], char borrowed_books_date[MAX_BORROWED_BOOKS][DATE_LENGTH], int data_count_3) {
    int counter = 0;  // Count overlapping borrowers
    // printf("Overlapping borrowers ID: \n");
    for ( int i = 0; i < data_count_3; i++ )
    {
        // Check if the book was borrowed by the given borrower ID
        if ( command_argument == borrowed_books_data[i][0] )
        {
            for ( int j = 0; j < data_count_3; j++ )
            {
                // Avoid self-comparison
                if ( j != i )
                {
                    if ( command_argument == borrowed_books_data[j][0] )
                    {
                        // Compare dates
                        if (
                                borrowed_books_date[i][0] == borrowed_books_date[j][0] &&
                                borrowed_books_date[i][1] == borrowed_books_date[j][1]
                            )
                        {
                            // Print overlapping borrower ID
                            printf("%d\n", borrowed_books_data[j][1]);
                            counter++;
                        }
                    }
                }
            }
        }
    }

    // If no overlapping borrowers were found
    if ( counter == 0 ) {
        printf("None\n");
    }

}


/* ---------------------------------------------------------------------------------- */


/* ---------------------------- HANDLER's SECTION ---------------------------- */
/*
    This section contains handlers that manage a section of the code (e.g., Inputs/Outputs)
    and decide which helper function to call
*/

/*
    Prerequisite:
    - All the data in the argument data_count[] are set to zero.

    Param:
    - int book_data[][] : to store book ID & number of copies
    - int members_id[]: to store member IDs
    - int borrowed_books_data[][]: to store borrowed book ID & borrower member ID
    - char borrowed_books_date[][]: to store the borrowed date
    - int data_count[3]: to store the outputs of the helper functions

    Outputs of the handler:
    - data_count[0] = total count of books
    - data_count[1] = total count of members
    - data_count[2] = total count of borrowed books
*/
int get_data_handler(int books_data[MAX_BOOKS][2], int members_id[MAX_MEMBERS], int borrowed_books_data[MAX_BORROWED_BOOKS][2], char borrowed_books_date[MAX_BORROWED_BOOKS][DATE_LENGTH], int data_count[4])
{
    // printf("\n--------------------------------------- Enter some data to get started ---------------------------------------\n");

    int books_count; /* Modified in the get_books_data function to store the count of books */
    data_count[1] = get_books_data(books_data, &books_count); // return total count of books
    data_count[0] = books_count;
    /*
        - What does clearerr do?
        It clears the flags/metadata of the EOF and Error status flags in the specified file/object stream.

        - Why do we clear it?
        Since if we return from the previous function, that means the EOF flag was set. If we don't clear it,
        any time we set a variable to check the status of the EOF flag, it will return -1.
    */
    clearerr(stdin);

    // printf("\n---------------------------------------\n");

    data_count[2] = get_members_data(members_id); // returns total count of members
    clearerr(stdin);

    // printf("\n---------------------------------------\n");

    data_count[3] = get_borrowed_data(borrowed_books_data, borrowed_books_date); // returns total count of borrowed books
    clearerr(stdin);

    // printf("\n------------------------------------------- End of data collection -------------------------------------------\n");

    return 0;
};

/*
    Prerequisite:
    - Data gathered using get_data_handler

    Param:
    - int book_data[][] : containing book ID & number of copies
    - int members_id[]: containing member IDs
    - int borrowed_books_data[][]: containing borrowed book ID & borrower member ID
    - char borrowed_books_date[][]: containing the borrowed date
    - int data_count[3]: containing the outputs of the get_data_helper functions

    Output Commands_List:
        - Number_Books
        - Number_Members
        - Book_ID_Min
        - Books_Available
        - List_Book_Borrowers ID
        - List_Member_Books ID
        - More_Borrowed
        - Members_Less n
        - Books_Unborrowed
        - Books_Borrowed_Days
        - Books_Per_Member
        - Overlapping_Borrowers ID
        - Quit

*/
int commands_handler(int books_data[MAX_BOOKS][2], int members_id[MAX_MEMBERS], int borrowed_books_data[MAX_BORROWED_BOOKS][2], char borrowed_books_date[MAX_BORROWED_BOOKS][DATE_LENGTH], int data_count[4])
{
    char command[40];
    // printf(
    //         "\n\nLibrary system commands\n"
    //         "[...]\n"
    //         "Available commands are\n\n"
    //         "- Number_Books\n"
    //         "- Number_Members\n"
    //         "- Book_ID_Min\n"
    //         "- Books_Available\n"
    //         "- List_Book_Borrowers ID\n"
    //         "- List_Member_Books ID\n"
    //         "- Most_Borrowed\n"
    //         "- Members_Less n\n"
    //         "- Books_Unborrowed\n"
    //         "- Books_Borrowed_Days\n"
    //         "- Books_Per_Member\n"
    //         "- Overlapping_Borrowers ID\n"
    //         "- Quit\n"
    // );

    // printf("Enter a command from the aforementioned list: ");
    /*
        - Why fgets? and not scanf?
        We use fgets because it continues to read the string even if it's separated by a whitespace.
        However, one thing to remember is that fgets adds a newline character at the end of the string.

        What are the parameters?
        - command: the memory (array) location to store the string.
        - sizeof(command): this specifies the length of the string we read. We use sizeof(command)
                            to get the binary length of the command to ensure the user can't input
                            anything longer than the size of the array and prevent buffer overflow.
        - stdin: is the "location" to read from, in our case it's the input (keyboard) stream.
    */
    fgets(command, sizeof(command), stdin);
    /*
        - strcspn(command, "\n") finds the first occurrence of the newline character ('\n') in the string.
        - command[strcspn(command, "\n")] = '\0'; replaces the newline character with the null-terminator '\0',
            effectively removing the newline and ensuring the string is properly terminated.
        - We do this to make sure that when we compare strings we get a correct result because
            "number_books\n" != "number_books".
    */
    command[strcspn(command, "\n")] = '\0';
    /*
        - We use tolower() to make the commands case-insensitive for simplicity and ease of use to the normal user.
        This ensures that users can enter commands in any case (e.g., "Quit", "quit", or "QUIT")
        without worrying about exact casing, which is generally user-friendly.

        This is safe in our case because:
            - Since we even we remove case-sensitivty there is no overlapping in our commands (e.g., no command collision).
            - Also since these commands are non-destructive ( Dont delete any data ) there is no harm if the user misinputs.

        tolower takes in a single character as the input so we loop over command[] and make each character lowercase
    */
   /*
        - We use isspace() to check if the character we pass to it is a whitespace() " " or not
        Why do we need to know this? well some commands take in an ID from the user as input
        Ex: "List_Book_Borrowers 100101" this is an example input from the user
        so if we find the index of the last whitespace in the string we can then do white_space_index + 1
        to get the index/start of the ID
   */
    int white_space_index = -1; // stores the index of the last white space in the command string ( if there is any )
    // stores the argument (ID/n) inputted ( if there is )
    char command_argument[7]; // an array length of 7 is based on the fact that the max length of ID is 6 + (null-terminator)
    for(int i = 0; command[i]; i++)
    {
        command[i] = tolower(command[i]);
        if ( isspace(command[i]) != 0 ){ white_space_index = i; };
    };
    if ( white_space_index != -1 )
    {
        command[white_space_index] = '\0';
        for ( int i = 0; command[white_space_index + i + 1] != '\0'; i++ )
        {
            command_argument[i] = command[i + white_space_index + 1];
            command[white_space_index + i] = '\0';
            if ( i == 5 ) break;
        };
        command_argument[6] = '\0';

        // conver the char command_argument into a string this will allow for easier handling
        int command_argument_int = atoi(command_argument);

        /*Done*/if (strcmp(command, "list_book_borrowers") == 0) { list_book_borrowers(command_argument_int, borrowed_books_data, data_count[3]); }
        /*Done*/else if (strcmp(command, "list_member_books") == 0) { list_member_books(command_argument_int, borrowed_books_data, data_count[3]); }
        /*Done*/else if (strcmp(command, "members_less") == 0) { members_less(command_argument_int, members_id, borrowed_books_data, data_count[2], data_count[3]); }
        /*Done*/else if (strcmp(command, "overlapping_borrowers") == 0) { overlapping_borrowers(command_argument_int, borrowed_books_data, borrowed_books_date, data_count[3]); }
        // /*Done*/else { printf("Invalid Command Try again..."); };

        // Recursion
        // Loop until user input the exit command
        commands_handler(books_data, members_id, borrowed_books_data, borrowed_books_date, data_count);

    };


    /*Done*/if (strcmp(command, "number_books") == 0) { number_books(data_count[1]); }
    /*Done*/else if (strcmp(command, "number_members") == 0) { number_members(data_count[2]); }
    /*Done*/else if (strcmp(command, "book_id_min") == 0) { book_id_min(books_data,  data_count[0]); }
    /*Done*/else if (strcmp(command, "books_available") == 0) { books_available(books_data, borrowed_books_data, data_count[0], data_count[3]); }
    /*Done*/else if (strcmp(command, "most_borrowed") == 0) { most_borrowed(books_data, borrowed_books_data, data_count[0], data_count[3]); }
    /*Done*/else if (strcmp(command, "books_unborrowed") == 0) { books_unborrowed(books_data, borrowed_books_data, data_count[0], data_count[3]); }
    /*Done*/else if (strcmp(command, "books_borrowed_days") == 0) { books_borrowed_days(borrowed_books_date, data_count[3]); }
    /*Done*/else if (strcmp(command, "books_per_member") == 0) { books_per_member(members_id, borrowed_books_data, data_count[2], data_count[3]); }
    /*Done*/else if (strcmp(command, "quit") == 0) { return 0; } // exit command
    // /*Done*/else { printf("Invalid Command Try again....."); };

    // Recursion
    // Loop until user input the exit command
    commands_handler(books_data, members_id, borrowed_books_data, borrowed_books_date, data_count);
};
/* --------------------------------------------------------------------------- */


/* Start of program */
int main()
{
    // Max number of books = 50
    // Max number of members = 30
    int books_data[MAX_BOOKS][2];   // book_ID & copies_Number
    int members_id[MAX_MEMBERS];    // member_ID

    // Max number of books one member can borrow is 5
    int borrowed_books_data[MAX_BORROWED_BOOKS][2];                // borrowed book_ID & borrower member_ID
    char borrowed_books_date[MAX_BORROWED_BOOKS][DATE_LENGTH];     // day/month/year

    /* Pre-requset of the get_data_handler function */
    /* Each value initialized to zero */
    int data_count[4] = {0, 0, 0, 0};

    /* These two handle both the input of data and output */
    get_data_handler(books_data, members_id, borrowed_books_data, borrowed_books_date, data_count);
    commands_handler(books_data, members_id, borrowed_books_data, borrowed_books_date, data_count);

    return 0; // exit
}
