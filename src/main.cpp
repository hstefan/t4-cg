#include <GL/glfw.h>
#include <GL/glut.h>
#include <iostream>

#include "core/game/GameWorld.hpp"
#include "munck/MunckTruck.hpp"
#include <GL/glu.h>
#include "core/math/vector.hpp"

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
   using namespace hstefan;
   core::game::GameWorld world;
   munck::MunckTruck* truck = new munck::MunckTruck(core::math::makeVec(0, 0, 0));
   world.addObject(truck);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluPerspective(45, (float)WINDOW_WIDTH/WINDOW_HEIGHT, 1, 10000);
   glMatrixMode(GL_MODELVIEW);
   glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
   glutInit(&argc, argv);
   world.run();
}  