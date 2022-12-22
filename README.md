
<h1 align="center"> University Database </h1>

This is a database application for storing records of students and employees at a university. The following features are included:

### Student Records

 - First name 
 - Last name
 -  Address
 -  Index
 -  number PESEL 
 - Gender

### Employee Records

 - First name 
 - Last name 
 - PESEL number 
 - Gender 
 - Address 
 - Salary

### Features

- [x] Add new students and employees
- [x] Display the entire database
- [x] Search by last name or PESEL number
- [x] Sort by PESEL number or last name
- [x] Delete by index number
- [x] Delete range of people
- [x] Validate the correctness of a PESEL number (using the Wiki - PESEL correctness guidelines)
- [x] Save the entire database to a file
- [x] Read data from a file
- [x] Generate artificial data to fill the database
- [x] Sort by salary
- [x] Modify salary by searching for a person by PESEL number
- [x] Delete duplicates
- [x] Menu for users
- [x] Load previous saved databases

<h1 align="center">How to use</h1>


### Building project
    mkdir build
    cd build
    cmake ..
    make -j
    .\UNIVERSITY-DB.exe (app)
    .\UNIVERSITY-DB-ut.exe (tests)
    
---
### Reading data from file
*Add to file called DatabaseOfStudentsINPUT.txt a person like this:*

***Student:**

    
    Name; Surname; Address; Pesel;
    OtherName; OtherSurname; OtherAddress; OtherPesel;
***Employee:**

    Name; Surname; Address; Pesel; Earnings;
    OtherName; OtherSurname; OtherAddress; OtherPesel; OtherEarnings;
*You can also add several Students and Staff at the same time without worrying about their order.*

*Main menu -> 7. Load poeple from file -> 1. Load Database from default file.*

---
### Directory named Config

*Do not modify these files!*

---
<h1 align="center"> How it looks </h1>

### Welcome menu
![image](https://user-images.githubusercontent.com/85802542/209230961-c7707b53-d761-4372-924b-49497b58a7d8.png)

### Main menu
![image](https://user-images.githubusercontent.com/85802542/209231009-1d9eae05-8763-4e27-a782-5ae51606ffff.png)

### Example of database
![image](https://user-images.githubusercontent.com/85802542/209231036-92c21352-f2a8-4dc0-b331-6a785de8566c.png)
