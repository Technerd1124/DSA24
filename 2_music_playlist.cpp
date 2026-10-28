#include <iostream>
#include <string>
using namespace std;

// A song node has a title and links to previous and next songs
struct Song {
    string title;
    Song *prev;
    Song *next;
};

Song *head = nullptr;
Song *tail = nullptr;

// Function to add a new song at the end
void addSong() {
    Song *newSong = new Song();

    cout << "Enter song title: ";
    cin.ignore();
    getline(cin, newSong->title);

    newSong->prev = nullptr;
    newSong->next = nullptr;

    if (head == nullptr) {
        head = newSong;
        tail = newSong;
    } else {
        tail->next = newSong;
        newSong->prev = tail;
        tail = newSong;
    }

    cout << "Song added to playlist.\n";
}

// Function to remove a song by its title
void removeSong() {
    string title;

    if (head == nullptr) {
        cout << "Playlist is empty.\n";
        return;
    }

    cout << "Enter title of song to remove: ";
    cin.ignore();
    getline(cin, title);

    Song *temp = head;

    while (temp != nullptr && temp->title != title) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Song not found.\n";
        return;
    }

    if (temp->prev != nullptr) {
        temp->prev->next = temp->next;
    } else {
        head = temp->next;
    }

    if (temp->next != nullptr) {
        temp->next->prev = temp->prev;
    } else {
        tail = temp->prev;
    }

    delete temp;
    cout << "Song removed from playlist.\n";
}

// Display playlist from first song to last
void displayForward() {
    if (head == nullptr) {
        cout << "Playlist is empty.\n";
        return;
    }

    cout << "Playlist (Forward order):\n";

    Song *temp = head;

    while (temp != nullptr) {
        cout << "-> " << temp->title << "\n";
        temp = temp->next;
    }
}

// Display playlist from last song to first
void displayReverse() {
    if (tail == nullptr) {
        cout << "Playlist is empty.\n";
        return;
    }

    cout << "Playlist (Reverse order):\n";

    Song *temp = tail;

    while (temp != nullptr) {
        cout << "-> " << temp->title << "\n";
        temp = temp->prev;
    }
}

int main() {
    int choice;

    do {
        cout << "\n----- MUSIC PLAYLIST MENU -----\n";
        cout << "1. Add Song\n";
        cout << "2. Remove Song\n";
        cout << "3. Display Playlist (Forward)\n";
        cout << "4. Display Playlist (Reverse)\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";

        cin >> choice;

        switch (choice) {
            case 1: addSong(); break;
            case 2: removeSong(); break;
            case 3: displayForward(); break;
            case 4: displayReverse(); break;
            case 5: cout << "Exiting...\n"; break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
