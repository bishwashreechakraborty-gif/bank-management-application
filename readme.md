# Bank Management System 🏦

A professional, console-based Bank Management Application developed in **C++** utilizing **Object-Oriented Programming (OOP)** and **File Handling** for persistent data storage.

## 🚀 Overview

This application simulates core banking operations, allowing users to create accounts, manage funds, and maintain records securely through binary file persistence. It is designed to demonstrate clean code practices, encapsulation, and robust data management.

## ✨ Key Features

* **Account Creation:** Initialize new customer accounts with unique IDs.
* **Persistent Storage:** Uses binary file handling (`.dat`) to save data permanently.
* **Transactions:** Securely perform deposits and withdrawals with real-time balance updates.
* **Inquiry System:** Search for specific account details or view a complete ledger of all holders.
* **Data Integrity:** Implements basic validation to prevent overdrafts and unauthorized access.

## 🛠️ Technical Stack

* **Language:** C++17 (or higher)
* **Paradigm:** Object-Oriented Programming (OOP)
* **Storage:** Binary File I/O (`fstream`)
* **Formatting:** `iomanip` for tabular data representation

## 📂 Project Structure

| Component | Responsibility |
| :--- | :--- |
| `Account` Class | Manages data members (ID, Name, Balance) and core logic (Deposit/Withdraw). |
| `File Handling` | Manages reading/writing objects to `bank_data.dat`. |
| `Main Menu` | Provides a user-friendly interface for system navigation. |

## ⚙️ Installation & Running

### Prerequisites
* A C++ compiler (GCC/MinGW, Clang, or MSVC).
* Standard terminal or command prompt.

### Compilation
Use the following command in your terminal to compile the source code:
```bash
g++ main.cpp -o main
```

**Developed by Bishwashree Chakraborty |**
**B.Tech CSE Student |** 
**Passionate about programming and problem-solving**
