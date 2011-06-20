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
#ifndef HSTEFAN_CORE_CAMERA_C3D_HPP
#define HSTEFAN_CORE_CAMERA_C3D_HPP

#include "../math/vector.hpp"

namespace hstefan
{
namespace core
{
namespace c3d
{
using hstefan::core::math::vec3;
using hstefan::core::math::mat4d;
class Camera
{
public:
   Camera(math::vec3 eye, math::vec3 center, math::vec3 up);

   void translate(float tx, float ty, float tz);
   void yaw(float angle);
   void pitch(float angle);
   void roll(float angle);
   void rotate(float yaw, float pitch, float roll);

   mat4d matrix() const;
private:
   void initCam();
   void createMatrix();
   void onChange();

   math::vec3 m_eye;
   math::vec3 m_center;
   math::vec3 m_up;
   math::vec3 m_forward;
   math::vec3 m_right;
   math::mat4d m_matrix;
};

} //namespace c3d
} //namespace core
} //namespace hstefan

#endif