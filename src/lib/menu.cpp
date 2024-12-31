#include <ncurses.h>
#include <iostream>

int displayMenu() {
	initscr(); // Initialize the window
	noecho(); // Don't echo any keypresses
	cbreak(); // Disable line buffering
	keypad(stdscr, TRUE); // Enable function keys

	int choice = 0;
	int highlight = 0;
	const char *choices[] = {
		"1. Create a File",
		"2. Read a File",
		"3. Delete a File",
		"4. Defragment the Disk",
		"5. Display Disk Status",
		"6. Quit"
	};
	int n_choices = sizeof(choices) / sizeof(choices[0]);

	while (true) {
		clear();
		mvprintw(0, 0, "Menu:");
		for (int i = 0; i < n_choices; ++i) {
			if (i == highlight) {
				attron(A_REVERSE); // Highlight the current choice
				mvprintw(i + 1, 0, "%s", choices[i]);
				attroff(A_REVERSE);
			} else {
				mvprintw(i + 1, 0, "%s", choices[i]);
			}
		}
		refresh();

		int c = getch();
		switch (c) {
			case KEY_UP:
				highlight = (highlight == 0) ? n_choices - 1 : highlight - 1;
				break;
			case KEY_DOWN:
				highlight = (highlight == n_choices - 1) ? 0 : highlight + 1;
				break;
			case 10: // Enter key
				choice = highlight + 1;
				break;
			default:
				break;
		}

		if (c == 10) { // Enter key
			switch (choice) {
				case 1:
					// Code to create a file
					mvprintw(n_choices + 1, 0, "Creating a file...");
					return 1;
				case 2:
					// Code to read a file
					mvprintw(n_choices + 1, 0, "Reading a file...");
					return 2;
				case 3:
					// Code to delete a file
					mvprintw(n_choices + 1, 0, "Deleting a file...");
					return 3;
				case 4:
					// Code to defragment the disk
					mvprintw(n_choices + 1, 0, "Defragmenting the disk...");
					return 4;
				case 5:
					// Code to display disk status
					mvprintw(n_choices + 1, 0, "Displaying disk status...");
					return 5;
				case 6:
					// Quit the program
					endwin();
					return 6;
				default:
					mvprintw(n_choices + 1, 0, "Invalid choice. Please try again.");
					break;
			}
			refresh();
			getch(); // Wait for user to press a key
		}
	}
}

