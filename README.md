# 🔐 Login & Registration System (C++ + OpenSSL SHA-256)

A simple **console-based login and registration system** written in **C++** that uses **SHA-256 hashing (OpenSSL)** for secure password storage.

---

## 🚀 Features
- Register a new user with **SHA-256 password hashing**
- Login with username & password
- Prevents duplicate usernames
- File-based credential storage (`data/users.txt`)
- Uses **OpenSSL** for secure hashing

---

## ⚙️ Requirements
- **C++17 or higher**
- **OpenSSL library**

### Install OpenSSL
- **Arch Linux / Manjaro**
```bash
  sudo pacman -S openssl
````

- **Ubuntu / Debian**

```bash
    sudo apt-get install libssl-dev
```
* **Windows**

  * Install [OpenSSL](https://slproweb.com/products/Win32OpenSSL.html)
  * Ensure your compiler (MSVC/MinGW) links with `-lssl -lcrypto`

---

## 🔨 Build Instructions

```bash
# 1. Clone project
git clone https://github.com/yourusername/LoginSystemSHA256.git
cd LoginSystemSHA256

# 2. Create build directory
mkdir build && cd build

# 3. Generate build files with CMake
cmake ..

# 4. Compile
make

# 5. Run the program
./login_app
```

---

## 💡 Example Usage

```
1. Register
2. Login
3. Exit
Enter choice: 1
Enter username: alice
Enter password: mypassword
Registration successful!

Enter choice: 2
Enter username: alice
Enter password: mypassword
Login successful!
```

---

## 🔒 Security Notes

* Passwords are **never stored in plain text**.
* Uses **SHA-256 hashing (OpenSSL)**.
---