/**********************************************************************************
 * Copyright (C) 2011 by Hugo Stefan Kaus Puhlmann                                *
 * Permission is hereby granted, free of charge, to any person obtaining a copy   *
 * of this software and associated documentation files (the "Software"), to deal  *
 * in the Software without restriction, including without limitation the rights   *
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell      *
 * copies of the Software, and to permit persons to whom the Software is          * 
 * furnished to do so, subject to the following conditions:                       *
 *                                                                                *
 * The above copyright notice and this permission notice shall be included in     *
 * all copies or substantial portions of the Software.                            *
 *                                                                                *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR     *
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,       *
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE    *
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER         *
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,  *
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN      *
 * THE SOFTWARE.                                                                  *
 *********************************************************************************/
/*
 * Nome: Hugo Stefan Kaus Puhlmann
 * Matricula: 2910182
 */
#include <GL/glfw.h>
#include <GL/glut.h>

#include "MunckTruck.hpp"
#include "../core/math/vector.hpp"
#include <cmath>
#include "../core/c3d/transform3d.hpp"

using namespace hstefan::munck;
using namespace hstefan::core::math;
using namespace hstefan::core::c3d;
using namespace hstefan;

#define M_PI 3.14159265358979323846f

MunckTruck::MunckTruck(const core::math::vec3& pbase)
   : arm_base(2), pbase(pbase), ext_size(0.f), max_ext(400.f)
{
   camera_eye = makeVec(-200.f, 200.f, -800.f);
   Arm a1(60.f, 150.f, 25.f, 90.f);
   Arm a2(30.f, 100.f, 10.f, 60.f);
   arm_base.setArm(0, a1);
   arm_base.setArm(1, a2);
   pf = makeVec(-200.f, 0.f, 0.f);
}

void MunckTruck::onUpdate()
{
   //N�o deu tempo de fazer um caminh�ozinho se movendo como pretendia :(
   if(glfwGetKey(Keys::TRUCK_FORWARD_KEY) == GLFW_PRESS) 
      camera_eye += makeVec(0, 0, 4.f);
   if(glfwGetKey(Keys::TRUCK_BACKWARD_KEY) == GLFW_PRESS) 
      camera_eye -= makeVec(0, 0, 4.f);
   if(glfwGetKey(Keys::TRUCK_LEFT_KEY) == GLFW_PRESS) 
      camera_eye += makeVec(4.f, 0, 0.f);
   if(glfwGetKey(Keys::TRUCK_RIGHT_KEY) == GLFW_PRESS) 
      camera_eye -= makeVec(4.f, 0, 0.f);

   if(glfwGetKey(Keys::ARM_BOTTOM_EXPAND) == GLFW_PRESS) 
      arm_base.raise(0);
   if(glfwGetKey(Keys::ARM_BOTTOM_SHRINK) == GLFW_PRESS) 
      arm_base.lower(0);
   if(glfwGetKey(Keys::ARM_MIDDLE_EXPAND) == GLFW_PRESS) 
      arm_base.raise(1);
   if(glfwGetKey(Keys::ARM_MIDDLE_SHRINK) == GLFW_PRESS) 
      arm_base.lower(1);
   if(glfwGetKey(Keys::ARM_TOP_EXPAND) == GLFW_PRESS) 
   {
      ext_size += 3.5f;
      if(ext_size > max_ext)
         ext_size = max_ext;
   }
   if(glfwGetKey(Keys::ARM_TOP_SHRINK) == GLFW_PRESS) 
   {
      ext_size -= 3.5f;
      if(ext_size < 0.f)
         ext_size = 0.f;
   }
}

