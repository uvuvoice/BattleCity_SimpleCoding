#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
using namespace std;

int g_windowSizeX = 640;
int g_windowSizeY = 480;

/* Processing new scale of window */
void glfwWindowSizeCallback(GLFWwindow* pWindow, int width, int height)
{
  g_windowSizeX = width;
  g_windowSizeY = height;

  /* Converting old coordinates to new coordinates */
  /* Drawing in some part of the window */
  glViewport(0, 0, g_windowSizeX, g_windowSizeY);
}

/* Processing keystrokes*/
void glfwKeyCallback(GLFWwindow* pWindow, int key, int scancode, int action, int mode)
{
  if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
  {
    /* Setting the flag to true */
    /* Exit the loop later and close the window */
    glfwSetWindowShouldClose(pWindow, GL_TRUE);
  }
}

int main(void)
{  
  /* Initialize the library glfw */
  if (!glfwInit())  
  {
    cout << "glfwInit failed" << endl;
    return -1;
  }

  /* Settings */
  /* Target OpenGL verion 4.6, if it less then 4 or 6 - it can't create the window */
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  
  /* Create a windowed mode window and its OpenGL context */
  /* 640, 480 - scale the window (width and height) */
  /* Battle City - the name of window (title) */
  /* GLFWmonitor* monitor ??? */
  /* GLFWwindow* share ??? */
  GLFWwindow *pWindow = glfwCreateWindow(g_windowSizeX, g_windowSizeY, "Battle City", nullptr, nullptr);

  /* Checking the success of window creation */
  if (!pWindow)
  {
    cout << "glfwCreateWindow failed" << endl;
    glfwTerminate();
    return -1;
  }

  /* Our callback registration */
  glfwSetWindowSizeCallback(pWindow, glfwWindowSizeCallback);
  glfwSetKeyCallback(pWindow, glfwKeyCallback);
  
  /* Make the window's context to current window (pointer) */
  /* Each window can have its own context */
  glfwMakeContextCurrent(pWindow);
	
  /* Initializing the glad library */
	if(!gladLoadGL())
	{
		cout << "Can't load GLAD" << endl;
		return -1;
	}
	
  /* Information about OpenGL from the driver */
  /* Renderer - video card */
  cout << "Renderer: " << glGetString(GL_RENDERER) << endl;
  cout << "OpenGL version: " << glGetString(GL_VERSION) << endl;
	
	glClearColor(1,1,0,1);

  ///////////////////////////////////////////////////////////////////////

  /* Main loop until the user closes the window */
  /* Main rendeing */

  /* What we can do: 
     1 - Clearing the window 
     2 - Drawing a new buffer 
     3 - Handling user actions 
  */

  while (!glfwWindowShouldClose(pWindow))
  {
    /* 1- glClear - clearing the buffer of color */
    glClear(GL_COLOR_BUFFER_BIT);

    /* 2 - Swap front and back buffers - double buffering */
    glfwSwapBuffers(pWindow);

    /* 3 - Poll for and process user events */
    glfwPollEvents();
  }

  /* Termination of work - clearing all resources */
  glfwTerminate();
  return 0;
}