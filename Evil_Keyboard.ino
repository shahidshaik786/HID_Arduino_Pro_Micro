#include <Keyboard.h>

// Define OS types
#define OS_WINDOWS 1
#define OS_LINUX 2
#define OS_MAC 3

// Set the OS here (1 for Windows, 2 for Linux, 3 for macOS)
#define CURRENT_OS OS_WINDOWS

void openCommandPrompt() {
  // Open Command Prompt on Windows
  Keyboard.press(KEY_LEFT_GUI); // Press the Windows key
  Keyboard.press('r');          // Press 'r'
  Keyboard.releaseAll();        // Release all keys
  
  delay(500); // Wait for the Run dialog to open
  
  Keyboard.print("cmd");
  Keyboard.press(KEY_RETURN);   // Press Enter to execute
  Keyboard.releaseAll();        // Release all keys
  
  delay(1000); // Wait for the Command Prompt to open
}

void openTerminal() {
  // Open Terminal on Linux or macOS
  Keyboard.press(KEY_LEFT_GUI); // Press the Windows key
  Keyboard.press('r');          // Press 'r'
  Keyboard.releaseAll();        // Release all keys
  
  delay(500); // Wait for the Run dialog to open
  
  #if CURRENT_OS == OS_LINUX
    // Common commands for opening a terminal on Linux
    Keyboard.print("gnome-terminal");  // GNOME Terminal
    // Keyboard.print("konsole");      // KDE Konsole
    // Keyboard.print("xfce4-terminal"); // Xfce Terminal
  #elif CURRENT_OS == OS_MAC
    Keyboard.print("Terminal"); // Command for macOS Terminal
  #endif
  Keyboard.press(KEY_RETURN);   // Press Enter to execute
  Keyboard.releaseAll();        // Release all keys
  
  delay(1000); // Wait for the Terminal to open
}

void runApplication() {
  // Run a specific application based on OS
  #if CURRENT_OS == OS_WINDOWS
    Keyboard.print("ping 8.8.8.8 -t"); // Open Notepad on Windows
  #elif CURRENT_OS == OS_LINUX
    Keyboard.print("leafpad");  // Open Leafpad on Linux
  #elif CURRENT_OS == OS_MAC
    Keyboard.print("open -a TextEdit"); // Open TextEdit on macOS
  #endif
  Keyboard.press(KEY_RETURN);   // Press Enter to execute
  Keyboard.releaseAll();        // Release all keys
  
  delay(2000); // Wait for the application to open
}

void closeCommandPrompt() {
  // Close Command Prompt on Windows
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press(KEY_F4);
  Keyboard.releaseAll(); // Release all keys
}

void closeTerminal() {
  // Close Terminal on Linux and macOS
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_SHIFT);
  Keyboard.press('w'); // Ctrl+Shift+W is common for closing Terminal on Linux
  Keyboard.releaseAll(); // Release all keys
}

void setup() {
  Keyboard.begin();
  delay(5000); // Wait for the system to recognize the device

  // Open Command Prompt or Terminal based on OS
  #if CURRENT_OS == OS_WINDOWS
    openCommandPrompt();
  #elif CURRENT_OS == OS_LINUX || CURRENT_OS == OS_MAC
    openTerminal();
  #endif

  // Additional delay to ensure the terminal or command prompt is ready
  delay(1000);

  // Run the specified application
  runApplication();

  // Close the Command Prompt or Terminal
  #if CURRENT_OS == OS_WINDOWS
    closeCommandPrompt();
  #elif CURRENT_OS == OS_LINUX || CURRENT_OS == OS_MAC
    closeTerminal();
  #endif

  Keyboard.end();
}

void loop() {
  // Nothing to do here
}
