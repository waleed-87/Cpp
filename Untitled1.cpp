

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

const int MAX_RECORDS   = 100;
const string ADMIN_PASS = "admin123";


const string DONOR_FILE  = "donors.txt";
const string SEEKER_FILE = "seekers.txt";


struct Donor {
    int id;
    char name[20];
    int age;
    char blood[10];
    char city[15];
    char number[15]; 
    bool available;
};

struct Seeker {
    int id;
    char name[20];
    int age;
    char blood_needed[10];
    char city[15];
    char number[15]; 
    char hospital_name[30];
    char urgency_lvl[10];
};


Donor donors[MAX_RECORDS];
Seeker seekers[MAX_RECORDS];
int donorCount = 0;
int seekerCount = 0;


void pressEnter() {
    cout << "\nPress Enter to continue...";
    cin.ignore();
    cin.get();
}



int generateDonorId() {
    return (donorCount == 0) ? 1001 : donors[donorCount - 1].id + 1;
}

int generateSeekerId() {
    return (seekerCount == 0) ? 2001 : seekers[seekerCount - 1].id + 1;
}


//  file handling

void saveDonorsFile() {
    ofstream f(DONOR_FILE.c_str());
    if (!f) return;
    f << donorCount << "\n";
    for (int i = 0; i < donorCount; i++) {
        f << donors[i].id << "\n"
          << donors[i].name << "\n"
          << donors[i].age << "\n"
          << donors[i].blood << "\n"
          << donors[i].city << "\n"
          << donors[i].number << "\n"
          << donors[i].available << "\n";
    }
    f.close();
}

void loadDonorsFile() {
    ifstream f(DONOR_FILE.c_str());
    if (!f) return;
    f >> donorCount;
    f.ignore();
    for (int i = 0; i < donorCount; i++) {
        f >> donors[i].id;
        f.ignore();
        f.getline(donors[i].name, 20);
        f >> donors[i].age;
        f.ignore();
        f.getline(donors[i].blood, 10);
        f.getline(donors[i].city, 15);
        f.getline(donors[i].number, 15);
        f >> donors[i].available;
        f.ignore();
    }
    f.close();
}

void saveSeekersFile() {
    ofstream f(SEEKER_FILE.c_str());
    if (!f) return;
    f << seekerCount << "\n";
    for (int i = 0; i < seekerCount; i++) {
        f << seekers[i].id << "\n"
          << seekers[i].name << "\n"
          << seekers[i].age << "\n"
          << seekers[i].blood_needed << "\n"
          << seekers[i].city << "\n"
          << seekers[i].number << "\n"
          << seekers[i].hospital_name << "\n"
          << seekers[i].urgency_lvl << "\n";
    }
    f.close();
}

void loadSeekersFile() {
    ifstream f(SEEKER_FILE.c_str());
    if (!f) return;
    f >> seekerCount;
    f.ignore();
    for (int i = 0; i < seekerCount; i++) {
        f >> seekers[i].id;
        f.ignore();
        f.getline(seekers[i].name, 20);
        f >> seekers[i].age;
        f.ignore();
        f.getline(seekers[i].blood_needed, 10);
        f.getline(seekers[i].city, 15);
        f.getline(seekers[i].number, 15);
        f.getline(seekers[i].hospital_name, 30);
        f.getline(seekers[i].urgency_lvl, 10);
    }
    f.close();
}

// 
//  seekeer panel

void addBloodRequest() {
    if (seekerCount >= MAX_RECORDS) {
        cout << "  [ERROR] Request list is full!\n";
        return;
    }

    cout << "\n ADD BLOOD REQUEST \n";
    Seeker s;
    s.id = generateSeekerId();

    cin.ignore(); 
    cout << "  Enter your full name       : ";
    cin.getline(s.name, 20); 

    cout << "  Enter your age             : ";
    cin >> s.age;
    cin.ignore();

    cout << "  Blood group needed (eg O+) : ";
    cin.getline(s.blood_needed, 10);  

  
   
    cout << "  Enter your city            : ";
    cin.getline(s.city, 15);

    cout << "  Enter your contact number  : ";
    cin.getline(s.number, 15);

    cout << "  Hospital name              : ";
    cin.getline(s.hospital_name, 30);
   
    cout << "  Urgency (Low/Medium/High)  : ";
    cin.getline(s.urgency_lvl, 10);
    
    seekers[seekerCount] = s;
    seekerCount++;
    saveSeekersFile();

    cout << "\n  [SUCCESS] Request added! Your Request ID is: " << s.id << "\n";
    pressEnter();
}

