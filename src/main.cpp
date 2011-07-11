#include <GL/glfw.h>
#include <GL/glut.h>
#include <iostream>

#include "core/game/GameWorld.hpp"
#include "munck/MunckTruck.hpp"
#include <GL/glu.h>
#include "core/math/vector.hpp"

void initOpenGLLighting()
{
   glEnable(GL_LIGHTING);
   glEnable(GL_LIGHT0);
   glEnable(GL_COLOR_MATERIAL);
   glColorMaterial(GL_FRONT,GL_AMBIENT_AND_DIFFUSE);

   GLfloat mat_env[] = {1.f,1.f,1.f,1.f}; //material ambiente.
   GLfloat mat_dif[] = {.7f,.4f,.0f,1.f}; //material difusa.
   GLfloat mat_spe[] = {1.f,1.f,1.f,1.f}; //material especular.
   GLfloat mat_shi = 125.f; //material brilho.

   GLfloat light_pos[] = {10.f,10.f,10.f,1.f}; //posicao da luz.
   GLfloat light_env[] = {.1f,.1f,.1f,1.f}; //luz ambiente.
   GLfloat light_dif[] = {1.f,1.f,1.f,1.f}; //luz difusa.
   GLfloat light_spe[] = {1.f,1.f,1.f,1.f}; //luz especular.

   glMaterialfv(GL_FRONT, GL_AMBIENT, mat_env);
   glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_dif);
   glMaterialfv(GL_FRONT, GL_SPECULAR, mat_spe);
   glMaterialf(GL_FRONT, GL_SHININESS, mat_shi);

   glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
   glLightfv(GL_LIGHT0, GL_AMBIENT, light_env);
   glLightfv(GL_LIGHT0, GL_DIFFUSE, light_dif);
   glLightfv(GL_LIGHT0, GL_SPECULAR, light_spe);
}

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
   glEnable(GL_DEPTH_TEST);
   initOpenGLLighting();
   glutInit(&argc, argv);
   world.run();
}  