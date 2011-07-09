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

#ifndef HSTEFAN_CORE_GAME_SHAPES_CUBE_HPP
#define HSTEFAN_CORE_GAME_SHAPES_CUBE_HPP

#include "../GameObject.hpp"
#include "../../math/vector.hpp"

namespace hstefan {
namespace core {
namespace game {
namespace shapes {

/**
 * Creates an 1x1x1 cube.
 */
class Cube : public GameObject
{
public:
   /**
    * @param wx X center.
    * @param wy Y center.
    * @param wz Z center.
    * @param sx X size.
    * @param sy Y size.
    * @param sy Z size.
    */
   Cube(float wx, float wy, float wz, float sx, float sy, float sz);

   void onUpdate();
   virtual void onRender();

   const float wx, wy, wz;
   const float sx, sy, sz;
   
   static const hstefan::core::math::vec3 v[8];
   static const int v_i[36];
};

} //namespace forms
} //namespace game
} //namespace core
} //namespace hstefan
#endif