void seekerMenu() {
    int choice;
    do {
        cout << "\n BLOOD SEEKER PANEL \n";
        cout << "  1. Add Blood Request\n"
             << "  0. Back to Main Menu\n";
        cout << "  Your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addBloodRequest(); break;
            case 0: break;
            default: cout << "  Invalid choice!\n"; pressEnter();
        }
    } while (choice != 0);
}


//  donor panel

void registerDonor() {
    if (donorCount >= MAX_RECORDS) {
        cout << "  [ERROR] Donor list is full!\n";
        return;
    }

    cout << "\n DONOR REGISTRATION \n";
    Donor d;
    d.id = generateDonorId();

    cin.ignore();
    cout << "  Enter your full name       : ";
    cin.getline(d.name, 20);

    cout << "  Enter your age             : ";
    cin >> d.age;
    cin.ignore();

    if (d.age < 18 || d.age > 65) {
        cout << "\n  [ERROR] Age must be between 18 and 65 to donate.\n";
        pressEnter();
        return;
    }

    cout << "  Enter blood group (eg A+)  : ";
    cin.getline(d.blood, 10);
  

    cout << "  Enter your city            : ";
    cin.getline(d.city, 15);

    cout << "  Enter contact number       : ";
    cin.getline(d.number, 15);

    d.available = true;

    donors[donorCount] = d;
    donorCount++;
    saveDonorsFile();

    cout << "\n  [SUCCESS] Registered! Your Donor ID is: " << d.id << "\n";
    pressEnter();
}

void viewAllSeekers() {
    cout << "\n PEOPLE WHO NEED BLOOD \n";
    if (seekerCount == 0) {
        cout << "  No blood requests found.\n";
        pressEnter();
        return;
    }
    for (int i = 0; i < seekerCount; i++) {
        cout << "  ID: " << seekers[i].id 
             << " | Name: " << seekers[i].name 
             << " | Blood Needed: " << seekers[i].blood_needed 
             << " | Urgency: " << seekers[i].urgency_lvl << "\n";
    }
    cout << "  Total requests: " << seekerCount << "\n";
    pressEnter();
}

void viewSeekerDetails() {
    cout << "\n VIEW SEEKER DETAILS \n";
    cout << "  Enter Seeker ID: ";
    int id; cin >> id;

    for (int i = 0; i < seekerCount; i++) {
        if (seekers[i].id == id) {
            cout << "\n  *** FULL DETAILS ***\n";
            cout << "  ID           : " << seekers[i].id << "\n"
                 << "  Name         : " << seekers[i].name << "\n"
                 << "  Age          : " << seekers[i].age << "\n"
                 << "  Blood Needed : " << seekers[i].blood_needed << "\n"
                 << "  City         : " << seekers[i].city << "\n"
                 << "  Hospital     : " << seekers[i].hospital_name << "\n"
                 << "  Urgency      : " << seekers[i].urgency_lvl << "\n"
                 << "  Contact Name : Contact " << seekers[i].name << " at " << seekers[i].number << "\n";
            pressEnter();
            return;
        }
    }
    cout << "  [ERROR] Seeker ID not found.\n";
    pressEnter();
}

void donorMenu() {
    int choice;
    do {
        cout << "\n DONOR PANEL \n";
        cout << "  1. Register as a Donor\n"
             << "  2. View All Blood Requests (People Needing Blood)\n"
             << "  3. View Seeker Details (to Contact)\n"
             << "  0. Back to Main Menu\n";
        cout << "  Your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: registerDonor();       break;
            case 2: viewAllSeekers();      break;
            case 3: viewSeekerDetails();   break;
            case 0: break;
            default: cout << "  Invalid choice!\n"; pressEnter();
        }
    } while (choice != 0);
}


//  admin panel 

