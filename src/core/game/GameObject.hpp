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

#ifndef HSTEFAN_CORE_GAME_GAMEOBJECT_HPP
#define HSTEFAN_CORE_GAME_GAMEOBJECT_HPP

#include "GameWorld.hpp"

namespace hstefan
{
namespace core
{
namespace game
{

class GameObject
{
public:
   inline GameObject();
   /**
    * Função chamada a cada ciclo de update no gameworld.
    */
   virtual void onUpdate() = 0;
   /**
    * Função chamada a cada ciclo de render no gameworld.
    */
   virtual void onRender() = 0;
   /**
    * Função chamada quando o gameworld é destruido.
    */
   virtual void onDestroy()
   {/* Por padrão, não faz nada. */ }
   virtual void onCreate()
   {/* Por padrão, não faz nada. */ }
protected:
   friend class GameWorld;
   GameWorld::object_id id;
};

GameObject::GameObject()
   : id(GameWorld::DEFAULT_OBJECT_ID)
{}

} //namespace game
} //namespace core
} //namespace hstefan

#endif