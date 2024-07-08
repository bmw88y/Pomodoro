#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>
#include <cstdio>

using namespace std;

void Task(int taskNumber) {

    // Ask the user for the task name
    string taskName;
    cout << "Enter the task name: ";
    cin.ignore(); // Skip the remaining newline from previous input
    getline(cin, taskName); // Read the new line

    // Save the completed task name to the file
    ofstream completedTasksFile("completed_tasks.txt", ios::app);
    completedTasksFile << "Task " << taskNumber << ": " << taskName << endl;
    completedTasksFile.close();
    // Tumer
    cout << "Work on task " << taskNumber << " for 25 minutes." << endl;
    this_thread::sleep_for(chrono::minutes(25));

    // Display a message
    switch (taskNumber) {
        case 1:
            cout << "Great job! Keep up the momentum!" << endl;
            break;
        case 2:
            cout << "You're doing fantastic! Stay focused!" << endl;
            break;
        case 3:
            cout << "You're making progress! Keep it up!" << endl;
            break;
        case 4:
            cout << "Congratulations! You've completed all tasks!" << endl;
            break;
        default:
            cout << "Please choose a valid number between 1 and 4." << endl;
            return; // Exit function
    }
}

int main() {
    int taskNumber;
    cout << "Enter task number (1-4): ";
    cin >> taskNumber;

    Task(taskNumber);

    // Take a short break after completing the task
    cout << "Short break for 5 minutes." << endl;
    this_thread::sleep_for(chrono::minutes(5));

    // If this is the last task, take a longer break
    if (taskNumber == 4) {
        cout << "Break for 15 minutes." << endl;
        for (int i = 15; i >= 0; --i) {
            cout << "Time remaining: " << i << " minutes" << endl;
            this_thread::sleep_for(chrono::minutes(1));
        }
    }

    cout << "Do you want to delete the file content? (yes/no): ";
    string response;
    cin >> response;
    if (response == "yes") {
        if (remove("completed_tasks.txt") == 0) {
            cout << "File content deleted." << endl;
        } else {
            cout << "Failed to delete the file." << endl;
        }
    } else {
        cout << "File content preserved." << endl;
    }

    return 0;
}
