#include <iostream>
#include <string>

using namespace std;

// Node class for Music Playlist
class Node {
public:
    string songTitle;
    string artistName;

    Node* prev;
    Node* next;

    // Constructor
    Node(string title, string artist) {
        songTitle = title;
        artistName = artist;
        prev = nullptr;
        next = nullptr;
    }
};


// Music Playlist Manager using Doubly Linked List
class MusicPlaylist {
private:
    Node* head;       // head points to the first song
    Node* current;    // current points to the current song

public:

    // Constructor
    MusicPlaylist() {
        head = nullptr;
        current = nullptr;
    }


    // 1. Add Song
    void addSong(string title, string artist) {

        // p points to the newly created node
        Node* p = new Node(title, artist);

        // If playlist is empty
        if (head == nullptr) {
            head = p;
            current = p;

            cout << "\nSong added successfully!\n";
            return;
        }

        // q is used for traversal
        Node* q = head;

        // Move q to the last node
        while (q->next != nullptr) {
            q = q->next;
        }

        // Connect new node
        q->next = p;
        p->prev = q;

        cout << "\nSong added successfully!\n";
    }


    // 2. Delete Song
    void deleteSong(string title) {

        if (head == nullptr) {
            cout << "\nPlaylist is empty!\n";
            return;
        }

        // q is used to search the song
        Node* q = head;

        while (q != nullptr) {

            if (q->songTitle == title) {

                // p points to the node to be deleted
                Node* p = q;

                // Case 1: Delete first song
                if (p == head) {

                    head = p->next;

                    if (head != nullptr) {
                        head->prev = nullptr;
                    }

                    // If current was the deleted song
                    if (current == p) {
                        current = head;
                    }

                    delete p;

                    cout << "\nSong deleted successfully!\n";
                    return;
                }


                // Case 2: Delete middle or last song

                if (p->prev != nullptr) {
                    p->prev->next = p->next;
                }

                if (p->next != nullptr) {
                    p->next->prev = p->prev;
                }

                // If current was the deleted song
                if (current == p) {

                    if (p->next != nullptr) {
                        current = p->next;
                    }
                    else {
                        current = p->prev;
                    }
                }

                delete p;

                cout << "\nSong deleted successfully!\n";
                return;
            }

            q = q->next;
        }

        cout << "\nSong not found!\n";
    }


    // 3. Display Playlist Forward
    void displayPlaylist() {

        if (head == nullptr) {
            cout << "\nPlaylist is empty!\n";
            return;
        }

        Node* q = head;

        cout << "\n========== PLAYLIST ==========\n";

        int number = 1;

        while (q != nullptr) {

            cout << number << ". "
                 << q->songTitle
                 << " - "
                 << q->artistName;

            if (q == current) {
                cout << " <-- CURRENT";
            }

            cout << endl;

            q = q->next;
            number++;
        }

        cout << "==============================\n";
    }


    // 4. Display Playlist in Reverse
    void displayReverse() {

        if (head == nullptr) {
            cout << "\nPlaylist is empty!\n";
            return;
        }

        // q starts from head
        Node* q = head;

        // Move q to last node
        while (q->next != nullptr) {
            q = q->next;
        }

        cout << "\n====== REVERSE PLAYLIST ======\n";

        int number = 1;

        // Traverse backwards using prev
        while (q != nullptr) {

            cout << number << ". "
                 << q->songTitle
                 << " - "
                 << q->artistName;

            if (q == current) {
                cout << " <-- CURRENT";
            }

            cout << endl;

            q = q->prev;
            number++;
        }

        cout << "==============================\n";
    }


    // 5. Play Current Song
    void playCurrentSong() {

        if (current == nullptr) {
            cout << "\nPlaylist is empty!\n";
            return;
        }

        cout << "\nNow Playing: "
             << current->songTitle
             << " - "
             << current->artistName
             << endl;
    }


    // 6. Play Next Song
    void playNextSong() {

        if (current == nullptr) {
            cout << "\nPlaylist is empty!\n";
            return;
        }

        if (current->next == nullptr) {
            cout << "\nAlready at the last song!\n";
            cout << "No next song available.\n";
            return;
        }

        // Move current to next song
        current = current->next;

        cout << "\nNext Song: "
             << current->songTitle
             << " - "
             << current->artistName
             << endl;
    }


