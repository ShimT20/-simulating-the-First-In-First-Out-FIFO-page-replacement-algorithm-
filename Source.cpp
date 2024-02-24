#include <iostream>
using namespace std;

// Function to check if a page is present in the frame
bool isPagePresent(int page, int* frames, int n) {
    for (int i = 0; i < n; ++i) {
        if (frames[i] == page) {
            return true;
        }
    }
    return false;
}

// Function to find the index of the oldest page in the frame
int findOldestPageIndex(int* arrivalTime, int n) {
    int oldestIndex = 0;
    for (int i = 1; i < n; ++i) {
        if (arrivalTime[i] < arrivalTime[oldestIndex]) {
            oldestIndex = i;
        }
    }
    return oldestIndex;
}

// Function to simulate FIFO page replacement algorithm
void simulateFIFO(int* referenceString, int length, int numFrames) {
    int frames[numFrames];
    int arrivalTime[numFrames];
    int pageFaults = 0;

    for (int i = 0; i < numFrames; ++i) {
        frames[i] = -1;  // Initialize frames with -1 indicating empty frame
        arrivalTime[i] = -1;  // Initialize arrival time with -1
    }

    for (int i = 0; i < length; ++i) {
        int currentPage = referenceString[i];

        if (!isPagePresent(currentPage, frames, numFrames)) {
            int oldestIndex = findOldestPageIndex(arrivalTime, numFrames);
            frames[oldestIndex] = currentPage;
            arrivalTime[oldestIndex] = i;
            pageFaults++;

            // Display frames after a page fault
            cout << "Page Fault #" << pageFaults << ": ";
            for (int j = 0; j < numFrames; ++j) {
                if (frames[j] == -1) {
                    cout << "[ ] ";
                }
                else {
                    cout << "[" << frames[j] << "] ";
                }
            }
            cout << endl;
        }
    }

    cout << "\nTotal Page Faults: " << pageFaults << endl;
}

int main() {
    int referenceString[] = { 1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5 };
    int referenceStringLength = 12;

    int numFrames;
    cout << "Enter the number of free frames: ";
    cin >> numFrames;

    cout << "\nSimulation Output:\n";
    simulateFIFO(referenceString, referenceStringLength, numFrames);

    return 0;
}
