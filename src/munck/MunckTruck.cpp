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

#include "MunckTruck.hpp"

using namespace hstefan::munck;

void MunckTruck::onUpdate()
{
   if(glfwGetKey(Keys::TRUCK_FORWARD_KEY) == GLFW_PRESS) 
      ;
   if(glfwGetKey(Keys::TRUCK_BACKWARD_KEY) == GLFW_PRESS) 
      ;
   if(glfwGetKey(Keys::TRUCK_LEFT_KEY) == GLFW_PRESS) 
      ;
   if(glfwGetKey(Keys::TRUCK_RIGHT_KEY) == GLFW_PRESS) 
      ;

   if(glfwGetKey(Keys::ARM_BOTTOM_EXPAND) == GLFW_PRESS) 
      ;
   if(glfwGetKey(Keys::ARM_BOTTOM_SHRINK) == GLFW_PRESS) 
      ;
   if(glfwGetKey(Keys::ARM_MIDDLE_EXPAND) == GLFW_PRESS) 
      ;
   if(glfwGetKey(Keys::ARM_MIDDLE_SHRINK) == GLFW_PRESS) 
      ;
   if(glfwGetKey(Keys::ARM_TOP_EXPAND) == GLFW_PRESS) 
      ;
   if(glfwGetKey(Keys::ARM_TOP_SHRINK) == GLFW_PRESS) 
      ;
}

void MunckTruck::onRender()
{
   throw std::exception("The method or operation is not implemented.");
}

void MunckTruck::onDestroy()
{
   throw std::exception("The method or operation is not implemented.");
}

void MunckTruck::onCreate()
{
   throw std::exception("The method or operation is not implemented.");
}
