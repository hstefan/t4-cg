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

#include "Cube.hpp"
#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN 1
#include <windows.h>
#endif
#include <GL/gl.h>

using hstefan::core::game::shapes::Cube;

const hstefan::core::math::vec3 Cube::v[8] = { {{-0.5f, 0.5f, 0.5f}}, 
   {{0.5f, 0.5f, 0.5f}}, {{0.5f, -0.5f, 0.5f}}, 
   {{-0.5f, -0.5f, 0.5f}}, {{-0.5f, 0.5f, -0.5f}}, 
   {{0.5f, 0.5f, -0.5f}}, {{0.5f, -0.5f, -0.5f}}, 
   {{-0.5f, -0.5f, -0.5f}} };
const int Cube::v_i[36] = {0, 1, 2, 2, 3, 0, 0, 4, 7, 7, 3, 0, 0, 4, 5, 5, 
   1, 4, 4, 5, 6, 6, 7, 4, 7, 2, 3, 7, 6, 2, 2, 1, 5, 5, 6, 1};

Cube::Cube(float wx, float wy, float wz, float sx, float sy, float sz)
   : wx(wx), wy(wy), wz(wz), sx(sx), sy(sy), sz(sz)
{

}

void Cube::onUpdate()
{
}

void Cube::onRender()
{
   glPushMatrix();
   glTranslatef(wx, wy, wz);
   glScalef(sx, sy, sz);
   glColor3f(1.f, 0.f, 0.f);
   glBegin(GL_TRIANGLES);
      for(int i = 0; i < 36; ++i) 
         glVertex3f(v[v_i[i]][0], v[v_i[i]][1], v[v_i[i]][2]);
   glEnd();
   glPopMatrix();
}
