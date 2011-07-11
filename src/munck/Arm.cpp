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

#include <cmath>
#include "Arm.hpp"
#include "../core/math/vector.hpp"
#include "../core/c3d/transform3d.hpp"

using hstefan::munck::Arm;
using namespace hstefan::core::math;
using namespace hstefan::core::c3d;
//using hstefan::munck::Piston;

Arm::Arm(float sangle, float length, float min_angle, float max_angle, 
   float rotation_angle)
   : rotation_angle(sangle), length(length), min_angle(min_angle), 
   max_angle(max_angle)
{

}
Arm::Arm(const Arm& arm)
   : rotation_angle(arm.rotation_angle), angle(arm.angle), length(arm.length),
   min_angle(arm.max_angle), max_angle(arm.max_angle)
{}

Arm& Arm::operator=(const Arm& arm)
{
   rotation_angle = arm.getRotationAngle();
   angle = arm.getAngle();
   length = arm.getLength();
   max_angle = arm.max_angle;
   min_angle = arm.min_angle;
   return *this;
}

bool Arm::raise()
{
   vec3 v = piston.pf;
   mat4d m = pitchRotationMatrix(rotation_angle);
   v = unhomogen(m*homogen(v));
   float sz = distance(piston.pi, v);
   if(piston.allowSizeChange(sz))
   {
      angle += rotation_angle;
      piston.pf = v;
      return true;
   }
   return false;
}

bool Arm::lower()
{
   vec3 v = piston.pf;
   mat4d m = pitchRotationMatrix(-rotation_angle);
   v = unhomogen(m*homogen(v));
   float sz = distance(piston.pi, v);
   if(piston.allowSizeChange(sz))
   {
      angle -= rotation_angle;
      piston.pf = v;
      return true;
   }
   return false;
}

float Arm::getRotationAngle() const
{
   return rotation_angle;
}

float Arm::getAngle() const
{
   return angle;
}

float Arm::getLength() const
{
   return length;
}

const Piston& Arm::getPiston() const
{
   return piston;
}
