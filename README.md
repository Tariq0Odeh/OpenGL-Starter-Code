# [OpenGL-Starter-Code]
---

## Description:
This code is an OpenGL program written in C that demonstrates a moving rectangle animation. It utilizes the GLUT (OpenGL Utility Toolkit) library for handling window creation and event processing. 

The program initializes an OpenGL window with a moving rectangle and a static square. The rectangle moves horizontally across the window and vertically downward when reaching the right edge. The square and text remain stationary.

Key functions include:
- `startOpenGl()`: Initializes the OpenGL window and sets up callback functions.
- `display()`: Clears the screen and renders the moving rectangle, square, and text.
- `timer()`: Updates the position of the moving rectangle and triggers screen redrawing.
- `rectangle()`, `drawSquare()`, `drawText_size()`: Functions to draw shapes and text on the screen.
- `reshape()`, `init()`: Functions for OpenGL setup and window resizing.
---
## How to Run

To run this OpenGL program, follow these steps:
1. **Install OpenGL**: First, ensure you have OpenGL installed on your system. Refer to the [openGL_install.txt](openGL_install.txt) file for detailed installation instructions.
2. **Install Makefile**: If you haven't already, make sure you have a Makefile installed. If not, you can find one suitable for your system or development environment.
3. **Install the Code**: Clone or download this repository to your local machine.
4. **Compile the Code**: Open a terminal and navigate to the directory containing the code. Run the following command to compile the code using the Makefile:
   ```bash
   make
5. **Run the Program**: After compiling successfully, execute the program by running the following command in the terminal: 
   ```bash
   ./parent

---
## Languages And Tools:

-  <img align="left" alt="OpenGL" width="50px" src="https://upload.wikimedia.org/wikipedia/commons/e/e9/Opengl-logo.svg" /> 

<br/>
