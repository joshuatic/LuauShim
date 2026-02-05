# LuauShim

## What this is
A high-performance C++ shim designed to bridge the **Luau** scripting language with C# environments. This was specifically built to power a custom fork of **LuauSharp**, ensuring stable P/Invoke signatures and memory safety across the managed/unmanaged boundary.

I made this for my own future projects, but it's open for anyone looking for a "rock-solid" way to embed Luau in .NET.

## Features
* **Stable Entry Points:** Every function is prefixed (e.g., `bridge_luaL_newstate`) to prevent naming collisions and ensure easy `DllImport` mapping.
* **Memory Safety:** Includes explicit `bridge_free` exports to handle bytecode buffers safely between C++ and C#.
* **Framework Ready:** Designed with a clean lifecycle in mind (State management, Stack operations, and Compilation).

## Licensing
The shim code itself is licensed under **CC0** (No Rights Reserved). You can copy, modify, and distribute it however you like. See the [LICENSE](LICENSE) file for details.

## Third-Party Credits
This project includes and depends on the following third-party software:
* **Luau**: Copyright (c) 2019-2026 Roblox Corporation. Licensed under the **MIT License**.
    * *Note: The Luau license can be found in the `include/deps` folder.*