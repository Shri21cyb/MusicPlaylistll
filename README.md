# Music Playlist System 

This project implements a **doubly linked list** to manage and traverse songs in a simple console-based music system.

## Class Structure

### `Song` Class
Represents each song in the playlist.
- `title`: The title of the song.
- `artist`: The artist of the song.
- `next`: Pointer to the next song.
- `prev`: Pointer to the previous song.

### `Playlist` Class
Manages the overall playlist.
- `head`: First song in the playlist.
- `last`: Last song in the playlist.
- `current`: Currently selected song.

## 🔧 Features

The `Playlist` class supports the following methods:

- `addSong(title, artist)` – Adds a new song to the end of the playlist.
- `removeSong(title)` – Removes a song by its title.
- `searchSong(title)` – Searches for a song by title.
- `nextSong()` – Moves to the next song.
- `prevSong()` – Moves to the previous song.
- `display()` – Displays the complete playlist.
- `saveToFile(filename)` – Saves the playlist to a CSV file.

## ✨ Additional Features

- Handles edge cases like navigating or removing songs in an empty list.
- Uses a **doubly linked list** for smooth bidirectional traversal.
- **CSV export** allows saving the playlist for future use.
- Built using **Object-Oriented Programming (OOP)** principles.
- Easily extendable with features like shuffle, repeat, or file-based import.

---

Feel free to contribute or suggest improvements! 🎧
