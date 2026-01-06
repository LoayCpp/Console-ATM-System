# 🏦 ATM System (C++)

A console-based **ATM Banking System** built in **C++**, simulating real ATM operations using **file-based storage**, authentication, and a menu-driven interface.

---

## 📑 Table of Contents
- [📌 Project Description](#-project-description)
- [🚀 Features](#-features)
- [🛠️ Technologies Used](#️-technologies-used)
- [📂 Data Storage Format](#-data-storage-format)
- [📷 Screenshots](#-screenshots)
- [🧠 What I Learned](#-what-i-learned)
- [📌 Notes](#-notes)
- [👤 Developer ](#-developer)

---

## 📌 Project Description

This project simulates an ATM machine system where users can securely log in using an **account number and PIN code**, then perform different banking transactions through a clear, menu-driven console interface.

The system uses a **text file as a simple database** to store client information and ensures that balances are updated and saved after every transaction without using any external database.

---

## 🚀 Features

- 🔐 Secure login using Account Number & PIN  
- ⚡ Quick Withdraw with predefined amounts  
- 💵 Normal Withdraw (multiples of 5 only)  
- ➕ Deposit money into account  
- 📊 Check account balance  
- 💾 File-based data persistence  
- 🔁 Automatic balance update after each transaction  
- 📋 User-friendly menu navigation  

---

## 🛠️ Technologies Used

- **C++**  
- File Handling (`fstream`)  
- `struct` for data modeling  
- `enum` for menu & transaction control  
- `vector` for dynamic data storage  
- Modular programming & clean code structure  

---

## 📂 Data Storage Format

Client data is stored in a text file using the following format:  
```text
AccountNumber#//#PinCode#//#Name#//#Phone#//#Balance
```
---

## 📷 Screenshots

> You can click any image to view it in full size.

### 🔐 Login Screen  :   
The **Main Menu** appears after a successful login.  
Users can choose from the available options: Quick Withdraw, Normal Withdraw, Deposit, Check Balance, or Logout.   

--- 
<img width="1483" height="762" alt="Screenshot 2026-01-06 224610" src="https://github.com/user-attachments/assets/8fe15d48-047b-4f14-8e48-4220bc2f3a49" />

---
### 🏠 ATM Main Menu :   
The **Main Menu** appears after a successful login.  
Users can choose from the available options: Quick Withdraw, Normal Withdraw, Deposit, Check Balance, or Logout.  

---
<img width="1483" height="762" alt="Screenshot 2026-01-06 224616" src="https://github.com/user-attachments/assets/a1e3bbdd-986c-4d0b-9fe1-0271abb68e58" />

---

### ⚡ Quick Withdraw  :  
The **Quick Withdraw** screen allows the user to withdraw **predefined amounts** quickly.  
Users can select from several common withdrawal amounts (20, 50, 100, etc.) or exit to the main menu.   

---

<img width="1483" height="762" alt="Screenshot 2026-01-06 224623" src="https://github.com/user-attachments/assets/c139de9a-da0d-4465-b1a9-558a9766b72f" />

---
### ⚡ Normal Withdraw  :   
The **Normal Withdraw** screen allows the user to enter a **custom amount**, which must be a **multiple of 5**.It validates the input and ensures the requested amount does not exceed the current balance.   

----
 
<img width="1483" height="762" alt="Screenshot 2026-01-06 224632" src="https://github.com/user-attachments/assets/efc077ee-0e6d-49a8-b0cf-1024396fe167" />

---

### ➕ Deposit Screen   :   
The **Deposit Screen** allows the user to add funds to their account.  
Users enter a **positive amount**, which is then added to their balance and saved to the data file.    

---
<img width="1483" height="762" alt="Screenshot 2026-01-06 224654" src="https://github.com/user-attachments/assets/e547bc26-d581-4d5c-ae48-4f017f45f412" />

---
### 📊 Check Balance  :   
The **Check Balance Screen** shows the user's **current account balance**.  
It allows the user to verify funds after any transaction.   

<img width="1483" height="762" alt="Screenshot 2026-01-06 224705" src="https://github.com/user-attachments/assets/9c42acd1-04ca-4462-80d4-10e404051957" />



---

## 📌 Notes
- Create a folder named `screenshots` and place all project images inside it.  
- Make sure the image names in the folder match the links used in this document (e.g., `login.png`, `main-menu.png`).  
- When running the project on a new machine, ensure the text data file (database) exists with the correct format.  
- Make sure the data file is readable and writable so that balances are updated after each transaction.  

---

## 🧠 What I Learned

- Designing a **menu-driven console application**  
- Implementing **authentication systems**  
- Working with **file-based data storage**  
- Updating and persisting data after transactions  
- Using `enum` to improve code readability  
- Structuring a project into **clear and reusable functions**  
- Handling user input validation and errors  
- Improving program flow and user experience  

---

## 👤 Developer  
<strong> Loay Anwar</strong> <br>
 <a href="https://github.com/LoayCpp">
    <img width="50" height="50" alt="Loay-modified" src="https://github.com/user-attachments/assets/8fee5f57-fc06-4723-a7ad-2d077ab1d7e2" />
</a>


  <a href="https://www.linkedin.com/in/loay-anwar-alarify-259634260" target="_blank">
    <img src="https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white" alt="LinkedIn" />
  </a>
  <a href="https://www.facebook.com/share/1ByuvJEiyu/" target="_blank">
    <img src="https://img.shields.io/badge/Facebook-1877F2?style=for-the-badge&logo=facebook&logoColor=white" alt="Facebook" />
  </a>
  <a href="https://www.instagram.com/7.loa7?igsh=cWxjeHRzM2pnaWc2" target="_blank">
    <img src="https://img.shields.io/badge/Instagram-E4405F?style=for-the-badge&logo=instagram&logoColor=white" alt="Instagram" />
  </a>



---
