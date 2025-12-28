
# 📔 Personal Diary Management System (C++ Console Application)

## 📌 Project Overview

**Personal Diary Management System** is a C++ console-based application that allows users to securely maintain a personal diary.
Users can register, log in, write diary entries, view past entries, and delete entries based on a specific date.

This project focuses on **file handling**, **user authentication**, **data persistence**, and **menu-driven programming** in C++.

---

## 📚 Table of Contents

* [Features](#-features)
* [Technologies Used](#-technologies-used)
* [Project Structure](#-project-structure)
* [Installation](#-installation)
* [System Workflow](#-system-workflow)
* [Usage Guide](#-usage-guide)
* [File Storage](#-file-storage)
* [Validation & Error Handling](#-validation--error-handling)
* [Known Limitations](#-known-limitations)
* [Future Enhancements](#-future-enhancements)
* [Author](#-author)
* [License](#-license)

---

## ✨ Features

* 🔐 User Registration & Login
* 📝 Add Diary Entries with Date
* 👀 View Personal Diary Entries
* 🗑️ Delete Diary Entries by Date
* 📁 File-based Data Storage
* ✅ Input Validation & Error Handling

---

## 🛠 Technologies Used

* **Language:** C++
* **Libraries:**

  * `<iostream>`
  * `<fstream>`
  * `<string>`
  * `<limits>`
* **Platform:** Windows (uses `system("cls")`)

---

## 📂 Project Structure

```
Personal-Diary-Management-Cpp/
│
├── main.cpp          # Main source code
├── user.txt          # Stores registered users
├── diary.txt         # Stores diary entries
├── temp.txt          # Temporary file for deletion
└── README.md
```

---

## ⚙️ Installation

1. Clone or download the repository.
2. Open the project in any C++ compiler (Dev-C++, Code::Blocks, Visual Studio).
3. Ensure the following directory exists on your system:

```
D:\PF LAb project Practices\Group_no_2\
```

4. Compile the program:

```
g++ main.cpp -o diary_system
```

5. Run the executable:

```
diary_system
```

---

## 🔁 System Workflow

1. User registers with a username and password
2. User logs in securely
3. User can:

   * Add diary entries
   * View previous entries
   * Delete entries by date
4. User logs out safely

---

## 🚀 Usage Guide

### Main Menu

```
1. Register
2. Login
3. Exit
```

### User Menu

```
1. Add Entry
2. Delete Entry
3. View Entries
4. Logout
```

---

## 🗃️ File Storage

### user.txt

```
username password
```

### diary.txt

```
username date diary_text
```

All diary entries are saved permanently until deleted by the user.

---

## ✅ Validation & Error Handling

* Prevents invalid menu selections
* Ensures valid numeric input
* Prevents duplicate usernames
* Handles incorrect login credentials
* Clears input buffer to avoid runtime errors
* Safely handles file operations

---

## ⚠️ Known Limitations

* Passwords stored in plain text
* Hardcoded Windows file paths
* Console-based interface only
* One entry deletion per date

---

## 🔮 Future Enhancements

* 🔒 Password encryption
* 🖥️ Cross-platform compatibility
* 📅 Multiple diary entries per date
* 🔍 Search functionality
* 🗄️ Database integration
* 📱 GUI or mobile application

---

## 👤 Author

**Ali Raza**
🎓 Programming Fundamentals
📘 Project: Personal Diary Management System

---

## 📜 License

This project is developed for **educational purposes only**.
You are free to use, modify, and improve it for learning and academic submissions.



