# Oladoc Management System

## Overview
Oladoc Management System is a console-based application built in C++ as part of my Object-Oriented Programming (OOP) coursework. The system facilitates the management of healthcare services, enabling patients to book appointments, doctors to manage schedules, and admins to oversee the entire system.

## Features
### Admin Panel
- Add, edit, delete, and view doctor data.
- View patient data.
- Schedule and manage doctor availability.
- View, process, or cancel appointments.

### Doctor Panel
- Register and log in to the system.
- Manage availability, consultation charges, and profile.
- View and update appointment statuses.

### Patient Panel
- Register and log in to the system.
- Search doctors by specialty or location.
- Book, update, or cancel appointments.
- Provide feedback on doctors.
- Recharge account balance for payments.

## Key Modules
1. Appointment Management
2. Doctor Schedule Management
3. Patient Management
4. Doctor Management
5. Login and Registration

## Technology Stack
- **Programming Language**: C++
- **Development Concepts**: Object-Oriented Programming (OOP)
- **File Handling**: Persistent storage using binary files.

## Installation and Running the System
1. Clone the repository:
   ```bash
   git clone https://github.com/Nouman-Amjad/Oladoc.git
2. Navigate to the project directory:
   ```bash
   cd Oladoc
3. Compile the code:
   ```bash
   g++ Main.cpp -o OladocManagementSystem
4. Run the game:
   ```bash
   ./OladocManagementSystem

## Files
- **Main.cpp**: Entry point for the application.
- **USER.h** & **util.h**: Contains user-related classes (Admin, Doctor, Patient).
- **OLADOC.h**: Main application logic and menu system.

## How It Works
- ### Login and Registration:
    - Users (Admin, Doctor, Patient) can register with unique credentials and log in to access features specific to their roles.
- ### Appointment Management:
    - Patients can search for doctors, view their availability, and book in-person or video appointments.
    - Doctors can manage appointments and schedules.
    - Admins can oversee and update appointment statuses.
- ### Feedback and Ratings:
    - Patients can leave reviews and rate doctors after appointments. 
    - Ratings are aggregated and displayed on doctor profiles.

## Future Enhancements:
- Implement GUI for a more user-friendly experience.
- Add support for real-time notifications for appointments.
- Integrate payment gateways like JazzCash and EasyPaisa.

## Acknowledgments
Special thanks to the faculty at FAST-NUCES for their guidance and support during this project.

## License
This project is licensed under the MIT License.
