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

#include "WinManager.hpp"

#include <algorithm>
#include <GL/glfw.h>

using hstefan::core::wman::WinManager;

WinManager::WinManager(float fps, float ups)
   : fps(1./fps), ups(1./ups)
{}

void WinManager::run()
{
   double last_update = 0.;
   double last_render = 0.;
   double sleep_t = 0.;
   onStart();
   while(!isDone() && glfwGetWindowParam(GLFW_OPENED))
   {
      if(glfwGetTime() - last_update > ups)
      {
         onUpdate();
         last_update = glfwGetTime();
      }
      if(glfwGetTime() - last_render > fps)
      {
         glClear(GL_COLOR_BUFFER_BIT);
         onRender();
         glfwSwapBuffers();
         last_render = glfwGetTime();
      }
      sleep_t = std::min(last_update + ups - glfwGetTime(), last_render + fps - glfwGetTime());
      glfwSleep(sleep_t);
   }
   onDestroy();
   glfwTerminate();
}