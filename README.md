# OpenGL rendering engine

A simple rendering engine built with C++ and OpenGL.

---

## Background information

Read more on the technical details in the [documentation folder](.github/docs/README.md)

## Installing dependencies

You'll need to build Vcpkg (which is included as submodule) by executing the command below.

```
./vcpkg/bootstrap-vcpkg.sh
```

After that's done, you can run the following command to install the required packages for this engine.

```
./vcpkg/vcpkg install
```

## Building

This project uses Cmake for building the source code. Run the commands below to generate the cmake files and build the binary.

```
cmake -B build
cmake --build build
```

## Running the application

The resulting binary can be found in the `build/` folder. You can run it by executing the command below or clicking the executable (`main`) in your file explorer.

```
./build/main
```

## To Do

- [x] Make the engine a separate library
- [ ] Separate application and hardware interfacing
- [ ] Add GUI components
- [ ] Move the demo to a separate repository
- [ ] Add support for Vulkan
