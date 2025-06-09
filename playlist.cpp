// Project Description: Linked List Playlist System
// Built a C++ application to manage a music playlist using a doubly linked list, supporting features like adding songs, removing songs, and navigating forward and backward. Designed Song and Playlist classes for efficient node-based operations and implemented search functionality by title or artist. Saved playlist to a CSV file for persistence. (C++, Doubly Linked List, File I/O)

// playlist.cpp
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// Class for a Song (node in the doubly linked list)
class Song {
public:
    string title;
    string artist;
    Song* next;
    Song* prev;
    Song(string t, string a) : title(t), artist(a), next(nullptr), prev(nullptr) {}
};

// Class to manage the playlist using a doubly linked list
class Playlist {
private:
    Song* head;
    Song* tail;
    Song* current; // Tracks current song for navigation
public:
    Playlist() : head(nullptr), tail(nullptr), current(nullptr) {}
    
    // Add a song to the end of the playlist
    void addSong(string title, string artist) {
        Song* newSong = new Song(title, artist);
        if (!head) {
            head = tail = current = newSong;
        } else {
            newSong->prev = tail;
            tail->next = newSong;
            tail = newSong;
        }
        cout << "Added: " << title << " by " << artist << endl;
    }
    
    // Remove a song by title
    void removeSong(string title) {
        Song* temp = head;
        while (temp && temp->title != title) {
            temp = temp->next;
        }
        if (!temp) {
            cout << "Song '" << title << "' not found!" << endl;
            return;
        }
        if (temp == head) {
            head = temp->next;
            if (head) head->prev = nullptr;
        } else if (temp == tail) {
            tail = temp->prev;
            tail->next = nullptr;
        } else {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }
        if (current == temp) current = temp->next ? temp->next : head;
        cout << "Removed: " << temp->title << endl;
        delete temp;
    }
    
    // Search for a song by title or artist
    void searchSong(string query) {
        Song* temp = head;
        bool found = false;
        while (temp) {
            if (temp->title == query || temp->artist == query) {
                cout << "Found: " << temp->title << " by " << temp->artist << endl;
                found = true;
            }
            temp = temp->next;
        }
        if (!found) cout << "No match for '" << query << "' found!" << endl;
    }
    
    // Navigate to the next song
    void nextSong() {
        if (current && current->next) {
            current = current->next;
            cout << "Current: " << current->title << " by " << current->artist << endl;
        } else {
            cout << "No next song!" << endl;
        }
    }
    
    // Navigate to the previous song
    void prevSong() {
        if (current && current->prev) {
            current = current->prev;
            cout << "Current: " << current->title << " by " << current->artist << endl;
        } else {
            cout << "No previous song!" << endl;
        }
    }
    
    // Display the entire playlist
    void display() {
        Song* temp = head;
        if (!temp) {
            cout << "Playlist is empty!" << endl;
            return;
        }
        cout << "Playlist:" << endl;
        while (temp) {
            cout << temp->title << " by " << temp->artist << endl;
            temp = temp->next;
        }
    }
    
    // Save playlist to a CSV file
    void saveToFile(string filename) {
        ofstream file(filename);
        if (!file) {
            cout << "Error opening file!" << endl;
            return;
        }
        Song* temp = head;
        while (temp) {
            file << temp->title << "," << temp->artist << endl;
            temp = temp->next;
        }
        file.close();
        cout << "Playlist saved to " << filename << endl;
    }
    
    // Destructor to free memory
    ~Playlist() {
        Song* temp = head;
        while (temp) {
            Song* next = temp->next;
            delete temp;
            temp = next;
        }
    }
};

// Main function to test the playlist system
int main() {
    Playlist playlist;
    playlist.addSong("Bohemian Rhapsody", "Queen");
    playlist.addSong("Stairway to Heaven", "Led Zeppelin");
    playlist.addSong("Imagine", "John Lennon");
     
    playlist.display();

    playlist.searchSong("Queen");

    playlist.addSong("Hotel California", "Eagles");
    playlist.addSong("Smells Like Teen Spirit", "Nirvana");
    playlist.addSong("Sweet Child O' Mine", "Guns N' Roses");
    playlist.addSong("Like a Rolling Stone", "Bob Dylan");
    playlist.addSong("Hey Jude", "The Beatles");
    playlist.addSong("Purple Haze", "Jimi Hendrix");
    playlist.addSong("Wish You Were Here", "Pink Floyd");
    playlist.addSong("Back in Black", "AC/DC");
   
    playlist.display();

    playlist.nextSong();
    playlist.nextSong();
    playlist.prevSong();
    playlist.removeSong("Stairway to Heaven");
    playlist.removeSong("Back in Black");
    playlist.removeSong("Sweet Child O' Mine");
    playlist.display();
    playlist.saveToFile("playlist.csv");
    return 0;
}