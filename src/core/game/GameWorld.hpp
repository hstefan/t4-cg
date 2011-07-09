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

#ifndef HSTEFAN_CORE_GAME_GAMEWORLD_HPP
#define HSTEFAN_CORE_GAME_GAMEWORLD_HPP

#include <map>
#include "../wman/WinManager.hpp"

namespace hstefan
{
namespace core
{
namespace game
{

class GameObject;

class GameWorld : public wman::WinManager
{
public:
   typedef int object_id;
   
   static const int DEFAULT_OBJECT_ID = -1;

   inline GameWorld(float fps = 30.f, float ups = 60.f);

   bool isDone();
   void onUpdate();
   void onRender();
   void onDestroy();
   void onStart();

   std::pair<object_id, bool> addObject(GameObject* obj);
   bool removeObject(object_id id);
private:
   std::map<object_id, GameObject*> game_objs;
   object_id next_id;
};

GameWorld::GameWorld(float  fps, float ups)
   : wman::WinManager(fps, ups), game_objs(), next_id(0)
{}

} //namespace game
} //namespace core
} //namespace hstefan

#endif