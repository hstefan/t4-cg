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

#ifndef HSTEFAN_EXAMPLE_WIN_MANAGER_EXAMPLE_HPP
#define HSTEFAN_EXAMPLE_WIN_MANAGER_EXAMPLE_HPP

#include <iostream>
#include "../core/WinManager.hpp"
#include <GL/glfw.h>

namespace hstefan
{
namespace example
{

class WinManagerExample : public core::WinManager
{
public:
   WinManagerExample()
      : hstefan::core::WinManager(30, 60), ttl(40.)
   {
      start_t = glfwGetTime();
      n_render = 0;
      n_update = 0;
   }
   virtual void onUpdate()
   {
      ++n_update;
   }
   virtual void onRender()
   {
      ++n_render;
   }
   virtual bool isDone()
   {
      return glfwGetTime() - start_t > ttl;
   }
   virtual void onDestroy()
   {
      std::cout << "Renderizou " << n_render << " vezes." << std::endl;
      std::cout << "Atualizou " << n_update << " vezes." << std::endl;
      std::cin.get();
   }
   virtual void onStart()
   {
      start_t = glfwGetTime();
   }
private:
   double start_t;
   unsigned int n_render, n_update;
   const double ttl;
};

} //namespace example
} //namespace hstefan

#endif