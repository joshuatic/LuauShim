#include "library.h"
#include <stdlib.h>

// --- State Management ---
LUAU_API lua_State* bridge_luaL_newstate() {
    return luaL_newstate();
}

LUAU_API void bridge_lua_close(lua_State* L) {
    if (L) lua_close(L);
}

LUAU_API void bridge_luaL_openlibs(lua_State* L) {
    if (L) luaL_openlibs(L);
}

// --- Stack Operations ---
LUAU_API int bridge_lua_type(lua_State* L, int idx) {
    return lua_type(L, idx);
}

LUAU_API void bridge_lua_pushcclosurek(lua_State* L, lua_CFunction fn, const char* debugname, int nup, lua_Continuation cont) {
    lua_pushcclosurek(L, fn, debugname, nup, cont);
}

LUAU_API double bridge_lua_tonumberx(lua_State* L, int idx, int* isnum) {
    return lua_tonumberx(L, idx, isnum);
}

LUAU_API bool bridge_lua_toboolean(lua_State* L, int idx) {
    return lua_toboolean(L, idx);
}

LUAU_API const char* bridge_lua_tolstring(lua_State* L, int idx, size_t* len) {
    return lua_tolstring(L, idx, len);
}

LUAU_API void bridge_lua_setfield(lua_State* L, int idx, const char* k) {
    lua_setfield(L, idx, k);
}

LUAU_API void bridge_lua_settop(lua_State* L, int idx) {
    lua_settop(L, idx);
}

// --- Compilation & Memory ---
LUAU_API char* bridge_luau_compile(const char* source, size_t size, lua_CompileOptions* options, size_t* outSize) {
    if (!source) return nullptr;
    return luau_compile(source, size, options, outSize);
}

LUAU_API void bridge_free(void* ptr) {
    if (ptr) free(ptr);
}