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

using namespace hstefan::munck;
using namespace hstefan::core::math;
using namespace hstefan;

#define M_PI 3.14159265358979323846

MunckTruck::MunckTruck(const core::math::vec3& pbase)
   : arm_base(2), pbase(pbase)
{
   vec3 fdir = makeVec(cos(M_PI/4), sin(M_PI/4), 0.f);
   vec3 sdir = makeVec(cos(M_PI/6), sin(M_PI/6), 0.f);
   float len = 150.f;
   
   vec3 pi_a = pbase + makeVec(100.f, 0.f, 0.f);
   vec3 pf_a = pbase + fdir*(len/3);
   Piston p1(pi_a, pf_a, 50.f, 100.f);
   Arm a1(M_PI/4, len, p1);
   arm_base.setArm(0, a1);

   vec3 pi_b = pbase + fdir*len/2.f;
   vec3 pf_b = pi_b + sdir*len/3;
   Piston p2(pi_b, pf_b, 50.f, 100.f);
   Arm a2(M_PI/6, len, p2);
   arm_base.setArm(1, a2);
}

void MunckTruck::onUpdate()
{
   //Não deu tempo de fazer um caminhãozinho se movendo como pretendia :(
   /*if(glfwGetKey(Keys::TRUCK_FORWARD_KEY) == GLFW_PRESS) 
      ;
   if(glfwGetKey(Keys::TRUCK_BACKWARD_KEY) == GLFW_PRESS) 
      ;
   if(glfwGetKey(Keys::TRUCK_LEFT_KEY) == GLFW_PRESS) 
      ;
   if(glfwGetKey(Keys::TRUCK_RIGHT_KEY) == GLFW_PRESS) 
      ;*/

   if(glfwGetKey(Keys::ARM_BOTTOM_EXPAND) == GLFW_PRESS) 
      arm_base.raise(0);
   if(glfwGetKey(Keys::ARM_BOTTOM_SHRINK) == GLFW_PRESS) 
      arm_base.lower(0);
   if(glfwGetKey(Keys::ARM_MIDDLE_EXPAND) == GLFW_PRESS) 
      arm_base.raise(1);
   if(glfwGetKey(Keys::ARM_MIDDLE_SHRINK) == GLFW_PRESS) 
      arm_base.lower(1);
   if(glfwGetKey(Keys::ARM_TOP_EXPAND) == GLFW_PRESS) 
      ;
   if(glfwGetKey(Keys::ARM_TOP_SHRINK) == GLFW_PRESS) 
      ;
}

void MunckTruck::onRender()
{
   glPushMatrix();
   glutSolidCube(100.f);
}

void MunckTruck::onDestroy()
{
   //throw std::exception("The method or operation is not implemented.");
}

void MunckTruck::onCreate()
{
}
