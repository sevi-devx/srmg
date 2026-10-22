# Student Record Management System

A lightweight, console-based C++ application designed to manage student records using standard file I/O operations and CSV storage.

---

## 📌 Features

- **Add New Students**: Automatically generates unique auto-incrementing Student IDs and appends new entries to persistent storage.
- **Search & View Marks**: Look up specific student records by ID.
- **Update Grades**: Modify student grades in memory and update persistent storage safely using temporary file replacement.
- **Display All Records**: Formatted box layout display for viewing all stored student entries.
- **CSV Data Persistence**: Automatically loads existing records from `sample.csv` on startup and updates the file upon modifications.

---

## 🛠️ Prerequisites

- **C++ Compiler**: GCC (`g++`), Clang, or MSVC with C++11 support or higher.
- **OS Compatibility**: Optimized for POSIX systems (Linux/macOS) due to the use of `system("clear")`.
  > *Note for Windows Users:* Replace `system("clear")` with `system("cls")` in the source code if compiling natively on Windows Command Prompt.

---

## 🚀 Getting Started

### 1. File Requirements
Ensure you have the program source file (e.g., `main.cpp`) in your directory. The system will create or update `sample.csv` in the same directory upon running.

### 2. CSV Data Format (`sample.csv`)
The application expects comma-separated values in the following format:
```csv
1001,John Doe,88.5
1002,Jane Smith,92.0
```

### 3. Compilation
Open your terminal and compile using `g++`:

```bash
g++ main.cpp -o main
```

### 4. Running the Program
Execute the compiled binary:

```bash
./main
```

---

## 📋 Menu Navigation

Upon launch, you will see the interactive terminal menu:

```text
 ------------------------------------------------ 
|        STUDENT RECORD MANAGEMENT SYSTEM        |
 ------------------------------------------------ 

[Select an option below]

1. Add New Students
2. Student View Marks
3. Update Student Marks
4. View All Student Marks
5. Calculate Average GPA
6. Exit
```

### Usage Instructions

1. **Option 1 (Add New Student)**:
   - Enter input in comma-separated format: `<Name>, <Grade>`
   - *Example:* `Alice Johnson, 94.5`

2. **Option 2 (View Student Record)**:
   - Enter the target Student ID (e.g., `1001`).

3. **Option 3 (Update Student Marks)**:
   - Enter the target Student ID.
   - Enter the updated numeric grade when prompted.

4. **Option 4 (View All Records)**:
   - Displays all loaded records formatted with ASCII borders.

5. **Option 6 (Exit)**:
   - Closes the application safely.

---

## ⚠️ Notes & Known Issues

- **Option 5 (Calculate Average GPA)**: Menu option 5 is currently a placeholder and pending implementation in the current release.
- **Input Validation**: Ensure input formats strictly follow requested prompts (e.g., non-empty strings and valid numerical values for grades).
