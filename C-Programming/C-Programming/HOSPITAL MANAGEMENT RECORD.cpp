#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PATIENTS 100
#define MAX_HOSPITALS 5
#define MAX_BEDS 4

struct Patient {
    char name[50];
    int age;
    char gender;
};

struct Bed {
    int price;
    int available;
};

struct Hospital {
    char name[50];
    int num_beds;
    struct Bed beds[MAX_BEDS];
};

struct Patient patients[MAX_PATIENTS];
int numPatients = 0;

struct Hospital hospitals[MAX_HOSPITALS];
int numHospitals = 0;

void addPatient() {
    if (numPatients < MAX_PATIENTS) {
        printf("Enter patient name: ");
        scanf("%s", patients[numPatients].name);
        printf("Enter patient age: ");
        scanf("%d", &patients[numPatients].age);
        printf("Enter patient gender (M/F): ");
        scanf(" %c", &patients[numPatients].gender);
        numPatients++;
        printf("Patient added successfully.\n");
    } else {
        printf("Maximum number of patients reached.\n");
    }
}

void displayPatients() {
    printf("Patient Records:\n");
    for (int i = 0; i < numPatients; i++) {
        printf("Name: %s, Age: %d, Gender: %c\n", patients[i].name, patients[i].age, patients[i].gender);
    }
}

void addHospital() {
    if (numHospitals < MAX_HOSPITALS) {
        printf("Enter hospital name: ");
        scanf("%s", hospitals[numHospitals].name);
        printf("Enter number of beds: ");
        scanf("%d", &hospitals[numHospitals].num_beds);
        for (int i = 0; i < hospitals[numHospitals].num_beds; i++) {
            printf("Enter price for bed %d: ", i + 1);
            scanf("%d", &hospitals[numHospitals].beds[i].price);
            printf("Enter availability for bed %d: ", i + 1);
            scanf("%d", &hospitals[numHospitals].beds[i].available);
        }
        numHospitals++;
        printf("Hospital added successfully.\n");
    } else {
        printf("Maximum number of hospitals reached.\n");
    }
}

void displayHospitals() {
    printf("Hospital Records:\n");
    for (int i = 0; i < numHospitals; i++) {
        printf("Hospital Name: %s\n", hospitals[i].name);
        printf("Number of Beds: %d\n", hospitals[i].num_beds);
        for (int j = 0; j < hospitals[i].num_beds; j++) {
            printf("Bed %d - Price: %d, Available: %d\n", j + 1, hospitals[i].beds[j].price, hospitals[i].beds[j].available);
        }
    }
}

int compareHospitalByName(const void *a, const void *b) {
    const struct Hospital *hospitalA = (const struct Hospital *)a;
    const struct Hospital *hospitalB = (const struct Hospital *)b;
    return strcmp(hospitalA->name, hospitalB->name);
}

int compareHospitalByAvailableBeds(const void *a, const void *b) {
    const struct Hospital *hospitalA = (const struct Hospital *)a;
    const struct Hospital *hospitalB = (const struct Hospital *)b;
    int totalAvailableA = 0, totalAvailableB = 0;
    for (int i = 0; i < hospitalA->num_beds; i++) {
        totalAvailableA += hospitalA->beds[i].available;
    }
    for (int i = 0; i < hospitalB->num_beds; i++) {
        totalAvailableB += hospitalB->beds[i].available;
    }
    return totalAvailableB - totalAvailableA;
}

int compareHospitalByAvgPrice(const void *a, const void *b) {
    const struct Hospital *hospitalA = (const struct Hospital *)a;
    const struct Hospital *hospitalB = (const struct Hospital *)b;
    int totalPriceA = 0, totalPriceB = 0;
    for (int i = 0; i < hospitalA->num_beds; i++) {
        totalPriceA += hospitalA->beds[i].price;
    }
    for (int i = 0; i < hospitalB->num_beds; i++) {
        totalPriceB += hospitalB->beds[i].price;
    }
    int avgPriceA = totalPriceA / hospitalA->num_beds;
    int avgPriceB = totalPriceB / hospitalB->num_beds;
    return avgPriceA - avgPriceB;
}

int main() {
    int choice;
    do {
        printf("\n--- Hospital Management System ---\n");
        printf("1. Add a new patient record\n");
        printf("2. Display all patient records\n");
        printf("3. Add a new hospital record\n");
        printf("4. Display all hospital records\n");
        printf("5. Sort hospitals by name\n");
        printf("6. Sort hospitals by number of available beds\n");
        printf("7. Sort hospitals by average bed price\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addPatient();
                break;
            case 2:
                displayPatients();
                break;
            case 3:
                addHospital();
                break;
            case 4:
                displayHospitals();
                break;
            case 5:
                qsort(hospitals, numHospitals, sizeof(struct Hospital), compareHospitalByName);
                printf("Hospitals sorted by name.\n");
                break;
            case 6:
                qsort(hospitals, numHospitals, sizeof(struct Hospital), compareHospitalByAvailableBeds);
                printf("Hospitals sorted by number of available beds.\n");
                break;
            case 7:
                qsort(hospitals, numHospitals, sizeof(struct Hospital), compareHospitalByAvgPrice);
                printf("Hospitals sorted by average bed price.\n");
                break;
            case 8:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 8);
    return 0;
}

