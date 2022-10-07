//Space and Time Trade-Off
/*
    - Pre-Structuring
    - Hashing algorithms
        - Indexes (B-trees) We are not talking about this!

    - Cryptographic Hashes
        - one way
        - 1:1 on avg hashing
        Ex: MD5, SHA-1, 128, 256, 512

    Passwords:
        - Check username and password pair
        - This means you have to do this for all users
            - You will have a file with all of the information
            - This means do not keep recrods of plain text (unencrypted) passwords
            - So we will store the user name and a has of the password
        
    Dictionary:
        - Data structure that allows us to search, insert, and delete from it
    
    Arrays are a way to impliment dictionaries as well as Linked Lists
    - insert: O(n)
    - search: O(n)
    - delete: O(n)
    Linked List:
    - insert: O(1)
    - search: O(n)
    - delete: O(n)

    What does this have to do with hashing?
    - Hashing is: give me an array of some fixed size 0-10
    - we are going to use a hash function h(x) = x % 11
    - This is now called a hash table
    - Our numbers are 3, 437, 999, 1113, 11

    Hash Table:
    - insert: O(1)
    - search: O(1)
    - delete: O(1)

    If we were to recieve any value that matches up to the hash, we don't need the password anymore and we can feed the hash the value
    This means MD5 is useless and it is soon to happen to SHA-1 due to collisions

    Closed Hashing
    - Checking and pushing the value to the next index
    - Causes more collisions
    - There is a limit to how many values I can store
    -insert: O(n)
    -search: O(n)
    -delete: O(n)

    Now to fix the problem, we will create an array of linked list pointers to dynamically
    allocate new values
    This is Open Hasing
    - search:


*/