#ifndef LUAUSHIM_H
#define LUAUSHIM_H

#include "lua.h"
#include "lualib.h"
#include "luacode.h"

#ifdef _WIN32
    #define LUAU_API extern "C" __declspec(dllexport)
#else
    #define LUAU_API extern "C" __attribute__((visibility("default")))
#endif

LUAU_API lua_State* bridge_luaL_newstate();
LUAU_API void bridge_lua_close(lua_State* L);
LUAU_API void bridge_luaL_openlibs(lua_State* L);
LUAU_API int bridge_lua_type(lua_State* L, int idx);
LUAU_API void bridge_lua_pushcclosurek(lua_State* L, lua_CFunction fn, const char* debugname, int nup, lua_Continuation cont);
LUAU_API double bridge_lua_tonumberx(lua_State* L, int idx, int* isnum);
LUAU_API bool bridge_lua_toboolean(lua_State* L, int idx);
LUAU_API const char* bridge_lua_tolstring(lua_State* L, int idx, size_t* len);
LUAU_API void bridge_lua_setfield(lua_State* L, int idx, const char* k);
LUAU_API void bridge_lua_settop(lua_State* L, int idx);
LUAU_API char* bridge_luau_compile(const char* source, size_t size, lua_CompileOptions* options, size_t* outSize);
LUAU_API void bridge_free(void* ptr);

#endif