    // 7. Play Previous Song
    void playPreviousSong() {

        if (current == nullptr) {
            cout << "\nPlaylist is empty!\n";
            return;
        }

        if (current->prev == nullptr) {
            cout << "\nAlready at the first song!\n";
            cout << "No previous song available.\n";
            return;
        }

        // Move current to previous song
        current = current->prev;

        cout << "\nPrevious Song: "
             << current->songTitle
             << " - "
             << current->artistName
             << endl;
    }


    // 8. Play Complete Playlist
    void playCompletePlaylist() {

        if (head == nullptr) {
            cout << "\nPlaylist is empty!\n";
            return;
        }

        // Start from first song
        current = head;

        Node* q = head;

        cout << "\n====== PLAYING COMPLETE PLAYLIST ======\n";

        while (q != nullptr) {

            cout << "Playing: "
                 << q->songTitle
                 << " - "
                 << q->artistName
                 << endl;

            current = q;

            q = q->next;
        }

        cout << "=======================================\n";
    }


    // 9. Repeat All
    void repeatAll() {

        if (head == nullptr) {
            cout << "\nPlaylist is empty!\n";
            return;
        }

        int repetitions;

        cout << "\nEnter number of repetitions: ";
        cin >> repetitions;

        if (repetitions <= 0) {
            cout << "\nInvalid number of repetitions!\n";
            return;
        }

        for (int i = 1; i <= repetitions; i++) {

            // Restart from first song
            current = head;

            Node* q = head;

            cout << "\nRepetition " << i << ":\n";

            while (q != nullptr) {

                cout << "Playing: "
                     << q->songTitle
                     << " - "
                     << q->artistName
                     << endl;

                current = q;

                q = q->next;
            }
        }
    }


    // 10. Show Current Song
    void showCurrentSong() {

        if (current == nullptr) {
            cout << "\nNo current song.\n";
            return;
        }

        cout << "\nCurrent Song: "
             << current->songTitle
             << " - "
             << current->artistName
             << endl;
    }


    // Destructor
    ~MusicPlaylist() {

        Node* q = head;

        while (q != nullptr) {

            Node* p = q;

            q = q->next;

            delete p;
        }

        head = nullptr;
        current = nullptr;
    }
};


// Display menu
void displayMenu() {

    cout << "\n\n========================================\n";
    cout << "       MUSIC PLAYLIST MANAGER\n";
    cout << "========================================\n";

    cout << "1. Add Song\n";
    cout << "2. Delete Song\n";
    cout << "3. Display Playlist\n";
    cout << "4. Display Playlist in Reverse\n";
    cout << "5. Play Current Song\n";
    cout << "6. Play Next Song\n";
    cout << "7. Play Previous Song\n";
    cout << "8. Play Complete Playlist\n";
    cout << "9. Repeat All\n";
    cout << "10. Show Current Song\n";
    cout << "11. Exit\n";

    cout << "========================================\n";
    cout << "Enter your choice: ";
}


// Main function
int main() {

    MusicPlaylist playlist;

    int choice;

    string title;
    string artist;

    do {

        displayMenu();

        cin >> choice;

        cin.ignore();

        switch (choice) {

        case 1:

            cout << "\nEnter Song Title: ";
            getline(cin, title);

            cout << "Enter Artist Name: ";
            getline(cin, artist);

            playlist.addSong(title, artist);

            break;


        case 2:

            cout << "\nEnter Song Title to Delete: ";
            getline(cin, title);

            playlist.deleteSong(title);

            break;


        case 3:

            playlist.displayPlaylist();

            break;


        case 4:

            playlist.displayReverse();

            break;


        case 5:

            playlist.playCurrentSong();

            break;


        case 6:

            playlist.playNextSong();

            break;


        case 7:

            playlist.playPreviousSong();

            break;


        case 8:

            playlist.playCompletePlaylist();

            break;


        case 9:

            playlist.repeatAll();

            break;


        case 10:

            playlist.showCurrentSong();

            break;


        case 11:

            cout << "\nExiting Music Playlist Manager...\n";
            cout << "Thank you!\n";

            break;


        default:

            cout << "\nInvalid choice! Please try again.\n";
        }

    } while (choice != 11);


    return 0;
}