void MunckTruck::onRender()
{
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

   //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   gluLookAt(camera_eye[0], camera_eye[1], camera_eye[2], 0, 0, 0, 0, 1, 0);
   
   glPushMatrix(); //desenha base
      glColor3f(0.f/255.f, 234.f/255.f, 0.f/255.f);
      glTranslatef(-0.f, -100.f, 0.f);
      glPushMatrix();
      glScalef(400.f, 50.f, 200.f);
      glutSolidCube(1.f);
   glPopMatrix();

   glTranslatef(100.f, 32.f, 0.f);
   glPushMatrix(); //esfera 1 (rolamento base)
      glColor3f(.7f, .0f, .0f);
      glScalef(14.f, 14.f, 14.f);
      glutSolidSphere(1.0, 30, 30);
   glPopMatrix();
   
   glPushMatrix(); //desenha o ponto de contato com chao do primeiro pistao
      glColor3f(54.f/255.f, 54.f/255.f, 54.f/255.f);
      glTranslatef(pf[0], pf[1], pf[2]);
      glScalef(5.f, 5.f, 5.f);
      glutSolidSphere(1.0, 30, 30);
   glPopMatrix();

   //calculos usados para encontrar novas posicoes de translacao
   float angulo = (arm_base.arms[0].getAngle()*M_PI)/180.f;
   vec3 dir = makeVec(-cos(angulo), sin(angulo), 0.f); //encontra um vetor apontando no mesmo angulo que a base
   vec3 dir2 = makeVec(-sin(angulo), -cos(angulo) , 0.f); //vetor perpendicular
   vec3 pi = dir*100.f; //pi � o ponto onde a outra extremidade do pistao deve ser desenhada
   
   vec3 delta = dir*arm_base.arms[0].getLength();

   glPushMatrix(); //desenha a outra extremidade do pistao
      glColor3f(54.f/255.f, 54.f/255.f, 54.f/255.f);
      glTranslatef(5.f*dir2[0], 5.f*dir2[1], dir2[2]);
      glTranslatef(pi[0], pi[1], pi[2]);
      glScalef(5.f, 5.f, 5.f);
      glutSolidSphere(1.0, 30, 30);
   glPopMatrix();

   glPushMatrix(); //desenha o pistao em si (linha)
      glColor3f(65.f/255.f, 65.f/255.f, 65.f/255.f);
      glLineWidth(20.f);
      glBegin(GL_LINES);
         glVertex3f(pi[0], pi[1], pi[2]);
         glVertex3f(pf[0], pf[1], pf[2]);
      glEnd();
   glPopMatrix();

   glTranslatef(0.f, 7.f, 0.f);
   glPushMatrix(); //desenha o primeiro bra�o
      glColor3f(1.f, 0.f, 0.f);
      glRotatef(90 - arm_base.arms[0].getAngle(), 0.f, 0.f, 1.f);
      glScalef(10.f, arm_base.arms[0].getLength(), 30.f);
      glTranslatef(0.f, .5f, 0.f);
      glutSolidCube(1.f);
   glPopMatrix();
  
   glTranslatef(delta[0], delta[1], 0.f);
   glPushMatrix(); //desenha uma esfera para representar a juncao dos dois bra�os
      glColor3f(.7f, .0f, .0f);
      glScalef(14.f, 14.f, 14.f);
      glutSolidSphere(1.0, 30, 30);
   glPopMatrix();

   //calculos usados para determinar a posicao do pistao 2
   vec3 pi2 = makeVec(0.f, -55.f, 0.f); 
   float angulo2 = (arm_base.arms[1].getAngle()*M_PI)/180.f;
   vec3 dir4 = makeVec(-cos(angulo2), sin(angulo2), 0.f);
   vec3 pf2 = dir4*85.f; 

   glPushMatrix(); //desenha o pistao
      glRotatef(90 - arm_base.arms[0].getAngle(), 0.f, 0.f, 1.f);
      glColor3f(65.f/255.f, 65.f/255.f, 65.f/255.f);
      glLineWidth(10.f);
      glBegin(GL_LINES);
         glVertex3f(pi2[0], pi2[1], pi2[2]);
         glVertex3f(pf2[0], pf2[1], pf2[2]);
      glEnd();
   glPopMatrix();

   vec3 hp = unit(delta)*7.f;
   glTranslatef(hp[0], hp[1], 0.f); //nessario por causa da esfera
   glPushMatrix(); //desenha o segundo bra�o
      glColor3f(1.f, 0.f, 0.f);
      glRotatef(90 - arm_base.arms[0].getAngle(), 0.f, 0.f, 1.f);
      glRotatef(90 - arm_base.arms[1].getAngle(), 0.f, 0.f, 1.f);
      glScalef(10.f, arm_base.arms[1].getLength(), 30.f);
      glTranslatef(0.f, .5f, 0.f);
      glutSolidCube(1.f);
   glPopMatrix();

   glPushMatrix(); //desenha o bra�o extens�vel
      glColor3f(105.f/255.f, 105.f/255.f, 105.f/255.f);
      glRotatef(90.f - arm_base.arms[0].getAngle(), 0.f, 0.f, 1.f);
      glRotatef(90.f - arm_base.arms[1].getAngle(), 0.f, 0.f, 1.f);
      glTranslatef(0.f, arm_base.arms[0].getAngle() + ext_size/2, 0.f);
      glRotatef(90.f, 0.f, 0.f, 1.f);
      glTranslatef(.0f, -4.f, 0.f);
      glScalef(ext_size, 8.f, 10.f);
      glTranslatef(0.f, .5f, 0.f);
      glutSolidCube(1.f);
   glPopMatrix();
   glPopMatrix();
}

void MunckTruck::onDestroy()
{
   //throw std::exception("The method or operation is not implemented.");
}

void MunckTruck::onCreate()
{
   glClearColor(0.f, 0.f, 0.f, 1.f);
}
