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

#include "GameWorld.hpp"
#include "GameObject.hpp"
#include <algorithm>
#include <GL/glfw.h>

using hstefan::core::game::GameWorld;
using hstefan::core::game::GameObject;

bool GameWorld::isDone()
{
   return glfwGetKey(GLFW_KEY_ESC) == GLFW_PRESS;
}

void GameWorld::onUpdate()
{
   std::for_each(game_objs.begin(), game_objs.end(), 
      [](std::pair<object_id, GameObject*> p) { p.second->onUpdate(); } );
}

void GameWorld::onRender()
{
   std::for_each(game_objs.begin(), game_objs.end(), 
      [](std::pair<object_id, GameObject*> p) { p.second->onRender(); } );
}
void GameWorld::onDestroy()
{
   std::for_each(game_objs.begin(), game_objs.end(), 
      [](std::pair<object_id, GameObject*> p) { p.second->onDestroy(); } );
}
void GameWorld::onStart()
{
   std::for_each(game_objs.begin(), game_objs.end(), 
      [](std::pair<object_id, GameObject*> p) { p.second->onCreate(); } );
}

std::pair<GameWorld::object_id, bool> GameWorld::addObject(GameObject* obj)
{
   int id = next_id++;
   auto r = game_objs.insert(std::make_pair(id, obj));
   if(r.second)
   {
      obj->id = id;
      return std::make_pair(id, true);
   }
   else
   {
      --next_id;
      return std::make_pair(DEFAULT_OBJECT_ID, false);
   }
}

bool GameWorld::removeObject(object_id id)
{
   return game_objs.erase(id) > 0;
}