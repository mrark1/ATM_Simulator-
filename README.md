# 💳 Advanced ATM Simulation System (C++ Capstone Project)

## 📌 Project Overview
The **Advanced ATM Simulation System** is a console-based C++ application that simulates the core working of an Automated Teller Machine (ATM).  
This project is designed as a **capstone / final-year project**, demonstrating the use of **Object-Oriented Programming**, **file handling**, and **real-world banking logic**.

The system allows users to securely log in using an account number and PIN, perform banking operations such as deposits, withdrawals, fund transfers, and maintain transaction records with persistent data storage.

---

## 🎯 Objectives
- To simulate real-time ATM banking operations
- To implement secure user authentication
- To demonstrate OOP concepts in C++
- To store data permanently using file handling
- To build a menu-driven, user-friendly console application

---

## 🚀 Features
✔ Secure login using Account Number and PIN  
✔ Balance inquiry  
✔ Cash deposit  
✔ Cash withdrawal with balance validation  
✔ Fund transfer between accounts  
✔ PIN change functionality  
✔ Transaction history logging  
✔ Persistent data using text files  
✔ Menu-driven interface  

---

## 🛠 Technologies Used
- **Programming Language:** C++  
- **Compiler:** Dev-C++ (C++98 compatible)  
- **Concepts Used:**
  - Object-Oriented Programming (OOP)
  - Classes and Objects
  - File Handling (`fstream`)
  - Functions
  - Conditional Statements
  - Loops
  - Vectors (STL)

---

## 📂 Project Structure
Advanced-ATM-Simulation/
│
├── ATM_Simulation.cpp # Main C++ source file
├── accounts.txt # Stores account details
├── transactions.txt # Stores transaction history
└── README.md # Project documentation  


---

## 🧾 Account Data Format (`accounts.txt`)
**Example:**
1001 Arpit 1234 5000
1002 User 4321 8000  

---

## 🧾 Transaction Log Format (`transactions.txt`)
Account: 1001 | Deposit | Amount: 2000
Account: 1001 | Withdrawal | Amount: 500
Account: 1002 | Transfer Received | Amount: 1000  


---

## ▶ How to Run the Project
1. Open **Dev-C++**
2. Create a new source file
3. Copy and paste `ATM_Simulation.cpp`
4. Save the file
5. Compile and Run (F11)

> ⚠ Ensure the `.cpp` file is in a writable folder so the program can create `accounts.txt` and `transactions.txt`.

---

## 🔐 Default Login Credentials
| Account No | Name  | PIN  | Balance |
|-----------|------|------|---------|
| 1001 | Arpit | 1234 | ₹5000 |
| 1002 | User  | 4321 | ₹8000 |

---

## 🧠 Concepts Demonstrated
- Encapsulation using classes
- Persistent storage using file handling
- Menu-driven programming
- Input validation
- Modular programming
- Real-world problem simulation

---

## 📈 Future Enhancements
- Admin panel for account management
- Account lock after multiple failed logins
- OTP-based authentication
- GUI version using **Qt**
- Database integration (MySQL / SQLite)
- Encryption of PIN for enhanced security

---

## 🎓 Academic Use
This project is suitable for:
- Final Year / Capstone Project
- Internship Evaluation
- College Mini Project
- C++ Practical Examination
- GitHub Portfolio

---

## 🧑‍💻 Author
**Arpit Raj Katiyar**  
B.Tech | Computer Science  
C++ | Python | Flask | Web Development  

---

## 📜 License
This project is developed for **educational purposes**.  
You are free to modify and enhance it for learning or academic use.

---
