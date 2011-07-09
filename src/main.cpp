#include <GL/glfw.h>
#include <iostream>

#include "core/game/GameWorld.hpp"
#include "core/game/shapes/Cube.hpp"
#include <GL/glu.h>

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
   
   hstefan::core::game::shapes::Cube* c = new hstefan::core::game::shapes::Cube(0.f, 0.f, 0.f,
      100.f, 100.f, 200.f);
   hstefan::core::game::GameWorld world;
   world.addObject(c);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluPerspective(45, WINDOW_WIDTH/WINDOW_HEIGHT, 1, 1000);
   glMatrixMode(GL_MODELVIEW);
   glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
   gluLookAt(-200.f, 200.f, 800, 0, 0, 0, 0, 1, 0);
   world.run();
}  