void adminViewAllDonors() {
    cout << "\n ALL REGISTERED DONORS \n";
    if (donorCount == 0) {
        cout << "  No donors registered yet.\n";
        pressEnter();
        return;
    }
    for (int i = 0; i < donorCount; i++) {
        cout << "  ID: " << donors[i].id 
             << " | Name: " << donors[i].name 
             << " | Age: " << donors[i].age 
             << " | Blood Group: " << donors[i].blood 
             << " | City: " << donors[i].city 
             << " | Phone: " << donors[i].number
             << " | Available: " << (donors[i].available ? "YES" : "NO") << "\n";
    }
    pressEnter();
}

void adminSearchByBloodGroup() {
    cout << "\n SEARCH BY BLOOD GROUP \n";
    cout << "  Enter blood group to search: ";
    char bg[10]; cin >> bg;

    int found = 0;
    for (int i = 0; i < donorCount; i++) {
        if (strcmp(donors[i].blood, bg) == 0) {
            cout << "  ID: " << donors[i].id << " | Name: " << donors[i].name << " | City: " << donors[i].city << " | Contact: " << donors[i].number << "\n";
            found++;
        }
    }
    if (found == 0) cout << "  No donors found with blood group: " << bg << "\n";
    pressEnter();
}

void adminUpdateDonor() {
    cout << "\n UPDATE DONOR RECORD \n";
    cout << "  Enter Donor ID to update: ";
    int id;
	 cin >> id;

    for (int i = 0; i < donorCount; i++) {
        if (donors[i].id == id) {
           
            cout << "  Enter New Name [" << donors[i].name << "]: ";
            cin.getline(donors[i].name, 20);
            cout << "  Enter New Age: ";
            cin >> donors[i].age;
            cin.ignore();
            cout << "  Enter New City: ";
            cin.getline(donors[i].city, 15);
            cout << "  Enter New Contact Number: ";
            cin.getline(donors[i].number, 15);
            cout << "  Is Available? (1=Yes, 0=No): ";
            cin >> donors[i].available;

            saveDonorsFile();
            cout << "  [SUCCESS] Donor record updated successfully!\n";
            pressEnter();
            return;
        }
    }
    cout << "  [ERROR] Donor ID not found.\n";
    pressEnter();
}

void adminDeleteDonor() {
    cout << "\n DELETE DONOR RECORD \n";
    cout << "  Enter Donor ID to delete: ";
    int id;
	 cin >> id;

    for (int i = 0; i < donorCount; i++) {
        if (donors[i].id == id) {
           
            for (int j = i; j < donorCount - 1; j++) {
                donors[j] = donors[j + 1];
            }
            donorCount--;
            saveDonorsFile();
            cout << "  [SUCCESS] Donor ID " << id << " deleted.\n";
            pressEnter();
            return;
        }
    }
    cout << "  [ERROR] Donor ID not found.\n";
    pressEnter();
}

void adminMenu() {
    cout << "\n ADMIN LOGIN \n";
    cout << "  Enter Admin Password: ";
    string pass; cin >> pass;

    if (pass != ADMIN_PASS) {
        cout << "  [ERROR] Access Denied. Wrong Password!\n";
        pressEnter();
        return;
    }

    int choice;
    do {
        cout << "\n ADMIN PANEL \n";
        cout << "  1. View All Donors\n"
             << "  2. Search Donors by Blood Group\n"
             << "  3. Update Donor Record\n"
             << "  4. Delete Donor Record\n"
             << "  0. Back to Main Menu\n";
        cout << "  Your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: adminViewAllDonors();      break;
            case 2: adminSearchByBloodGroup(); break;
            case 3: adminUpdateDonor();        break;
            case 4: adminDeleteDonor();        break;
            case 0: break;
            default: cout << "  Invalid choice!\n"; pressEnter();
        }
    } while (choice != 0);
}


//  main body

int main() {
   
    loadDonorsFile();
    loadSeekersFile();

    int choice;
    do {
        cout << "\n------\n"
             << "   *** BLOOD DONATION SYSTEM ***\n";
            
        cout << "  1. Admin Panel\n"
             << "  2. Donor Panel\n"
             << "  3. Seeker Panel\n"
             << "  0. Exit\n";
        cout << "  Your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: adminMenu();  break;
            case 2: donorMenu();  break;
            case 3: seekerMenu(); break;
            case 0:
                cout << "\n  Thank you for using the Blood Donation System!\n\n";
                break;
            default:
                cout << "  Invalid choice! Try again.\n";
                pressEnter();
        }
    } while (choice != 0);

    return 0;
}
