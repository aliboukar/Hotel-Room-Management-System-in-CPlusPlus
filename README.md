# 🏨 C++ Hotel Management System

A lightweight, console-based Hotel Management System written in C++. This application allows hotel staff to manage room bookings, view availability, track revenue, and maintain persistence across sessions using file I/O operations.



## ✨ Features

* **Room Management:** View all rooms, or filter to see only currently available rooms.
* **Booking System:** Book available rooms with a confirmation step.
* **Cancellation System:** Easily free up occupied rooms.
* **Price Search:** Search for specific rooms based on their nightly rate.
* **Statistics & Reporting:** Instantly view the total number of rooms, occupancy rates, and calculate current total income from booked rooms.
* **Data Persistence:** Automatically saves and loads booking states to a local `bookings.txt` file so data isn't lost when the program closes.

## 🛠️ Architecture

The system is built using Object-Oriented Programming (OOP) principles and consists of two main classes:

1.  **`Room`**: Represents an individual hotel room. It stores the room number, price, and occupancy status.
2.  **`Hotel`**: Manages a collection (`std::vector`) of `Room` objects. It handles all the core logic, including searching, booking, calculating statistics, and file processing.

## 🚀 Getting Started

### Prerequisites
To compile and run this program, you will need a C++ compiler installed on your system (such as GCC, Clang, or MSVC).

### Compilation
Open your terminal and navigate to the directory containing the source code. Compile the code using the following command:

```bash
g++ main.cpp -o hotel_management
