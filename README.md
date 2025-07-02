# Airline-Ticket-Reservation-Project
This is a simple console-based Airline Ticket Reservation System built using C++. The program allows users to view available flights and reserve a seat if available. It uses file handling to store and update flight data.

✅ Features:
View flight details (Flight No, Destination, Departure, Seats)

Reserve a seat by entering the flight number

Real-time update of available seats in a .txt file

Handles unavailable seat situations

Easy-to-use menu system

How It Works:
1. Three flights are initialized with destinations and seat counts.

2. The program writes this info into Flight.txt.

3. When a user chooses to reserve, they input the flight number.

4. If seats are available, it decrements and updates the file.

5. If no seats are left, it informs the user.

