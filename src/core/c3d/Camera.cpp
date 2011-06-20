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

#include "Camera.hpp"
#include "transform3d.hpp"

using hstefan::core::c3d::Camera;
using namespace hstefan::core::math;

Camera::Camera(vec3 eye, vec3 center, vec3 up)
   : m_eye(eye), m_center(center), m_up(up)
{
   initCam();
   createMatrix();
}

void Camera::initCam()
{
   m_forward = normalize(m_center - m_eye);
   m_up = normalize(m_up);
   m_right =  cross(m_forward, m_up);
}

void Camera::createMatrix()
{
   vec3 u = cross(m_right, m_forward);
   float a = dot(m_eye, m_right);
   float b = dot(m_eye, m_forward);
   float c = dot(m_eye, m_up);

   static const mat4d res = {{
      m_right[0]  ,  m_right[1] ,  m_right[2]  ,  -a,
         u[0]     ,      u[1]   ,     u[2]     ,  -c,
      m_forward[0], m_forward[1],  m_forward[2],  -b,
          0       ,       0     ,       0      ,    1
   }};

   m_matrix = res;
}

void Camera::onChange()
{
   createMatrix();
}

void Camera::translate(float tx, float ty, float tz)
{
   m_eye = unhomogen(translationMatrix(tx, ty, tz) * homogen(m_eye));
}

void Camera::yaw(float angle)
{
   rotate(angle, 0.f, 0.f);
}

void Camera::pitch(float angle)
{
   rotate(0.f, angle, 0.f);
}

void Camera::roll(float angle)
{
   rotate(0.f, 0.f, angle);
}

hstefan::core::math::mat4d Camera::matrix() const
{
   return m_matrix;
}

void Camera::rotate(float yaw, float pitch, float roll)
{
   mat4d res = pitchRotationMatrix(pitch)*yawRotationMatrix(yaw)*rollRotationMatrix(roll);
   m_forward = unhomogen(res*homogen(m_forward));
   m_up = unhomogen(res*homogen(m_up));
   m_right = unhomogen(res*homogen(m_right));
   onChange();
}