#include <iostream>
#include <cstring>
#include <cstdlib>

// Struct definition
struct FlightInfo {
    char* destination;
    char* date;
};

// Function to fill flight information
void fillFlightInfo(FlightInfo* flight, const char* dest, const char* date) {
    // Allocate memory for destination and date
    flight->destination = (char*)malloc(strlen(dest) + 1);
    flight->date = (char*)malloc(strlen(date) + 1);

    // Check if memory allocation was successful
    if (flight->destination == nullptr || flight->date == nullptr) {
        std::cerr << "Memory allocation failed" << std::endl;
        exit(EXIT_FAILURE);
    }

    // Copy strings into allocated memory
    strcpy_s(flight->destination, strlen(dest) + 1, dest);
    strcpy_s(flight->date, strlen(date) + 1, date);
}

// Function to print flight information
void printFlightInfo(FlightInfo flights[], int size) {
    std::cout << "Flight Information:\n";
    for (int i = 0; i < size; ++i) {
        printf("%-35s %-35s\n", flights[i].destination, flights[i].date);
    }
}

int main() {
    const int numFlights = 10;
    FlightInfo flights[numFlights];

    // Input flight information
    for (int i = 0; i < numFlights; ++i) {
        char dest[31], date[31];
        std::cout << "Enter destination for flight " << i + 1 << ": ";
        std::cin.getline(dest, 31);
        std::cout << "Enter date for flight " << i + 1 << ": ";
        std::cin.getline(date, 31);

        // Fill flight info
        fillFlightInfo(&flights[i], dest, date);
    }

    // Print flight information
    printFlightInfo(flights, numFlights);

    // Free allocated memory
    for (int i = 0; i < numFlights; ++i) {
        free(flights[i].destination);
        free(flights[i].date);
    }

    return 0;
}
