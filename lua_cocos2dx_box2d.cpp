#include "lua_cocos2dx_box2d.hpp"
#include "Box2D/Box2D.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"
#include "LuaScriptHandlerMgr.h"
#include "CCLuaEngine.h"
#include "CCLuaValue.h"

#include "Box2D/Box2D.h"
#include <Box2D/Dynamics/Contacts/b2Contact.h>
#include <Box2D/Dynamics/Contacts/b2CircleContact.h>
#include <Box2D/Dynamics/Contacts/b2PolygonAndCircleContact.h>
#include <Box2D/Dynamics/Contacts/b2PolygonContact.h>
#include <Box2D/Dynamics/Contacts/b2EdgeAndCircleContact.h>
#include <Box2D/Dynamics/Contacts/b2EdgeAndPolygonContact.h>
#include <Box2D/Dynamics/Contacts/b2ChainAndCircleContact.h>
#include <Box2D/Dynamics/Contacts/b2ChainAndPolygonContact.h>
#include <Box2D/Dynamics/Contacts/b2ContactSolver.h>
#include <Box2D/Collision/b2Collision.h>
#include <Box2D/Collision/b2TimeOfImpact.h>
#include <Box2D/Collision/Shapes/b2Shape.h>
#include <Box2D/Common/b2BlockAllocator.h>
#include <Box2D/Dynamics/b2Body.h>
#include <Box2D/Dynamics/b2Fixture.h>
#include <Box2D/Dynamics/b2World.h>
#include <Box2D/Dynamics/b2Island.h>
#include <Box2D/Dynamics/Joints/b2PulleyJoint.h>
#include <Box2D/Dynamics/Contacts/b2Contact.h>
#include <Box2D/Dynamics/Contacts/b2ContactSolver.h>
#include <Box2D/Collision/b2BroadPhase.h>
#include <Box2D/Collision/Shapes/b2CircleShape.h>
#include <Box2D/Collision/Shapes/b2EdgeShape.h>
#include <Box2D/Collision/Shapes/b2ChainShape.h>
#include <Box2D/Collision/Shapes/b2PolygonShape.h>
#include <Box2D/Rope/b2Rope.h>




/* new_local function: new world of class  b2World */
int lua_cocos2dx_b2world_new00_local(lua_State *tolua_S)
{
    int argc = 0;
    b2World *cobj = nullptr;
    bool ok = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

    cobj = (b2World *)tolua_tousertype(tolua_S, 1, 0);

    argc = lua_gettop(tolua_S) - 1;
    do
    {
        if (argc == 1)
        {
            const b2Vec2 *arg0 = ((const b2Vec2 *)tolua_tousertype(tolua_S, 2, 0));
            ok &= luaval_is_usertype(tolua_S, 2, "const b2Vec2", 1);

            if (!ok)
            {
                tolua_error(tolua_S, "invalid arguments in function 'lua_cocos2dx_b2world_new00_local', was expecting 'b2Vec2'", nullptr);
                return 0;
            }
            b2World *ret = new b2World(*arg0);
            object_to_luaval<b2World>(tolua_S, "b2World", (b2World *)ret);
            tolua_register_gc(tolua_S, lua_gettop(tolua_S));
            return 1;
        }
    } while (0);
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2World:new", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_cocos2dx_b2world_new00_local'.", &tolua_err);
#endif
    return 0;
}

/* new_local function: x of class b2World */
#ifndef TOLUA_DISABLE_lua_LuaBox2D_b2World_delete
int lua_LuaBox2D_b2World_delete(lua_State *tolua_S)
{
    int argc = 0;
    b2World *cobj = nullptr;
    bool ok = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2World", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2World *)tolua_tousertype(tolua_S, 1, 0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_LuaBox2D_b2World_delete'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S) - 1;
    do
    {
        if (argc == 0)
        {
            delete cobj;
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2World:delete", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2World_delete'.", &tolua_err);
#endif
    return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* new_local function: x of class b2World */
#ifndef TOLUA_DISABLE_tolua_LuaBox2D_b2World_SetDestructionListener
int lua_LuaBox2D_b2World_SetDestructionListener(lua_State *tolua_S)
{
    int argc = 0;
    b2World *cobj = nullptr;
    bool ok = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2World", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2World *)tolua_tousertype(tolua_S, 1, 0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2World_SetDestructionListener'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S) - 1;
    do
    {
        if (argc == 1)
        {
            // b2DestructionListener* listener = ((b2DestructionListener*)  tolua_tousertype(tolua_S,2,0));
            b2DestructionListener *listener;
            ok &= luaval_to_object<b2DestructionListener>(tolua_S, 2, "b2DestructionListener", &listener);

            if (!ok)
            {
                tolua_error(tolua_S, "invalid arguments in function 'tolua_LuaBox2D_b2World_SetDestructionListener', was expecting 'b2DestructionListener'", nullptr);
                return 0;
            }
            cobj->SetDestructionListener(listener);
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2World:SetDestructionListener", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2World_SetDestructionListener'.", &tolua_err);
#endif
    return 0;
}
#endif //#ifndef TOLUA_DISABLE

#ifndef TOLUA_DISABLE_tolua_LuaBox2D_b2World_SetContactFilter
int tolua_LuaBox2D_b2World_SetContactFilter(lua_State *tolua_S)
{
    int argc = 0;
    b2World *cobj = nullptr;
    bool ok = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2World", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2World *)tolua_tousertype(tolua_S, 1, 0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2World_SetContactFilter'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S) - 1;
    do
    {
        if (argc == 1)
        {
            // b2ContactFilter* arg0 = ((b2ContactFilter*) tolua_tousertype(tolua_S, 2, 0));
            b2ContactFilter *arg0;
            ok &= luaval_to_object<b2ContactFilter>(tolua_S, 2, "b2ContactFilter", &arg0);
            if (!ok)
            {
                tolua_error(tolua_S, "invalid arguments in function 'tolua_LuaBox2D_b2World_SetContactFilter', was expecting 'b2ContactFilter'", nullptr);
                return 0;
            }

            cobj->SetContactFilter((b2ContactFilter *)arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2World:SetContactFilter", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2World_SetContactFilter'.", &tolua_err);
#endif
    return 0;
}
#endif //#ifndef TOLUA_DISABLE

#ifndef TOLUA_DISABLE_tolua_LuaBox2D_b2World_SetContactListener
int tolua_LuaBox2D_b2World_SetContactListener(lua_State *tolua_S)
{
    int argc = 0;
    b2World *cobj = nullptr;
    bool ok = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2World", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2World *)tolua_tousertype(tolua_S, 1, 0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2World_SetContactListener'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S) - 1;
    do
    {
        if (argc == 1)
        {
            b2ContactListener *listener;
            ok &= luaval_to_object<b2ContactListener>(tolua_S, 2, "b2ContactListener", &listener);
            if (!ok)
            {
                tolua_error(tolua_S, "invalid arguments in function 'tolua_LuaBox2D_b2World_SetContactListener', was expecting b2ContactListener", nullptr);
                return 0;
            }

            cobj->SetContactListener(listener);
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2World:SetContactListener", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2World_SetContactListener'.", &tolua_err);
#endif
    return 0;
}
#endif //#ifndef TOLUA_DISABLE

#ifndef TOLUA_DISABLE_lua_LuaBox2D_b2World_SetDebugDraw
int lua_LuaBox2D_b2World_SetDebugDraw(lua_State *tolua_S)
{
    int argc = 0;
    b2World *cobj = nullptr;
    bool ok = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2World", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2World *)tolua_tousertype(tolua_S, 1, 0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_LuaBox2D_b2World_SetDebugDraw'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    do
    {
        if (argc == 1)
        {
            // b2Draw* arg0 = ((b2Draw*) tolua_tousertype(tolua_S, 2, 0));
            b2Draw *arg0;
            ok &= luaval_to_object<b2Draw>(tolua_S, 2, "b2Draw", &arg0);
            if (!ok)
            {
                tolua_error(tolua_S, "invalid arguments in function 'lua_LuaBox2D_b2World_SetDebugDraw', was expecting b2Draw", nullptr);
                return 0;
            }
            cobj->SetDebugDraw(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2World:SetDebugDraw", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2World_SetDebugDraw'.", &tolua_err);
#endif
    return 0;
}
#endif

#ifndef TOLUA_DISABLE_lua_LuaBox2D_b2World_CreateBody
int lua_LuaBox2D_b2World_CreateBody(lua_State *tolua_S)
{
    int argc = 0;
    b2World *cobj = nullptr;
    bool ok = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2World", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2World *)tolua_tousertype(tolua_S, 1, 0);

    argc = lua_gettop(tolua_S) - 1;
    do
    {
        if (argc == 1)
        {
            // const b2BodyDef* arg0 = ((const b2BodyDef*)  tolua_tousertype(tolua_S,2,0));
            const b2BodyDef *arg0;
            ok &= luaval_to_object<const b2BodyDef>(tolua_S, 2, "const b2BodyDef", &arg0);
            if (!ok)
            {
                tolua_error(tolua_S, "invalid arguments in function 'lua_LuaBox2D_b2World_CreateBody', was expecting b2BodyDef", nullptr);
                return 0;
            }
            b2Body *ret = (b2Body *)cobj->CreateBody((const b2BodyDef *)arg0);
            object_to_luaval<b2Body>(tolua_S, "b2Body", (b2Body *)ret);
            return 1;
        }
    } while (0);
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2World:SetDebugDraw", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2World_CreateBody'.", &tolua_err);
#endif
    return 0;
}
#endif

#ifndef TOLUA_DISABLE_lua_lua_LuaBox2D_b2World_DestroyBody
int lua_LuaBox2D_b2World_DestroyBody(lua_State *tolua_S)
{
    int argc = 0;
    b2World *cobj = nullptr;
    bool ok = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2World", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2World *)tolua_tousertype(tolua_S, 1, 0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_LuaBox2D_b2World_DestroyBody'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    do
    {
        if (argc == 1)
        {
            b2Body *arg0;
            ok &= luaval_to_object<b2Body>(tolua_S, 2, "b2Body", &arg0);
            if (!ok)
            {
                tolua_error(tolua_S, "invalid arguments in function 'lua_LuaBox2D_b2World_DestroyBody', was expecting b2Body", nullptr);
                return 0;
            }
            cobj->DestroyBody(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2World:DestroyBody", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2World_DestroyBody'.", &tolua_err);
#endif
    return 0;
}
#endif

#ifndef TOLUA_DISABLE_lua_LuaBox2D_b2World_CreateJoint
int lua_LuaBox2D_b2World_CreateJoint(lua_State *tolua_S)
{
    int argc = 0;
    b2World *cobj = nullptr;
    bool ok = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2World", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2World *)tolua_tousertype(tolua_S, 1, 0);

    argc = lua_gettop(tolua_S) - 1;
    do
    {
        if (argc == 1)
        {
            // const b2BodyDef* arg0 = ((const b2BodyDef*)  tolua_tousertype(tolua_S,2,0));
            const b2JointDef *arg0;
            ok &= luaval_to_object<const b2JointDef>(tolua_S, 2, "b2JointDef", &arg0);
            if (!ok)
            {
                tolua_error(tolua_S, "invalid arguments in function 'lua_LuaBox2D_b2World_CreateJoint', was expecting b2JointDef", nullptr);
                return 0;
            }
            b2Joint *ret = (b2Joint *)cobj->CreateJoint((const b2JointDef *)arg0);
            object_to_luaval<b2Joint>(tolua_S, "b2Joint", (b2Joint *)ret);
            return 1;
        }
    } while (0);
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2World:CreateJoint", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2World_CreateJoint'.", &tolua_err);
#endif
    return 0;
}
#endif

#ifndef TOLUA_DISABLE_lua_LuaBox2D_b2World_DestroyJoint
int lua_LuaBox2D_b2World_DestroyJoint(lua_State *tolua_S)
{
    int argc = 0;
    b2World *cobj = nullptr;
    bool ok = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2World", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2World *)tolua_tousertype(tolua_S, 1, 0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_LuaBox2D_b2World_DestroyJoint'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    do
    {
        if (argc == 1)
        {
            b2Joint *arg0;
            ok &= luaval_to_object<b2Joint>(tolua_S, 2, "b2Joint", &arg0);
            if (!ok)
            {
                tolua_error(tolua_S, "invalid arguments in function 'lua_LuaBox2D_b2World_DestroyJoint', was expecting b2Joint", nullptr);
                return 0;
            }
            cobj->DestroyJoint(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2World:DestroyJoint", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2World_DestroyJoint'.", &tolua_err);
#endif
    return 0;
}
#endif

#ifndef TOLUA_DISABLE_lua_LuaBox2D_b2World_Step
int lua_LuaBox2D_b2World_Step(lua_State *tolua_S){
    int argc = 0;
    b2World *cobj = nullptr;
    bool ok = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2World", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2World *)tolua_tousertype(tolua_S, 1, 0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_LuaBox2D_b2World_Step'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    do
    {
        if (argc == 3)
        {
            double arg0;
            ok &= luaval_to_number(tolua_S, 2, &arg0, "b2World:Step");
            if (!ok)
            {
                tolua_error(tolua_S, "invalid arguments 1 in function 'lua_LuaBox2D_b2World_Step', was expecting number", nullptr);
                return 0;
            }

            int32 arg1;
            ok &= luaval_to_int32(tolua_S, 3, &arg1, "b2World:Step");
            if (!ok)
            {
                tolua_error(tolua_S, "invalid arguments 2 in function 'lua_LuaBox2D_b2World_Step', was expecting number", nullptr);
                return 0;
            }

            int32 arg2;
            ok &= luaval_to_int32(tolua_S, 4, &arg2, "b2World:Step");
            if (!ok)
            {
                tolua_error(tolua_S, "invalid arguments 2 in function 'lua_LuaBox2D_b2World_Step', was expecting number", nullptr);
                return 0;
            }

            cobj->Step(arg0, arg1, arg2);
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);

    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2World:Step", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2World_Step'.", &tolua_err);
#endif
    return 0;
}
#endif

#ifndef TOLUA_DISABLE_lua_LuaBox2D_b2World_ClearForces
int lua_LuaBox2D_b2World_ClearForces(lua_State *tolua_S){
    int argc = 0;
    b2World *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2World", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2World *)tolua_tousertype(tolua_S, 1, 0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_LuaBox2D_b2World_ClearForces'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
  
    if (argc == 0)
    {
        cobj->ClearForces();
        lua_settop(tolua_S, 1);
        return 1;
    }

    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2World:ClearForces", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2World_ClearForces'.", &tolua_err);
#endif
    return 0;
}
#endif

#ifndef TOLUA_DISABLE_lua_LuaBox2D_b2World_ClearForces
int lua_LuaBox2D_b2World_QueryAABB(lua_State *tolua_S){
    int argc = 0;
    b2World *cobj = nullptr;
    bool ok = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2World", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2World *)tolua_tousertype(tolua_S, 1, 0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_LuaBox2D_b2World_QueryAABB'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    if(argc == 2){
        b2QueryCallback* arg0;
        ok &= luaval_to_object<b2QueryCallback>(tolua_S, 2, "b2QueryCallback", &arg0);
        if(!ok){
            tolua_error(tolua_S, "invalid arguments 2 in function 'lua_LuaBox2D_b2World_RayCast', was expecting b2QueryCallback", nullptr);
            return 0;
        }

        const b2AABB* arg1;
        ok &= luaval_to_object<const b2AABB>(tolua_S, 3, "b2AABB", &arg1);
        if(!ok){
            tolua_error(tolua_S, "invalid arguments 2 in function 'lua_LuaBox2D_b2World_RayCast', was expecting b2AABB", nullptr);
            return 0;
        }
        cobj -> QueryAABB(arg0, *arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2World:QueryAABB", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2World_QueryAABB'.", &tolua_err);
#endif
    return 0;
}
#endif

#ifndef TOLUA_DISABLE_lua_LuaBox2D_b2World_RayCast
int lua_LuaBox2D_b2World_RayCast(lua_State *tolua_S){
    int argc = 0;
    b2World *cobj = nullptr;
    bool ok = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2World", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2World *)tolua_tousertype(tolua_S, 1, 0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_LuaBox2D_b2World_RayCast'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if(argc == 3){
        b2RayCastCallback* arg0;
        ok &= luaval_to_object<b2RayCastCallback>(tolua_S, 2, "b2RayCastCallback", &arg0);
        if(!ok){
            tolua_error(tolua_S, "invalid arguments 1 in function 'lua_LuaBox2D_b2World_RayCast', was expecting b2RayCastCallback", nullptr);
            return 0;
        }

        const b2Vec2* arg1;
        ok &= luaval_to_object<const b2Vec2>(tolua_S, 3, "b2Vec2", &arg1);
        if(!ok){
            tolua_error(tolua_S, "invalid arguments 2 in function 'lua_LuaBox2D_b2World_RayCast', was expecting b2Vec2", nullptr);
            return 0;
        }

        const b2Vec2* arg2;
        ok &= luaval_to_object<const b2Vec2>(tolua_S, 4, "b2Vec2", &arg2);
        if(!ok){
            tolua_error(tolua_S, "invalid arguments 3 in function 'lua_LuaBox2D_b2World_RayCast', was expecting b2Vec2", nullptr);
            return 0;
        }

        cobj -> RayCast(arg0, *arg1, *arg2);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2World:RayCast", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2World_RayCast'.", &tolua_err);
#endif
    return 0;
}
#endif

#ifndef TOLUA_DISABLE_lua_LuaBox2D_b2World_GetBodyList
int lua_LuaBox2D_b2World_GetBodyList(lua_State *tolua_S){
    int argc = 0;
    b2World *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2World", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2World *)tolua_tousertype(tolua_S, 1, 0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_LuaBox2D_b2World_GetBodyList'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if(argc >= 0){
        b2Body *ret = cobj -> GetBodyList();
        object_to_luaval<b2Body>(tolua_S, "b2Body", (b2Body *)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2World:GetBodyList", argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2World_GetBodyList'.", &tolua_err);
#endif
    return 0;
}
#endif

#ifndef TOLUA_DISABLE_lua_LuaBox2D_b2World_GetJointList
int lua_LuaBox2D_b2World_GetJointList(lua_State *tolua_S){
    int argc = 0;
    b2World *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2World", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2World *)tolua_tousertype(tolua_S, 1, 0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_LuaBox2D_b2World_GetJointList'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if(argc >= 0){
        b2Joint *ret = cobj -> GetJointList();
        object_to_luaval<b2Joint>(tolua_S, "b2Joint", (b2Joint *)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2World:GetJointList", argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2World_GetJointList'.", &tolua_err);
#endif
    return 0;
}
#endif

#ifndef TOLUA_DISABLE_lua_LuaBox2D_b2World_GetContactList
int lua_LuaBox2D_b2World_GetContactList(lua_State *tolua_S){
    int argc = 0;
    b2World *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2World", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2World *)tolua_tousertype(tolua_S, 1, 0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_LuaBox2D_b2World_GetContactList'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if(argc >= 0){
        b2Contact *ret = cobj -> GetContactList();
        object_to_luaval<b2Contact>(tolua_S, "b2Contact", (b2Contact *)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2World:GetContactList", argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2World_GetContactList'.", &tolua_err);
#endif
    return 0;
}
#endif

#ifndef TOLUA_DISABLE_lua_LuaBox2D_b2World_SetAllowSleeping
int lua_LuaBox2D_b2World_SetAllowSleeping(lua_State *tolua_S){
    int argc = 0;
    b2World *cobj = nullptr;
    bool ok = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2World", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2World *)tolua_tousertype(tolua_S, 1, 0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_LuaBox2D_b2World_SetAllowSleeping'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if(argc == 1){
        bool arg0;
        ok &= luaval_to_boolean(tolua_S, 2, &arg0, "b2World:SetAllowSleeping");
        if(!ok){
            tolua_error(tolua_S, "invalid arguments 2 in function 'lua_LuaBox2D_b2World_SetAllowSleeping', was expecting bool", nullptr);
            return 0;
        }
        cobj -> SetAllowSleeping(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2World:SetAllowSleeping", argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2World_SetAllowSleeping'.", &tolua_err);
#endif
    return 0;
}
#endif

#ifndef TOLUA_DISABLE_lua_LuaBox2D_b2World_GetAllowSleeping
int lua_LuaBox2D_b2World_GetAllowSleeping(lua_State *tolua_S){
    int argc = 0;
    b2World *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2World", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2World *)tolua_tousertype(tolua_S, 1, 0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_LuaBox2D_b2World_GetAllowSleeping'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if(argc >= 0){
        bool ret = cobj -> GetAllowSleeping();
        tolua_pushboolean(tolua_S, (bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2World:GetAllowSleeping", argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2World_GetAllowSleeping'.", &tolua_err);
#endif
    return 0;
}
#endif

#ifndef TOLUA_DISABLE_lua_LuaBox2D_b2World_SetWarmStarting
int lua_LuaBox2D_b2World_SetWarmStarting(lua_State *tolua_S){
    int argc = 0;
    b2World *cobj = nullptr;
    bool ok = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2World", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2World *)tolua_tousertype(tolua_S, 1, 0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_LuaBox2D_b2World_SetWarmStarting'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if(argc >= 1){
        bool arg0;
        ok &= luaval_to_boolean(tolua_S, 1, &arg0, "b2World:SetWarmStarting");
        if(!ok){
            tolua_error(tolua_S, "invalid arguments 2 in function 'lua_LuaBox2D_b2World_SetWarmStarting', was expecting bool", nullptr);
            return 0;
        }
        cobj -> SetWarmStarting(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2World:SetWarmStarting", argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2World_SetWarmStarting'.", &tolua_err);
#endif
    return 0;
}
#endif

#ifndef TOLUA_DISABLE_lua_LuaBox2D_b2World_GetWarmStarting
int lua_LuaBox2D_b2World_GetWarmStarting(lua_State *tolua_S){
    int argc = 0;
    b2World *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2World", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2World *)tolua_tousertype(tolua_S, 1, 0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_LuaBox2D_b2World_GetWarmStarting'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if(argc >= 0){
        bool ret = cobj -> GetWarmStarting();
        tolua_pushboolean(tolua_S, (bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2World:GetWarmStarting", argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2World_GetWarmStarting'.", &tolua_err);
#endif
    return 0;
}
#endif

#ifndef TOLUA_DISABLE_lua_LuaBox2D_b2World_SetContinuousPhysics
int lua_LuaBox2D_b2World_SetContinuousPhysics(lua_State *tolua_S){
    int argc = 0;
    b2World *cobj = nullptr;
    bool ok = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2World", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2World *)tolua_tousertype(tolua_S, 1, 0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_LuaBox2D_b2World_SetContinuousPhysics'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if(argc == 1){
        bool arg0;
        ok &= luaval_to_boolean(tolua_S, 2, &arg0, "b2World:SetWarmStarting");
        if(!ok){
            tolua_error(tolua_S, "invalid arguments 1 in function 'lua_LuaBox2D_b2World_SetContinuousPhysics', was expecting bool", nullptr);
            return 0;
        }
        cobj -> SetContinuousPhysics(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2World:SetWarmStarting", argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2World_SetContinuousPhysics'.", &tolua_err);
#endif
    return 0;
}
#endif

#ifndef TOLUA_DISABLE_lua_LuaBox2D_b2World_GetContinuousPhysics
int lua_LuaBox2D_b2World_GetContinuousPhysics(lua_State *tolua_S){
    int argc = 0;
    b2World *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2World", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2World *)tolua_tousertype(tolua_S, 1, 0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_LuaBox2D_b2World_GetContinuousPhysics'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if(argc >= 0){
        bool ret = cobj -> GetContinuousPhysics();
        tolua_pushboolean(tolua_S, (bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2World:GetContinuousPhysics", argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2World_GetContinuousPhysics'.", &tolua_err);
#endif
    return 0;
}
#endif

#ifndef TOLUA_DISABLE_lua_LuaBox2D_b2World_SetSubStepping
int lua_LuaBox2D_b2World_SetSubStepping(lua_State *tolua_S){
    int argc = 0;
    b2World *cobj = nullptr;
    bool ok = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2World", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2World *)tolua_tousertype(tolua_S, 1, 0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_LuaBox2D_b2World_SetSubStepping'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if(argc >= 1){
        bool arg0;
        ok &= luaval_to_boolean(tolua_S, 2, &arg0, "b2World:SetSubStepping");
        if(!ok){
            tolua_error(tolua_S, "invalid arguments 2 in function 'lua_LuaBox2D_b2World_SetSubStepping', was expecting bool", nullptr);
            return 0;
        }
        cobj -> SetSubStepping(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2World:SetSubStepping", argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2World_SetSubStepping'.", &tolua_err);
#endif
    return 0;
}
#endif

#ifndef TOLUA_DISABLE_lua_LuaBox2D_b2World_GetSubStepping
int lua_LuaBox2D_b2World_GetSubStepping(lua_State *tolua_S){
    int argc = 0;
    b2World *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2World", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2World *)tolua_tousertype(tolua_S, 1, 0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_LuaBox2D_b2World_GetSubStepping'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if(argc >= 0){
        bool ret = cobj -> GetSubStepping();
        tolua_pushboolean(tolua_S, (bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2World:GetSubStepping", argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2World_GetSubStepping'.", &tolua_err);
#endif
    return 0;
}
#endif

#ifndef TOLUA_DISABLE_lua_LuaBox2D_b2World_GetProxyCount
int lua_LuaBox2D_b2World_GetProxyCount(lua_State *tolua_S){
    int argc = 0;
    b2World *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2World", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2World *)tolua_tousertype(tolua_S, 1, 0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_LuaBox2D_b2World_GetSubStepping'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if(argc >= 0){
        int32 ret = cobj -> GetProxyCount();
        tolua_pushnumber(tolua_S, (lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2World:GetSubStepping", argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2World_GetSubStepping'.", &tolua_err);
#endif
    return 0;
}
#endif

#ifndef TOLUA_DISABLE_lua_LuaBox2D_b2World_GetJointCount
int lua_LuaBox2D_b2World_GetJointCount(lua_State *tolua_S){
    int argc = 0;
    b2World *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2World", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2World *)tolua_tousertype(tolua_S, 1, 0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_LuaBox2D_b2World_GetJointCount'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if(argc >= 0){
        int32 ret = cobj -> GetJointCount();
        tolua_pushnumber(tolua_S, (lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2World:GetJointCount", argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2World_GetJointCount'.", &tolua_err);
#endif
    return 0;
}
#endif

#ifndef TOLUA_DISABLE_lua_LuaBox2D_b2World_GetContactCount
int lua_LuaBox2D_b2World_GetContactCount(lua_State *tolua_S){
    int argc = 0;
    b2World *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2World", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2World *)tolua_tousertype(tolua_S, 1, 0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_LuaBox2D_b2World_GetContactCount'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if(argc >= 0){
        int32 ret = cobj -> GetContactCount();
        tolua_pushnumber(tolua_S, (lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2World:GetContactCount", argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2World_GetContactCount'.", &tolua_err);
#endif
    return 0;
}
#endif

#ifndef TOLUA_DISABLE_lua_LuaBox2D_b2World_GetTreeHeight
int lua_LuaBox2D_b2World_GetTreeHeight(lua_State *tolua_S){
    int argc = 0;
    b2World *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2World", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2World *)tolua_tousertype(tolua_S, 1, 0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_LuaBox2D_b2World_GetTreeHeight'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if(argc >= 0){
        int32 ret = cobj -> GetTreeHeight();
        tolua_pushnumber(tolua_S, (lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2World:GetTreeHeight", argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2World_GetTreeHeight'.", &tolua_err);
#endif
    return 0;
}
#endif

#ifndef TOLUA_DISABLE_lua_LuaBox2D_b2World_GetContactCount
int lua_LuaBox2D_b2World_GetTreeBalance(lua_State *tolua_S){
    int argc = 0;
    b2World *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2World", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2World *)tolua_tousertype(tolua_S, 1, 0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_LuaBox2D_b2World_GetTreeBalance'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if(argc >= 0){
        int32 ret = cobj -> GetTreeBalance();
        tolua_pushnumber(tolua_S, (lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2World:GetTreeBalance", argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2World_GetTreeBalance'.", &tolua_err);
#endif
    return 0;
}
#endif

#ifndef TOLUA_DISABLE_lua_LuaBox2D_b2World_GetTreeQuality
int lua_LuaBox2D_b2World_GetTreeQuality(lua_State *tolua_S){
    int argc = 0;
    b2World *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2World", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2World *)tolua_tousertype(tolua_S, 1, 0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_LuaBox2D_b2World_GetTreeQuality'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if(argc >= 0){
        int32 ret = cobj -> GetTreeQuality();
        tolua_pushnumber(tolua_S, (lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2World:GetTreeQuality", argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2World_GetTreeQuality'.", &tolua_err);
#endif
    return 0;
}
#endif


#ifndef TOLUA_DISABLE_lua_LuaBox2D_b2World_SetGravity
int lua_LuaBox2D_b2World_SetGravity(lua_State *tolua_S){
    int argc = 0;
    b2World *cobj = nullptr;
    bool ok = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2World", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2World *)tolua_tousertype(tolua_S, 1, 0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_LuaBox2D_b2World_SetGravity'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if(argc == 1){
        const b2Vec2* arg0;
        ok &= luaval_to_object<const b2Vec2>(tolua_S, 3, "b2Vec2", &arg0);
        if(!ok){
            tolua_error(tolua_S, "invalid arguments 2 in function 'lua_LuaBox2D_b2World_SetGravity', was expecting bool", nullptr);
            return 0;
        }
        cobj -> SetGravity(*arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2World:SetAllowSleeping", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2World_SetGravity'.", &tolua_err);
#endif
    return 0;
}
#endif

#ifndef TOLUA_DISABLE_lua_LuaBox2D_b2World_GetGravity
int lua_LuaBox2D_b2World_GetGravity(lua_State *tolua_S){
    int argc = 0;
    b2World *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2World", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2World *)tolua_tousertype(tolua_S, 1, 0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_LuaBox2D_b2World_GetGravity'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if(argc >= 0){
        b2Vec2 newVec = cobj -> GetGravity();
        b2Vec2 *ret = new b2Vec2(newVec.x, newVec.y);
        object_to_luaval(tolua_S, "b2Vec2", (b2Vec2 *)ret);
        tolua_register_gc(tolua_S, lua_gettop(tolua_S));
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2World:GetGravity", argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2World_GetGravity'.", &tolua_err);
#endif
    return 0;
}
#endif

#ifndef TOLUA_DISABLE_lua_LuaBox2D_b2World_IsLocked
int lua_LuaBox2D_b2World_IsLocked(lua_State *tolua_S){
    int argc = 0;
    b2World *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2World", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2World *)tolua_tousertype(tolua_S, 1, 0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_LuaBox2D_b2World_IsLocked'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if(argc >= 0){
        bool ret = cobj -> IsLocked();
        tolua_pushboolean(tolua_S, (bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2World:IsLocked", argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2World_IsLocked'.", &tolua_err);
#endif
    return 0;
}
#endif

#ifndef TOLUA_DISABLE_lua_LuaBox2D_b2World_SetAutoClearForces
int lua_LuaBox2D_b2World_SetAutoClearForces(lua_State *tolua_S){
    int argc = 0;
    b2World *cobj = nullptr;
    bool ok = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2World", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2World *)tolua_tousertype(tolua_S, 1, 0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_LuaBox2D_b2World_SetAutoClearForces'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if(argc >= 1){
        bool arg0;
        ok &= luaval_to_boolean(tolua_S, 1, &arg0, "b2World:SetContinuousPhysics");
        if(!ok){
            tolua_error(tolua_S, "invalid arguments 2 in function 'lua_LuaBox2D_b2World_SetAutoClearForces', was expecting bool", nullptr);
            return 0;
        }
        cobj -> SetContinuousPhysics(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2World:SetContinuousPhysics", argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2World_SetAutoClearForces'.", &tolua_err);
#endif
    return 0;
}
#endif

#ifndef TOLUA_DISABLE_lua_LuaBox2D_b2World_GetAutoClearForces
int lua_LuaBox2D_b2World_GetAutoClearForces(lua_State *tolua_S){
    int argc = 0;
    b2World *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2World", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2World *)tolua_tousertype(tolua_S, 1, 0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_LuaBox2D_b2World_GetAutoClearForces'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if(argc >= 0){
        bool ret = cobj -> GetAutoClearForces();
        tolua_pushboolean(tolua_S, (bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2World:GetAutoClearForces", argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2World_GetAutoClearForces'.", &tolua_err);
#endif
    return 0;
}
#endif

#ifndef TOLUA_DISABLE_lua_LuaBox2D_b2World_ShiftOrigin
int lua_LuaBox2D_b2World_ShiftOrigin(lua_State *tolua_S){
        int argc = 0;
    b2World *cobj = nullptr;
    bool ok = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2World", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2World *)tolua_tousertype(tolua_S, 1, 0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_LuaBox2D_b2World_ShiftOrigin'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if(argc >= 1){
        const b2Vec2* arg0;
        ok &= luaval_to_object<const b2Vec2>(tolua_S, 3, "b2Vec2", &arg0);
        if(!ok){
            tolua_error(tolua_S, "invalid arguments 2 in function 'lua_LuaBox2D_b2World_ShiftOrigin', was expecting bool", nullptr);
            return 0;
        }
        cobj -> ShiftOrigin(*arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2World:ShiftOrigin", argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2World_ShiftOrigin'.", &tolua_err);
#endif
    return 0;
}
#endif


#ifndef TOLUA_DISABLE_lua_LuaBox2D_b2World_GetContactManager
int lua_LuaBox2D_b2World_GetContactManager(lua_State *tolua_S){
    int argc = 0;
    b2World *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2World", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2World *)tolua_tousertype(tolua_S, 1, 0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_LuaBox2D_b2World_GetContactManager'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if(argc >= 0){
        const b2ContactManager ret = cobj -> GetContactManager();
        object_to_luaval<b2ContactManager>(tolua_S, "b2ContactManager", (b2ContactManager *)&ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2World:GetContactManager", argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2World_GetContactManager'.", &tolua_err);
#endif
    return 0;
}
#endif


int lua_register_cocos2dx_b2world(lua_State *tolua_S)
{
    tolua_usertype(tolua_S, "b2World");
    tolua_cclass(tolua_S, "b2World", "b2World", "", nullptr);
    tolua_beginmodule(tolua_S, "b2World");
    tolua_function(tolua_S, "new", lua_cocos2dx_b2world_new00_local);
    tolua_function(tolua_S, ".call", lua_cocos2dx_b2world_new00_local);
    tolua_function(tolua_S, "delete", lua_LuaBox2D_b2World_delete);
    tolua_function(tolua_S, "SetDestructionListener", lua_LuaBox2D_b2World_SetDestructionListener);
    tolua_function(tolua_S, "SetContactFilter", tolua_LuaBox2D_b2World_SetContactFilter);
    tolua_function(tolua_S, "SetContactListener", tolua_LuaBox2D_b2World_SetContactListener);
    tolua_function(tolua_S, "SetDebugDraw", lua_LuaBox2D_b2World_SetDebugDraw);
    tolua_function(tolua_S, "CreateBody", lua_LuaBox2D_b2World_CreateBody);
    tolua_function(tolua_S, "DestroyBody", lua_LuaBox2D_b2World_DestroyBody);
    tolua_function(tolua_S, "CreateJoint", lua_LuaBox2D_b2World_CreateJoint);
    tolua_function(tolua_S, "DestroyJoint", lua_LuaBox2D_b2World_DestroyJoint);
    tolua_function(tolua_S, "Step", lua_LuaBox2D_b2World_Step);
    tolua_function(tolua_S, "ClearForces", lua_LuaBox2D_b2World_ClearForces);
    tolua_function(tolua_S, "QueryAABB", lua_LuaBox2D_b2World_QueryAABB);
    tolua_function(tolua_S, "RayCast", lua_LuaBox2D_b2World_RayCast);
    tolua_function(tolua_S, "GetBodyList", lua_LuaBox2D_b2World_GetBodyList);
    tolua_function(tolua_S, "GetJointList", lua_LuaBox2D_b2World_GetJointList);
    tolua_function(tolua_S, "GetContactList", lua_LuaBox2D_b2World_GetContactList);
    tolua_function(tolua_S, "SetAllowSleeping", lua_LuaBox2D_b2World_SetAllowSleeping);
    tolua_function(tolua_S, "GetAllowSleeping", lua_LuaBox2D_b2World_GetAllowSleeping);
    tolua_function(tolua_S, "SetWarmStarting", lua_LuaBox2D_b2World_SetWarmStarting);
    tolua_function(tolua_S, "GetWarmStarting", lua_LuaBox2D_b2World_SetWarmStarting);
    tolua_function(tolua_S, "SetContinuousPhysics", lua_LuaBox2D_b2World_SetContinuousPhysics);
    tolua_function(tolua_S, "GetContinuousPhysics", lua_LuaBox2D_b2World_GetContinuousPhysics);
    tolua_function(tolua_S, "SetSubStepping", lua_LuaBox2D_b2World_SetSubStepping);
    tolua_function(tolua_S, "GetSubStepping", lua_LuaBox2D_b2World_GetSubStepping);
    tolua_function(tolua_S, "GetProxyCount", lua_LuaBox2D_b2World_GetProxyCount);
    tolua_function(tolua_S, "GetJointCount", lua_LuaBox2D_b2World_GetJointCount);
    tolua_function(tolua_S, "GetContactCount", lua_LuaBox2D_b2World_GetContactCount);
    tolua_function(tolua_S, "GetTreeHeight", lua_LuaBox2D_b2World_GetTreeHeight);
    tolua_function(tolua_S, "GetTreeBalance", lua_LuaBox2D_b2World_GetTreeBalance);
    tolua_function(tolua_S, "GetTreeQuality", lua_LuaBox2D_b2World_GetTreeQuality);
    tolua_function(tolua_S, "SetGravity", lua_LuaBox2D_b2World_SetGravity);
    tolua_function(tolua_S, "GetGravity", lua_LuaBox2D_b2World_GetGravity);
    tolua_function(tolua_S, "IsLocked", lua_LuaBox2D_b2World_IsLocked);
    tolua_function(tolua_S, "SetAutoClearForces", lua_LuaBox2D_b2World_SetAutoClearForces);
    tolua_function(tolua_S, "GetAutoClearForces", lua_LuaBox2D_b2World_GetAutoClearForces);
    tolua_function(tolua_S, "ShiftOrigin", lua_LuaBox2D_b2World_ShiftOrigin);
    tolua_function(tolua_S, "GetContactManager", lua_LuaBox2D_b2World_GetContactManager);

    tolua_endmodule(tolua_S);
    std::string typeName = typeid(b2World).name();
    g_luaType[typeName] = "b2World";
    g_typeCast["b2World"] = "b2World";
    return 1;
}

/* class of bodyDef */
//function of new bodyDef
#ifndef TOLUA_DISABLE_lua_LuaBox2D_b2BodyDef_new00_local
int lua_LuaBox2D_b2BodyDef_new00_local(lua_State *tolua_S)
{
    int argc = 0;
    b2BodyDef *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

    cobj = (b2BodyDef *)tolua_tousertype(tolua_S, 1, 0);

    argc = lua_gettop(tolua_S) - 1;
    do
    {
        if (argc == 0)
        {
            b2BodyDef *ret = new b2BodyDef();
            object_to_luaval<b2BodyDef>(tolua_S, "b2BodyDef", (b2BodyDef *)ret);
            tolua_register_gc(tolua_S, lua_gettop(tolua_S));
            return 1;
        }
    } while (0);
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2BodyDef:new", argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2BodyDef_new00_local'.", &tolua_err);
#endif
    return 0;
}
#endif

//function of set bodyType
#ifndef TOLUA_DISABLE_tolua_set_b2BodyDef_type
int lua_set_b2BodyDef_type(lua_State *tolua_S)
{
    int argc = 0;
    b2BodyDef *cobj = nullptr;
    bool ok = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2BodyDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2BodyDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_set_b2BodyDef_type'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        int arg0;
        ok &= luaval_to_int32(tolua_S, 2, &arg0, "b2BodyDef:type");
        if (!ok)
        {
            tolua_error(tolua_S, "invalid arguments 1 in function 'lua_set_b2BodyDef_type'", nullptr);
            return 0;
        };
        cobj->type = (b2BodyType)arg0;
        lua_settop(tolua_S, 1);
        return 1;
    }

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2BodyDef:type", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_set_b2BodyDef_type'.", &tolua_err);
    return 0;
#endif
}
#endif

//bodyDef.typy
//function of get bodyType
#ifndef TOLUA_DISABLE_lua_get_b2BodyDef_type
int lua_get_b2BodyDef_type(lua_State *tolua_S)
{
    int argc = 0;
    b2BodyDef *cobj = nullptr;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
if (!tolua_isusertype(tolua_S, 1, "b2BodyDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2BodyDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1

    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_get_b2BodyDef_type'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if (argc == 0){
        int32 ret = cobj->type;
        tolua_pushnumber(tolua_S, (lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2BodyDef:type", argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_get_b2BodyDef_type'.", &tolua_err);
    return 0;
#endif
}
#endif

// bodyDef.position
//function of get position
#ifndef TOLUA_DISABLE_lua_get_b2BodyDef_position
int lua_get_b2BodyDef_position(lua_State *tolua_S)
{
    int argc = 0;
    b2BodyDef *cobj = nullptr;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2BodyDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2BodyDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_get_b2BodyDef_position'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if(argc >= 0){
        b2Vec2 newVec = cobj->position;
        b2Vec2 *ret = new b2Vec2(newVec.x, newVec.y);
        object_to_luaval(tolua_S, "b2Vec2", (b2Vec2 *)ret);
        tolua_register_gc(tolua_S, lua_gettop(tolua_S));
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2BodyDef:position", argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_get_b2BodyDef_position'.", &tolua_err);
    return 0;
#endif
}
#endif

//function of set position
#ifndef TOLUA_DISABLE_lua_set_b2BodyDef_position
int lua_set_b2BodyDef_position(lua_State *tolua_S)
{
    int argc = 0;
    b2BodyDef *cobj = nullptr;
    bool ok = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2BodyDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2BodyDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_set_b2BodyDef_position'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (1 == argc)
        {
            b2Vec2 *arg0;
            ok &= luaval_to_object<b2Vec2>(tolua_S, 2, "b2Vec2", &arg0);
            if (!ok)
            {
                tolua_error(tolua_S, "invalid arguments 1 in function 'lua_set_b2BodyDef_position', was expecting b2Vec2", nullptr);
                return 0;
            };
            cobj->position = *arg0;
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2BodyDef:postion", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_set_b2BodyDef_position'.", &tolua_err);
    return 0;
#endif
}
#endif

// function of get bodyDef angle
#ifndef LUA_DISABLE_lua_get_b2BodyDef_angle
int lua_get_b2BodyDef_angle(lua_State *tolua_S)
{
    int argc = 0;
    b2BodyDef *cobj = nullptr;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2BodyDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2BodyDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_get_b2BodyDef_angle'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if(argc >= 0){
        float32 ret = cobj->angle;
        tolua_pushnumber(tolua_S, (lua_Number)ret);
        return 1;
    } 
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2BodyDef:angle", argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_get_b2BodyDef_angle'.", &tolua_err);
    return 0;
#endif
}
#endif

// function of set bodyDef angle
#ifndef LUA_DISABLE_lua_set_b2BodyDef_angle
int lua_set_b2BodyDef_angle(lua_State *tolua_S)
{
    int argc = 0;
    b2BodyDef *cobj = nullptr;
    bool ok = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2BodyDef", 0, &tolua_err) ||
        !tolua_isnumber(tolua_S, 2, 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2BodyDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_set_b2BodyDef_angle'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (1 == argc)
        {
            double arg0;
            ok &= luaval_to_number(tolua_S, 2, &arg0, "b2BodyDef:angle");
            if (!ok)
            {
                tolua_error(tolua_S, "invalid arguments in function 'lua_set_b2BodyDef_angle', was expecting number", nullptr);
                return 0;
            };
            cobj->angle = arg0;
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2Vec2:x", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_set_b2BodyDef_angle'.", &tolua_err);
    return 0;
#endif
}
#endif

/* function of get bodyDef linearVelocity */
#ifndef LUA_DISABLE_lua_get_b2BodyDef_linearVelocity
int lua_get_b2BodyDef_linearVelocity(lua_State *tolua_S)
{
    int argc = 0;
    b2BodyDef *cobj = nullptr;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2BodyDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2BodyDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_get_b2BodyDef_linearVelocity'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if(argc >= 0){
        b2Vec2 newVec = cobj->linearVelocity;
        b2Vec2 *ret = new b2Vec2(newVec.x, newVec.y);
        object_to_luaval(tolua_S, "b2Vec2", (b2Vec2 *)ret);
        tolua_register_gc(tolua_S, lua_gettop(tolua_S));
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2BodyDef:linearVelocity", argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_get_b2BodyDef_linearVelocity'.", &tolua_err);
    return 0;
#endif
}
#endif

/* function of set bodyDef linearVelocity */
#ifndef LUA_DISABLE_lua_set_b2BodyDef_linearVelocity
int lua_set_b2BodyDef_linearVelocity(lua_State *tolua_S)
{
    int argc = 0;
    b2BodyDef *cobj = nullptr;
    bool ok = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2BodyDef", 0, &tolua_err) ||
        !tolua_isusertype(tolua_S, 2, "b2Vec2", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2BodyDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_set_b2BodyDef_linearVelocity'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        b2Vec2 *arg0;
        ok &= luaval_to_object<b2Vec2>(tolua_S, 2, "b2Vec2", &arg0);
        if(!ok){
            tolua_error(tolua_S, "invalid arguments in function 'lua_set_b2BodyDef_linearVelocity', was expecting b2Vec2", nullptr);
            return 0;
        };
        cobj->linearVelocity = *arg0;
        lua_settop(tolua_S, 1);
        return 1;
    }

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2BodyDef:linearVelocity", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_set_b2BodyDef_linearVelocity'.", &tolua_err);
    return 0;
#endif
}
#endif

#ifndef LUA_DISABLED_lua_get_b2BodyDef_angularVelocity
int lua_get_b2BodyDef_angularVelocity(lua_State *tolua_S)
{
    int argc = 0;
    b2BodyDef *cobj = nullptr;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2BodyDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2BodyDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_get_b2BodyDef_angularVelocity'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if(argc == 0){
        float32 ret = cobj->angularVelocity;
        tolua_pushnumber(tolua_S, (lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2BodyDef:angularVelocity", argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_get_b2BodyDef_angularVelocity'.", &tolua_err);
    return 0;
#endif
}
#endif

/* function of get bodyDef linearVelocity */
#ifndef LUA_DISABLED_lua_set_b2BodyDef_angularVelocity
int lua_set_b2BodyDef_angularVelocity(lua_State *tolua_S)
{
    int argc = 0;
    b2BodyDef *cobj = nullptr;
    bool ok = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2BodyDef", 0, &tolua_err) ||
        !tolua_isnumber(tolua_S, 2, 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2BodyDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_set_b2BodyDef_angularVelocity'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (1 == argc)
        {
            double arg0;
            ok &= luaval_to_number(tolua_S, 2, &arg0, "b2BodyDef:angularVelocity");
            if(!ok){
                tolua_error(tolua_S, "invalid arguments 1 in function 'lua_set_b2BodyDef_angularVelocity', was expecting number", nullptr);
                return 0;
            };
            cobj->angularVelocity = arg0;
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2BodyDef:angularVelocity", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_set_b2BodyDef_angularVelocity'.", &tolua_err);
    return 0;
#endif
}
#endif

/* function of get bodyDef linearDamping */
#ifndef LUA_DISABLED_lua_get_b2BodyDef_linearDamping
int lua_get_b2BodyDef_linearDamping(lua_State *tolua_S)
{
    int argc = 0;
    b2BodyDef *cobj = nullptr;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2BodyDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2BodyDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_get_b2BodyDef_linearDamping'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if(argc == 0){
        float32 ret = cobj->linearDamping;
        tolua_pushnumber(tolua_S, (lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2BodyDef:linearDamping", argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_get_b2BodyDef_linearDamping'.", &tolua_err);
    return 0;
#endif
}
#endif

/* function of set bodyDef linearDamping */
#ifndef LUA_DISABLED_lua_set_b2BodyDef_linearDamping
int lua_set_b2BodyDef_linearDamping(lua_State *tolua_S)
{
    int argc = 0;
    b2BodyDef *cobj = nullptr;
    bool ok = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2BodyDef", 0, &tolua_err) ||
        !tolua_isnumber(tolua_S, 2, 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2BodyDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_set_b2BodyDef_linearDamping'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (1 == argc)
        {
            double arg0;
            ok &= luaval_to_number(tolua_S, 2, &arg0, "b2BodyDef:linearDamping");
            if(!ok){
                tolua_error(tolua_S, "invalid arguments 1 in function 'lua_set_b2BodyDef_linearDamping', was expecting number", nullptr);
                return 0;
            };
            cobj->linearDamping = arg0;
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2BodyDef:linearDamping", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_set_b2BodyDef_linearDamping'.", &tolua_err);
    return 0;
#endif
}
#endif

/* function of get bodyDef angularDamping */
#ifndef LUA_DISABLED_lua_get_b2BodyDef_angularDamping
int lua_get_b2BodyDef_angularDamping(lua_State *tolua_S)
{
    int argc = 0;
    b2BodyDef *cobj = nullptr;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2BodyDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2BodyDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_get_b2BodyDef_angularDamping'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if(argc == 0){
        float32 ret = cobj->angularDamping;
        tolua_pushnumber(tolua_S, (lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2BodyDef:angularDamping", argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_get_b2BodyDef_angularDamping'.", &tolua_err);
    return 0;
#endif
}
#endif

/* function of set bodyDef angularDamping */
#ifndef LUA_DISABLED_lua_get_b2BodyDef_angularDamping
int lua_set_b2BodyDef_angularDamping(lua_State *tolua_S)
{
    int argc = 0;
    b2BodyDef *cobj = nullptr;
    bool ok = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2BodyDef", 0, &tolua_err) ||
        !tolua_isnumber(tolua_S, 2, 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2BodyDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_set_b2BodyDef_angularDamping'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (1 == argc)
        {
            double arg0;
            ok &= luaval_to_number(tolua_S, 2, &arg0, "b2BodyDef:angularDamping");
            if(!ok){
                tolua_error(tolua_S, "invalid arguments 1 in function 'lua_set_b2BodyDef_angularDamping', was expecting number", nullptr);
                return 0;
            }
            cobj->angularDamping = arg0;
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2BodyDef:angularDamping", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_set_b2BodyDef_angularDamping'.", &tolua_err);
    return 0;
#endif
}
#endif

/* function of get bodyDef allowSleep */
#ifndef LUA_DISABLED_lua_get_b2BodyDef_allowSleep
int lua_get_b2BodyDef_allowSleep(lua_State *tolua_S)
{
    int argc = 0;
    b2BodyDef *cobj = nullptr;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2BodyDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2BodyDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_get_b2BodyDef_allowSleep'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if(argc == 0){
        bool ret = cobj->allowSleep;
        tolua_pushboolean(tolua_S, (bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2BodyDef:allowSleep", argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_get_b2BodyDef_allowSleep'.", &tolua_err);
    return 0;
#endif
}
#endif

/* function of set bodyDef allowSleep */
#ifndef LUA_DISABLED_lua_set_b2BodyDef_allowSleep
int lua_set_b2BodyDef_allowSleep(lua_State *tolua_S)
{
    int argc = 0;
    b2BodyDef *cobj = nullptr;
    bool ok = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2BodyDef", 0, &tolua_err) ||
        !tolua_isboolean(tolua_S, 2, 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2BodyDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_set_b2BodyDef_allowSleep'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (1 == argc)
        {
            bool arg0;
            ok &= luaval_to_boolean(tolua_S, 2, &arg0, "b2BodyDef:allowSleep");
            if(!ok){
                tolua_error(tolua_S, "invalid arguments 1 in function 'lua_set_b2BodyDef_allowSleep', was expecting bool", nullptr);
                return 0;
            }
            cobj->allowSleep = arg0;
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2BodyDef:allowSleep", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_set_b2BodyDef_allowSleep'.", &tolua_err);
    return 0;
#endif
}
#endif

/* function of get bodyDef awake */
#ifndef LUA_DISABLED_lua_get_b2BodyDef_awake
int lua_get_b2BodyDef_awake(lua_State *tolua_S)
{
    int argc = 0;
    b2BodyDef *cobj = nullptr;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2BodyDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2BodyDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_get_b2BodyDef_awake'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if(argc == 0){
        bool ret = cobj->awake;
        tolua_pushboolean(tolua_S, (bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2BodyDef:awake", argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_get_b2BodyDef_awake'.", &tolua_err);
    return 0;
#endif
}
#endif

/* function of set bodyDef awake */
#ifndef LUA_DISABLED_lua_set_b2BodyDef_awake
int lua_set_b2BodyDef_awake(lua_State *tolua_S)
{
    int argc = 0;
    b2BodyDef *cobj = nullptr;
    bool ok = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2BodyDef", 0, &tolua_err) ||
        !tolua_isboolean(tolua_S, 2, 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2BodyDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_set_b2BodyDef_awake'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;


    if (1 == argc)
    {
        bool arg0;
        ok &= luaval_to_boolean(tolua_S, 2, &arg0, "b2BodyDef:awake");
        if(!ok){
            tolua_error(tolua_S, "invalid arguments 1 in function 'lua_set_b2BodyDef_awake', was expecting bool", nullptr);
            return 0;
        }
        cobj->awake = arg0;
        lua_settop(tolua_S, 1);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2BodyDef:awake", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_set_b2BodyDef_awake'.", &tolua_err);
    return 0;
#endif
}
#endif

/* function of get bodyDef fixedRotation */
#ifndef LUA_DISABLED_lua_get_b2BodyDef_fixedRotation
int lua_get_b2BodyDef_fixedRotation(lua_State *tolua_S)
{
    int argc = 0;
    b2BodyDef *cobj = nullptr;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2BodyDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2BodyDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_get_b2BodyDef_fixedRotation'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if(argc == 0){
        bool ret = cobj->fixedRotation;
        tolua_pushboolean(tolua_S, (bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2BodyDef:fixedRotation", argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_get_b2BodyDef_fixedRotation'.", &tolua_err);
    return 0;
#endif
}
#endif

/* function of set bodyDef fixedRotation */
#ifndef LUA_DISABLED_lua_set_b2BodyDef_fixedRotation
int lua_set_b2BodyDef_fixedRotation(lua_State *tolua_S)
{
    int argc = 0;
    b2BodyDef *cobj = nullptr;
    bool ok = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2BodyDef", 0, &tolua_err) ||
        !tolua_isboolean(tolua_S, 2, 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2BodyDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_set_b2BodyDef_fixedRotation'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (1 == argc)
        {
            bool arg0;
            ok &= luaval_to_boolean(tolua_S, 2, &arg0, "b2BodyDef:fixedRotation");
            if(!ok){
                tolua_error(tolua_S, "invalid arguments 1 in function 'lua_set_b2BodyDef_fixedRotation', was expecting bool", nullptr);
                return 0;
            }
            cobj->fixedRotation = arg0;
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2BodyDef:fixedRotation", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_set_b2BodyDef_fixedRotation'.", &tolua_err);
    return 0;
#endif
}
#endif

#ifndef LUA_DISABLED_lua_get_b2BodyDef_bullet
int lua_get_b2BodyDef_bullet(lua_State *tolua_S)
{
    int argc = 0;
    b2BodyDef *cobj = nullptr;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2BodyDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2BodyDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_get_b2BodyDef_bullet'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if(argc == 0){
        bool ret = cobj->bullet;
        tolua_pushboolean(tolua_S, (bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2BodyDef:bullet", argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_get_b2BodyDef_bullet'.", &tolua_err);
    return 0;
#endif
}
#endif

#ifndef LUA_DISABLED_lua_set_b2BodyDef_bullet
int lua_set_b2BodyDef_bullet(lua_State *tolua_S)
{
    int argc = 0;
    b2BodyDef *cobj = nullptr;
    bool ok = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2BodyDef", 0, &tolua_err) ||
        !tolua_isboolean(tolua_S, 2, 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2BodyDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_set_b2BodyDef_bullet'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if (1 == argc)
    {
        bool arg0;
        ok &= luaval_to_boolean(tolua_S, 2, &arg0, "b2BodyDef:bullet");
        if(!ok){
            tolua_error(tolua_S, "invalid arguments 1 in function 'lua_set_b2BodyDef_bullet', was expecting bool", nullptr);
            return 0;
        }
        cobj->bullet = arg0;
        lua_settop(tolua_S, 1);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2BodyDef:bullet", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_set_b2BodyDef_bullet'.", &tolua_err);
    return 0;
#endif
}
#endif

#ifndef LUA_DISABLED_lua_get_b2BodyDef_active
int lua_get_b2BodyDef_active(lua_State *tolua_S)
{
    int argc = 0;
    b2BodyDef *cobj = nullptr;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2BodyDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2BodyDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_get_b2BodyDef_active'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if(argc == 0){
        bool ret = cobj->active;
        tolua_pushboolean(tolua_S, (bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2BodyDef:active", argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_get_b2BodyDef_active'.", &tolua_err);
    return 0;
#endif
}
#endif

#ifndef LUA_DISABLED_lua_set_b2BodyDef_active
int lua_set_b2BodyDef_active(lua_State *tolua_S)
{
    int argc = 0;
    b2BodyDef *cobj = nullptr;
    bool ok = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2BodyDef", 0, &tolua_err) ||
        !tolua_isboolean(tolua_S, 2, 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2BodyDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_set_b2BodyDef_active'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (1 == argc)
        {
            bool arg0;
            ok &= luaval_to_boolean(tolua_S, 2, &arg0, "b2BodyDef:active");
            if(!ok){
                tolua_error(tolua_S, "invalid arguments 1 in function 'lua_set_b2BodyDef_active', was expecting bool", nullptr);
                return 0;
            }
            cobj->active = arg0;
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2BodyDef:active", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_set_b2BodyDef_active'.", &tolua_err);
    return 0;
#endif
}
#endif

#ifndef LUA_DISABLE_lua_get_b2BodyDef_gravityScale
int lua_get_b2BodyDef_gravityScale(lua_State *tolua_S)
{
    int argc = 0;
    b2BodyDef *cobj = nullptr;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2BodyDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2BodyDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_get_b2BodyDef_gravityScale'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if(argc == 0){
        float32 ret = cobj->gravityScale;
        tolua_pushnumber(tolua_S, (lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2BodyDef:gravityScale", argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_get_b2BodyDef_gravityScale'.", &tolua_err);
    return 0;
#endif
}
#endif

// function of set bodyDef angle
#ifndef LUA_DISABLE_lua_set_b2BodyDef_gravityScale
int lua_set_b2BodyDef_gravityScale(lua_State *tolua_S)
{
    int argc = 0;
    b2BodyDef *cobj = nullptr;
    bool ok = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2BodyDef", 0, &tolua_err) ||
        !tolua_isnumber(tolua_S, 2, 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2BodyDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_set_b2BodyDef_gravityScale'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (1 == argc)
        {
            double arg0;
            ok &= luaval_to_number(tolua_S, 2, &arg0, "b2BodyDef:gravityScale");
            if(!ok){
                tolua_error(tolua_S, "invalid arguments 2 in function 'lua_get_b2BodyDef_gravityScale', was expecting number", nullptr);
                return 0;
            }
            cobj->gravityScale = arg0;
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2BodyDef:gravityScale", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_get_b2BodyDef_gravityScale'.", &tolua_err);
    return 0;
#endif
}
#endif

#ifndef LUA_DISABLE_lua_get_b2BodyDef_userData
int lua_get_b2BodyDef_userData(lua_State *tolua_S)
{
    int argc = 0;
    b2BodyDef *cobj = nullptr;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2BodyDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2BodyDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_get_b2BodyDef_userData'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if(argc == 0){
        void *ret = cobj->userData;
        object_to_luaval<void>(tolua_S, "void", &ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2BodyDef:userData", argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_get_b2BodyDef_userData'.", &tolua_err);
    return 0;
#endif
}
#endif

#ifndef LUA_DISABLE_lua_set_b2BodyDef_userData
int lua_set_b2BodyDef_userData(lua_State *tolua_S)
{
    int argc = 0;
    b2BodyDef *cobj = nullptr;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2BodyDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2BodyDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_set_b2BodyDef_userData'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (1 == argc)
        {
            cobj->userData = ((void*) tolua_touserdata(tolua_S,2,0));
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2BodyDef:userData", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_set_b2BodyDef_userData'.", &tolua_err);
    return 0;
#endif
}
#endif

/* class of b2BodyDef */
int lua_register_cocos2dx_b2BodyDef(lua_State *tolua_S)
{
    tolua_usertype(tolua_S, "b2BodyDef");
    tolua_cclass(tolua_S, "b2BodyDef", "b2BodyDef", "", nullptr);
    tolua_beginmodule(tolua_S, "b2BodyDef");
    tolua_function(tolua_S, "new", lua_LuaBox2D_b2BodyDef_new00_local);
    tolua_function(tolua_S, ".call", lua_LuaBox2D_b2BodyDef_new00_local);
    tolua_variable(tolua_S, "type", lua_get_b2BodyDef_type, lua_set_b2BodyDef_type);
    tolua_variable(tolua_S, "position", lua_get_b2BodyDef_position, lua_set_b2BodyDef_position);
    tolua_variable(tolua_S, "angle", lua_get_b2BodyDef_angle, lua_set_b2BodyDef_angle);
    tolua_variable(tolua_S, "linearVelocity", lua_get_b2BodyDef_linearVelocity, lua_set_b2BodyDef_linearVelocity);
    tolua_variable(tolua_S, "angularVelocity", lua_get_b2BodyDef_angularVelocity, lua_set_b2BodyDef_angularVelocity);
    tolua_variable(tolua_S, "linearDamping", lua_get_b2BodyDef_linearDamping, lua_set_b2BodyDef_linearDamping);
    tolua_variable(tolua_S, "angularDamping", lua_get_b2BodyDef_angularDamping, lua_set_b2BodyDef_angularDamping);
    tolua_variable(tolua_S, "allowSleep", lua_get_b2BodyDef_allowSleep, lua_set_b2BodyDef_allowSleep);
    tolua_variable(tolua_S, "awake", lua_get_b2BodyDef_awake, lua_set_b2BodyDef_awake);
    tolua_variable(tolua_S, "fixedRotation", lua_get_b2BodyDef_fixedRotation, lua_set_b2BodyDef_fixedRotation);
    tolua_variable(tolua_S, "bullet", lua_get_b2BodyDef_bullet, lua_set_b2BodyDef_bullet);
    tolua_variable(tolua_S, "active", lua_get_b2BodyDef_active, lua_set_b2BodyDef_active);
    tolua_variable(tolua_S, "userData", lua_get_b2BodyDef_userData, lua_set_b2BodyDef_userData);
    tolua_variable(tolua_S, "gravityScale", lua_get_b2BodyDef_gravityScale, lua_set_b2BodyDef_gravityScale);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(b2BodyDef).name();
    g_luaType[typeName] = "b2BodyDef";
    g_typeCast["b2BodyDef"] = "b2BodyDef";
    return 1;
}

#ifndef LUA_DISABLE_lua_LuaBox2D_b2Body_CreateFixture
int lua_LuaBox2D_b2Body_CreateFixture(lua_State *tolua_S){
    int argc = 0;
    b2Body *cobj = nullptr;
    bool ok = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2Body", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2Body *)tolua_tousertype(tolua_S, 1, 0);

    argc = lua_gettop(tolua_S) - 1;
    do
    {
        if (argc == 1)
        {
            const b2FixtureDef *arg0;
            ok &= luaval_to_object<const b2FixtureDef>(tolua_S, 2, "b2FixtureDef", &arg0);
            if (!ok)
            {
                tolua_error(tolua_S, "invalid arguments in function 'lua_LuaBox2D_b2Body_CreateFixture', was expecting b2FixtureDef", nullptr);
                return 0;
            }
            b2Fixture *ret = (b2Fixture *)cobj->CreateFixture((const b2FixtureDef *)arg0);
            object_to_luaval<b2Fixture>(tolua_S, "b2Fixture", (b2Fixture *)ret);
            return 1;
        }
    } while (0);

    do
    {
        if(argc == 2 ){
            const b2Shape *arg0;
            ok &= luaval_to_object<const b2Shape>(tolua_S, 2, "b2Shape", &arg0);
            if (!ok)
            {
                tolua_error(tolua_S, "invalid arguments 1 in function 'lua_LuaBox2D_b2Body_CreateFixture', was expecting b2Shape", nullptr);
                return 0;
            }
            double arg1;
            ok &= luaval_to_number(tolua_S, 3, &arg1, "b2Body:CreateFixture");
            if (!ok)
            {
                tolua_error(tolua_S, "invalid arguments 2 in function 'lua_LuaBox2D_b2Body_CreateFixture', was expecting number", nullptr);
                return 0;
            }
            b2Fixture *ret = (b2Fixture *)cobj->CreateFixture((const b2Shape *)arg0, arg1);
            object_to_luaval<b2Fixture>(tolua_S, "b2Fixture", (b2Fixture *)ret);
            return 1;
        }
    } while (0);
    
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2Body:CreateFixture", argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2Body_CreateFixture'.", &tolua_err);
#endif
    return 0;
}
#endif

#ifndef LUA_DISABLE_lua_LuaBox2D_b2Body_DestroyFixture
int lua_LuaBox2D_b2Body_DestroyFixture(lua_State *tolua_S){
    int argc = 0;
    b2Body *cobj = nullptr;
    bool ok = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2Body", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2Body *)tolua_tousertype(tolua_S, 1, 0);

    argc = lua_gettop(tolua_S) - 1;
    do
    {
        if (argc == 1)
        {
            b2Fixture *arg0;
            ok &= luaval_to_object<b2Fixture>(tolua_S, 2, "b2Fixture", &arg0);
            if (!ok)
            {
                tolua_error(tolua_S, "invalid arguments in function 'lua_LuaBox2D_b2Body_DestroyFixture', was expecting b2Fixture", nullptr);
                return 0;
            }

            cobj->DestroyFixture(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);
    
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2Body:DestroyFixture", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2Body_DestroyFixture'.", &tolua_err);
#endif
    return 0;
}
#endif

#ifndef LUA_DISABLE_lua_LuaBox2D_b2Body_SetTransform
int lua_LuaBox2D_b2Body_SetTransform(lua_State *tolua_S){
    int argc = 0;
    b2Body *cobj = nullptr;
    bool ok = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2Body", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2Body *)tolua_tousertype(tolua_S, 1, 0);

    argc = lua_gettop(tolua_S) - 1;
    do
    {
        if (argc == 2)
        {
            const b2Vec2 *arg0;
            ok &= luaval_to_object<const b2Vec2>(tolua_S, 2, "b2Vec2", &arg0);
            if (!ok)
            {
                tolua_error(tolua_S, "invalid arguments in function 'lua_LuaBox2D_b2Body_SetTransform', was expecting b2Vec2", nullptr);
                return 0;
            }

            double arg1;
            ok &= luaval_to_number(tolua_S, 3, &arg1, "b2Body:SetTransform");
            if (!ok)
            {
                tolua_error(tolua_S, "invalid arguments in function 'lua_LuaBox2D_b2Body_SetTransform', was expecting number", nullptr);
                return 0;
            }
 
            cobj->SetTransform(*arg0, arg1);
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);
    
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2Body:SetTransform", argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2Body_SetTransform'.", &tolua_err);
#endif
    return 0;
}
#endif

#ifndef LUA_DISABLE_lua_LuaBox2D_b2Body_GetTransform
int lua_LuaBox2D_b2Body_GetTransform(lua_State *tolua_S){
    int argc = 0;
    b2Body *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2Body", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2Body *)tolua_tousertype(tolua_S, 1, 0);

    argc = lua_gettop(tolua_S) - 1;
    do
    {
        if (argc == 0)
        {
            const b2Transform& ret =  (const b2Transform&)cobj->GetTransform();
            object_to_luaval<const b2Transform>(tolua_S, "b2Transform", (const b2Transform *)&ret);
            return 1;
        }
    } while (0);
    
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2Bodty:GetTransform", argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2Body_GetTransform'.", &tolua_err);
#endif
    return 0;
}
#endif

#ifndef LUA_DISABLE_lua_LuaBox2D_b2Body_GetPosition
int lua_LuaBox2D_b2Body_GetPosition(lua_State *tolua_S){
    int argc = 0;
    b2Body *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2Body", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2Body *)tolua_tousertype(tolua_S, 1, 0);

    argc = lua_gettop(tolua_S) - 1;
    if (argc == 0)
    {
        const b2Vec2& ret =  (const b2Vec2&)cobj->GetPosition();
        object_to_luaval<const b2Vec2>(tolua_S, "b2Vec2", (const b2Vec2 *)&ret);
        return 1;
    }

    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2Bodty:GetTransform", argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2Body_GetPosition'.", &tolua_err);
#endif
    return 0;
}
#endif


#ifndef LUA_DISABLE_lua_LuaBox2D_b2Body_GetAngle
int lua_LuaBox2D_b2Body_GetAngle(lua_State *tolua_S){
    int argc = 0;
    b2Body *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2Body", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2Body *)tolua_tousertype(tolua_S, 1, 0);

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        float32 ret = cobj->GetAngle();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }

    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2Bodty:GetAngle", argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2Body_GetPosition'.", &tolua_err);
#endif
    return 0;
}
#endif

#ifndef LUA_DISABLE_lua_LuaBox2D_b2Body_GetWorldCenter
int lua_LuaBox2D_b2Body_GetWorldCenter(lua_State *tolua_S){
    int argc = 0;
    b2Body *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2Body", 0, &tolua_err))
        goto tolua_lerror;
#endif
    cobj = (b2Body *)tolua_tousertype(tolua_S, 1, 0);

    argc = lua_gettop(tolua_S) - 1;
    if (argc == 0)
    {
        const b2Vec2& ret =  (const b2Vec2&)cobj->GetWorldCenter();
        object_to_luaval<const b2Vec2>(tolua_S, "b2Vec2", (const b2Vec2 *)&ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2Bodty:GetWorldCenter", argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2Body_GetWorldCenter'.", &tolua_err);
#endif
    return 0;
}
#endif

#ifndef LUA_DISABLE_lua_LuaBox2D_b2Body_GetLocalCenter
int lua_LuaBox2D_b2Body_GetLocalCenter(lua_State *tolua_S){
    int argc = 0;
    b2Body *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2Body", 0, &tolua_err))
        goto tolua_lerror;
#endif
    cobj = (b2Body *)tolua_tousertype(tolua_S, 1, 0);

    argc = lua_gettop(tolua_S) - 1;
    if (argc == 0)
    {
        const b2Vec2& ret =  (const b2Vec2&)cobj->GetLocalCenter();
        object_to_luaval<const b2Vec2>(tolua_S, "b2Vec2", (const b2Vec2 *)&ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2Bodty:GetLocalCenter", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2Body_GetLocalCenter'.", &tolua_err);
#endif
    return 0;
}
#endif

#ifndef LUA_DISABLE_lua_LuaBox2D_b2Body_SetLinearVelocity
int lua_LuaBox2D_b2Body_SetLinearVelocity(lua_State *tolua_S){
    int argc = 0;
    b2Body *cobj = nullptr;
    bool ok = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2Body", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2Body *)tolua_tousertype(tolua_S, 1, 0);

    argc = lua_gettop(tolua_S) - 1;
    if (argc == 1)
    {
        const b2Vec2 *arg0;
        ok &= luaval_to_object<const b2Vec2>(tolua_S, 2, "const b2Vec2", &arg0);
        if (!ok)
        {
            tolua_error(tolua_S, "invalid arguments in function 'lua_LuaBox2D_b2Body_SetLinearVelocity', was expecting b2Vec2", nullptr);
            return 0;
        }
        cobj->SetLinearVelocity(*arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2Body:SetLinearVelocity", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2Body_SetLinearVelocity'.", &tolua_err);
#endif
    return 0;
}
#endif

#ifndef LUA_DISABLE_lua_LuaBox2D_b2Body_GetLinearVelocity
int lua_LuaBox2D_b2Body_GetLinearVelocity(lua_State *tolua_S){
    int argc = 0;
    b2Body *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2Body", 0, &tolua_err))
        goto tolua_lerror;
#endif
    cobj = (b2Body *)tolua_tousertype(tolua_S, 1, 0);

    argc = lua_gettop(tolua_S) - 1;
    if (argc == 0)
    {
        const b2Vec2& ret =  (const b2Vec2&)cobj->GetLinearVelocity();
        object_to_luaval<const b2Vec2>(tolua_S, "b2Vec2", &ret);
        // tolua_pushusertype(tolua_S,(void*)&ret,"const b2Vec2");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2Bodty:GetLinearVelocity", argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2Body_GetLinearVelocity'.", &tolua_err);
#endif
    return 0;
}
#endif

#ifndef LUA_DISABLE_lua_LuaBox2D_b2Body_SetAngularVelocity
int lua_LuaBox2D_b2Body_SetAngularVelocity(lua_State *tolua_S){
    int argc = 0;
    b2Body *cobj = nullptr;
    bool ok = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2Body", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2Body *)tolua_tousertype(tolua_S, 1, 0);

    argc = lua_gettop(tolua_S) - 1;
    if (argc == 1)
    {
        double arg0;
        ok &= luaval_to_number(tolua_S, 2, &arg0, "b2Body:SetAngularVelocity");
        if (!ok)
        {
            tolua_error(tolua_S, "invalid arguments in function 'lua_LuaBox2D_b2Body_SetAngularVelocity', was expecting number", nullptr);
            return 0;
        }

        cobj->SetAngularVelocity(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2Body:SetAngularVelocity", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2Body_SetAngularVelocity'.", &tolua_err);
#endif
    return 0;
}
#endif

#ifndef LUA_DISABLE_lua_LuaBox2D_b2Body_GetAngularVelocity
int lua_LuaBox2D_b2Body_GetAngularVelocity(lua_State *tolua_S){
    int argc = 0;
    b2Body *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2Body", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2Body *)tolua_tousertype(tolua_S, 1, 0);

    argc = lua_gettop(tolua_S) - 1;
    do
    {
        if (argc == 0)
        {
            float32 ret = cobj->GetAngularVelocity();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    } while (0);
    
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2Bodty:GetAngularVelocity", argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2Body_GetAngularVelocity'.", &tolua_err);
#endif
    return 0;
}
#endif

#ifndef LUA_DISABLE_lua_LuaBox2D_b2Body_ApplyForce
int lua_LuaBox2D_b2Body_ApplyForce(lua_State *tolua_S){
    int argc = 0;
    b2Body *cobj = nullptr;
    bool ok = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2Body", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2Body *)tolua_tousertype(tolua_S, 1, 0);

    argc = lua_gettop(tolua_S) - 1;
    if (argc == 3)
    {
        const b2Vec2 *arg0;
        ok &= luaval_to_object<const b2Vec2>(tolua_S, 2, "const b2Vec2", &arg0);
        if (!ok)
        {
            tolua_error(tolua_S, "invalid arguments 1 in function 'lua_LuaBox2D_b2Body_ApplyForce', was expecting b2Vec2", nullptr);
            return 0;
        }

        const b2Vec2 *arg1;
        ok &= luaval_to_object<const b2Vec2>(tolua_S, 3, "const b2Vec2", &arg1);
        if (!ok)
        {
            tolua_error(tolua_S, "invalid arguments 2 in function 'lua_LuaBox2D_b2Body_ApplyForce', was expecting b2Vec2", nullptr);
            return 0;
        }

        bool arg2;
        ok &= luaval_to_boolean(tolua_S, 4, &arg2, "b2Body:SetAngularVelocity");
        if (!ok)
        {
            tolua_error(tolua_S, "invalid arguments 2 in function 'lua_LuaBox2D_b2Body_ApplyForce', was expecting boolean", nullptr);
            return 0;
        }

        cobj->ApplyForce(*arg0, *arg1, arg2);
        lua_settop(tolua_S, 1);
        return 1;
    }

    if (argc == 2)
    {
        const b2Vec2 *arg0;
        ok &= luaval_to_object<const b2Vec2>(tolua_S, 2, "const b2Vec2", &arg0);
        if (!ok)
        {
            tolua_error(tolua_S, "invalid arguments 1 in function 'lua_LuaBox2D_b2Body_ApplyForce', was expecting b2Vec2", nullptr);
            return 0;
        }

        const b2Vec2 *arg1;
        ok &= luaval_to_object<const b2Vec2>(tolua_S, 3, "const b2Vec2", &arg1);
        if (!ok)
        {
            tolua_error(tolua_S, "invalid arguments 2 in function 'lua_LuaBox2D_b2Body_ApplyForce', was expecting b2Vec2", nullptr);
            return 0;
        }

        cobj->ApplyForce(*arg0, *arg1, false);
        lua_settop(tolua_S, 1);
        return 1;
    }
    
    
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d or %d \n", "b2Body:ApplyForce", argc, 3, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2Body_ApplyForce'.", &tolua_err);
#endif
    return 0;
}
#endif

#ifndef LUA_DISABLE_lua_LuaBox2D_b2Body_ApplyForceToCenter
int lua_LuaBox2D_b2Body_ApplyForceToCenter(lua_State *tolua_S){
    int argc = 0;
    b2Body *cobj = nullptr;
    bool ok = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2Body", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2Body *)tolua_tousertype(tolua_S, 1, 0);

    argc = lua_gettop(tolua_S) - 1;
    if (argc == 2)
    {
        const b2Vec2 *arg0;
        ok &= luaval_to_object<const b2Vec2>(tolua_S, 2, "const b2Vec2", &arg0);
        if (!ok)
        {
            tolua_error(tolua_S, "invalid arguments 1 in function 'lua_LuaBox2D_b2Body_ApplyForceToCenter', was expecting b2Vec2", nullptr);
            return 0;
        }

        bool arg2;
        ok &= luaval_to_boolean(tolua_S, 2, &arg2, "b2Body:SetAngularVelocity");
        if (!ok)
        {
            tolua_error(tolua_S, "invalid arguments 2 in function 'lua_LuaBox2D_b2Body_ApplyForceToCenter', was expecting boolean", nullptr);
            return 0;
        }

        cobj->ApplyForceToCenter(*arg0, arg2);
        lua_settop(tolua_S, 1);
        return 1;
    }

    if (argc == 1)
    {
        const b2Vec2 *arg0;
        ok &= luaval_to_object<const b2Vec2>(tolua_S, 2, "const b2Vec2", &arg0);
        if (!ok)
        {
            tolua_error(tolua_S, "invalid arguments 1 in function 'lua_LuaBox2D_b2Body_ApplyForceToCenter', was expecting b2Vec2", nullptr);
            return 0;
        }
        cobj->ApplyForceToCenter(*arg0, false);
        lua_settop(tolua_S, 1);
        return 1;
    }
    
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2Body:ApplyForceToCenter", argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2Body_ApplyForceToCenter'.", &tolua_err);
#endif
    return 0;
}
#endif

#ifndef LUA_DISABLE_lua_LuaBox2D_b2Body_ApplyTorque
int lua_LuaBox2D_b2Body_ApplyTorque(lua_State *tolua_S){
    int argc = 0;
    b2Body *cobj = nullptr;
    bool ok = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2Body", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2Body *)tolua_tousertype(tolua_S, 1, 0);

    argc = lua_gettop(tolua_S) - 1;
    if (argc == 2)
    {
        double arg0;
        ok &= luaval_to_number(tolua_S, 2, &arg0, "b2Body:ApplyTorque");
        if (!ok)
        {
            tolua_error(tolua_S, "invalid arguments 1 in function 'lua_LuaBox2D_b2Body_ApplyTorque', was expecting number", nullptr);
            return 0;
        }

        bool arg2;
        ok &= luaval_to_boolean(tolua_S, 2, &arg2, "b2Body:SetAngularVelocity");
        if (!ok)
        {
            tolua_error(tolua_S, "invalid arguments 2 in function 'lua_LuaBox2D_b2Body_ApplyTorque', was expecting boolean", nullptr);
            return 0;
        }

        cobj->ApplyTorque(arg0, arg2);
        lua_settop(tolua_S, 1);
        return 1;
    }
    
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2Body:ApplyTorque", argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2Body_ApplyTorque'.", &tolua_err);
#endif
    return 0;
}
#endif

#ifndef LUA_DISABLE_lua_LuaBox2D_b2Body_ApplyLinearImpulse
int lua_LuaBox2D_b2Body_ApplyLinearImpulse(lua_State *tolua_S){
    int argc = 0;
    b2Body *cobj = nullptr;
    bool ok = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2Body", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2Body *)tolua_tousertype(tolua_S, 1, 0);

    argc = lua_gettop(tolua_S) - 1;
    if (argc == 3)
    {
        const b2Vec2 *arg0;
        ok &= luaval_to_object<const b2Vec2>(tolua_S, 2, "const b2Vec2", &arg0);
        if (!ok)
        {
            tolua_error(tolua_S, "invalid arguments 1 in function 'lua_LuaBox2D_b2Body_ApplyLinearImpulse', was expecting b2Vec2", nullptr);
            return 0;
        }

        const b2Vec2 *arg1;
        ok &= luaval_to_object<const b2Vec2>(tolua_S, 3, "const b2Vec2", &arg1);
        if (!ok)
        {
            tolua_error(tolua_S, "invalid arguments 2 in function 'lua_LuaBox2D_b2Body_ApplyLinearImpulse', was expecting b2Vec2", nullptr);
            return 0;
        }

        bool arg2;
        ok &= luaval_to_boolean(tolua_S, 4, &arg2, "b2Body:ApplyLinearImpulse");
        if (!ok)
        {
            tolua_error(tolua_S, "invalid arguments 3 in function 'lua_LuaBox2D_b2Body_ApplyLinearImpulse', was expecting boolean", nullptr);
            return 0;
        }

        cobj->ApplyLinearImpulse(*arg0, *arg1, arg2);
        lua_settop(tolua_S, 1);
        return 1;
    }

        if (argc == 2)
    {
        const b2Vec2 *arg0;
        ok &= luaval_to_object<const b2Vec2>(tolua_S, 2, "const b2Vec2", &arg0);
        if (!ok)
        {
            tolua_error(tolua_S, "invalid arguments 1 in function 'lua_LuaBox2D_b2Body_ApplyLinearImpulse', was expecting b2Vec2", nullptr);
            return 0;
        }

        const b2Vec2 *arg1;
        ok &= luaval_to_object<const b2Vec2>(tolua_S, 3, "const b2Vec2", &arg1);
        if (!ok)
        {
            tolua_error(tolua_S, "invalid arguments 2 in function 'lua_LuaBox2D_b2Body_ApplyLinearImpulse', was expecting b2Vec2", nullptr);
            return 0;
        }
        cobj->ApplyLinearImpulse(*arg0, *arg1, false);
        lua_settop(tolua_S, 1);
        return 1;
    }
    
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2Body:ApplyLinearImpulse", argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2Body_ApplyLinearImpulse'.", &tolua_err);
#endif
    return 0;
}
#endif

#ifndef LUA_DISABLE_lua_LuaBox2D_b2Body_ApplyAngularImpulse
int lua_LuaBox2D_b2Body_ApplyAngularImpulse(lua_State *tolua_S){
    int argc = 0;
    b2Body *cobj = nullptr;
    bool ok = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2Body", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2Body *)tolua_tousertype(tolua_S, 1, 0);

    argc = lua_gettop(tolua_S) - 1;
    if (argc == 2)
    {
        double arg0;
        ok &= luaval_to_number(tolua_S, 2, &arg0, "b2Body:ApplyAngularImpulse");
        if (!ok)
        {
            tolua_error(tolua_S, "invalid arguments 1 in function 'lua_LuaBox2D_b2Body_ApplyAngularImpulse', was expecting b2Vec2", nullptr);
            return 0;
        }

        bool arg1;
        ok &= luaval_to_boolean(tolua_S, 3, &arg1, "b2Body:ApplyAngularImpulse");
        if (!ok)
        {
            tolua_error(tolua_S, "invalid arguments 2 in function 'lua_LuaBox2D_b2Body_ApplyAngularImpulse', was expecting boolean", nullptr);
            return 0;
        }

        cobj->ApplyAngularImpulse(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2Body:ApplyAngularImpulse", argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2Body_ApplyAngularImpulse'.", &tolua_err);
#endif
    return 0;
}
#endif

#ifndef LUA_DISABLE_lua_LuaBox2D_b2Body_GetMass
int lua_LuaBox2D_b2Body_GetMass(lua_State *tolua_S){
    int argc = 0;
    b2Body *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2Body", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2Body *)tolua_tousertype(tolua_S, 1, 0);
    argc = lua_gettop(tolua_S) - 1;
    if (argc == 0)
    {
        float32 ret = cobj->GetMass();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2Bodty:GetMass", argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2Body_GetMass'.", &tolua_err);
#endif
    return 0;
}
#endif

#ifndef LUA_DISABLE_lua_LuaBox2D_b2Body_GetInertia
int lua_LuaBox2D_b2Body_GetInertia(lua_State *tolua_S){
    int argc = 0;
    b2Body *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2Body", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2Body *)tolua_tousertype(tolua_S, 1, 0);
    argc = lua_gettop(tolua_S) - 1;
    if (argc == 0)
    {
        float32 ret = cobj->GetInertia();
        tolua_pushnumber(tolua_S, (lua_Number)ret);
        return 1;
    }
    
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2Bodty:GetInertia", argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2Body_GetInertia'.", &tolua_err);
#endif
    return 0;
}
#endif

#ifndef LUA_DISABLE_lua_LuaBox2D_b2Body_GetMassData
int lua_LuaBox2D_b2Body_GetMassData(lua_State *tolua_S){
    int argc = 0;
    b2Body *cobj = nullptr;
    bool ok = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2Body", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2Body *)tolua_tousertype(tolua_S, 1, 0);

    argc = lua_gettop(tolua_S) - 1;
    if (argc == 1)
    {
        b2MassData *arg0;
        ok &= luaval_to_object<b2MassData>(tolua_S, 2, "b2MassData", &arg0);
        if (!ok)
        {
            tolua_error(tolua_S, "invalid arguments 1 in function 'lua_LuaBox2D_b2Body_GetMassData', was expecting b2MassData", nullptr);
            return 0;
        }
        cobj->GetMassData(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2Body:GetMassData", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2Body_GetMassData'.", &tolua_err);
#endif
    return 0;
}
#endif

#ifndef LUA_DISABLE_lua_LuaBox2D_b2Body_SetMassData
int lua_LuaBox2D_b2Body_SetMassData(lua_State *tolua_S){
    int argc = 0;
    b2Body *cobj = nullptr;
    bool ok = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2Body", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2Body *)tolua_tousertype(tolua_S, 1, 0);

    argc = lua_gettop(tolua_S) - 1;
    if (argc == 1)
    {
        b2MassData *arg0;
        ok &= luaval_to_object<b2MassData>(tolua_S, 2, "b2MassData", &arg0);
        if (!ok)
        {
            tolua_error(tolua_S, "invalid arguments 1 in function 'lua_LuaBox2D_b2Body_SetMassData', was expecting b2MassData", nullptr);
            return 0;
        }
        cobj->SetMassData(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2Body:SetMassData", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2Body_SetMassData'.", &tolua_err);
#endif
    return 0;
}
#endif

#ifndef LUA_DISABLE_lua_LuaBox2D_b2Body_ResetMassData
int lua_LuaBox2D_b2Body_ResetMassData(lua_State *tolua_S){
    int argc = 0;
    b2Body *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2Body", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2Body *)tolua_tousertype(tolua_S, 1, 0);

    argc = lua_gettop(tolua_S) - 1;
    if (argc == 0)
    {
        cobj->ResetMassData();
        lua_settop(tolua_S, 1);
        return 1;
    }
    
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2Body:ResetMassData", argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2Body_ResetMassData'.", &tolua_err);
#endif
    return 0;
}
#endif

#ifndef LUA_DISABLE_lua_LuaBox2D_b2Body_GetWorldPoint
int lua_LuaBox2D_b2Body_GetWorldPoint(lua_State *tolua_S){
    int argc = 0;
    b2Body *cobj = nullptr;
    bool ok = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2Body", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2Body *)tolua_tousertype(tolua_S, 1, 0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_LuaBox2D_b2Body_GetWorldPoint'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if(argc == 1){
        const b2Vec2 *arg0;
        ok &= luaval_to_object<const b2Vec2>(tolua_S, 2, "const b2Vec2", &arg0);
        if (!ok)
        {
            tolua_error(tolua_S, "invalid arguments 1 in function 'lua_LuaBox2D_b2Body_GetWorldPoint', was expecting b2Vec2", nullptr);
            return 0;
        }
        b2Vec2 newVec = cobj -> GetWorldPoint(*arg0);
        // object_to_luaval<b2Vec2>(tolua_S, "b2Vec2", (b2Vec2 *)&ret);
        b2Vec2 *ret = new b2Vec2(newVec.x, newVec.y);
        object_to_luaval(tolua_S, "b2Vec2", (b2Vec2 *)ret);
        tolua_register_gc(tolua_S, lua_gettop(tolua_S));
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2Body:GetWorldPoint", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2Body_GetWorldPoint'.", &tolua_err);
#endif
    return 0;  
}
#endif

#ifndef LUA_DISABLE_lua_LuaBox2D_b2Body_GetWorldVector
int lua_LuaBox2D_b2Body_GetWorldVector(lua_State *tolua_S){
    int argc = 0;
    b2Body *cobj = nullptr;
    bool ok = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2Body", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2Body *)tolua_tousertype(tolua_S, 1, 0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_LuaBox2D_b2Body_GetWorldVector'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if(argc == 1){

        const b2Vec2 *arg0;
        ok &= luaval_to_object<const b2Vec2>(tolua_S, 2, "const b2Vec2", &arg0);
        if (!ok)
        {
            tolua_error(tolua_S, "invalid arguments 1 in function 'lua_LuaBox2D_b2Body_GetWorldVector', was expecting b2Vec2", nullptr);
            return 0;
        }
        b2Vec2 newVec = cobj -> GetWorldVector(*arg0);
        // object_to_luaval<b2Vec2>(tolua_S, "b2Vec2", (b2Vec2 *)&ret);
        b2Vec2 *ret = new b2Vec2(newVec.x, newVec.y);
        object_to_luaval(tolua_S, "b2Vec2", (b2Vec2 *)ret);
        tolua_register_gc(tolua_S, lua_gettop(tolua_S));
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2Body:GetWorldVector", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2Body_GetWorldVector'.", &tolua_err);
#endif
    return 0;  
}
#endif

#ifndef LUA_DISABLE_lua_LuaBox2D_b2Body_GetLocalPoint
int lua_LuaBox2D_b2Body_GetLocalPoint(lua_State *tolua_S){
    int argc = 0;
    b2Body *cobj = nullptr;
    bool ok = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2Body", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2Body *)tolua_tousertype(tolua_S, 1, 0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_LuaBox2D_b2Body_GetLocalPoint'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if(argc == 1){

        const b2Vec2 *arg0;
        ok &= luaval_to_object<const b2Vec2>(tolua_S, 2, "const b2Vec2", &arg0);
        if (!ok)
        {
            tolua_error(tolua_S, "invalid arguments 1 in function 'lua_LuaBox2D_b2Body_GetLocalPoint', was expecting b2Vec2", nullptr);
            return 0;
        }
        b2Vec2 newVec = cobj -> GetLocalPoint(*arg0);
        // object_to_luaval<b2Vec2>(tolua_S, "b2Vec2", (b2Vec2 *)&ret);
        b2Vec2 *ret = new b2Vec2(newVec.x, newVec.y);
        object_to_luaval(tolua_S, "b2Vec2", (b2Vec2 *)ret);
        tolua_register_gc(tolua_S, lua_gettop(tolua_S));
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2Body:GetLocalPoint", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2Body_GetLocalPoint'.", &tolua_err);
#endif
    return 0; 
}
#endif

#ifndef LUA_DISABLE_lua_LuaBox2D_b2Body_GetLocalVector
int lua_LuaBox2D_b2Body_GetLocalVector(lua_State *tolua_S){
    int argc = 0;
    b2Body *cobj = nullptr;
    bool ok = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2Body", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2Body *)tolua_tousertype(tolua_S, 1, 0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_LuaBox2D_b2Body_GetLocalVector'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if(argc == 1){

        const b2Vec2 *arg0;
        ok &= luaval_to_object<const b2Vec2>(tolua_S, 2, "const b2Vec2", &arg0);
        if (!ok)
        {
            tolua_error(tolua_S, "invalid arguments 1 in function 'lua_LuaBox2D_b2Body_GetLocalVector', was expecting b2Vec2", nullptr);
            return 0;
        }
        b2Vec2 newVec = cobj -> GetLocalVector(*arg0);
        // object_to_luaval<b2Vec2>(tolua_S, "b2Vec2", (b2Vec2 *)&ret);
        b2Vec2 *ret = new b2Vec2(newVec.x, newVec.y);
        object_to_luaval(tolua_S, "b2Vec2", (b2Vec2 *)ret);
        tolua_register_gc(tolua_S, lua_gettop(tolua_S));
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2Body:GetLocalVector", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2Body_GetLocalVector'.", &tolua_err);
#endif
    return 0; 
}
#endif

#ifndef LUA_DISABLE_lua_LuaBox2D_b2Body_GetLinearVelocityFromWorldPoint
int lua_LuaBox2D_b2Body_GetLinearVelocityFromWorldPoint(lua_State *tolua_S){
    int argc = 0;
    b2Body *cobj = nullptr;
    bool ok = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2Body", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2Body *)tolua_tousertype(tolua_S, 1, 0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_LuaBox2D_b2Body_GetLinearVelocityFromWorldPoint'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if(argc == 1){

        const b2Vec2 *arg0;
        ok &= luaval_to_object<const b2Vec2>(tolua_S, 2, "const b2Vec2", &arg0);
        if (!ok)
        {
            tolua_error(tolua_S, "invalid arguments 1 in function 'lua_LuaBox2D_b2Body_GetLinearVelocityFromWorldPoint', was expecting b2Vec2", nullptr);
            return 0;
        }
        b2Vec2 newVec = cobj -> GetLinearVelocityFromWorldPoint(*arg0);
        // object_to_luaval<b2Vec2>(tolua_S, "b2Vec2", (b2Vec2 *)&ret);
        b2Vec2 *ret = new b2Vec2(newVec.x, newVec.y);
        object_to_luaval(tolua_S, "b2Vec2", (b2Vec2 *)ret);
        tolua_register_gc(tolua_S, lua_gettop(tolua_S));
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2Body:GetLinearVelocityFromLocalPoint", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2Body_GetLinearVelocityFromWorldPoint'.", &tolua_err);
#endif
    return 0; 
}
#endif

int lua_LuaBox2D_b2Body_GetLinearVelocityFromLocalPoint(lua_State *tolua_S){
        int argc = 0;
    b2Body *cobj = nullptr;
    bool ok = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2Body", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2Body *)tolua_tousertype(tolua_S, 1, 0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_LuaBox2D_b2Body_GetLinearVelocityFromLocalPoint'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if(argc == 1){

        const b2Vec2 *arg0;
        ok &= luaval_to_object<const b2Vec2>(tolua_S, 2, "const b2Vec2", &arg0);
        if (!ok)
        {
            tolua_error(tolua_S, "invalid arguments 1 in function 'lua_LuaBox2D_b2Body_GetLinearVelocityFromLocalPoint', was expecting b2Vec2", nullptr);
            return 0;
        }
        b2Vec2 newVec = cobj -> GetLinearVelocityFromLocalPoint(*arg0);
        // object_to_luaval<b2Vec2>(tolua_S, "b2Vec2", (b2Vec2 *)&ret);
        b2Vec2 *ret = new b2Vec2(newVec.x, newVec.y);
        object_to_luaval(tolua_S, "b2Vec2", (b2Vec2 *)ret);
        tolua_register_gc(tolua_S, lua_gettop(tolua_S));
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2Body:GetLinearVelocityFromLocalPoint", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2Body_GetLinearVelocityFromLocalPoint'.", &tolua_err);
#endif
    return 0; 
}


#ifndef LUA_DISABLE_lua_LuaBox2D_b2Body_GetLinearDamping
int lua_LuaBox2D_b2Body_GetLinearDamping(lua_State *tolua_S){
    int argc = 0;
    b2Body *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2Body", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2Body *)tolua_tousertype(tolua_S, 1, 0);
    argc = lua_gettop(tolua_S) - 1;
    if (argc == 0)
    {
        float32 ret = cobj->GetLinearDamping();
        tolua_pushnumber(tolua_S, (lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2Bodty:GetLinearDamping", argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2Body_GetLinearDamping'.", &tolua_err);
#endif
    return 0;
}
#endif

#ifndef LUA_DISABLE_lua_LuaBox2D_b2Body_SetLinearDamping
int lua_LuaBox2D_b2Body_SetLinearDamping(lua_State *tolua_S){
    int argc = 0;
    b2Body *cobj = nullptr;
    bool ok = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2Body", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2Body *)tolua_tousertype(tolua_S, 1, 0);

    argc = lua_gettop(tolua_S) - 1;
    if (argc == 1)
    {
        double arg0;
        ok &= luaval_to_number(tolua_S, 2, &arg0, "b2Body:SetLinearDamping");
        if (!ok)
        {
            tolua_error(tolua_S, "invalid arguments 1 in function 'lua_LuaBox2D_b2Body_SetLinearDamping', was expecting number", nullptr);
            return 0;
        }

        cobj->SetLinearDamping(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2Body:SetLinearDamping", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2Body_SetLinearDamping'.", &tolua_err);
#endif
    return 0;
}
#endif

#ifndef LUA_DISABLE_lua_LuaBox2D_b2Body_GetAngularDamping
int lua_LuaBox2D_b2Body_GetAngularDamping(lua_State *tolua_S){
    int argc = 0;
    b2Body *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2Body", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2Body *)tolua_tousertype(tolua_S, 1, 0);
    argc = lua_gettop(tolua_S) - 1;
    if (argc == 0)
    {
        float32 ret = cobj->GetAngularDamping();
        tolua_pushnumber(tolua_S, (lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2Bodty:GetAngularDamping", argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2Body_GetAngularDamping'.", &tolua_err);
#endif
    return 0;
}
#endif


#ifndef LUA_DISABLE_lua_LuaBox2D_b2Body_SetAngularDamping
int lua_LuaBox2D_b2Body_SetAngularDamping(lua_State *tolua_S){
    int argc = 0;
    b2Body *cobj = nullptr;
    bool ok = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2Body", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2Body *)tolua_tousertype(tolua_S, 1, 0);

    argc = lua_gettop(tolua_S) - 1;
    if (argc == 1)
    {
        double arg0;
        ok &= luaval_to_number(tolua_S, 2, &arg0, "b2Body:SetAngularDamping");
        if (!ok)
        {
            tolua_error(tolua_S, "invalid arguments 1 in function 'lua_LuaBox2D_b2Body_SetAngularDamping', was expecting number", nullptr);
            return 0;
        }

        cobj->SetAngularDamping(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2Body:SetAngularDamping", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2Body_SetAngularDamping'.", &tolua_err);
#endif
    return 0;
}
#endif

#ifndef LUA_DISABLE_lua_LuaBox2D_b2Body_GetGravityScale
int lua_LuaBox2D_b2Body_GetGravityScale(lua_State *tolua_S){
    int argc = 0;
    b2Body *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2Body", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2Body *)tolua_tousertype(tolua_S, 1, 0);
    argc = lua_gettop(tolua_S) - 1;
    if (argc == 0)
    {
        float32 ret = cobj->GetAngularDamping();
        tolua_pushnumber(tolua_S, (lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2Bodty:GetGravityScale", argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2Body_GetGravityScale'.", &tolua_err);
#endif
    return 0;
}
#endif

#ifndef LUA_DISABLE_lua_LuaBox2D_b2Body_SetGravityScale
int lua_LuaBox2D_b2Body_SetGravityScale(lua_State *tolua_S){
    int argc = 0;
    b2Body *cobj = nullptr;
    bool ok = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2Body", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2Body *)tolua_tousertype(tolua_S, 1, 0);

    argc = lua_gettop(tolua_S) - 1;
    if (argc == 1)
    {
        double arg0;
        ok &= luaval_to_number(tolua_S, 2, &arg0, "b2Body:SetGravityScale");
        if (!ok)
        {
            tolua_error(tolua_S, "invalid arguments 1 in function 'lua_LuaBox2D_b2Body_SetGravityScale', was expecting number", nullptr);
            return 0;
        }

        cobj->SetGravityScale(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2Body:SetGravityScale", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2Body_SetGravityScale'.", &tolua_err);
#endif
    return 0;
}
#endif

#ifndef LUA_DISABLE_lua_LuaBox2D_b2Body_SetType
int lua_LuaBox2D_b2Body_SetType(lua_State *tolua_S){
    int argc = 0;
    b2Body *cobj = nullptr;
    bool ok = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2Body", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2Body *)tolua_tousertype(tolua_S, 1, 0);

    argc = lua_gettop(tolua_S) - 1;
    if (argc == 1)
    {
        int32 arg0;
        ok &= luaval_to_int32(tolua_S, 2, &arg0, "b2Vec2:SetType");
        if (!ok)
        {
            tolua_error(tolua_S, "invalid arguments 1 in function 'lua_LuaBox2D_b2Body_SetType', was expecting number", nullptr);
        };
        cobj->SetType((b2BodyType)arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2Body:SetType", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2Body_SetType'.", &tolua_err);
#endif
    return 0;
}
#endif

#ifndef LUA_DISABLE_lua_LuaBox2D_b2Body_GetType
int lua_LuaBox2D_b2Body_GetType(lua_State *tolua_S){
    int argc = 0;
    b2Body *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2Body", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2Body *)tolua_tousertype(tolua_S, 1, 0);
    argc = lua_gettop(tolua_S) - 1;
    if (argc == 0)
    {
        int32 ret = cobj->GetType();
        tolua_pushnumber(tolua_S, (lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2Bodty:GetType", argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2Body_GetType'.", &tolua_err);
#endif
    return 0;
}
#endif

#ifndef LUA_DISABLE_lua_LuaBox2D_b2Body_SetBullet
int lua_LuaBox2D_b2Body_SetBullet(lua_State *tolua_S){
    int argc = 0;
    b2Body *cobj = nullptr;
    bool ok = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2Body", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2Body *)tolua_tousertype(tolua_S, 1, 0);

    argc = lua_gettop(tolua_S) - 1;
    if (argc == 1)
    {
        bool arg0;
        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "b2Body:SetBullet");
        if (!ok)
        {
            tolua_error(tolua_S, "invalid arguments 1 in function 'lua_LuaBox2D_b2Body_SetBullet', was expecting bool", nullptr);
        };
        cobj->SetBullet(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2Body:SetType", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2Body_SetBullet'.", &tolua_err);
#endif
    return 0;
}
#endif

#ifndef LUA_DISABLE_lua_LuaBox2D_b2Body_IsBullet
int lua_LuaBox2D_b2Body_IsBullet(lua_State *tolua_S){
    int argc = 0;
    b2Body *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2Body", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2Body *)tolua_tousertype(tolua_S, 1, 0);
    argc = lua_gettop(tolua_S) - 1;
    if (argc == 0)
    {
        bool ret = cobj->IsBullet();
        tolua_pushboolean(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2Bodty:IsBullet", argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2Body_IsBullet'.", &tolua_err);
#endif
    return 0;
}
#endif

#ifndef LUA_DISABLE_lua_LuaBox2D_b2Body_SetSleepingAllowed
int lua_LuaBox2D_b2Body_SetSleepingAllowed(lua_State *tolua_S){
    int argc = 0;
    b2Body *cobj = nullptr;
    bool ok = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2Body", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2Body *)tolua_tousertype(tolua_S, 1, 0);

    argc = lua_gettop(tolua_S) - 1;
    if (argc == 1)
    {
        bool arg0;
        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "b2Body:SetSleepingAllowed");
        if (!ok)
        {
            tolua_error(tolua_S, "invalid arguments 1 in function 'lua_LuaBox2D_b2Body_SetSleepingAllowed', was expecting bool", nullptr);
        };
        cobj->SetSleepingAllowed(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2Body:SetSleepingAllowed", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2Body_SetSleepingAllowed'.", &tolua_err);
#endif
    return 0;
}
#endif

#ifndef LUA_DISABLE_lua_LuaBox2D_b2Body_IsSleepingAllowed
int lua_LuaBox2D_b2Body_IsSleepingAllowed(lua_State *tolua_S){
    int argc = 0;
    b2Body *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2Body", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2Body *)tolua_tousertype(tolua_S, 1, 0);
    argc = lua_gettop(tolua_S) - 1;
    if (argc == 0)
    {
        bool ret = cobj->IsSleepingAllowed();
        tolua_pushboolean(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2Bodty:IsSleepingAllowed", argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2Body_IsSleepingAllowed'.", &tolua_err);
#endif
    return 0;
}
#endif

#ifndef LUA_DISABLE_lua_LuaBox2D_b2Body_SetAwake
int lua_LuaBox2D_b2Body_SetAwake(lua_State *tolua_S){
    int argc = 0;
    b2Body *cobj = nullptr;
    bool ok = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2Body", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2Body *)tolua_tousertype(tolua_S, 1, 0);

    argc = lua_gettop(tolua_S) - 1;
    if (argc == 1)
    {
        bool arg0;
        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "b2Body:SetAwake");
        if (!ok)
        {
            tolua_error(tolua_S, "invalid arguments 1 in function 'lua_LuaBox2D_b2Body_SetAwake', was expecting bool", nullptr);
        };
        cobj->SetAwake(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2Body:SetAwake", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2Body_SetAwake'.", &tolua_err);
#endif
    return 0;
}
#endif

#ifndef LUA_DISABLE_lua_LuaBox2D_b2Body_SetAwake
int lua_LuaBox2D_b2Body_IsAwake(lua_State *tolua_S){
    int argc = 0;
    b2Body *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2Body", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2Body *)tolua_tousertype(tolua_S, 1, 0);
    argc = lua_gettop(tolua_S) - 1;
    if (argc == 0)
    {
        bool ret = cobj->IsAwake();
        tolua_pushboolean(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2Bodty:IsAwake", argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2Body_IsAwake'.", &tolua_err);
#endif
    return 0;
}
#endif

#ifndef LUA_DISABLE_lua_LuaBox2D_b2Body_SetActive
int lua_LuaBox2D_b2Body_SetActive(lua_State *tolua_S){
    int argc = 0;
    b2Body *cobj = nullptr;
    bool ok = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2Body", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2Body *)tolua_tousertype(tolua_S, 1, 0);

    argc = lua_gettop(tolua_S) - 1;
    if (argc == 1)
    {
        bool arg0;
        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "b2Body:SetActive");
        if (!ok)
        {
            tolua_error(tolua_S, "invalid arguments 1 in function 'lua_LuaBox2D_b2Body_SetActive', was expecting bool", nullptr);
        };
        cobj->SetActive(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2Body:SetActive", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2Body_SetActive'.", &tolua_err);
#endif
    return 0;
}
#endif

#ifndef LUA_DISABLE_lua_LuaBox2D_b2Body_IsActive
int lua_LuaBox2D_b2Body_IsActive(lua_State *tolua_S){
    int argc = 0;
    b2Body *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2Body", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2Body *)tolua_tousertype(tolua_S, 1, 0);
    argc = lua_gettop(tolua_S) - 1;
    if (argc == 0)
    {
        bool ret = cobj->IsActive();
        tolua_pushboolean(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2Bodty:IsActive", argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2Body_IsActive'.", &tolua_err);
#endif
    return 0;
}
#endif

#ifndef LUA_DISABLE_lua_LuaBox2D_b2Body_SetFixedRotation
int lua_LuaBox2D_b2Body_SetFixedRotation(lua_State *tolua_S){
    int argc = 0;
    b2Body *cobj = nullptr;
    bool ok = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2Body", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2Body *)tolua_tousertype(tolua_S, 1, 0);

    argc = lua_gettop(tolua_S) - 1;
    if (argc == 1)
    {
        bool arg0;
        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "b2Body:SetFixedRotation");
        if (!ok)
        {
            tolua_error(tolua_S, "invalid arguments 1 in function 'lua_LuaBox2D_b2Body_SetFixedRotation', was expecting bool", nullptr);
        };
        cobj->SetFixedRotation(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2Body:SetFixedRotation", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2Body_SetFixedRotation'.", &tolua_err);
#endif
    return 0;
}
#endif

#ifndef LUA_DISABLE_lua_LuaBox2D_b2Body_IsFixedRotation
int lua_LuaBox2D_b2Body_IsFixedRotation(lua_State *tolua_S){
    int argc = 0;
    b2Body *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2Body", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2Body *)tolua_tousertype(tolua_S, 1, 0);
    argc = lua_gettop(tolua_S) - 1;
    if (argc == 0)
    {
        bool ret = cobj->IsFixedRotation();
        tolua_pushboolean(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2Bodty:IsFixedRotation", argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2Body_IsFixedRotation'.", &tolua_err);
#endif
    return 0;
}
#endif

#ifndef LUA_DISABLE_lua_LuaBox2D_b2Body_GetFixtureList
int lua_LuaBox2D_b2Body_GetFixtureList(lua_State *tolua_S){
    int argc = 0;
    b2Body *cobj = nullptr;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2Body", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2Body *)tolua_tousertype(tolua_S, 1, 0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_LuaBox2D_b2Body_GetFixtureList'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if(argc == 0){
        b2Fixture  *ret = cobj -> GetFixtureList();
        object_to_luaval<b2Fixture>(tolua_S, "b2Fixture", (b2Fixture *)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2Body:GetFixtureList", argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2Body_GetFixtureList'.", &tolua_err);
#endif
    return 0; 
}
#endif

#ifndef LUA_DISABLE_lua_LuaBox2D_b2Body_GetJointList
int lua_LuaBox2D_b2Body_GetJointList(lua_State *tolua_S){
    int argc = 0;
    b2Body *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2Body", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2Body *)tolua_tousertype(tolua_S, 1, 0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_LuaBox2D_b2Body_GetJointList'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if(argc == 0){
        b2JointEdge  *ret = cobj -> GetJointList();
        object_to_luaval<b2JointEdge>(tolua_S, "b2JointEdge", (b2JointEdge *)&ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2Body:GetJointList", argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2Body_GetJointList'.", &tolua_err);
#endif
    return 0; 
}
#endif

#ifndef LUA_DISABLE_lua_LuaBox2D_b2Body_GetContactList
int lua_LuaBox2D_b2Body_GetContactList(lua_State *tolua_S){
    int argc = 0;
    b2Body *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2Body", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2Body *)tolua_tousertype(tolua_S, 1, 0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_LuaBox2D_b2Body_GetContactList'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if(argc == 0){
        b2ContactEdge  *ret = cobj -> GetContactList();
        object_to_luaval<b2ContactEdge>(tolua_S, "b2ContactEdge", (b2ContactEdge *)&ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2Body:GetContactList", argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2Body_GetContactList'.", &tolua_err);
#endif
    return 0; 
}
#endif

#ifndef LUA_DISABLE_lua_LuaBox2D_b2Body_GetNext
int lua_LuaBox2D_b2Body_GetNext(lua_State *tolua_S){
    int argc = 0;
    b2Body *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2Body", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2Body *)tolua_tousertype(tolua_S, 1, 0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_LuaBox2D_b2Body_GetNext'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if(argc == 0){
        b2Body  *ret = cobj -> GetNext();
        object_to_luaval<b2Body>(tolua_S, "b2Body", (b2Body *)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2Body:GetNext", argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2Body_GetNext'.", &tolua_err);
#endif
    return 0; 
}
#endif

#ifndef LUA_DISABLE_lua_LuaBox2D_b2Body_GetUserData
int lua_LuaBox2D_b2Body_GetUserData(lua_State *tolua_S){
    int argc = 0;
    b2Body *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2Body", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2Body *)tolua_tousertype(tolua_S, 1, 0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_LuaBox2D_b2Body_GetUserData'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if(argc == 0){
        void  *ret = (void*) cobj -> GetUserData();
        // object_to_luaval<void>(tolua_S, "void", (void *)&ret);
        tolua_pushuserdata(tolua_S,(void*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2Body:GetUserData", argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2Body_GetUserData'.", &tolua_err);
#endif
    return 0; 
}
#endif

#ifndef LUA_DISABLE_lua_LuaBox2D_b2Body_SetUserData
int lua_LuaBox2D_b2Body_SetUserData(lua_State *tolua_S){
    int argc = 0;
    b2Body *cobj = nullptr;


#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2Body", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2Body *)tolua_tousertype(tolua_S, 1, 0);

    argc = lua_gettop(tolua_S) - 1;
    if (argc == 1)
    {
        void* arg0;
        arg0 = ((void*)  tolua_touserdata(tolua_S, 2, 0));
        cobj->SetUserData(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2Body:SetUserData", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2Body_SetUserData'.", &tolua_err);
#endif
    return 0;
}
#endif

#ifndef LUA_DISABLE_lua_LuaBox2D_b2Body_GetWorld
int lua_LuaBox2D_b2Body_GetWorld(lua_State *tolua_S){
    int argc = 0;
    b2Body *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2Body", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2Body *)tolua_tousertype(tolua_S, 1, 0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_LuaBox2D_b2Body_GetWorld'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if(argc == 0){
        void  *ret = cobj -> GetWorld();
        object_to_luaval<void>(tolua_S, "void", (void *)&ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2Body:GetWorld", argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2Body_GetWorld'.", &tolua_err);
#endif
    return 0; 
}
#endif

#ifndef LUA_DISABLE_lua_LuaBox2D_b2Body_Dump
int lua_LuaBox2D_b2Body_Dump(lua_State *tolua_S){
    int argc = 0;
    b2Body *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2Body", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2Body *)tolua_tousertype(tolua_S, 1, 0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_LuaBox2D_b2Body_Dump'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if(argc == 0){
        cobj -> Dump();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2Body:Dump", argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2Body_Dump'.", &tolua_err);
#endif
    return 0; 
}
#endif

int lua_register_cocos2dx_b2Body(lua_State *tolua_S){
    tolua_usertype(tolua_S, "b2Body");
    tolua_cclass(tolua_S, "b2Body", "b2Body", "", nullptr);
    tolua_beginmodule(tolua_S, "b2Body");
    tolua_function(tolua_S, "CreateFixture", lua_LuaBox2D_b2Body_CreateFixture);
    tolua_function(tolua_S, "DestroyFixture", lua_LuaBox2D_b2Body_DestroyFixture);
    tolua_function(tolua_S, "SetTransform", lua_LuaBox2D_b2Body_SetTransform);
    tolua_function(tolua_S, "GetTransform", lua_LuaBox2D_b2Body_GetTransform);
    tolua_function(tolua_S, "GetPosition", lua_LuaBox2D_b2Body_GetPosition);
    tolua_function(tolua_S, "GetAngle", lua_LuaBox2D_b2Body_GetAngle);
    tolua_function(tolua_S, "GetWorldCenter", lua_LuaBox2D_b2Body_GetWorldCenter);
    tolua_function(tolua_S, "GetLocalCenter", lua_LuaBox2D_b2Body_GetLocalCenter);
    tolua_function(tolua_S, "SetLinearVelocity", lua_LuaBox2D_b2Body_SetLinearVelocity);
    tolua_function(tolua_S, "GetLinearVelocity", lua_LuaBox2D_b2Body_GetLinearVelocity);
    tolua_function(tolua_S, "SetAngularVelocity", lua_LuaBox2D_b2Body_SetAngularVelocity);
    tolua_function(tolua_S, "GetAngularVelocity", lua_LuaBox2D_b2Body_GetAngularVelocity);
    tolua_function(tolua_S, "ApplyForce", lua_LuaBox2D_b2Body_ApplyForce);
    tolua_function(tolua_S, "ApplyForceToCenter", lua_LuaBox2D_b2Body_ApplyForceToCenter);
    tolua_function(tolua_S, "ApplyTorque", lua_LuaBox2D_b2Body_ApplyTorque); 
    tolua_function(tolua_S, "ApplyLinearImpulse", lua_LuaBox2D_b2Body_ApplyLinearImpulse); 
    tolua_function(tolua_S, "ApplyAngularImpulse", lua_LuaBox2D_b2Body_ApplyAngularImpulse); 
    tolua_function(tolua_S, "GetMass", lua_LuaBox2D_b2Body_GetMass); 
    tolua_function(tolua_S, "GetInertia", lua_LuaBox2D_b2Body_GetInertia); 
    tolua_function(tolua_S, "GetMassData", lua_LuaBox2D_b2Body_GetMassData); 
    tolua_function(tolua_S, "SetMassData", lua_LuaBox2D_b2Body_SetMassData); 
    tolua_function(tolua_S, "ResetMassData", lua_LuaBox2D_b2Body_ResetMassData); 
    tolua_function(tolua_S, "GetWorldPoint", lua_LuaBox2D_b2Body_GetWorldPoint); 
    tolua_function(tolua_S, "GetWorldVector", lua_LuaBox2D_b2Body_GetWorldVector); 
    tolua_function(tolua_S, "GetLocalPoint", lua_LuaBox2D_b2Body_GetLocalPoint); 
    tolua_function(tolua_S, "GetLocalVector", lua_LuaBox2D_b2Body_GetLocalVector); 
    tolua_function(tolua_S, "GetLinearVelocityFromWorldPoint", lua_LuaBox2D_b2Body_GetLinearVelocityFromWorldPoint); 
    tolua_function(tolua_S, "GetLinearVelocityFromLocalPoint", lua_LuaBox2D_b2Body_GetLinearVelocityFromLocalPoint); 
    tolua_function(tolua_S, "GetLinearDamping", lua_LuaBox2D_b2Body_GetLinearDamping); 
    tolua_function(tolua_S, "SetLinearDamping", lua_LuaBox2D_b2Body_SetLinearDamping); 
    tolua_function(tolua_S, "GetAngularDamping", lua_LuaBox2D_b2Body_GetAngularDamping); 
    tolua_function(tolua_S, "SetAngularDamping", lua_LuaBox2D_b2Body_SetAngularDamping); 
    tolua_function(tolua_S, "GetGravityScale", lua_LuaBox2D_b2Body_GetGravityScale); 
    tolua_function(tolua_S, "SetGravityScale", lua_LuaBox2D_b2Body_SetGravityScale); 
    tolua_function(tolua_S, "SetType", lua_LuaBox2D_b2Body_SetType); 
    tolua_function(tolua_S, "GetType", lua_LuaBox2D_b2Body_GetType); 
    tolua_function(tolua_S, "SetBullet", lua_LuaBox2D_b2Body_SetBullet); 
    tolua_function(tolua_S, "IsBullet", lua_LuaBox2D_b2Body_IsBullet); 
    tolua_function(tolua_S, "SetSleepingAllowed", lua_LuaBox2D_b2Body_SetSleepingAllowed); 
    tolua_function(tolua_S, "IsSleepingAllowed", lua_LuaBox2D_b2Body_IsSleepingAllowed); 
    tolua_function(tolua_S, "SetAwake", lua_LuaBox2D_b2Body_SetAwake); 
    tolua_function(tolua_S, "IsAwake", lua_LuaBox2D_b2Body_IsAwake); 
    tolua_function(tolua_S, "SetActive", lua_LuaBox2D_b2Body_SetActive); 
    tolua_function(tolua_S, "IsActive", lua_LuaBox2D_b2Body_IsActive); 
    tolua_function(tolua_S, "SetFixedRotation", lua_LuaBox2D_b2Body_SetFixedRotation); 
    tolua_function(tolua_S, "IsFixedRotation", lua_LuaBox2D_b2Body_IsFixedRotation); 
    tolua_function(tolua_S, "GetFixtureList", lua_LuaBox2D_b2Body_GetFixtureList); 
    tolua_function(tolua_S, "GetJointList", lua_LuaBox2D_b2Body_GetJointList); 
    tolua_function(tolua_S, "GetContactList", lua_LuaBox2D_b2Body_GetContactList); 
    tolua_function(tolua_S, "GetNext", lua_LuaBox2D_b2Body_GetNext); 
    tolua_function(tolua_S, "GetUserData", lua_LuaBox2D_b2Body_GetUserData); 
    tolua_function(tolua_S, "SetUserData", lua_LuaBox2D_b2Body_SetUserData); 
    tolua_function(tolua_S, "GetWorld", lua_LuaBox2D_b2Body_GetWorld); 
    tolua_function(tolua_S, "Dump", lua_LuaBox2D_b2Body_Dump); 
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(b2Body).name();
    g_luaType[typeName] = "b2Body";
    g_typeCast["b2Body"] = "b2Body";
    return 1;
}

#ifndef LUA_DISABLE_lua_LuaBox2D_b2Filter_new_local
int lua_LuaBox2D_b2Filter_new_local(lua_State *tolua_S){
    int argc = 0;
    b2Filter *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

    cobj = (b2Filter *)tolua_tousertype(tolua_S, 1, 0);

    argc = lua_gettop(tolua_S) - 1;
    if (argc == 0)
    {
        b2Filter *ret = new b2Filter();
        object_to_luaval<b2Filter>(tolua_S, "b2Filter", (b2Filter *)ret);
        tolua_register_gc(tolua_S, lua_gettop(tolua_S));
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2Filter:new", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2Filter_new_local'.", &tolua_err);
#endif
    return 0;
}
#endif

#ifndef LUA_DISABLE_lua_get_b2Filter_categoryBits
int lua_get_b2Filter_categoryBits(lua_State *tolua_S){
    int argc = 0;
    b2Filter *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2Filter", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2Filter *)tolua_tousertype(tolua_S, 1, 0);

    argc = lua_gettop(tolua_S) - 1;
    if (argc == 0)
    {
        uint16 ret = cobj->categoryBits;
        tolua_pushnumber(tolua_S, (lua_Number)ret);
        return 1;
    }

    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2Filter:categoryBits", argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_get_b2Filter_categoryBits'.", &tolua_err);
#endif
    return 0;
}
#endif

#ifndef LUA_DISABLE_lua_set_b2Filter_categoryBits
int lua_set_b2Filter_categoryBits(lua_State *tolua_S){
    int argc = 0;
    b2Filter *cobj = nullptr;
    bool ok = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2Filter", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2Filter *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_set_b2Filter_categoryBits'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    if (1 == argc)
    {
        uint16_t arg0;
        ok &= luaval_to_uint16(tolua_S, 2, &arg0, "b2Filter:categoryBits");
        if (!ok)
        {
            tolua_error(tolua_S, "invalid arguments in function 'lua_set_b2Filter_categoryBits', was expecting number", nullptr);
            return 0;
        };
        cobj->categoryBits = arg0;
        lua_settop(tolua_S, 1);
        return 1;
    }

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2Filter:categoryBits", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_set_b2Filter_categoryBits'.", &tolua_err);
    return 0;
#endif
}
#endif

#ifndef LUA_DISABLE_lua_get_b2Filter_maskBits
int lua_get_b2Filter_maskBits(lua_State *tolua_S){
    int argc = 0;
    b2Filter *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2Filter", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2Filter *)tolua_tousertype(tolua_S, 1, 0);

    argc = lua_gettop(tolua_S) - 1;
    if (argc == 0)
    {
        uint16 ret = cobj->maskBits;
        tolua_pushnumber(tolua_S, (lua_Number)ret);
        return 1;
    }

    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2Filter:maskBits", argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_get_b2Filter_maskBits'.", &tolua_err);
#endif
    return 0;
}
#endif

#ifndef LUA_DISABLE_lua_set_b2Filter_maskBits
int lua_set_b2Filter_maskBits(lua_State *tolua_S){
    int argc = 0;
    b2Filter *cobj = nullptr;
    bool ok = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2Filter", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2Filter *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_set_b2Filter_maskBits'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    if (1 == argc)
    {
        uint16_t arg0;
        ok &= luaval_to_uint16(tolua_S, 2, &arg0, "b2Filter:categoryBits");
        if (!ok)
        {
            tolua_error(tolua_S, "invalid arguments in function 'lua_set_b2Filter_maskBits', was expecting number", nullptr);
            return 0;
        };
        cobj->maskBits = arg0;
        lua_settop(tolua_S, 1);
        return 1;
    }

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2Filter:maskBits", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_set_b2Filter_maskBits'.", &tolua_err);
    return 0;
#endif
}
#endif

#ifndef LUA_DISABLE_lua_get_b2Filter_groupIndex
int lua_get_b2Filter_groupIndex(lua_State *tolua_S){
    int argc = 0;
    b2Filter *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2Filter", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2Filter *)tolua_tousertype(tolua_S, 1, 0);

    argc = lua_gettop(tolua_S) - 1;
    if (argc == 0)
    {
        uint16 ret = cobj->groupIndex;
        tolua_pushnumber(tolua_S, (lua_Number)ret);
        return 1;
    }

    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2Filter:groupIndex", argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_get_b2Filter_groupIndex'.", &tolua_err);
#endif
    return 0;
}
#endif

#ifndef LUA_DISABLE_lua_set_b2Filter_groupIndex
int lua_set_b2Filter_groupIndex(lua_State *tolua_S){
    int argc = 0;
    b2Filter *cobj = nullptr;
    bool ok = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2Filter", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2Filter *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_set_b2Filter_groupIndex'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    if (1 == argc)
    {
        uint16_t arg0;
        ok &= luaval_to_uint16(tolua_S, 2, &arg0, "b2Filter:groupIndex");
        if (!ok)
        {
            tolua_error(tolua_S, "invalid arguments in function 'lua_set_b2Filter_groupIndex', was expecting number", nullptr);
            return 0;
        };
        cobj->groupIndex = arg0;
        lua_settop(tolua_S, 1);
        return 1;
    }

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2Filter:groupIndex", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_set_b2Filter_groupIndex'.", &tolua_err);
    return 0;
#endif
}
#endif

int lua_register_cocos2dx_b2Filter(lua_State *tolua_S){
    tolua_usertype(tolua_S, "b2Filter");
    tolua_cclass(tolua_S, "b2Filter", "b2Filter", "", nullptr);
    tolua_beginmodule(tolua_S, "b2Filter");
        tolua_function(tolua_S, "new", lua_LuaBox2D_b2Filter_new_local);
        tolua_function(tolua_S, ".call", lua_LuaBox2D_b2Filter_new_local);
        tolua_variable(tolua_S, "categoryBits", lua_get_b2Filter_categoryBits, lua_set_b2Filter_categoryBits);
        tolua_variable(tolua_S, "maskBits", lua_get_b2Filter_maskBits, lua_set_b2Filter_maskBits);
        tolua_variable(tolua_S, "groupIndex", lua_get_b2Filter_groupIndex, lua_set_b2Filter_groupIndex);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(b2Filter).name();
    g_luaType[typeName] = "b2Filter";
    g_typeCast["b2Filter"] = "b2Filter";
    return 1;
}

#ifndef LUA_DISABLE_lua_LuaBox2D_b2FixtureDef_new_local
int lua_LuaBox2D_b2FixtureDef_new_local(lua_State *tolua_S){
    int argc = 0;
    b2FixtureDef *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

    cobj = (b2FixtureDef *)tolua_tousertype(tolua_S, 1, 0);

    argc = lua_gettop(tolua_S) - 1;
    if (argc == 0)
    {
        b2FixtureDef *ret = new b2FixtureDef();
        object_to_luaval<b2FixtureDef>(tolua_S, "b2FixtureDef", (b2FixtureDef *)ret);
        tolua_register_gc(tolua_S, lua_gettop(tolua_S));
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2FixtureDef:new", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2FixtureDef_new_local'.", &tolua_err);
#endif
    return 0;
}
#endif

#ifndef LUA_DISABLE_lua_LuaBox2D_get_b2FixtureDef_shape
int lua_LuaBox2D_get_b2FixtureDef_shape(lua_State *tolua_S){
    int argc = 0;
    b2FixtureDef *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2FixtureDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2FixtureDef *)tolua_tousertype(tolua_S, 1, 0);

    argc = lua_gettop(tolua_S) - 1;
    if (argc == 0)
    {
        const b2Shape *ret = cobj->shape;
        object_to_luaval<b2Shape>(tolua_S, "b2Shape", (b2Shape *)ret);
        return 1;
    }

    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2FixtureDef:shape", argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_get_b2FixtureDef_shape'.", &tolua_err);
#endif
    return 0;
}
#endif

#ifndef LUA_DISABLE_lua_LuaBox2D_set_b2FixtureDef_shape
int lua_LuaBox2D_set_b2FixtureDef_shape(lua_State *tolua_S){
    int argc = 0;
    b2FixtureDef *cobj = nullptr;
    bool ok = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2FixtureDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2FixtureDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_LuaBox2D_set_b2FixtureDef_shape'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    if (1 == argc)
    {
        const b2Shape *arg0;
        ok &= luaval_to_object<const b2Shape>(tolua_S, 2, "const b2Shape", &arg0);

        if (!ok)
        {
            tolua_error(tolua_S, "invalid arguments in function 'lua_LuaBox2D_set_b2FixtureDef_shape', was expecting b2Shape", nullptr);
            return 0;
        };
        cobj->shape = arg0;
        lua_settop(tolua_S, 1);
        return 1;
    }

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2FixtureDef:b2Shape", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_set_b2FixtureDef_shape'.", &tolua_err);
    return 0;
#endif
}
#endif


#ifndef LUA_DISABLE_lua_LuaBox2D_get_b2FixtureDef_userData
int lua_LuaBox2D_get_b2FixtureDef_userData(lua_State *tolua_S){
    int argc = 0;
    b2FixtureDef *cobj = nullptr;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2FixtureDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2FixtureDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_LuaBox2D_get_b2FixtureDef_userData'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if(argc == 0){
        void *ret = cobj->userData;
        object_to_luaval<void>(tolua_S, "void", &ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2FixtureDef:userData", argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_get_b2FixtureDef_userData'.", &tolua_err);
    return 0;
#endif
}
#endif

#ifndef LUA_DISABLE_lua_LuaBox2D_set_b2FixtureDef_userData
int lua_LuaBox2D_set_b2FixtureDef_userData(lua_State *tolua_S){
    int argc = 0;
    b2FixtureDef *cobj = nullptr;
    bool ok = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2FixtureDef", 0, &tolua_err) ||
        !tolua_isuserdata(tolua_S, 2, 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2FixtureDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_LuaBox2D_set_b2FixtureDef_userData'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (1 == argc)
        {
            void *arg0;
            arg0 = tolua_tousertype(tolua_S, 2, 0);
            ok &= luaval_is_usertype(tolua_S, 2, "void", 1);
            if(!ok){
                tolua_error(tolua_S, "invalid arguments 2 in function 'lua_LuaBox2D_set_b2FixtureDef_userData', was expecting void", nullptr);
                return 0;
            };
            cobj->userData = arg0;
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2FixtureDef:userData", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_set_b2FixtureDef_userData'.", &tolua_err);
    return 0;
#endif
}
#endif

#ifndef LUA_DISABLE_lua_LuaBox2D_get_b2FixtureDef_friction
int lua_LuaBox2D_get_b2FixtureDef_friction(lua_State *tolua_S){
    int argc = 0;
    b2FixtureDef *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2FixtureDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2FixtureDef *)tolua_tousertype(tolua_S, 1, 0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_LuaBox2D_get_b2FixtureDef_friction'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if(argc == 0){
        float32 ret = cobj -> friction;
        tolua_pushnumber(tolua_S, (lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2FixtureDef:friction", argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_get_b2FixtureDef_friction'.", &tolua_err);
#endif
    return 0; 
}
#endif

#ifndef LUA_DISABLE_lua_LuaBox2D_set_b2FixtureDef_friction
int lua_LuaBox2D_set_b2FixtureDef_friction(lua_State *tolua_S){
    int argc = 0;
    b2FixtureDef *cobj = nullptr;
    bool ok = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2FixtureDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2FixtureDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_LuaBox2D_set_b2FixtureDef_friction'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if (1 == argc)
    {
        double arg0;
        ok &= luaval_to_number(tolua_S, 2, &arg0, "b2FixtureDef:friction");
        if (!ok)
        {
            tolua_error(tolua_S, "invalid arguments 1 in function 'lua_LuaBox2D_set_b2FixtureDef_friction', was expecting number", nullptr);
            return 0;   
        };
        cobj->friction = arg0;
        lua_settop(tolua_S, 1);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2FixtureDef:friction", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_set_b2FixtureDef_friction'.", &tolua_err);
    return 0;
#endif
}
#endif

#ifndef LUA_DISABLE_lua_LuaBox2D_get_b2FixtureDef_restitution
int lua_LuaBox2D_get_b2FixtureDef_restitution(lua_State *tolua_S){
    int argc = 0;
    b2FixtureDef *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2FixtureDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2FixtureDef *)tolua_tousertype(tolua_S, 1, 0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_LuaBox2D_get_b2FixtureDef_restitution'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if(argc == 0){
        float32 ret = cobj -> restitution;
        tolua_pushnumber(tolua_S, (lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2FixtureDef:restitution", argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_get_b2FixtureDef_restitution'.", &tolua_err);
#endif
    return 0;
}
#endif

#ifndef LUA_DISABLE_lua_LuaBox2D_set_b2FixtureDef_restitution
int lua_LuaBox2D_set_b2FixtureDef_restitution(lua_State *tolua_S){
    int argc = 0;
    b2FixtureDef *cobj = nullptr;
    bool ok = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2FixtureDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2FixtureDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_LuaBox2D_get_b2FixtureDef_restitution'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if (1 == argc)
    {
        double arg0;
        ok &= luaval_to_number(tolua_S, 2, &arg0, "b2FixtureDef:restitution");
        if (!ok)
        {
            tolua_error(tolua_S, "invalid arguments 1 in function 'lua_LuaBox2D_get_b2FixtureDef_restitution', was expecting number", nullptr);
            return 0;   
        };
        cobj->restitution = arg0;
        lua_settop(tolua_S, 1);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2FixtureDef:restitution", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_get_b2FixtureDef_restitution'.", &tolua_err);
    return 0;
#endif
}
#endif

#ifndef LUA_DISABLE_lua_LuaBox2D_get_b2FixtureDef_density
int lua_LuaBox2D_get_b2FixtureDef_density(lua_State *tolua_S){
    int argc = 0;
    b2FixtureDef *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2FixtureDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2FixtureDef *)tolua_tousertype(tolua_S, 1, 0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_LuaBox2D_get_b2FixtureDef_density'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if(argc == 0){
        float32 ret = cobj -> density;
        tolua_pushnumber(tolua_S, (lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2FixtureDef:density", argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_get_b2FixtureDef_density'.", &tolua_err);
#endif
    return 0;
}
#endif

#ifndef LUA_DISABLE_lua_LuaBox2D_set_b2FixtureDef_density
int lua_LuaBox2D_set_b2FixtureDef_density(lua_State *tolua_S){
    int argc = 0;
    b2FixtureDef *cobj = nullptr;
    bool ok = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2FixtureDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2FixtureDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_LuaBox2D_set_b2FixtureDef_density'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if (1 == argc)
    {
        double arg0;
        ok &= luaval_to_number(tolua_S, 2, &arg0, "b2FixtureDef:density");
        if (!ok)
        {
            tolua_error(tolua_S, "invalid arguments 1 in function 'lua_LuaBox2D_set_b2FixtureDef_density', was expecting number", nullptr);
            return 0;   
        };
        cobj->density = arg0;
        lua_settop(tolua_S, 1);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2FixtureDef:density", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_set_b2FixtureDef_density'.", &tolua_err);
    return 0;
#endif
}
#endif

#ifndef LUA_DISABLE_lua_LuaBox2D_get_b2FixtureDef_isSensor
int lua_LuaBox2D_get_b2FixtureDef_isSensor(lua_State *tolua_S){
    int argc = 0;
    b2FixtureDef *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2FixtureDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2FixtureDef *)tolua_tousertype(tolua_S, 1, 0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_LuaBox2D_get_b2FixtureDef_isSensor'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if(argc == 0){
        bool ret = cobj -> isSensor;
        tolua_pushboolean(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2FixtureDef:isSensor", argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_get_b2FixtureDef_isSensor'.", &tolua_err);
#endif
    return 0;
}
#endif

#ifndef LUA_DISABLE_lua_LuaBox2D_set_b2FixtureDef_isSensor
int lua_LuaBox2D_set_b2FixtureDef_isSensor(lua_State *tolua_S){
    int argc = 0;
    b2FixtureDef *cobj = nullptr;
    bool ok = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2FixtureDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2FixtureDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_LuaBox2D_set_b2FixtureDef_isSensor'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if (1 == argc)
    {
        bool arg0;
        ok &= luaval_to_boolean(tolua_S, 2, &arg0, "b2FixtureDef:isSensor");
        if (!ok)
        {
            tolua_error(tolua_S, "invalid arguments 1 in function 'lua_LuaBox2D_set_b2FixtureDef_isSensor', was expecting bool", nullptr);
            return 0;   
        };
        cobj->isSensor = arg0;
        lua_settop(tolua_S, 1);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2FixtureDef:isSensor", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_set_b2FixtureDef_isSensor'.", &tolua_err);
    return 0;
#endif    
}
#endif

#ifndef LUA_DISABLE_lua_LuaBox2D_get_b2FixtureDef_filter
int lua_LuaBox2D_get_b2FixtureDef_filter(lua_State *tolua_S){
    int argc = 0;
    b2FixtureDef *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2FixtureDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2FixtureDef *)tolua_tousertype(tolua_S, 1, 0);

    argc = lua_gettop(tolua_S) - 1;
    if (argc >= 0)
    {
        const b2Filter ret = cobj -> filter;
        object_to_luaval<b2Filter>(tolua_S, "b2Filter", (b2Filter *)&ret);
        return 1;
    }

    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2FixtureDef:filter", argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_get_b2FixtureDef_filter'.", &tolua_err);
#endif
    return 0;
}
#endif

#ifndef LUA_DISABLE_lua_LuaBox2D_set_b2FixtureDef_filter
int lua_LuaBox2D_set_b2FixtureDef_filter(lua_State *tolua_S){
   int argc = 0;
    b2FixtureDef *cobj = nullptr;
    bool ok = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2FixtureDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2FixtureDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_LuaBox2D_set_b2FixtureDef_filter'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    if (1 == argc)
    {
        b2Filter *arg0;
        ok &= luaval_to_object<b2Filter>(tolua_S, 2, "b2Filter", &arg0);
        if (!ok)
        {
            tolua_error(tolua_S, "invalid arguments in function 'lua_LuaBox2D_set_b2FixtureDef_filter', was expecting b2Filter", nullptr);
            return 0;
        };
        cobj->filter = *arg0;
        lua_settop(tolua_S, 1);
        return 1;
    }

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2FixtureDef:filter", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_set_b2FixtureDef_filter'.", &tolua_err);
    return 0;
#endif
}
#endif

int lua_register_cocos2dx_b2FixtureDef(lua_State *tolua_S){
    tolua_usertype(tolua_S, "b2FixtureDef");
    tolua_cclass(tolua_S, "b2FixtureDef", "b2FixtureDef", "", nullptr);
    tolua_beginmodule(tolua_S, "b2FixtureDef");
        tolua_function(tolua_S, "new", lua_LuaBox2D_b2FixtureDef_new_local);
        tolua_function(tolua_S, ".call", lua_LuaBox2D_b2FixtureDef_new_local);
        tolua_variable(tolua_S, "shape", lua_LuaBox2D_get_b2FixtureDef_shape, lua_LuaBox2D_set_b2FixtureDef_shape);
        tolua_variable(tolua_S, "userData", lua_LuaBox2D_get_b2FixtureDef_userData, lua_LuaBox2D_set_b2FixtureDef_userData);
        tolua_variable(tolua_S, "friction", lua_LuaBox2D_get_b2FixtureDef_friction, lua_LuaBox2D_set_b2FixtureDef_friction);
        tolua_variable(tolua_S, "restitution", lua_LuaBox2D_get_b2FixtureDef_restitution, lua_LuaBox2D_set_b2FixtureDef_restitution);
        tolua_variable(tolua_S, "density", lua_LuaBox2D_get_b2FixtureDef_density, lua_LuaBox2D_set_b2FixtureDef_density);
        tolua_variable(tolua_S, "isSensor", lua_LuaBox2D_get_b2FixtureDef_isSensor, lua_LuaBox2D_set_b2FixtureDef_isSensor);
        tolua_variable(tolua_S, "filter", lua_LuaBox2D_get_b2FixtureDef_filter, lua_LuaBox2D_set_b2FixtureDef_filter);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(b2FixtureDef).name();
    g_luaType[typeName] = "b2FixtureDef";
    g_typeCast["b2FixtureDef"] = "b2FixtureDef";
    return  1;
}


#ifndef LUA_DISABLE_lua_LuaBox2D_b2Fixture_GetType
int lua_LuaBox2D_b2Fixture_GetType(lua_State *tolua_S){
    int argc = 0;
    b2Fixture *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2Fixture", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2Fixture *)tolua_tousertype(tolua_S, 1, 0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_LuaBox2D_b2Fixture_GetType'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if(argc == 0){
        b2Shape::Type ret;
        ret = cobj -> GetType();
       tolua_pushnumber(tolua_S, (lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2FixtureDef:GetType", argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2Fixture_GetType'.", &tolua_err);
#endif
    return 0;
}
#endif

#ifndef LUA_DISABLE_lua_LuaBox2D_b2Fixture_GetShape
int lua_LuaBox2D_b2Fixture_GetShape(lua_State *tolua_S){
    int argc = 0;
    b2Fixture *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2Fixture", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2Fixture *)tolua_tousertype(tolua_S, 1, 0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_LuaBox2D_b2Fixture_GetShape'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if(argc == 0){
        b2Shape *ret;
        ret = cobj -> GetShape();
        object_to_luaval<b2Shape>(tolua_S, "b2Shape", ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2FixtureDef:GetShape", argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2Fixture_GetShape'.", &tolua_err);
#endif
    return 0;
}
#endif

#ifndef LUA_DISABLE_lua_LuaBox2D_b2Fixture_IsSensor
int lua_LuaBox2D_b2Fixture_IsSensor(lua_State *tolua_S){
    int argc = 0;
    b2Fixture *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2Fixture", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2Fixture *)tolua_tousertype(tolua_S, 1, 0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_LuaBox2D_b2Fixture_IsSensor'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if(argc == 0){
        bool ret;
        ret = cobj -> IsSensor();
        tolua_pushboolean(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2FixtureDef:IsSensor", argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2Fixture_IsSensor'.", &tolua_err);
#endif
    return 0;
}
#endif

#ifndef LUA_DISABLE_lua_LuaBox2D_b2Fixture_SetSensor
int lua_LuaBox2D_b2Fixture_SetSensor(lua_State *tolua_S){
    int argc = 0;
    b2Fixture *cobj = nullptr;
    bool ok = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2Fixture", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2Fixture *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_LuaBox2D_b2Fixture_SetSensor'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if (1 == argc)
    {
        bool arg0;
        ok &= luaval_to_boolean(tolua_S, 2, &arg0, "b2Fixture:SetSensor");
        if (!ok)
        {
            tolua_error(tolua_S, "invalid arguments 1 in function 'lua_LuaBox2D_b2Fixture_SetSensor', was expecting bool", nullptr);
            return 0;   
        };
        cobj->SetSensor(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2Fixture:SetSensor", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2Fixture_SetSensor'.", &tolua_err);
    return 0;
#endif    
}
#endif

#ifndef LUA_DISABLE_lua_LuaBox2D_b2Fixture_SetFilterData
int lua_LuaBox2D_b2Fixture_SetFilterData(lua_State *tolua_S){
    int argc = 0;
    b2Fixture *cobj = nullptr;
    bool ok = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2Fixture", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2Fixture *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_LuaBox2D_b2Fixture_SetFilterData'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if (1 == argc)
    {
        const b2Filter *arg0;
        ok &= luaval_to_object<const b2Filter>(tolua_S, 2, "const b2Filter", &arg0);
        if (!ok)
        {
            tolua_error(tolua_S, "invalid arguments 1 in function 'lua_LuaBox2D_b2Fixture_SetFilterData', was expecting b2Filter", nullptr);
            return 0;
        }
        cobj->SetFilterData(*arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2Fixture:SetFilterData", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2Fixture_SetFilterData'.", &tolua_err);
    return 0;
#endif 
}
#endif

#ifndef LUA_DISABLE_lua_LuaBox2D_b2Fixture_GetFilterData
int lua_LuaBox2D_b2Fixture_GetFilterData(lua_State *tolua_S){
    int argc = 0;
    b2Fixture *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2Fixture", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2Fixture *)tolua_tousertype(tolua_S, 1, 0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_LuaBox2D_b2Fixture_GetFilterData'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if(argc == 0){
        const b2Filter& ret = cobj->GetFilterData();
        object_to_luaval<const b2Filter>(tolua_S, "b2Filter", (const b2Filter *)&ret);

        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2Filter:GetFilterData", argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2Fixture_GetFilterData'.", &tolua_err);
#endif
    return 0;
}
#endif

#ifndef LUA_DISABLE_lua_LuaBox2D_b2Fixture_Refilter
int lua_LuaBox2D_b2Fixture_Refilter(lua_State *tolua_S){
    int argc = 0;
    b2Fixture *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2Fixture", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2Fixture *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_LuaBox2D_b2Fixture_Refilter'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if (0 == argc)
    {
        cobj->Refilter();
        lua_settop(tolua_S, 1);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2Fixture:Refilter", argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2Fixture_Refilter'.", &tolua_err);
    return 0;
#endif 
}
#endif

#ifndef LUA_DISABLE_lua_LuaBox2D_b2Fixture_GetNext
int lua_LuaBox2D_b2Fixture_GetNext(lua_State *tolua_S){
    int argc = 0;
    b2Fixture *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2Fixture", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2Fixture *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_LuaBox2D_b2Fixture_GetNext'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if (0 == argc)
    {
        b2Fixture *ret = cobj->GetNext();
        object_to_luaval<b2Fixture>(tolua_S, "b2Fixture", (b2Fixture *)&ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2Fixture:GetNext", argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2Fixture_GetNext'.", &tolua_err);
    return 0;
#endif 
}
#endif

#ifndef LUA_DISABLE_lua_LuaBox2D_b2Fixture_GetBody
int lua_LuaBox2D_b2Fixture_GetBody(lua_State *tolua_S){
    int argc = 0;
    b2Fixture *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2Fixture", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2Fixture *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_LuaBox2D_b2Fixture_GetBody'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if (0 == argc)
    {
        b2Body *ret = cobj->GetBody();
        object_to_luaval<b2Body>(tolua_S, "b2Body", (b2Body *)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2Fixture:GetBody", argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2Fixture_GetBody'.", &tolua_err);
    return 0;
#endif 
}
#endif

#ifndef LUA_DISABLE_lua_LuaBox2D_b2Fixture_GetUserData
int lua_LuaBox2D_b2Fixture_GetUserData(lua_State *tolua_S){
    int argc = 0;
    b2Fixture *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2Fixture", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2Fixture *)tolua_tousertype(tolua_S, 1, 0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_LuaBox2D_b2Fixture_GetUserData'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if(argc == 0){
        void  *ret = cobj -> GetUserData();
        object_to_luaval<void>(tolua_S, "void", (void *)&ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2Fixture:GetUserData", argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2Fixture_GetUserData'.", &tolua_err);
#endif
    return 0; 
}
#endif

#ifndef LUA_DISABLE_lua_LuaBox2D_b2Fixture_SetUserData
int lua_LuaBox2D_b2Fixture_SetUserData(lua_State *tolua_S){
    int argc = 0;
    b2Fixture *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2Fixture", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2Fixture *)tolua_tousertype(tolua_S, 1, 0);

    argc = lua_gettop(tolua_S) - 1;
    if (argc == 1)
    {
        void* arg0;
        arg0 = ((void*)  tolua_touserdata(tolua_S, 2, 0));
        cobj->SetUserData(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2Fixture:SetUserData", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2Fixture_SetUserData'.", &tolua_err);
#endif
    return 0;
}
#endif

#ifndef LUA_DISABLE_lua_LuaBox2D_b2Fixture_TestPoint
int lua_LuaBox2D_b2Fixture_TestPoint(lua_State *tolua_S){
    int argc = 0;
    b2Fixture *cobj = nullptr;
    bool ok = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2Fixture", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2Fixture *)tolua_tousertype(tolua_S, 1, 0);

    argc = lua_gettop(tolua_S) - 1;
    if (argc == 1)
    {
        const b2Vec2 *arg0;
        ok &= luaval_to_object<const b2Vec2>(tolua_S, 2, "const b2Vec2", &arg0);
        if(!ok){
            tolua_error(tolua_S, "invalid arguments 1 in function 'lua_LuaBox2D_b2Fixture_TestPoint', was expecting b2Vec2", nullptr);
            return 0;
        }
        bool ret = cobj->TestPoint(*arg0);
        tolua_pushboolean(tolua_S, ret);
        return 1;
    }
    
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2Fixture:TestPoint", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2Fixture_TestPoint'.", &tolua_err);
#endif
    return 0;
}
#endif

#ifndef LUA_DISABLE_lua_LuaBox2D_b2Fixture_RayCast
int lua_LuaBox2D_b2Fixture_RayCast(lua_State *tolua_S){
    int argc = 0;
    b2Fixture *cobj = nullptr;
    bool ok = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2Fixture", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2Fixture *)tolua_tousertype(tolua_S, 1, 0);
    argc = lua_gettop(tolua_S) - 1;
    if (argc == 3)
    {
        b2RayCastOutput *arg0;
        ok &= luaval_to_object<b2RayCastOutput>(tolua_S, 2, "b2RayCastOutput", &arg0);
        if(!ok){
            tolua_error(tolua_S, "invalid arguments 1 in function 'lua_LuaBox2D_b2Fixture_RayCast', was expecting b2RayCastOutput", nullptr);
            return 0;
        }

        b2RayCastInput *arg1;
        ok &= luaval_to_object<b2RayCastInput>(tolua_S, 3, "b2RayCastInput", &arg1);
        if(!ok){
            tolua_error(tolua_S, "invalid arguments 2 in function 'lua_LuaBox2D_b2Fixture_RayCast', was expecting b2RayCastInput", nullptr);
            return 0;
        }

        int32 arg2;
        ok &= luaval_to_int32(tolua_S, 4, &arg2, "RayCast");
        if(!ok){
            tolua_error(tolua_S, "invalid arguments 3 in function 'lua_LuaBox2D_b2Fixture_RayCast', was expecting number", nullptr);
            return 0;
        }
        bool ret = cobj->RayCast(arg0, *arg1, arg2);
        tolua_pushboolean(tolua_S, ret);
        return 1;
    }
    
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2Fixture:RayCast", argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2Fixture_RayCast'.", &tolua_err);
#endif
    return 0;
}
#endif



#ifndef LUA_DISABLE_lua_LuaBox2D_b2Fixture_GetMassData
int lua_LuaBox2D_b2Fixture_GetMassData(lua_State *tolua_S){
    int argc = 0;
    b2Fixture *cobj = nullptr;
    bool ok = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2Fixture", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2Fixture *)tolua_tousertype(tolua_S, 1, 0);

    argc = lua_gettop(tolua_S) - 1;
    if (argc == 1)
    {
        b2MassData *arg0;
        ok &= luaval_to_object<b2MassData>(tolua_S, 2, "b2MassData", &arg0);
        if (!ok)
        {
            tolua_error(tolua_S, "invalid arguments 1 in function 'lua_LuaBox2D_b2Fixture_GetMassData', was expecting b2MassData", nullptr);
            return 0;
        }
        cobj->GetMassData(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2Fixture:GetMassData", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2Fixture_GetMassData'.", &tolua_err);
#endif
    return 0;
}
#endif

#ifndef LUA_DISABLE_lua_LuaBox2D_b2Fixture_SetDensity
int lua_LuaBox2D_b2Fixture_SetDensity(lua_State *tolua_S){
    int argc = 0;
    b2Fixture *cobj = nullptr;
    bool ok = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2Fixture", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2Fixture *)tolua_tousertype(tolua_S, 1, 0);

    argc = lua_gettop(tolua_S) - 1;
    if (argc == 1)
    {
        double arg0;
        ok &= luaval_to_number(tolua_S, 2,  &arg0, "SetDensity");
        if (!ok)
        {
            tolua_error(tolua_S, "invalid arguments 1 in function 'lua_LuaBox2D_b2Fixture_SetDensity', was expecting number", nullptr);
            return 0;
        }
        cobj->SetDensity(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2Body:SetDensity", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2Fixture_SetDensity'.", &tolua_err);
#endif
    return 0;
}
#endif

#ifndef LUA_DISABLE_lua_LuaBox2D_b2Fixture_GetDensity
int lua_LuaBox2D_b2Fixture_GetDensity(lua_State *tolua_S){
    int argc = 0;
    b2Fixture *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2Fixture", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2Fixture *)tolua_tousertype(tolua_S, 1, 0);

    argc = lua_gettop(tolua_S) - 1;
    if (argc == 0)
    {
        float32 ret = cobj->GetDensity();
        tolua_pushnumber(tolua_S, (lua_Number)ret);
        return 1;
    }
    
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2Body:GetDensity", argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2Fixture_GetDensity'.", &tolua_err);
#endif
    return 0;
}
#endif

#ifndef LUA_DISABLE_lua_LuaBox2D_b2Fixture_SetFriction
int lua_LuaBox2D_b2Fixture_SetFriction(lua_State *tolua_S){
    int argc = 0;
    b2Fixture *cobj = nullptr;
    bool ok = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2Fixture", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2Fixture *)tolua_tousertype(tolua_S, 1, 0);

    argc = lua_gettop(tolua_S) - 1;
    if (argc == 1)
    {
        double arg0;
        ok &= luaval_to_number(tolua_S, 2,  &arg0, "SetFriction");
        if (!ok)
        {
            tolua_error(tolua_S, "invalid arguments 1 in function 'lua_LuaBox2D_b2Fixture_SetFriction', was expecting number", nullptr);
            return 0;
        }
        cobj->SetFriction(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2Body:SetFriction", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2Fixture_SetFriction'.", &tolua_err);
#endif
    return 0;
}
#endif

#ifndef LUA_DISABLE_lua_LuaBox2D_b2Fixture_GetFriction
int lua_LuaBox2D_b2Fixture_GetFriction(lua_State *tolua_S){
    int argc = 0;
    b2Fixture *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2Fixture", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2Fixture *)tolua_tousertype(tolua_S, 1, 0);

    argc = lua_gettop(tolua_S) - 1;
    if (argc == 0)
    {
        float32 ret = cobj->GetFriction();
        tolua_pushnumber(tolua_S, (lua_Number)ret);
        return 1;
    }
    
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2Fixture:GetFriction", argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2Fixture_GetFriction'.", &tolua_err);
#endif
    return 0;
}
#endif

#ifndef LUA_DISABLE_lua_LuaBox2D_b2Fixture_SetRestitution
int lua_LuaBox2D_b2Fixture_SetRestitution(lua_State *tolua_S){
    int argc = 0;
    b2Fixture *cobj = nullptr;
    bool ok = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2Fixture", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2Fixture *)tolua_tousertype(tolua_S, 1, 0);

    argc = lua_gettop(tolua_S) - 1;
    if (argc == 1)
    {
        double arg0;
        ok &= luaval_to_number(tolua_S, 2,  &arg0, "SetRestitution");
        if (!ok)
        {
            tolua_error(tolua_S, "invalid arguments 1 in function 'lua_LuaBox2D_b2Fixture_SetRestitution', was expecting number", nullptr);
            return 0;
        }
        cobj->SetRestitution(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2Fixture:SetRestitution", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2Fixture_SetRestitution'.", &tolua_err);
#endif
    return 0;
}
#endif

#ifndef LUA_DISABLE_lua_LuaBox2D_b2Fixture_GetRestitution
int lua_LuaBox2D_b2Fixture_GetRestitution(lua_State *tolua_S){
    int argc = 0;
    b2Fixture *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2Fixture", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2Fixture *)tolua_tousertype(tolua_S, 1, 0);

    argc = lua_gettop(tolua_S) - 1;
    if (argc == 0)
    {
        float32 ret = cobj->GetRestitution();
        tolua_pushnumber(tolua_S, (lua_Number)ret);
        return 1;
    }
    
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2Fixture:GetRestitution", argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2Fixture_GetRestitution'.", &tolua_err);
#endif
    return 0;
}
#endif

#ifndef LUA_DISABLE_lua_LuaBox2D_b2Fixture_GetAABB
int lua_LuaBox2D_b2Fixture_GetAABB(lua_State *tolua_S){
    int argc = 0;
    b2Fixture *cobj = nullptr;
    bool ok = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2Fixture", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2Fixture *)tolua_tousertype(tolua_S, 1, 0);

    argc = lua_gettop(tolua_S) - 1;
    if (argc == 1)
    {
        double arg0;
        ok &= luaval_to_number(tolua_S, 2,  &arg0, "GetAABB");
        if (!ok)
        {
            tolua_error(tolua_S, "invalid arguments 1 in function 'lua_LuaBox2D_b2Fixture_GetAABB', was expecting number", nullptr);
            return 0;
        }
        const b2AABB &ret = cobj->GetAABB(arg0);
        object_to_luaval<const b2AABB>(tolua_S, "b2AABB", (const b2AABB *)&ret);
        return 1;
    }
    
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2Fixture:GetAABB", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2Fixture_GetAABB'.", &tolua_err);
#endif
    return 0;
}
#endif

#ifndef LUA_DISABLE_lua_LuaBox2D_b2Fixture_Dump
int lua_LuaBox2D_b2Fixture_Dump(lua_State *tolua_S){
    int argc = 0;
    b2Fixture *cobj = nullptr;
    bool ok = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2Fixture", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2Fixture *)tolua_tousertype(tolua_S, 1, 0);

    argc = lua_gettop(tolua_S) - 1;
    if (argc == 1)
    {
        int32 arg0;
        ok &= luaval_to_int32(tolua_S, 2,  &arg0, "Dump");
        if (!ok)
        {
            tolua_error(tolua_S, "invalid arguments 1 in function 'lua_LuaBox2D_b2Fixture_Dump', was expecting number", nullptr);
            return 0;
        }
        cobj->Dump(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2Fixture:GetAABB", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2Fixture_Dump'.", &tolua_err);
#endif
    return 0;
}
#endif

int lua_register_cocos2dx_b2Fixture(lua_State *tolua_S){
    tolua_usertype(tolua_S, "b2Fixture");
    tolua_cclass(tolua_S, "b2Fixture", "b2Fixture", "", nullptr);
    tolua_beginmodule(tolua_S, "b2Fixture");
        tolua_function(tolua_S, "GetType", lua_LuaBox2D_b2Fixture_GetType);
        tolua_function(tolua_S, "GetShape", lua_LuaBox2D_b2Fixture_GetShape);
        tolua_function(tolua_S, "SetSensor", lua_LuaBox2D_b2Fixture_SetSensor);
        tolua_function(tolua_S, "IsSensor", lua_LuaBox2D_b2Fixture_IsSensor);
        tolua_function(tolua_S, "SetFilterData", lua_LuaBox2D_b2Fixture_SetFilterData);
        tolua_function(tolua_S, "GetFilterData", lua_LuaBox2D_b2Fixture_GetFilterData);
        tolua_function(tolua_S, "Refilter", lua_LuaBox2D_b2Fixture_Refilter);
        tolua_function(tolua_S, "GetNext", lua_LuaBox2D_b2Fixture_GetNext);
        tolua_function(tolua_S, "GetBody", lua_LuaBox2D_b2Fixture_GetBody);
        tolua_function(tolua_S, "GetUserData", lua_LuaBox2D_b2Fixture_GetUserData);
        tolua_function(tolua_S, "SetUserData", lua_LuaBox2D_b2Fixture_SetUserData);
        tolua_function(tolua_S, "TestPoint", lua_LuaBox2D_b2Fixture_TestPoint);
        tolua_function(tolua_S, "RayCast", lua_LuaBox2D_b2Fixture_RayCast);
        tolua_function(tolua_S, "GetMassData", lua_LuaBox2D_b2Fixture_GetMassData);
        tolua_function(tolua_S, "SetDensity", lua_LuaBox2D_b2Fixture_SetDensity);
        tolua_function(tolua_S, "GetDensity", lua_LuaBox2D_b2Fixture_GetDensity);
        tolua_function(tolua_S, "SetFriction", lua_LuaBox2D_b2Fixture_SetFriction);
        tolua_function(tolua_S, "GetFriction", lua_LuaBox2D_b2Fixture_GetFriction);
        tolua_function(tolua_S, "SetRestitution", lua_LuaBox2D_b2Fixture_SetRestitution);
        tolua_function(tolua_S, "GetRestitution", lua_LuaBox2D_b2Fixture_GetRestitution);
        tolua_function(tolua_S, "GetRestitution", lua_LuaBox2D_b2Fixture_GetRestitution);
        tolua_function(tolua_S, "GetAABB", lua_LuaBox2D_b2Fixture_GetAABB);
        tolua_function(tolua_S, "Dump", lua_LuaBox2D_b2Fixture_Dump);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(b2Fixture).name();
    g_luaType[typeName] = "b2Fixture";
    g_typeCast["b2Fixture"] = "b2Fixture";
    return  1;
}


#ifndef LUA_DISABLE_lua_LuaBox2D_b2JointDef_new
int lua_LuaBox2D_b2JointDef_new(lua_State *tolua_S){
    int argc = 0;
    b2JointDef *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

    cobj = (b2JointDef *)tolua_tousertype(tolua_S, 1, 0);

    argc = lua_gettop(tolua_S) - 1;
    if (argc == 0)
    {
        b2JointDef *ret = new b2JointDef();
        object_to_luaval<b2JointDef>(tolua_S, "b2JointDef", (b2JointDef *)ret);
        tolua_register_gc(tolua_S, lua_gettop(tolua_S));
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2JointDef:new", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2JointDef_new'.", &tolua_err);
#endif
    return 0;
}
#endif

#ifndef LUA_DISABLE_lua_get_b2JointDef_b2JointType
int lua_get_b2JointDef_b2JointType(lua_State *tolua_S){
    b2JointDef *cobj = nullptr;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2JointDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2JointDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_get_b2JointDef_b2JointType'", nullptr);
        return 0;
    }
#endif
    tolua_pushnumber(tolua_S, (lua_Number)cobj->type);
    return 1;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_get_b2JointDef_b2JointType'.", &tolua_err);
    return 0;
#endif
}
#endif

#ifndef LUA_DISABLE_lua_set_b2JointDef_b2JointType
int lua_set_b2JointDef_b2JointType(lua_State *tolua_S){
    int argc = 0;
    b2JointDef *cobj = nullptr;
    bool ok = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2JointDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2JointDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_set_b2JointDef_b2JointType'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if (1 == argc)
    {
        int arg0;
        ok &= luaval_to_int32(tolua_S, 2, &arg0, "b2Vec2:type");
        if (!ok)
        {
            tolua_error(tolua_S, "invalid arguments in function 'lua_set_b2JointDef_b2JointType'", nullptr);
        };
        cobj->type = (b2JointType)arg0;
        lua_settop(tolua_S, 1);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2JointDef:type", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_set_b2JointDef_b2JointType'.", &tolua_err);
    return 0;
#endif
}
#endif

#ifndef LUA_DISABLE_lua_get_b2JointDef_userData
int lua_get_b2JointDef_userData(lua_State *tolua_S){
    b2JointDef *cobj = nullptr;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2JointDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2JointDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_get_b2JointDef_userData'", nullptr);
        return 0;
    }
#endif
    do
    {
        void *ret = cobj->userData;
        object_to_luaval<void>(tolua_S, "void", &ret);
        return 1;
    } while (0);

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_get_b2JointDef_userData'.", &tolua_err);
    return 0;
#endif
}
#endif

#ifndef LUA_DISABLE_lua_set_b2JointDef_userData
int lua_set_b2JointDef_userData(lua_State *tolua_S){
    int argc = 0;
    b2JointDef *cobj = nullptr;
    bool ok = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2JointDef", 0, &tolua_err) ||
        !tolua_isuserdata(tolua_S, 2, 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2JointDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_set_b2JointDef_userData'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    do
    {
        if (argc == 1)
        {
            void *arg0;
            arg0 = tolua_tousertype(tolua_S, 2, 0);
            ok &= luaval_is_usertype(tolua_S, 2, "void", 1);
            if (!ok)
                break;
            cobj->userData = arg0;
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2JointDef:userData", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_set_b2JointDef_userData'.", &tolua_err);
    return 0;
#endif
}
#endif

#ifndef LUA_DISABLE_lua_get_b2JointDef_bodyA
int lua_get_b2JointDef_bodyA(lua_State *tolua_S){
    int argc = 0;
    b2JointDef *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2JointDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2JointDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_get_b2JointDef_bodyA'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if (argc == 0)
    {
        b2Body* ret = cobj->bodyA;
        object_to_luaval<b2Body*>(tolua_S, "b2Body", &ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2JointDef:bodyA", argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_get_b2JointDef_bodyA'.", &tolua_err);
    return 0;
#endif
}
#endif

#ifndef LUA_DISABLE_lua_set_b2JointDef_bodyA
int lua_set_b2JointDef_bodyA(lua_State *tolua_S){
    int argc = 0;
    b2JointDef *cobj = nullptr;
    bool ok = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2JointDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2JointDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_set_b2JointDef_bodyA'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (1 == argc)
        {
            b2Body *arg0;
            ok &= luaval_to_object<b2Body>(tolua_S, 2, "b2Body", &arg0);
            if (!ok)
            {
                tolua_error(tolua_S, "invalid arguments 1 in function 'lua_set_b2JointDef_bodyA', was expecting b2Body", nullptr);
                return 0;   
            };
            cobj->bodyA = arg0;
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2JointDef:bodyA", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_set_b2JointDef_bodyA'.", &tolua_err);
    return 0;
#endif
}
#endif

#ifndef LUA_DISABLE_lua_get_b2JointDef_bodyB
int lua_get_b2JointDef_bodyB(lua_State *tolua_S){
    int argc = 0;
    b2JointDef *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2JointDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2JointDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_get_b2JointDef_bodyB'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if (argc == 0)
    {
        b2Body* ret = cobj->bodyB;
        object_to_luaval<b2Body*>(tolua_S, "b2Body", &ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2JointDef:bodyB", argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_get_b2JointDef_bodyB'.", &tolua_err);
    return 0;
#endif
}
#endif

#ifndef LUA_DISABLE_lua_set_b2JointDef_bodyB
int lua_set_b2JointDef_bodyB(lua_State *tolua_S){
    int argc = 0;
    b2JointDef *cobj = nullptr;
    bool ok = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2JointDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2JointDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_set_b2JointDef_bodyB'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (argc == 1)
        {
            b2Body *arg0;
            ok &= luaval_to_object<b2Body>(tolua_S, 2, "b2Body", &arg0);
            if (!ok)
            {
                tolua_error(tolua_S, "invalid arguments 1 in function 'lua_set_b2JointDef_bodyB', was expecting b2Body", nullptr);
                return 0;   
            };
            cobj->bodyB = arg0;
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2JointDef:bodyB", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_set_b2JointDef_bodyB'.", &tolua_err);
    return 0;
#endif
}
#endif

#ifndef LUA_DISABLE_lua_get_b2JointDef_collideConnected
int lua_get_b2JointDef_collideConnected(lua_State *tolua_S){
    int argc = 0;
    b2JointDef *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2JointDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2JointDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'int lua_get_b2JointDef_collideConnected .", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if (argc == 0)
    {
        bool ret = cobj->collideConnected;
        tolua_pushboolean(tolua_S, (bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2JointDef:collideConnected", argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'int lua_get_b2JointDef_collideConnected .", &tolua_err);
    return 0;
#endif
}
#endif

#ifndef LUA_DISABLE_lua_set_b2JointDef_collideConnected
int lua_set_b2JointDef_collideConnected(lua_State *tolua_S){
    int argc = 0;
    b2JointDef *cobj = nullptr;
    bool ok = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2JointDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2JointDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_set_b2JointDef_collideConnected'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (argc == 1)
        {
            bool arg0;
            ok &= luaval_to_boolean(tolua_S, 2, &arg0, "cobj:collideConnected");
            if (!ok)
            {
                tolua_error(tolua_S, "invalid arguments 1 in function 'lua_set_b2JointDef_collideConnected', was expecting bool", nullptr);
                return 0;   
            };
            cobj->collideConnected = arg0;
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2JointDef:collideConnected", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_set_b2JointDef_collideConnected'.", &tolua_err);
    return 0;
#endif
}
#endif

int lua_register_cocos2dx_b2JointDef(lua_State *tolua_S){
    tolua_usertype(tolua_S, "b2JointDef");
    tolua_cclass(tolua_S, "b2JointDef", "b2JointDef", "", nullptr);
    tolua_beginmodule(tolua_S, "b2JointDef");
        tolua_function(tolua_S, "new", lua_LuaBox2D_b2JointDef_new);
        tolua_function(tolua_S, ".call", lua_LuaBox2D_b2JointDef_new);
        tolua_variable(tolua_S, "b2JointType", lua_get_b2JointDef_b2JointType, lua_set_b2JointDef_b2JointType);
        tolua_variable(tolua_S, "userData", lua_get_b2JointDef_userData, lua_set_b2JointDef_userData);
        tolua_variable(tolua_S, "bodyA", lua_get_b2JointDef_bodyA, lua_set_b2JointDef_bodyA);
        tolua_variable(tolua_S, "bodyB", lua_get_b2JointDef_bodyB, lua_set_b2JointDef_bodyB);
        tolua_variable(tolua_S, "collideConnected", lua_get_b2JointDef_collideConnected, lua_set_b2JointDef_collideConnected);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(b2JointDef).name();
    g_luaType[typeName] = "b2JointDef";
    g_typeCast["b2JointDef"] = "b2JointDef";
    return 1;  
}

#ifndef LUA_DISABLE_lua_LuaBox2D_b2Joint_GetType
int lua_LuaBox2D_b2Joint_GetType(lua_State *tolua_S){
    int argc = 0;
    b2Joint *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2Joint", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2Joint *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'int lua_LuaBox2D_b2Joint_GetType .", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if (argc == 0)
    {
        int32 ret = cobj->GetType();
        tolua_pushnumber(tolua_S, (lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2Joint:GetType", argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'int lua_LuaBox2D_b2Joint_GetType .", &tolua_err);
    return 0;
#endif
}
#endif

#ifndef LUA_DISABLE_lua_LuaBox2D_b2Joint_GetBodyA
int lua_LuaBox2D_b2Joint_GetBodyA(lua_State *tolua_S){
    int argc = 0;
    b2Joint *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2Joint", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2Joint *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'int lua_LuaBox2D_b2Joint_GetBodyA .", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if (argc == 0)
    {
        b2Body* ret = cobj->GetBodyA();
        object_to_luaval<b2Body*>(tolua_S, "b2Body", &ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2Joint:GetBodyA", argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'int lua_LuaBox2D_b2Joint_GetBodyA .", &tolua_err);
    return 0;
#endif
}
#endif

#ifndef LUA_DISABLE_lua_LuaBox2D_b2Joint_GetBodyA
int lua_LuaBox2D_b2Joint_GetBodyB(lua_State *tolua_S){
    int argc = 0;
    b2Joint *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2Joint", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2Joint *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'int lua_LuaBox2D_b2Joint_GetBodyB .", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if (argc == 0)
    {
        b2Body* ret = cobj->GetBodyB();
        object_to_luaval<b2Body*>(tolua_S, "b2Body", &ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2Joint:GetBodyB", argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'int lua_LuaBox2D_b2Joint_GetBodyB .", &tolua_err);
    return 0;
#endif
}
#endif

#ifndef LUA_DISABLE_lua_LuaBox2D_b2Joint_GetAnchorA
int lua_LuaBox2D_b2Joint_GetAnchorA(lua_State *tolua_S){
    int argc = 0;
    b2Joint *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2Joint", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2Joint *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'int lua_LuaBox2D_b2Joint_GetAnchorA .", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if (argc == 0)
    {
        b2Vec2 newVec = cobj->GetAnchorA();
        // object_to_luaval<b2Vec2>(tolua_S, "b2Vec2", &ret);
        b2Vec2 *ret = new b2Vec2(newVec.x, newVec.y);
        object_to_luaval(tolua_S, "b2Vec2", (b2Vec2 *)ret);
        tolua_register_gc(tolua_S, lua_gettop(tolua_S));
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2Joint:GetAnchorA", argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'int lua_LuaBox2D_b2Joint_GetAnchorA .", &tolua_err);
    return 0;
#endif
}
#endif

#ifndef LUA_DISABLE_lua_LuaBox2D_b2Joint_GetAnchorB
int lua_LuaBox2D_b2Joint_GetAnchorB(lua_State *tolua_S){
    int argc = 0;
    b2Joint *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2Joint", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2Joint *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'int lua_LuaBox2D_b2Joint_GetAnchorB .", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if (argc == 0)
    {
        b2Vec2 newVec = cobj->GetAnchorB();
        // object_to_luaval<b2Vec2>(tolua_S, "b2Vec2", &ret);
        b2Vec2 *ret = new b2Vec2(newVec.x, newVec.y);
        object_to_luaval(tolua_S, "b2Vec2", (b2Vec2 *)ret);
        tolua_register_gc(tolua_S, lua_gettop(tolua_S));
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2Joint:GetAnchorB", argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'int lua_LuaBox2D_b2Joint_GetAnchorB .", &tolua_err);
    return 0;
#endif
}
#endif

#ifndef LUA_DISABLE_lua_LuaBox2D_b2Joint_GetReactionForce
int lua_LuaBox2D_b2Joint_GetReactionForce(lua_State *tolua_S){
    int argc = 0;
    b2Joint *cobj = nullptr;
    bool ok = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2JointDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2Joint *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_LuaBox2D_b2Joint_GetReactionForce'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if (argc == 1)
    {
        double arg0;
        ok &= luaval_to_number(tolua_S, 2, &arg0, "b2Joint:GetReactionForce");
        if (!ok)
        {
            tolua_error(tolua_S, "invalid arguments 1 in function 'lua_LuaBox2D_b2Joint_GetReactionForce', was expecting number", nullptr);
            return 0;   
        };
        b2Vec2 newVec = cobj->GetReactionForce(arg0);
        // object_to_luaval<b2Vec2>(tolua_S, "b2Vec2", &ret);
        b2Vec2 *ret = new b2Vec2(newVec.x, newVec.y);
        object_to_luaval(tolua_S, "b2Vec2", (b2Vec2 *)ret);
        tolua_register_gc(tolua_S, lua_gettop(tolua_S));
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2JointDef:GetReactionForce", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2Joint_GetReactionForce'.", &tolua_err);
    return 0;
#endif
}
#endif

#ifndef LUA_DISABLE_lua_LuaBox2D_b2Joint_GetReactionTorque
int lua_LuaBox2D_b2Joint_GetReactionTorque(lua_State *tolua_S){
    int argc = 0;
    b2Joint *cobj = nullptr;
    bool ok = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2JointDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2Joint *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_LuaBox2D_b2Joint_GetReactionTorque'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if (argc == 1)
    {
        double arg0;
        ok &= luaval_to_number(tolua_S, 2, &arg0, "b2Joint:GetReactionTorque");
        if (!ok)
        {
            tolua_error(tolua_S, "invalid arguments 1 in function 'lua_LuaBox2D_b2Joint_GetReactionTorque', was expecting number", nullptr);
            return 0;   
        };
        float32 ret = cobj->GetReactionTorque(arg0);
        tolua_pushnumber(tolua_S, (lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2JointDef:GetReactionTorque", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2Joint_GetReactionTorque'.", &tolua_err);
    return 0;
#endif
}
#endif

#ifndef LUA_DISABLE_lua_register_lua_LuaBox2d_b2Joint_GetNext
int lua_LuaBox2D_b2Joint_GetNext(lua_State *tolua_S){
    int argc = 0;
    b2Joint *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2Joint", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2Joint *)tolua_tousertype(tolua_S, 1, 0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_LuaBox2D_b2Joint_GetNext'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if(argc == 0){
        b2Joint  *ret = cobj -> GetNext();
        object_to_luaval<b2Joint>(tolua_S, "b2Joint", (b2Joint *)&ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2Joint:GetNext", argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2Joint_GetNext'.", &tolua_err);
#endif
    return 0; 
}
#endif

#ifndef LUA_DISABLE_lua_LuaBox2D_b2Joint_GetUserData
int lua_LuaBox2D_b2Joint_GetUserData(lua_State *tolua_S){
    int argc = 0;
    b2Joint *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2Joint", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2Joint *)tolua_tousertype(tolua_S, 1, 0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_LuaBox2D_b2Joint_GetUserData'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if(argc == 0){
        void  *ret = cobj -> GetUserData();
        object_to_luaval<void>(tolua_S, "void", (void *)&ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2Joint:GetUserData", argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2Joint_GetUserData'.", &tolua_err);
#endif
    return 0; 
}
#endif

#ifndef LUA_DISABLE_lua_LuaBox2D_b2Joint_SetUserData
int lua_LuaBox2D_b2Joint_SetUserData(lua_State *tolua_S){
    int argc = 0;
    b2Joint *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2Joint", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2Joint *)tolua_tousertype(tolua_S, 1, 0);

    argc = lua_gettop(tolua_S) - 1;
    if (argc == 1)
    {
        void* arg0;
        arg0 = ((void*) tolua_touserdata(tolua_S, 2, 0));
        cobj->SetUserData(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2Joint:SetUserData", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2Joint_SetUserData'.", &tolua_err);
#endif
    return 0;
}
#endif

#ifndef LUA_DISABLE_lua_LuaBox2D_b2Joint_IsActive
int lua_LuaBox2D_b2Joint_IsActive(lua_State *tolua_S){
    int argc = 0;
    b2Joint *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2Joint", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2Joint *)tolua_tousertype(tolua_S, 1, 0);

    argc = lua_gettop(tolua_S) - 1;
    if (argc == 0)
    {
        bool ret = cobj->IsActive();
        tolua_pushboolean(tolua_S, ret);
        return 1;
    }
    
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2Joint:IsActive", argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2Joint_IsActive'.", &tolua_err);
#endif
    return 0;
}
#endif

#ifndef LUA_DISABLE_lua_LuaBox2D_b2Joint_GetCollideConnected
int lua_LuaBox2D_b2Joint_GetCollideConnected(lua_State *tolua_S){
    int argc = 0;
    b2Joint *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2Joint", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2Joint *)tolua_tousertype(tolua_S, 1, 0);

    argc = lua_gettop(tolua_S) - 1;
    if (argc == 0)
    {
        bool ret = cobj->GetCollideConnected();
        tolua_pushboolean(tolua_S, ret);
        return 1;
    }
    
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2Joint:GetCollideConnected", argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2Joint_GetCollideConnected'.", &tolua_err);
#endif
    return 0;
}
#endif

int lua_register_cocos2dx_b2Joint(lua_State *tolua_S){
    tolua_usertype(tolua_S, "b2Joint");
    tolua_cclass(tolua_S, "b2Joint", "b2Joint", "", nullptr);
    tolua_beginmodule(tolua_S, "b2Joint");
        tolua_constant(tolua_S,"e_unknownJoint",e_unknownJoint);
        tolua_constant(tolua_S,"e_revoluteJoint",e_revoluteJoint);
        tolua_constant(tolua_S,"e_prismaticJoint",e_prismaticJoint);
        tolua_constant(tolua_S,"e_distanceJoint",e_distanceJoint);
        tolua_constant(tolua_S,"e_pulleyJoint",e_pulleyJoint);
        tolua_constant(tolua_S,"e_mouseJoint",e_mouseJoint);
        tolua_constant(tolua_S,"e_gearJoint",e_gearJoint);
        tolua_constant(tolua_S,"e_wheelJoint",e_wheelJoint);
        tolua_constant(tolua_S,"e_weldJoint",e_weldJoint);
        tolua_constant(tolua_S,"e_frictionJoint",e_frictionJoint);
        tolua_constant(tolua_S,"e_ropeJoint",e_ropeJoint);
        tolua_constant(tolua_S,"e_inactiveLimit",e_inactiveLimit);
        tolua_constant(tolua_S,"e_atLowerLimit",e_atLowerLimit);
        tolua_constant(tolua_S,"e_atUpperLimit",e_atUpperLimit);
        tolua_constant(tolua_S,"e_equalLimits",e_equalLimits);
        tolua_function(tolua_S, "GetType", lua_LuaBox2D_b2Joint_GetType);
        tolua_function(tolua_S, "GetBodyA", lua_LuaBox2D_b2Joint_GetBodyA);
        tolua_function(tolua_S, "GetBodyB", lua_LuaBox2D_b2Joint_GetBodyB);
        tolua_function(tolua_S, "GetAnchorA", lua_LuaBox2D_b2Joint_GetAnchorA);
        tolua_function(tolua_S, "GetAnchorB", lua_LuaBox2D_b2Joint_GetAnchorB);
        tolua_function(tolua_S, "GetReactionForce", lua_LuaBox2D_b2Joint_GetReactionForce);
        tolua_function(tolua_S, "GetReactionTorque", lua_LuaBox2D_b2Joint_GetReactionTorque);
        tolua_function(tolua_S, "GetNext", lua_LuaBox2D_b2Joint_GetNext);
        tolua_function(tolua_S, "GetUserData", lua_LuaBox2D_b2Joint_GetUserData);
        tolua_function(tolua_S, "SetUserData", lua_LuaBox2D_b2Joint_SetUserData);
        tolua_function(tolua_S, "IsActive", lua_LuaBox2D_b2Joint_IsActive);
        tolua_function(tolua_S, "GetCollideConnected", lua_LuaBox2D_b2Joint_GetCollideConnected);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(b2JointDef).name();
    g_luaType[typeName] = "b2JointDef";
    g_typeCast["b2JointDef"] = "b2JointDef";
    return 1;  
}


#ifndef TOLUA_DISABLE_lua_LuaBox2D_b2GearJointDef_new
int lua_LuaBox2D_b2GearJointDef_new(lua_State *tolua_S){
    int argc = 0;
    b2GearJointDef *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

    cobj = (b2GearJointDef *)tolua_tousertype(tolua_S, 1, 0);

    argc = lua_gettop(tolua_S) - 1;
    if (argc == 0)
    {
        b2GearJointDef *ret = new b2GearJointDef();
        object_to_luaval<b2GearJointDef>(tolua_S, "b2JointDef", (b2GearJointDef *)ret);
        tolua_register_gc(tolua_S, lua_gettop(tolua_S));
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2GearJointDef:new", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2GearJointDef_new'.", &tolua_err);
#endif
    return 0;
}
#endif

#ifndef TOLUA_DISABLE_lua_get_b2GearJointDef_joint1
int lua_get_b2GearJointDef_joint1(lua_State *tolua_S){
    int argc = 0;
    b2GearJointDef *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2GearJointDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2GearJointDef *)tolua_tousertype(tolua_S, 1, 0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_get_b2GearJointDef_joint1'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if(argc == 0){
        b2Joint  *ret = cobj -> joint1;
        object_to_luaval<b2Joint>(tolua_S, "b2Joint", (b2Joint *)&ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2Joint:joint1", argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_get_b2GearJointDef_joint1'.", &tolua_err);
#endif
    return 0; 
}
#endif

#ifndef TOLUA_DISABLE_lua_set_b2GearJointDef_joint1
int lua_set_b2GearJointDef_joint1(lua_State *tolua_S){
    int argc = 0;
    b2GearJointDef *cobj = nullptr;
    bool ok = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2GearJointDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2GearJointDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_set_b2GearJointDef_joint1'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if (1 == argc)
    {
        b2Joint *arg0;
        ok &= luaval_to_object<b2Joint>(tolua_S, 2, "b2Joint", &arg0);
        if (!ok)
        {
            tolua_error(tolua_S, "invalid arguments 1 in function 'lua_set_b2GearJointDef_joint1', was expecting b2Joint", nullptr);
            return 0;   
        };
        cobj->joint1 = arg0;
        lua_settop(tolua_S, 1);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2GearJointDef:joint1", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_set_b2GearJointDef_joint1'.", &tolua_err);
    return 0;
#endif
}
#endif

#ifndef TOLUA_DISABLE_lua_get_b2GearJointDef_joint2
int lua_get_b2GearJointDef_joint2(lua_State *tolua_S){
    int argc = 0;
    b2GearJointDef *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2GearJointDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2GearJointDef *)tolua_tousertype(tolua_S, 1, 0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_get_b2GearJointDef_joint2'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if(argc == 0){
        b2Joint  *ret = cobj -> joint2;
        object_to_luaval<b2Joint>(tolua_S, "b2Joint", (b2Joint *)&ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2Joint:joint2", argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_get_b2GearJointDef_joint2'.", &tolua_err);
#endif
    return 0; 
}
#endif

#ifndef TOLUA_DISABLE_lua_set_b2GearJointDef_joint2
int lua_set_b2GearJointDef_joint2(lua_State *tolua_S){
    int argc = 0;
    b2GearJointDef *cobj = nullptr;
    bool ok = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2GearJointDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2GearJointDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_set_b2GearJointDef_joint2'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if (1 == argc)
    {
        b2Joint *arg0;
        ok &= luaval_to_object<b2Joint>(tolua_S, 2, "b2Joint", &arg0);
        if (!ok)
        {
            tolua_error(tolua_S, "invalid arguments 1 in function 'lua_set_b2GearJointDef_joint2', was expecting b2Joint", nullptr);
            return 0;   
        };
        cobj->joint2 = arg0;
        lua_settop(tolua_S, 1);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2GearJointDef:joint2", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_set_b2GearJointDef_joint2'.", &tolua_err);
    return 0;
#endif
}
#endif

#ifndef TOLUA_DISABLE_lua_get_b2GearJointDef_ratio
int lua_get_b2GearJointDef_ratio(lua_State *tolua_S){
    int argc = 0;
    b2GearJointDef *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2GearJointDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2GearJointDef *)tolua_tousertype(tolua_S, 1, 0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_get_b2GearJointDef_ratio'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if(argc == 0){
        float32 ret = cobj -> ratio;
        tolua_pushnumber(tolua_S, (lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2Joint:ratio", argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_get_b2GearJointDef_ratio'.", &tolua_err);
#endif
    return 0; 
}
#endif

#ifndef TOLUA_DISABLE_lua_set_b2GearJointDef_ratio
int lua_set_b2GearJointDef_ratio(lua_State *tolua_S){
    int argc = 0;
    b2GearJointDef *cobj = nullptr;
    bool ok = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2GearJointDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2GearJointDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_set_b2GearJointDef_ratio'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if (1 == argc)
    {
        double arg0;
        ok &= luaval_to_number(tolua_S, 2, &arg0, "b2GearJointDef:ratio");
        if (!ok)
        {
            tolua_error(tolua_S, "invalid arguments 1 in function 'lua_set_b2GearJointDef_ratio', was expecting number", nullptr);
            return 0;   
        };
        cobj->ratio = arg0;
        lua_settop(tolua_S, 1);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2GearJointDef:ratio", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_set_b2GearJointDef_ratio'.", &tolua_err);
    return 0;
#endif
}
#endif

int lua_register_cocos2dx_b2GearJointDef(lua_State *tolua_S){
    tolua_usertype(tolua_S, "b2GearJointDef");
    tolua_cclass(tolua_S, "b2GearJointDef", "b2GearJointDef", "b2JointDef", nullptr);
    tolua_beginmodule(tolua_S, "b2GearJointDef");
        tolua_function(tolua_S, "new", lua_LuaBox2D_b2GearJointDef_new);
        tolua_function(tolua_S, ".call", lua_LuaBox2D_b2GearJointDef_new);
        tolua_variable(tolua_S, "joint1", lua_get_b2GearJointDef_joint1, lua_set_b2GearJointDef_joint1);
        tolua_variable(tolua_S, "joint2", lua_get_b2GearJointDef_joint2, lua_set_b2GearJointDef_joint2);
        tolua_variable(tolua_S, "ratio", lua_get_b2GearJointDef_ratio, lua_set_b2GearJointDef_ratio);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(b2GearJointDef).name();
    g_luaType[typeName] = "b2GearJointDef";
    g_typeCast["b2GearJointDef"] = "b2GearJointDef";
    return 1;  
}

#ifndef TOLUA_DISABLE_lua_LuaBox2D_b2GearJoint_GetJoint1
int lua_LuaBox2D_b2GearJoint_GetJoint1(lua_State *tolua_S){
    int argc = 0;
    b2GearJoint *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2GearJoint", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2GearJoint *)tolua_tousertype(tolua_S, 1, 0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_LuaBox2D_b2GearJoint_GetJoint1'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if(argc == 0){
        b2Joint  *ret = cobj -> GetJoint1();
        object_to_luaval<b2Joint>(tolua_S, "b2Joint", (b2Joint *)&ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2GearJoint:GetJoint1", argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2GearJoint_GetJoint1'.", &tolua_err);
#endif
    return 0; 
}
#endif

#ifndef TOLUA_DISABLE_lua_LuaBox2D_b2GearJoint_GetJoint2
int lua_LuaBox2D_b2GearJoint_GetJoint2(lua_State *tolua_S){
    int argc = 0;
    b2GearJoint *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2GearJoint", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2GearJoint *)tolua_tousertype(tolua_S, 1, 0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_LuaBox2D_b2GearJoint_GetJoint2'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if(argc == 0){
        b2Joint  *ret = cobj -> GetJoint2();
        object_to_luaval<b2Joint>(tolua_S, "b2Joint", (b2Joint *)&ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2GearJoint:GetJoint2", argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2GearJoint_GetJoint2'.", &tolua_err);
#endif
    return 0; 
}
#endif

#ifndef TOLUA_DISABLE_lua_LuaBox2D_b2GearJoint_SetRatio
int lua_LuaBox2D_b2GearJoint_SetRatio(lua_State *tolua_S){
    int argc = 0;
    b2GearJoint *cobj = nullptr;
    bool ok = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2GearJoint", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2GearJoint *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_LuaBox2D_b2GearJoint_SetRatio'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if (1 == argc)
    {
        double arg0;
        ok &= luaval_to_number(tolua_S, 2, &arg0, "b2GearJoint:SetRatio");
        if (!ok)
        {
            tolua_error(tolua_S, "invalid arguments 1 in function 'lua_LuaBox2D_b2GearJoint_SetRatio', was expecting number", nullptr);
            return 0;   
        };
        cobj->SetRatio(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2GearJoint:SetRatio", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2GearJoint_SetRatio'.", &tolua_err);
    return 0;
#endif
}
#endif

#ifndef TOLUA_DISABLE_lua_LuaBox2D_b2GearJoint_GetRatio
int lua_LuaBox2D_b2GearJoint_GetRatio(lua_State *tolua_S){
    int argc = 0;
    b2GearJoint *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2GearJoint", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2GearJoint *)tolua_tousertype(tolua_S, 1, 0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_LuaBox2D_b2GearJoint_GetRatio'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if(argc == 0){
        float32 ret = cobj -> GetRatio();
        tolua_pushnumber(tolua_S, (lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2GearJoint:GetRatio", argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2GearJoint_GetRatio'.", &tolua_err);
#endif
    return 0; 
}
#endif


#ifndef LUA_DISABLE_lua_LuaBox2D_b2GearJoint_Dump
int lua_LuaBox2D_b2GearJoint_Dump(lua_State *tolua_S){
    int argc = 0;
    b2GearJoint *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2GearJoint", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2GearJoint *)tolua_tousertype(tolua_S, 1, 0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_LuaBox2D_b2GearJoint_Dump'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if(argc == 0){
        cobj -> Dump();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2GearJoint:Dump", argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_LuaBox2D_b2GearJoint_Dump'.", &tolua_err);
#endif
    return 0; 
}
#endif

int lua_register_cocos2dx_b2GearJoint(lua_State *tolua_S){
    tolua_usertype(tolua_S, "b2GearJoint");
    tolua_cclass(tolua_S, "b2GearJoint", "b2GearJoint", "b2Joint", nullptr);
    tolua_beginmodule(tolua_S, "b2GearJoint");
        tolua_function(tolua_S, "GetJoint1", lua_LuaBox2D_b2GearJoint_GetJoint1);
        tolua_function(tolua_S, "GetJoint2", lua_LuaBox2D_b2GearJoint_GetJoint2);
        tolua_function(tolua_S, "SetRatio", lua_LuaBox2D_b2GearJoint_SetRatio);
        tolua_function(tolua_S, "GetRatio", lua_LuaBox2D_b2GearJoint_GetRatio);
        tolua_function(tolua_S, "Dump", lua_LuaBox2D_b2GearJoint_Dump);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(b2GearJoint).name();
    g_luaType[typeName] = "b2GearJoint";
    g_typeCast["b2GearJoint"] = "b2GearJoint";
    return 1;  
}

/* class of b2Vec2 */
/* new function: x of class  b2Vec2 */
#ifndef TOLUA_DISABLE_tolua_LuaBox2D_b2Vec2_new00_local
int tolua_LuaBox2D_b2Vec2_new00_local(lua_State *tolua_S)
{
    int argc = 0;
    b2Vec2 *cobj = nullptr;
    bool ok = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

    cobj = (b2Vec2 *)tolua_tousertype(tolua_S, 1, 0);

    argc = lua_gettop(tolua_S) - 1;
    do
    {
        if (argc == 0)
        {
            if (!ok)
            {
                tolua_error(tolua_S, "invalid arguments in function 'tolua_LuaBox2D_b2Vec2_new00_local'", nullptr);
                return 0;
            }
            b2Vec2 *ret = new b2Vec2();
            object_to_luaval<b2Vec2>(tolua_S, "b2Vec2", (b2Vec2 *)ret);
            tolua_register_gc(tolua_S, lua_gettop(tolua_S));
            return 1;
        }
    } while (0);

    do
    {
        if (argc == 2)
        {
            double arg0;
            ok &= luaval_to_number(tolua_S, 2, &arg0, "b2Vec2:constructor");

            if (!ok)
            {
                break;
            }
            double arg1;

            ok &= luaval_to_number(tolua_S, 3, &arg1, "b2Vec2:constructor");
            if (!ok)
            {
                break;
            }
            b2Vec2 *ret = new b2Vec2(arg0, arg1);
            object_to_luaval<b2Vec2>(tolua_S, "b2Vec2", (b2Vec2 *)ret);
            tolua_register_gc(tolua_S, lua_gettop(tolua_S));
            return 1;
        }
    } while (0);

    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2Vec2", argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2Vec2_new00_local'.", &tolua_err);
#endif
    return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: x of class  b2Vec2 */
#ifndef TOLUA_DISABLE_tolua_get_b2Vec2_x
static int tolua_get_b2Vec2_x(lua_State *tolua_S)
{
    b2Vec2 *cobj = nullptr;
 #if COCOS2D_DEBUG >= 1
     tolua_Error tolua_err;
//     if (!tolua_isusertype(tolua_S, 1, "b2Vec2", 0, &tolua_err))
//         goto tolua_lerror;
 #endif

    cobj = (b2Vec2 *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_get_b2Vec2_x'", nullptr);
        return 0;
    }
#endif
    tolua_pushnumber(tolua_S, (lua_Number)cobj->x);
    return 1;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_get_b2Vec2_x'.", &tolua_err);
    return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* set function: x of class  b2Vec2 */
#ifndef TOLUA_DISABLE_tolua_set_b2Vec2_x
static int tolua_set_b2Vec2_x(lua_State *tolua_S)
{
    int argc = 0;
    b2Vec2 *cobj = nullptr;
    bool ok = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    // if (!tolua_isusertype(tolua_S, 1, "b2Vec2", 0, &tolua_err))
    //     goto tolua_lerror;
#endif

    cobj = (b2Vec2 *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_set_b2Vec2_x'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (1 == argc)
        {
            double arg0;
            ok &= luaval_to_number(tolua_S, 2, &arg0, "b2Vec2:x");
            if (!ok)
                break;
            cobj->x = arg0;
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2Vec2:x", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_dragonbones_Transform_getx'.", &tolua_err);
    return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: y of class  b2Vec2 */
#ifndef TOLUA_DISABLE_tolua_get_b2Vec2_y
static int tolua_get_b2Vec2_y(lua_State *tolua_S)
{
    b2Vec2 *cobj = nullptr;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    // if (!tolua_isusertype(tolua_S, 1, "b2Vec2", 0, &tolua_err))
    //     goto tolua_lerror;
#endif

    cobj = (b2Vec2 *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_get_b2Vec2_y'", nullptr);
        return 0;
    }
#endif
    tolua_pushnumber(tolua_S, (lua_Number)cobj->y);
    return 1;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_get_b2Vec2_y'.", &tolua_err);
    return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* set function: y of class  b2Vec2 */
#ifndef TOLUA_DISABLE_tolua_set_b2Vec2_y
static int tolua_set_b2Vec2_y(lua_State *tolua_S)
{
    int argc = 0;
    b2Vec2 *cobj = nullptr;
    bool ok = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2Vec2", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2Vec2 *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_set_b2Vec2_y'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (1 == argc)
        {
            double arg0;
            ok &= luaval_to_number(tolua_S, 2, &arg0, "b2Vec2:y");
            if (!ok)
                break;
            cobj->y = arg0;
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2Vec2:x", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_set_b2Vec2_y'.", &tolua_err);
    return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: SetZero of class  b2Vec2 */
#ifndef TOLUA_DISABLE_tolua_LuaBox2D_b2Vec2_SetZero
int tolua_LuaBox2D_b2Vec2_SetZero(lua_State *tolua_S)
{
    int argc = 0;
    b2Vec2 *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2Vec2", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2Vec2 *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2Vec2_SetZero'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (0 == argc)
        {
            cobj->SetZero();
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2Vec2:setZero", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2Vec2_SetZero'.", &tolua_err);
    return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* set function: Set of class  b2Vec2 */
#ifndef TOLUA_DISABLE_tolua_LuaBox2D_b2Vec2_Set
int tolua_LuaBox2D_b2Vec2_Set(lua_State *tolua_S)
{
    int argc = 0;
    b2Vec2 *cobj = nullptr;
    bool ok = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2Vec2", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2Vec2 *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2Vec2_Set'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (2 == argc)
        {
            double arg0;
            ok &= luaval_to_number(tolua_S, 2, &arg0, "b2Vec2:constructor");

            if (!ok)
            {
                break;
            }
            double arg1;
            ok &= luaval_to_number(tolua_S, 3, &arg1, "b2Vec2:constructor");
            if (!ok)
            {
                break;
            }

            cobj->Set(arg0, arg1);
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2Vec2:Set", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2Vec2_Set'.", &tolua_err);
    return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

#ifndef TOLUA_DISABLE_tolua_LuaBox2D_b2Vec2_Length
int tolua_LuaBox2D_b2Vec2_Length(lua_State *tolua_S)
{
    int argc = 0;
    b2Vec2 *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2Vec2", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2Vec2 *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2Vec2_Length'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (0 == argc)
        {
            float32 ret = cobj->Length();
            tolua_pushnumber(tolua_S, (lua_Number)ret);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2Vec2:Length", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2Vec2_Length'.", &tolua_err);
    return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

#ifndef TOLUA_DISABLE_tolua_LuaBox2D_b2Vec2_LengthSquared
int tolua_LuaBox2D_b2Vec2_LengthSquared(lua_State *tolua_S)
{
    int argc = 0;
    b2Vec2 *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2Vec2", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2Vec2 *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2Vec2_LengthSquared'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (0 == argc)
        {
            float32 ret = cobj->LengthSquared();
            tolua_pushnumber(tolua_S, (lua_Number)ret);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2Vec2:LengthSquared", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2Vec2_LengthSquared'.", &tolua_err);
    return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

#ifndef TOLUA_DISABLE_tolua_LuaBox2D_b2Vec2_Normalize
int tolua_LuaBox2D_b2Vec2_Normalize(lua_State *tolua_S)
{
    int argc = 0;
    b2Vec2 *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2Vec2", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2Vec2 *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2Vec2_Normalize'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (0 == argc)
        {
            float32 ret = cobj->Normalize();
            tolua_pushnumber(tolua_S, (lua_Number)ret);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2Vec2:Normalize", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2Vec2_Normalize'.", &tolua_err);
    return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

#ifndef TOLUA_DISABLE_tolua_LuaBox2D_b2Vec2_IsValid
int tolua_LuaBox2D_b2Vec2_IsValid(lua_State *tolua_S)
{
    int argc = 0;
    b2Vec2 *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2Vec2", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2Vec2 *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2Vec2_IsValid'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (0 == argc)
        {
            bool ret = cobj->IsValid();
            tolua_pushboolean(tolua_S, (bool)ret);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2Vec2:IsValid", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2Vec2_IsValid'.", &tolua_err);
    return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

#ifndef TOLUA_DISABLE_tolua_LuaBox2D_b2Vec2_Skew
int tolua_LuaBox2D_b2Vec2_Skew(lua_State *tolua_S)
{
    int argc = 0;
    b2Vec2 *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2Vec2", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2Vec2 *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2Vec2_IsValid'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (0 == argc)
        {
            b2Vec2 newVec = cobj->Skew();
            b2Vec2 *ret = new b2Vec2(newVec.x, newVec.y);
            object_to_luaval(tolua_S, "b2Vec2", (b2Vec2 *)ret);
            tolua_register_gc(tolua_S, lua_gettop(tolua_S));
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2Vec2:IsValid", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2Vec2_IsValid'.", &tolua_err);
    return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

int lua_register_cocos2dx_b2Vec2(lua_State *tolua_S)
{
    tolua_usertype(tolua_S, "b2Vec2");
    tolua_cclass(tolua_S, "b2Vec2", "b2Vec2", "", nullptr);
    tolua_beginmodule(tolua_S, "b2Vec2");
        tolua_function(tolua_S, "new_local", tolua_LuaBox2D_b2Vec2_new00_local);
        tolua_function(tolua_S, ".call", tolua_LuaBox2D_b2Vec2_new00_local);
        tolua_function(tolua_S, "SetZero", tolua_LuaBox2D_b2Vec2_SetZero);
        tolua_function(tolua_S, "Set", tolua_LuaBox2D_b2Vec2_Set);
        tolua_function(tolua_S, "Length", tolua_LuaBox2D_b2Vec2_Length);
        tolua_function(tolua_S, "LengthSquared", tolua_LuaBox2D_b2Vec2_LengthSquared);
        tolua_function(tolua_S, "Normalize", tolua_LuaBox2D_b2Vec2_Normalize);
        tolua_function(tolua_S, "IsValid", tolua_LuaBox2D_b2Vec2_IsValid);
        tolua_function(tolua_S, "Skew", tolua_LuaBox2D_b2Vec2_Skew);
        tolua_variable(tolua_S, "x", tolua_get_b2Vec2_x, tolua_set_b2Vec2_x);
        tolua_variable(tolua_S, "y", tolua_get_b2Vec2_y, tolua_set_b2Vec2_y);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(b2Vec2).name();
    g_luaType[typeName] = "b2Vec2";
    g_typeCast["b2Vec2"] = "b2Vec2";
    return 1;
}

int tolua_LuaBox2D_b2FrictionJointDef_new00_local(lua_State *tolua_S)
{
    int argc = 0;
    b2FrictionJointDef *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

    cobj = (b2FrictionJointDef *)tolua_tousertype(tolua_S, 1, 0);
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (0 == argc)
        {
            b2FrictionJointDef* ret = (b2FrictionJointDef*)  Mtolua_new((b2FrictionJointDef)());
            object_to_luaval<b2FrictionJointDef>(tolua_S, "b2FrictionJointDef", ret);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2FrictionJointDef:new00_local", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2FrictionJointDef_new00_local'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2FrictionJointDef_Initialize(lua_State *tolua_S)
{
    int argc = 0;
    b2FrictionJointDef *cobj = nullptr;
    bool ok = true;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2FrictionJointDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2FrictionJointDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2FrictionJointDef_Initialize'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (3 == argc)
        {
            b2Body* bodyA;
            ok &= luaval_to_object<b2Body>(tolua_S, 2, "b2Body", &bodyA);
            b2Body* bodyB;
            ok &= luaval_to_object<b2Body>(tolua_S, 3, "b2Body", &bodyB);
            const b2Vec2* anchor;
            ok &= luaval_to_object<const b2Vec2>(tolua_S, 4, "const b2Vec2", &anchor);
            if(!ok)
            {
                tolua_error(tolua_S,"invalid arguments in function 'tolua_LuaBox2D_b2FrictionJointDef_Initialize'", nullptr);
                return 0;
            }
            cobj->Initialize(bodyA, bodyB, *anchor);
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2FrictionJointDef:Initialize", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2FrictionJointDef_Initialize'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2FrictionJointDef_Get_localAnchorA(lua_State *tolua_S)
{
    int argc = 0;
    b2FrictionJointDef *cobj = nullptr;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2FrictionJointDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2FrictionJointDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2FrictionJointDef_Get_localAnchorA'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (0 == argc)
        {
            b2Vec2 ret = cobj->localAnchorA;
            object_to_luaval(tolua_S, "b2Vec2", &ret);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2FrictionJointDef:Get_localAnchorA", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2FrictionJointDef_Get_localAnchorA'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2FrictionJointDef_Set_localAnchorA(lua_State *tolua_S)
{
    int argc = 0;
    b2FrictionJointDef *cobj = nullptr;
    bool ok = true;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2FrictionJointDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2FrictionJointDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2FrictionJointDef_Set_localAnchorA'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (1 == argc)
        {
            b2Vec2* anchorA;
            ok&=luaval_to_object<b2Vec2>(tolua_S, 2, "b2Vec2", &anchorA);
            if(!ok)
            {
                tolua_error(tolua_S,"invalid arguments in function 'tolua_LuaBox2D_b2FrictionJointDef_Set_localAnchorA'", nullptr);
                return 0;
            }
            cobj->localAnchorA = *anchorA;
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2FrictionJointDef:Set_localAnchorA", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2FrictionJointDef_Set_localAnchorA'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2FrictionJointDef_Get_localAnchorB(lua_State *tolua_S)
{
    int argc = 0;
    b2FrictionJointDef *cobj = nullptr;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2FrictionJointDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2FrictionJointDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2FrictionJointDef_Get_localAnchorB'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (0 == argc)
        {
            b2Vec2 ret = cobj->localAnchorB;
            object_to_luaval(tolua_S, "b2Vec2", &ret);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2FrictionJointDef:Get_localAnchorB", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2FrictionJointDef_Get_localAnchorB'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2FrictionJointDef_Set_localAnchorB(lua_State *tolua_S)
{
    int argc = 0;
    b2FrictionJointDef *cobj = nullptr;
    bool ok = true;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2FrictionJointDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2FrictionJointDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2FrictionJointDef_Set_localAnchorB'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (1 == argc)
        {
            b2Vec2* anchorB;
            ok&=luaval_to_object<b2Vec2>(tolua_S, 2, "b2Vec2", &anchorB);
            if(!ok)
            {
                tolua_error(tolua_S,"invalid arguments in function 'tolua_LuaBox2D_b2FrictionJointDef_Set_localAnchorB'", nullptr);
                return 0;
            }
            cobj->localAnchorA = *anchorB;
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2FrictionJointDef:Set_localAnchorB", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2FrictionJointDef_Set_localAnchorB'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2FrictionJointDef_Get_maxForce(lua_State *tolua_S)
{
    int argc = 0;
    b2FrictionJointDef *cobj = nullptr;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2FrictionJointDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2FrictionJointDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2FrictionJointDef_Get_maxForce'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (0 == argc)
        {
            float32 ret = cobj->maxForce;
            lua_pushnumber(tolua_S, (lua_Number)ret);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2FrictionJointDef:Get_maxForce", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2FrictionJointDef_Get_maxForce'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2FrictionJointDef_Set_maxForce(lua_State *tolua_S)
{
    int argc = 0;
    b2FrictionJointDef *cobj = nullptr;
    bool ok = true;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2FrictionJointDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2FrictionJointDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2FrictionJointDef_Set_maxForce'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (1 == argc)
        {
            double maxForce;
            ok&=luaval_to_number(tolua_S, 2, &maxForce, "tolua_LuaBox2D_b2FrictionJointDef_Set_maxForce");
            if(!ok)
            {
                tolua_error(tolua_S,"invalid arguments in function 'tolua_LuaBox2D_b2FrictionJointDef_Set_maxForce'", nullptr);
                return 0;
            }
            cobj->maxForce = maxForce;
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2FrictionJointDef:Set_maxForce", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2FrictionJointDef_Set_maxForce'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2FrictionJointDef_Get_maxTorque(lua_State *tolua_S)
{
    int argc = 0;
    b2FrictionJointDef *cobj = nullptr;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2FrictionJointDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2FrictionJointDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2FrictionJointDef_Get_maxTorque'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (0 == argc)
        {
            float32 ret = cobj->maxTorque;
            lua_pushnumber(tolua_S, (lua_Number)ret);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2FrictionJointDef:Get_maxTorque", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2FrictionJointDef_Get_maxTorque'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2FrictionJointDef_Set_maxTorque(lua_State *tolua_S)
{
    int argc = 0;
    b2FrictionJointDef *cobj = nullptr;
    bool ok = true;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2FrictionJointDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2FrictionJointDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2FrictionJointDef_Set_maxTorque'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (1 == argc)
        {
            double maxTorque;
            ok&=luaval_to_number(tolua_S, 2, &maxTorque, "tolua_LuaBox2D_b2FrictionJointDef_Set_maxTorque");
            if(!ok)
            {
                tolua_error(tolua_S,"invalid arguments in function 'tolua_LuaBox2D_b2FrictionJointDef_Set_maxTorque'", nullptr);
                return 0;
            }
            cobj->maxTorque = maxTorque;
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2FrictionJointDef:Set_maxTorque", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2FrictionJointDef_Set_maxTorque'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2FrictionJoint_GetAnchorA(lua_State *tolua_S)
{
    int argc = 0;
    b2FrictionJoint *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2FrictionJoint", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2FrictionJoint *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2FrictionJoint_GetAnchorA'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (0 == argc)
        {
            b2Vec2 anchor = cobj->GetAnchorA();
            // object_to_luaval<b2Vec2>(tolua_S, "b2Vec2", &ret);
            b2Vec2 *ret = new b2Vec2(anchor.x, anchor.y);
            object_to_luaval(tolua_S, "b2Vec2", (b2Vec2 *)ret);
            tolua_register_gc(tolua_S, lua_gettop(tolua_S));
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2FrictionJoint:GetAnchorA", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2FrictionJoint_GetAnchorA'.", &tolua_err);
    return 0;
#endif
}


int tolua_LuaBox2D_b2FrictionJoint_GetAnchorB(lua_State *tolua_S)
{
    int argc = 0;
    b2FrictionJoint *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2FrictionJoint", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2FrictionJoint *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2FrictionJoint_GetAnchorB'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (0 == argc)
        {
            b2Vec2 newVec = cobj->GetAnchorB();
            // object_to_luaval<b2Vec2>(tolua_S, "b2Vec2", &ret);
            b2Vec2 *ret = new b2Vec2(newVec.x, newVec.y);
            object_to_luaval(tolua_S, "b2Vec2", (b2Vec2 *)ret);
            tolua_register_gc(tolua_S, lua_gettop(tolua_S));
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2FrictionJoint:GetAnchorB", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2FrictionJoint_GetAnchorB'.", &tolua_err);
    return 0;
#endif
}


int tolua_LuaBox2D_b2FrictionJoint_GetReactionForce(lua_State *tolua_S)
{
    int argc = 0;
    b2FrictionJoint *cobj = nullptr;
    bool ok = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2FrictionJoint", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2FrictionJoint *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2FrictionJoint_GetReactionForce'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (1 == argc)
        {
            int arg0;
            ok &= luaval_to_int32(tolua_S, 2, &arg0, "b2FrictionJoint:GetReactionForce");
            if(!ok)
            {
                tolua_error(tolua_S,"invalid arguments in function 'tolua_LuaBox2D_b2FrictionJoint_GetReactionForce'", nullptr);
                return 0;
            }
            b2Vec2 newVec = cobj->GetReactionForce(arg0);
            // object_to_luaval<b2Vec2>(tolua_S, "b2Vec2", &ret);
            b2Vec2 *ret = new b2Vec2(newVec.x, newVec.y);
            object_to_luaval(tolua_S, "b2Vec2", (b2Vec2 *)ret);
            tolua_register_gc(tolua_S, lua_gettop(tolua_S));
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2FrictionJoint:GetReactionForce", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2FrictionJoint_GetReactionForce'.", &tolua_err);
    return 0;
#endif
}


int tolua_LuaBox2D_b2FrictionJoint_GetReactionTorque(lua_State *tolua_S)
{
    int argc = 0;
    b2FrictionJoint *cobj = nullptr;
    bool ok = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2FrictionJoint", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2FrictionJoint *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2FrictionJoint_GetReactionTorque'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (1 == argc)
        {
            double arg0;
            ok &= luaval_to_number(tolua_S, 2, &arg0, "b2FrictionJoint:GetReactionTorque");
            if(!ok)
            {
                tolua_error(tolua_S,"invalid arguments in function 'tolua_LuaBox2D_b2FrictionJoint_GetReactionTorque'", nullptr);
                return 0;
            }
            float32 ret = cobj->GetReactionTorque((float)arg0);
            tolua_pushnumber(tolua_S, (lua_Number)ret);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2FrictionJoint:GetReactionTorque", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2FrictionJoint_GetReactionTorque'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2FrictionJoint_GetLocalAnchorA(lua_State *tolua_S)
{
    int argc = 0;
    b2FrictionJoint *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2FrictionJoint", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2FrictionJoint *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2FrictionJoint_GetLocalAnchorA'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (0 == argc)
        {
            b2Vec2 newVec = cobj->GetLocalAnchorA();
            // object_to_luaval<b2Vec2>(tolua_S, "b2Vec2", &ret);
            b2Vec2 *ret = new b2Vec2(newVec.x, newVec.y);
            object_to_luaval(tolua_S, "b2Vec2", (b2Vec2 *)ret);
            tolua_register_gc(tolua_S, lua_gettop(tolua_S));
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2FrictionJoint:GetLocalAnchorA", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2FrictionJoint_GetLocalAnchorA'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2FrictionJoint_GetLocalAnchorB(lua_State *tolua_S)
{
    int argc = 0;
    b2FrictionJoint *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2FrictionJoint", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2FrictionJoint *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2FrictionJoint_GetLocalAnchorB'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (0 == argc)
        {
            b2Vec2 newVec = cobj->GetLocalAnchorB();
            // object_to_luaval<b2Vec2>(tolua_S, "b2Vec2", &ret);
            b2Vec2 *ret = new b2Vec2(newVec.x, newVec.y);
            object_to_luaval(tolua_S, "b2Vec2", (b2Vec2 *)ret);
            tolua_register_gc(tolua_S, lua_gettop(tolua_S));
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2FrictionJoint:GetLocalAnchorB", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2FrictionJoint_GetLocalAnchorB'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2FrictionJoint_SetMaxForce(lua_State *tolua_S)
{
    int argc = 0;
    b2FrictionJoint *cobj = nullptr;
    bool ok = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2FrictionJoint", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2FrictionJoint *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2FrictionJoint_SetMaxForce'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (1 == argc)
        {
            double arg0;
            ok &= luaval_to_number(tolua_S, 2, &arg0, "b2FrictionJoint:SetMaxForce");
            if(!ok)
            {
                tolua_error(tolua_S,"invalid arguments in function 'tolua_LuaBox2D_b2FrictionJoint_SetMaxForce'", nullptr);
                return 0;
            }
            cobj->SetMaxForce(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2FrictionJoint:SetMaxForce", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2FrictionJoint_SetMaxForce'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2FrictionJoint_SetMaxTorque(lua_State *tolua_S)
{
    int argc = 0;
    b2FrictionJoint *cobj = nullptr;
    bool ok = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2FrictionJoint", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2FrictionJoint *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2FrictionJoint_SetMaxTorque'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (1 == argc)
        {
            double arg0;
            ok &= luaval_to_number(tolua_S, 2, &arg0, "b2FrictionJoint:SetMaxTorque");
            if(!ok)
            {
                tolua_error(tolua_S,"invalid arguments in function 'tolua_LuaBox2D_b2FrictionJoint_SetMaxTorque'", nullptr);
                return 0;
            }
            cobj->SetMaxTorque(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2FrictionJoint:SetMaxTorque", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2FrictionJoint_SetMaxTorque'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2FrictionJoint_GetMaxTorque(lua_State *tolua_S)
{
    int argc = 0;
    b2FrictionJoint *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2FrictionJoint", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2FrictionJoint *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2FrictionJoint_GetMaxTorque'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (0 == argc)
        {
            double ret = cobj->GetMaxTorque();
            lua_pushnumber(tolua_S, (lua_Number)ret);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2FrictionJoint:GetMaxTorque", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2FrictionJoint_GetMaxTorque'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2FrictionJoint_Dump(lua_State *tolua_S)
{
    int argc = 0;
    b2FrictionJoint *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2FrictionJoint", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2FrictionJoint *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2FrictionJoint_Dump'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (0 == argc)
        {
            cobj->Dump();
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2FrictionJoint:Dump", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2FrictionJoint_Dump'.", &tolua_err);
    return 0;
#endif
}


int lua_register_cocos2dx_b2FrictionJointDef(lua_State *tolua_S)
{
    tolua_usertype(tolua_S, "b2FrictionJointDef");
    tolua_cclass(tolua_S, "b2FrictionJointDef", "b2FrictionJointDef", "b2JointDef", nullptr);
    tolua_beginmodule(tolua_S, "b2FrictionJointDef");
    tolua_function(tolua_S, "new", tolua_LuaBox2D_b2FrictionJointDef_new00_local);
    tolua_function(tolua_S, "new_local", tolua_LuaBox2D_b2FrictionJointDef_new00_local);
    tolua_function(tolua_S, ".call", tolua_LuaBox2D_b2FrictionJointDef_new00_local);
    tolua_function(tolua_S, "Initialize", tolua_LuaBox2D_b2FrictionJointDef_Initialize);
    tolua_variable(tolua_S, "localAnchorA", tolua_LuaBox2D_b2FrictionJointDef_Get_localAnchorA,tolua_LuaBox2D_b2FrictionJointDef_Set_localAnchorA);
    tolua_variable(tolua_S, "localAnchorB", tolua_LuaBox2D_b2FrictionJointDef_Get_localAnchorB,tolua_LuaBox2D_b2FrictionJointDef_Set_localAnchorB);
    tolua_variable(tolua_S, "maxForce", tolua_LuaBox2D_b2FrictionJointDef_Get_maxForce,tolua_LuaBox2D_b2FrictionJointDef_Set_maxForce);
    tolua_variable(tolua_S, "maxTorque", tolua_LuaBox2D_b2FrictionJointDef_Get_maxTorque,tolua_LuaBox2D_b2FrictionJointDef_Set_maxTorque);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(b2FrictionJointDef).name();
    g_luaType[typeName] = "b2FrictionJointDef";
    g_typeCast["b2FrictionJointDef"] = "b2FrictionJointDef";
    return 1;
}

int lua_register_cocos2dx_b2FrictionJoint(lua_State *tolua_S)
{
    tolua_usertype(tolua_S, "b2FrictionJoint");
    tolua_cclass(tolua_S, "b2FrictionJoint", "b2FrictionJoint", "b2Joint", nullptr);
    tolua_beginmodule(tolua_S, "b2FrictionJoint");
    tolua_function(tolua_S, "GetAnchorA", tolua_LuaBox2D_b2FrictionJoint_GetAnchorA);
    tolua_function(tolua_S, "GetAnchorB", tolua_LuaBox2D_b2FrictionJoint_GetAnchorB);
    tolua_function(tolua_S, "GetReactionForce", tolua_LuaBox2D_b2FrictionJoint_GetReactionForce);
    tolua_function(tolua_S, "GetReactionTorque", tolua_LuaBox2D_b2FrictionJoint_GetReactionTorque);
    tolua_function(tolua_S, "GetLocalAnchorA", tolua_LuaBox2D_b2FrictionJoint_GetLocalAnchorA);
    tolua_function(tolua_S, "GetLocalAnchorB", tolua_LuaBox2D_b2FrictionJoint_GetLocalAnchorB);
    tolua_function(tolua_S, "SetMaxForce", tolua_LuaBox2D_b2FrictionJoint_SetMaxForce);
    tolua_function(tolua_S, "SetMaxTorque", tolua_LuaBox2D_b2FrictionJoint_SetMaxTorque);
    tolua_function(tolua_S, "GetMaxTorque", tolua_LuaBox2D_b2FrictionJoint_GetMaxTorque);
    tolua_function(tolua_S, "Dump", tolua_LuaBox2D_b2FrictionJoint_Dump);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(b2FrictionJoint).name();
    g_luaType[typeName] = "b2FrictionJoint";
    g_typeCast["b2FrictionJoint"] = "b2FrictionJoint";
    return 1;
}

int tolua_LuaBox2D_b2MouseJoint_GetAnchorA(lua_State *tolua_S)
{
    int argc = 0;
    b2MouseJoint *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2MouseJoint", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2MouseJoint *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2MouseJoint_GetAnchorA'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (0 == argc)
        {
            b2Vec2 newVec = cobj->GetAnchorA();
            // object_to_luaval<b2Vec2>(tolua_S, "b2Vec2", &ret);
            b2Vec2 *ret = new b2Vec2(newVec.x, newVec.y);
            object_to_luaval(tolua_S, "b2Vec2", (b2Vec2 *)ret);
            tolua_register_gc(tolua_S, lua_gettop(tolua_S));
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2MouseJoint:GetAnchorA", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2MouseJoint_GetAnchorA'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2MouseJoint_GetAnchorB(lua_State *tolua_S)
{
    int argc = 0;
    b2MouseJoint *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2MouseJoint", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2MouseJoint *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2MouseJoint_GetAnchorB'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (0 == argc)
        {
            b2Vec2 newVec = cobj->GetAnchorB();
            // object_to_luaval<b2Vec2>(tolua_S, "b2Vec2", &ret);
            b2Vec2 *ret = new b2Vec2(newVec.x, newVec.y);
            object_to_luaval(tolua_S, "b2Vec2", (b2Vec2 *)ret);
            tolua_register_gc(tolua_S, lua_gettop(tolua_S));
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2MouseJoint:GetAnchorB", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2MouseJoint_GetAnchorB'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2MouseJoint_GetReactionForce(lua_State *tolua_S)
{
    int argc = 0;
    b2MouseJoint *cobj = nullptr;
    bool ok = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2MouseJoint", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2MouseJoint *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2MouseJoint_GetReactionForce'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (1 == argc)
        {
            int arg0;
            ok &= luaval_to_int32(tolua_S, 2, &arg0, "b2FrictionJoint:GetReactionForce");
            if(!ok)
            {
                tolua_error(tolua_S,"invalid arguments in function 'tolua_LuaBox2D_b2MouseJoint_GetReactionForce'", nullptr);
                return 0;
            }
            b2Vec2 newVec = cobj->GetReactionForce(arg0);
            // object_to_luaval<b2Vec2>(tolua_S, "b2Vec2", &ret);
            b2Vec2 *ret = new b2Vec2(newVec.x, newVec.y);
            object_to_luaval(tolua_S, "b2Vec2", (b2Vec2 *)ret);
            tolua_register_gc(tolua_S, lua_gettop(tolua_S));
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2MouseJoint:GetReactionForce", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2MouseJoint_GetReactionForce'.", &tolua_err);
    return 0;
#endif
}


int tolua_LuaBox2D_b2MouseJoint_GetReactionTorque(lua_State *tolua_S)
{
    int argc = 0;
    b2MouseJoint *cobj = nullptr;
    bool ok = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2MouseJoint", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2MouseJoint *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2MouseJoint_GetReactionTorque'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (1 == argc)
        {
            double arg0;
            ok &= luaval_to_number(tolua_S, 2, &arg0, "b2MouseJoint:GetReactionTorque");
            if(!ok)
            {
                tolua_error(tolua_S,"invalid arguments in function 'tolua_LuaBox2D_b2MouseJoint_GetReactionTorque'", nullptr);
                return 0;
            }
            float32 ret = cobj->GetReactionTorque((float)arg0);
            tolua_pushnumber(tolua_S, (lua_Number)ret);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2MouseJoint:GetReactionTorque", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2MouseJoint_GetReactionTorque'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2MouseJoint_SetTarget(lua_State *tolua_S)
{
    int argc = 0;
    b2MouseJoint *cobj = nullptr;
    bool ok = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2MouseJoint", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2MouseJoint *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2MouseJoint_SetTarget'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (1 == argc)
        {
            b2Vec2* arg0;
            ok &= luaval_to_object<b2Vec2>(tolua_S, 2, "b2Vec2", &arg0);
            if(!ok)
            {
                tolua_error(tolua_S,"invalid arguments in function 'tolua_LuaBox2D_b2MouseJoint_SetTarget'", nullptr);
                return 0;
            }
            cobj->SetTarget(*arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2MouseJoint:SetTarget", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2MouseJoint_SetTarget'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2MouseJoint_GetTarget(lua_State *tolua_S)
{
    int argc = 0;
    b2MouseJoint *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2MouseJoint", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2MouseJoint *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2MouseJoint_GetTarget'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (0 == argc)
        {
            b2Vec2 newVec = cobj->GetTarget();
            // object_to_luaval<b2Vec2>(tolua_S, "b2Vec2", &ret);
            b2Vec2 *ret = new b2Vec2(newVec.x, newVec.y);
            object_to_luaval(tolua_S, "b2Vec2", (b2Vec2 *)ret);
            tolua_register_gc(tolua_S, lua_gettop(tolua_S));
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2MouseJoint:GetTarget", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2MouseJoint_GetTarget'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2MouseJoint_SetMaxForce(lua_State *tolua_S)
{
    int argc = 0;
    b2MouseJoint *cobj = nullptr;
    bool ok = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2MouseJoint", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2MouseJoint *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2MouseJoint_SetMaxForce'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (1 == argc)
        {
            double arg0;
            ok &= luaval_to_number(tolua_S, 2, &arg0);
            if(!ok)
            {
                tolua_error(tolua_S,"invalid arguments in function 'tolua_LuaBox2D_b2MouseJoint_SetMaxForce'", nullptr);
                return 0;
            }
            cobj->SetMaxForce(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2MouseJoint:SetMaxForce", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2MouseJoint_SetMaxForce'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2MouseJoint_GetMaxForce(lua_State *tolua_S)
{
    int argc = 0;
    b2MouseJoint *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2MouseJoint", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2MouseJoint *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2MouseJoint_GetMaxForce'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (0 == argc)
        {
            float32 ret = cobj->GetMaxForce();
            lua_pushnumber(tolua_S, (lua_Number)ret);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2MouseJoint:GetMaxForce", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2MouseJoint_GetMaxForce'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2MouseJoint_SetFrequency(lua_State *tolua_S)
{
    int argc = 0;
    b2MouseJoint *cobj = nullptr;
    bool ok = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2MouseJoint", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2MouseJoint *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2MouseJoint_SetFrequency'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (1 == argc)
        {
            double arg0;
            ok &= luaval_to_number(tolua_S, 2, &arg0);
            if(!ok)
            {
                tolua_error(tolua_S,"invalid arguments in function 'tolua_LuaBox2D_b2MouseJoint_SetFrequency'", nullptr);
                return 0;
            }
            cobj->SetFrequency(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2MouseJoint:SetFrequency", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2MouseJoint_SetFrequency'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2MouseJoint_GetFrequency(lua_State *tolua_S)
{
    int argc = 0;
    b2MouseJoint *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2MouseJoint", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2MouseJoint *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2MouseJoint_GetFrequency'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (0 == argc)
        {
            float32 ret = cobj->GetFrequency();
            lua_pushnumber(tolua_S, (lua_Number)ret);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2MouseJoint:GetFrequency", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2MouseJoint_GetFrequency'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2MouseJoint_SetDampingRatio(lua_State *tolua_S)
{
    int argc = 0;
    b2MouseJoint *cobj = nullptr;
    bool ok = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2MouseJoint", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2MouseJoint *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2MouseJoint_SetDampingRatio'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (1 == argc)
        {
            double arg0;
            ok &= luaval_to_number(tolua_S, 2, &arg0);
            if(!ok)
            {
                tolua_error(tolua_S,"invalid arguments in function 'tolua_LuaBox2D_b2MouseJoint_SetDampingRatio'", nullptr);
                return 0;
            }
            cobj->SetDampingRatio(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2MouseJoint:SetDampingRatio", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2MouseJoint_SetDampingRatio'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2MouseJoint_GetDampingRatio(lua_State *tolua_S)
{
    int argc = 0;
    b2MouseJoint *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2MouseJoint", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2MouseJoint *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2MouseJoint_GetDampingRatio'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (0 == argc)
        {
            float32 ret = cobj->GetDampingRatio();
            lua_pushnumber(tolua_S, (lua_Number)ret);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2MouseJoint:GetDampingRatio", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2MouseJoint_GetDampingRatio'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2MouseJoint_Dump(lua_State *tolua_S)
{
    int argc = 0;
    b2MouseJoint *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2MouseJoint", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2MouseJoint *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2MouseJoint_Dump'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (0 == argc)
        {
            cobj->Dump();
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2MouseJoint:Dump", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2MouseJoint_Dump'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2MouseJointDef_new00_local(lua_State *tolua_S)
{
    int argc = 0;
    b2MouseJointDef *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

    cobj = (b2MouseJointDef *)tolua_tousertype(tolua_S, 1, 0);
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (0 == argc)
        {
            b2MouseJointDef* ret = (b2MouseJointDef*)  Mtolua_new((b2MouseJointDef)());
            object_to_luaval<b2MouseJointDef>(tolua_S, "b2MouseJointDef", ret);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2MouseJointDef:new00_local", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2MouseJointDef_new00_local'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2MouseJointDef_Get_target(lua_State *tolua_S)
{
    int argc = 0;
    b2MouseJointDef *cobj = nullptr;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2MouseJointDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2MouseJointDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2MouseJointDef_Get_target'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (0 == argc)
        {
            b2Vec2 ret = cobj->target;
            object_to_luaval(tolua_S, "b2Vec2", &ret);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2MouseJointDef:Get_target", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2MouseJointDef_Get_target'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2MouseJointDef_Set_target(lua_State *tolua_S)
{
    int argc = 0;
    b2MouseJointDef *cobj = nullptr;
    bool ok = true;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2MouseJointDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2MouseJointDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2MouseJointDef_Set_target'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (1 == argc)
        {
            b2Vec2* target;
            ok&=luaval_to_object<b2Vec2>(tolua_S, 2, "b2Vec2", &target);
            if(!ok)
            {
                tolua_error(tolua_S,"invalid arguments in function 'tolua_LuaBox2D_b2MouseJointDef_Set_target'", nullptr);
                return 0;
            }
            cobj->target = *target;
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2MouseJointDef:Set_target", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2MouseJointDef_Set_target'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2MouseJointDef_Get_maxForce(lua_State *tolua_S)
{
    int argc = 0;
    b2MouseJointDef *cobj = nullptr;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2MouseJointDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2MouseJointDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2MouseJointDef_Get_maxForce'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (0 == argc)
        {
            float32 ret = cobj->maxForce;
            lua_pushnumber(tolua_S, (lua_Number)ret);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2MouseJointDef:Get_maxForce", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2MouseJointDef_Get_maxForce'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2MouseJointDef_Set_maxForce(lua_State *tolua_S)
{
    int argc = 0;
    b2MouseJointDef *cobj = nullptr;
    bool ok = true;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2MouseJointDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2MouseJointDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2MouseJointDef_Set_maxForce'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (1 == argc)
        {
            double maxForce;
            ok&=luaval_to_number(tolua_S, 2, &maxForce);
            if(!ok)
            {
                tolua_error(tolua_S,"invalid arguments in function 'tolua_LuaBox2D_b2MouseJointDef_Set_maxForce'", nullptr);
                return 0;
            }
            cobj->maxForce = maxForce;
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2MouseJointDef:Set_maxForce", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2MouseJointDef_Set_maxForce'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2MouseJointDef_Get_frequencyHz(lua_State *tolua_S)
{
    int argc = 0;
    b2MouseJointDef *cobj = nullptr;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2MouseJointDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2MouseJointDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2MouseJointDef_Get_frequencyHz'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (0 == argc)
        {
            float32 ret = cobj->frequencyHz;
            lua_pushnumber(tolua_S, (lua_Number)ret);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2MouseJointDef:Get_frequencyHz", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2MouseJointDef_Get_frequencyHz'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2MouseJointDef_Set_frequencyHz(lua_State *tolua_S)
{
    int argc = 0;
    b2MouseJointDef *cobj = nullptr;
    bool ok = true;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2MouseJointDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2MouseJointDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2MouseJointDef_Set_frequencyHz'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (1 == argc)
        {
            double frequencyHz;
            ok&=luaval_to_number(tolua_S, 2, &frequencyHz);
            if(!ok)
            {
                tolua_error(tolua_S,"invalid arguments in function 'tolua_LuaBox2D_b2MouseJointDef_Set_frequencyHz'", nullptr);
                return 0;
            }
            cobj->frequencyHz = frequencyHz;
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2MouseJointDef:Set_frequencyHz", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2MouseJointDef_Set_frequencyHz'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2MouseJointDef_Get_dampingRatio(lua_State *tolua_S)
{
    int argc = 0;
    b2MouseJointDef *cobj = nullptr;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2MouseJointDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2MouseJointDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2MouseJointDef_Get_dampingRatio'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (0 == argc)
        {
            float32 ret = cobj->dampingRatio;
            lua_pushnumber(tolua_S, (lua_Number)ret);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2MouseJointDef:Get_dampingRatio", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2MouseJointDef_Get_dampingRatio'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2MouseJointDef_Set_dampingRatio(lua_State *tolua_S)
{
    int argc = 0;
    b2MouseJointDef *cobj = nullptr;
    bool ok = true;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2MouseJointDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2MouseJointDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2MouseJointDef_Set_dampingRatio'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (1 == argc)
        {
            double dampingRatio;
            ok&=luaval_to_number(tolua_S, 2, &dampingRatio);
            if(!ok)
            {
                tolua_error(tolua_S,"invalid arguments in function 'tolua_LuaBox2D_b2MouseJointDef_Set_dampingRatio'", nullptr);
                return 0;
            }
            cobj->dampingRatio = dampingRatio;
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2MouseJointDef:Set_dampingRatio", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2MouseJointDef_Set_dampingRatio'.", &tolua_err);
    return 0;
#endif
}

int lua_register_cocos2dx_b2MouseJointDef(lua_State *tolua_S)
{
    tolua_usertype(tolua_S, "b2MouseJointDef");
    tolua_cclass(tolua_S, "b2MouseJointDef", "b2MouseJointDef", "b2JointDef", nullptr);
    tolua_beginmodule(tolua_S, "b2MouseJointDef");
    tolua_function(tolua_S, "new", tolua_LuaBox2D_b2MouseJointDef_new00_local);
    tolua_function(tolua_S, "new_local", tolua_LuaBox2D_b2MouseJointDef_new00_local);
    tolua_function(tolua_S, ".call", tolua_LuaBox2D_b2MouseJointDef_new00_local);
    tolua_variable(tolua_S, "target", tolua_LuaBox2D_b2MouseJointDef_Get_target,tolua_LuaBox2D_b2MouseJointDef_Set_target);
    tolua_variable(tolua_S, "maxForce", tolua_LuaBox2D_b2MouseJointDef_Get_maxForce,tolua_LuaBox2D_b2MouseJointDef_Set_maxForce);
    tolua_variable(tolua_S, "frequencyHz", tolua_LuaBox2D_b2MouseJointDef_Get_frequencyHz,tolua_LuaBox2D_b2MouseJointDef_Set_frequencyHz);
    tolua_variable(tolua_S, "dampingRatio", tolua_LuaBox2D_b2MouseJointDef_Get_dampingRatio,tolua_LuaBox2D_b2MouseJointDef_Set_dampingRatio);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(b2MouseJointDef).name();
    g_luaType[typeName] = "b2MouseJointDef";
    g_typeCast["b2MouseJointDef"] = "b2MouseJointDef";
    return 1;
}

int lua_register_cocos2dx_b2MouseJoint(lua_State *tolua_S)
{
    tolua_usertype(tolua_S, "b2MouseJoint");
    tolua_cclass(tolua_S, "b2MouseJoint", "b2MouseJoint", "b2Joint", nullptr);
    tolua_beginmodule(tolua_S, "b2MouseJoint");
    tolua_function(tolua_S, "GetAnchorA", tolua_LuaBox2D_b2MouseJoint_GetAnchorA);
    tolua_function(tolua_S, "GetAnchorB", tolua_LuaBox2D_b2MouseJoint_GetAnchorB);
    tolua_function(tolua_S, "GetReactionForce", tolua_LuaBox2D_b2MouseJoint_GetReactionForce);
    tolua_function(tolua_S, "GetReactionTorque", tolua_LuaBox2D_b2MouseJoint_GetReactionTorque);
    tolua_function(tolua_S, "SetTarget", tolua_LuaBox2D_b2MouseJoint_SetTarget);
    tolua_function(tolua_S, "GetTarget", tolua_LuaBox2D_b2MouseJoint_GetTarget);
    tolua_function(tolua_S, "SetMaxForce", tolua_LuaBox2D_b2MouseJoint_SetMaxForce);
    tolua_function(tolua_S, "SetMaxTorque", tolua_LuaBox2D_b2MouseJoint_GetMaxForce);
    tolua_function(tolua_S, "SetFrequency", tolua_LuaBox2D_b2MouseJoint_SetFrequency);
    tolua_function(tolua_S, "GetFrequency", tolua_LuaBox2D_b2MouseJoint_GetFrequency);
    tolua_function(tolua_S, "SetDampingRatio", tolua_LuaBox2D_b2MouseJoint_SetDampingRatio);
    tolua_function(tolua_S, "GetDampingRatio", tolua_LuaBox2D_b2MouseJoint_GetDampingRatio);
    tolua_function(tolua_S, "Dump", tolua_LuaBox2D_b2MouseJoint_Dump);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(b2MouseJoint).name();
    g_luaType[typeName] = "b2MouseJoint";
    g_typeCast["b2MouseJoint"] = "b2MouseJoint";
    return 1;
}

int tolua_LuaBox2D_b2PulleyJointDef_new00_local(lua_State *tolua_S)
{
    int argc = 0;
    b2PulleyJointDef *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

    cobj = (b2PulleyJointDef *)tolua_tousertype(tolua_S, 1, 0);

    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (0 == argc)
        {
            b2PulleyJointDef* ret = (b2PulleyJointDef*)  Mtolua_new((b2PulleyJointDef)());
            object_to_luaval<b2PulleyJointDef>(tolua_S, "b2PulleyJointDef", ret);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2PulleyJointDef:new00_local", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2PulleyJointDef_new00_local'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2PulleyJointDef_Initialize(lua_State *tolua_S)
{
    int argc = 0;
    b2PulleyJointDef *cobj = nullptr;
    bool ok = true;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2PulleyJointDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2PulleyJointDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2PulleyJointDef_Initialize'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (7 == argc)
        {
            b2Body* bodyA;
            ok &= luaval_to_object<b2Body>(tolua_S, 2, "b2Body", &bodyA);
            b2Body* bodyB;
            ok &= luaval_to_object<b2Body>(tolua_S, 3, "b2Body", &bodyB);
            const b2Vec2* groundAnchorA;
            ok &= luaval_to_object<const b2Vec2>(tolua_S, 4, "const b2Vec2", &groundAnchorA);
            const b2Vec2* groundAnchorB;
            ok &= luaval_to_object<const b2Vec2>(tolua_S, 5, "const b2Vec2", &groundAnchorB);
            const b2Vec2* anchorA;
            ok &= luaval_to_object<const b2Vec2>(tolua_S, 6, "const b2Vec2", &anchorA);
            const b2Vec2* anchorB;
            ok &= luaval_to_object<const b2Vec2>(tolua_S, 7, "const b2Vec2", &anchorB);
            double ratio;
            ok &= luaval_to_number(tolua_S, 8, &ratio);
            if(!ok)
            {
                tolua_error(tolua_S,"invalid arguments in function 'tolua_LuaBox2D_b2PulleyJointDef_Initialize'", nullptr);
                return 0;
            }
            cobj->Initialize(bodyA, bodyB, *groundAnchorA, *groundAnchorB, *anchorA, *anchorB, ratio);
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2PulleyJointDef:Initialize", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2PulleyJointDef_Initialize'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2PulleyJointDef_Get_groundAnchorA(lua_State *tolua_S)
{
    int argc = 0;
    b2PulleyJointDef *cobj = nullptr;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2PulleyJointDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2PulleyJointDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2PulleyJointDef_Get_groundAnchorA'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (0 == argc)
        {
            b2Vec2 ret = cobj->groundAnchorA;
            object_to_luaval(tolua_S, "b2Vec2", &ret);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2PulleyJointDef:Get_groundAnchorA", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2PulleyJointDef_Get_groundAnchorA'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2PulleyJointDef_Set_groundAnchorA(lua_State *tolua_S)
{
    int argc = 0;
    b2PulleyJointDef *cobj = nullptr;
    bool ok = true;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2PulleyJointDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2PulleyJointDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2PulleyJointDef_Set_groundAnchorA'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (1 == argc)
        {
            b2Vec2* groundAnchorA;
            ok&=luaval_to_object<b2Vec2>(tolua_S, 2, "b2Vec2", &groundAnchorA);
            if(!ok)
            {
                tolua_error(tolua_S,"invalid arguments in function 'tolua_LuaBox2D_b2PulleyJointDef_Set_groundAnchorA'", nullptr);
                return 0;
            }
            cobj->groundAnchorA = *groundAnchorA;
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2PulleyJointDef:Set_groundAnchorA", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2PulleyJointDef_Set_groundAnchorA'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2PulleyJointDef_Get_groundAnchorB(lua_State *tolua_S)
{
    int argc = 0;
    b2PulleyJointDef *cobj = nullptr;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2PulleyJointDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2PulleyJointDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2PulleyJointDef_Get_groundAnchorB'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (0 == argc)
        {
            b2Vec2 ret = cobj->groundAnchorB;
            object_to_luaval(tolua_S, "b2Vec2", &ret);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2PulleyJointDef:Get_groundAnchorB", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2PulleyJointDef_Get_groundAnchorB'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2PulleyJointDef_Set_groundAnchorB(lua_State *tolua_S)
{
    int argc = 0;
    b2PulleyJointDef *cobj = nullptr;
    bool ok = true;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2PulleyJointDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2PulleyJointDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2PulleyJointDef_Set_groundAnchorB'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (1 == argc)
        {
            b2Vec2* groundAnchorB;
            ok&=luaval_to_object<b2Vec2>(tolua_S, 2, "b2Vec2", &groundAnchorB);
            if(!ok)
            {
                tolua_error(tolua_S,"invalid arguments in function 'tolua_LuaBox2D_b2PulleyJointDef_Set_groundAnchorB'", nullptr);
                return 0;
            }
            cobj->groundAnchorB = *groundAnchorB;
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2PulleyJointDef:Set_groundAnchorB", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2PulleyJointDef_Set_groundAnchorB'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2PulleyJointDef_Get_localAnchorA(lua_State *tolua_S)
{
    int argc = 0;
    b2PulleyJointDef *cobj = nullptr;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2PulleyJointDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2PulleyJointDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2PulleyJointDef_Get_localAnchorA'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (0 == argc)
        {
            b2Vec2 ret = cobj->localAnchorA;
            object_to_luaval(tolua_S, "b2Vec2", &ret);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2PulleyJointDef:Get_localAnchorA", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2PulleyJointDef_Get_localAnchorA'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2PulleyJointDef_Set_localAnchorA(lua_State *tolua_S)
{
    int argc = 0;
    b2PulleyJointDef *cobj = nullptr;
    bool ok = true;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2PulleyJointDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2PulleyJointDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2PulleyJointDef_Set_localAnchorA'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (1 == argc)
        {
            b2Vec2* localAnchorA;
            ok&=luaval_to_object<b2Vec2>(tolua_S, 2, "b2Vec2", &localAnchorA);
            if(!ok)
            {
                tolua_error(tolua_S,"invalid arguments in function 'tolua_LuaBox2D_b2PulleyJointDef_Set_localAnchorA'", nullptr);
                return 0;
            }
            cobj->localAnchorA = *localAnchorA;
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2PulleyJointDef:Set_localAnchorA", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2PulleyJointDef_Set_localAnchorA'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2PulleyJointDef_Get_localAnchorB(lua_State *tolua_S)
{
    int argc = 0;
    b2PulleyJointDef *cobj = nullptr;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2PulleyJointDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2PulleyJointDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2PulleyJointDef_Get_localAnchorB'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (0 == argc)
        {
            b2Vec2 ret = cobj->localAnchorB;
            object_to_luaval(tolua_S, "b2Vec2", &ret);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2PulleyJointDef:Get_localAnchorB", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2PulleyJointDef_Get_localAnchorB'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2PulleyJointDef_Set_localAnchorB(lua_State *tolua_S)
{
    int argc = 0;
    b2PulleyJointDef *cobj = nullptr;
    bool ok = true;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2PulleyJointDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2PulleyJointDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2PulleyJointDef_Set_localAnchorB'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (1 == argc)
        {
            b2Vec2* localAnchorB;
            ok&=luaval_to_object<b2Vec2>(tolua_S, 2, "b2Vec2", &localAnchorB);
            if(!ok)
            {
                tolua_error(tolua_S,"invalid arguments in function 'tolua_LuaBox2D_b2PulleyJointDef_Set_localAnchorB'", nullptr);
                return 0;
            }
            cobj->localAnchorB = *localAnchorB;
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2PulleyJointDef:Set_localAnchorB", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2PulleyJointDef_Set_localAnchorB'.", &tolua_err);
    return 0;
#endif
}


int tolua_LuaBox2D_b2PulleyJointDef_Get_lengthA(lua_State *tolua_S)
{
    int argc = 0;
    b2PulleyJointDef *cobj = nullptr;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2PulleyJointDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2PulleyJointDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2PulleyJointDef_Get_lengthA'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (0 == argc)
        {
            float32 ret = cobj->lengthA;
            lua_pushnumber(tolua_S, (lua_Number)ret);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2PulleyJointDef:Get_lengthA", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2PulleyJointDef_Get_lengthA'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2PulleyJointDef_Set_lengthA(lua_State *tolua_S)
{
    int argc = 0;
    b2PulleyJointDef *cobj = nullptr;
    bool ok = true;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2PulleyJointDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2PulleyJointDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2PulleyJointDef_Set_lengthA'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (1 == argc)
        {
            double lengthA;
            ok&=luaval_to_number(tolua_S, 2, &lengthA);
            if(!ok)
            {
                tolua_error(tolua_S,"invalid arguments in function 'tolua_LuaBox2D_b2PulleyJointDef_Set_lengthA'", nullptr);
                return 0;
            }
            cobj->lengthA = lengthA;
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2PulleyJointDef:Set_lengthA", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2PulleyJointDef_Set_lengthA'.", &tolua_err);
    return 0;
#endif
}


int tolua_LuaBox2D_b2PulleyJointDef_Get_lengthB(lua_State *tolua_S)
{
    int argc = 0;
    b2PulleyJointDef *cobj = nullptr;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2PulleyJointDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2PulleyJointDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2PulleyJointDef_Get_lengthB'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (0 == argc)
        {
            float32 ret = cobj->lengthB;
            lua_pushnumber(tolua_S, (lua_Number)ret);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2PulleyJointDef:Get_lengthB", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2PulleyJointDef_Get_lengthB'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2PulleyJointDef_Set_lengthB(lua_State *tolua_S)
{
    int argc = 0;
    b2PulleyJointDef *cobj = nullptr;
    bool ok = true;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2PulleyJointDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2PulleyJointDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2PulleyJointDef_Set_lengthB'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (1 == argc)
        {
            double lengthB;
            ok&=luaval_to_number(tolua_S, 2, &lengthB);
            if(!ok)
            {
                tolua_error(tolua_S,"invalid arguments in function 'tolua_LuaBox2D_b2PulleyJointDef_Set_lengthB'", nullptr);
                return 0;
            }
            cobj->lengthB = lengthB;
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2PulleyJointDef:Set_lengthB", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2PulleyJointDef_Set_lengthB'.", &tolua_err);
    return 0;
#endif
}


int tolua_LuaBox2D_b2PulleyJointDef_Get_ratio(lua_State *tolua_S)
{
    int argc = 0;
    b2PulleyJointDef *cobj = nullptr;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2PulleyJointDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2PulleyJointDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2PulleyJointDef_Get_ratio'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (0 == argc)
        {
            float32 ret = cobj->ratio;
            lua_pushnumber(tolua_S, (lua_Number)ret);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2PulleyJointDef:Get_ratio", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2PulleyJointDef_Get_ratio'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2PulleyJointDef_Set_ratio(lua_State *tolua_S)
{
    int argc = 0;
    b2PulleyJointDef *cobj = nullptr;
    bool ok = true;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2PulleyJointDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2PulleyJointDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2PulleyJointDef_Set_ratio'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (1 == argc)
        {
            double ratio;
            ok&=luaval_to_number(tolua_S, 2, &ratio);
            if(!ok)
            {
                tolua_error(tolua_S,"invalid arguments in function 'tolua_LuaBox2D_b2PulleyJointDef_Set_ratio'", nullptr);
                return 0;
            }
            cobj->ratio = ratio;
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2PulleyJointDef:Set_ratio", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2PulleyJointDef_Set_ratio'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2PulleyJoint_GetAnchorA(lua_State *tolua_S)
{
    int argc = 0;
    b2PulleyJoint *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2PulleyJoint", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2PulleyJoint *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2PulleyJoint_GetAnchorA'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (0 == argc)
        {
            b2Vec2 newVec = cobj->GetAnchorA();
            // object_to_luaval<b2Vec2>(tolua_S, "b2Vec2", &ret);
            b2Vec2 *ret = new b2Vec2(newVec.x, newVec.y);
            object_to_luaval(tolua_S, "b2Vec2", (b2Vec2 *)ret);
            tolua_register_gc(tolua_S, lua_gettop(tolua_S));
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2PulleyJoint:GetAnchorA", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2PulleyJoint_GetAnchorA'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2PulleyJoint_GetAnchorB(lua_State *tolua_S)
{
    int argc = 0;
    b2PulleyJoint *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2PulleyJoint", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2PulleyJoint *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2PulleyJoint_GetAnchorB'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (0 == argc)
        {
            b2Vec2 newVec = cobj->GetAnchorB();
            // object_to_luaval<b2Vec2>(tolua_S, "b2Vec2", &ret);
            b2Vec2 *ret = new b2Vec2(newVec.x, newVec.y);
            object_to_luaval(tolua_S, "b2Vec2", (b2Vec2 *)ret);
            tolua_register_gc(tolua_S, lua_gettop(tolua_S));
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2PulleyJoint:GetAnchorB", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2PulleyJoint_GetAnchorB'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2PulleyJoint_GetReactionForce(lua_State *tolua_S)
{
    int argc = 0;
    b2PulleyJoint *cobj = nullptr;
    bool ok = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2PulleyJoint", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2PulleyJoint *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2PulleyJoint_GetReactionForce'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (1 == argc)
        {
            int arg0;
            ok &= luaval_to_int32(tolua_S, 2, &arg0, "b2FrictionJoint:GetReactionForce");
            if(!ok)
            {
                tolua_error(tolua_S,"invalid arguments in function 'tolua_LuaBox2D_b2PulleyJoint_GetReactionForce'", nullptr);
                return 0;
            }
            b2Vec2 newVec = cobj->GetReactionForce(arg0);
            // object_to_luaval<b2Vec2>(tolua_S, "b2Vec2", &ret);
            b2Vec2 *ret = new b2Vec2(newVec.x, newVec.y);
            object_to_luaval(tolua_S, "b2Vec2", (b2Vec2 *)ret);
            tolua_register_gc(tolua_S, lua_gettop(tolua_S));
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2PulleyJoint:GetReactionForce", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2PulleyJoint_GetReactionForce'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2PulleyJoint_GetReactionTorque(lua_State *tolua_S)
{
    int argc = 0;
    b2PulleyJoint *cobj = nullptr;
    bool ok = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2PulleyJoint", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2PulleyJoint *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2PulleyJoint_GetReactionTorque'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (1 == argc)
        {
            double arg0;
            ok &= luaval_to_number(tolua_S, 2, &arg0, "b2PulleyJoint:GetReactionTorque");
            if(!ok)
            {
                tolua_error(tolua_S,"invalid arguments in function 'tolua_LuaBox2D_b2PulleyJoint_GetReactionTorque'", nullptr);
                return 0;
            }
            float32 ret = cobj->GetReactionTorque((float)arg0);
            tolua_pushnumber(tolua_S, (lua_Number)ret);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2PulleyJoint:GetReactionTorque", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2PulleyJoint_GetReactionTorque'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2PulleyJoint_GetGroundAnchorA(lua_State *tolua_S)
{
    int argc = 0;
    b2PulleyJoint *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2PulleyJoint", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2PulleyJoint *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2PulleyJoint_GetGroundAnchorA'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (0 == argc)
        {
            b2Vec2 newVec = cobj->GetGroundAnchorA();
            // object_to_luaval<b2Vec2>(tolua_S, "b2Vec2", &ret);
            b2Vec2 *ret = new b2Vec2(newVec.x, newVec.y);
            object_to_luaval(tolua_S, "b2Vec2", (b2Vec2 *)ret);
            tolua_register_gc(tolua_S, lua_gettop(tolua_S));
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2PulleyJoint:GetGroundAnchorA", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2PulleyJoint_GetGroundAnchorA'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2PulleyJoint_GetGroundAnchorB(lua_State *tolua_S)
{
    int argc = 0;
    b2PulleyJoint *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2PulleyJoint", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2PulleyJoint *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2PulleyJoint_GetGroundAnchorB'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (0 == argc)
        {
            b2Vec2 newVec = cobj->GetGroundAnchorB();
            // object_to_luaval<b2Vec2>(tolua_S, "b2Vec2", &ret);
            b2Vec2 *ret = new b2Vec2(newVec.x, newVec.y);
            object_to_luaval(tolua_S, "b2Vec2", (b2Vec2 *)ret);
            tolua_register_gc(tolua_S, lua_gettop(tolua_S));
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2PulleyJoint:GetGroundAnchorB", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2PulleyJoint_GetGroundAnchorB'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2PulleyJoint_GetLengthA(lua_State *tolua_S)
{
    int argc = 0;
    b2PulleyJoint *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2PulleyJoint", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2PulleyJoint *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2PulleyJoint_GetLengthA'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (0 == argc)
        {
            float32 ret = cobj->GetLengthA();
            lua_pushnumber(tolua_S, (lua_Number)ret);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2PulleyJoint:GetLengthA", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2PulleyJoint_GetLengthA'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2PulleyJoint_GetLengthB(lua_State *tolua_S)
{
    int argc = 0;
    b2PulleyJoint *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2PulleyJoint", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2PulleyJoint *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2PulleyJoint_GetLengthB'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (0 == argc)
        {
            float32 ret = cobj->GetLengthB();
            lua_pushnumber(tolua_S, (lua_Number)ret);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2PulleyJoint:GetLengthB", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2PulleyJoint_GetLengthB'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2PulleyJoint_GetRatio(lua_State *tolua_S)
{
    int argc = 0;
    b2PulleyJoint *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2PulleyJoint", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2PulleyJoint *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2PulleyJoint_GetRatio'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (0 == argc)
        {
            float32 ret = cobj->GetRatio();
            lua_pushnumber(tolua_S, (lua_Number)ret);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2PulleyJoint:GetRatio", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2PulleyJoint_GetRatio'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2PulleyJoint_Dump(lua_State *tolua_S)
{
    int argc = 0;
    b2PulleyJoint *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2PulleyJoint", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2PulleyJoint *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2PulleyJoint_Dump'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (0 == argc)
        {
            cobj->Dump();
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2PulleyJoint:Dump", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2PulleyJoint_Dump'.", &tolua_err);
    return 0;
#endif
}

int lua_register_cocos2dx_b2PulleyJointDef(lua_State* tolua_S){
    tolua_usertype(tolua_S, "b2PulleyJointDef");
    tolua_cclass(tolua_S, "b2PulleyJointDef", "b2PulleyJointDef", "b2JointDef", nullptr);
    tolua_beginmodule(tolua_S, "b2PulleyJointDef");
    tolua_function(tolua_S, "new", tolua_LuaBox2D_b2PulleyJointDef_new00_local);
    tolua_function(tolua_S, "new_local", tolua_LuaBox2D_b2PulleyJointDef_new00_local);
    tolua_function(tolua_S, ".call", tolua_LuaBox2D_b2PulleyJointDef_new00_local);
    tolua_function(tolua_S, "Initialize", tolua_LuaBox2D_b2PulleyJointDef_Initialize);
    tolua_variable(tolua_S, "groundAnchorA", tolua_LuaBox2D_b2PulleyJointDef_Get_groundAnchorA,tolua_LuaBox2D_b2PulleyJointDef_Set_groundAnchorA);
    tolua_variable(tolua_S, "groundAnchorB", tolua_LuaBox2D_b2PulleyJointDef_Get_groundAnchorB,tolua_LuaBox2D_b2PulleyJointDef_Set_groundAnchorB);
    tolua_variable(tolua_S, "localAnchorA", tolua_LuaBox2D_b2PulleyJointDef_Get_localAnchorA,tolua_LuaBox2D_b2PulleyJointDef_Set_localAnchorA);
    tolua_variable(tolua_S, "localAnchorB", tolua_LuaBox2D_b2PulleyJointDef_Get_localAnchorB,tolua_LuaBox2D_b2PulleyJointDef_Set_localAnchorB);
    tolua_variable(tolua_S, "lengthA", tolua_LuaBox2D_b2PulleyJointDef_Get_lengthA,tolua_LuaBox2D_b2PulleyJointDef_Set_lengthA);
    tolua_variable(tolua_S, "lengthB", tolua_LuaBox2D_b2PulleyJointDef_Get_lengthB,tolua_LuaBox2D_b2PulleyJointDef_Set_lengthB);
    tolua_variable(tolua_S, "ratio", tolua_LuaBox2D_b2PulleyJointDef_Get_ratio,tolua_LuaBox2D_b2PulleyJointDef_Set_ratio);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(b2PulleyJointDef).name();
    g_luaType[typeName] = "b2PulleyJointDef";
    g_typeCast["b2PulleyJointDef"] = "b2PulleyJointDef";
    return 1;
}

int lua_register_cocos2dx_b2PulleyJoint(lua_State* tolua_S){
    tolua_usertype(tolua_S, "b2PulleyJoint");
    tolua_cclass(tolua_S, "b2PulleyJoint", "b2PulleyJoint", "b2Joint", nullptr);
    tolua_beginmodule(tolua_S, "b2PulleyJoint");
    tolua_function(tolua_S, "GetAnchorA", tolua_LuaBox2D_b2PulleyJoint_GetAnchorA);
    tolua_function(tolua_S, "GetAnchorB", tolua_LuaBox2D_b2PulleyJoint_GetAnchorB);
    tolua_function(tolua_S, "GetReactionForce", tolua_LuaBox2D_b2PulleyJoint_GetReactionForce);
    tolua_function(tolua_S, "GetReactionTorque", tolua_LuaBox2D_b2PulleyJoint_GetReactionTorque);
    tolua_function(tolua_S, "GetGroundAnchorA", tolua_LuaBox2D_b2PulleyJoint_GetGroundAnchorA);
    tolua_function(tolua_S, "GetGroundAnchorB", tolua_LuaBox2D_b2PulleyJoint_GetGroundAnchorB);
    tolua_function(tolua_S, "GetLengthA", tolua_LuaBox2D_b2PulleyJoint_GetLengthA);
    tolua_function(tolua_S, "GetLengthB", tolua_LuaBox2D_b2PulleyJoint_GetLengthB);
    tolua_function(tolua_S, "GetRatio", tolua_LuaBox2D_b2PulleyJoint_GetRatio);
    tolua_function(tolua_S, "Dump", tolua_LuaBox2D_b2PulleyJoint_Dump);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(b2PulleyJoint).name();
    g_luaType[typeName] = "b2PulleyJoint";
    g_typeCast["b2PulleyJoint"] = "b2PulleyJoint";
    return 1;
}


int tolua_LuaBox2D_b2RevoluteJointDef_new00_local(lua_State *tolua_S)
{
    int argc = 0;
    b2RevoluteJointDef *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

    cobj = (b2RevoluteJointDef *)tolua_tousertype(tolua_S, 1, 0);
    argc = lua_gettop(tolua_S) - 1;
    do
    {
        if (0 == argc)
        {
            b2RevoluteJointDef* ret = (b2RevoluteJointDef*)  Mtolua_new((b2RevoluteJointDef)());
            object_to_luaval<b2RevoluteJointDef>(tolua_S, "b2RevoluteJointDef", ret);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2RevoluteJointDef:new00_local", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2RevoluteJointDef_new00_local'.", &tolua_err);
    return 0;
#endif
}


int tolua_LuaBox2D_b2RevoluteJointDef_Initialize(lua_State *tolua_S)
{
    int argc = 0;
    b2RevoluteJointDef *cobj = nullptr;
    bool ok = true;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2RevoluteJointDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2RevoluteJointDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2RevoluteJointDef_Initialize'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (3 == argc)
        {
            b2Body* bodyA;
            ok &= luaval_to_object<b2Body>(tolua_S, 2, "b2Body", &bodyA);
            if(!ok)
            {
                tolua_error(tolua_S,"invalid arguments 1 in function 'tolua_LuaBox2D_b2RevoluteJointDef_Initialize'", nullptr);
                return 0;
            }
            b2Body* bodyB;
            ok &= luaval_to_object<b2Body>(tolua_S, 3, "b2Body", &bodyB);
            if(!ok)
            {
                tolua_error(tolua_S,"invalid arguments 2 in function 'tolua_LuaBox2D_b2RevoluteJointDef_Initialize'", nullptr);
                return 0;
            }
            const b2Vec2* anchor;
            ok &= luaval_to_object<const b2Vec2>(tolua_S, 4, "const b2Vec2", &anchor);
            if(!ok)
            {
                tolua_error(tolua_S,"invalid arguments 3 in function 'tolua_LuaBox2D_b2RevoluteJointDef_Initialize'", nullptr);
                return 0;
            }
            cobj->Initialize(bodyA, bodyB, *anchor);
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2RevoluteJointDef:Initialize", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2RevoluteJointDef_Initialize'.", &tolua_err);
    return 0;
#endif
}


int tolua_LuaBox2D_b2RevoluteJointDef_Get_localAnchorA(lua_State *tolua_S)
{
    int argc = 0;
    b2RevoluteJointDef *cobj = nullptr;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2RevoluteJointDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2RevoluteJointDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2RevoluteJointDef_Get_localAnchorA'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (0 == argc)
        {
            b2Vec2 ret = cobj->localAnchorA;
            object_to_luaval(tolua_S, "b2Vec2", &ret);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2RevoluteJointDef:Get_localAnchorA", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2RevoluteJointDef_Get_localAnchorA'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2RevoluteJointDef_Set_localAnchorA(lua_State *tolua_S)
{
    int argc = 0;
    b2RevoluteJointDef *cobj = nullptr;
    bool ok = true;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2RevoluteJointDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2RevoluteJointDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2RevoluteJointDef_Set_localAnchorA'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (1 == argc)
        {
            b2Vec2* localAnchorA;
            ok&=luaval_to_object<b2Vec2>(tolua_S, 2, "b2Vec2", &localAnchorA);
            if(!ok)
            {
                tolua_error(tolua_S,"invalid arguments in function 'tolua_LuaBox2D_b2RevoluteJointDef_Set_localAnchorA'", nullptr);
                return 0;
            }
            cobj->localAnchorA = *localAnchorA;
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2RevoluteJointDef:Set_localAnchorA", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2RevoluteJointDef_Set_localAnchorA'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2RevoluteJointDef_Get_localAnchorB(lua_State *tolua_S)
{
    int argc = 0;
    b2RevoluteJointDef *cobj = nullptr;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2RevoluteJointDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2RevoluteJointDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2RevoluteJointDef_Get_localAnchorB'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (0 == argc)
        {
            b2Vec2 ret = cobj->localAnchorB;
            object_to_luaval(tolua_S, "b2Vec2", &ret);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2RevoluteJointDef:Get_localAnchorB", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2RevoluteJointDef_Get_localAnchorB'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2RevoluteJointDef_Set_localAnchorB(lua_State *tolua_S)
{
    int argc = 0;
    b2RevoluteJointDef *cobj = nullptr;
    bool ok = true;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2RevoluteJointDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2RevoluteJointDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2RevoluteJointDef_Set_localAnchorB'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (1 == argc)
        {
            b2Vec2* localAnchorB;
            ok&=luaval_to_object<b2Vec2>(tolua_S, 2, "b2Vec2", &localAnchorB);
            if(!ok)
            {
                tolua_error(tolua_S,"invalid arguments in function 'tolua_LuaBox2D_b2RevoluteJointDef_Set_localAnchorB'", nullptr);
                return 0;
            }
            cobj->localAnchorB = *localAnchorB;
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2RevoluteJointDef:Set_localAnchorB", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2RevoluteJointDef_Set_localAnchorB'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2RevoluteJointDef_Get_referenceAngle(lua_State *tolua_S)
{
    int argc = 0;
    b2RevoluteJointDef *cobj = nullptr;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2RevoluteJointDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2RevoluteJointDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2RevoluteJointDef_Get_referenceAngle'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (0 == argc)
        {
            float32 ret = cobj->referenceAngle;
            lua_pushnumber(tolua_S, (lua_Number)ret);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2RevoluteJointDef:Get_referenceAngle", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2RevoluteJointDef_Get_referenceAngle'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2RevoluteJointDef_Set_referenceAngle(lua_State *tolua_S)
{
    int argc = 0;
    b2RevoluteJointDef *cobj = nullptr;
    bool ok = true;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2RevoluteJointDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2RevoluteJointDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2RevoluteJointDef_Set_referenceAngle'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (1 == argc)
        {
            double referenceAngle;
            ok&=luaval_to_number(tolua_S, 2, &referenceAngle);
            if(!ok)
            {
                tolua_error(tolua_S,"invalid arguments in function 'tolua_LuaBox2D_b2RevoluteJointDef_Set_referenceAngle'", nullptr);
                return 0;
            }
            cobj->referenceAngle = referenceAngle;
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2RevoluteJointDef:Set_referenceAngle", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2RevoluteJointDef_Set_referenceAngle'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2RevoluteJointDef_Get_enableLimit(lua_State *tolua_S)
{
    int argc = 0;
    b2RevoluteJointDef *cobj = nullptr;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2RevoluteJointDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2RevoluteJointDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2RevoluteJointDef_Get_enableLimit'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (0 == argc)
        {
            bool ret = cobj->enableLimit;
            lua_pushboolean(tolua_S, ret);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2RevoluteJointDef:Get_enableLimit", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2RevoluteJointDef_Get_enableLimit'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2RevoluteJointDef_Set_enableLimit(lua_State *tolua_S)
{
    int argc = 0;
    b2RevoluteJointDef *cobj = nullptr;
    bool ok = true;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2RevoluteJointDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2RevoluteJointDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2RevoluteJointDef_Set_enableLimit'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (1 == argc)
        {
            bool enableLimit;
            ok&=luaval_to_boolean(tolua_S, 2, &enableLimit);
            if(!ok)
            {
                tolua_error(tolua_S,"invalid arguments in function 'tolua_LuaBox2D_b2RevoluteJointDef_Set_enableLimit'", nullptr);
                return 0;
            }
            cobj->enableLimit = enableLimit;
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2RevoluteJointDef:Set_enableLimit", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2RevoluteJointDef_Set_enableLimit'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2RevoluteJointDef_Get_lowerAngle(lua_State *tolua_S)
{
    int argc = 0;
    b2RevoluteJointDef *cobj = nullptr;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2RevoluteJointDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2RevoluteJointDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2RevoluteJointDef_Get_lowerAngle'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (0 == argc)
        {
            float32 ret = cobj->lowerAngle;
            lua_pushnumber(tolua_S, (lua_Number)ret);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2RevoluteJointDef:Get_lowerAngle", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2RevoluteJointDef_Get_lowerAngle'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2RevoluteJointDef_Set_lowerAngle(lua_State *tolua_S)
{
    int argc = 0;
    b2RevoluteJointDef *cobj = nullptr;
    bool ok = true;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2RevoluteJointDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2RevoluteJointDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2RevoluteJointDef_Set_lowerAngle'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (1 == argc)
        {
            double lowerAngle;
            ok&=luaval_to_number(tolua_S, 2, &lowerAngle);
            if(!ok)
            {
                tolua_error(tolua_S,"invalid arguments in function 'tolua_LuaBox2D_b2RevoluteJointDef_Set_lowerAngle'", nullptr);
                return 0;
            }
            cobj->lowerAngle = lowerAngle;
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2RevoluteJointDef:Set_lowerAngle", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2RevoluteJointDef_Set_lowerAngle'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2RevoluteJointDef_Get_upperAngle(lua_State *tolua_S)
{
    int argc = 0;
    b2RevoluteJointDef *cobj = nullptr;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2RevoluteJointDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2RevoluteJointDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2RevoluteJointDef_Get_upperAngle'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (0 == argc)
        {
            float32 ret = cobj->upperAngle;
            lua_pushnumber(tolua_S, (lua_Number)ret);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2RevoluteJointDef:Get_upperAngle", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2RevoluteJointDef_Get_upperAngle'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2RevoluteJointDef_Set_upperAngle(lua_State *tolua_S)
{
    int argc = 0;
    b2RevoluteJointDef *cobj = nullptr;
    bool ok = true;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2RevoluteJointDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2RevoluteJointDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2RevoluteJointDef_Set_upperAngle'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (1 == argc)
        {
            double upperAngle;
            ok&=luaval_to_number(tolua_S, 2, &upperAngle);
            if(!ok)
            {
                tolua_error(tolua_S,"invalid arguments in function 'tolua_LuaBox2D_b2RevoluteJointDef_Set_upperAngle'", nullptr);
                return 0;
            }
            cobj->upperAngle = upperAngle;
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2RevoluteJointDef:Set_upperAngle", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2RevoluteJointDef_Set_upperAngle'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2RevoluteJointDef_Get_enableMotor(lua_State *tolua_S)
{
    int argc = 0;
    b2RevoluteJointDef *cobj = nullptr;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2RevoluteJointDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2RevoluteJointDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2RevoluteJointDef_Get_enableMotor'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (0 == argc)
        {
            bool ret = cobj->enableMotor;
            lua_pushboolean(tolua_S, ret);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2RevoluteJointDef:Get_enableMotor", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2RevoluteJointDef_Get_enableMotor'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2RevoluteJointDef_Set_enableMotor(lua_State *tolua_S)
{
    int argc = 0;
    b2RevoluteJointDef *cobj = nullptr;
    bool ok = true;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2RevoluteJointDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2RevoluteJointDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2RevoluteJointDef_Set_enableMotor'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (1 == argc)
        {
            bool enableMotor;
            ok&=luaval_to_boolean(tolua_S, 2, &enableMotor);
            if(!ok)
            {
                tolua_error(tolua_S,"invalid arguments in function 'tolua_LuaBox2D_b2RevoluteJointDef_Set_enableMotor'", nullptr);
                return 0;
            }
            cobj->enableMotor = enableMotor;
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2RevoluteJointDef:Set_enableMotor", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2RevoluteJointDef_Set_enableMotor'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2RevoluteJointDef_Get_motorSpeed(lua_State *tolua_S)
{
    int argc = 0;
    b2RevoluteJointDef *cobj = nullptr;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2RevoluteJointDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2RevoluteJointDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2RevoluteJointDef_Get_motorSpeed'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (0 == argc)
        {
            float32 ret = cobj->motorSpeed;
            lua_pushnumber(tolua_S, (lua_Number)ret);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2RevoluteJointDef:Get_motorSpeed", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2RevoluteJointDef_Get_motorSpeed'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2RevoluteJointDef_Set_motorSpeed(lua_State *tolua_S)
{
    int argc = 0;
    b2RevoluteJointDef *cobj = nullptr;
    bool ok = true;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2RevoluteJointDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2RevoluteJointDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2RevoluteJointDef_Set_motorSpeed'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (1 == argc)
        {
            double motorSpeed;
            ok&=luaval_to_number(tolua_S, 2, &motorSpeed);
            if(!ok)
            {
                tolua_error(tolua_S,"invalid arguments in function 'tolua_LuaBox2D_b2RevoluteJointDef_Set_motorSpeed'", nullptr);
                return 0;
            }
            cobj->motorSpeed = motorSpeed;
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2RevoluteJointDef:Set_motorSpeed", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2RevoluteJointDef_Set_motorSpeed'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2RevoluteJointDef_Get_maxMotorTorque(lua_State *tolua_S)
{
    int argc = 0;
    b2RevoluteJointDef *cobj = nullptr;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2RevoluteJointDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2RevoluteJointDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2RevoluteJointDef_Get_maxMotorTorque'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (0 == argc)
        {
            float32 ret = cobj->maxMotorTorque;
            lua_pushnumber(tolua_S, (lua_Number)ret);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2RevoluteJointDef:Get_maxMotorTorque", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2RevoluteJointDef_Get_maxMotorTorque'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2RevoluteJointDef_Set_maxMotorTorque(lua_State *tolua_S)
{
    int argc = 0;
    b2RevoluteJointDef *cobj = nullptr;
    bool ok = true;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2RevoluteJointDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2RevoluteJointDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2RevoluteJointDef_Set_maxMotorTorque'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (1 == argc)
        {
            double maxMotorTorque;
            ok&=luaval_to_number(tolua_S, 2, &maxMotorTorque);
            if(!ok)
            {
                tolua_error(tolua_S,"invalid arguments in function 'tolua_LuaBox2D_b2RevoluteJointDef_Set_maxMotorTorque'", nullptr);
                return 0;
            }
            cobj->maxMotorTorque = maxMotorTorque;
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2RevoluteJointDef:Set_maxMotorTorque", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2RevoluteJointDef_Set_maxMotorTorque'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2RevoluteJoint_GetAnchorA(lua_State *tolua_S)
{
    int argc = 0;
    b2RevoluteJoint *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2RevoluteJoint", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2RevoluteJoint *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2RevoluteJoint_GetAnchorA'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (0 == argc)
        {
            b2Vec2 newVec = cobj->GetAnchorA();
            // object_to_luaval<b2Vec2>(tolua_S, "b2Vec2", &ret);
            b2Vec2 *ret = new b2Vec2(newVec.x, newVec.y);
            object_to_luaval(tolua_S, "b2Vec2", (b2Vec2 *)ret);
            tolua_register_gc(tolua_S, lua_gettop(tolua_S));
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2RevoluteJoint:GetAnchorA", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2RevoluteJoint_GetAnchorA'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2RevoluteJoint_GetAnchorB(lua_State *tolua_S)
{
    int argc = 0;
    b2RevoluteJoint *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2RevoluteJoint", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2RevoluteJoint *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2RevoluteJoint_GetAnchorB'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (0 == argc)
        {
            b2Vec2 newVec = cobj->GetAnchorB();
            // object_to_luaval<b2Vec2>(tolua_S, "b2Vec2", &ret);
            b2Vec2 *ret = new b2Vec2(newVec.x, newVec.y);
            object_to_luaval(tolua_S, "b2Vec2", (b2Vec2 *)ret);
            tolua_register_gc(tolua_S, lua_gettop(tolua_S));
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2RevoluteJoint:GetAnchorB", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2RevoluteJoint_GetAnchorB'.", &tolua_err);
    return 0;
#endif
}


int tolua_LuaBox2D_b2RevoluteJoint_GetLocalAnchorA(lua_State *tolua_S)
{
    int argc = 0;
    b2RevoluteJoint *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2RevoluteJoint", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2RevoluteJoint *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2RevoluteJoint_GetLocalAnchorA'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (0 == argc)
        {
            b2Vec2 newVec = cobj->GetLocalAnchorA();
            // object_to_luaval<b2Vec2>(tolua_S, "b2Vec2", &ret);
            b2Vec2 *ret = new b2Vec2(newVec.x, newVec.y);
            object_to_luaval(tolua_S, "b2Vec2", (b2Vec2 *)ret);
            tolua_register_gc(tolua_S, lua_gettop(tolua_S));
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2RevoluteJoint:GetLocalAnchorA", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2RevoluteJoint_GetLocalAnchorA'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2RevoluteJoint_GetLocalAnchorB(lua_State *tolua_S)
{
    int argc = 0;
    b2RevoluteJoint *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2RevoluteJoint", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2RevoluteJoint *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2RevoluteJoint_GetLocalAnchorB'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (0 == argc)
        {
            b2Vec2 newVec = cobj->GetLocalAnchorB();
            // object_to_luaval<b2Vec2>(tolua_S, "b2Vec2", &ret);
            b2Vec2 *ret = new b2Vec2(newVec.x, newVec.y);
            object_to_luaval(tolua_S, "b2Vec2", (b2Vec2 *)ret);
            tolua_register_gc(tolua_S, lua_gettop(tolua_S));
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2RevoluteJoint:GetLocalAnchorB", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2RevoluteJoint_GetLocalAnchorB'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2RevoluteJoint_GetReferenceAngle(lua_State *tolua_S)
{
    int argc = 0;
    b2RevoluteJoint *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2RevoluteJoint", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2RevoluteJoint *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2RevoluteJoint_GetReferenceAngle'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (0 == argc)
        {
            float32 ret = cobj->GetReferenceAngle();
            tolua_pushnumber(tolua_S, (lua_Number)ret);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2RevoluteJoint:GetReferenceAngle", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2RevoluteJoint_GetReferenceAngle'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2RevoluteJoint_GetJointAngle(lua_State *tolua_S)
{
    int argc = 0;
    b2RevoluteJoint *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2RevoluteJoint", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2RevoluteJoint *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2RevoluteJoint_GetJointAngle'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (0 == argc)
        {
            float32 ret = cobj->GetJointAngle();
            tolua_pushnumber(tolua_S, (lua_Number)ret);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2RevoluteJoint:GetJointAngle", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2RevoluteJoint_GetJointAngle'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2RevoluteJoint_GetJointSpeed(lua_State *tolua_S)
{
    int argc = 0;
    b2RevoluteJoint *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2RevoluteJoint", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2RevoluteJoint *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2RevoluteJoint_GetJointSpeed'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (0 == argc)
        {
            float32 ret = cobj->GetJointSpeed();
            tolua_pushnumber(tolua_S, (lua_Number)ret);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2RevoluteJoint:GetJointSpeed", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2RevoluteJoint_GetJointSpeed'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2RevoluteJoint_IsLimitEnabled(lua_State *tolua_S)
{
    int argc = 0;
    b2RevoluteJoint *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2RevoluteJoint", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2RevoluteJoint *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2RevoluteJoint_IsLimitEnabled'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (0 == argc)
        {
            bool ret = cobj->IsLimitEnabled();
            tolua_pushboolean(tolua_S, ret);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2RevoluteJoint:IsLimitEnabled", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2RevoluteJoint_IsLimitEnabled'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2RevoluteJoint_EnableLimit(lua_State *tolua_S)
{
    int argc = 0;
    b2RevoluteJoint *cobj = nullptr;
    bool ok = true;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2RevoluteJoint", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2RevoluteJoint *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2RevoluteJoint_EnableLimit'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (1 == argc)
        {
            bool enableLimit;
            ok&=luaval_to_boolean(tolua_S, 2, &enableLimit);
            if(!ok){
                tolua_error(tolua_S, "invalid arguments 2 in function 'tolua_LuaBox2D_b2RevoluteJoint_EnableLimit', was expecting bool", nullptr);
                return 0;
            }
            cobj->EnableLimit(enableLimit);
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2RevoluteJoint:EnableLimit", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2RevoluteJoint_EnableLimit'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2RevoluteJoint_GetUpperLimit(lua_State *tolua_S)
{
    int argc = 0;
    b2RevoluteJoint *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2RevoluteJoint", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2RevoluteJoint *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2RevoluteJoint_GetUpperLimit'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (0 == argc)
        {
            float32 ret = cobj->GetUpperLimit();
            tolua_pushnumber(tolua_S, (lua_Number)ret);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2RevoluteJoint:GetUpperLimit", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2RevoluteJoint_GetUpperLimit'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2RevoluteJoint_GetLowerLimit(lua_State *tolua_S)
{
    int argc = 0;
    b2RevoluteJoint *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

    cobj = (b2RevoluteJoint *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2RevoluteJoint_GetLowerLimit'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (0 == argc)
        {
            float32 ret = cobj->GetLowerLimit();
            tolua_pushnumber(tolua_S, (lua_Number)ret);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2RevoluteJoint:GetLowerLimit", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2RevoluteJoint_GetLowerLimit'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2RevoluteJoint_SetLimits(lua_State *tolua_S)
{
    int argc = 0;
    b2RevoluteJoint *cobj = nullptr;
    bool ok = true;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2RevoluteJoint", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2RevoluteJoint *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2RevoluteJoint_SetLimits'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (2 == argc)
        {
            double lower;
            double upper;
            ok&=luaval_to_number(tolua_S, 2, &lower);
            ok&=luaval_to_number(tolua_S, 3, &upper);
            if(!ok)
            {
                tolua_error(tolua_S,"invalid arguments in function 'tolua_LuaBox2D_b2RevoluteJoint_SetLimits'", nullptr);
                return 0;
            }
            cobj->SetLimits(lower, upper);
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2RevoluteJoint:SetLimits", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2RevoluteJoint_SetLimits'.", &tolua_err);
    return 0;
#endif
}


int tolua_LuaBox2D_b2RevoluteJoint_IsMotorEnabled(lua_State *tolua_S)
{
    int argc = 0;
    b2RevoluteJoint *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2RevoluteJoint", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2RevoluteJoint *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2RevoluteJoint_IsMotorEnabled'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (0 == argc)
        {
            bool ret = cobj->IsMotorEnabled();
            tolua_pushboolean(tolua_S, ret);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2RevoluteJoint:IsMotorEnabled", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2RevoluteJoint_IsMotorEnabled'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2RevoluteJoint_EnableMotor(lua_State *tolua_S)
{
    int argc = 0;
    b2RevoluteJoint *cobj = nullptr;
    bool ok = true;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2RevoluteJoint", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2RevoluteJoint *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2RevoluteJoint_EnableMotor'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (1 == argc)
        {
            bool EnableMotor;
            ok&=luaval_to_boolean(tolua_S, 2, &EnableMotor);
            if(!ok)
            {
                tolua_error(tolua_S,"invalid arguments in function 'tolua_LuaBox2D_b2RevoluteJoint_EnableMotor'", nullptr);
                return 0;
            }
            cobj->EnableMotor(EnableMotor);
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2RevoluteJoint:EnableMotor", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2RevoluteJoint_EnableMotor'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2RevoluteJoint_SetMotorSpeed(lua_State *tolua_S)
{
    int argc = 0;
    b2RevoluteJoint *cobj = nullptr;
    bool ok = true;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2RevoluteJoint", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2RevoluteJoint *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2RevoluteJoint_SetMotorSpeed'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (1 == argc)
        {
            double motorSpeed;
            ok&=luaval_to_number(tolua_S, 2, &motorSpeed);
            if(!ok)
            {
                tolua_error(tolua_S,"invalid arguments in function 'tolua_LuaBox2D_b2RevoluteJoint_SetMotorSpeed'", nullptr);
                return 0;
            }
            cobj->SetMotorSpeed(motorSpeed);
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2RevoluteJoint:SetMotorSpeed", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2RevoluteJoint_SetMotorSpeed'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2RevoluteJoint_GetMotorSpeed(lua_State *tolua_S)
{
    int argc = 0;
    b2RevoluteJoint *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2RevoluteJoint", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2RevoluteJoint *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2RevoluteJoint_GetMotorSpeed'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (0 == argc)
        {
            float32 ret = cobj->GetMotorSpeed();
            tolua_pushnumber(tolua_S, (lua_Number)ret);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2RevoluteJoint:GetMotorSpeed", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2RevoluteJoint_GetMotorSpeed'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2RevoluteJoint_SetMaxMotorTorque(lua_State *tolua_S)
{
    int argc = 0;
    b2RevoluteJoint *cobj = nullptr;
    bool ok = true;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2RevoluteJoint", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2RevoluteJoint *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2RevoluteJoint_SetMaxMotorTorque'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (1 == argc)
        {
            double MaxMotorTorque;
            ok&=luaval_to_number(tolua_S, 2, &MaxMotorTorque);
            if(!ok)
            {
                tolua_error(tolua_S,"invalid arguments in function 'tolua_LuaBox2D_b2RevoluteJoint_SetMaxMotorTorque'", nullptr);
                return 0;
            }
            cobj->SetMaxMotorTorque(MaxMotorTorque);
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2RevoluteJoint:SetMaxMotorTorque", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2RevoluteJoint_SetMaxMotorTorque'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2RevoluteJoint_GetMaxMotorTorque(lua_State *tolua_S)
{
    int argc = 0;
    b2RevoluteJoint *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2RevoluteJoint", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2RevoluteJoint *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2RevoluteJoint_GetMaxMotorTorque'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (0 == argc)
        {
            float32 ret = cobj->GetMaxMotorTorque();
            tolua_pushnumber(tolua_S, (lua_Number)ret);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2RevoluteJoint:GetMaxMotorTorque", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2RevoluteJoint_GetMaxMotorTorque'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2RevoluteJoint_GetReactionForce(lua_State *tolua_S)
{
    int argc = 0;
    b2RevoluteJoint *cobj = nullptr;
    bool ok = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2RevoluteJoint", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2RevoluteJoint *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2RevoluteJoint_GetReactionForce'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (1 == argc)
        {
            int arg0;
            ok &= luaval_to_int32(tolua_S, 2, &arg0, "b2RevoluteJoint:GetReactionForce");
            
            if(!ok)
            {
                tolua_error(tolua_S,"invalid arguments in function 'tolua_LuaBox2D_b2RevoluteJoint_GetReactionForce'", nullptr);
                return 0;
            }
            b2Vec2 newVec = cobj->GetReactionForce(arg0);
            // object_to_luaval<b2Vec2>(tolua_S, "b2Vec2", &ret);
            b2Vec2 *ret = new b2Vec2(newVec.x, newVec.y);
            object_to_luaval(tolua_S, "b2Vec2", (b2Vec2 *)ret);
            tolua_register_gc(tolua_S, lua_gettop(tolua_S));
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2RevoluteJoint:GetReactionForce", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2RevoluteJoint_GetReactionForce'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2RevoluteJoint_GetReactionTorque(lua_State *tolua_S)
{
    int argc = 0;
    b2RevoluteJoint *cobj = nullptr;
    bool ok = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2RevoluteJoint", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2RevoluteJoint *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2RevoluteJoint_GetReactionTorque'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (1 == argc)
        {
            double arg0;
            ok &= luaval_to_number(tolua_S, 2, &arg0, "b2RevoluteJoint:GetReactionTorque");
            if(!ok)
            {
                tolua_error(tolua_S,"invalid arguments in function 'tolua_LuaBox2D_b2RevoluteJoint_GetReactionTorque'", nullptr);
                return 0;
            }
            float32 ret = cobj->GetReactionTorque((float)arg0);
            tolua_pushnumber(tolua_S, (lua_Number)ret);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2RevoluteJoint:GetReactionTorque", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2RevoluteJoint_GetReactionTorque'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2RevoluteJoint_GetMotorTorque(lua_State *tolua_S)
{
    int argc = 0;
    b2RevoluteJoint *cobj = nullptr;
    bool ok = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2RevoluteJoint", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2RevoluteJoint *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2RevoluteJoint_GetMotorTorque'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (1 == argc)
        {
            double arg0;
            ok &= luaval_to_number(tolua_S, 2, &arg0, "b2RevoluteJoint:GetMotorTorque");
            if(!ok)
            {
                tolua_error(tolua_S,"invalid arguments in function 'tolua_LuaBox2D_b2RevoluteJoint_GetMotorTorque'", nullptr);
                return 0;
            }
            float32 ret = cobj->GetMotorTorque((float)arg0);
            tolua_pushnumber(tolua_S, (lua_Number)ret);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2RevoluteJoint:GetMotorTorque", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2RevoluteJoint_GetMotorTorque'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2RevoluteJoint_Dump(lua_State *tolua_S)
{
    int argc = 0;
    b2RevoluteJoint *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2RevoluteJoint", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2RevoluteJoint *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2RevoluteJoint_Dump'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (0 == argc)
        {
            cobj->Dump();
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2RevoluteJoint:Dump", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2RevoluteJoint_Dump'.", &tolua_err);
    return 0;
#endif
}


int lua_register_cocos2dx_b2RevoluteJointDef(lua_State* tolua_S){
    tolua_usertype(tolua_S, "b2RevoluteJointDef");
    tolua_cclass(tolua_S, "b2RevoluteJointDef", "b2RevoluteJointDef", "b2JointDef", nullptr);
    tolua_beginmodule(tolua_S, "b2RevoluteJointDef");
    tolua_function(tolua_S, "new", tolua_LuaBox2D_b2RevoluteJointDef_new00_local);
    tolua_function(tolua_S, "new_local", tolua_LuaBox2D_b2RevoluteJointDef_new00_local);
    tolua_function(tolua_S, ".call", tolua_LuaBox2D_b2RevoluteJointDef_new00_local);
    tolua_function(tolua_S, "Initialize", tolua_LuaBox2D_b2RevoluteJointDef_Initialize);
    tolua_variable(tolua_S, "localAnchorA", tolua_LuaBox2D_b2RevoluteJointDef_Get_localAnchorA,tolua_LuaBox2D_b2RevoluteJointDef_Set_localAnchorA);
    tolua_variable(tolua_S, "localAnchorB", tolua_LuaBox2D_b2RevoluteJointDef_Get_localAnchorB,tolua_LuaBox2D_b2RevoluteJointDef_Set_localAnchorB);
    tolua_variable(tolua_S, "referenceAngle", tolua_LuaBox2D_b2RevoluteJointDef_Get_referenceAngle,tolua_LuaBox2D_b2RevoluteJointDef_Set_referenceAngle);
    tolua_variable(tolua_S, "enableLimit", tolua_LuaBox2D_b2RevoluteJointDef_Get_enableLimit,tolua_LuaBox2D_b2RevoluteJointDef_Set_enableLimit);
    tolua_variable(tolua_S, "lowerAngle", tolua_LuaBox2D_b2RevoluteJointDef_Get_lowerAngle,tolua_LuaBox2D_b2RevoluteJointDef_Set_lowerAngle);
    tolua_variable(tolua_S, "upperAngle", tolua_LuaBox2D_b2RevoluteJointDef_Get_upperAngle,tolua_LuaBox2D_b2RevoluteJointDef_Set_upperAngle);
    tolua_variable(tolua_S, "enableMotor", tolua_LuaBox2D_b2RevoluteJointDef_Get_enableMotor,tolua_LuaBox2D_b2RevoluteJointDef_Set_enableMotor);
    tolua_variable(tolua_S, "motorSpeed", tolua_LuaBox2D_b2RevoluteJointDef_Get_motorSpeed,tolua_LuaBox2D_b2RevoluteJointDef_Set_motorSpeed);
    tolua_variable(tolua_S, "maxMotorTorque", tolua_LuaBox2D_b2RevoluteJointDef_Get_maxMotorTorque,tolua_LuaBox2D_b2RevoluteJointDef_Set_maxMotorTorque);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(b2RevoluteJointDef).name();
    g_luaType[typeName] = "b2RevoluteJointDef";
    g_typeCast["b2RevoluteJointDef"] = "b2RevoluteJointDef";
    return 1;
}

int lua_register_cocos2dx_b2RevoluteJoint(lua_State* tolua_S){
    tolua_usertype(tolua_S, "b2RevoluteJoint");
    tolua_cclass(tolua_S, "b2RevoluteJoint", "b2RevoluteJoint", "b2Joint", nullptr);
    tolua_beginmodule(tolua_S, "b2RevoluteJoint");
    tolua_function(tolua_S, "GetAnchorA", tolua_LuaBox2D_b2RevoluteJoint_GetAnchorA);
    tolua_function(tolua_S, "GetAnchorB", tolua_LuaBox2D_b2RevoluteJoint_GetAnchorB);
    tolua_function(tolua_S, "GetLocalAnchorA", tolua_LuaBox2D_b2RevoluteJoint_GetLocalAnchorA);
    tolua_function(tolua_S, "GetLocalAnchorB", tolua_LuaBox2D_b2RevoluteJoint_GetLocalAnchorB);
    tolua_function(tolua_S, "GetReferenceAngle", tolua_LuaBox2D_b2RevoluteJoint_GetReferenceAngle);
    tolua_function(tolua_S, "GetJointAngle", tolua_LuaBox2D_b2RevoluteJoint_GetJointAngle);
    tolua_function(tolua_S, "GetJointSpeed", tolua_LuaBox2D_b2RevoluteJoint_GetJointSpeed);
    tolua_function(tolua_S, "IsLimitEnabled", tolua_LuaBox2D_b2RevoluteJoint_IsLimitEnabled);
    tolua_function(tolua_S, "EnableLimit", tolua_LuaBox2D_b2RevoluteJoint_EnableLimit);
    tolua_function(tolua_S, "GetUpperLimit", tolua_LuaBox2D_b2RevoluteJoint_GetUpperLimit);
    tolua_function(tolua_S, "GetLowerLimit", tolua_LuaBox2D_b2RevoluteJoint_GetLowerLimit);
    tolua_function(tolua_S, "SetLimits", tolua_LuaBox2D_b2RevoluteJoint_SetLimits);
    tolua_function(tolua_S, "IsMotorEnabled", tolua_LuaBox2D_b2RevoluteJoint_IsMotorEnabled);
    tolua_function(tolua_S, "EnableMotor", tolua_LuaBox2D_b2RevoluteJoint_EnableMotor);
    tolua_function(tolua_S, "SetMotorSpeed", tolua_LuaBox2D_b2RevoluteJoint_SetMotorSpeed);
    tolua_function(tolua_S, "GetMotorSpeed", tolua_LuaBox2D_b2RevoluteJoint_GetMotorSpeed);
    tolua_function(tolua_S, "SetMaxMotorTorque", tolua_LuaBox2D_b2RevoluteJoint_SetMaxMotorTorque);
    tolua_function(tolua_S, "GetMaxMotorTorque", tolua_LuaBox2D_b2RevoluteJoint_GetMaxMotorTorque);
    tolua_function(tolua_S, "GetReactionForce", tolua_LuaBox2D_b2RevoluteJoint_GetReactionForce);
    tolua_function(tolua_S, "GetReactionTorque", tolua_LuaBox2D_b2RevoluteJoint_GetReactionTorque);
    tolua_function(tolua_S, "GetMotorTorque", tolua_LuaBox2D_b2RevoluteJoint_GetMotorTorque);
    tolua_function(tolua_S, "Dump", tolua_LuaBox2D_b2RevoluteJoint_Dump);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(b2RevoluteJoint).name();
    g_luaType[typeName] = "b2RevoluteJoint";
    g_typeCast["b2RevoluteJoint"] = "b2RevoluteJoint";
    return 1;
}

int tolua_LuaBox2D_b2WheelJointDef_new00_local(lua_State *tolua_S)
{
    int argc = 0;
    b2WheelJointDef *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

    cobj = (b2WheelJointDef *)tolua_tousertype(tolua_S, 1, 0);

    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (0 == argc)
        {
            b2WheelJointDef* ret = (b2WheelJointDef*)  Mtolua_new((b2WheelJointDef)());
            object_to_luaval<b2WheelJointDef>(tolua_S, "b2WheelJointDef", ret);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2WheelJointDef:new00_local", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2WheelJointDef_new00_local'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2WheelJointDef_Initialize(lua_State *tolua_S)
{
    int argc = 0;
    b2WheelJointDef *cobj = nullptr;
    bool ok = true;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2WheelJointDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2WheelJointDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2WheelJointDef_Initialize'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (4 == argc)
        {
            b2Body* bodyA;
            ok &= luaval_to_object<b2Body>(tolua_S, 2, "b2Body", &bodyA);
            if(!ok){
                tolua_error(tolua_S,"invalid arguments 1 in function 'tolua_LuaBox2D_b2WheelJointDef_Initialize'", nullptr);
                return 0;
            }
            b2Body* bodyB;
            ok &= luaval_to_object<b2Body>(tolua_S, 3, "b2Body", &bodyB);
            if(!ok){
                tolua_error(tolua_S, "invalid arguments 2 in function 'tolua_LuaBox2D_b2WheelJointDef_Initialize'", nullptr);
                return 0;
            }
            const b2Vec2* anchor;
            ok &= luaval_to_object<const b2Vec2>(tolua_S, 4, "const b2Vec2", &anchor);
            if(!ok){
                tolua_error(tolua_S, "invalid arguments 3 in function 'tolua_LuaBox2D_b2WheelJointDef_Initialize'", nullptr);
                return 0;
            }
            const b2Vec2* axis;
            ok &= luaval_to_object<const b2Vec2>(tolua_S, 5, "const b2Vec2", &axis);
            if(!ok)
            {
                tolua_error(tolua_S,"invalid arguments 4 in function 'tolua_LuaBox2D_b2WheelJointDef_Initialize'", nullptr);
                return 0;
            }
            cobj->Initialize(bodyA, bodyB, *anchor, *axis);
            
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2WheelJointDef:Initialize", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2WheelJointDef_Initialize'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2WheelJointDef_Get_localAnchorA(lua_State *tolua_S)
{
    int argc = 0;
    b2WheelJointDef *cobj = nullptr;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2WheelJointDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2WheelJointDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2WheelJointDef_Get_localAnchorA'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (0 == argc)
        {
            b2Vec2 ret = cobj->localAnchorA;
            object_to_luaval(tolua_S, "b2Vec2", &ret);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2WheelJointDef:Get_localAnchorA", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2WheelJointDef_Get_localAnchorA'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2WheelJointDef_Set_localAnchorA(lua_State *tolua_S)
{
    int argc = 0;
    b2WheelJointDef *cobj = nullptr;
    bool ok = true;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2WheelJointDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2WheelJointDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2WheelJointDef_Set_localAnchorA'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (1 == argc)
        {
            b2Vec2* localAnchorA;
            ok&=luaval_to_object<b2Vec2>(tolua_S, 2, "b2Vec2", &localAnchorA);
            if(!ok)
            {
                tolua_error(tolua_S,"invalid arguments in function 'tolua_LuaBox2D_b2WheelJointDef_Set_localAnchorA'", nullptr);
                return 0;
            }
            cobj->localAnchorA = *localAnchorA;
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2WheelJointDef:Set_localAnchorA", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2WheelJointDef_Set_localAnchorA'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2WheelJointDef_Get_localAnchorB(lua_State *tolua_S)
{
    int argc = 0;
    b2WheelJointDef *cobj = nullptr;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2WheelJointDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2WheelJointDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2WheelJointDef_Get_localAnchorB'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (0 == argc)
        {
            b2Vec2 ret = cobj->localAnchorB;
            object_to_luaval(tolua_S, "b2Vec2", &ret);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2WheelJointDef:Get_localAnchorB", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2WheelJointDef_Get_localAnchorB'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2WheelJointDef_Set_localAnchorB(lua_State *tolua_S)
{
    int argc = 0;
    b2WheelJointDef *cobj = nullptr;
    bool ok = true;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2WheelJointDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2WheelJointDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2WheelJointDef_Set_localAnchorB'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (1 == argc)
        {
            b2Vec2* localAnchorB;
            ok&=luaval_to_object<b2Vec2>(tolua_S, 2, "b2Vec2", &localAnchorB);
            if(!ok)
            {
                tolua_error(tolua_S,"invalid arguments in function 'tolua_LuaBox2D_b2WheelJointDef_Set_localAnchorB'", nullptr);
                return 0;
            }
            cobj->localAnchorB = *localAnchorB;
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2WheelJointDef:Set_localAnchorB", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2WheelJointDef_Set_localAnchorB'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2WheelJointDef_Get_localAxisA(lua_State *tolua_S)
{
    int argc = 0;
    b2WheelJointDef *cobj = nullptr;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2WheelJointDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2WheelJointDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2WheelJointDef_Get_localAxisA'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (0 == argc)
        {
            b2Vec2 ret = cobj->localAxisA;
            object_to_luaval(tolua_S, "b2Vec2", &ret);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2WheelJointDef:Get_localAxisA", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2WheelJointDef_Get_localAxisA'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2WheelJointDef_Set_localAxisA(lua_State *tolua_S)
{
    int argc = 0;
    b2WheelJointDef *cobj = nullptr;
    bool ok = true;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2WheelJointDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2WheelJointDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2WheelJointDef_Set_localAxisA'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (1 == argc)
        {
            b2Vec2* localAxisA;
            ok&=luaval_to_object<b2Vec2>(tolua_S, 2, "b2Vec2", &localAxisA);
            if(!ok)
            {
                tolua_error(tolua_S,"invalid arguments in function 'tolua_LuaBox2D_b2WheelJointDef_Set_localAxisA'", nullptr);
                return 0;
            }
            cobj->localAxisA = *localAxisA;
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2WheelJointDef:Set_localAxisA", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2WheelJointDef_Set_localAxisA'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2WheelJointDef_Get_enableMotor(lua_State *tolua_S)
{
    int argc = 0;
    b2WheelJointDef *cobj = nullptr;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2WheelJointDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2WheelJointDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2WheelJointDef_Get_enableMotor'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (0 == argc)
        {
            bool ret = cobj->enableMotor;
            lua_pushboolean(tolua_S, ret);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2WheelJointDef:Get_enableMotor", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2WheelJointDef_Get_enableMotor'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2WheelJointDef_Set_enableMotor(lua_State *tolua_S)
{
    int argc = 0;
    b2WheelJointDef *cobj = nullptr;
    bool ok = true;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2WheelJointDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2WheelJointDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2WheelJointDef_Set_enableMotor'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (1 == argc)
        {
            bool enableMotor;
            ok&=luaval_to_boolean(tolua_S, 2, &enableMotor);
            if(!ok)
            {
                tolua_error(tolua_S,"invalid arguments in function 'tolua_LuaBox2D_b2WheelJointDef_Set_enableMotor'", nullptr);
                return 0;
            }
            cobj->enableMotor = enableMotor;
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2WheelJointDef:Set_enableMotor", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2WheelJointDef_Set_enableMotor'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2WheelJointDef_Get_maxMotorTorque(lua_State *tolua_S)
{
    int argc = 0;
    b2WheelJointDef *cobj = nullptr;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2WheelJointDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2WheelJointDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2WheelJointDef_Get_maxMotorTorque'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (0 == argc)
        {
            float32 ret = cobj->maxMotorTorque;
            lua_pushnumber(tolua_S, (lua_Number)ret);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2WheelJointDef:Get_maxMotorTorque", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2WheelJointDef_Get_maxMotorTorque'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2WheelJointDef_Set_maxMotorTorque(lua_State *tolua_S)
{
    int argc = 0;
    b2WheelJointDef *cobj = nullptr;
    bool ok = true;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2WheelJointDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2WheelJointDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2WheelJointDef_Set_maxMotorTorque'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (1 == argc)
        {
            double maxMotorTorque;
            ok&=luaval_to_number(tolua_S, 2, &maxMotorTorque);
            if(!ok)
            {
                tolua_error(tolua_S,"invalid arguments in function 'tolua_LuaBox2D_b2WheelJointDef_Set_maxMotorTorque'", nullptr);
                return 0;
            }
            cobj->maxMotorTorque = maxMotorTorque;
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2WheelJointDef:Set_maxMotorTorque", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2WheelJointDef_Set_maxMotorTorque'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2WheelJointDef_Get_motorSpeed(lua_State *tolua_S)
{
    int argc = 0;
    b2WheelJointDef *cobj = nullptr;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2WheelJointDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2WheelJointDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2WheelJointDef_Get_motorSpeed'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (0 == argc)
        {
            float32 ret = cobj->motorSpeed;
            lua_pushnumber(tolua_S, (lua_Number)ret);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2WheelJointDef:Get_motorSpeed", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2WheelJointDef_Get_motorSpeed'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2WheelJointDef_Set_motorSpeed(lua_State *tolua_S)
{
    int argc = 0;
    b2WheelJointDef *cobj = nullptr;
    bool ok = true;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2WheelJointDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2WheelJointDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2WheelJointDef_Set_motorSpeed'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (1 == argc)
        {
            double motorSpeed;
            ok&=luaval_to_number(tolua_S, 2, &motorSpeed);
            if(!ok)
            {
                tolua_error(tolua_S,"invalid arguments in function 'tolua_LuaBox2D_b2WheelJointDef_Set_motorSpeed'", nullptr);
                return 0;
            }
            cobj->motorSpeed = motorSpeed;
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2WheelJointDef:Set_motorSpeed", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2WheelJointDef_Set_motorSpeed'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2WheelJointDef_Get_frequencyHz(lua_State *tolua_S)
{
    int argc = 0;
    b2WheelJointDef *cobj = nullptr;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2WheelJointDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2WheelJointDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2WheelJointDef_Get_frequencyHz'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (0 == argc)
        {
            float32 ret = cobj->frequencyHz;
            lua_pushnumber(tolua_S, (lua_Number)ret);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2WheelJointDef:Get_frequencyHz", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2WheelJointDef_Get_frequencyHz'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2WheelJointDef_Set_frequencyHz(lua_State *tolua_S)
{
    int argc = 0;
    b2WheelJointDef *cobj = nullptr;
    bool ok = true;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2WheelJointDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2WheelJointDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2WheelJointDef_Set_frequencyHz'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (1 == argc)
        {
            double frequencyHz;
            ok&=luaval_to_number(tolua_S, 2, &frequencyHz);
            if(!ok)
            {
                tolua_error(tolua_S,"invalid arguments in function 'tolua_LuaBox2D_b2WheelJointDef_Set_frequencyHz'", nullptr);
                return 0;
            }
            cobj->frequencyHz = frequencyHz;
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2WheelJointDef:Set_frequencyHz", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2WheelJointDef_Set_frequencyHz'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2WheelJointDef_Get_dampingRatio(lua_State *tolua_S)
{
    int argc = 0;
    b2WheelJointDef *cobj = nullptr;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2WheelJointDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2WheelJointDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2WheelJointDef_Get_dampingRatio'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (0 == argc)
        {
            float32 ret = cobj->dampingRatio;
            lua_pushnumber(tolua_S, (lua_Number)ret);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2WheelJointDef:Get_dampingRatio", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2WheelJointDef_Get_dampingRatio'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2WheelJointDef_Set_dampingRatio(lua_State *tolua_S)
{
    int argc = 0;
    b2WheelJointDef *cobj = nullptr;
    bool ok = true;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2WheelJointDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2WheelJointDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2WheelJointDef_Set_dampingRatio'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (1 == argc)
        {
            double dampingRatio;
            ok&=luaval_to_number(tolua_S, 2, &dampingRatio);
            if(!ok)
            {
                tolua_error(tolua_S,"invalid arguments in function 'tolua_LuaBox2D_b2WheelJointDef_Set_dampingRatio'", nullptr);
                return 0;
            }
            cobj->dampingRatio = dampingRatio;
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2WheelJointDef:Set_dampingRatio", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2WheelJointDef_Set_dampingRatio'.", &tolua_err);
    return 0;
#endif
}

int lua_register_cocos2dx_b2WheelJointDef(lua_State* tolua_S){
    tolua_usertype(tolua_S, "b2WheelJointDef");
    tolua_cclass(tolua_S, "b2WheelJointDef", "b2WheelJointDef", "b2JointDef", nullptr);
    tolua_beginmodule(tolua_S, "b2WheelJointDef");
    tolua_function(tolua_S, "new", tolua_LuaBox2D_b2WheelJointDef_new00_local);
    tolua_function(tolua_S, "new_local", tolua_LuaBox2D_b2WheelJointDef_new00_local);
    tolua_function(tolua_S, ".call", tolua_LuaBox2D_b2WheelJointDef_new00_local);
    tolua_function(tolua_S, "Initialize", tolua_LuaBox2D_b2WheelJointDef_Initialize);
    tolua_variable(tolua_S, "localAnchorA", tolua_LuaBox2D_b2WheelJointDef_Get_localAnchorA,tolua_LuaBox2D_b2WheelJointDef_Set_localAnchorA);
    tolua_variable(tolua_S, "localAnchorB", tolua_LuaBox2D_b2WheelJointDef_Get_localAnchorB,tolua_LuaBox2D_b2WheelJointDef_Set_localAnchorB);
    tolua_variable(tolua_S, "localAxisA", tolua_LuaBox2D_b2WheelJointDef_Get_localAxisA,tolua_LuaBox2D_b2WheelJointDef_Set_localAxisA);
    tolua_variable(tolua_S, "enableMotor", tolua_LuaBox2D_b2WheelJointDef_Get_enableMotor,tolua_LuaBox2D_b2WheelJointDef_Set_enableMotor);
    tolua_variable(tolua_S, "maxMotorTorque", tolua_LuaBox2D_b2WheelJointDef_Get_maxMotorTorque,tolua_LuaBox2D_b2WheelJointDef_Set_maxMotorTorque);
    tolua_variable(tolua_S, "motorSpeed", tolua_LuaBox2D_b2WheelJointDef_Get_motorSpeed,tolua_LuaBox2D_b2WheelJointDef_Set_motorSpeed);
    tolua_variable(tolua_S, "frequencyHz", tolua_LuaBox2D_b2WheelJointDef_Get_frequencyHz,tolua_LuaBox2D_b2WheelJointDef_Set_frequencyHz);
    tolua_variable(tolua_S, "dampingRatio", tolua_LuaBox2D_b2WheelJointDef_Get_dampingRatio,tolua_LuaBox2D_b2WheelJointDef_Set_dampingRatio);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(b2WheelJointDef).name();
    g_luaType[typeName] = "b2WheelJointDef";
    g_typeCast["b2WheelJointDef"] = "b2WheelJointDef";
    return 1;
}

//function of GetAnchorA b2WheelJoint
int tolua_LuaBox2D_b2WheelJoint_GetAnchorA(lua_State* tolua_S){
    int argc = 0;
    b2WheelJoint* cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2WheelJoint", 0, &tolua_err)) goto tolua_lerror;
#endif

    cobj = (b2WheelJoint*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_LuaBox2D_b2WheelJoint_GetAnchorA'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do{
        if (0 == argc)
        {

            b2Vec2 newVec = cobj->GetAnchorA();
            // object_to_luaval<b2Vec2>(tolua_S, "b2Vec2",(b2Vec2*)&ret);
            b2Vec2 *ret = new b2Vec2(newVec.x, newVec.y);
            object_to_luaval(tolua_S, "b2Vec2", (b2Vec2 *)ret);
            tolua_register_gc(tolua_S, lua_gettop(tolua_S));
            return 1;
        }
    }while(0);
   
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_LuaBox2D_b2WheelJoint_GetAnchorA",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2WheelJoint_GetAnchorA'.",&tolua_err);
    return 0;
#endif
}

//function of GetAnchorB b2WheelJoint
int tolua_LuaBox2D_b2WheelJoint_GetAnchorB(lua_State* tolua_S){
    int argc = 0;
    b2WheelJoint* cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2WheelJoint", 0, &tolua_err)) goto tolua_lerror;
#endif

    cobj = (b2WheelJoint*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_LuaBox2D_b2WheelJoint_GetAnchorB'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do{
        if (0 == argc)
        {

            b2Vec2 newVec = cobj->GetAnchorB();
            // object_to_luaval<b2Vec2>(tolua_S, "b2Vec2",(b2Vec2*)&ret);
            b2Vec2 *ret = new b2Vec2(newVec.x, newVec.y);
            object_to_luaval(tolua_S, "b2Vec2", (b2Vec2 *)ret);
            tolua_register_gc(tolua_S, lua_gettop(tolua_S));
            return 1;
        }
    }while(0);
   
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_LuaBox2D_b2WheelJoint_GetAnchorB",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2WheelJoint_GetAnchorB'.",&tolua_err);
    return 0;
#endif
}

//function of GetLocalAnchorA b2WheelJoint
int tolua_LuaBox2D_b2WheelJoint_GetLocalAnchorA(lua_State* tolua_S){
    int argc = 0;
    b2WheelJoint* cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2WheelJoint", 0, &tolua_err)) goto tolua_lerror;
#endif

    cobj = (b2WheelJoint*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_LuaBox2D_b2WheelJoint_GetLocalAnchorA'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do{
        if (0 == argc)
        {

            b2Vec2 newVec = cobj->GetLocalAnchorA();
            // object_to_luaval<b2Vec2>(tolua_S, "b2Vec2",(b2Vec2*)&ret);
            b2Vec2 *ret = new b2Vec2(newVec.x, newVec.y);
            object_to_luaval(tolua_S, "b2Vec2", (b2Vec2 *)ret);
            tolua_register_gc(tolua_S, lua_gettop(tolua_S));
            return 1;
        }
    }while(0);
   
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_LuaBox2D_b2WheelJoint_GetLocalAnchorA",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2WheelJoint_GetLocalAnchorA'.",&tolua_err);
    return 0;
#endif
}

//function of GetLocalAnchorB b2WheelJoint
int tolua_LuaBox2D_b2WheelJoint_GetLocalAnchorB(lua_State* tolua_S){
    int argc = 0;
    b2WheelJoint* cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2WheelJoint", 0, &tolua_err)) goto tolua_lerror;
#endif

    cobj = (b2WheelJoint*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_LuaBox2D_b2WheelJoint_GetLocalAnchorB'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do{
        if (0 == argc)
        {

            b2Vec2 newVec = cobj->GetLocalAnchorB();
            // object_to_luaval<b2Vec2>(tolua_S, "b2Vec2",(b2Vec2*)&ret);
            b2Vec2 *ret = new b2Vec2(newVec.x, newVec.y);
            object_to_luaval(tolua_S, "b2Vec2", (b2Vec2 *)ret);
            tolua_register_gc(tolua_S, lua_gettop(tolua_S));
            return 1;
        }
    }while(0);
   
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_LuaBox2D_b2WheelJoint_GetLocalAnchorB",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2WheelJoint_GetLocalAnchorB'.",&tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2WheelJoint_GetReactionForce(lua_State *tolua_S)
{
    int argc = 0;
    b2WheelJoint *cobj = nullptr;
    bool ok = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2WheelJoint", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2WheelJoint *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2WheelJoint_GetReactionForce'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (1 == argc)
        {
            int arg0;
            ok &= luaval_to_int32(tolua_S, 2, &arg0, "b2WheelJoint:GetReactionForce");
            
            if(!ok)
            {
                tolua_error(tolua_S,"invalid arguments in function 'tolua_LuaBox2D_b2WheelJoint_GetReactionForce'", nullptr);
                return 0;
            }
            b2Vec2 newVec = cobj->GetReactionForce(arg0);
            // object_to_luaval<b2Vec2>(tolua_S, "b2Vec2", &ret);
            b2Vec2 *ret = new b2Vec2(newVec.x, newVec.y);
            object_to_luaval(tolua_S, "b2Vec2", (b2Vec2 *)ret);
            tolua_register_gc(tolua_S, lua_gettop(tolua_S));
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2WheelJoint:GetReactionForce", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2WheelJoint_GetReactionForce'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2WheelJoint_GetReactionTorque(lua_State *tolua_S)
{
    int argc = 0;
    b2WheelJoint *cobj = nullptr;
    bool ok = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2WheelJoint", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2WheelJoint *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2WheelJoint_GetReactionTorque'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (1 == argc)
        {
            double arg0;
            ok &= luaval_to_number(tolua_S, 2, &arg0, "b2WheelJoint:GetReactionTorque");
            if(!ok)
            {
                tolua_error(tolua_S,"invalid arguments in function 'tolua_LuaBox2D_b2WheelJoint_GetReactionTorque'", nullptr);
                return 0;
            }
            float32 ret = cobj->GetReactionTorque((float)arg0);
            tolua_pushnumber(tolua_S, (lua_Number)ret);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2WheelJoint:GetReactionTorque", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2WheelJoint_GetReactionTorque'.", &tolua_err);
    return 0;
#endif
}

//function of GetLocalAxisA b2WheelJoint
int tolua_LuaBox2D_b2WheelJoint_GetLocalAxisA(lua_State* tolua_S){
    int argc = 0;
    b2WheelJoint* cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2WheelJoint", 0, &tolua_err)) goto tolua_lerror;
#endif

    cobj = (b2WheelJoint*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_LuaBox2D_b2WheelJoint_GetLocalAxisA'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do{
        if (0 == argc)
        {

            b2Vec2 newVec = cobj->GetLocalAxisA();
            // object_to_luaval<b2Vec2>(tolua_S, "b2Vec2",(b2Vec2*)&ret);
            b2Vec2 *ret = new b2Vec2(newVec.x, newVec.y);
            object_to_luaval(tolua_S, "b2Vec2", (b2Vec2 *)ret);
            tolua_register_gc(tolua_S, lua_gettop(tolua_S));
            return 1;
        }
    }while(0);
   
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_LuaBox2D_b2WheelJoint_GetLocalAxisA",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2WheelJoint_GetLocalAxisA'.",&tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2WheelJoint_GetJointTranslation(lua_State *tolua_S)
{
    int argc = 0;
    b2WheelJoint *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2WheelJoint", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2WheelJoint *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2WheelJoint_GetJointTranslation'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (0 == argc)
        {
            float32 ret = cobj->GetJointTranslation();
            tolua_pushnumber(tolua_S, (lua_Number)ret);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2WheelJoint:GetJointTranslation", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2WheelJoint_GetJointTranslation'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2WheelJoint_GetJointSpeed(lua_State *tolua_S)
{
    int argc = 0;
    b2WheelJoint *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2WheelJoint", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2WheelJoint *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2WheelJoint_GetJointSpeed'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (0 == argc)
        {
            float32 ret = cobj->GetJointSpeed();
            tolua_pushnumber(tolua_S, (lua_Number)ret);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2WheelJoint:GetJointSpeed", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2WheelJoint_GetJointSpeed'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2WheelJoint_IsMotorEnabled(lua_State *tolua_S)
{
    int argc = 0;
    b2WheelJoint *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2WheelJoint", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2WheelJoint *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2WheelJoint_IsMotorEnabled'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (0 == argc)
        {
            bool ret = cobj->IsMotorEnabled();
            tolua_pushboolean(tolua_S, ret);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2WheelJoint:IsMotorEnabled", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2WheelJoint_IsMotorEnabled'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2WheelJoint_EnableMotor(lua_State *tolua_S)
{
    int argc = 0;
    b2WheelJoint *cobj = nullptr;
    bool ok = true;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2WheelJoint", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2WheelJoint *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2WheelJoint_EnableMotor'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (1 == argc)
        {
            bool EnableMotor;
            ok&=luaval_to_boolean(tolua_S, 2, &EnableMotor);
            if(!ok)
            {
                tolua_error(tolua_S,"invalid arguments in function 'tolua_LuaBox2D_b2WheelJoint_EnableMotor'", nullptr);
                return 0;
            }
            cobj->EnableMotor(EnableMotor);
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2WheelJoint:EnableMotor", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2WheelJoint_EnableMotor'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2WheelJoint_SetMotorSpeed(lua_State *tolua_S)
{
    int argc = 0;
    b2WheelJoint *cobj = nullptr;
    bool ok = true;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2WheelJoint", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2WheelJoint *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2WheelJoint_SetMotorSpeed'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (1 == argc)
        {
            double motorSpeed;
            ok&=luaval_to_number(tolua_S, 2, &motorSpeed);
            if(!ok)
            {
                tolua_error(tolua_S,"invalid arguments in function 'tolua_LuaBox2D_b2WheelJoint_SetMotorSpeed'", nullptr);
                return 0;
            }
            cobj->SetMotorSpeed(motorSpeed);
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2WheelJoint:SetMotorSpeed", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2WheelJoint_SetMotorSpeed'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2WheelJoint_GetMotorSpeed(lua_State *tolua_S)
{
    int argc = 0;
    b2WheelJoint *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2WheelJoint", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2WheelJoint *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2WheelJoint_GetMotorSpeed'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (0 == argc)
        {
            float32 ret = cobj->GetMotorSpeed();
            tolua_pushnumber(tolua_S, (lua_Number)ret);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2WheelJoint:GetMotorSpeed", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2WheelJoint_GetMotorSpeed'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2WheelJoint_SetMaxMotorTorque(lua_State *tolua_S)
{
    int argc = 0;
    b2WheelJoint *cobj = nullptr;
    bool ok = true;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2WheelJoint", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2WheelJoint *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2WheelJoint_SetMaxMotorTorque'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (1 == argc)
        {
            double MaxMotorTorque;
            ok&=luaval_to_number(tolua_S, 2, &MaxMotorTorque);
            if(!ok)
            {
                tolua_error(tolua_S,"invalid arguments in function 'tolua_LuaBox2D_b2WheelJoint_SetMaxMotorTorque'", nullptr);
                return 0;
            }
            cobj->SetMaxMotorTorque(MaxMotorTorque);
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2WheelJoint:SetMaxMotorTorque", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2WheelJoint_SetMaxMotorTorque'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2WheelJoint_GetMaxMotorTorque(lua_State *tolua_S)
{
    int argc = 0;
    b2WheelJoint *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2WheelJoint", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2WheelJoint *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2WheelJoint_GetMaxMotorTorque'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (0 == argc)
        {
            float32 ret = cobj->GetMaxMotorTorque();
            tolua_pushnumber(tolua_S, (lua_Number)ret);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2WheelJoint:GetMaxMotorTorque", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2WheelJoint_GetMaxMotorTorque'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2WheelJoint_GetMotorTorque(lua_State *tolua_S)
{
    int argc = 0;
    b2WheelJoint *cobj = nullptr;
    bool ok = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2WheelJoint", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2WheelJoint *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2WheelJoint_GetMotorTorque'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (1 == argc)
        {
            double arg0;
            ok &= luaval_to_number(tolua_S, 2, &arg0, "b2WheelJoint:GetMotorTorque");
            if(!ok)
            {
                tolua_error(tolua_S,"invalid arguments in function 'tolua_LuaBox2D_b2WheelJoint_GetMotorTorque'", nullptr);
                return 0;
            }
            float32 ret = cobj->GetMotorTorque((float)arg0);
            tolua_pushnumber(tolua_S, (lua_Number)ret);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2WheelJoint:GetMotorTorque", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2WheelJoint_GetMotorTorque'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2WheelJoint_SetSpringFrequencyHz(lua_State *tolua_S)
{
    int argc = 0;
    b2WheelJoint *cobj = nullptr;
    bool ok = true;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2WheelJoint", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2WheelJoint *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2WheelJoint_SetSpringFrequencyHz'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (1 == argc)
        {
            double SpringFrequencyHz;
            ok&=luaval_to_number(tolua_S, 2, &SpringFrequencyHz);
            if(!ok)
            {
                tolua_error(tolua_S,"invalid arguments in function 'tolua_LuaBox2D_b2WheelJoint_SetSpringFrequencyHz'", nullptr);
                return 0;
            }
            cobj->SetSpringFrequencyHz(SpringFrequencyHz);
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2WheelJoint:SetSpringFrequencyHz", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2WheelJoint_SetSpringFrequencyHz'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2WheelJoint_GetSpringFrequencyHz(lua_State *tolua_S)
{
    int argc = 0;
    b2WheelJoint *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2WheelJoint", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2WheelJoint *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2WheelJoint_GetSpringFrequencyHz'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (0 == argc)
        {
            float32 ret = cobj->GetSpringFrequencyHz();
            tolua_pushnumber(tolua_S, (lua_Number)ret);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2WheelJoint:GetSpringFrequencyHz", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2WheelJoint_GetSpringFrequencyHz'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2WheelJoint_SetSpringDampingRatio(lua_State *tolua_S)
{
    int argc = 0;
    b2WheelJoint *cobj = nullptr;
    bool ok = true;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2WheelJoint", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2WheelJoint *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2WheelJoint_SetSpringDampingRatio'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (1 == argc)
        {
            double SpringDampingRatio;
            ok&=luaval_to_number(tolua_S, 2, &SpringDampingRatio);
            if(!ok)
            {
                tolua_error(tolua_S,"invalid arguments in function 'tolua_LuaBox2D_b2WheelJoint_SetSpringDampingRatio'", nullptr);
                return 0;
            }
            cobj->SetSpringDampingRatio(SpringDampingRatio);
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2WheelJoint:SetSpringDampingRatio", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2WheelJoint_SetSpringDampingRatio'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2WheelJoint_GetSpringDampingRatio(lua_State *tolua_S)
{
    int argc = 0;
    b2WheelJoint *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2WheelJoint", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2WheelJoint *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2WheelJoint_GetSpringDampingRatio'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (0 == argc)
        {
            float32 ret = cobj->GetSpringDampingRatio();
            tolua_pushnumber(tolua_S, (lua_Number)ret);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2WheelJoint:GetSpringDampingRatio", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2WheelJoint_GetSpringDampingRatio'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2WheelJoint_Dump(lua_State *tolua_S)
{
    int argc = 0;
    b2WheelJoint *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2WheelJoint", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2WheelJoint *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2WheelJoint_Dump'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (0 == argc)
        {
            cobj->Dump();
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2WheelJoint:Dump", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2WheelJoint_Dump'.", &tolua_err);
    return 0;
#endif
}

int lua_register_cocos2dx_b2WheelJoint(lua_State* tolua_S){
    tolua_usertype(tolua_S, "b2WheelJoint");
    tolua_cclass(tolua_S, "b2WheelJoint", "b2WheelJoint", "b2Joint", nullptr);
    tolua_beginmodule(tolua_S, "b2WheelJoint");
    tolua_function(tolua_S, "GetAnchorA", tolua_LuaBox2D_b2WheelJoint_GetAnchorA);
    tolua_function(tolua_S, "GetAnchorB", tolua_LuaBox2D_b2WheelJoint_GetAnchorB);
    tolua_function(tolua_S, "GetLocalAnchorA", tolua_LuaBox2D_b2WheelJoint_GetLocalAnchorA);
    tolua_function(tolua_S, "GetLocalAnchorB", tolua_LuaBox2D_b2WheelJoint_GetLocalAnchorB);
    tolua_function(tolua_S, "GetReactionForce", tolua_LuaBox2D_b2WheelJoint_GetReactionForce);
    tolua_function(tolua_S, "GetReactionTorque", tolua_LuaBox2D_b2WheelJoint_GetReactionTorque);
    tolua_function(tolua_S, "GetLocalAxisA", tolua_LuaBox2D_b2WheelJoint_GetLocalAxisA);
    tolua_function(tolua_S, "GetJointTranslation", tolua_LuaBox2D_b2WheelJoint_GetJointTranslation);
    tolua_function(tolua_S,"GetJointSpeed",tolua_LuaBox2D_b2WheelJoint_GetJointSpeed);
    tolua_function(tolua_S, "IsMotorEnabled", tolua_LuaBox2D_b2WheelJoint_IsMotorEnabled);
    tolua_function(tolua_S, "EnableMotor", tolua_LuaBox2D_b2WheelJoint_EnableMotor);
    tolua_function(tolua_S, "SetMotorSpeed", tolua_LuaBox2D_b2WheelJoint_SetMotorSpeed);
    tolua_function(tolua_S, "GetMotorSpeed", tolua_LuaBox2D_b2WheelJoint_GetMotorSpeed);
    tolua_function(tolua_S, "SetMaxMotorTorque", tolua_LuaBox2D_b2WheelJoint_SetMaxMotorTorque);
    tolua_function(tolua_S, "GetMaxMotorTorque", tolua_LuaBox2D_b2WheelJoint_GetMaxMotorTorque);
    tolua_function(tolua_S, "GetMotorTorque", tolua_LuaBox2D_b2WheelJoint_GetMotorTorque);
    tolua_function(tolua_S, "SetSpringFrequencyHz", tolua_LuaBox2D_b2WheelJoint_SetSpringFrequencyHz);
    tolua_function(tolua_S, "GetSpringFrequencyHz", tolua_LuaBox2D_b2WheelJoint_GetSpringFrequencyHz);
    
    tolua_function(tolua_S, "SetSpringDampingRatio", tolua_LuaBox2D_b2WheelJoint_SetSpringDampingRatio);
    tolua_function(tolua_S, "GetSpringDampingRatio", tolua_LuaBox2D_b2WheelJoint_GetSpringDampingRatio);

    tolua_function(tolua_S, "Dump", tolua_LuaBox2D_b2WheelJoint_Dump);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(b2WheelJoint).name();
    g_luaType[typeName] = "b2WheelJoint";
    g_typeCast["b2WheelJoint"] = "b2WheelJoint";
    return 1;
}


int tolua_LuaBox2D_b2RopeJointDef_new00_local(lua_State* tolua_S){
   int argc = 0;
    b2RopeJointDef *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2RopeJointDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2RopeJointDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2RopeJointDef_new00_local'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (0 == argc)
        {
            b2RopeJointDef* ret = (b2RopeJointDef*)  Mtolua_new((b2RopeJointDef)());
            object_to_luaval<b2RopeJointDef>(tolua_S, "b2RopeJointDef", ret);
            tolua_register_gc(tolua_S, lua_gettop(tolua_S));
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2RopeJointDef:new00_local", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2RopeJointDef_new00_local'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2RopeJointDef_Get_localAnchorA(lua_State* tolua_S){
    int argc = 0;
    b2RopeJointDef *cobj = nullptr;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2RopeJointDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2RopeJointDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2RopeJointDef_Get_localAnchorA'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (0 == argc)
        {
            object_to_luaval<b2Vec2>(tolua_S, "b2Vec2",(b2Vec2*)&(cobj->localAnchorA));
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2RopeJointDef:Get_localAnchorA", argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2RopeJointDef_Get_localAnchorA'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2RopeJointDef_Set_localAnchorA(lua_State* tolua_S){
    int argc = 0;
    b2RopeJointDef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"b2RopeJointDef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (b2RopeJointDef*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (nullptr == cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_LuaBox2D_b2RopeJointDef_Set_localAnchorA'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S) - 1;

    do{
        if (1 == argc)
        {
            b2Vec2* arg0;
            ok &= luaval_to_object<b2Vec2>(tolua_S, 2, "b2Vec2", &arg0);
            if (!ok) break;
             
            cobj->localAnchorA = *arg0;
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_LuaBox2D_b2RopeJointDef_Set_localAnchorA", argc, 1);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2RopeJointDef_Set_localAnchorA'.",&tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2RopeJointDef_Get_localAnchorB(lua_State* tolua_S){
    int argc = 0;
    b2RopeJointDef *cobj = nullptr;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2RopeJointDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2RopeJointDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2RopeJointDef_Get_localAnchorB'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (0 == argc)
        {
            object_to_luaval<b2Vec2>(tolua_S, "b2Vec2",(b2Vec2*)&(cobj->localAnchorB));
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2RopeJointDef:Get_localAnchorB", argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2RopeJointDef_Get_localAnchorB'.", &tolua_err);
    return 0;
#endif
}


int tolua_LuaBox2D_b2RopeJointDef_Set_localAnchorB(lua_State* tolua_S){
    int argc = 0;
    b2RopeJointDef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"b2RopeJointDef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (b2RopeJointDef*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (nullptr == cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_LuaBox2D_b2RopeJointDef_Set_localAnchorB'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S) - 1;

    do{
        if (1 == argc)
        {
            b2Vec2* arg0;
            ok &= luaval_to_object<b2Vec2>(tolua_S, 2, "b2Vec2", &arg0);
            if (!ok) break;
             
            cobj->localAnchorB = *arg0;
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_LuaBox2D_b2RopeJointDef_Set_localAnchorB",argc, 1);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2RopeJointDef_Set_localAnchorB'.",&tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2RopeJointDef_Get_maxLength(lua_State* tolua_S){
    int argc = 0;
    b2RopeJointDef *cobj = nullptr;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2RopeJointDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2RopeJointDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2RopeJointDef_Get_maxLength'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (0 == argc)
        {
            float32 ret = cobj->maxLength;
            tolua_pushnumber(tolua_S, (lua_Number)ret);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2RopeJointDef:Get_maxLength", argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2RopeJointDef_Get_maxLength'.", &tolua_err);
    return 0;
#endif
}


int tolua_LuaBox2D_b2RopeJointDef_Set_maxLength(lua_State* tolua_S){
    int argc = 0;
    b2RopeJointDef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"b2RopeJointDef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (b2RopeJointDef*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (nullptr == cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_LuaBox2D_b2RopeJointDef_Set_localAnchorB'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S) - 1;

    do{
        if (1 == argc)
        {
            double arg0;
            ok &= luaval_to_number(tolua_S, 2, &arg0, "b2RopeJointDef.maxLength");
            if (!ok) break;
             
            cobj->maxLength = arg0;
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_LuaBox2D_b2RopeJointDef_Set_localAnchorB",argc, 1);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2RopeJointDef_Set_localAnchorB'.",&tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2RopeJoint_GetLocalAnchorA(lua_State* tolua_S){
    int argc = 0;
    b2RopeJoint *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2RopeJoint", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2RopeJoint *)tolua_tousertype(tolua_S, 1, 0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2RopeJoint_GetLocalAnchorA'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if(argc >= 0){
        b2Vec2 ret = cobj -> GetLocalAnchorA();
        object_to_luaval<b2Vec2>(tolua_S, "b2Vec2", (b2Vec2 *)&ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2RopeJoint:GetGravity", argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2RopeJoint_GetLocalAnchorA'.", &tolua_err);
#endif
    return 0;
}


int tolua_LuaBox2D_b2RopeJoint_GetLocalAnchorB(lua_State* tolua_S){
    int argc = 0;
    b2RopeJoint *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2RopeJoint", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2RopeJoint *)tolua_tousertype(tolua_S, 1, 0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2RopeJoint_GetLocalAnchorB'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if(argc >= 0){
        b2Vec2 ret = cobj -> GetLocalAnchorB();
        object_to_luaval<b2Vec2>(tolua_S, "b2Vec2", (b2Vec2 *)&ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2RopeJoint:GetGravity", argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2RopeJoint_GetLocalAnchorB'.", &tolua_err);
#endif
    return 0;
}

int tolua_LuaBox2D_b2RopeJoint_SetMaxLength(lua_State* tolua_S){
    int argc = 0;
    b2RopeJoint* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"b2RopeJoint",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (b2RopeJoint*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_LuaBox2D_b2RopeJoint_SetMaxLength'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    ok  = true;
    do{
        if (argc == 1) {
            double arg0;
            ok &= luaval_to_number(tolua_S, 2,&arg0, "b2RopeJoint:SetMaxLength");
            if (!ok) { break; }
            cobj->SetMaxLength(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "b2RopeJoint:SetMaxLength",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2RopeJoint_SetMaxLength'.",&tolua_err);
#endif

    return 0;
}

int tolua_LuaBox2D_b2RopeJoint_GetMaxLength(lua_State* tolua_S){
    int argc = 0;
    b2RopeJoint* cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"b2RopeJoint",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (b2RopeJoint*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_LuaBox2D_b2RopeJoint_GetMaxLength'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0)
    {
        double ret = cobj->GetMaxLength();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2RopeJoint:getScale",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2RopeJoint_GetMaxLength'.",&tolua_err);
#endif

    return 0;
}

int tolua_LuaBox2D_b2RopeJoint_Dump(lua_State* tolua_S){
    int argc = 0;
    b2RopeJoint *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

// 参数判断
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "b2RopeJoint", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2RopeJoint *)tolua_tousertype(tolua_S, 1, 0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2RopeJoint_Dump'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if(argc == 0){
        cobj -> Dump();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2RopeJoint:Dump", argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2RopeJoint_Dump'.", &tolua_err);
#endif
    return 0; 
}

int lua_register_cocos2dx_b2RopeJointDef(lua_State* tolua_S){
    tolua_usertype(tolua_S, "b2RopeJointDef");
    tolua_cclass(tolua_S, "b2RopeJointDef", "b2RopeJointDef", "b2JointDef", nullptr);
    tolua_beginmodule(tolua_S, "b2RopeJointDef");
    tolua_function(tolua_S, "new", tolua_LuaBox2D_b2RopeJointDef_new00_local);
    tolua_function(tolua_S, "new_local", tolua_LuaBox2D_b2RopeJointDef_new00_local);
    tolua_function(tolua_S, ".call", tolua_LuaBox2D_b2RopeJointDef_new00_local);
    tolua_variable(tolua_S, "localAnchorA", tolua_LuaBox2D_b2RopeJointDef_Get_localAnchorA, tolua_LuaBox2D_b2RopeJointDef_Set_localAnchorA);
    tolua_variable(tolua_S, "localAnchorB", tolua_LuaBox2D_b2RopeJointDef_Get_localAnchorB, tolua_LuaBox2D_b2RopeJointDef_Set_localAnchorB);
    tolua_variable(tolua_S, "maxLength", tolua_LuaBox2D_b2RopeJointDef_Get_maxLength, tolua_LuaBox2D_b2RopeJointDef_Set_maxLength);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(b2RopeJointDef).name();
    g_luaType[typeName] = "b2RopeJointDef";
    g_typeCast["b2RopeJointDef"] = "b2RopeJointDef";
    return 1;
}

int lua_register_cocos2dx_b2RopeJoint(lua_State* tolua_S){
    tolua_usertype(tolua_S, "b2RopeJoint");
    tolua_cclass(tolua_S, "b2RopeJoint", "b2RopeJoint", "b2Joint", nullptr);
    tolua_beginmodule(tolua_S, "b2RopeJoint");
    tolua_function(tolua_S, "GetLocalAnchorA", tolua_LuaBox2D_b2RopeJoint_GetLocalAnchorA);
    tolua_function(tolua_S, "GetLocalAnchorB", tolua_LuaBox2D_b2RopeJoint_GetLocalAnchorB);
    tolua_function(tolua_S, "SetMaxLength", tolua_LuaBox2D_b2RopeJoint_SetMaxLength);
    tolua_function(tolua_S, "GetMaxLength", tolua_LuaBox2D_b2RopeJoint_GetMaxLength);
    tolua_function(tolua_S, "Dump", tolua_LuaBox2D_b2RopeJoint_Dump);

    tolua_endmodule(tolua_S);
    std::string typeName = typeid(b2RopeJoint).name();
    g_luaType[typeName] = "b2RopeJoint";
    g_typeCast["b2RopeJoint"] = "b2RopeJoint";
    return 1;
}

int tolua_LuaBox2D_b2WeldJointDef_new00_local(lua_State* tolua_S){
   int argc = 0;
    b2WeldJointDef *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

    cobj = (b2WeldJointDef *)tolua_tousertype(tolua_S, 1, 0);
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (0 == argc)
        {
            b2WeldJointDef* ret = (b2WeldJointDef*)  Mtolua_new((b2WeldJointDef)());
            object_to_luaval<b2WeldJointDef>(tolua_S, "b2WeldJointDef", ret);
            tolua_register_gc(tolua_S, lua_gettop(tolua_S));
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2WeldJointDef:new00_local", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2WeldJointDef_new00_local'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2WeldJointDef_Initialize(lua_State *tolua_S)
{
    int argc = 0;
    b2WeldJointDef *cobj = nullptr;
    bool ok = true;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2WeldJointDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2WeldJointDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2WeldJointDef_Initialize'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (4 == argc)
        {
            b2Body* bodyA;
            ok &= luaval_to_object<b2Body>(tolua_S, 2, "b2Body", &bodyA);
            b2Body* bodyB;
            ok &= luaval_to_object<b2Body>(tolua_S, 3, "b2Body", &bodyB);
            const b2Vec2* anchor;
            ok &= luaval_to_object<const b2Vec2>(tolua_S, 4, "const b2Vec2", &anchor);
            if(!ok)
            {
                tolua_error(tolua_S,"invalid arguments in function 'tolua_LuaBox2D_b2WeldJointDef_Initialize'", nullptr);
                return 0;
            }
            cobj->Initialize(bodyA, bodyB, *anchor);
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2WeldJointDef:Initialize", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2WeldJointDef_Initialize'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2WeldJointDef_Get_localAnchorA(lua_State *tolua_S)
{
    int argc = 0;
    b2WeldJointDef *cobj = nullptr;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2WeldJointDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2WeldJointDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2WeldJointDef_Get_localAnchorA'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (0 == argc)
        {
            b2Vec2 ret = cobj->localAnchorA;
            object_to_luaval(tolua_S, "b2Vec2", &ret);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2WeldJointDef:Get_localAnchorA", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2WeldJointDef_Get_localAnchorA'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2WeldJointDef_Set_localAnchorA(lua_State *tolua_S)
{
    int argc = 0;
    b2WeldJointDef *cobj = nullptr;
    bool ok = true;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2WeldJointDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2WeldJointDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2WeldJointDef_Set_localAnchorA'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (1 == argc)
        {
            b2Vec2* localAnchorA;
            ok&=luaval_to_object<b2Vec2>(tolua_S, 2, "b2Vec2", &localAnchorA);
            if(!ok)
            {
                tolua_error(tolua_S,"invalid arguments in function 'tolua_LuaBox2D_b2WeldJointDef_Set_localAnchorA'", nullptr);
                return 0;
            }
            cobj->localAnchorA = *localAnchorA;
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2WeldJointDef:Set_localAnchorA", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2WeldJointDef_Set_localAnchorA'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2WeldJointDef_Get_localAnchorB(lua_State *tolua_S)
{
    int argc = 0;
    b2WeldJointDef *cobj = nullptr;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2WeldJointDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2WeldJointDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2WeldJointDef_Get_localAnchorB'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (0 == argc)
        {
            b2Vec2 ret = cobj->localAnchorB;
            object_to_luaval(tolua_S, "b2Vec2", &ret);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2WeldJointDef:Get_localAnchorB", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2WeldJointDef_Get_localAnchorB'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2WeldJointDef_Set_localAnchorB(lua_State *tolua_S)
{
    int argc = 0;
    b2WeldJointDef *cobj = nullptr;
    bool ok = true;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2WeldJointDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2WeldJointDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2WeldJointDef_Set_localAnchorB'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (1 == argc)
        {
            b2Vec2* localAnchorB;
            ok&=luaval_to_object<b2Vec2>(tolua_S, 2, "b2Vec2", &localAnchorB);
            if(!ok)
            {
                tolua_error(tolua_S,"invalid arguments in function 'tolua_LuaBox2D_b2WeldJointDef_Set_localAnchorB'", nullptr);
                return 0;
            }
            cobj->localAnchorB = *localAnchorB;
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2WeldJointDef:Set_localAnchorB", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2WeldJointDef_Set_localAnchorB'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2WeldJointDef_Get_referenceAngle(lua_State *tolua_S)
{
    int argc = 0;
    b2WeldJointDef *cobj = nullptr;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2WeldJointDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2WeldJointDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2WeldJointDef_Get_referenceAngle'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (0 == argc)
        {
            float32 ret = cobj->referenceAngle;
            lua_pushnumber(tolua_S, (lua_Number)ret);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2WeldJointDef:Get_referenceAngle", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2WeldJointDef_Get_referenceAngle'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2WeldJointDef_Set_referenceAngle(lua_State *tolua_S)
{
    int argc = 0;
    b2WeldJointDef *cobj = nullptr;
    bool ok = true;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2WeldJointDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2WeldJointDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2WeldJointDef_Set_referenceAngle'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (1 == argc)
        {
            double referenceAngle;
            ok&=luaval_to_number(tolua_S, 2, &referenceAngle);
            if(!ok)
            {
                tolua_error(tolua_S,"invalid arguments in function 'tolua_LuaBox2D_b2WeldJointDef_Set_referenceAngle'", nullptr);
                return 0;
            }
            cobj->referenceAngle = referenceAngle;
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2WeldJointDef:Set_referenceAngle", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2WeldJointDef_Set_referenceAngle'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2WeldJointDef_Get_frequencyHz(lua_State *tolua_S)
{
    int argc = 0;
    b2WeldJointDef *cobj = nullptr;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2WeldJointDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2WeldJointDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2WeldJointDef_Get_frequencyHz'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (0 == argc)
        {
            float32 ret = cobj->frequencyHz;
            lua_pushnumber(tolua_S, (lua_Number)ret);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2WeldJointDef:Get_frequencyHz", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2WeldJointDef_Get_frequencyHz'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2WeldJointDef_Set_frequencyHz(lua_State *tolua_S)
{
    int argc = 0;
    b2WeldJointDef *cobj = nullptr;
    bool ok = true;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2WeldJointDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2WeldJointDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2WeldJointDef_Set_frequencyHz'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (1 == argc)
        {
            double frequencyHz;
            ok&=luaval_to_number(tolua_S, 2, &frequencyHz);
            if(!ok)
            {
                tolua_error(tolua_S,"invalid arguments in function 'tolua_LuaBox2D_b2WeldJointDef_Set_frequencyHz'", nullptr);
                return 0;
            }
            cobj->frequencyHz = frequencyHz;
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2WeldJointDef:Set_frequencyHz", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2WeldJointDef_Set_frequencyHz'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2WeldJointDef_Get_dampingRatio(lua_State *tolua_S)
{
    int argc = 0;
    b2WeldJointDef *cobj = nullptr;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2WeldJointDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2WeldJointDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2WeldJointDef_Get_dampingRatio'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (0 == argc)
        {
            float32 ret = cobj->dampingRatio;
            lua_pushnumber(tolua_S, (lua_Number)ret);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2WeldJointDef:Get_dampingRatio", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2WeldJointDef_Get_dampingRatio'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2WeldJointDef_Set_dampingRatio(lua_State *tolua_S)
{
    int argc = 0;
    b2WeldJointDef *cobj = nullptr;
    bool ok = true;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2WeldJointDef", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2WeldJointDef *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2WeldJointDef_Set_dampingRatio'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (1 == argc)
        {
            double dampingRatio;
            ok&=luaval_to_number(tolua_S, 2, &dampingRatio);
            if(!ok)
            {
                tolua_error(tolua_S,"invalid arguments in function 'tolua_LuaBox2D_b2WeldJointDef_Set_dampingRatio'", nullptr);
                return 0;
            }
            cobj->dampingRatio = dampingRatio;
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2WeldJointDef:Set_dampingRatio", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2WeldJointDef_Set_dampingRatio'.", &tolua_err);
    return 0;
#endif
}

int lua_register_cocos2dx_b2WeldJointDef(lua_State* tolua_S){
    tolua_usertype(tolua_S, "b2WeldJointDef");
    tolua_cclass(tolua_S, "b2WeldJointDef", "b2WeldJointDef", "b2JointDef", nullptr);
    tolua_beginmodule(tolua_S, "b2WeldJointDef");
    tolua_function(tolua_S, "new", tolua_LuaBox2D_b2WeldJointDef_new00_local);
    tolua_function(tolua_S, "new_local", tolua_LuaBox2D_b2WeldJointDef_new00_local);
    tolua_function(tolua_S, ".call", tolua_LuaBox2D_b2WeldJointDef_new00_local);
    tolua_function(tolua_S, "Initialize", tolua_LuaBox2D_b2WeldJointDef_Initialize);
    tolua_variable(tolua_S, "localAnchorA", tolua_LuaBox2D_b2WeldJointDef_Get_localAnchorA, tolua_LuaBox2D_b2WeldJointDef_Set_localAnchorA);
    tolua_variable(tolua_S, "localAnchorB", tolua_LuaBox2D_b2WeldJointDef_Get_localAnchorB, tolua_LuaBox2D_b2WeldJointDef_Set_localAnchorB);
    tolua_variable(tolua_S, "referenceAngle", tolua_LuaBox2D_b2WeldJointDef_Get_referenceAngle, tolua_LuaBox2D_b2WeldJointDef_Set_referenceAngle);
    tolua_variable(tolua_S, "frequencyHz", tolua_LuaBox2D_b2WeldJointDef_Get_frequencyHz, tolua_LuaBox2D_b2WeldJointDef_Set_frequencyHz);
    tolua_variable(tolua_S, "dampingRatio", tolua_LuaBox2D_b2WeldJointDef_Get_dampingRatio, tolua_LuaBox2D_b2WeldJointDef_Set_dampingRatio);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(b2WeldJointDef).name();
    g_luaType[typeName] = "b2WeldJointDef";
    g_typeCast["b2WeldJointDef"] = "b2WeldJointDef";
    return 1;
}

//function of GetAnchorA b2WeldJoint
int tolua_LuaBox2D_b2WeldJoint_GetAnchorA(lua_State* tolua_S){
    int argc = 0;
    b2WeldJoint* cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2WeldJoint", 0, &tolua_err)) goto tolua_lerror;
#endif

    cobj = (b2WeldJoint*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_LuaBox2D_b2WeldJoint_GetAnchorA'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do{
        if (0 == argc)
        {

            b2Vec2 newVec = cobj->GetAnchorA();
            // object_to_luaval<b2Vec2>(tolua_S, "b2Vec2",(b2Vec2*)&ret);
            b2Vec2 *ret = new b2Vec2(newVec.x, newVec.y);
            object_to_luaval(tolua_S, "b2Vec2", (b2Vec2 *)ret);
            tolua_register_gc(tolua_S, lua_gettop(tolua_S));
            return 1;
        }
    }while(0);
   
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_LuaBox2D_b2WeldJoint_GetAnchorA",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2WeldJoint_GetAnchorA'.",&tolua_err);
    return 0;
#endif
}

//function of GetAnchorB b2WeldJoint
int tolua_LuaBox2D_b2WeldJoint_GetAnchorB(lua_State* tolua_S){
    int argc = 0;
    b2WeldJoint* cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2WeldJoint", 0, &tolua_err)) goto tolua_lerror;
#endif

    cobj = (b2WeldJoint*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_LuaBox2D_b2WeldJoint_GetAnchorB'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do{
        if (0 == argc)
        {

            b2Vec2 newVec = cobj->GetAnchorB();
            // object_to_luaval<b2Vec2>(tolua_S, "b2Vec2",(b2Vec2*)&ret);
            b2Vec2 *ret = new b2Vec2(newVec.x, newVec.y);
            object_to_luaval(tolua_S, "b2Vec2", (b2Vec2 *)ret);
            tolua_register_gc(tolua_S, lua_gettop(tolua_S));
            return 1;
        }
    }while(0);
   
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_LuaBox2D_b2WeldJoint_GetAnchorB",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2WeldJoint_GetAnchorB'.",&tolua_err);
    return 0;
#endif
}

//function of GetLocalAnchorA b2WeldJoint
int tolua_LuaBox2D_b2WeldJoint_GetLocalAnchorA(lua_State* tolua_S){
    int argc = 0;
    b2WeldJoint* cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2WeldJoint", 0, &tolua_err)) goto tolua_lerror;
#endif

    cobj = (b2WeldJoint*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_LuaBox2D_b2WeldJoint_GetLocalAnchorA'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do{
        if (0 == argc)
        {

            b2Vec2 newVec = cobj->GetLocalAnchorA();
            // object_to_luaval<b2Vec2>(tolua_S, "b2Vec2",(b2Vec2*)&ret);
            b2Vec2 *ret = new b2Vec2(newVec.x, newVec.y);
            object_to_luaval(tolua_S, "b2Vec2", (b2Vec2 *)ret);
            tolua_register_gc(tolua_S, lua_gettop(tolua_S));
            return 1;
        }
    }while(0);
   
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_LuaBox2D_b2WeldJoint_GetLocalAnchorA",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2WeldJoint_GetLocalAnchorA'.",&tolua_err);
    return 0;
#endif
}

//function of GetLocalAnchorB b2WeldJoint
int tolua_LuaBox2D_b2WeldJoint_GetLocalAnchorB(lua_State* tolua_S){
    int argc = 0;
    b2WeldJoint* cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2WeldJoint", 0, &tolua_err)) goto tolua_lerror;
#endif

    cobj = (b2WeldJoint*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_LuaBox2D_b2WeldJoint_GetLocalAnchorB'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do{
        if (0 == argc)
        {

            b2Vec2 newVec = cobj->GetLocalAnchorB();
            // object_to_luaval<b2Vec2>(tolua_S, "b2Vec2",(b2Vec2*)&ret);
            b2Vec2 *ret = new b2Vec2(newVec.x, newVec.y);
            object_to_luaval(tolua_S, "b2Vec2", (b2Vec2 *)ret);
            tolua_register_gc(tolua_S, lua_gettop(tolua_S));
            return 1;
        }
    }while(0);
   
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_LuaBox2D_b2WeldJoint_GetLocalAnchorB",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2WeldJoint_GetLocalAnchorB'.",&tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2WeldJoint_GetReactionForce(lua_State *tolua_S)
{
    int argc = 0;
    b2WeldJoint *cobj = nullptr;
    bool ok = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2WeldJoint", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2WeldJoint *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2WeldJoint_GetReactionForce'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (1 == argc)
        {
            int arg0;
            ok &= luaval_to_int32(tolua_S, 2, &arg0, "b2WeldJoint:GetReactionForce");
            
            if(!ok)
            {
                tolua_error(tolua_S,"invalid arguments in function 'tolua_LuaBox2D_b2WeldJoint_GetReactionForce'", nullptr);
                return 0;
            }
            b2Vec2 newVec = cobj->GetReactionForce(arg0);
            // object_to_luaval<b2Vec2>(tolua_S, "b2Vec2", &ret);
            b2Vec2 *ret = new b2Vec2(newVec.x, newVec.y);
            object_to_luaval(tolua_S, "b2Vec2", (b2Vec2 *)ret);
            tolua_register_gc(tolua_S, lua_gettop(tolua_S));
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2WeldJoint:GetReactionForce", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2WeldJoint_GetReactionForce'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2WeldJoint_GetReactionTorque(lua_State *tolua_S)
{
    int argc = 0;
    b2WeldJoint *cobj = nullptr;
    bool ok = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2WeldJoint", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2WeldJoint *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2WeldJoint_GetReactionTorque'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (1 == argc)
        {
            double arg0;
            ok &= luaval_to_number(tolua_S, 2, &arg0, "b2WeldJoint:GetReactionTorque");
            if(!ok)
            {
                tolua_error(tolua_S,"invalid arguments in function 'tolua_LuaBox2D_b2WeldJoint_GetReactionTorque'", nullptr);
                return 0;
            }
            float32 ret = cobj->GetReactionTorque((float)arg0);
            tolua_pushnumber(tolua_S, (lua_Number)ret);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2WeldJoint:GetReactionTorque", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2WeldJoint_GetReactionTorque'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2WeldJoint_GetReferenceAngle(lua_State *tolua_S)
{
    int argc = 0;
    b2WeldJoint *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2WeldJoint", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2WeldJoint *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2WeldJoint_GetReferenceAngle'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (0 == argc)
        {
            float32 ret = cobj->GetReferenceAngle();
            tolua_pushnumber(tolua_S, (lua_Number)ret);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2WeldJoint:GetReferenceAngle", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2WeldJoint_GetReferenceAngle'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2WeldJoint_SetFrequency(lua_State *tolua_S)
{
    int argc = 0;
    b2WeldJoint *cobj = nullptr;
    bool ok = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2WeldJoint", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2WeldJoint *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2WeldJoint_SetFrequency'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (1 == argc)
        {
            double arg0;
            ok &= luaval_to_number(tolua_S, 2, &arg0);
            if(!ok)
            {
                tolua_error(tolua_S,"invalid arguments in function 'tolua_LuaBox2D_b2WeldJoint_SetFrequency'", nullptr);
                return 0;
            }
            cobj->SetFrequency(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2WeldJoint:SetFrequency", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2WeldJoint_SetFrequency'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2WeldJoint_GetFrequency(lua_State *tolua_S)
{
    int argc = 0;
    b2WeldJoint *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2WeldJoint", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2WeldJoint *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2WeldJoint_GetFrequency'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (0 == argc)
        {
            float32 ret = cobj->GetFrequency();
            lua_pushnumber(tolua_S, (lua_Number)ret);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2WeldJoint:GetFrequency", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2WeldJoint_GetFrequency'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2WeldJoint_SetDampingRatio(lua_State *tolua_S)
{
    int argc = 0;
    b2WeldJoint *cobj = nullptr;
    bool ok = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2WeldJoint", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2WeldJoint *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2WeldJoint_SetDampingRatio'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (1 == argc)
        {
            double arg0;
            ok &= luaval_to_number(tolua_S, 2, &arg0);
            if(!ok)
            {
                tolua_error(tolua_S,"invalid arguments in function 'tolua_LuaBox2D_b2WeldJoint_SetDampingRatio'", nullptr);
                return 0;
            }
            cobj->SetDampingRatio(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2WeldJoint:SetDampingRatio", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2WeldJoint_SetDampingRatio'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2WeldJoint_GetDampingRatio(lua_State *tolua_S)
{
    int argc = 0;
    b2WeldJoint *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2WeldJoint", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2WeldJoint *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2WeldJoint_GetDampingRatio'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (0 == argc)
        {
            float32 ret = cobj->GetDampingRatio();
            lua_pushnumber(tolua_S, (lua_Number)ret);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2WeldJoint:GetDampingRatio", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2WeldJoint_GetDampingRatio'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2WeldJoint_Dump(lua_State *tolua_S)
{
    int argc = 0;
    b2WeldJoint *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2WeldJoint", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2WeldJoint *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2WeldJoint_Dump'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do
    {
        if (0 == argc)
        {
            cobj->Dump();
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "b2WeldJoint:Dump", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2WeldJoint_Dump'.", &tolua_err);
    return 0;
#endif
}

int lua_register_cocos2dx_b2WeldJoint(lua_State* tolua_S){
    tolua_usertype(tolua_S, "b2WeldJoint");
    tolua_cclass(tolua_S, "b2WeldJoint", "b2WeldJoint", "b2Joint", nullptr);
    tolua_beginmodule(tolua_S, "b2WeldJoint");
    tolua_function(tolua_S, "GetAnchorA", tolua_LuaBox2D_b2WeldJoint_GetAnchorA);
    tolua_function(tolua_S, "GetAnchorB", tolua_LuaBox2D_b2WeldJoint_GetAnchorB);
    tolua_function(tolua_S, "GetReactionForce", tolua_LuaBox2D_b2WeldJoint_GetReactionForce);
    tolua_function(tolua_S, "GetReactionTorque", tolua_LuaBox2D_b2WeldJoint_GetReactionTorque);
    tolua_function(tolua_S, "GetLocalAnchorA", tolua_LuaBox2D_b2WeldJoint_GetLocalAnchorA);
    tolua_function(tolua_S, "GetLocalAnchorB", tolua_LuaBox2D_b2WeldJoint_GetLocalAnchorB);
    tolua_function(tolua_S, "GetReferenceAngle", tolua_LuaBox2D_b2WeldJoint_GetReferenceAngle);
    tolua_function(tolua_S, "SetFrequency", tolua_LuaBox2D_b2WeldJoint_SetFrequency);
    tolua_function(tolua_S, "GetFrequency", tolua_LuaBox2D_b2WeldJoint_GetFrequency);
    tolua_function(tolua_S, "SetDampingRatio", tolua_LuaBox2D_b2WeldJoint_SetDampingRatio);
    tolua_function(tolua_S, "GetDampingRatio", tolua_LuaBox2D_b2WeldJoint_GetDampingRatio);
    tolua_function(tolua_S, "Dump", tolua_LuaBox2D_b2WeldJoint_Dump);

    tolua_endmodule(tolua_S);
    std::string typeName = typeid(b2WeldJoint).name();
    g_luaType[typeName] = "b2WeldJoint";
    g_typeCast["b2WeldJoint"] = "b2WeldJoint";
    return 1;
}

/* class of b2Shape */
//function of delete b2Shape
int tolua_LuaBox2D_b2Shape_delete00(lua_State* tolua_S){
    int argc = 0;
    b2Shape* cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2Shape", 0, &tolua_err)) goto tolua_lerror;
#endif

    cobj = (b2Shape*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_LuaBox2D_b2Shape_delete00'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do{
        if (0 == argc)
        {
            Mtolua_delete(cobj);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
   
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_LuaBox2D_b2Shape_delete00",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2Shape_delete00'.",&tolua_err);
    return 0;
#endif
}

//function of Clone b2Shape
int tolua_LuaBox2D_b2Shape_Clone00(lua_State* tolua_S){
    int argc = 0;
    b2Shape* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2Shape", 0, &tolua_err)) goto tolua_lerror;
#endif

    cobj = (b2Shape*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_LuaBox2D_b2Shape_Clone00'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do{
        if (1 == argc)
        {
            b2BlockAllocator* arg0;
            ok &= luaval_to_object<b2BlockAllocator>(tolua_S, 2, "b2BlockAllocator", &arg0);
            if (!ok) { break; }
            
            b2Shape* ret = (b2Shape*)  cobj->Clone(arg0);
            object_to_luaval<b2Shape>(tolua_S, "b2Shape",(b2Shape*)ret);

            return 1;
        }
    }while(0);
   
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_LuaBox2D_b2Shape_Clone00",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2Shape_Clone00'.",&tolua_err);
    return 0;
#endif
}

//function of GetType b2Shape
int tolua_LuaBox2D_b2Shape_GetType00(lua_State* tolua_S){
    int argc = 0;
    b2Shape* cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2Shape", 0, &tolua_err)) goto tolua_lerror;
#endif

    cobj = (b2Shape*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_LuaBox2D_b2Shape_GetType00'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do{
        if (0 == argc)
        {
            b2Shape::Type ret = (b2Shape::Type)  cobj->GetType();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
   
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_LuaBox2D_b2Shape_GetType00",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2Shape_GetType00'.",&tolua_err);
    return 0;
#endif
}

//function of GetChildCount b2Shape
int tolua_LuaBox2D_b2Shape_GetChildCount00(lua_State* tolua_S){
    int argc = 0;
    b2Shape* cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2Shape", 0, &tolua_err)) goto tolua_lerror;
#endif

    cobj = (b2Shape*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_LuaBox2D_b2Shape_GetChildCount00'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do{
        if (0 == argc)
        {
            signed int ret = (signed int)  cobj->GetChildCount();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
   
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_LuaBox2D_b2Shape_GetChildCount00",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2Shape_GetChildCount00'.",&tolua_err);
    return 0;
#endif
}

//function of TestPoint b2Shape
int tolua_LuaBox2D_b2Shape_TestPoint00(lua_State* tolua_S){
    int argc = 0;
    b2Shape* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2Shape", 0, &tolua_err)) goto tolua_lerror;
#endif

    cobj = (b2Shape*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_LuaBox2D_b2Shape_TestPoint00'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do{
        if (2 == argc)
        {
            b2Transform* arg0;
            ok &= luaval_to_object<b2Transform>(tolua_S, 2, "b2Transform",&arg0);
            if (!ok) { break; }

            b2Vec2* arg1;
            ok &= luaval_to_object<b2Vec2>(tolua_S, 3, "b2Vec2",&arg1);
            if (!ok) { break; }
            
            bool ret = (bool)  cobj->TestPoint(*arg0,*arg1);
            tolua_pushboolean(tolua_S,(bool)ret);

            return 1;
        }
    }while(0);
   
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_LuaBox2D_b2Shape_TestPoint00",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2Shape_TestPoint00'.",&tolua_err);
    return 0;
#endif
}

//function of RayCast b2Shape
int tolua_LuaBox2D_b2Shape_RayCast00(lua_State* tolua_S){
    int argc = 0;
    b2Shape* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2Shape", 0, &tolua_err)) goto tolua_lerror;
#endif

    cobj = (b2Shape*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_LuaBox2D_b2Shape_RayCast00'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do{
        if (4 == argc)
        {
            b2RayCastOutput* arg0;
            ok &= luaval_to_object<b2RayCastOutput>(tolua_S, 2, "b2RayCastOutput",&arg0);
            if (!ok) { break; }

            b2RayCastInput* arg1;
            ok &= luaval_to_object<b2RayCastInput>(tolua_S, 3, "b2RayCastInput",&arg1);
            if (!ok) { break; }

            b2Transform* arg2;
            ok &= luaval_to_object<b2Transform>(tolua_S, 4, "b2Transform",&arg2);
            if (!ok) { break; }

            signed int arg3;
            ok &= luaval_to_int32(tolua_S, 5,(int *)&arg3, "b2Shape:RayCast");
            if (!ok) { break; }

            bool ret = (bool)  cobj->RayCast(arg0,*arg1,*arg2,arg3);
            tolua_pushboolean(tolua_S,(bool)ret);

            return 1;
        }
    }while(0);
   
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_LuaBox2D_b2Shape_RayCast00",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2Shape_RayCast00'.",&tolua_err);
    return 0;
#endif
}

//function of ComputeAABB b2Shape
int tolua_LuaBox2D_b2Shape_ComputeAABB00(lua_State* tolua_S){
    int argc = 0;
    b2Shape* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2Shape", 0, &tolua_err)) goto tolua_lerror;
#endif

    cobj = (b2Shape*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_LuaBox2D_b2Shape_ComputeAABB00'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do{
        if (3 == argc)
        {
            b2AABB* arg0;
            ok &= luaval_to_object<b2AABB>(tolua_S, 2, "b2AABB",&arg0);
            if (!ok) { break; }

            b2Transform* arg1;
            ok &= luaval_to_object<b2Transform>(tolua_S, 3, "b2Transform",&arg1);
            if (!ok) { break; }

            signed int arg2;
            ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "b2Shape:ComputeAABB");
            if (!ok) { break; }

            cobj->ComputeAABB(arg0,*arg1,arg2);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
   
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_LuaBox2D_b2Shape_ComputeAABB00",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2Shape_ComputeAABB00'.",&tolua_err);
    return 0;
#endif
}

//function of ComputeMass b2Shape
int tolua_LuaBox2D_b2Shape_ComputeMass00(lua_State* tolua_S){
    int argc = 0;
    b2Shape* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2Shape", 0, &tolua_err)) goto tolua_lerror;
#endif

    cobj = (b2Shape*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_LuaBox2D_b2Shape_ComputeMass00'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do{
        if (2 == argc)
        {
            b2MassData* arg0;
            ok &= luaval_to_object<b2MassData>(tolua_S, 2, "b2MassData",&arg0);
            if (!ok) { break; }

            double arg1;
            ok &= luaval_to_number(tolua_S, 3,&arg1, "b2Shape:ComputeMass");
            if (!ok) { break; }

            cobj->ComputeMass(arg0,arg1);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
   
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_LuaBox2D_b2Shape_ComputeMass00",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2Shape_ComputeMass00'.",&tolua_err);
    return 0;
#endif
}

/* get function: m_type of class  b2Shape */
static int tolua_get_b2Shape_m_type(lua_State* tolua_S)
{
    b2Shape* cobj = nullptr;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"b2Shape",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (b2Shape*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (nullptr == cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_get_b2Shape_m_type'", nullptr);
        return 0;
    }
#endif
    tolua_pushnumber(tolua_S,(lua_Number)cobj->m_type);
    return 1;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_get_b2Shape_m_type'.",&tolua_err);
    return 0;
#endif
}

/* set function: m_type of class  b2Shape */
static int tolua_set_b2Shape_m_type(lua_State* tolua_S)
{
    int argc = 0;
    b2Shape* cobj = nullptr;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"b2Shape",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (b2Shape*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (nullptr == cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_set_b2Shape_m_type'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (1 == argc)
    {
#if COCOS2D_DEBUG >= 1
        if (!tolua_isnumber(tolua_S, 2, 0, &tolua_err))
            goto tolua_lerror;
#endif
        cobj->m_type = ((b2Shape::Type) (int) tolua_tonumber(tolua_S,2,0));
        return 0;
    }

    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_set_b2Shape_m_type'.",&tolua_err);
    return 0;
#endif
}

/* get function: m_radius of class  b2Shape */
static int tolua_get_b2Shape_m_radius(lua_State* tolua_S)
{
    b2Shape* cobj = nullptr;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"b2Shape",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (b2Shape*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (nullptr == cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_get_b2Shape_m_radius'", nullptr);
        return 0;
    }
#endif
    tolua_pushnumber(tolua_S,(lua_Number)cobj->m_radius);
    return 1;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_get_b2Shape_m_radius'.",&tolua_err);
    return 0;
#endif
}

/* set function: m_radius of class  b2Shape */
static int tolua_set_b2Shape_m_radius(lua_State* tolua_S)
{
    int argc = 0;
    b2Shape* cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"b2Shape",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (b2Shape*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (nullptr == cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_LuaBox2D_b2Shape_TestPoint00'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (1 == argc)
    {
#if COCOS2D_DEBUG >= 1
        if (!tolua_isnumber(tolua_S, 2, 0, &tolua_err))
            goto tolua_lerror;
#endif
        cobj->m_radius = ((float)tolua_tonumber(tolua_S,2,0));
        return 0;
    }

    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2Shape_TestPoint00'.",&tolua_err);
    return 0;
#endif
}

int lua_register_cocos2dx_b2Shape(lua_State* tolua_S)
{
    tolua_usertype(tolua_S, "b2Shape");
    tolua_cclass(tolua_S, "b2Shape", "b2Shape", "",nullptr);
    tolua_beginmodule(tolua_S, "b2Shape");
        tolua_constant(tolua_S,"e_circle",b2Shape::e_circle);
        tolua_constant(tolua_S,"e_edge",b2Shape::e_edge);
        tolua_constant(tolua_S,"e_polygon",b2Shape::e_polygon);
        tolua_constant(tolua_S,"e_chain",b2Shape::e_chain);
        tolua_constant(tolua_S,"e_typeCount",b2Shape::e_typeCount);
        tolua_function(tolua_S,"delete",tolua_LuaBox2D_b2Shape_delete00);
        tolua_function(tolua_S,"Clone",tolua_LuaBox2D_b2Shape_Clone00);
        tolua_function(tolua_S,"GetType",tolua_LuaBox2D_b2Shape_GetType00);
        tolua_function(tolua_S,"GetChildCount",tolua_LuaBox2D_b2Shape_GetChildCount00);
        tolua_function(tolua_S,"TestPoint",tolua_LuaBox2D_b2Shape_TestPoint00);
        tolua_function(tolua_S,"RayCast",tolua_LuaBox2D_b2Shape_RayCast00);
        tolua_function(tolua_S,"ComputeAABB",tolua_LuaBox2D_b2Shape_ComputeAABB00);
        tolua_function(tolua_S,"ComputeMass",tolua_LuaBox2D_b2Shape_ComputeMass00);
        tolua_variable(tolua_S,"m_type",tolua_get_b2Shape_m_type,tolua_set_b2Shape_m_type);
        tolua_variable(tolua_S,"m_radius",tolua_get_b2Shape_m_radius,tolua_set_b2Shape_m_radius);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(b2Shape).name();
    g_luaType[typeName] = "b2Shape";
    g_typeCast["b2Shape"] = "b2Shape";
    return 1;
}

/* class of b2CircleShape */
//function of new b2CircleShape
int tolua_LuaBox2D_b2CircleShape_new00_local(lua_State* tolua_S)
{
    int argc = 0;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"b2CircleShape",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S)-1;

    do
    {
        if (argc == 0)
        {
            b2CircleShape* ret = (b2CircleShape*)  Mtolua_new((b2CircleShape)());
            object_to_luaval<b2CircleShape>(tolua_S, "b2CircleShape",(b2CircleShape*)ret);
            tolua_register_gc(tolua_S,lua_gettop(tolua_S));
            return 1;
        }
    } while (0);
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d", "tolua_LuaBox2D_b2CircleShape_new00_local",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2CircleShape_new00_local'.",&tolua_err);
#endif
    return 0;
}

//function of GetSupport b2CircleShape
int tolua_LuaBox2D_b2CircleShape_GetSupport00(lua_State* tolua_S){
    int argc = 0;
    b2CircleShape* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2CircleShape", 0, &tolua_err)) goto tolua_lerror;
#endif

    cobj = (b2CircleShape*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_LuaBox2D_b2CircleShape_GetSupport00'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do{
        if (1 == argc)
        {
            b2Vec2* arg0;
            ok &= luaval_to_object<b2Vec2>(tolua_S, 2, "b2Vec2",&arg0);
            if (!ok) { break; }

            int32 ret = (int32)  cobj->GetSupport(*arg0);
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
   
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_LuaBox2D_b2CircleShape_GetSupport00",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2CircleShape_GetSupport00'.",&tolua_err);
    return 0;
#endif
}

//function of GetSupportVertex b2CircleShape
int tolua_LuaBox2D_b2CircleShape_GetSupportVertex00(lua_State* tolua_S){
    int argc = 0;
    b2CircleShape* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2CircleShape", 0, &tolua_err)) goto tolua_lerror;
#endif

    cobj = (b2CircleShape*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_LuaBox2D_b2CircleShape_GetSupportVertex00'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do{
        if (1 == argc)
        {
            b2Vec2* arg0;
            ok &= luaval_to_object<b2Vec2>(tolua_S, 2, "b2Vec2",&arg0);
            if (!ok) { break; }

            const b2Vec2& ret = (const b2Vec2&)  cobj->GetSupportVertex(*arg0);
            object_to_luaval<b2Vec2>(tolua_S, "b2Vec2",(b2Vec2*)&ret);

            return 1;
        }
    }while(0);
   
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_LuaBox2D_b2CircleShape_GetSupportVertex00",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2CircleShape_GetSupportVertex00'.",&tolua_err);
    return 0;
#endif
}

//function of GetVertexCount b2CircleShape
int tolua_LuaBox2D_b2CircleShape_GetVertexCount00(lua_State* tolua_S){
    int argc = 0;
    b2CircleShape* cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2CircleShape", 0, &tolua_err)) goto tolua_lerror;
#endif

    cobj = (b2CircleShape*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_LuaBox2D_b2CircleShape_GetVertexCount00'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do{
        if (0 == argc)
        {
            int32 ret = (int32)  cobj->GetVertexCount();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
   
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_LuaBox2D_b2CircleShape_GetVertexCount00",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2CircleShape_GetVertexCount00'.",&tolua_err);
    return 0;
#endif
}

//function of GetVertex b2CircleShape
int tolua_LuaBox2D_b2CircleShape_GetVertex00(lua_State* tolua_S){
    int argc = 0;
    b2CircleShape* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2CircleShape", 0, &tolua_err)) goto tolua_lerror;
#endif

    cobj = (b2CircleShape*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_LuaBox2D_b2CircleShape_GetVertex00'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do{
        if (1 == argc)
        {
            int arg0;
            ok &= luaval_to_int32(tolua_S, 2, &arg0, "tolua_LuaBox2D_b2CircleShape_GetVertex00");
            if (!ok) { break; }

            const b2Vec2& ret = (const b2Vec2&)  cobj->GetVertex(arg0);
            object_to_luaval<b2Vec2>(tolua_S, "b2Vec2",(b2Vec2*)&ret);

            return 1;
        }
    }while(0);
   
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_LuaBox2D_b2CircleShape_GetVertex00",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2CircleShape_GetVertex00'.",&tolua_err);
    return 0;
#endif
}

/* get function: m_p of class  b2CircleShape */
static int tolua_get_b2CircleShape_m_p(lua_State* tolua_S)
{
    b2CircleShape* cobj = nullptr;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"b2CircleShape",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (b2CircleShape*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (nullptr == cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_get_b2CircleShape_m_p'", nullptr);
        return 0;
    }
#endif

    object_to_luaval<b2Vec2>(tolua_S, "b2Vec2",(b2Vec2*)&(cobj->m_p));
    return 1;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_get_b2CircleShape_m_p'.",&tolua_err);
    return 0;
#endif
}

/* set function: m_p of class  b2CircleShape */
static int tolua_set_b2CircleShape_m_p(lua_State* tolua_S)
{
    int argc = 0;
    b2CircleShape* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"b2CircleShape",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (b2CircleShape*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (nullptr == cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_set_b2CircleShape_m_p'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S) - 1;

    do{
        if (1 == argc)
        {
            b2Vec2* arg0;
            ok &= luaval_to_object<b2Vec2>(tolua_S, 2, "b2Vec2",&arg0);
            if (!ok) break;
             
            cobj->m_p = *arg0;
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_set_b2CircleShape_m_p",argc, 1);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_set_b2CircleShape_m_p'.",&tolua_err);
    return 0;
#endif
}

int lua_register_cocos2dx_b2CircleShape(lua_State* tolua_S)
{
    tolua_usertype(tolua_S, "b2CircleShape");
    tolua_cclass(tolua_S, "b2CircleShape", "b2CircleShape", "b2Shape",nullptr);
    tolua_beginmodule(tolua_S, "b2CircleShape");
        tolua_function(tolua_S,"new",tolua_LuaBox2D_b2CircleShape_new00_local);
        tolua_function(tolua_S,".call",tolua_LuaBox2D_b2CircleShape_new00_local);
        tolua_function(tolua_S,"GetSupport",tolua_LuaBox2D_b2CircleShape_GetSupport00);
        tolua_function(tolua_S,"GetSupportVertex",tolua_LuaBox2D_b2CircleShape_GetSupportVertex00);
        tolua_function(tolua_S,"GetVertexCount",tolua_LuaBox2D_b2CircleShape_GetVertexCount00);
        tolua_function(tolua_S,"GetVertex",tolua_LuaBox2D_b2CircleShape_GetVertex00);
        tolua_variable(tolua_S,"m_p",tolua_get_b2CircleShape_m_p,tolua_set_b2CircleShape_m_p);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(b2CircleShape).name();
    g_luaType[typeName] = "b2CircleShape";
    g_typeCast["b2CircleShape"] = "b2CircleShape";
    return 1;
}

/* class of b2ChainShape */
//function of new b2ChainShape
int tolua_LuaBox2D_b2ChainShape_new00_local(lua_State* tolua_S)
{
    int argc = 0;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"b2ChainShape",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S)-1;

    do
    {
        if (argc == 0)
        {
            b2ChainShape* ret = (b2ChainShape*)  Mtolua_new((b2ChainShape)());
            object_to_luaval<b2ChainShape>(tolua_S, "b2ChainShape",(b2ChainShape*)ret);
            tolua_register_gc(tolua_S,lua_gettop(tolua_S));
            return 1;
        }
    } while (0);
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d", "tolua_LuaBox2D_b2ChainShape_new00_local",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2ChainShape_new00_local'.",&tolua_err);
#endif
    return 0;
}

//function of CreateLoop b2ChainShape
int tolua_LuaBox2D_b2ChainShape_CreateLoop00(lua_State* tolua_S){
    int argc = 0;
    b2ChainShape* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2ChainShape", 0, &tolua_err)) goto tolua_lerror;
#endif

    cobj = (b2ChainShape*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_LuaBox2D_b2ChainShape_CreateLoop00'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do{
        if (2 == argc)
        {
            b2Vec2* arg0;
            ok &= luaval_to_object<b2Vec2>(tolua_S, 2, "b2Vec2",&arg0);
            if (!ok) { break; }

            int arg1;
            ok &= luaval_to_int32(tolua_S, 3, &arg1, "tolua_LuaBox2D_b2ChainShape_CreateLoop00");
            if (!ok) { break; }

            cobj->CreateLoop(arg0,arg1);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
   
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_LuaBox2D_b2ChainShape_CreateLoop00",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2ChainShape_CreateLoop00'.",&tolua_err);
    return 0;
#endif
}

//function of CreateChain b2ChainShape
int tolua_LuaBox2D_b2ChainShape_CreateChain00(lua_State* tolua_S){
    int argc = 0;
    b2ChainShape* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2ChainShape", 0, &tolua_err)) goto tolua_lerror;
#endif

    cobj = (b2ChainShape*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_LuaBox2D_b2ChainShape_CreateChain00'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do{
        if (2 == argc)
        {
            b2Vec2* arg0;
            ok &= luaval_to_object<b2Vec2>(tolua_S, 2, "b2Vec2",&arg0);
            if (!ok) { break; }

            int arg1;
            ok &= luaval_to_int32(tolua_S, 3, &arg1, "tolua_LuaBox2D_b2ChainShape_CreateChain00");
            if (!ok) { break; }

            cobj->CreateChain(arg0,arg1);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
   
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_LuaBox2D_b2ChainShape_CreateChain00",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2ChainShape_CreateChain00'.",&tolua_err);
    return 0;
#endif
}

//function of SetPrevVertex b2ChainShape
int tolua_LuaBox2D_b2ChainShape_SetPrevVertex00(lua_State* tolua_S){
    int argc = 0;
    b2ChainShape* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2ChainShape", 0, &tolua_err)) goto tolua_lerror;
#endif

    cobj = (b2ChainShape*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_LuaBox2D_b2ChainShape_SetPrevVertex00'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do{
        if (1 == argc)
        {
            b2Vec2* arg0;
            ok &= luaval_to_object<b2Vec2>(tolua_S, 2, "b2Vec2",&arg0);
            if (!ok) { break; }

            cobj->SetPrevVertex(*arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
   
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_LuaBox2D_b2ChainShape_SetPrevVertex00",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2ChainShape_SetPrevVertex00'.",&tolua_err);
    return 0;
#endif
}

//function of SetNextVertex b2ChainShape
int tolua_LuaBox2D_b2ChainShape_SetNextVertex00(lua_State* tolua_S){
    int argc = 0;
    b2ChainShape* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2ChainShape", 0, &tolua_err)) goto tolua_lerror;
#endif

    cobj = (b2ChainShape*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_LuaBox2D_b2ChainShape_SetNextVertex00'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do{
        if (1 == argc)
        {
            b2Vec2* arg0;
            ok &= luaval_to_object<b2Vec2>(tolua_S, 2, "b2Vec2",&arg0);
            if (!ok) { break; }

            cobj->SetNextVertex(*arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
   
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_LuaBox2D_b2ChainShape_SetNextVertex00",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2ChainShape_SetNextVertex00'.",&tolua_err);
    return 0;
#endif
}

//function of GetChildEdge b2ChainShape
int tolua_LuaBox2D_b2ChainShape_GetChildEdge00(lua_State* tolua_S){
    int argc = 0;
    b2ChainShape* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2ChainShape", 0, &tolua_err)) goto tolua_lerror;
#endif

    cobj = (b2ChainShape*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_LuaBox2D_b2ChainShape_GetChildEdge00'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do{
        if (2 == argc)
        {
            b2EdgeShape* arg0;
            ok &= luaval_to_object<b2EdgeShape>(tolua_S, 2, "b2EdgeShape",&arg0);
            if (!ok) { break; }

            int arg1;
            ok &= luaval_to_int32(tolua_S, 3, &arg1, "tolua_LuaBox2D_b2ChainShape_GetChildEdge00");
            if (!ok) { break; }

            cobj->GetChildEdge(arg0,arg1);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
   
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_LuaBox2D_b2ChainShape_GetChildEdge00",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2ChainShape_GetChildEdge00'.",&tolua_err);
    return 0;
#endif
}

/* get function: m_vertices of class  b2ChainShape */
static int tolua_get_b2ChainShape_m_vertices(lua_State* tolua_S)
{
    b2ChainShape* cobj = nullptr;
    b2Vec2* inValue;
    std::vector<Vec2> outValue;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"b2ChainShape",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (b2ChainShape*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (nullptr == cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_get_b2ChainShape_m_vertices'", nullptr);
        return 0;
    }
#endif
    inValue = cobj->m_vertices;
    for (int32 i = 0; i < cobj->m_count; i++)
    {
        outValue.insert(outValue.end(), Vec2(inValue[i].x,inValue[i].y));
    }
    ccvector_vec2_to_luaval(tolua_S, outValue);

    return 1;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_get_b2ChainShape_m_vertices'.",&tolua_err);
    return 0;
#endif
}

/* set function: m_vertices of class  b2ChainShape */
static int tolua_set_b2ChainShape_m_vertices(lua_State* tolua_S)
{
    int argc = 0;
    b2ChainShape* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"b2ChainShape",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (b2ChainShape*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (nullptr == cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_set_b2ChainShape_m_vertices'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S) - 1;

    do{
        if (1 == argc)
        {
            b2Vec2* outValue = nullptr;
            std::vector<Vec2> inValue;
            ok &= luaval_to_std_vector_vec2(tolua_S,2,&inValue,"tolua_set_b2ChainShape_m_vertices");
            if (!ok) break;

            outValue = (b2Vec2*)b2Alloc((int32)inValue.size() * sizeof(b2Vec2));

            for (size_t i = 0; i < inValue.size(); i++)
            {
                outValue[i] = b2Vec2(inValue[i].x, inValue[i].y);
            }
            cobj->m_vertices = outValue;
            cobj->m_count = (int32)inValue.size();
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_set_b2ChainShape_m_vertices",argc, 1);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_set_b2ChainShape_m_vertices'.",&tolua_err);
    return 0;
#endif
}

/* get function: m_count of class  b2ChainShape */
static int tolua_get_b2ChainShape_m_count(lua_State* tolua_S)
{
    b2ChainShape* cobj = nullptr;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"b2ChainShape",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (b2ChainShape*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (nullptr == cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_get_b2ChainShape_m_count'", nullptr);
        return 0;
    }
#endif
    tolua_pushnumber(tolua_S,(lua_Number)cobj->m_count);
    return 1;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_get_b2ChainShape_m_count'.",&tolua_err);
    return 0;
#endif
}

/* set function: m_count of class  b2ChainShape */
static int tolua_set_b2ChainShape_m_count(lua_State* tolua_S)
{
    int argc = 0;
    b2ChainShape* cobj = nullptr;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"b2ChainShape",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (b2ChainShape*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (nullptr == cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_set_b2ChainShape_m_count'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (1 == argc)
    {
#if COCOS2D_DEBUG >= 1
        if (!tolua_isnumber(tolua_S, 2, 0, &tolua_err))
            goto tolua_lerror;
#endif
        cobj->m_count = (int32) tolua_tonumber(tolua_S,2,0);
        return 0;
    }

    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_set_b2ChainShape_m_count'.",&tolua_err);
    return 0;
#endif
}

/* get function: m_prevVertex of class  b2ChainShape */
static int tolua_get_b2ChainShape_m_prevVertex(lua_State* tolua_S)
{
    b2ChainShape* cobj = nullptr;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"b2ChainShape",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (b2ChainShape*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (nullptr == cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_get_b2ChainShape_m_prevVertex'", nullptr);
        return 0;
    }
#endif

    object_to_luaval<b2Vec2>(tolua_S, "b2Vec2",(b2Vec2*)&cobj->m_prevVertex);

    return 1;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_get_b2ChainShape_m_prevVertex'.",&tolua_err);
    return 0;
#endif
}

/* set function: m_prevVertex of class  b2ChainShape */
static int tolua_set_b2ChainShape_m_prevVertex(lua_State* tolua_S)
{
    int argc = 0;
    b2ChainShape* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"b2ChainShape",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (b2ChainShape*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (nullptr == cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_set_b2ChainShape_m_prevVertex'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S) - 1;

    do{
        if (1 == argc)
        {
            b2Vec2* arg0;
            ok &= luaval_to_object<b2Vec2>(tolua_S, 2, "b2Vec2",&arg0);
            if (!ok) break;
             
            cobj->m_prevVertex = *arg0;
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_set_b2ChainShape_m_prevVertex",argc, 1);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_set_b2ChainShape_m_prevVertex'.",&tolua_err);
    return 0;
#endif
}

/* get function: m_nextVertex of class  b2ChainShape */
static int tolua_get_b2ChainShape_m_nextVertex(lua_State* tolua_S)
{
    b2ChainShape* cobj = nullptr;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"b2ChainShape",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (b2ChainShape*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (nullptr == cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_get_b2ChainShape_m_nextVertex'", nullptr);
        return 0;
    }
#endif

    object_to_luaval<b2Vec2>(tolua_S, "b2Vec2",(b2Vec2*)&cobj->m_nextVertex);

    return 1;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_get_b2ChainShape_m_nextVertex'.",&tolua_err);
    return 0;
#endif
}

/* set function: m_nextVertex of class  b2ChainShape */
static int tolua_set_b2ChainShape_m_nextVertex(lua_State* tolua_S)
{
    int argc = 0;
    b2ChainShape* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"b2ChainShape",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (b2ChainShape*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (nullptr == cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_set_b2ChainShape_m_nextVertex'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S) - 1;

    do{
        if (1 == argc)
        {
            b2Vec2* arg0;
            ok &= luaval_to_object<b2Vec2>(tolua_S, 2, "b2Vec2",&arg0);
            if (!ok) break;
             
            cobj->m_nextVertex = *arg0;
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_set_b2ChainShape_m_nextVertex",argc, 1);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_set_b2ChainShape_m_nextVertex'.",&tolua_err);
    return 0;
#endif
}

/* get function: m_hasPrevVertex of class  b2ChainShape */
static int tolua_get_b2ChainShape_m_hasPrevVertex(lua_State* tolua_S)
{
    b2ChainShape* cobj = nullptr;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"b2ChainShape",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (b2ChainShape*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (nullptr == cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_get_b2ChainShape_m_hasPrevVertex'", nullptr);
        return 0;
    }
#endif
    tolua_pushboolean(tolua_S,(bool)cobj->m_hasPrevVertex);

    return 1;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_get_b2ChainShape_m_hasPrevVertex'.",&tolua_err);
    return 0;
#endif
}

/* set function: m_hasPrevVertex of class  b2ChainShape */
static int tolua_set_b2ChainShape_m_hasPrevVertex(lua_State* tolua_S)
{
    int argc = 0;
    b2ChainShape* cobj = nullptr;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"b2ChainShape",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (b2ChainShape*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (nullptr == cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_set_b2ChainShape_m_hasPrevVertex'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (1 == argc)
    {
#if COCOS2D_DEBUG >= 1
        if (!tolua_isboolean(tolua_S, 2, 0, &tolua_err))
            goto tolua_lerror;
#endif
        cobj->m_hasPrevVertex = (bool) tolua_toboolean(tolua_S,2,0);
        return 0;
    }

    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_set_b2ChainShape_m_hasPrevVertex'.",&tolua_err);
    return 0;
#endif
}

/* get function: m_hasNextVertex of class  b2ChainShape */
static int tolua_get_b2ChainShape_m_hasNextVertex(lua_State* tolua_S)
{
    b2ChainShape* cobj = nullptr;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"b2ChainShape",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (b2ChainShape*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (nullptr == cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_get_b2ChainShape_m_hasNextVertex'", nullptr);
        return 0;
    }
#endif
    tolua_pushboolean(tolua_S,(bool)cobj->m_hasNextVertex);

    return 1;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_get_b2ChainShape_m_hasNextVertex'.",&tolua_err);
    return 0;
#endif
}

/* set function: m_hasNextVertex of class  b2ChainShape */
static int tolua_set_b2ChainShape_m_hasNextVertex(lua_State* tolua_S)
{
    int argc = 0;
    b2ChainShape* cobj = nullptr;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"b2ChainShape",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (b2ChainShape*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (nullptr == cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_set_b2ChainShape_m_hasNextVertex'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (1 == argc)
    {
#if COCOS2D_DEBUG >= 1
        if (!tolua_isboolean(tolua_S, 2, 0, &tolua_err))
            goto tolua_lerror;
#endif
        cobj->m_hasNextVertex = (bool) tolua_toboolean(tolua_S,2,0);
        return 0;
    }

    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_set_b2ChainShape_m_hasNextVertex'.",&tolua_err);
    return 0;
#endif
}

int lua_register_cocos2dx_b2ChainShape(lua_State* tolua_S)
{
    tolua_usertype(tolua_S, "b2ChainShape");
    tolua_cclass(tolua_S, "b2ChainShape", "b2ChainShape", "b2Shape",nullptr);
    tolua_beginmodule(tolua_S, "b2ChainShape");
        tolua_function(tolua_S,"new",tolua_LuaBox2D_b2ChainShape_new00_local);
        tolua_function(tolua_S,".call",tolua_LuaBox2D_b2ChainShape_new00_local);
        tolua_function(tolua_S,"CreateLoop",tolua_LuaBox2D_b2ChainShape_CreateLoop00);
        tolua_function(tolua_S,"CreateChain",tolua_LuaBox2D_b2ChainShape_CreateChain00);
        tolua_function(tolua_S,"SetPrevVertex",tolua_LuaBox2D_b2ChainShape_SetPrevVertex00);
        tolua_function(tolua_S,"SetNextVertex",tolua_LuaBox2D_b2ChainShape_SetNextVertex00);
        tolua_function(tolua_S,"GetChildEdge",tolua_LuaBox2D_b2ChainShape_GetChildEdge00);
        tolua_variable(tolua_S,"m_vertices",tolua_get_b2ChainShape_m_vertices,tolua_set_b2ChainShape_m_vertices);
        tolua_variable(tolua_S,"m_count",tolua_get_b2ChainShape_m_count,tolua_set_b2ChainShape_m_count);
        tolua_variable(tolua_S,"m_prevVertex",tolua_get_b2ChainShape_m_prevVertex,tolua_set_b2ChainShape_m_prevVertex);
        tolua_variable(tolua_S,"m_nextVertex",tolua_get_b2ChainShape_m_nextVertex,tolua_set_b2ChainShape_m_nextVertex);
        tolua_variable(tolua_S,"m_hasPrevVertex",tolua_get_b2ChainShape_m_hasPrevVertex,tolua_set_b2ChainShape_m_hasPrevVertex);
        tolua_variable(tolua_S,"m_hasNextVertex",tolua_get_b2ChainShape_m_hasNextVertex,tolua_set_b2ChainShape_m_hasNextVertex);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(b2ChainShape).name();
    g_luaType[typeName] = "b2ChainShape";
    g_typeCast["b2ChainShape"] = "b2ChainShape";
    return 1;
}

/* class of b2EdgeShape */
//function of new b2EdgeShape
int tolua_LuaBox2D_b2EdgeShape_new00_local(lua_State* tolua_S)
{
    int argc = 0;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"b2EdgeShape",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S)-1;

    do
    {
        if (argc == 0)
        {
            b2EdgeShape* ret = (b2EdgeShape*)  Mtolua_new((b2EdgeShape)());
            object_to_luaval<b2EdgeShape>(tolua_S, "b2EdgeShape",(b2EdgeShape*)ret);
            tolua_register_gc(tolua_S,lua_gettop(tolua_S));
            return 1;
        }
    } while (0);
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d", "tolua_LuaBox2D_b2EdgeShape_new00_local",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2EdgeShape_new00_local'.",&tolua_err);
#endif
    return 0;
}

//function of Set b2EdgeShape
int tolua_LuaBox2D_b2EdgeShape_Set00(lua_State* tolua_S){
    int argc = 0;
    b2EdgeShape* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2EdgeShape", 0, &tolua_err)) goto tolua_lerror;
#endif

    cobj = (b2EdgeShape*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_LuaBox2D_b2EdgeShape_Set00'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do{
        if (2 == argc)
        {
            b2Vec2* arg0;
            ok &= luaval_to_object<b2Vec2>(tolua_S, 2, "b2Vec2",&arg0);
            if (!ok) { break; }

            b2Vec2* arg1;
            ok &= luaval_to_object<b2Vec2>(tolua_S, 3, "b2Vec2",&arg1);
            if (!ok) { break; }
            
            cobj->Set(*arg0,*arg1);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
   
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_LuaBox2D_b2EdgeShape_Set00",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2EdgeShape_Set00'.",&tolua_err);
    return 0;
#endif
}

/* get function: m_vertex0 of class  b2EdgeShape */
static int tolua_get_b2EdgeShape_m_vertex0(lua_State* tolua_S)
{
    b2EdgeShape* cobj = nullptr;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"b2EdgeShape",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (b2EdgeShape*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (nullptr == cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_get_b2EdgeShape_m_vertex0'", nullptr);
        return 0;
    }
#endif

    object_to_luaval<b2Vec2>(tolua_S, "b2Vec2",(b2Vec2*)&cobj->m_vertex0);

    return 1;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_get_b2EdgeShape_m_vertex0'.",&tolua_err);
    return 0;
#endif
}

/* set function: m_vertex0 of class  b2EdgeShape */
static int tolua_set_b2EdgeShape_m_vertex0(lua_State* tolua_S)
{
    int argc = 0;
    b2EdgeShape* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"b2EdgeShape",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (b2EdgeShape*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (nullptr == cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_set_b2EdgeShape_m_vertex0'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S) - 1;

    do{
        if (1 == argc)
        {
            b2Vec2* arg0;
            ok &= luaval_to_object<b2Vec2>(tolua_S, 2, "b2Vec2",&arg0);
            if (!ok) break;
             
            cobj->m_vertex0 = *arg0;
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_set_b2EdgeShape_m_vertex0",argc, 1);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_set_b2EdgeShape_m_vertex0'.",&tolua_err);
    return 0;
#endif
}

/* get function: m_vertex1 of class  b2EdgeShape */
static int tolua_get_b2EdgeShape_m_vertex1(lua_State* tolua_S)
{
    b2EdgeShape* cobj = nullptr;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"b2EdgeShape",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (b2EdgeShape*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (nullptr == cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_get_b2EdgeShape_m_vertex1'", nullptr);
        return 0;
    }
#endif

    object_to_luaval<b2Vec2>(tolua_S, "b2Vec2",(b2Vec2*)&cobj->m_vertex1);

    return 1;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_get_b2EdgeShape_m_vertex1'.",&tolua_err);
    return 0;
#endif
}

/* set function: m_vertex1 of class  b2EdgeShape */
static int tolua_set_b2EdgeShape_m_vertex1(lua_State* tolua_S)
{
    int argc = 0;
    b2EdgeShape* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"b2EdgeShape",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (b2EdgeShape*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (nullptr == cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_set_b2EdgeShape_m_vertex1'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S) - 1;

    do{
        if (1 == argc)
        {
            b2Vec2* arg0;
            ok &= luaval_to_object<b2Vec2>(tolua_S, 2, "b2Vec2",&arg0);
            if (!ok) break;
             
            cobj->m_vertex1 = *arg0;
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_set_b2EdgeShape_m_vertex1",argc, 1);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_set_b2EdgeShape_m_vertex1'.",&tolua_err);
    return 0;
#endif
}

/* get function: m_vertex2 of class  b2EdgeShape */
static int tolua_get_b2EdgeShape_m_vertex2(lua_State* tolua_S)
{
    b2EdgeShape* cobj = nullptr;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"b2EdgeShape",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (b2EdgeShape*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (nullptr == cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_get_b2EdgeShape_m_vertex2'", nullptr);
        return 0;
    }
#endif

    object_to_luaval<b2Vec2>(tolua_S, "b2Vec2",(b2Vec2*)&cobj->m_vertex2);

    return 1;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_get_b2EdgeShape_m_vertex2'.",&tolua_err);
    return 0;
#endif
}

/* set function: m_vertex2 of class  b2EdgeShape */
static int tolua_set_b2EdgeShape_m_vertex2(lua_State* tolua_S)
{
    int argc = 0;
    b2EdgeShape* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"b2EdgeShape",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (b2EdgeShape*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (nullptr == cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_set_b2EdgeShape_m_vertex2'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S) - 1;

    do{
        if (1 == argc)
        {
            b2Vec2* arg0;
            ok &= luaval_to_object<b2Vec2>(tolua_S, 2, "b2Vec2",&arg0);
            if (!ok) break;
             
            cobj->m_vertex2 = *arg0;
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_set_b2EdgeShape_m_vertex2",argc, 1);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_set_b2EdgeShape_m_vertex2'.",&tolua_err);
    return 0;
#endif
}

/* get function: m_vertex3 of class  b2EdgeShape */
static int tolua_get_b2EdgeShape_m_vertex3(lua_State* tolua_S)
{
    b2EdgeShape* cobj = nullptr;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"b2EdgeShape",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (b2EdgeShape*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (nullptr == cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_get_b2EdgeShape_m_vertex3'", nullptr);
        return 0;
    }
#endif

    object_to_luaval<b2Vec2>(tolua_S, "b2Vec2",(b2Vec2*)&cobj->m_vertex3);

    return 1;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_get_b2EdgeShape_m_vertex3'.",&tolua_err);
    return 0;
#endif
}

/* set function: m_vertex3 of class  b2EdgeShape */
static int tolua_set_b2EdgeShape_m_vertex3(lua_State* tolua_S)
{
    int argc = 0;
    b2EdgeShape* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"b2EdgeShape",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (b2EdgeShape*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (nullptr == cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_set_b2EdgeShape_m_vertex3'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S) - 1;

    do{
        if (1 == argc)
        {
            b2Vec2* arg0;
            ok &= luaval_to_object<b2Vec2>(tolua_S, 2, "b2Vec2",&arg0);
            if (!ok) break;
             
            cobj->m_vertex3 = *arg0;
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_set_b2EdgeShape_m_vertex3",argc, 1);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_set_b2EdgeShape_m_vertex3'.",&tolua_err);
    return 0;
#endif
}

/* get function: m_hasVertex0 of class  b2EdgeShape */
static int tolua_get_b2EdgeShape_m_hasVertex0(lua_State* tolua_S)
{
    b2EdgeShape* cobj = nullptr;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"b2EdgeShape",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (b2EdgeShape*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (nullptr == cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_get_b2EdgeShape_m_hasVertex0'", nullptr);
        return 0;
    }
#endif
    tolua_pushboolean(tolua_S,(bool)cobj->m_hasVertex0);

    return 1;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_get_b2EdgeShape_m_hasVertex0'.",&tolua_err);
    return 0;
#endif
}

/* set function: m_hasVertex0 of class  b2EdgeShape */
static int tolua_set_b2EdgeShape_m_hasVertex0(lua_State* tolua_S)
{
    int argc = 0;
    b2EdgeShape* cobj = nullptr;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"b2EdgeShape",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (b2EdgeShape*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (nullptr == cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_set_b2EdgeShape_m_hasVertex0'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (1 == argc)
    {
#if COCOS2D_DEBUG >= 1
        if (!tolua_isboolean(tolua_S, 2, 0, &tolua_err))
            goto tolua_lerror;
#endif
        cobj->m_hasVertex0 = (bool) tolua_toboolean(tolua_S,2,0);
        return 0;
    }

    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_set_b2EdgeShape_m_hasVertex0'.",&tolua_err);
    return 0;
#endif
}

/* get function: m_hasVertex3 of class  b2EdgeShape */
static int tolua_get_b2EdgeShape_m_hasVertex3(lua_State* tolua_S)
{
    b2EdgeShape* cobj = nullptr;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"b2EdgeShape",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (b2EdgeShape*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (nullptr == cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_get_b2EdgeShape_m_hasVertex3'", nullptr);
        return 0;
    }
#endif
    tolua_pushboolean(tolua_S,(bool)cobj->m_hasVertex3);

    return 1;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_get_b2EdgeShape_m_hasVertex3'.",&tolua_err);
    return 0;
#endif
}

/* set function: m_hasVertex3 of class  b2EdgeShape */
static int tolua_set_b2EdgeShape_m_hasVertex3(lua_State* tolua_S)
{
    int argc = 0;
    b2EdgeShape* cobj = nullptr;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"b2EdgeShape",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (b2EdgeShape*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (nullptr == cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_set_b2EdgeShape_m_hasVertex3'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (1 == argc)
    {
#if COCOS2D_DEBUG >= 1
        if (!tolua_isboolean(tolua_S, 2, 0, &tolua_err))
            goto tolua_lerror;
#endif
        cobj->m_hasVertex3 = (bool) tolua_toboolean(tolua_S,2,0);
        return 0;
    }

    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_set_b2EdgeShape_m_hasVertex3'.",&tolua_err);
    return 0;
#endif
}

int lua_register_cocos2dx_b2EdgeShape(lua_State* tolua_S)
{
    tolua_usertype(tolua_S, "b2EdgeShape");
    tolua_cclass(tolua_S, "b2EdgeShape", "b2EdgeShape", "b2Shape",nullptr);
    tolua_beginmodule(tolua_S, "b2EdgeShape");
        tolua_function(tolua_S,"new",tolua_LuaBox2D_b2EdgeShape_new00_local);
        tolua_function(tolua_S,".call",tolua_LuaBox2D_b2EdgeShape_new00_local);
        tolua_function(tolua_S,"Set",tolua_LuaBox2D_b2EdgeShape_Set00);
        tolua_variable(tolua_S,"m_vertex0",tolua_get_b2EdgeShape_m_vertex0,tolua_set_b2EdgeShape_m_vertex0);
        tolua_variable(tolua_S,"m_vertex1",tolua_get_b2EdgeShape_m_vertex1,tolua_set_b2EdgeShape_m_vertex1);
        tolua_variable(tolua_S,"m_vertex2",tolua_get_b2EdgeShape_m_vertex2,tolua_set_b2EdgeShape_m_vertex2);
        tolua_variable(tolua_S,"m_vertex3",tolua_get_b2EdgeShape_m_vertex3,tolua_set_b2EdgeShape_m_vertex3);
        tolua_variable(tolua_S,"m_hasVertex0",tolua_get_b2EdgeShape_m_hasVertex0,tolua_set_b2EdgeShape_m_hasVertex0);
        tolua_variable(tolua_S,"m_hasVertex3",tolua_get_b2EdgeShape_m_hasVertex3,tolua_set_b2EdgeShape_m_hasVertex3);
     tolua_endmodule(tolua_S);
    std::string typeName = typeid(b2EdgeShape).name();
    g_luaType[typeName] = "b2EdgeShape";
    g_typeCast["b2EdgeShape"] = "b2EdgeShape";
    return 1;
}

/* class of b2PolygonShape */
//function of new b2PolygonShape
int tolua_LuaBox2D_b2PolygonShape_new00_local(lua_State* tolua_S)
{
    int argc = 0;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"b2PolygonShape",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S)-1;

    do
    {
        if (argc == 0)
        {
            b2PolygonShape* ret = (b2PolygonShape*)  Mtolua_new((b2PolygonShape)());
            object_to_luaval<b2PolygonShape>(tolua_S, "b2PolygonShape",(b2PolygonShape*)ret);
            tolua_register_gc(tolua_S,lua_gettop(tolua_S));
            return 1;
        }
    } while (0);
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d", "tolua_LuaBox2D_b2PolygonShape_new00_local",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2PolygonShape_new00_local'.",&tolua_err);
#endif
    return 0;
}

//function of Set b2PolygonShape
int tolua_LuaBox2D_b2PolygonShape_Set00(lua_State* tolua_S){
    int argc = 0;
    b2PolygonShape* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2PolygonShape", 0, &tolua_err)) goto tolua_lerror;
#endif

    cobj = (b2PolygonShape*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_LuaBox2D_b2PolygonShape_Set00'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do{
        if (2 == argc)
        {
            const b2Vec2* arg0;
            ok &= luaval_to_object<const b2Vec2>(tolua_S, 2, "const b2Vec2", &arg0);
            if (!ok) { break; }


            int32 arg1;
            ok &= luaval_to_int32(tolua_S, 3,(int32 *)&arg1, "tolua_set_b2ChainShape_m_vertices");
            if (!ok) { break; }
            
            cobj->Set(arg0,arg1);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
   
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_LuaBox2D_b2PolygonShape_Set00",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2PolygonShape_Set00'.",&tolua_err);
    return 0;
#endif
}

//function of SetAsBox b2PolygonShape
int tolua_LuaBox2D_b2PolygonShape_SetAsBox00(lua_State* tolua_S){
    int argc = 0;
    b2PolygonShape* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2PolygonShape", 0, &tolua_err)) goto tolua_lerror;
#endif

    cobj = (b2PolygonShape*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_LuaBox2D_b2PolygonShape_SetAsBox00'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do{
        if (2 == argc)
        {
            double arg0;
            ok &= luaval_to_number(tolua_S, 2, &arg0, "tolua_LuaBox2D_b2PolygonShape_SetAsBox00");
            if (!ok) { break; }

            double arg1;
            ok &= luaval_to_number(tolua_S, 3, &arg1, "tolua_LuaBox2D_b2PolygonShape_SetAsBox00");
            if (!ok) { break; }
            

            cobj->SetAsBox(arg0,arg1);
            lua_settop(tolua_S, 1);
            return 1;
        }
        if (4 == argc)
        {
            double arg0;
            ok &= luaval_to_number(tolua_S, 2,&arg0, "tolua_LuaBox2D_b2PolygonShape_SetAsBox00");
            if (!ok) { break; }

            double arg1;
            ok &= luaval_to_number(tolua_S, 3,&arg1, "tolua_LuaBox2D_b2PolygonShape_SetAsBox00");
            if (!ok) { break; }
            
            b2Vec2* arg3;
            ok &= luaval_to_object<b2Vec2>(tolua_S, 4, "b2Vec2",&arg3);
            if (!ok) break;

            double arg4;
            ok &= luaval_to_number(tolua_S, 5,&arg4, "tolua_LuaBox2D_b2PolygonShape_SetAsBox00");
            if (!ok) { break; }
            
            cobj->SetAsBox(arg0,arg1,*arg3,arg4);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
   
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_LuaBox2D_b2PolygonShape_SetAsBox00",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2PolygonShape_SetAsBox00'.",&tolua_err);
    return 0;
#endif
}

//function of GetVertex b2PolygonShape
int tolua_LuaBox2D_b2PolygonShape_GetVertex00(lua_State* tolua_S){
    int argc = 0;
    b2PolygonShape* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2PolygonShape", 0, &tolua_err)) goto tolua_lerror;
#endif

    cobj = (b2PolygonShape*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_LuaBox2D_b2PolygonShape_GetVertex00'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do{
        if (1 == argc)
        {
            int arg0;
            ok &= luaval_to_int32(tolua_S, 2, &arg0, "tolua_LuaBox2D_b2PolygonShape_GetVertex00");
            if (!ok) { break; }

            const b2Vec2& ret = (const b2Vec2&)  cobj->GetVertex(arg0);
            object_to_luaval<b2Vec2>(tolua_S, "b2Vec2",(b2Vec2*)&ret);

            return 1;
        }
    }while(0);
   
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_LuaBox2D_b2PolygonShape_GetVertex00",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2PolygonShape_GetVertex00'.",&tolua_err);
    return 0;
#endif
}


/* get function: m_centroid of class  b2PolygonShape */
static int tolua_get_b2PolygonShape_m_centroid(lua_State* tolua_S)
{
    b2PolygonShape* cobj = nullptr;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"b2PolygonShape",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (b2PolygonShape*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (nullptr == cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_get_b2PolygonShape_m_centroid'", nullptr);
        return 0;
    }
#endif

    object_to_luaval<b2Vec2>(tolua_S, "b2Vec2",(b2Vec2*)&cobj->m_centroid);

    return 1;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_get_b2PolygonShape_m_centroid'.",&tolua_err);
    return 0;
#endif
}

/* set function: m_centroid of class  b2PolygonShape */
static int tolua_set_b2PolygonShape_m_centroid(lua_State* tolua_S)
{
    int argc = 0;
    b2PolygonShape* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"b2PolygonShape",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (b2PolygonShape*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (nullptr == cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_set_b2PolygonShape_m_centroid'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S) - 1;

    do{
        if (1 == argc)
        {
            b2Vec2* arg0;
            ok &= luaval_to_object<b2Vec2>(tolua_S, 2, "b2Vec2",&arg0);
            if (!ok) break;
             
            cobj->m_centroid = *arg0;
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_set_b2PolygonShape_m_centroid",argc, 1);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_set_b2PolygonShape_m_centroid'.",&tolua_err);
    return 0;
#endif
}

/* get function: m_vertices of class  b2PolygonShape */
static int tolua_get_b2PolygonShape_m_vertices(lua_State* tolua_S)
{
    b2PolygonShape* cobj = nullptr;
    b2Vec2* inValue;
    std::vector<Vec2> outValue;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"b2PolygonShape",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (b2PolygonShape*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (nullptr == cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_get_b2PolygonShape_m_vertices'", nullptr);
        return 0;
    }
#endif
    inValue = cobj->m_vertices;
    for (int32 i = 0; i < cobj->m_count; i++)
    {
        outValue.insert(outValue.end(), Vec2(inValue[i].x,inValue[i].y));
    }
    ccvector_vec2_to_luaval(tolua_S, outValue);

    return 1;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_get_b2PolygonShape_m_vertices'.",&tolua_err);
    return 0;
#endif
}

/* set function: m_vertices of class  b2PolygonShape */
static int tolua_set_b2PolygonShape_m_vertices(lua_State* tolua_S)
{
    int argc = 0;
    b2PolygonShape* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"b2PolygonShape",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (b2PolygonShape*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (nullptr == cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_set_b2PolygonShape_m_vertices'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S) - 1;

    do{
        if (1 == argc)
        {
            std::vector<Vec2> inValue;
            ok &= luaval_to_std_vector_vec2(tolua_S,2,&inValue,"tolua_set_b2PolygonShape_m_vertices");
            if (!ok) break;

            for (size_t i = 0; i < inValue.size(); i++)
            {
                cobj->m_vertices[i] = b2Vec2(inValue[i].x, inValue[i].y);
            }
            cobj->m_count = (int32)inValue.size();
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_set_b2PolygonShape_m_vertices",argc, 1);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_set_b2PolygonShape_m_vertices'.",&tolua_err);
    return 0;
#endif
}

/* get function: m_normals of class  b2PolygonShape */
static int tolua_get_b2PolygonShape_m_normals(lua_State* tolua_S)
{
    b2PolygonShape* cobj = nullptr;
    b2Vec2* inValue;
    std::vector<Vec2> outValue;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"b2PolygonShape",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (b2PolygonShape*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (nullptr == cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_get_b2PolygonShape_m_normals'", nullptr);
        return 0;
    }
#endif
    inValue = cobj->m_normals;
    for (int32 i = 0; i < cobj->m_count; i++)
    {
        outValue.insert(outValue.end(), Vec2(inValue[i].x,inValue[i].y));
    }
    ccvector_vec2_to_luaval(tolua_S, outValue);

    return 1;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_get_b2PolygonShape_m_normals'.",&tolua_err);
    return 0;
#endif
}

/* set function: m_normals of class  b2PolygonShape */
static int tolua_set_b2PolygonShape_m_normals(lua_State* tolua_S)
{
    int argc = 0;
    b2PolygonShape* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"b2PolygonShape",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (b2PolygonShape*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (nullptr == cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_set_b2PolygonShape_m_normals'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S) - 1;

    do{
        if (1 == argc)
        {
            std::vector<Vec2> inValue;
            ok &= luaval_to_std_vector_vec2(tolua_S,2,&inValue,"tolua_set_b2PolygonShape_m_normals");
            if (!ok) break;

            for (size_t i = 0; i < inValue.size(); i++)
            {
                cobj->m_normals[i] = b2Vec2(inValue[i].x, inValue[i].y);
            }
            cobj->m_count = (int32)inValue.size();
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_set_b2PolygonShape_m_normals",argc, 1);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_set_b2PolygonShape_m_normals'.",&tolua_err);
    return 0;
#endif
}

/* get function: m_count of class  b2PolygonShape */
static int tolua_get_b2PolygonShape_m_count(lua_State* tolua_S)
{
    b2PolygonShape* cobj = nullptr;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"b2PolygonShape",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (b2PolygonShape*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (nullptr == cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_get_b2PolygonShape_m_count'", nullptr);
        return 0;
    }
#endif
    tolua_pushnumber(tolua_S,(lua_Number)cobj->m_count);
    return 1;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_get_b2PolygonShape_m_count'.",&tolua_err);
    return 0;
#endif
}

/* set function: m_count of class  b2PolygonShape */
static int tolua_set_b2PolygonShape_m_count(lua_State* tolua_S)
{
    int argc = 0;
    b2PolygonShape* cobj = nullptr;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"b2PolygonShape",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (b2PolygonShape*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (nullptr == cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_set_b2PolygonShape_m_count'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (1 == argc)
    {
#if COCOS2D_DEBUG >= 1
        if (!tolua_isnumber(tolua_S, 2, 0, &tolua_err))
            goto tolua_lerror;
#endif
        cobj->m_count = (int32) tolua_tonumber(tolua_S,2,0);
        return 0;
    }

    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_set_b2PolygonShape_m_count'.",&tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_b2PolygonShape_GetVertexCount00(lua_State* tolua_S){
    int argc = 0;
    b2PolygonShape* cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2PolygonShape", 0, &tolua_err)) goto tolua_lerror;
#endif

    cobj = (b2PolygonShape*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_LuaBox2D_b2PolygonShape_GetVertexCount00'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do{
        if (0 == argc)
        {
            int32 ret = (int32)  cobj->GetVertexCount();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
   
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_LuaBox2D_b2PolygonShape_GetVertexCount00",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2PolygonShape_GetVertexCount00'.",&tolua_err);
    return 0;
#endif
}


int lua_register_cocos2dx_b2PolygonShape(lua_State* tolua_S)
{
    tolua_usertype(tolua_S, "b2PolygonShape");
    tolua_cclass(tolua_S, "b2PolygonShape", "b2PolygonShape", "b2Shape",nullptr);
    tolua_beginmodule(tolua_S, "b2PolygonShape");
        tolua_function(tolua_S,"new",tolua_LuaBox2D_b2PolygonShape_new00_local);
        tolua_function(tolua_S,".call",tolua_LuaBox2D_b2PolygonShape_new00_local);
        tolua_function(tolua_S,"Set",tolua_LuaBox2D_b2PolygonShape_Set00);
        tolua_function(tolua_S,"SetAsBox",tolua_LuaBox2D_b2PolygonShape_SetAsBox00);
        tolua_function(tolua_S,"GetVertex",tolua_LuaBox2D_b2PolygonShape_GetVertex00);
        tolua_function(tolua_S,"GetVertexCount",tolua_LuaBox2D_b2PolygonShape_GetVertexCount00);

        tolua_variable(tolua_S,"m_centroid",tolua_get_b2PolygonShape_m_centroid,tolua_set_b2PolygonShape_m_centroid);
        tolua_variable(tolua_S,"m_vertices",tolua_get_b2PolygonShape_m_vertices,tolua_set_b2PolygonShape_m_vertices);
        tolua_variable(tolua_S,"m_normals",tolua_get_b2PolygonShape_m_normals,tolua_set_b2PolygonShape_m_normals);
        tolua_variable(tolua_S,"m_count",tolua_get_b2PolygonShape_m_count,tolua_set_b2PolygonShape_m_count);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(b2PolygonShape).name();
    g_luaType[typeName] = "b2PolygonShape";
    g_typeCast["b2PolygonShape"] = "b2PolygonShape";
    return 1;
}

/* class of b2BlockAllocator */
//function of new b2BlockAllocator
int tolua_LuaBox2D_b2BlockAllocator_new00_local(lua_State* tolua_S)
{
    int argc = 0;
   
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"b2BlockAllocator",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S)-1;

    do
    {
        if (argc == 0)
        {
            b2BlockAllocator* ret = (b2BlockAllocator*)  Mtolua_new((b2BlockAllocator)());
            object_to_luaval<b2BlockAllocator>(tolua_S, "b2BlockAllocator",(b2BlockAllocator*)ret);
            tolua_register_gc(tolua_S,lua_gettop(tolua_S));
            return 1;
        }
    } while (0);
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d", "tolua_LuaBox2D_b2BlockAllocator_new00_local",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2BlockAllocator_new00_local'.",&tolua_err);
#endif
    return 0;
}

int tolua_LuaBox2D_b2BlockAllocator_delete00(lua_State* tolua_S){
    int argc = 0;
    b2BlockAllocator* cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2BlockAllocator", 0, &tolua_err)) goto tolua_lerror;
#endif

    cobj = (b2BlockAllocator*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_LuaBox2D_b2BlockAllocator_delete00'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do{
        if (0 == argc)
        {
            Mtolua_delete(cobj);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
   
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_LuaBox2D_b2BlockAllocator_delete00",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2BlockAllocator_delete00'.",&tolua_err);
    return 0;
#endif
}

//function of Allocate b2BlockAllocator
int tolua_LuaBox2D_b2BlockAllocator_Allocate00(lua_State* tolua_S){
    int argc = 0;
    b2BlockAllocator* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2BlockAllocator", 0, &tolua_err)) goto tolua_lerror;
#endif

    cobj = (b2BlockAllocator*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_LuaBox2D_b2BlockAllocator_Allocate00'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do{
        if (1 == argc)
        {
            int arg0;
            ok &= luaval_to_int32(tolua_S, 2, &arg0, "tolua_LuaBox2D_b2BlockAllocator_Allocate00");
            if (!ok) { break; }

            void* ret = (void*)  cobj->Allocate(arg0);
            tolua_pushuserdata(tolua_S,(void*)ret);
            return 1;
        }
    }while(0);
   
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_LuaBox2D_b2BlockAllocator_Allocate00",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2BlockAllocator_Allocate00'.",&tolua_err);
    return 0;
#endif
}

//function of Free b2BlockAllocator
int tolua_LuaBox2D_b2BlockAllocator_Free00(lua_State* tolua_S){
    int argc = 0;
    b2BlockAllocator* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2BlockAllocator", 0, &tolua_err)) goto tolua_lerror;
#endif

    cobj = (b2BlockAllocator*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_LuaBox2D_b2BlockAllocator_Free00'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do{
        if (2 == argc)
        {
            void* arg0 = ((void*)  tolua_touserdata(tolua_S,2,0));

            int arg1;
            ok &= luaval_to_int32(tolua_S, 3, &arg1, "tolua_LuaBox2D_b2BlockAllocator_Free00");
            if (!ok) { break; }

            cobj->Free(cobj,arg1);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
   
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_LuaBox2D_b2BlockAllocator_Free00",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2BlockAllocator_Free00'.",&tolua_err);
    return 0;
#endif
}

//function of Clear b2BlockAllocator
int tolua_LuaBox2D_b2BlockAllocator_Clear00(lua_State* tolua_S){
    int argc = 0;
    b2BlockAllocator* cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2BlockAllocator", 0, &tolua_err)) goto tolua_lerror;
#endif

    cobj = (b2BlockAllocator*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_LuaBox2D_b2BlockAllocator_Clear00'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do{
        if (0 == argc)
        {
            cobj->Clear();
            lua_settop(tolua_S, 1);
            
            return 1;
        }
    }while(0);
   
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_LuaBox2D_b2BlockAllocator_Clear00",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2BlockAllocator_Clear00'.",&tolua_err);
    return 0;
#endif
}

int lua_register_cocos2dx_b2BlockAllocator(lua_State* tolua_S)
{
    tolua_usertype(tolua_S, "b2BlockAllocator");
    tolua_cclass(tolua_S, "b2BlockAllocator", "b2BlockAllocator", "b2Shape",nullptr);
    tolua_beginmodule(tolua_S, "b2BlockAllocator");
        tolua_function(tolua_S,"new",tolua_LuaBox2D_b2BlockAllocator_new00_local);
        tolua_function(tolua_S,".call",tolua_LuaBox2D_b2BlockAllocator_new00_local);
        tolua_function(tolua_S,"delete",tolua_LuaBox2D_b2BlockAllocator_delete00);
        tolua_function(tolua_S,"Allocate",tolua_LuaBox2D_b2BlockAllocator_Allocate00);
        tolua_function(tolua_S,"Free",tolua_LuaBox2D_b2BlockAllocator_Free00);
        tolua_function(tolua_S,"Clear",tolua_LuaBox2D_b2BlockAllocator_Clear00);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(b2BlockAllocator).name();
    g_luaType[typeName] = "b2BlockAllocator";
    g_typeCast["b2BlockAllocator"] = "b2BlockAllocator";
    return 1;
}

/* class of b2Contact */
//function of GetManifold b2Contact
int tolua_LuaBox2D_b2Contact_GetManifold00(lua_State* tolua_S){
    int argc = 0;
    b2Contact* cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2Contact", 0, &tolua_err)) goto tolua_lerror;
#endif

    cobj = (b2Contact*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_LuaBox2D_b2Contact_GetManifold00'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do{
        if (0 == argc)
        {
            object_to_luaval<b2Manifold>(tolua_S, "b2Manifold",(b2Manifold*)cobj->GetManifold());

            return 1;
        }
    }while(0);
   
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_LuaBox2D_b2Contact_GetManifold00",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2Contact_GetManifold00'.",&tolua_err);
    return 0;
#endif
}

//function of GetWorldManifold b2Contact
int tolua_LuaBox2D_b2Contact_GetWorldManifold00(lua_State* tolua_S){
    int argc = 0;
    b2Contact* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
 
#endif

    cobj = (b2Contact*)tolua_tousertype(tolua_S, 1, 0);

    argc = lua_gettop(tolua_S) - 1;

    do{
        if (1 == argc)
        {
            b2WorldManifold* arg0;
            ok &= luaval_to_object<b2WorldManifold>(tolua_S, 2, "b2WorldManifold", &arg0);
            if (!ok) { break; }

            cobj->GetWorldManifold(arg0);
            lua_settop(tolua_S, 1);
            
            return 1;
        }
    }while(0);
   
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_LuaBox2D_b2Contact_GetWorldManifold00",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2Contact_GetWorldManifold00'.",&tolua_err);
    return 0;
#endif
}

//function of IsTouching b2Contact
int tolua_LuaBox2D_b2Contact_IsTouching00(lua_State* tolua_S){
    int argc = 0;
    b2Contact* cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2Contact", 0, &tolua_err)) goto tolua_lerror;
#endif

    cobj = (b2Contact*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_LuaBox2D_b2Contact_IsTouching00'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do{
        if (0 == argc)
        {
            bool ret = (bool)  cobj->IsTouching();
            tolua_pushboolean(tolua_S,(bool)ret);

            return 1;
        }
    }while(0);
   
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_LuaBox2D_b2Contact_IsTouching00",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2Contact_IsTouching00'.",&tolua_err);
    return 0;
#endif
}

//function of SetEnabled b2Contact
int tolua_LuaBox2D_b2Contact_SetEnabled00(lua_State* tolua_S){
    int argc = 0;
    b2Contact* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2Contact", 0, &tolua_err)) goto tolua_lerror;
#endif

    cobj = (b2Contact*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_LuaBox2D_b2Contact_SetEnabled00'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do{
        if (1 == argc)
        {
            bool arg0;
            ok &= luaval_to_boolean(tolua_S, 2,&arg0, "tolua_LuaBox2D_b2Contact_SetEnabled00");

            if (!ok) { break; }

            cobj->SetEnabled(arg0);
            lua_settop(tolua_S, 1);

            return 1;
        }
    }while(0);
   
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_LuaBox2D_b2Contact_SetEnabled00",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2Contact_SetEnabled00'.",&tolua_err);
    return 0;
#endif
}

//function of IsEnabled b2Contact
int tolua_LuaBox2D_b2Contact_IsEnabled00(lua_State* tolua_S){
    int argc = 0;
    b2Contact* cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2Contact", 0, &tolua_err)) goto tolua_lerror;
#endif

    cobj = (b2Contact*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_LuaBox2D_b2Contact_IsEnabled00'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do{
        if (0 == argc)
        {
            bool ret = (bool)  cobj->IsEnabled();
            tolua_pushboolean(tolua_S,(bool)ret);

            return 1;
        }
    }while(0);
   
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_LuaBox2D_b2Contact_IsEnabled00",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2Contact_IsEnabled00'.",&tolua_err);
    return 0;
#endif
}

//function of GetNext b2Contact
int tolua_LuaBox2D_b2Contact_GetNext00(lua_State* tolua_S){
    int argc = 0;
    b2Contact* cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2Contact", 0, &tolua_err)) goto tolua_lerror;
#endif

    cobj = (b2Contact*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_LuaBox2D_b2Contact_GetNext00'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do{
        if (0 == argc)
        {
            object_to_luaval<b2Contact>(tolua_S, "b2Contact",(b2Contact*)cobj->GetNext());

            return 1;
        }
    }while(0);
   
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_LuaBox2D_b2Contact_GetNext00",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2Contact_GetNext00'.",&tolua_err);
    return 0;
#endif
}

//function of GetFixtureA b2Contact
int tolua_LuaBox2D_b2Contact_GetFixtureA00(lua_State* tolua_S){
    int argc = 0;
    b2Contact* cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2Contact", 0, &tolua_err)) goto tolua_lerror;
#endif

    cobj = (b2Contact*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_LuaBox2D_b2Contact_GetFixtureA00'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do{
        if (0 == argc)
        {
            object_to_luaval<b2Fixture>(tolua_S, "b2Fixture",(b2Fixture*)cobj->GetFixtureA());

            return 1;
        }
    }while(0);
   
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_LuaBox2D_b2Contact_GetFixtureA00",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2Contact_GetFixtureA00'.",&tolua_err);
    return 0;
#endif
}

//function of GetChildIndexA b2Contact
int tolua_LuaBox2D_b2Contact_GetChildIndexA00(lua_State* tolua_S){
    int argc = 0;
    b2Contact* cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2Contact", 0, &tolua_err)) goto tolua_lerror;
#endif

    cobj = (b2Contact*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_LuaBox2D_b2Contact_GetChildIndexA00'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do{
        if (0 == argc)
        {
            int32 ret = (int32)  cobj->GetChildIndexA();
            tolua_pushnumber(tolua_S,(lua_Number)ret);

            return 1;
        }
    }while(0);
   
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_LuaBox2D_b2Contact_GetChildIndexA00",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2Contact_GetChildIndexA00'.",&tolua_err);
    return 0;
#endif
}

//function of GetFixtureB b2Contact
int tolua_LuaBox2D_b2Contact_GetFixtureB00(lua_State* tolua_S){
    int argc = 0;
    b2Contact* cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2Contact", 0, &tolua_err)) goto tolua_lerror;
#endif

    cobj = (b2Contact*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_LuaBox2D_b2Contact_GetFixtureB00'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do{
        if (0 == argc)
        {
            object_to_luaval<b2Fixture>(tolua_S, "b2Fixture",(b2Fixture*)cobj->GetFixtureB());

            return 1;
        }
    }while(0);
   
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_LuaBox2D_b2Contact_GetFixtureB00",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2Contact_GetFixtureB00'.",&tolua_err);
    return 0;
#endif
}

//function of GetChildIndexB b2Contact
int tolua_LuaBox2D_b2Contact_GetChildIndexB00(lua_State* tolua_S){
    int argc = 0;
    b2Contact* cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2Contact", 0, &tolua_err)) goto tolua_lerror;
#endif

    cobj = (b2Contact*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_LuaBox2D_b2Contact_GetChildIndexB00'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do{
        if (0 == argc)
        {
            int32 ret = (int32)  cobj->GetChildIndexB();
            tolua_pushnumber(tolua_S,(lua_Number)ret);

            return 1;
        }
    }while(0);
   
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_LuaBox2D_b2Contact_GetChildIndexB00",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2Contact_GetChildIndexB00'.",&tolua_err);
    return 0;
#endif
}

//function of SetFriction b2Contact
int tolua_LuaBox2D_b2Contact_SetFriction00(lua_State* tolua_S){
    int argc = 0;
    b2Contact* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2Contact", 0, &tolua_err)) goto tolua_lerror;
#endif

    cobj = (b2Contact*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_LuaBox2D_b2Contact_SetFriction00'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do{
        if (1 == argc)
        {
            double arg0;
            ok &= luaval_to_number(tolua_S, 2,&arg0, "tolua_LuaBox2D_b2Contact_SetFriction00");

            cobj->SetFriction((float32)arg0);
            lua_settop(tolua_S, 1);

            return 1;
        }
    }while(0);
   
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_LuaBox2D_b2Contact_SetFriction00",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2Contact_SetFriction00'.",&tolua_err);
    return 0;
#endif
}

//function of GetFriction b2Contact
int tolua_LuaBox2D_b2Contact_GetFriction00(lua_State* tolua_S){
    int argc = 0;
    b2Contact* cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2Contact", 0, &tolua_err)) goto tolua_lerror;
#endif

    cobj = (b2Contact*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_LuaBox2D_b2Contact_GetFriction00'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do{
        if (0 == argc)
        {
            float32 ret = (float32)  cobj->GetFriction();
            tolua_pushnumber(tolua_S,(lua_Number)ret);

            return 1;
        }
    }while(0);
   
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_LuaBox2D_b2Contact_GetFriction00",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2Contact_GetFriction00'.",&tolua_err);
    return 0;
#endif
}

//function of ResetFriction b2Contact
int tolua_LuaBox2D_b2Contact_ResetFriction00(lua_State* tolua_S){
    int argc = 0;
    b2Contact* cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2Contact", 0, &tolua_err)) goto tolua_lerror;
#endif

    cobj = (b2Contact*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_LuaBox2D_b2Contact_ResetFriction00'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do{
        if (0 == argc)
        {
            cobj->ResetFriction();
            lua_settop(tolua_S, 1);
            
            return 1;
        }
    }while(0);
   
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_LuaBox2D_b2Contact_ResetFriction00",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2Contact_ResetFriction00'.",&tolua_err);
    return 0;
#endif
}

//function of SetRestitution b2Contact
int tolua_LuaBox2D_b2Contact_SetRestitution00(lua_State* tolua_S){
    int argc = 0;
    b2Contact* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2Contact", 0, &tolua_err)) goto tolua_lerror;
#endif

    cobj = (b2Contact*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_LuaBox2D_b2Contact_SetRestitution00'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do{
        if (1 == argc)
        {
            double arg0;
            ok &= luaval_to_number(tolua_S, 2,&arg0, "tolua_LuaBox2D_b2Contact_SetRestitution00");

            cobj->SetRestitution((float32)arg0);
            lua_settop(tolua_S, 1);

            return 1;
        }
    }while(0);
   
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_LuaBox2D_b2Contact_SetRestitution00",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2Contact_SetRestitution00'.",&tolua_err);
    return 0;
#endif
}

//function of GetRestitution b2Contact
int tolua_LuaBox2D_b2Contact_GetRestitution00(lua_State* tolua_S){
    int argc = 0;
    b2Contact* cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2Contact", 0, &tolua_err)) goto tolua_lerror;
#endif

    cobj = (b2Contact*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_LuaBox2D_b2Contact_GetRestitution00'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do{
        if (0 == argc)
        {
            float32 ret = (float32)  cobj->GetRestitution();
            tolua_pushnumber(tolua_S,(lua_Number)ret);

            return 1;
        }
    }while(0);
   
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_LuaBox2D_b2Contact_GetRestitution00",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2Contact_GetRestitution00'.",&tolua_err);
    return 0;
#endif
}

//function of ResetRestitution b2Contact
int tolua_LuaBox2D_b2Contact_ResetRestitution00(lua_State* tolua_S){
    int argc = 0;
    b2Contact* cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2Contact", 0, &tolua_err)) goto tolua_lerror;
#endif

    cobj = (b2Contact*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_LuaBox2D_b2Contact_ResetRestitution00'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do{
        if (0 == argc)
        {
            cobj->ResetRestitution();
            lua_settop(tolua_S, 1);
            
            return 1;
        }
    }while(0);
   
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_LuaBox2D_b2Contact_ResetRestitution00",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2Contact_ResetRestitution00'.",&tolua_err);
    return 0;
#endif
}

//function of Evaluate b2Contact
int tolua_LuaBox2D_b2Contact_Evaluate00(lua_State* tolua_S){
    int argc = 0;
    b2Contact* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2Contact", 0, &tolua_err)) goto tolua_lerror;
#endif

    cobj = (b2Contact*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_LuaBox2D_b2Contact_Evaluate00'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do{
        if (3 == argc)
        {
            b2Manifold* arg0;
            ok &= luaval_to_object<b2Manifold>(tolua_S, 2, "b2Manifold",&arg0);
            if (!ok) { break; }

            b2Transform* arg1;
            ok &= luaval_to_object<b2Transform>(tolua_S, 3, "b2Transform",&arg1);
            if (!ok) { break; }

            b2Transform* arg2;
            ok &= luaval_to_object<b2Transform>(tolua_S, 4, "b2Transform",&arg2);
            if (!ok) { break; }

            cobj->Evaluate(arg0,*arg1,*arg2);
            lua_settop(tolua_S, 1);

            return 1;
        }
    }while(0);
   
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_LuaBox2D_b2Contact_Evaluate00",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2Contact_Evaluate00'.",&tolua_err);
    return 0;
#endif
}

int lua_register_cocos2dx_b2Contact(lua_State* tolua_S)
{
    tolua_usertype(tolua_S, "b2Contact");
    tolua_cclass(tolua_S, "b2Contact", "b2Contact", "",nullptr);
    tolua_beginmodule(tolua_S, "b2Contact");
        tolua_function(tolua_S,"GetManifold",tolua_LuaBox2D_b2Contact_GetManifold00);
        tolua_function(tolua_S,"GetWorldManifold",tolua_LuaBox2D_b2Contact_GetWorldManifold00);
        tolua_function(tolua_S,"IsTouching",tolua_LuaBox2D_b2Contact_IsTouching00);
        tolua_function(tolua_S,"SetEnabled",tolua_LuaBox2D_b2Contact_SetEnabled00);
        tolua_function(tolua_S,"IsEnabled",tolua_LuaBox2D_b2Contact_IsEnabled00);
        tolua_function(tolua_S,"GetNext",tolua_LuaBox2D_b2Contact_GetNext00);
        tolua_function(tolua_S,"GetFixtureA",tolua_LuaBox2D_b2Contact_GetFixtureA00);
        tolua_function(tolua_S,"GetChildIndexA",tolua_LuaBox2D_b2Contact_GetChildIndexA00);
        tolua_function(tolua_S,"GetFixtureB",tolua_LuaBox2D_b2Contact_GetFixtureB00);
        tolua_function(tolua_S,"GetChildIndexB",tolua_LuaBox2D_b2Contact_GetChildIndexB00);
        tolua_function(tolua_S,"SetFriction",tolua_LuaBox2D_b2Contact_SetFriction00);
        tolua_function(tolua_S,"GetFriction",tolua_LuaBox2D_b2Contact_GetFriction00);
        tolua_function(tolua_S,"ResetFriction",tolua_LuaBox2D_b2Contact_ResetFriction00);
        tolua_function(tolua_S,"SetRestitution",tolua_LuaBox2D_b2Contact_SetRestitution00);
        tolua_function(tolua_S,"GetRestitution",tolua_LuaBox2D_b2Contact_GetRestitution00);
        tolua_function(tolua_S,"ResetRestitution",tolua_LuaBox2D_b2Contact_ResetRestitution00);
        tolua_function(tolua_S,"Evaluate",tolua_LuaBox2D_b2Contact_Evaluate00);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(b2Contact).name();
    g_luaType[typeName] = "b2Contact";
    g_typeCast["b2Contact"] = "b2Contact";
    return 1;
}

/* class of b2ContactListener */
//function of delete b2ContactListener
int tolua_LuaBox2D_b2ContactListener_delete00(lua_State* tolua_S){
    int argc = 0;
    b2ContactListener* cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2ContactListener", 0, &tolua_err)) goto tolua_lerror;
#endif

    cobj = (b2ContactListener*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_LuaBox2D_b2ContactListener_delete00'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do{
        if (0 == argc)
        {
            Mtolua_delete(cobj);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
   
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_LuaBox2D_b2ContactListener_delete00",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2ContactListener_delete00'.",&tolua_err);
    return 0;
#endif
}

//function of BeginContact b2ContactListener
int tolua_LuaBox2D_b2ContactListener_BeginContact00(lua_State* tolua_S){
    int argc = 0;
    b2ContactListener* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2ContactListener", 0, &tolua_err)) goto tolua_lerror;
#endif

    cobj = (b2ContactListener*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_LuaBox2D_b2ContactListener_BeginContact00'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do{
        if (1 == argc)
        {
            b2Contact* arg0;
            ok &= luaval_to_object<b2Contact>(tolua_S, 2, "b2Contact",&arg0);
            if (!ok) { break; }

            cobj->BeginContact(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
   
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_LuaBox2D_b2ContactListener_BeginContact00",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2ContactListener_BeginContact00'.",&tolua_err);
    return 0;
#endif
}

//function of EndContact b2ContactListener
int tolua_LuaBox2D_b2ContactListener_EndContact00(lua_State* tolua_S){
    int argc = 0;
    b2ContactListener* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2ContactListener", 0, &tolua_err)) goto tolua_lerror;
#endif

    cobj = (b2ContactListener*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_LuaBox2D_b2ContactListener_EndContact00'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do{
        if (1 == argc)
        {
            b2Contact* arg0;
            ok &= luaval_to_object<b2Contact>(tolua_S, 2, "b2Contact",&arg0);
            if (!ok) { break; }

            cobj->EndContact(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
   
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_LuaBox2D_b2ContactListener_EndContact00",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2ContactListener_EndContact00'.",&tolua_err);
    return 0;
#endif
}

//function of PreSolve b2ContactListener
int tolua_LuaBox2D_b2ContactListener_PreSolve00(lua_State* tolua_S){
    int argc = 0;
    b2ContactListener* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2ContactListener", 0, &tolua_err)) goto tolua_lerror;
#endif

    cobj = (b2ContactListener*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_LuaBox2D_b2ContactListener_PreSolve00'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do{
        if (2 == argc)
        {
            b2Contact* arg0;
            ok &= luaval_to_object<b2Contact>(tolua_S, 2, "b2Contact",&arg0);
            if (!ok) { break; }

            b2Manifold* arg1;
            ok &= luaval_to_object<b2Manifold>(tolua_S, 3, "b2Manifold",&arg1);
            if (!ok) { break; }

            cobj->PreSolve(arg0,arg1);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
   
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_LuaBox2D_b2ContactListener_PreSolve00",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2ContactListener_PreSolve00'.",&tolua_err);
    return 0;
#endif
}

//function of PostSolve b2ContactListener
int tolua_LuaBox2D_b2ContactListener_PostSolve00(lua_State* tolua_S){
    int argc = 0;
    b2ContactListener* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2ContactListener", 0, &tolua_err)) goto tolua_lerror;
#endif

    cobj = (b2ContactListener*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_LuaBox2D_b2ContactListener_PostSolve00'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do{
        if (2 == argc)
        {
            b2Contact* arg0;
            ok &= luaval_to_object<b2Contact>(tolua_S, 2, "b2Contact",&arg0);
            if (!ok) { break; }

            b2ContactImpulse* arg1;
            ok &= luaval_to_object<b2ContactImpulse>(tolua_S, 3, "b2ContactImpulse",&arg1);
            if (!ok) { break; }

            cobj->PostSolve(arg0,arg1);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
   
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_LuaBox2D_b2ContactListener_PostSolve00",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2ContactListener_PostSolve00'.",&tolua_err);
    return 0;
#endif
}

int lua_register_cocos2dx_b2ContactListener(lua_State* tolua_S)
{
    tolua_usertype(tolua_S, "b2ContactListener");
    tolua_cclass(tolua_S, "b2ContactListener", "b2ContactListener", "",nullptr);
    tolua_beginmodule(tolua_S, "b2ContactListener");
        tolua_function(tolua_S,"delete",tolua_LuaBox2D_b2ContactListener_delete00);
        tolua_function(tolua_S,"BeginContact",tolua_LuaBox2D_b2ContactListener_BeginContact00);
        tolua_function(tolua_S,"EndContact",tolua_LuaBox2D_b2ContactListener_EndContact00);
        tolua_function(tolua_S,"PreSolve",tolua_LuaBox2D_b2ContactListener_PreSolve00);
        tolua_function(tolua_S,"PostSolve",tolua_LuaBox2D_b2ContactListener_PostSolve00);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(b2ContactListener).name();
    g_luaType[typeName] = "b2ContactListener";
    g_typeCast["b2ContactListener"] = "b2ContactListener";
    return 1;
}

/* class of b2DistanceJointDef */
//function of new b2DistanceJointDef
int tolua_LuaBox2D_b2DistanceJointDef_new00_local(lua_State* tolua_S)
{
    int argc = 0;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"b2DistanceJointDef",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S)-1;

    do
    {
        if (argc == 0)
        {
            b2DistanceJointDef* ret = (b2DistanceJointDef*)  Mtolua_new((b2DistanceJointDef)());
            object_to_luaval<b2DistanceJointDef>(tolua_S, "b2DistanceJointDef",(b2DistanceJointDef*)ret);
            tolua_register_gc(tolua_S,lua_gettop(tolua_S));
            return 1;
        }
    } while (0);
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d", "tolua_LuaBox2D_b2DistanceJointDef_new00_local",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2DistanceJointDef_new00_local'.",&tolua_err);
#endif
    return 0;
}

//function of Initialize b2DistanceJointDef
int tolua_LuaBox2D_b2DistanceJointDef_Initialize00(lua_State* tolua_S){
    int argc = 0;
    b2DistanceJointDef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2DistanceJointDef", 0, &tolua_err)) goto tolua_lerror;
#endif

    cobj = (b2DistanceJointDef*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_LuaBox2D_b2DistanceJointDef_Initialize00'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do{
        if (4 == argc)
        {
            b2Body *arg0;
            ok &= luaval_to_object<b2Body>(tolua_S, 2, "b2Body", &arg0);
            if (!ok) { break; }

            b2Body *arg1;
            ok &= luaval_to_object<b2Body>(tolua_S, 3, "b2Body", &arg1);
            if (!ok) { break; }

            b2Vec2* arg2;
            ok &= luaval_to_object<b2Vec2>(tolua_S, 4, "b2Vec2",&arg2);
            if (!ok) break;

            b2Vec2* arg3;
            ok &= luaval_to_object<b2Vec2>(tolua_S, 5, "b2Vec2",&arg3);
            if (!ok) break;

            cobj->Initialize(arg0,arg1,*arg2,*arg3);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
   
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_LuaBox2D_b2DistanceJointDef_Initialize00",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2DistanceJointDef_Initialize00'.",&tolua_err);
    return 0;
#endif
}

/* get function: localAnchorA of class  b2DistanceJointDef */
static int tolua_get_b2DistanceJointDef_localAnchorA(lua_State* tolua_S)
{
    b2DistanceJointDef* cobj = nullptr;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"b2DistanceJointDef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (b2DistanceJointDef*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (nullptr == cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_get_b2DistanceJointDef_localAnchorA'", nullptr);
        return 0;
    }
#endif

    object_to_luaval<b2Vec2>(tolua_S, "b2Vec2",(b2Vec2*)&cobj->localAnchorA);

    return 1;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_get_b2DistanceJointDef_localAnchorA'.",&tolua_err);
    return 0;
#endif
}

/* set function: localAnchorA of class  b2DistanceJointDef */
static int tolua_set_b2DistanceJointDef_localAnchorA(lua_State* tolua_S)
{
    int argc = 0;
    b2DistanceJointDef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"b2DistanceJointDef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (b2DistanceJointDef*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (nullptr == cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_set_b2DistanceJointDef_localAnchorA'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S) - 1;

    do{
        if (1 == argc)
        {
            b2Vec2* arg0;
            ok &= luaval_to_object<b2Vec2>(tolua_S, 2, "b2Vec2",&arg0);
            if (!ok) break;
             
            cobj->localAnchorA = *arg0;
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_set_b2DistanceJointDef_localAnchorA",argc, 1);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_set_b2DistanceJointDef_localAnchorA'.",&tolua_err);
    return 0;
#endif
}

/* get function: localAnchorB of class  b2DistanceJointDef */
static int tolua_get_b2DistanceJointDef_localAnchorB(lua_State* tolua_S)
{
    b2DistanceJointDef* cobj = nullptr;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"b2DistanceJointDef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (b2DistanceJointDef*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (nullptr == cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_get_b2DistanceJointDef_localAnchorB'", nullptr);
        return 0;
    }
#endif

    object_to_luaval<b2Vec2>(tolua_S, "b2Vec2",(b2Vec2*)&cobj->localAnchorB);

    return 1;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_get_b2DistanceJointDef_localAnchorB'.",&tolua_err);
    return 0;
#endif
}

/* set function: localAnchorB of class  b2DistanceJointDef */
static int tolua_set_b2DistanceJointDef_localAnchorB(lua_State* tolua_S)
{
    int argc = 0;
    b2DistanceJointDef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"b2DistanceJointDef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (b2DistanceJointDef*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (nullptr == cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_set_b2DistanceJointDef_localAnchorB'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S) - 1;

    do{
        if (1 == argc)
        {
            b2Vec2* arg0;
            ok &= luaval_to_object<b2Vec2>(tolua_S, 2, "b2Vec2",&arg0);
            if (!ok) break;
             
            cobj->localAnchorB = *arg0;
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_set_b2DistanceJointDef_localAnchorB",argc, 1);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_set_b2DistanceJointDef_localAnchorB'.",&tolua_err);
    return 0;
#endif
}

/* get function: length of class  b2DistanceJointDef */
static int tolua_get_b2DistanceJointDef_length(lua_State* tolua_S)
{
    b2DistanceJointDef* cobj = nullptr;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"b2DistanceJointDef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (b2DistanceJointDef*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (nullptr == cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_get_b2DistanceJointDef_length'", nullptr);
        return 0;
    }
#endif
    tolua_pushnumber(tolua_S,(lua_Number)cobj->length);

    return 1;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_get_b2DistanceJointDef_length'.",&tolua_err);
    return 0;
#endif
}

/* set function: length of class  b2DistanceJointDef */
static int tolua_set_b2DistanceJointDef_length(lua_State* tolua_S)
{
    int argc = 0;
    b2DistanceJointDef* cobj = nullptr;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"b2DistanceJointDef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (b2DistanceJointDef*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (nullptr == cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_set_b2DistanceJointDef_length'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (1 == argc)
    {
#if COCOS2D_DEBUG >= 1
        if (!tolua_isnumber(tolua_S, 2, 0, &tolua_err))
            goto tolua_lerror;
#endif

        cobj->length = ((float32) tolua_tonumber(tolua_S,2,0));
        return 0;
    }

    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_set_b2DistanceJointDef_length'.",&tolua_err);
    return 0;
#endif
}

/* get function: frequencyHz of class  b2DistanceJointDef */
static int tolua_get_b2DistanceJointDef_frequencyHz(lua_State* tolua_S)
{
    b2DistanceJointDef* cobj = nullptr;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"b2DistanceJointDef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (b2DistanceJointDef*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (nullptr == cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_get_b2DistanceJointDef_frequencyHz'", nullptr);
        return 0;
    }
#endif
    tolua_pushnumber(tolua_S,(lua_Number)cobj->frequencyHz);

    return 1;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_get_b2DistanceJointDef_frequencyHz'.",&tolua_err);
    return 0;
#endif
}

/* set function: frequencyHz of class  b2DistanceJointDef */
static int tolua_set_b2DistanceJointDef_frequencyHz(lua_State* tolua_S)
{
    int argc = 0;
    b2DistanceJointDef* cobj = nullptr;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"b2DistanceJointDef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (b2DistanceJointDef*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (nullptr == cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_set_b2DistanceJointDef_frequencyHz'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (1 == argc)
    {
#if COCOS2D_DEBUG >= 1
        if (!tolua_isnumber(tolua_S, 2, 0, &tolua_err))
            goto tolua_lerror;
#endif

        cobj->frequencyHz = ((float32) tolua_tonumber(tolua_S,2,0));
        return 0;
    }

    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_set_b2DistanceJointDef_frequencyHz'.",&tolua_err);
    return 0;
#endif
}

/* get function: dampingRatio of class  b2DistanceJointDef */
static int tolua_get_b2DistanceJointDef_dampingRatio(lua_State* tolua_S)
{
    b2DistanceJointDef* cobj = nullptr;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"b2DistanceJointDef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (b2DistanceJointDef*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (nullptr == cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_get_b2DistanceJointDef_dampingRatio'", nullptr);
        return 0;
    }
#endif
    tolua_pushnumber(tolua_S,(lua_Number)cobj->dampingRatio);

    return 1;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_get_b2DistanceJointDef_dampingRatio'.",&tolua_err);
    return 0;
#endif
}

/* set function: dampingRatio of class  b2DistanceJointDef */
static int tolua_set_b2DistanceJointDef_dampingRatio(lua_State* tolua_S)
{
    int argc = 0;
    b2DistanceJointDef* cobj = nullptr;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"b2DistanceJointDef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (b2DistanceJointDef*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (nullptr == cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_set_b2DistanceJointDef_dampingRatio'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (1 == argc)
    {
#if COCOS2D_DEBUG >= 1
        if (!tolua_isnumber(tolua_S, 2, 0, &tolua_err))
            goto tolua_lerror;
#endif

        cobj->dampingRatio = ((float32) tolua_tonumber(tolua_S,2,0));
        return 0;
    }

    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_set_b2DistanceJointDef_dampingRatio'.",&tolua_err);
    return 0;
#endif
}

int lua_register_cocos2dx_b2DistanceJointDef(lua_State *tolua_S){
    tolua_usertype(tolua_S, "b2DistanceJointDef");
    tolua_cclass(tolua_S, "b2DistanceJointDef", "b2DistanceJointDef", "b2JointDef", nullptr);
    tolua_beginmodule(tolua_S, "b2DistanceJointDef");
        tolua_function(tolua_S,"new",tolua_LuaBox2D_b2DistanceJointDef_new00_local);
        tolua_function(tolua_S,".call",tolua_LuaBox2D_b2DistanceJointDef_new00_local);
        tolua_function(tolua_S,"Initialize",tolua_LuaBox2D_b2DistanceJointDef_Initialize00);
        tolua_variable(tolua_S,"localAnchorA",tolua_get_b2DistanceJointDef_localAnchorA,tolua_set_b2DistanceJointDef_localAnchorA);
        tolua_variable(tolua_S,"localAnchorB",tolua_get_b2DistanceJointDef_localAnchorB,tolua_set_b2DistanceJointDef_localAnchorB);
        tolua_variable(tolua_S,"length",tolua_get_b2DistanceJointDef_length,tolua_set_b2DistanceJointDef_length);
        tolua_variable(tolua_S,"frequencyHz",tolua_get_b2DistanceJointDef_frequencyHz,tolua_set_b2DistanceJointDef_frequencyHz);
        tolua_variable(tolua_S,"dampingRatio",tolua_get_b2DistanceJointDef_dampingRatio,tolua_set_b2DistanceJointDef_dampingRatio);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(b2DistanceJointDef).name();
    g_luaType[typeName] = "b2DistanceJointDef";
    g_typeCast["b2DistanceJointDef"] = "b2DistanceJointDef";
    return 1;  
}

/* class of b2DistanceJoint */
//function of GetAnchorA b2DistanceJoint
int tolua_LuaBox2D_b2DistanceJoint_GetAnchorA00(lua_State* tolua_S){
    int argc = 0;
    b2DistanceJoint* cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2DistanceJoint", 0, &tolua_err)) goto tolua_lerror;
#endif

    cobj = (b2DistanceJoint*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_LuaBox2D_b2DistanceJoint_GetAnchorA00'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do{
        if (0 == argc)
        {

            b2Vec2 newVec = cobj->GetAnchorA();
            // object_to_luaval<b2Vec2>(tolua_S, "b2Vec2",(b2Vec2*)&ret);
            b2Vec2 *ret = new b2Vec2(newVec.x, newVec.y);
            object_to_luaval(tolua_S, "b2Vec2", (b2Vec2 *)ret);
            tolua_register_gc(tolua_S, lua_gettop(tolua_S));
            
            return 1;
        }
    }while(0);
   
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_LuaBox2D_b2DistanceJoint_GetAnchorA00",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2DistanceJoint_GetAnchorA00'.",&tolua_err);
    return 0;
#endif
}

//function of GetAnchorB b2DistanceJoint
int tolua_LuaBox2D_b2DistanceJoint_GetAnchorB00(lua_State* tolua_S){
    int argc = 0;
    b2DistanceJoint* cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2DistanceJoint", 0, &tolua_err)) goto tolua_lerror;
#endif

    cobj = (b2DistanceJoint*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_LuaBox2D_b2DistanceJoint_GetAnchorB00'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do{
        if (0 == argc)
        {

            b2Vec2 newVec = cobj->GetAnchorB();
            // object_to_luaval<b2Vec2>(tolua_S, "b2Vec2",(b2Vec2*)&ret);
            b2Vec2 *ret = new b2Vec2(newVec.x, newVec.y);
            object_to_luaval(tolua_S, "b2Vec2", (b2Vec2 *)ret);
            tolua_register_gc(tolua_S, lua_gettop(tolua_S));
            return 1;
        }
    }while(0);
   
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_LuaBox2D_b2DistanceJoint_GetAnchorB00",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2DistanceJoint_GetAnchorB00'.",&tolua_err);
    return 0;
#endif
}

//function of GetReactionForce b2DistanceJoint
int tolua_LuaBox2D_b2DistanceJoint_GetReactionForce00(lua_State* tolua_S){
    int argc = 0;
    b2DistanceJoint* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2DistanceJoint", 0, &tolua_err)) goto tolua_lerror;
#endif

    cobj = (b2DistanceJoint*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_LuaBox2D_b2DistanceJoint_GetReactionForce00'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do{
        if (1 == argc)
        {
            double arg0;
            ok &= luaval_to_number(tolua_S, 2,&arg0, "tolua_LuaBox2D_b2DistanceJoint_GetReactionForce00");
            if (!ok) { break; }

            b2Vec2 newVec = cobj->GetReactionForce((float32)arg0);
            // object_to_luaval<b2Vec2>(tolua_S, "b2Vec2",(b2Vec2*)&ret);
            b2Vec2 *ret = new b2Vec2(newVec.x, newVec.y);
            object_to_luaval(tolua_S, "b2Vec2", (b2Vec2 *)ret);
            tolua_register_gc(tolua_S, lua_gettop(tolua_S));
            return 1;
        }
    }while(0);
   
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_LuaBox2D_b2DistanceJoint_GetReactionForce00",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2DistanceJoint_GetReactionForce00'.",&tolua_err);
    return 0;
#endif
}

//function of GetReactionTorque b2DistanceJoint
int tolua_LuaBox2D_b2DistanceJoint_GetReactionTorque00(lua_State* tolua_S){
    int argc = 0;
    b2DistanceJoint* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2DistanceJoint", 0, &tolua_err)) goto tolua_lerror;
#endif

    cobj = (b2DistanceJoint*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_LuaBox2D_b2DistanceJoint_GetReactionTorque00'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do{
        if (1 == argc)
        {
            double arg0;
            ok &= luaval_to_number(tolua_S, 2,&arg0, "tolua_LuaBox2D_b2DistanceJoint_GetReactionTorque00");
            if (!ok) { break; }

            float32 ret = cobj->GetReactionTorque((float32)arg0);
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            
            return 1;
        }
    }while(0);
   
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_LuaBox2D_b2DistanceJoint_GetReactionTorque00",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2DistanceJoint_GetReactionTorque00'.",&tolua_err);
    return 0;
#endif
}

//function of GetLocalAnchorA b2DistanceJoint
int tolua_LuaBox2D_b2DistanceJoint_GetLocalAnchorA00(lua_State* tolua_S){
    int argc = 0;
    b2DistanceJoint* cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2DistanceJoint", 0, &tolua_err)) goto tolua_lerror;
#endif

    cobj = (b2DistanceJoint*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_LuaBox2D_b2DistanceJoint_GetLocalAnchorA00'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do{
        if (0 == argc)
        {

            b2Vec2 newVec = cobj->GetLocalAnchorA();
            // object_to_luaval<b2Vec2>(tolua_S, "b2Vec2",(b2Vec2*)&ret);
            b2Vec2 *ret = new b2Vec2(newVec.x, newVec.y);
            object_to_luaval(tolua_S, "b2Vec2", (b2Vec2 *)ret);
            tolua_register_gc(tolua_S, lua_gettop(tolua_S));
            return 1;
        }
    }while(0);
   
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_LuaBox2D_b2DistanceJoint_GetLocalAnchorA00",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2DistanceJoint_GetLocalAnchorA00'.",&tolua_err);
    return 0;
#endif
}

//function of GetLocalAnchorB b2DistanceJoint
int tolua_LuaBox2D_b2DistanceJoint_GetLocalAnchorB00(lua_State* tolua_S){
    int argc = 0;
    b2DistanceJoint* cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2DistanceJoint", 0, &tolua_err)) goto tolua_lerror;
#endif

    cobj = (b2DistanceJoint*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_LuaBox2D_b2DistanceJoint_GetLocalAnchorB00'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do{
        if (0 == argc)
        {

            b2Vec2 newVec = cobj->GetLocalAnchorB();
            // object_to_luaval<b2Vec2>(tolua_S, "b2Vec2",(b2Vec2*)&ret);
            b2Vec2 *ret = new b2Vec2(newVec.x, newVec.y);
            object_to_luaval(tolua_S, "b2Vec2", (b2Vec2 *)ret);
            tolua_register_gc(tolua_S, lua_gettop(tolua_S));
            return 1;
        }
    }while(0);
   
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_LuaBox2D_b2DistanceJoint_GetLocalAnchorB00",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2DistanceJoint_GetLocalAnchorB00'.",&tolua_err);
    return 0;
#endif
}

//function of SetLength b2DistanceJoint
int tolua_LuaBox2D_b2DistanceJoint_SetLength00(lua_State* tolua_S){
    int argc = 0;
    b2DistanceJoint* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2DistanceJoint", 0, &tolua_err)) goto tolua_lerror;
#endif

    cobj = (b2DistanceJoint*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_LuaBox2D_b2DistanceJoint_SetLength00'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do{
        if (1 == argc)
        {
            double arg0;
            ok &= luaval_to_number(tolua_S, 2,&arg0, "tolua_LuaBox2D_b2DistanceJoint_SetLength00");
            if (!ok) { break; }

            cobj->SetLength((float32)arg0);
            lua_settop(tolua_S, 1);
            
            return 1;
        }
    }while(0);
   
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_LuaBox2D_b2DistanceJoint_SetLength00",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2DistanceJoint_SetLength00'.",&tolua_err);
    return 0;
#endif
}

//function of GetLength b2DistanceJoint
int tolua_LuaBox2D_b2DistanceJoint_GetLength00(lua_State* tolua_S){
    int argc = 0;
    b2DistanceJoint* cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2DistanceJoint", 0, &tolua_err)) goto tolua_lerror;
#endif

    cobj = (b2DistanceJoint*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_LuaBox2D_b2DistanceJoint_GetLength00'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do{
        if (0 == argc)
        {

            float32 ret = cobj->GetLength();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            
            return 1;
        }
    }while(0);
   
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_LuaBox2D_b2DistanceJoint_GetLength00",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2DistanceJoint_GetLength00'.",&tolua_err);
    return 0;
#endif
}

//function of SetFrequency b2DistanceJoint
int tolua_LuaBox2D_b2DistanceJoint_SetFrequency00(lua_State* tolua_S){
    int argc = 0;
    b2DistanceJoint* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2DistanceJoint", 0, &tolua_err)) goto tolua_lerror;
#endif

    cobj = (b2DistanceJoint*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_LuaBox2D_b2DistanceJoint_SetFrequency00'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do{
        if (1 == argc)
        {
            double arg0;
            ok &= luaval_to_number(tolua_S, 2,&arg0, "tolua_LuaBox2D_b2DistanceJoint_SetFrequency00");
            if (!ok) { break; }

            cobj->SetFrequency((float32)arg0);
            lua_settop(tolua_S, 1);
            
            return 1;
        }
    }while(0);
   
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_LuaBox2D_b2DistanceJoint_SetFrequency00",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2DistanceJoint_SetFrequency00'.",&tolua_err);
    return 0;
#endif
}

//function of GetFrequency b2DistanceJoint
int tolua_LuaBox2D_b2DistanceJoint_GetFrequency00(lua_State* tolua_S){
    int argc = 0;
    b2DistanceJoint* cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2DistanceJoint", 0, &tolua_err)) goto tolua_lerror;
#endif

    cobj = (b2DistanceJoint*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_LuaBox2D_b2DistanceJoint_GetFrequency00'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do{
        if (0 == argc)
        {

            float32 ret = cobj->GetFrequency();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            
            return 1;
        }
    }while(0);
   
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_LuaBox2D_b2DistanceJoint_GetFrequency00",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2DistanceJoint_GetFrequency00'.",&tolua_err);
    return 0;
#endif
}

//function of SetDampingRatio b2DistanceJoint
int tolua_LuaBox2D_b2DistanceJoint_SetDampingRatio00(lua_State* tolua_S){
    int argc = 0;
    b2DistanceJoint* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2DistanceJoint", 0, &tolua_err)) goto tolua_lerror;
#endif

    cobj = (b2DistanceJoint*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_LuaBox2D_b2DistanceJoint_SetDampingRatio00'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do{
        if (1 == argc)
        {
            double arg0;
            ok &= luaval_to_number(tolua_S, 2,&arg0, "tolua_LuaBox2D_b2DistanceJoint_SetDampingRatio00");
            if (!ok) { break; }

            cobj->SetDampingRatio((float32)arg0);
            lua_settop(tolua_S, 1);
            
            return 1;
        }
    }while(0);
   
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_LuaBox2D_b2DistanceJoint_SetDampingRatio00",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2DistanceJoint_SetDampingRatio00'.",&tolua_err);
    return 0;
#endif
}

//function of GetDampingRatio b2DistanceJoint
int tolua_LuaBox2D_b2DistanceJoint_GetDampingRatio00(lua_State* tolua_S){
    int argc = 0;
    b2DistanceJoint* cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2DistanceJoint", 0, &tolua_err)) goto tolua_lerror;
#endif

    cobj = (b2DistanceJoint*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_LuaBox2D_b2DistanceJoint_GetDampingRatio00'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do{
        if (0 == argc)
        {

            float32 ret = cobj->GetDampingRatio();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            
            return 1;
        }
    }while(0);
   
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_LuaBox2D_b2DistanceJoint_GetDampingRatio00",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2DistanceJoint_GetDampingRatio00'.",&tolua_err);
    return 0;
#endif
}

//function of Dump b2DistanceJoint
int tolua_LuaBox2D_b2DistanceJoint_Dump00(lua_State* tolua_S){
    int argc = 0;
    b2DistanceJoint* cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2DistanceJoint", 0, &tolua_err)) goto tolua_lerror;
#endif

    cobj = (b2DistanceJoint*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_LuaBox2D_b2DistanceJoint_Dump00'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do{
        if (0 == argc)
        {
            cobj->Dump();
            lua_settop(tolua_S, 1);
            
            return 1;
        }
    }while(0);
   
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_LuaBox2D_b2DistanceJoint_Dump00",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2DistanceJoint_Dump00'.",&tolua_err);
    return 0;
#endif
}

int lua_register_cocos2dx_b2DistanceJoint(lua_State* tolua_S)
{
    tolua_usertype(tolua_S, "b2DistanceJoint");
    tolua_cclass(tolua_S, "b2DistanceJoint", "b2DistanceJoint", "b2Joint",nullptr);
    tolua_beginmodule(tolua_S, "b2DistanceJoint");
        tolua_function(tolua_S,"GetAnchorA",tolua_LuaBox2D_b2DistanceJoint_GetAnchorA00);
        tolua_function(tolua_S,"GetAnchorB",tolua_LuaBox2D_b2DistanceJoint_GetAnchorB00);
        tolua_function(tolua_S,"GetReactionForce",tolua_LuaBox2D_b2DistanceJoint_GetReactionForce00);
        tolua_function(tolua_S,"GetReactionTorque",tolua_LuaBox2D_b2DistanceJoint_GetReactionTorque00);
        tolua_function(tolua_S,"GetLocalAnchorA",tolua_LuaBox2D_b2DistanceJoint_GetLocalAnchorA00);
        tolua_function(tolua_S,"GetLocalAnchorB",tolua_LuaBox2D_b2DistanceJoint_GetLocalAnchorB00);
        tolua_function(tolua_S,"SetLength",tolua_LuaBox2D_b2DistanceJoint_SetLength00);
        tolua_function(tolua_S,"GetLength",tolua_LuaBox2D_b2DistanceJoint_GetLength00);
        tolua_function(tolua_S,"SetFrequency",tolua_LuaBox2D_b2DistanceJoint_SetFrequency00);
        tolua_function(tolua_S,"GetFrequency",tolua_LuaBox2D_b2DistanceJoint_GetFrequency00);
        tolua_function(tolua_S,"SetDampingRatio",tolua_LuaBox2D_b2DistanceJoint_SetDampingRatio00);
        tolua_function(tolua_S,"GetDampingRatio",tolua_LuaBox2D_b2DistanceJoint_GetDampingRatio00);
        tolua_function(tolua_S,"Dump",tolua_LuaBox2D_b2DistanceJoint_Dump00);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(b2DistanceJoint).name();
    g_luaType[typeName] = "b2DistanceJoint";
    g_typeCast["b2DistanceJoint"] = "b2DistanceJoint";
    return 1;
}

/* class of b2MotorJointDef */
//function of new b2MotorJointDef
int tolua_LuaBox2D_b2MotorJointDef_new00_local(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"b2MotorJointDef",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S)-1;

    do
    {
        if (argc == 0)
        {
            b2MotorJointDef* ret = (b2MotorJointDef*)  Mtolua_new((b2MotorJointDef)());
            object_to_luaval<b2MotorJointDef>(tolua_S, "b2MotorJointDef",(b2MotorJointDef*)ret);
            tolua_register_gc(tolua_S,lua_gettop(tolua_S));
            return 1;
        }
    } while (0);
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d", "tolua_LuaBox2D_b2MotorJointDef_new00_local",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2MotorJointDef_new00_local'.",&tolua_err);
#endif
    return 0;
}

/* get function: linearOffset of class  b2MotorJointDef */
static int tolua_get_b2MotorJointDef_linearOffset(lua_State* tolua_S)
{
    b2MotorJointDef* cobj = nullptr;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"b2MotorJointDef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (b2MotorJointDef*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (nullptr == cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_get_b2MotorJointDef_linearOffset'", nullptr);
        return 0;
    }
#endif

    object_to_luaval<b2Vec2>(tolua_S, "b2Vec2",(b2Vec2*)&cobj->linearOffset);

    return 1;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_get_b2MotorJointDef_linearOffset'.",&tolua_err);
    return 0;
#endif
}

/* set function: linearOffset of class  b2MotorJointDef */
static int tolua_set_b2MotorJointDef_linearOffset(lua_State* tolua_S)
{
    int argc = 0;
    b2MotorJointDef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"b2MotorJointDef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (b2MotorJointDef*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (nullptr == cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_set_b2MotorJointDef_linearOffset'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S) - 1;

    do{
        if (1 == argc)
        {
            b2Vec2* arg0;
            ok &= luaval_to_object<b2Vec2>(tolua_S, 2, "b2Vec2",&arg0);
            if (!ok) break;
             
            cobj->linearOffset = *arg0;
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_set_b2MotorJointDef_linearOffset",argc, 1);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_set_b2MotorJointDef_linearOffset'.",&tolua_err);
    return 0;
#endif
}


/* get function: angularOffset of class  b2MotorJointDef */
static int tolua_get_b2MotorJointDef_angularOffset(lua_State* tolua_S)
{
    b2MotorJointDef* cobj = nullptr;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"b2MotorJointDef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (b2MotorJointDef*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (nullptr == cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_get_b2MotorJointDef_angularOffset'", nullptr);
        return 0;
    }
#endif
    tolua_pushnumber(tolua_S,(lua_Number)cobj->angularOffset);

    return 1;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_get_b2MotorJointDef_angularOffset'.",&tolua_err);
    return 0;
#endif
}

/* set function: angularOffset of class  b2MotorJointDef */
static int tolua_set_b2MotorJointDef_angularOffset(lua_State* tolua_S)
{
    int argc = 0;
    b2MotorJointDef* cobj = nullptr;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"b2MotorJointDef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (b2MotorJointDef*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (nullptr == cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_set_b2MotorJointDef_angularOffset'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (1 == argc)
    {
#if COCOS2D_DEBUG >= 1
        if (!tolua_isnumber(tolua_S, 2, 0, &tolua_err))
            goto tolua_lerror;
#endif

        cobj->angularOffset = ((float32) tolua_tonumber(tolua_S,2,0));
        return 0;
    }

    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_set_b2MotorJointDef_angularOffset'.",&tolua_err);
    return 0;
#endif
}


/* get function: maxForce of class  b2MotorJointDef */
static int tolua_get_b2MotorJointDef_maxForce(lua_State* tolua_S)
{
    b2MotorJointDef* cobj = nullptr;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"b2MotorJointDef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (b2MotorJointDef*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (nullptr == cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_get_b2MotorJointDef_maxForce'", nullptr);
        return 0;
    }
#endif
    tolua_pushnumber(tolua_S,(lua_Number)cobj->maxForce);

    return 1;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_get_b2MotorJointDef_maxForce'.",&tolua_err);
    return 0;
#endif
}

/* set function: maxForce of class  b2MotorJointDef */
static int tolua_set_b2MotorJointDef_maxForce(lua_State* tolua_S)
{
    int argc = 0;
    b2MotorJointDef* cobj = nullptr;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"b2MotorJointDef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (b2MotorJointDef*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (nullptr == cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_set_b2MotorJointDef_maxForce'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (1 == argc)
    {
#if COCOS2D_DEBUG >= 1
        if (!tolua_isnumber(tolua_S, 2, 0, &tolua_err))
            goto tolua_lerror;
#endif

        cobj->maxForce = ((float32) tolua_tonumber(tolua_S,2,0));
        return 0;
    }

    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_set_b2MotorJointDef_maxForce'.",&tolua_err);
    return 0;
#endif
}


/* get function: maxTorque of class  b2MotorJointDef */
static int tolua_get_b2MotorJointDef_maxTorque(lua_State* tolua_S)
{
    b2MotorJointDef* cobj = nullptr;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"b2MotorJointDef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (b2MotorJointDef*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (nullptr == cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_get_b2MotorJointDef_maxTorque'", nullptr);
        return 0;
    }
#endif
    tolua_pushnumber(tolua_S,(lua_Number)cobj->maxTorque);

    return 1;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_get_b2MotorJointDef_maxTorque'.",&tolua_err);
    return 0;
#endif
}

/* set function: maxTorque of class  b2MotorJointDef */
static int tolua_set_b2MotorJointDef_maxTorque(lua_State* tolua_S)
{
    int argc = 0;
    b2MotorJointDef* cobj = nullptr;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"b2MotorJointDef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (b2MotorJointDef*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (nullptr == cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_set_b2MotorJointDef_maxTorque'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (1 == argc)
    {
#if COCOS2D_DEBUG >= 1
        if (!tolua_isnumber(tolua_S, 2, 0, &tolua_err))
            goto tolua_lerror;
#endif

        cobj->maxTorque = ((float32) tolua_tonumber(tolua_S,2,0));
        return 0;
    }

    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_set_b2MotorJointDef_maxTorque'.",&tolua_err);
    return 0;
#endif
}


/* get function: correctionFactor of class  b2MotorJointDef */
static int tolua_get_b2MotorJointDef_correctionFactor(lua_State* tolua_S)
{
    b2MotorJointDef* cobj = nullptr;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"b2MotorJointDef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (b2MotorJointDef*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (nullptr == cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_get_b2MotorJointDef_correctionFactor'", nullptr);
        return 0;
    }
#endif
    tolua_pushnumber(tolua_S,(lua_Number)cobj->correctionFactor);

    return 1;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_get_b2MotorJointDef_correctionFactor'.",&tolua_err);
    return 0;
#endif
}

/* set function: correctionFactor of class  b2MotorJointDef */
static int tolua_set_b2MotorJointDef_correctionFactor(lua_State* tolua_S)
{
    int argc = 0;
    b2MotorJointDef* cobj = nullptr;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"b2MotorJointDef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (b2MotorJointDef*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (nullptr == cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_set_b2MotorJointDef_correctionFactor'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (1 == argc)
    {
#if COCOS2D_DEBUG >= 1
        if (!tolua_isnumber(tolua_S, 2, 0, &tolua_err))
            goto tolua_lerror;
#endif

        cobj->correctionFactor = ((float32) tolua_tonumber(tolua_S,2,0));
        return 0;
    }

    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_set_b2MotorJointDef_correctionFactor'.",&tolua_err);
    return 0;
#endif
}

int lua_register_cocos2dx_b2MotorJointDef(lua_State *tolua_S){
    tolua_usertype(tolua_S, "b2MotorJointDef");
    tolua_cclass(tolua_S, "b2MotorJointDef", "b2MotorJointDef", "b2JointDef", nullptr);
    tolua_beginmodule(tolua_S, "b2MotorJointDef");
        tolua_function(tolua_S,"new",tolua_LuaBox2D_b2MotorJointDef_new00_local);
        tolua_function(tolua_S,".call",tolua_LuaBox2D_b2MotorJointDef_new00_local);
        tolua_variable(tolua_S,"linearOffset",tolua_get_b2MotorJointDef_linearOffset,tolua_set_b2MotorJointDef_linearOffset);
        tolua_variable(tolua_S,"angularOffset",tolua_get_b2MotorJointDef_angularOffset,tolua_set_b2MotorJointDef_angularOffset);
        tolua_variable(tolua_S,"maxForce",tolua_get_b2MotorJointDef_maxForce,tolua_set_b2MotorJointDef_maxForce);
        tolua_variable(tolua_S,"maxTorque",tolua_get_b2MotorJointDef_maxTorque,tolua_set_b2MotorJointDef_maxTorque);
        tolua_variable(tolua_S,"correctionFactor",tolua_get_b2MotorJointDef_correctionFactor,tolua_set_b2MotorJointDef_correctionFactor);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(b2MotorJointDef).name();
    g_luaType[typeName] = "b2MotorJointDef";
    g_typeCast["b2MotorJointDef"] = "b2MotorJointDef";
    return 1;  
}

/* class of b2MotorJoint */
//function of GetAnchorA b2MotorJoint
int tolua_LuaBox2D_b2MotorJoint_GetAnchorA00(lua_State* tolua_S){
    int argc = 0;
    b2MotorJoint* cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2MotorJoint", 0, &tolua_err)) goto tolua_lerror;
#endif

    cobj = (b2MotorJoint*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_LuaBox2D_b2MotorJoint_GetAnchorA00'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do{
        if (0 == argc)
        {

            b2Vec2 newVec = cobj->GetAnchorA();
            // object_to_luaval<b2Vec2>(tolua_S, "b2Vec2",(b2Vec2*)&ret);
            b2Vec2 *ret = new b2Vec2(newVec.x, newVec.y);
            object_to_luaval(tolua_S, "b2Vec2", (b2Vec2 *)ret);
            tolua_register_gc(tolua_S, lua_gettop(tolua_S));
            return 1;
        }
    }while(0);
   
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_LuaBox2D_b2MotorJoint_GetAnchorA00",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2MotorJoint_GetAnchorA00'.",&tolua_err);
    return 0;
#endif
}

//function of GetAnchorB b2MotorJoint
int tolua_LuaBox2D_b2MotorJoint_GetAnchorB00(lua_State* tolua_S){
    int argc = 0;
    b2MotorJoint* cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2MotorJoint", 0, &tolua_err)) goto tolua_lerror;
#endif

    cobj = (b2MotorJoint*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_LuaBox2D_b2MotorJoint_GetAnchorB00'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do{
        if (0 == argc)
        {

            b2Vec2 newVec = cobj->GetAnchorB();
            // object_to_luaval<b2Vec2>(tolua_S, "b2Vec2",(b2Vec2*)&ret);
            b2Vec2 *ret = new b2Vec2(newVec.x, newVec.y);
            object_to_luaval(tolua_S, "b2Vec2", (b2Vec2 *)ret);
            tolua_register_gc(tolua_S, lua_gettop(tolua_S));
            return 1;
        }
    }while(0);
   
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_LuaBox2D_b2MotorJoint_GetAnchorB00",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2MotorJoint_GetAnchorB00'.",&tolua_err);
    return 0;
#endif
}

//function of GetReactionForce b2MotorJoint
int tolua_LuaBox2D_b2MotorJoint_GetReactionForce00(lua_State* tolua_S){
    int argc = 0;
    b2MotorJoint* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2MotorJoint", 0, &tolua_err)) goto tolua_lerror;
#endif

    cobj = (b2MotorJoint*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_LuaBox2D_b2MotorJoint_GetReactionForce00'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do{
        if (1 == argc)
        {
            double arg0;
            ok &= luaval_to_number(tolua_S, 2,&arg0, "tolua_LuaBox2D_b2MotorJoint_GetReactionForce00");
            if (!ok) { break; }

            b2Vec2 newVec = cobj->GetReactionForce((float32)arg0);
            // object_to_luaval<b2Vec2>(tolua_S, "b2Vec2",(b2Vec2*)&ret);
            b2Vec2 *ret = new b2Vec2(newVec.x, newVec.y);
            object_to_luaval(tolua_S, "b2Vec2", (b2Vec2 *)ret);
            tolua_register_gc(tolua_S, lua_gettop(tolua_S));
            return 1;
        }
    }while(0);
   
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_LuaBox2D_b2MotorJoint_GetReactionForce00",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2MotorJoint_GetReactionForce00'.",&tolua_err);
    return 0;
#endif
}

//function of GetReactionTorque b2MotorJoint
int tolua_LuaBox2D_b2MotorJoint_GetReactionTorque00(lua_State* tolua_S){
    int argc = 0;
    b2MotorJoint* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2MotorJoint", 0, &tolua_err)) goto tolua_lerror;
#endif

    cobj = (b2MotorJoint*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_LuaBox2D_b2MotorJoint_GetReactionTorque00'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do{
        if (1 == argc)
        {
            double arg0;
            ok &= luaval_to_number(tolua_S, 2,&arg0, "tolua_LuaBox2D_b2MotorJoint_GetReactionTorque00");
            if (!ok) { break; }

            float32 ret = cobj->GetReactionTorque((float32)arg0);
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            
            return 1;
        }
    }while(0);
   
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_LuaBox2D_b2MotorJoint_GetReactionTorque00",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2MotorJoint_GetReactionTorque00'.",&tolua_err);
    return 0;
#endif
}

//function of SetLinearOffset b2MotorJoint
int tolua_LuaBox2D_b2MotorJoint_SetLinearOffset00(lua_State* tolua_S){
    int argc = 0;
    b2MotorJoint* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2MotorJoint", 0, &tolua_err)) goto tolua_lerror;
#endif

    cobj = (b2MotorJoint*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_LuaBox2D_b2MotorJoint_SetLinearOffset00'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do{
        if (1 == argc)
        {
            b2Vec2* arg0;
            ok &= luaval_to_object<b2Vec2>(tolua_S, 2, "b2Vec2",&arg0);
            if (!ok) { break; }

            cobj->SetLinearOffset(*arg0);
            lua_settop(tolua_S, 1);
            
            return 1;
        }
    }while(0);
   
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_LuaBox2D_b2MotorJoint_SetLinearOffset00",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2MotorJoint_SetLinearOffset00'.",&tolua_err);
    return 0;
#endif
}

//function of GetLinearOffset b2MotorJoint
int tolua_LuaBox2D_b2MotorJoint_GetLinearOffset00(lua_State* tolua_S){
    int argc = 0;
    b2MotorJoint* cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2MotorJoint", 0, &tolua_err)) goto tolua_lerror;
#endif

    cobj = (b2MotorJoint*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_LuaBox2D_b2MotorJoint_GetLinearOffset00'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do{
        if (0 == argc)
        {

            b2Vec2 newVec = cobj->GetLinearOffset();
            // object_to_luaval<b2Vec2>(tolua_S, "b2Vec2",(b2Vec2*)&ret);
            b2Vec2 *ret = new b2Vec2(newVec.x, newVec.y);
            object_to_luaval(tolua_S, "b2Vec2", (b2Vec2 *)ret);
            tolua_register_gc(tolua_S, lua_gettop(tolua_S));
            return 1;
        }
    }while(0);
   
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_LuaBox2D_b2MotorJoint_GetLinearOffset00",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2MotorJoint_GetLinearOffset00'.",&tolua_err);
    return 0;
#endif
}

//function of SetAngularOffset b2MotorJoint
int tolua_LuaBox2D_b2MotorJoint_SetAngularOffset00(lua_State* tolua_S){
    int argc = 0;
    b2MotorJoint* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2MotorJoint", 0, &tolua_err)) goto tolua_lerror;
#endif

    cobj = (b2MotorJoint*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_LuaBox2D_b2MotorJoint_SetAngularOffset00'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do{
        if (1 == argc)
        {
            double arg0;
            ok &= luaval_to_number(tolua_S, 2,&arg0, "tolua_LuaBox2D_b2MotorJoint_SetAngularOffset00");
            if (!ok) { break; }

            cobj->SetAngularOffset((float32)arg0);
            lua_settop(tolua_S, 1);
            
            return 1;
        }
    }while(0);
   
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_LuaBox2D_b2MotorJoint_SetAngularOffset00",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2MotorJoint_SetAngularOffset00'.",&tolua_err);
    return 0;
#endif
}

//function of GetAngularOffset b2MotorJoint
int tolua_LuaBox2D_b2MotorJoint_GetAngularOffset00(lua_State* tolua_S){
    int argc = 0;
    b2MotorJoint* cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2MotorJoint", 0, &tolua_err)) goto tolua_lerror;
#endif

    cobj = (b2MotorJoint*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_LuaBox2D_b2MotorJoint_GetAngularOffset00'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do{
        if (0 == argc)
        {

            float32 ret = cobj->GetAngularOffset();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            
            return 1;
        }
    }while(0);
   
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_LuaBox2D_b2MotorJoint_GetAngularOffset00",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2MotorJoint_GetAngularOffset00'.",&tolua_err);
    return 0;
#endif
}

//function of SetMaxForce b2MotorJoint
int tolua_LuaBox2D_b2MotorJoint_SetMaxForce00(lua_State* tolua_S){
    int argc = 0;
    b2MotorJoint* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2MotorJoint", 0, &tolua_err)) goto tolua_lerror;
#endif

    cobj = (b2MotorJoint*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_LuaBox2D_b2MotorJoint_SetMaxForce00'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do{
        if (1 == argc)
        {
            double arg0;
            ok &= luaval_to_number(tolua_S, 2,&arg0, "tolua_LuaBox2D_b2MotorJoint_SetMaxForce00");
            if (!ok) { break; }

            cobj->SetMaxForce((float32)arg0);
            lua_settop(tolua_S, 1);
            
            return 1;
        }
    }while(0);
   
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_LuaBox2D_b2MotorJoint_SetMaxForce00",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2MotorJoint_SetMaxForce00'.",&tolua_err);
    return 0;
#endif
}

//function of GetMaxForce b2MotorJoint
int tolua_LuaBox2D_b2MotorJoint_GetMaxForce00(lua_State* tolua_S){
    int argc = 0;
    b2MotorJoint* cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2MotorJoint", 0, &tolua_err)) goto tolua_lerror;
#endif

    cobj = (b2MotorJoint*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_LuaBox2D_b2MotorJoint_GetMaxForce00'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do{
        if (0 == argc)
        {

            float32 ret = cobj->GetMaxForce();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            
            return 1;
        }
    }while(0);
   
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_LuaBox2D_b2MotorJoint_GetMaxForce00",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2MotorJoint_GetMaxForce00'.",&tolua_err);
    return 0;
#endif
}

//function of SetMaxTorque b2MotorJoint
int tolua_LuaBox2D_b2MotorJoint_SetMaxTorque00(lua_State* tolua_S){
    int argc = 0;
    b2MotorJoint* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2MotorJoint", 0, &tolua_err)) goto tolua_lerror;
#endif

    cobj = (b2MotorJoint*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_LuaBox2D_b2MotorJoint_SetMaxTorque00'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do{
        if (1 == argc)
        {
            double arg0;
            ok &= luaval_to_number(tolua_S, 2,&arg0, "tolua_LuaBox2D_b2MotorJoint_SetMaxTorque00");
            if (!ok) { break; }

            cobj->SetMaxTorque((float32)arg0);
            lua_settop(tolua_S, 1);
            
            return 1;
        }
    }while(0);
   
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_LuaBox2D_b2MotorJoint_SetMaxTorque00",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2MotorJoint_SetMaxTorque00'.",&tolua_err);
    return 0;
#endif
}

//function of GetMaxTorque b2MotorJoint
int tolua_LuaBox2D_b2MotorJoint_GetMaxTorque00(lua_State* tolua_S){
    int argc = 0;
    b2MotorJoint* cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2MotorJoint", 0, &tolua_err)) goto tolua_lerror;
#endif

    cobj = (b2MotorJoint*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_LuaBox2D_b2MotorJoint_GetMaxTorque00'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do{
        if (0 == argc)
        {

            float32 ret = cobj->GetMaxTorque();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            
            return 1;
        }
    }while(0);
   
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_LuaBox2D_b2MotorJoint_GetMaxTorque00",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2MotorJoint_GetMaxTorque00'.",&tolua_err);
    return 0;
#endif
}

//function of SetCorrectionFactor b2MotorJoint
int tolua_LuaBox2D_b2MotorJoint_SetCorrectionFactor00(lua_State* tolua_S){
    int argc = 0;
    b2MotorJoint* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2MotorJoint", 0, &tolua_err)) goto tolua_lerror;
#endif

    cobj = (b2MotorJoint*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_LuaBox2D_b2MotorJoint_SetCorrectionFactor00'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do{
        if (1 == argc)
        {
            double arg0;
            ok &= luaval_to_number(tolua_S, 2,&arg0, "tolua_LuaBox2D_b2MotorJoint_SetCorrectionFactor00");
            if (!ok) { break; }

            cobj->SetCorrectionFactor((float32)arg0);
            lua_settop(tolua_S, 1);
            
            return 1;
        }
    }while(0);
   
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_LuaBox2D_b2MotorJoint_SetCorrectionFactor00",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2MotorJoint_SetCorrectionFactor00'.",&tolua_err);
    return 0;
#endif
}

//function of GetCorrectionFactor b2MotorJoint
int tolua_LuaBox2D_b2MotorJoint_GetCorrectionFactor00(lua_State* tolua_S){
    int argc = 0;
    b2MotorJoint* cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2MotorJoint", 0, &tolua_err)) goto tolua_lerror;
#endif

    cobj = (b2MotorJoint*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_LuaBox2D_b2MotorJoint_GetCorrectionFactor00'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do{
        if (0 == argc)
        {

            float32 ret = cobj->GetCorrectionFactor();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            
            return 1;
        }
    }while(0);
   
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_LuaBox2D_b2MotorJoint_GetCorrectionFactor00",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2MotorJoint_GetCorrectionFactor00'.",&tolua_err);
    return 0;
#endif
}

//function of Dump b2MotorJoint
int tolua_LuaBox2D_b2MotorJoint_Dump00(lua_State* tolua_S){
    int argc = 0;
    b2MotorJoint* cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2MotorJoint", 0, &tolua_err)) goto tolua_lerror;
#endif

    cobj = (b2MotorJoint*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_LuaBox2D_b2MotorJoint_Dump00'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do{
        if (0 == argc)
        {
            cobj->Dump();
            lua_settop(tolua_S, 1);
            
            return 1;
        }
    }while(0);
   
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_LuaBox2D_b2MotorJoint_Dump00",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2MotorJoint_Dump00'.",&tolua_err);
    return 0;
#endif
}

int lua_register_cocos2dx_b2MotorJoint(lua_State* tolua_S)
{
    tolua_usertype(tolua_S, "b2MotorJoint");
    tolua_cclass(tolua_S, "b2MotorJoint", "b2MotorJoint", "b2Joint",nullptr);
    tolua_beginmodule(tolua_S, "b2MotorJoint");
        tolua_function(tolua_S,"GetAnchorA",tolua_LuaBox2D_b2MotorJoint_GetAnchorA00);
        tolua_function(tolua_S,"GetAnchorB",tolua_LuaBox2D_b2MotorJoint_GetAnchorB00);
        tolua_function(tolua_S,"GetReactionForce",tolua_LuaBox2D_b2MotorJoint_GetReactionForce00);
        tolua_function(tolua_S,"GetReactionTorque",tolua_LuaBox2D_b2MotorJoint_GetReactionTorque00);
        tolua_function(tolua_S,"SetLinearOffset",tolua_LuaBox2D_b2MotorJoint_SetLinearOffset00);
        tolua_function(tolua_S,"GetLinearOffset",tolua_LuaBox2D_b2MotorJoint_GetLinearOffset00);
        tolua_function(tolua_S,"SetAngularOffset",tolua_LuaBox2D_b2MotorJoint_SetAngularOffset00);
        tolua_function(tolua_S,"GetAngularOffset",tolua_LuaBox2D_b2MotorJoint_GetAngularOffset00);
        tolua_function(tolua_S,"SetMaxForce",tolua_LuaBox2D_b2MotorJoint_SetMaxForce00);
        tolua_function(tolua_S,"GetMaxForce",tolua_LuaBox2D_b2MotorJoint_GetMaxForce00);
        tolua_function(tolua_S,"SetMaxTorque",tolua_LuaBox2D_b2MotorJoint_SetMaxTorque00);
        tolua_function(tolua_S,"GetMaxTorque",tolua_LuaBox2D_b2MotorJoint_GetMaxTorque00);
        tolua_function(tolua_S,"SetCorrectionFactor",tolua_LuaBox2D_b2MotorJoint_SetCorrectionFactor00);
        tolua_function(tolua_S,"GetCorrectionFactor",tolua_LuaBox2D_b2MotorJoint_GetCorrectionFactor00);
        tolua_function(tolua_S,"Dump",tolua_LuaBox2D_b2MotorJoint_Dump00);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(b2MotorJoint).name();
    g_luaType[typeName] = "b2MotorJoint";
    g_typeCast["b2MotorJoint"] = "b2MotorJoint";
    return 1;
}

/* class of b2PrismaticJointDef */
//function of new b2PrismaticJointDef
int tolua_LuaBox2D_b2PrismaticJointDef_new00_local(lua_State* tolua_S)
{
    int argc = 0;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"b2PrismaticJointDef",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S)-1;

    do
    {
        if (argc == 0)
        {
            b2PrismaticJointDef* ret = (b2PrismaticJointDef*)  Mtolua_new((b2PrismaticJointDef)());
            object_to_luaval<b2PrismaticJointDef>(tolua_S, "b2PrismaticJointDef",(b2PrismaticJointDef*)ret);
            tolua_register_gc(tolua_S,lua_gettop(tolua_S));
            return 1;
        }
    } while (0);
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d", "tolua_LuaBox2D_b2PrismaticJointDef_new00_local",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2PrismaticJointDef_new00_local'.",&tolua_err);
#endif
    return 0;
}

//function of Initialize b2PrismaticJointDef
int tolua_LuaBox2D_b2PrismaticJointDef_Initialize00(lua_State* tolua_S){
    int argc = 0;
    b2PrismaticJointDef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2PrismaticJointDef", 0, &tolua_err)) goto tolua_lerror;
#endif

    cobj = (b2PrismaticJointDef*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_LuaBox2D_b2PrismaticJointDef_Initialize00'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do{
        if (4 == argc)
        {
            b2Body *arg0;
            ok &= luaval_to_object<b2Body>(tolua_S, 2, "b2Body", &arg0);
            if (!ok) { break; }

            b2Body *arg1;
            ok &= luaval_to_object<b2Body>(tolua_S, 3, "b2Body", &arg1);
            if (!ok) { break; }

            b2Vec2* arg2;
            ok &= luaval_to_object<b2Vec2>(tolua_S, 4, "b2Vec2",&arg2);
            if (!ok) break;

            b2Vec2* arg3;
            ok &= luaval_to_object<b2Vec2>(tolua_S, 5, "b2Vec2",&arg3);
            if (!ok) break;

            cobj->Initialize(arg0,arg1,*arg2,*arg3);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
   
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_LuaBox2D_b2PrismaticJointDef_Initialize00",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2PrismaticJointDef_Initialize00'.",&tolua_err);
    return 0;
#endif
}

/* get function: localAnchorA of class  b2PrismaticJointDef */
static int tolua_get_b2PrismaticJointDef_localAnchorA(lua_State* tolua_S)
{
    b2PrismaticJointDef* cobj = nullptr;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"b2PrismaticJointDef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (b2PrismaticJointDef*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (nullptr == cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_get_b2PrismaticJointDef_localAnchorA'", nullptr);
        return 0;
    }
#endif

    object_to_luaval<b2Vec2>(tolua_S, "b2Vec2",(b2Vec2*)&cobj->localAnchorA);

    return 1;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_get_b2PrismaticJointDef_localAnchorA'.",&tolua_err);
    return 0;
#endif
}

/* set function: localAnchorA of class  b2PrismaticJointDef */
static int tolua_set_b2PrismaticJointDef_localAnchorA(lua_State* tolua_S)
{
    int argc = 0;
    b2PrismaticJointDef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"b2PrismaticJointDef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (b2PrismaticJointDef*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (nullptr == cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_set_b2PrismaticJointDef_localAnchorA'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S) - 1;

    do{
        if (1 == argc)
        {
            b2Vec2* arg0;
            ok &= luaval_to_object<b2Vec2>(tolua_S, 2, "b2Vec2",&arg0);
            if (!ok) break;
             
            cobj->localAnchorA = *arg0;
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_set_b2PrismaticJointDef_localAnchorA",argc, 1);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_set_b2PrismaticJointDef_localAnchorA'.",&tolua_err);
    return 0;
#endif
}

/* get function: localAnchorB of class  b2PrismaticJointDef */
static int tolua_get_b2PrismaticJointDef_localAnchorB(lua_State* tolua_S)
{
    b2PrismaticJointDef* cobj = nullptr;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"b2PrismaticJointDef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (b2PrismaticJointDef*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (nullptr == cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_get_b2PrismaticJointDef_localAnchorB'", nullptr);
        return 0;
    }
#endif

    object_to_luaval<b2Vec2>(tolua_S, "b2Vec2",(b2Vec2*)&cobj->localAnchorB);

    return 1;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_get_b2PrismaticJointDef_localAnchorB'.",&tolua_err);
    return 0;
#endif
}

/* set function: localAnchorB of class  b2PrismaticJointDef */
static int tolua_set_b2PrismaticJointDef_localAnchorB(lua_State* tolua_S)
{
    int argc = 0;
    b2PrismaticJointDef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"b2PrismaticJointDef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (b2PrismaticJointDef*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (nullptr == cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_set_b2PrismaticJointDef_localAnchorB'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S) - 1;

    do{
        if (1 == argc)
        {
            b2Vec2* arg0;
            ok &= luaval_to_object<b2Vec2>(tolua_S, 2, "b2Vec2",&arg0);
            if (!ok) break;
             
            cobj->localAnchorB = *arg0;
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_set_b2PrismaticJointDef_localAnchorB",argc, 1);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_set_b2PrismaticJointDef_localAnchorB'.",&tolua_err);
    return 0;
#endif
}

/* get function: localAxisA of class  b2PrismaticJointDef */
static int tolua_get_b2PrismaticJointDef_localAxisA(lua_State* tolua_S)
{
    b2PrismaticJointDef* cobj = nullptr;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"b2PrismaticJointDef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (b2PrismaticJointDef*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (nullptr == cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_get_b2PrismaticJointDef_localAxisA'", nullptr);
        return 0;
    }
#endif

    object_to_luaval<b2Vec2>(tolua_S, "b2Vec2",(b2Vec2*)&cobj->localAxisA);

    return 1;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_get_b2PrismaticJointDef_localAxisA'.",&tolua_err);
    return 0;
#endif
}

/* set function: localAxisA of class  b2PrismaticJointDef */
static int tolua_set_b2PrismaticJointDef_localAxisA(lua_State* tolua_S)
{
    int argc = 0;
    b2PrismaticJointDef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"b2PrismaticJointDef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (b2PrismaticJointDef*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (nullptr == cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_set_b2PrismaticJointDef_localAxisA'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S) - 1;

    do{
        if (1 == argc)
        {
            b2Vec2* arg0;
            ok &= luaval_to_object<b2Vec2>(tolua_S, 2, "b2Vec2",&arg0);
            if (!ok) break;
             
            cobj->localAxisA = *arg0;
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_set_b2PrismaticJointDef_localAxisA",argc, 1);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_set_b2PrismaticJointDef_localAxisA'.",&tolua_err);
    return 0;
#endif
}

/* get function: referenceAngle of class  b2PrismaticJointDef */
static int tolua_get_b2PrismaticJointDef_referenceAngle(lua_State* tolua_S)
{
    b2PrismaticJointDef* cobj = nullptr;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"b2PrismaticJointDef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (b2PrismaticJointDef*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (nullptr == cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_get_b2PrismaticJointDef_referenceAngle'", nullptr);
        return 0;
    }
#endif
    tolua_pushnumber(tolua_S,(lua_Number)cobj->referenceAngle);

    return 1;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_get_b2PrismaticJointDef_referenceAngle'.",&tolua_err);
    return 0;
#endif
}

/* set function: referenceAngle of class  b2PrismaticJointDef */
static int tolua_set_b2PrismaticJointDef_referenceAngle(lua_State* tolua_S)
{
    int argc = 0;
    b2PrismaticJointDef* cobj = nullptr;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"b2PrismaticJointDef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (b2PrismaticJointDef*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (nullptr == cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_set_b2PrismaticJointDef_referenceAngle'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (1 == argc)
    {
#if COCOS2D_DEBUG >= 1
        if (!tolua_isnumber(tolua_S, 2, 0, &tolua_err))
            goto tolua_lerror;
#endif

        cobj->referenceAngle = ((float32) tolua_tonumber(tolua_S,2,0));
        return 0;
    }

    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_set_b2PrismaticJointDef_referenceAngle'.",&tolua_err);
    return 0;
#endif
}

/* get function: enableLimit of class  b2PrismaticJointDef */
static int tolua_get_b2PrismaticJointDef_enableLimit(lua_State* tolua_S)
{
    b2PrismaticJointDef* cobj = nullptr;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"b2PrismaticJointDef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (b2PrismaticJointDef*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (nullptr == cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_get_b2PrismaticJointDef_enableLimit'", nullptr);
        return 0;
    }
#endif
    tolua_pushboolean(tolua_S,(bool)cobj->enableLimit);

    return 1;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_get_b2PrismaticJointDef_enableLimit'.",&tolua_err);
    return 0;
#endif
}

/* set function: enableLimit of class  b2PrismaticJointDef */
static int tolua_set_b2PrismaticJointDef_enableLimit(lua_State* tolua_S)
{
    int argc = 0;
    b2PrismaticJointDef* cobj = nullptr;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"b2PrismaticJointDef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (b2PrismaticJointDef*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (nullptr == cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_set_b2PrismaticJointDef_enableLimit'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (1 == argc)
    {
#if COCOS2D_DEBUG >= 1
        if (!tolua_isboolean(tolua_S, 2, 0, &tolua_err))
            goto tolua_lerror;
#endif
        cobj->enableLimit = (bool) tolua_toboolean(tolua_S,2,0);
        return 0;
    }

    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_set_b2PrismaticJointDef_enableLimit'.",&tolua_err);
    return 0;
#endif
}

/* get function: lowerTranslation of class  b2PrismaticJointDef */
static int tolua_get_b2PrismaticJointDef_lowerTranslation(lua_State* tolua_S)
{
    b2PrismaticJointDef* cobj = nullptr;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"b2PrismaticJointDef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (b2PrismaticJointDef*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (nullptr == cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_get_b2PrismaticJointDef_lowerTranslation'", nullptr);
        return 0;
    }
#endif
    tolua_pushnumber(tolua_S,(lua_Number)cobj->lowerTranslation);

    return 1;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_get_b2PrismaticJointDef_lowerTranslation'.",&tolua_err);
    return 0;
#endif
}

/* set function: lowerTranslation of class  b2PrismaticJointDef */
static int tolua_set_b2PrismaticJointDef_lowerTranslation(lua_State* tolua_S)
{
    int argc = 0;
    b2PrismaticJointDef* cobj = nullptr;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"b2PrismaticJointDef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (b2PrismaticJointDef*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (nullptr == cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_set_b2PrismaticJointDef_lowerTranslation'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (1 == argc)
    {
#if COCOS2D_DEBUG >= 1
        if (!tolua_isnumber(tolua_S, 2, 0, &tolua_err))
            goto tolua_lerror;
#endif

        cobj->lowerTranslation = ((float32) tolua_tonumber(tolua_S,2,0));
        return 0;
    }

    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_set_b2PrismaticJointDef_lowerTranslation'.",&tolua_err);
    return 0;
#endif
}

/* get function: upperTranslation of class  b2PrismaticJointDef */
static int tolua_get_b2PrismaticJointDef_upperTranslation(lua_State* tolua_S)
{
    b2PrismaticJointDef* cobj = nullptr;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"b2PrismaticJointDef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (b2PrismaticJointDef*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (nullptr == cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_get_b2PrismaticJointDef_upperTranslation'", nullptr);
        return 0;
    }
#endif
    tolua_pushnumber(tolua_S,(lua_Number)cobj->upperTranslation);

    return 1;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_get_b2PrismaticJointDef_upperTranslation'.",&tolua_err);
    return 0;
#endif
}

/* set function: upperTranslation of class  b2PrismaticJointDef */
static int tolua_set_b2PrismaticJointDef_upperTranslation(lua_State* tolua_S)
{
    int argc = 0;
    b2PrismaticJointDef* cobj = nullptr;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"b2PrismaticJointDef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (b2PrismaticJointDef*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (nullptr == cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_set_b2PrismaticJointDef_upperTranslation'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (1 == argc)
    {
#if COCOS2D_DEBUG >= 1
        if (!tolua_isnumber(tolua_S, 2, 0, &tolua_err))
            goto tolua_lerror;
#endif

        cobj->upperTranslation = ((float32) tolua_tonumber(tolua_S,2,0));
        return 0;
    }

    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_set_b2PrismaticJointDef_upperTranslation'.",&tolua_err);
    return 0;
#endif
}

/* get function: enableMotor of class  b2PrismaticJointDef */
static int tolua_get_b2PrismaticJointDef_enableMotor(lua_State* tolua_S)
{
    b2PrismaticJointDef* cobj = nullptr;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"b2PrismaticJointDef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (b2PrismaticJointDef*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (nullptr == cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_get_b2PrismaticJointDef_enableMotor'", nullptr);
        return 0;
    }
#endif
    tolua_pushboolean(tolua_S,(bool)cobj->enableMotor);

    return 1;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_get_b2PrismaticJointDef_enableMotor'.",&tolua_err);
    return 0;
#endif
}

/* set function: enableMotor of class  b2PrismaticJointDef */
static int tolua_set_b2PrismaticJointDef_enableMotor(lua_State* tolua_S)
{
    int argc = 0;
    b2PrismaticJointDef* cobj = nullptr;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"b2PrismaticJointDef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (b2PrismaticJointDef*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (nullptr == cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_set_b2PrismaticJointDef_enableMotor'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (1 == argc)
    {
#if COCOS2D_DEBUG >= 1
        if (!tolua_isboolean(tolua_S, 2, 0, &tolua_err))
            goto tolua_lerror;
#endif
        cobj->enableMotor = (bool) tolua_toboolean(tolua_S,2,0);
        return 0;
    }

    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_set_b2PrismaticJointDef_enableMotor'.",&tolua_err);
    return 0;
#endif
}

/* get function: maxMotorForce of class  b2PrismaticJointDef */
static int tolua_get_b2PrismaticJointDef_maxMotorForce(lua_State* tolua_S)
{
    b2PrismaticJointDef* cobj = nullptr;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"b2PrismaticJointDef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (b2PrismaticJointDef*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (nullptr == cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_get_b2PrismaticJointDef_maxMotorForce'", nullptr);
        return 0;
    }
#endif
    tolua_pushnumber(tolua_S,(lua_Number)cobj->maxMotorForce);

    return 1;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_get_b2PrismaticJointDef_maxMotorForce'.",&tolua_err);
    return 0;
#endif
}

/* set function: maxMotorForce of class  b2PrismaticJointDef */
static int tolua_set_b2PrismaticJointDef_maxMotorForce(lua_State* tolua_S)
{
    int argc = 0;
    b2PrismaticJointDef* cobj = nullptr;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"b2PrismaticJointDef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (b2PrismaticJointDef*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (nullptr == cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_set_b2PrismaticJointDef_maxMotorForce'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (1 == argc)
    {
#if COCOS2D_DEBUG >= 1
        if (!tolua_isnumber(tolua_S, 2, 0, &tolua_err))
            goto tolua_lerror;
#endif

        cobj->maxMotorForce = ((float32) tolua_tonumber(tolua_S,2,0));
        return 0;
    }

    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_set_b2PrismaticJointDef_maxMotorForce'.",&tolua_err);
    return 0;
#endif
}

/* get function: motorSpeed of class  b2PrismaticJointDef */
static int tolua_get_b2PrismaticJointDef_motorSpeed(lua_State* tolua_S)
{
    b2PrismaticJointDef* cobj = nullptr;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"b2PrismaticJointDef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (b2PrismaticJointDef*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (nullptr == cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_get_b2PrismaticJointDef_motorSpeed'", nullptr);
        return 0;
    }
#endif
    tolua_pushnumber(tolua_S,(lua_Number)cobj->motorSpeed);

    return 1;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_get_b2PrismaticJointDef_motorSpeed'.",&tolua_err);
    return 0;
#endif
}

/* set function: motorSpeed of class  b2PrismaticJointDef */
static int tolua_set_b2PrismaticJointDef_motorSpeed(lua_State* tolua_S)
{
    int argc = 0;
    b2PrismaticJointDef* cobj = nullptr;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"b2PrismaticJointDef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (b2PrismaticJointDef*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (nullptr == cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_set_b2PrismaticJointDef_motorSpeed'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (1 == argc)
    {
#if COCOS2D_DEBUG >= 1
        if (!tolua_isnumber(tolua_S, 2, 0, &tolua_err))
            goto tolua_lerror;
#endif

        cobj->motorSpeed = ((float32) tolua_tonumber(tolua_S,2,0));
        return 0;
    }

    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_set_b2PrismaticJointDef_motorSpeed'.",&tolua_err);
    return 0;
#endif
}

int lua_register_cocos2dx_b2PrismaticJointDef(lua_State *tolua_S){
    tolua_usertype(tolua_S, "b2PrismaticJointDef");
    tolua_cclass(tolua_S, "b2PrismaticJointDef", "b2PrismaticJointDef", "b2JointDef", nullptr);
    tolua_beginmodule(tolua_S, "b2PrismaticJointDef");
        tolua_function(tolua_S,"new",tolua_LuaBox2D_b2PrismaticJointDef_new00_local);
        tolua_function(tolua_S,".call",tolua_LuaBox2D_b2PrismaticJointDef_new00_local);
        tolua_function(tolua_S,"Initialize",tolua_LuaBox2D_b2PrismaticJointDef_Initialize00);
        tolua_variable(tolua_S,"localAnchorA",tolua_get_b2PrismaticJointDef_localAnchorA,tolua_set_b2PrismaticJointDef_localAnchorA);
        tolua_variable(tolua_S,"localAnchorB",tolua_get_b2PrismaticJointDef_localAnchorB,tolua_set_b2PrismaticJointDef_localAnchorB);
        tolua_variable(tolua_S,"localAxisA",tolua_get_b2PrismaticJointDef_localAxisA,tolua_set_b2PrismaticJointDef_localAxisA);
        tolua_variable(tolua_S,"referenceAngle",tolua_get_b2PrismaticJointDef_referenceAngle,tolua_set_b2PrismaticJointDef_referenceAngle);
        tolua_variable(tolua_S,"enableLimit",tolua_get_b2PrismaticJointDef_enableLimit,tolua_set_b2PrismaticJointDef_enableLimit);
        tolua_variable(tolua_S,"lowerTranslation",tolua_get_b2PrismaticJointDef_lowerTranslation,tolua_set_b2PrismaticJointDef_lowerTranslation);
        tolua_variable(tolua_S,"upperTranslation",tolua_get_b2PrismaticJointDef_upperTranslation,tolua_set_b2PrismaticJointDef_upperTranslation);
        tolua_variable(tolua_S,"enableMotor",tolua_get_b2PrismaticJointDef_enableMotor,tolua_set_b2PrismaticJointDef_enableMotor);
        tolua_variable(tolua_S,"maxMotorForce",tolua_get_b2PrismaticJointDef_maxMotorForce,tolua_set_b2PrismaticJointDef_maxMotorForce);
        tolua_variable(tolua_S,"motorSpeed",tolua_get_b2PrismaticJointDef_motorSpeed,tolua_set_b2PrismaticJointDef_motorSpeed);
    
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(b2PrismaticJointDef).name();
    g_luaType[typeName] = "b2PrismaticJointDef";
    g_typeCast["b2PrismaticJointDef"] = "b2PrismaticJointDef";
    return 1;  
}

/* class of b2PrismaticJoint */
//function of GetAnchorA b2PrismaticJoint
int tolua_LuaBox2D_b2PrismaticJoint_GetAnchorA00(lua_State* tolua_S){
    int argc = 0;
    b2PrismaticJoint* cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2PrismaticJoint", 0, &tolua_err)) goto tolua_lerror;
#endif

    cobj = (b2PrismaticJoint*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_LuaBox2D_b2PrismaticJoint_GetAnchorA00'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do{
        if (0 == argc)
        {

            b2Vec2 newVec = cobj->GetAnchorA();
            // object_to_luaval<b2Vec2>(tolua_S, "b2Vec2",(b2Vec2*)&ret);
            b2Vec2 *ret = new b2Vec2(newVec.x, newVec.y);
            object_to_luaval(tolua_S, "b2Vec2", (b2Vec2 *)ret);
            tolua_register_gc(tolua_S, lua_gettop(tolua_S));
            return 1;
        }
    }while(0);
   
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_LuaBox2D_b2PrismaticJoint_GetAnchorA00",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2PrismaticJoint_GetAnchorA00'.",&tolua_err);
    return 0;
#endif
}

//function of GetAnchorB b2PrismaticJoint
int tolua_LuaBox2D_b2PrismaticJoint_GetAnchorB00(lua_State* tolua_S){
    int argc = 0;
    b2PrismaticJoint* cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2PrismaticJoint", 0, &tolua_err)) goto tolua_lerror;
#endif

    cobj = (b2PrismaticJoint*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_LuaBox2D_b2PrismaticJoint_GetAnchorB00'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do{
        if (0 == argc)
        {

            b2Vec2 newVec = cobj->GetAnchorB();
            // object_to_luaval<b2Vec2>(tolua_S, "b2Vec2",(b2Vec2*)&ret);
            b2Vec2 *ret = new b2Vec2(newVec.x, newVec.y);
            object_to_luaval(tolua_S, "b2Vec2", (b2Vec2 *)ret);
            tolua_register_gc(tolua_S, lua_gettop(tolua_S));
            return 1;
        }
    }while(0);
   
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_LuaBox2D_b2PrismaticJoint_GetAnchorB00",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2PrismaticJoint_GetAnchorB00'.",&tolua_err);
    return 0;
#endif
}

//function of GetReactionForce b2PrismaticJoint
int tolua_LuaBox2D_b2PrismaticJoint_GetReactionForce00(lua_State* tolua_S){
    int argc = 0;
    b2PrismaticJoint* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2PrismaticJoint", 0, &tolua_err)) goto tolua_lerror;
#endif

    cobj = (b2PrismaticJoint*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_LuaBox2D_b2PrismaticJoint_GetReactionForce00'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do{
        if (1 == argc)
        {
            double arg0;
            ok &= luaval_to_number(tolua_S, 2,&arg0, "tolua_LuaBox2D_b2PrismaticJoint_GetReactionForce00");
            if (!ok) { break; }

            b2Vec2 newVec = cobj->GetReactionForce((float32)arg0);
            // object_to_luaval<b2Vec2>(tolua_S, "b2Vec2",(b2Vec2*)&ret);
            b2Vec2 *ret = new b2Vec2(newVec.x, newVec.y);
            object_to_luaval(tolua_S, "b2Vec2", (b2Vec2 *)ret);
            tolua_register_gc(tolua_S, lua_gettop(tolua_S));
            return 1;
        }
    }while(0);
   
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_LuaBox2D_b2PrismaticJoint_GetReactionForce00",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2PrismaticJoint_GetReactionForce00'.",&tolua_err);
    return 0;
#endif
}

//function of GetReactionTorque b2PrismaticJoint
int tolua_LuaBox2D_b2PrismaticJoint_GetReactionTorque00(lua_State* tolua_S){
    int argc = 0;
    b2PrismaticJoint* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2PrismaticJoint", 0, &tolua_err)) goto tolua_lerror;
#endif

    cobj = (b2PrismaticJoint*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_LuaBox2D_b2PrismaticJoint_GetReactionTorque00'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do{
        if (1 == argc)
        {
            double arg0;
            ok &= luaval_to_number(tolua_S, 2,&arg0, "tolua_LuaBox2D_b2PrismaticJoint_GetReactionTorque00");
            if (!ok) { break; }

            float32 ret = cobj->GetReactionTorque((float32)arg0);
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            
            return 1;
        }
    }while(0);
   
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_LuaBox2D_b2PrismaticJoint_GetReactionTorque00",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2PrismaticJoint_GetReactionTorque00'.",&tolua_err);
    return 0;
#endif
}

//function of GetLocalAnchorA b2PrismaticJoint
int tolua_LuaBox2D_b2PrismaticJoint_GetLocalAnchorA00(lua_State* tolua_S){
    int argc = 0;
    b2PrismaticJoint* cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2PrismaticJoint", 0, &tolua_err)) goto tolua_lerror;
#endif

    cobj = (b2PrismaticJoint*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_LuaBox2D_b2PrismaticJoint_GetLocalAnchorA00'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do{
        if (0 == argc)
        {

            b2Vec2 newVec = cobj->GetLocalAnchorA();
            // object_to_luaval<b2Vec2>(tolua_S, "b2Vec2",(b2Vec2*)&ret);
            b2Vec2 *ret = new b2Vec2(newVec.x, newVec.y);
            object_to_luaval(tolua_S, "b2Vec2", (b2Vec2 *)ret);
            tolua_register_gc(tolua_S, lua_gettop(tolua_S));
            return 1;
        }
    }while(0);
   
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_LuaBox2D_b2PrismaticJoint_GetLocalAnchorA00",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2PrismaticJoint_GetLocalAnchorA00'.",&tolua_err);
    return 0;
#endif
}

//function of GetLocalAnchorB b2PrismaticJoint
int tolua_LuaBox2D_b2PrismaticJoint_GetLocalAnchorB00(lua_State* tolua_S){
    int argc = 0;
    b2PrismaticJoint* cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2PrismaticJoint", 0, &tolua_err)) goto tolua_lerror;
#endif

    cobj = (b2PrismaticJoint*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_LuaBox2D_b2PrismaticJoint_GetLocalAnchorB00'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do{
        if (0 == argc)
        {

            b2Vec2 newVec = cobj->GetLocalAnchorB();
            // object_to_luaval<b2Vec2>(tolua_S, "b2Vec2",(b2Vec2*)&ret);
            b2Vec2 *ret = new b2Vec2(newVec.x, newVec.y);
            object_to_luaval(tolua_S, "b2Vec2", (b2Vec2 *)ret);
            tolua_register_gc(tolua_S, lua_gettop(tolua_S));
            return 1;
        }
    }while(0);
   
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_LuaBox2D_b2PrismaticJoint_GetLocalAnchorB00",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2PrismaticJoint_GetLocalAnchorB00'.",&tolua_err);
    return 0;
#endif
}

//function of GetLocalAxisA b2PrismaticJoint
int tolua_LuaBox2D_b2PrismaticJoint_GetLocalAxisA00(lua_State* tolua_S){
    int argc = 0;
    b2PrismaticJoint* cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2PrismaticJoint", 0, &tolua_err)) goto tolua_lerror;
#endif

    cobj = (b2PrismaticJoint*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_LuaBox2D_b2PrismaticJoint_GetLocalAxisA00'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do{
        if (0 == argc)
        {

            b2Vec2 newVec = cobj->GetLocalAxisA();
            // object_to_luaval<b2Vec2>(tolua_S, "b2Vec2",(b2Vec2*)&ret);
            b2Vec2 *ret = new b2Vec2(newVec.x, newVec.y);
            object_to_luaval(tolua_S, "b2Vec2", (b2Vec2 *)ret);
            tolua_register_gc(tolua_S, lua_gettop(tolua_S));
            return 1;
        }
    }while(0);
   
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_LuaBox2D_b2PrismaticJoint_GetLocalAxisA00",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2PrismaticJoint_GetLocalAxisA00'.",&tolua_err);
    return 0;
#endif
}

//function of GetReferenceAngle b2PrismaticJoint
int tolua_LuaBox2D_b2PrismaticJoint_GetReferenceAngle00(lua_State* tolua_S){
    int argc = 0;
    b2PrismaticJoint* cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2PrismaticJoint", 0, &tolua_err)) goto tolua_lerror;
#endif

    cobj = (b2PrismaticJoint*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_LuaBox2D_b2PrismaticJoint_GetReferenceAngle00'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do{
        if (0 == argc)
        {

            float32 ret = cobj->GetReferenceAngle();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            
            return 1;
        }
    }while(0);
   
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_LuaBox2D_b2PrismaticJoint_GetReferenceAngle00",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2PrismaticJoint_GetReferenceAngle00'.",&tolua_err);
    return 0;
#endif
}

//function of GetJointTranslation b2PrismaticJoint
int tolua_LuaBox2D_b2PrismaticJoint_GetJointTranslation00(lua_State* tolua_S){
    int argc = 0;
    b2PrismaticJoint* cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2PrismaticJoint", 0, &tolua_err)) goto tolua_lerror;
#endif

    cobj = (b2PrismaticJoint*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_LuaBox2D_b2PrismaticJoint_GetJointTranslation00'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do{
        if (0 == argc)
        {

            float32 ret = cobj->GetJointTranslation();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            
            return 1;
        }
    }while(0);
   
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_LuaBox2D_b2PrismaticJoint_GetJointTranslation00",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2PrismaticJoint_GetJointTranslation00'.",&tolua_err);
    return 0;
#endif
}

//function of GetJointSpeed b2PrismaticJoint
int tolua_LuaBox2D_b2PrismaticJoint_GetJointSpeed00(lua_State* tolua_S){
    int argc = 0;
    b2PrismaticJoint* cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2PrismaticJoint", 0, &tolua_err)) goto tolua_lerror;
#endif

    cobj = (b2PrismaticJoint*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_LuaBox2D_b2PrismaticJoint_GetJointSpeed00'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do{
        if (0 == argc)
        {

            float32 ret = cobj->GetJointSpeed();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            
            return 1;
        }
    }while(0);
   
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_LuaBox2D_b2PrismaticJoint_GetJointSpeed00",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2PrismaticJoint_GetJointSpeed00'.",&tolua_err);
    return 0;
#endif
}

//function of IsLimitEnabled b2PrismaticJoint
int tolua_LuaBox2D_b2PrismaticJoint_IsLimitEnabled00(lua_State* tolua_S){
    int argc = 0;
    b2PrismaticJoint* cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2PrismaticJoint", 0, &tolua_err)) goto tolua_lerror;
#endif

    cobj = (b2PrismaticJoint*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_LuaBox2D_b2PrismaticJoint_IsLimitEnabled00'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do{
        if (0 == argc)
        {

            bool ret = cobj->IsLimitEnabled();
            tolua_pushboolean(tolua_S,(bool)ret);
            
            return 1;
        }
    }while(0);
   
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_LuaBox2D_b2PrismaticJoint_IsLimitEnabled00",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2PrismaticJoint_IsLimitEnabled00'.",&tolua_err);
    return 0;
#endif
}

//function of EnableLimit b2PrismaticJoint
int tolua_LuaBox2D_b2PrismaticJoint_EnableLimit00(lua_State* tolua_S){
    int argc = 0;
    b2PrismaticJoint* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2PrismaticJoint", 0, &tolua_err)) goto tolua_lerror;
#endif

    cobj = (b2PrismaticJoint*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_LuaBox2D_b2PrismaticJoint_EnableLimit00'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do{
        if (1 == argc)
        {
            bool arg0;
            ok &= luaval_to_boolean(tolua_S, 2,&arg0, "tolua_LuaBox2D_b2PrismaticJoint_EnableLimit00");

            if (!ok) { break; }

            cobj->EnableLimit(arg0);
            lua_settop(tolua_S, 1);

            return 1;
        }
    }while(0);
   
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_LuaBox2D_b2PrismaticJoint_EnableLimit00",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2PrismaticJoint_EnableLimit00'.",&tolua_err);
    return 0;
#endif
}

//function of GetLowerLimit b2PrismaticJoint
int tolua_LuaBox2D_b2PrismaticJoint_GetLowerLimit00(lua_State* tolua_S){
    int argc = 0;
    b2PrismaticJoint* cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2PrismaticJoint", 0, &tolua_err)) goto tolua_lerror;
#endif

    cobj = (b2PrismaticJoint*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_LuaBox2D_b2PrismaticJoint_GetLowerLimit00'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do{
        if (0 == argc)
        {

            float32 ret = cobj->GetLowerLimit();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            
            return 1;
        }
    }while(0);
   
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_LuaBox2D_b2PrismaticJoint_GetLowerLimit00",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2PrismaticJoint_GetLowerLimit00'.",&tolua_err);
    return 0;
#endif
}

//function of GetUpperLimit b2PrismaticJoint
int tolua_LuaBox2D_b2PrismaticJoint_GetUpperLimit00(lua_State* tolua_S){
    int argc = 0;
    b2PrismaticJoint* cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2PrismaticJoint", 0, &tolua_err)) goto tolua_lerror;
#endif

    cobj = (b2PrismaticJoint*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_LuaBox2D_b2PrismaticJoint_GetUpperLimit00'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do{
        if (0 == argc)
        {

            float32 ret = cobj->GetUpperLimit();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            
            return 1;
        }
    }while(0);
   
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_LuaBox2D_b2PrismaticJoint_GetUpperLimit00",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2PrismaticJoint_GetUpperLimit00'.",&tolua_err);
    return 0;
#endif
}

//function of SetLimits b2PrismaticJoint
int tolua_LuaBox2D_b2PrismaticJoint_SetLimits00(lua_State* tolua_S){
    int argc = 0;
    b2PrismaticJoint* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2PrismaticJoint", 0, &tolua_err)) goto tolua_lerror;
#endif

    cobj = (b2PrismaticJoint*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_LuaBox2D_b2PrismaticJoint_SetLimits00'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do{
        if (1 == argc)
        {
            double arg0;
            ok &= luaval_to_number(tolua_S, 2,&arg0, "tolua_LuaBox2D_b2PrismaticJoint_SetLimits00");
            if (!ok) { break; }

            double arg1;
            ok &= luaval_to_number(tolua_S, 3,&arg1, "tolua_LuaBox2D_b2PrismaticJoint_SetLimits00");
            if (!ok) { break; }

            cobj->SetLimits((float32)arg0,(float32)arg1);
            lua_settop(tolua_S, 1);
            
            return 1;
        }
    }while(0);
   
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_LuaBox2D_b2PrismaticJoint_SetLimits00",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2PrismaticJoint_SetLimits00'.",&tolua_err);
    return 0;
#endif
}

//function of IsMotorEnabled b2PrismaticJoint
int tolua_LuaBox2D_b2PrismaticJoint_IsMotorEnabled00(lua_State* tolua_S){
    int argc = 0;
    b2PrismaticJoint* cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2PrismaticJoint", 0, &tolua_err)) goto tolua_lerror;
#endif

    cobj = (b2PrismaticJoint*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_LuaBox2D_b2PrismaticJoint_IsMotorEnabled00'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do{
        if (0 == argc)
        {

            bool ret = cobj->IsMotorEnabled();
            tolua_pushboolean(tolua_S,(bool)ret);
            
            return 1;
        }
    }while(0);
   
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_LuaBox2D_b2PrismaticJoint_IsMotorEnabled00",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2PrismaticJoint_IsMotorEnabled00'.",&tolua_err);
    return 0;
#endif
}

//function of EnableMotor b2PrismaticJoint
int tolua_LuaBox2D_b2PrismaticJoint_EnableMotor00(lua_State* tolua_S){
    int argc = 0;
    b2PrismaticJoint* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2PrismaticJoint", 0, &tolua_err)) goto tolua_lerror;
#endif

    cobj = (b2PrismaticJoint*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_LuaBox2D_b2PrismaticJoint_EnableMotor00'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do{
        if (1 == argc)
        {
            bool arg0;
            ok &= luaval_to_boolean(tolua_S, 2,&arg0, "tolua_LuaBox2D_b2PrismaticJoint_EnableMotor00");

            if (!ok) { break; }

            cobj->EnableMotor(arg0);
            lua_settop(tolua_S, 1);

            return 1;
        }
    }while(0);
   
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_LuaBox2D_b2PrismaticJoint_EnableMotor00",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2PrismaticJoint_EnableMotor00'.",&tolua_err);
    return 0;
#endif
}

//function of SetMotorSpeed b2PrismaticJoint
int tolua_LuaBox2D_b2PrismaticJoint_SetMotorSpeed00(lua_State* tolua_S){
    int argc = 0;
    b2PrismaticJoint* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2PrismaticJoint", 0, &tolua_err)) goto tolua_lerror;
#endif

    cobj = (b2PrismaticJoint*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_LuaBox2D_b2PrismaticJoint_SetMotorSpeed00'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do{
        if (1 == argc)
        {
            double arg0;
            ok &= luaval_to_number(tolua_S, 2,&arg0, "tolua_LuaBox2D_b2PrismaticJoint_SetMotorSpeed00");
            if (!ok) { break; }

            cobj->SetMotorSpeed((float32)arg0);
            lua_settop(tolua_S, 1);
            
            return 1;
        }
    }while(0);
   
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_LuaBox2D_b2PrismaticJoint_SetMotorSpeed00",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2PrismaticJoint_SetMotorSpeed00'.",&tolua_err);
    return 0;
#endif
}

//function of GetMotorSpeed b2PrismaticJoint
int tolua_LuaBox2D_b2PrismaticJoint_GetMotorSpeed00(lua_State* tolua_S){
    int argc = 0;
    b2PrismaticJoint* cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2PrismaticJoint", 0, &tolua_err)) goto tolua_lerror;
#endif

    cobj = (b2PrismaticJoint*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_LuaBox2D_b2PrismaticJoint_GetMotorSpeed00'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do{
        if (0 == argc)
        {

            float32 ret = cobj->GetMotorSpeed();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            
            return 1;
        }
    }while(0);
   
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_LuaBox2D_b2PrismaticJoint_GetMotorSpeed00",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2PrismaticJoint_GetMotorSpeed00'.",&tolua_err);
    return 0;
#endif
}

//function of SetMaxMotorForce b2PrismaticJoint
int tolua_LuaBox2D_b2PrismaticJoint_SetMaxMotorForce00(lua_State* tolua_S){
    int argc = 0;
    b2PrismaticJoint* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2PrismaticJoint", 0, &tolua_err)) goto tolua_lerror;
#endif

    cobj = (b2PrismaticJoint*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_LuaBox2D_b2PrismaticJoint_SetMaxMotorForce00'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do{
        if (1 == argc)
        {
            double arg0;
            ok &= luaval_to_number(tolua_S, 2,&arg0, "tolua_LuaBox2D_b2PrismaticJoint_SetMaxMotorForce00");
            if (!ok) { break; }

            cobj->SetMaxMotorForce((float32)arg0);
            lua_settop(tolua_S, 1);
            
            return 1;
        }
    }while(0);
   
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_LuaBox2D_b2PrismaticJoint_SetMaxMotorForce00",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2PrismaticJoint_SetMaxMotorForce00'.",&tolua_err);
    return 0;
#endif
}

//function of GetMaxMotorForce b2PrismaticJoint
int tolua_LuaBox2D_b2PrismaticJoint_GetMaxMotorForce00(lua_State* tolua_S){
    int argc = 0;
    b2PrismaticJoint* cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2PrismaticJoint", 0, &tolua_err)) goto tolua_lerror;
#endif

    cobj = (b2PrismaticJoint*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_LuaBox2D_b2PrismaticJoint_GetMaxMotorForce00'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do{
        if (0 == argc)
        {

            float32 ret = cobj->GetMaxMotorForce();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            
            return 1;
        }
    }while(0);
   
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_LuaBox2D_b2PrismaticJoint_GetMaxMotorForce00",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2PrismaticJoint_GetMaxMotorForce00'.",&tolua_err);
    return 0;
#endif
}

//function of GetMotorForce b2PrismaticJoint
int tolua_LuaBox2D_b2PrismaticJoint_GetMotorForce00(lua_State* tolua_S){
    int argc = 0;
    b2PrismaticJoint* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2PrismaticJoint", 0, &tolua_err)) goto tolua_lerror;
#endif

    cobj = (b2PrismaticJoint*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_LuaBox2D_b2PrismaticJoint_GetMotorForce00'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do{
        if (1 == argc)
        {
            double arg0;
            ok &= luaval_to_number(tolua_S, 2,&arg0, "tolua_LuaBox2D_b2PrismaticJoint_GetMotorForce00");
            if (!ok) { break; }

            float32 ret = cobj->GetMotorForce((float32)arg0);
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            
            return 1;
        }
    }while(0);
   
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_LuaBox2D_b2PrismaticJoint_GetMotorForce00",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2PrismaticJoint_GetMotorForce00'.",&tolua_err);
    return 0;
#endif
}

//function of Dump b2PrismaticJoint
int tolua_LuaBox2D_b2PrismaticJoint_Dump00(lua_State* tolua_S){
    int argc = 0;
    b2PrismaticJoint* cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2PrismaticJoint", 0, &tolua_err)) goto tolua_lerror;
#endif

    cobj = (b2PrismaticJoint*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'tolua_LuaBox2D_b2PrismaticJoint_Dump00'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    do{
        if (0 == argc)
        {
            cobj->Dump();
            lua_settop(tolua_S, 1);
            
            return 1;
        }
    }while(0);
   
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "tolua_LuaBox2D_b2PrismaticJoint_Dump00",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'tolua_LuaBox2D_b2PrismaticJoint_Dump00'.",&tolua_err);
    return 0;
#endif
}

int lua_register_cocos2dx_b2PrismaticJoint(lua_State* tolua_S)
{
    tolua_usertype(tolua_S, "b2PrismaticJoint");
    tolua_cclass(tolua_S, "b2PrismaticJoint", "b2PrismaticJoint", "b2Joint",nullptr);
    tolua_beginmodule(tolua_S, "b2PrismaticJoint");
        tolua_function(tolua_S,"GetAnchorA",tolua_LuaBox2D_b2PrismaticJoint_GetAnchorA00);
        tolua_function(tolua_S,"GetAnchorB",tolua_LuaBox2D_b2PrismaticJoint_GetAnchorB00);
        tolua_function(tolua_S,"GetReactionForce",tolua_LuaBox2D_b2PrismaticJoint_GetReactionForce00);
        tolua_function(tolua_S,"GetReactionTorque",tolua_LuaBox2D_b2PrismaticJoint_GetReactionTorque00);
        tolua_function(tolua_S,"GetLocalAxisA",tolua_LuaBox2D_b2PrismaticJoint_GetLocalAxisA00);
        tolua_function(tolua_S,"GetReferenceAngle",tolua_LuaBox2D_b2PrismaticJoint_GetReferenceAngle00);
        tolua_function(tolua_S,"GetJointTranslation",tolua_LuaBox2D_b2PrismaticJoint_GetJointTranslation00);
        tolua_function(tolua_S,"GetJointSpeed",tolua_LuaBox2D_b2PrismaticJoint_GetJointSpeed00);
        tolua_function(tolua_S,"IsLimitEnabled",tolua_LuaBox2D_b2PrismaticJoint_IsLimitEnabled00);
        tolua_function(tolua_S,"EnableLimit",tolua_LuaBox2D_b2PrismaticJoint_EnableLimit00);
        tolua_function(tolua_S,"GetLowerLimit",tolua_LuaBox2D_b2PrismaticJoint_GetLowerLimit00);
        tolua_function(tolua_S,"GetUpperLimit",tolua_LuaBox2D_b2PrismaticJoint_GetUpperLimit00);
        tolua_function(tolua_S,"SetLimits",tolua_LuaBox2D_b2PrismaticJoint_SetLimits00);
        tolua_function(tolua_S,"IsMotorEnabled",tolua_LuaBox2D_b2PrismaticJoint_IsMotorEnabled00);
        tolua_function(tolua_S,"EnableMotor",tolua_LuaBox2D_b2PrismaticJoint_EnableMotor00);
        tolua_function(tolua_S,"SetMotorSpeed",tolua_LuaBox2D_b2PrismaticJoint_SetMotorSpeed00);
        tolua_function(tolua_S,"GetMotorSpeed",tolua_LuaBox2D_b2PrismaticJoint_GetMotorSpeed00);
        tolua_function(tolua_S,"SetMaxMotorForce",tolua_LuaBox2D_b2PrismaticJoint_SetMaxMotorForce00);
        tolua_function(tolua_S,"GetMaxMotorForce",tolua_LuaBox2D_b2PrismaticJoint_GetMaxMotorForce00);
        tolua_function(tolua_S,"GetMotorForce",tolua_LuaBox2D_b2PrismaticJoint_GetMotorForce00);
        tolua_function(tolua_S,"Dump",tolua_LuaBox2D_b2PrismaticJoint_Dump00);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(b2PrismaticJoint).name();
    g_luaType[typeName] = "b2PrismaticJoint";
    g_typeCast["b2PrismaticJoint"] = "b2PrismaticJoint";
    return 1;
}

int tolua_get_b2RayCastInput_p1(lua_State *tolua_S){
    int argc = 0;
    b2RayCastInput *cobj = nullptr;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2RayCastInput", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2RayCastInput *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_get_b2RayCastInput_p1'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if(argc == 0){
        b2Vec2 newVec = cobj->p1;
        // object_to_luaval<b2Vec2>(tolua_S, "b2Vec2", &ret);
        b2Vec2 *ret = new b2Vec2(newVec.x, newVec.y);
        object_to_luaval(tolua_S, "b2Vec2", (b2Vec2 *)ret);
        tolua_register_gc(tolua_S, lua_gettop(tolua_S));
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2RayCastInput:p1", argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_get_b2RayCastInput_p1'.", &tolua_err);
    return 0;
#endif
}

int tolua_set_b2RayCastInput_p1(lua_State *tolua_S){
    int argc = 0;
    b2RayCastInput *cobj = nullptr;
    bool ok = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2RayCastInput", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2RayCastInput *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_get_b2RayCastInput_p1'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    do
    {
        if(argc == 1){
            b2Vec2 *argc0;
            ok &= luaval_to_object<b2Vec2>(tolua_S, 2, "b2Vec2", &argc0);
            if(!ok){
                
            }
            cobj->p1 = *argc0;
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2RayCastInput:p1", argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_get_b2RayCastInput_p1'.", &tolua_err);
    return 0;
#endif
}

int tolua_get_b2RayCastInput_p2(lua_State *tolua_S){
    int argc = 0;
    b2RayCastInput *cobj = nullptr;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2RayCastInput", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2RayCastInput *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_get_b2RayCastInput_p2'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if(argc == 0){
        b2Vec2 newVec = cobj->p2;
        // object_to_luaval<b2Vec2>(tolua_S, "b2Vec2", &ret);
        b2Vec2 *ret = new b2Vec2(newVec.x, newVec.y);
        object_to_luaval(tolua_S, "b2Vec2", (b2Vec2 *)ret);
        tolua_register_gc(tolua_S, lua_gettop(tolua_S));
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2RayCastInput:p2", argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_get_b2RayCastInput_p2'.", &tolua_err);
    return 0;
#endif
}

int tolua_set_b2RayCastInput_p2(lua_State *tolua_S){
    int argc = 0;
    b2RayCastInput *cobj = nullptr;
    bool ok = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2RayCastInput", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2RayCastInput *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_get_b2RayCastInput_p2'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    do
    {
        if(argc == 1){
            b2Vec2 *argc0;
            ok &= luaval_to_object<b2Vec2>(tolua_S, 2, "b2Vec2", &argc0);
            if(!ok){
                break;
            }
            cobj->p1 = *argc0;
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2RayCastInput:p2", argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_get_b2RayCastInput_p2'.", &tolua_err);
    return 0;
#endif
}


int tolua_get_b2RayCastInput_maxFraction(lua_State *tolua_S){
    int argc = 0;
    b2RayCastInput *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2RayCastInput", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2RayCastInput *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_get_b2RayCastInput_maxFraction'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if(argc == 0){
        float32 ret = cobj->maxFraction;
        tolua_pushnumber(tolua_S, (lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2RayCastInput:maxFraction", argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_get_b2RayCastInput_maxFraction'.", &tolua_err);
    return 0;
#endif
}

int tolua_set_b2RayCastInput_maxFraction(lua_State *tolua_S){
    int argc = 0;
    b2RayCastInput *cobj = nullptr;
    bool ok = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2RayCastInput", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2RayCastInput *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_get_b2RayCastInput_maxFraction'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    do
    {
        if(argc == 1){
            double argc0;
            ok &= luaval_to_number(tolua_S, 2,  &argc0, "b2RayCastInput:maxFraction");
            if(!ok){
                break;
            }
            cobj -> maxFraction = argc0;
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2RayCastInput:maxFraction", argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_get_b2RayCastInput_maxFraction'.", &tolua_err);
    return 0;
#endif
}

int lua_register_cocos2dx_b2RayCastInput(lua_State *tolua_S){
   tolua_usertype(tolua_S, "b2RayCastInput");
    tolua_cclass(tolua_S, "b2RayCastInput", "b2RayCastInput", "",nullptr);
    tolua_beginmodule(tolua_S, "b2RayCastInput");
        tolua_variable(tolua_S,"p1",tolua_get_b2RayCastInput_p1,tolua_set_b2RayCastInput_p1);
        tolua_variable(tolua_S,"p2",tolua_get_b2RayCastInput_p2,tolua_set_b2RayCastInput_p2);
        tolua_variable(tolua_S,"maxFraction",tolua_get_b2RayCastInput_maxFraction,tolua_set_b2RayCastInput_maxFraction);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(b2RayCastInput).name();
    g_luaType[typeName] = "b2RayCastInput";
    g_typeCast["b2RayCastInput"] = "b2RayCastInput";
}

int tolua_set_b2RayCastOutput_normal(lua_State *tolua_S){
    int argc = 0;
    b2RayCastOutput *cobj = nullptr;
    bool ok = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2RayCastOutput", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2RayCastOutput *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_get_b2RayCastOutput_normal'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    do
    {
        if(argc == 1){
            b2Vec2 *argc0;
            ok &= luaval_to_object<b2Vec2>(tolua_S, 2, "b2Vec2", &argc0);
            if(!ok){
                break;
            }
            cobj->normal = *argc0;
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2RayCastOutput:normal", argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_get_b2RayCastOutput_normal'.", &tolua_err);
    return 0;
#endif
}

int tolua_get_b2RayCastOutput_normal(lua_State *tolua_S){
    int argc = 0;
    b2RayCastOutput *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2RayCastOutput", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2RayCastOutput *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_get_b2RayCastOutput_normal'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if(argc == 0){
        b2Vec2 newVec = cobj->normal;
        // object_to_luaval<b2Vec2>(tolua_S, "b2Vec2", &ret);
        b2Vec2 *ret = new b2Vec2(newVec.x, newVec.y);
        object_to_luaval(tolua_S, "b2Vec2", (b2Vec2 *)ret);
        tolua_register_gc(tolua_S, lua_gettop(tolua_S));
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2RayCastOutput:maxFraction", argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_get_b2RayCastOutput_normal'.", &tolua_err);
    return 0;
#endif
}

int tolua_get_b2RayCastOutput_fraction(lua_State *tolua_S){
    int argc = 0;
    b2RayCastOutput *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2RayCastOutput", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2RayCastOutput *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_get_b2RayCastOutput_fraction'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if(argc == 0){
        float32 ret = cobj->fraction;
        tolua_pushnumber(tolua_S, (lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2RayCastOutput:fraction", argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_get_b2RayCastOutput_fraction'.", &tolua_err);
    return 0;
#endif
}

int tolua_set_b2RayCastOutput_fraction(lua_State *tolua_S){
    int argc = 0;
    b2RayCastOutput *cobj = nullptr;
    bool ok = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2RayCastOutput", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2RayCastOutput *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_set_b2RayCastOutput_fraction'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    do
    {
        if(argc == 1){
            double argc0;
            ok &= luaval_to_number(tolua_S, 2,  &argc0, "b2RayCastOutput:maxFraction");
            if(!ok){
                break;
            }
            cobj -> fraction = argc0;
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2RayCastOutput:maxFraction", argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_set_b2RayCastOutput_fraction'.", &tolua_err);
    return 0;
#endif
}

int lua_register_cocos2dx_b2RayCastOutput(lua_State *tolua_S){
    tolua_usertype(tolua_S, "b2RayCastOutput");
    tolua_cclass(tolua_S, "b2RayCastOutput", "b2RayCastOutput", "",nullptr);
    tolua_beginmodule(tolua_S, "b2RayCastOutput");
        tolua_variable(tolua_S,"normal",tolua_get_b2RayCastOutput_normal, tolua_set_b2RayCastOutput_normal);
        tolua_variable(tolua_S,"fraction",tolua_get_b2RayCastOutput_fraction, tolua_set_b2RayCastOutput_fraction);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(b2RayCastOutput).name();
    g_luaType[typeName] = "b2RayCastOutput";
    g_typeCast["b2RayCastOutput"] = "b2RayCastOutput";
}

int lua_register_cocos2dx_b2AABB(lua_State *tolua_S){
    tolua_usertype(tolua_S, "b2AABB");
    tolua_cclass(tolua_S, "b2AABB", "b2AABB", "",nullptr);
    tolua_beginmodule(tolua_S, "b2AABB");

    tolua_endmodule(tolua_S);
    std::string typeName = typeid(b2AABB).name();
    g_luaType[typeName] = "b2AABB";
    g_typeCast["b2AABB"] = "b2AABB";
    return 1;
}

int tolua_LuaBox2D_b2Transform_new(lua_State *tolua_S){
    int argc = 0;
    b2Transform *cobj = nullptr;
    bool ok = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

    cobj = (b2Transform *)tolua_tousertype(tolua_S, 1, 0);

    argc = lua_gettop(tolua_S) - 1;
    do
    {
        if (argc == 0)
        {
            if (!ok)
            {
                tolua_error(tolua_S, "invalid arguments in function 'tolua_LuaBox2D_b2Transform_new'", nullptr);
                return 0;
            }
            b2Transform *ret = new b2Transform();
            object_to_luaval<b2Transform>(tolua_S, "b2Transform", (b2Transform *)ret);
            tolua_register_gc(tolua_S, lua_gettop(tolua_S));
            return 1;
        }
    } while (0);

    do
    {
        if (argc == 2)
        {
           const b2Vec2 *argc0;
            ok &= luaval_to_object<const b2Vec2>(tolua_S, 2, "const b2Vec2", &argc0);

            if (!ok)
            {
                break;
            }
           const b2Rot *arg1;

            ok &= luaval_to_object<const b2Rot>(tolua_S, 2, "const b2Rot", &arg1);
            if (!ok)
            {
                break;
            }
            b2Transform *ret = new b2Transform(*argc0, *arg1);
            object_to_luaval<b2Transform>(tolua_S, "b2Transform", (b2Transform *)ret);
            tolua_register_gc(tolua_S, lua_gettop(tolua_S));
            return 1;
        }
    } while (0);

    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2Transform:new", argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2Transform_new'.", &tolua_err);
#endif
    return 0;
}

int tolua_LuaBox2D_b2Transform_SetIdentity(lua_State *tolua_S){
    int argc = 0;
    b2Transform *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

    cobj = (b2Transform *)tolua_tousertype(tolua_S, 1, 0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2Transform_SetIdentity'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if (argc == 0)
    {
        cobj -> SetIdentity();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2Transform:SetIdentity", argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2Transform_SetIdentity'.", &tolua_err);
#endif
    return 0;
}

int tolua_LuaBox2D_b2Transform_Set(lua_State *tolua_S){
    int argc = 0;
    b2Transform *cobj = nullptr;
    bool ok = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

    cobj = (b2Transform *)tolua_tousertype(tolua_S, 1, 0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'b2Transform' in function 'tolua_LuaBox2D_b2Transform_Set'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    do
    {
        if (argc == 2)
        {
           const b2Vec2 *argc0;
            ok &= luaval_to_object<const b2Vec2>(tolua_S, 2, "const b2Vec2", &argc0);

            if (!ok)
            {
                break;
            }
            double argc1;
            ok &= luaval_to_number(tolua_S, 3, &argc1, "tolua_LuaBox2D_b2Transform_Set");
            if (!ok)
            {
                break;
            }
            cobj->Set(*argc0, argc1);
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);

    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2Transform:Set", argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2Transform_new'.", &tolua_err);
#endif
    return 0;
}

int lua_register_cocos2dx_b2Transform(lua_State *tolua_S){
    tolua_usertype(tolua_S, "b2Transform");
    tolua_cclass(tolua_S, "b2Transform", "b2Transform", "",nullptr);
    tolua_beginmodule(tolua_S, "b2Transform");
        tolua_function(tolua_S, "new", tolua_LuaBox2D_b2Transform_new);
        tolua_function(tolua_S, ".call", tolua_LuaBox2D_b2Transform_new);
        tolua_function(tolua_S, "SetIdentity", tolua_LuaBox2D_b2Transform_SetIdentity);
        tolua_function(tolua_S, "Set", tolua_LuaBox2D_b2Transform_Set);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(b2Transform).name();
    g_luaType[typeName] = "b2Transform";
    g_typeCast["b2Transform"] = "b2Transform";
    return 1; 
}

int tolua_LuaBox2D_b2Rot_new(lua_State *tolua_S){
    int argc = 0;
    b2Rot *cobj = nullptr;
    bool ok = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

    cobj = (b2Rot *)tolua_tousertype(tolua_S, 1, 0);
    argc = lua_gettop(tolua_S) - 1;
    do
    {
        if (argc == 0)
        {
            if (!ok)
            {
                tolua_error(tolua_S, "invalid arguments in function 'tolua_LuaBox2D_b2Rot_new'", nullptr);
                return 0;
            }
            b2Rot *ret = new b2Rot();
            object_to_luaval<b2Rot>(tolua_S, "b2Rot", (b2Rot *)ret);
            tolua_register_gc(tolua_S, lua_gettop(tolua_S));
            return 1;
        }
    } while (0);

    do
    {
        if (argc == 1)
        {
            double argc0;
            ok &= luaval_to_number(tolua_S, 2, &argc0, "tolua_LuaBox2D_b2Rot_new");
            if (!ok)
            {
                break;
            }
            b2Rot *ret = new b2Rot(argc0);
            object_to_luaval<b2Rot>(tolua_S, "b2Rot", (b2Rot *)ret);
            tolua_register_gc(tolua_S, lua_gettop(tolua_S));
            return 1;
        }
    } while (0);

    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2Rot", argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2Rot_new'.", &tolua_err);
#endif
    return 0;
}


int tolua_LuaBox2D_b2Rot_Set(lua_State *tolua_S){
    int argc = 0;
    b2Rot *cobj = nullptr;
    bool ok = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

    cobj = (b2Rot *)tolua_tousertype(tolua_S, 1, 0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2Rot_Set'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    do
    {
        if (argc == 1)
        {
            double argc0;
            ok &= luaval_to_number(tolua_S, 3, &argc0, "tolua_LuaBox2D_b2Rot_Set");
            if (!ok)
            {
                break;
            }
            cobj->Set(argc0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);

    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2Rot", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2Rot_Set'.", &tolua_err);
#endif
    return 0;
}

int tolua_LuaBox2D_b2Rot_SetIdentity(lua_State *tolua_S){
    int argc = 0;
    b2Rot *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

    cobj = (b2Rot *)tolua_tousertype(tolua_S, 1, 0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2Rot_SetIdentity'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if (argc == 0)
    {
        cobj -> SetIdentity();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2Rot", argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2Rot_SetIdentity'.", &tolua_err);
#endif
    return 0;   
}

int tolua_LuaBox2D_b2Rot_GetAngle(lua_State *tolua_S){
    int argc = 0;
    b2Rot *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

    cobj = (b2Rot *)tolua_tousertype(tolua_S, 1, 0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2Rot_SetIdentity'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if (argc == 0)
    {
        float32 ret = cobj -> GetAngle();
        tolua_pushnumber(tolua_S, (lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2Rot", argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2Rot_SetIdentity'.", &tolua_err);
#endif
    return 0;  
}

int tolua_LuaBox2D_b2Rot_GetXAxis(lua_State *tolua_S){
    int argc = 0;
    b2Rot *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

    cobj = (b2Rot *)tolua_tousertype(tolua_S, 1, 0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2Rot_GetXAxis'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if (argc == 0)
    {

        b2Vec2 newVec = cobj -> GetXAxis();
        b2Vec2 *ret = new b2Vec2(newVec.x, newVec.y);
        object_to_luaval(tolua_S, "b2Vec2", (b2Vec2 *)ret);
        tolua_register_gc(tolua_S, lua_gettop(tolua_S));
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2Rot:GetXAxis", argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2Rot_GetXAxis'.", &tolua_err);
#endif
    return 0;   
}

int tolua_LuaBox2D_b2Rot_GetYAxis(lua_State *tolua_S){
    int argc = 0;
    b2Rot *cobj = nullptr;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

    cobj = (b2Rot *)tolua_tousertype(tolua_S, 1, 0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_b2Rot_GetYAxis'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if (argc == 0)
    {

        b2Vec2 newVec = cobj -> GetYAxis();
        b2Vec2 *ret = new b2Vec2(newVec.x, newVec.y);
        object_to_luaval(tolua_S, "b2Vec2", (b2Vec2 *)ret);
        tolua_register_gc(tolua_S, lua_gettop(tolua_S));
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "GetYAxis:GetYAxis", argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_b2Rot_GetYAxis'.", &tolua_err);
#endif
    return 0; 
}

int tolua_LuaBox2D_get_b2Rot_s(lua_State *tolua_S){
    int argc = 0;
    b2Rot *cobj = nullptr;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2Rot", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2Rot *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_get_b2Rot_s'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if(argc == 0){
        float32 ret = cobj->s;
        tolua_pushnumber(tolua_S, (lua_Number)ret);
        return 1;
    } 
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2Rot:s", argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_get_b2Rot_s'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_set_b2Rot_s(lua_State *tolua_S){
    int argc = 0;
    b2Rot *cobj = nullptr;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2Rot", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2Rot *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_set_b2Rot_s'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if(argc == 1){
        double argc0;
        luaval_to_number(tolua_S, 2, &argc0, "tolua_LuaBox2D_set_b2Rot_s");
        cobj->s = argc0;
        lua_settop(tolua_S, 1);
        return 1;
    } 
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2Rot:s", argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_set_b2Rot_s'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_get_b2Rot_c(lua_State *tolua_S){
    int argc = 0;
    b2Rot *cobj = nullptr;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2Rot", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2Rot *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_get_b2Rot_c'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if(argc == 0){
        float32 ret = cobj->c;
        tolua_pushnumber(tolua_S, (lua_Number)ret);
        return 1;
    } 
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2Rot:c", argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_get_b2Rot_c'.", &tolua_err);
    return 0;
#endif
}

int tolua_LuaBox2D_set_b2Rot_c(lua_State *tolua_S){
    int argc = 0;
    b2Rot *cobj = nullptr;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S, 1, "b2Rot", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (b2Rot *)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'tolua_LuaBox2D_set_b2Rot_c'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if(argc == 1){
        double argc0;
        luaval_to_number(tolua_S, 2, &argc0, "tolua_LuaBox2D_set_b2Rot_c");
        cobj->c = argc0;
        lua_settop(tolua_S, 1);
        return 1;
    } 
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "b2Rot:c", argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'tolua_LuaBox2D_set_b2Rot_c'.", &tolua_err);
    return 0;
#endif 
}

int lua_register_cocos2dx_b2Rot(lua_State *tolua_S){
    tolua_usertype(tolua_S, "b2Rot");
    tolua_cclass(tolua_S, "b2Rot", "b2Rot", "",nullptr);
    tolua_beginmodule(tolua_S, "b2Rot");
        tolua_function(tolua_S,"new", tolua_LuaBox2D_b2Rot_new);
        tolua_function(tolua_S,".call", tolua_LuaBox2D_b2Rot_new);
        tolua_function(tolua_S,"Set", tolua_LuaBox2D_b2Rot_Set);
        tolua_function(tolua_S,"SetIdentity", tolua_LuaBox2D_b2Rot_SetIdentity);
        tolua_function(tolua_S,"GetAngle", tolua_LuaBox2D_b2Rot_GetAngle);
        tolua_function(tolua_S,"GetXAxis", tolua_LuaBox2D_b2Rot_GetXAxis);
        tolua_function(tolua_S,"GetYAxis", tolua_LuaBox2D_b2Rot_GetYAxis);
        tolua_variable(tolua_S,"s", tolua_LuaBox2D_get_b2Rot_s, tolua_LuaBox2D_set_b2Rot_s);
        tolua_variable(tolua_S,"c" ,tolua_LuaBox2D_get_b2Rot_c, tolua_LuaBox2D_set_b2Rot_c);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(b2Rot).name();
    g_luaType[typeName] = "b2Rot";
    g_typeCast["b2Rot"] = "b2Rot";
    return 1; 
}

TOLUA_API int register_box2d_manual(lua_State *tolua_S)
{

    tolua_open(tolua_S);
    tolua_module(tolua_S, NULL, 1);
    tolua_beginmodule(tolua_S, NULL);
        lua_register_cocos2dx_b2Vec2(tolua_S);
        lua_register_cocos2dx_b2world(tolua_S);
        lua_register_cocos2dx_b2BodyDef(tolua_S);
        lua_register_cocos2dx_b2Body(tolua_S);
        lua_register_cocos2dx_b2Filter(tolua_S);
        lua_register_cocos2dx_b2FixtureDef(tolua_S);
        lua_register_cocos2dx_b2Fixture(tolua_S);
        lua_register_cocos2dx_b2JointDef(tolua_S);
        lua_register_cocos2dx_b2Joint(tolua_S);
        lua_register_cocos2dx_b2GearJointDef(tolua_S);
        lua_register_cocos2dx_b2GearJoint(tolua_S);
        lua_register_cocos2dx_b2Shape(tolua_S);
        lua_register_cocos2dx_b2CircleShape(tolua_S);
        lua_register_cocos2dx_b2ChainShape(tolua_S);
        lua_register_cocos2dx_b2EdgeShape(tolua_S);
        lua_register_cocos2dx_b2PolygonShape(tolua_S);
        lua_register_cocos2dx_b2BlockAllocator(tolua_S);
        lua_register_cocos2dx_b2Contact(tolua_S);
        lua_register_cocos2dx_b2ContactListener(tolua_S);
        lua_register_cocos2dx_b2DistanceJointDef(tolua_S);
        lua_register_cocos2dx_b2DistanceJoint(tolua_S);
        lua_register_cocos2dx_b2MotorJointDef(tolua_S);
        lua_register_cocos2dx_b2MotorJoint(tolua_S);
        lua_register_cocos2dx_b2PrismaticJointDef(tolua_S);
        lua_register_cocos2dx_b2PrismaticJoint(tolua_S);
        // ADD BY YQS ===b2FrictionJoint 20201208
        lua_register_cocos2dx_b2FrictionJointDef(tolua_S);
        lua_register_cocos2dx_b2FrictionJoint(tolua_S);
        lua_register_cocos2dx_b2MouseJointDef(tolua_S);
        lua_register_cocos2dx_b2MouseJoint(tolua_S);
        lua_register_cocos2dx_b2PulleyJointDef(tolua_S);
        lua_register_cocos2dx_b2PulleyJoint(tolua_S);
        lua_register_cocos2dx_b2RevoluteJointDef(tolua_S);
        lua_register_cocos2dx_b2RevoluteJoint(tolua_S);
        lua_register_cocos2dx_b2WheelJointDef(tolua_S);
        lua_register_cocos2dx_b2WheelJoint(tolua_S);
        lua_register_cocos2dx_b2RopeJointDef(tolua_S);
        lua_register_cocos2dx_b2RopeJoint(tolua_S);
        lua_register_cocos2dx_b2WeldJointDef(tolua_S);
        lua_register_cocos2dx_b2WeldJoint(tolua_S);

        lua_register_cocos2dx_b2RayCastInput(tolua_S);
        lua_register_cocos2dx_b2RayCastOutput(tolua_S);
        lua_register_cocos2dx_b2AABB(tolua_S);
        lua_register_cocos2dx_b2Transform(tolua_S);
        lua_register_cocos2dx_b2Rot(tolua_S);

    tolua_endmodule(tolua_S);
    tolua_constant(tolua_S, "b2_staticBody", b2_staticBody);
    tolua_constant(tolua_S, "b2_kinematicBody", b2_kinematicBody);
    tolua_constant(tolua_S, "b2_dynamicBody", b2_dynamicBody);
    return 1;
}
