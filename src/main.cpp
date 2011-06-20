#include <GL/glfw.h>
#include <iostream>

#include "example/WinManagerExample.hpp"

int main(int argc, char* argv[])
{
   static const int WINDOW_WIDTH = 800;
   static const int WINDOW_HEIGHT = 600;
   
   static const int ERR_GLFW_INIT = -1;
   static const int ERR_GLFW_WIN  = -2;

   if(glfwInit() == GL_FALSE)
   {
      std::cerr << "Failed to initialize GLFW." << std::endl;
      return ERR_GLFW_INIT;
   }
   
   glfwOpenWindowHint(GLFW_WINDOW_NO_RESIZE, GL_TRUE);
   
   if(glfwOpenWindow(WINDOW_WIDTH, WINDOW_HEIGHT, 8, 8, 8, 8, 24, 0, GLFW_WINDOW) == GL_FALSE)
   {
      std::cerr << "Failed to open GLFW window." << std::endl;
      return ERR_GLFW_WIN;
   }

   hstefan::example::WinManagerExample m;
   m.run();
}