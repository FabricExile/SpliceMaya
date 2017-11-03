Fabric Splice for Autodesk Maya
===================================
A Fabric Splice integration for Maya.

Fabric Splice for Maya allows you to make use of the Fabric Core inside of Maya and use KL to perform computations inside of Maya using a custom node.

Repository Status
=================

This repository will be maintained and kept up to date by Fabric Software to match the latest Fabric Core / Fabric Splice.

Supported platforms
===================

To date all three major platforms (windows, linux, osx) are supported, if you build the thirdparty dependencies for the corresponding platform.

Building
========

A scons (http://www.scons.org/) build script is provided. Fabric Splice for Maya depends on
* A dynamic build of Fabric Core (matching the latest version).
* The SpliceAPI repository checked out one level above (http://github.com/fabric-engine/SpliceAPI)
* The FTL (Fabric Template Library) repository (it can be pulled here: https://github.com/fabric-engine/FTL).
* The FabricUI repository (http://github.com/fabric-engine/FabricUI)
* A build of Boost (version 1.55.0 recommended. http://www.boost.org/)

Fabric Splice for Maya requires a certain folder structure to build properly. You will need to have the SpliceAPI cloned as well on your drive, as such:

    SpliceAPI
    Applications/SpliceMaya

    You can use the bash script below to clone the repositories accordingly:

    git clone git@github.com:fabric-engine/SpliceAPI.git
    mkdir Applications
    cd Applications
    git clone git@github.com:fabric-engine/SpliceMaya.git
    cd SpliceMaya
    scons

To inform scons where to find the Fabric Core includes as well as the thirdparty libraries, you need to set the following environment variables:

* FABRIC_BUILD_OS: Should be the type of OS you are building for (Windows, Darwin, Linux)
* FABRIC_BUILD_ARCH: The architecture you are building for (x86, x86_64)
* FABRIC_BUILD_TYPE: The optimization type (Release, Debug)
* FABRIC_SPLICE_VERSION: Refers to the version you want to build. Typically the name of the branch (for example 2.6.0)
* FABRIC_DIR: Should point to Fabric Engine's installation folder.
* FABRIC_UI_DIR: Should point to the source code of FabricUI.
* MAYA_INCLUDE_DIR: The include folder of the Autodesk Maya installation. (for example: C:\Program Files\Autodesk\Maya2017\include)
* MAYA_LIB_DIR: The library folder of the Autodesk Maya installation. (for example: C:\Program Files\Autodesk\Maya2017\lib)
* MAYA_BIN_DIR: The bin folder of the Autodesk Maya installation. It should contain a working `moc` (Qt's meta-object compiler) executable.
* MAYA_VERSION: The Maya version to use including eventual SP suffix. (for example: 2014SP2)
* BOOST_DIR: The folder of a Boost installation.
* BOOST_VERSION: Version of Boost libraries (e.g., 1.65)
* MSVC_VERSION: Microsoft Visual Studio Compiler version (defaults to 12.0)
* GCC_ROOT (optional): The compiler can be overridden by using this variable (`$GCC_ROOT/bin/gcc` and `$GCC_ROOT/bin/g++` will be used)

The temporary files will be built into the *.build* folder, while the structured output files will be placed in the *.stage* folder.

To perform a build you can just run

    scons all -j8

To clean the build you can run

    scons clean

License
==========

The license used for this DCC integration can be found in the root folder of this repository.
