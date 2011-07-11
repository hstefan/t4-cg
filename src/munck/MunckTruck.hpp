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

#ifndef HSTEFAN_MUNCK_MUNCK_TRUCK_HPP
#define HSTEFAN_MUNCK_MUNCK_TRUCK_HPP

#include "../core/game/GameObject.hpp"
#include "ArmBase.hpp"
#include "../core/math/vector.hpp"

namespace hstefan
{
namespace munck
{

class MunckTruck : public core::game::GameObject
{
public:
   MunckTruck(const core::math::vec3& pbase);

   void onUpdate();
   void onRender();
   void onDestroy();
   void onCreate();

protected:
   enum TruckAction
   {
      MOVE_FORWARD, MOVE_BACKWARD, STEER_LEFT, STEER_RIGHT
   };

   enum ArmAction
   {
      SHRINK, EXPAND
   };
   
   struct Keys
   {
      static const int TRUCK_FORWARD_KEY  = 'W'; 
      static const int TRUCK_BACKWARD_KEY = 'S';
      static const int TRUCK_LEFT_KEY     = 'A';
      static const int TRUCK_RIGHT_KEY    = 'D';

      static const int ARM_BOTTOM_SHRINK = 'J';
      static const int ARM_MIDDLE_SHRINK = 'K';
      static const int ARM_TOP_SHRINK    = 'O';
      static const int ARM_BOTTOM_EXPAND = 'U';
      static const int ARM_MIDDLE_EXPAND = 'I';
      static const int ARM_TOP_EXPAND    = 'L';

   };
private:
   ArmBase arm_base;
   core::math::vec3 pbase;
   core::math::vec3 camera_eye;
};

} //namespace munck
} //namespace hstefan

#endif