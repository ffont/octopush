# Octopush


## Buildin Octopush


### OctopushOS

#### Repository checkout

You need to checkout the code including submodules. This will download source code for all required 3rd party libraries (juce, etc.)

```
git clone --recurse-submodules git@github.com:ffont/octopush.git
```

#### Building Projucer

OcotpushOS is a standard JUCE app and can be edited and built using standard JUCE workflows.

A utility script is provided to build Projucer in GPL mode which will allow you to edit the `OctopushOS.jucer` file. After cloning the repository (with submodules), run the following:

```
cd OctospushOS/Scripts
./build_projucer_gpl
```

The executable for projucer will be placed in `OctospushOS/3rdParty/juce/extras/Projucer/Builds/MacOSX/build/Release/Projucer` for MacOSX, and in `OctospushOS/3rdParty/juce/extras/Projucer/Builds/LinuxMakefile/build/Release/Projucer` for Linux.


#### Development build

To build OctopushOS during development use the Xcode file/Makefile available for MacOSX and Linux respectively. See the `OctopushOS/Builds` folder.


#### Release build

A utility script is provided to build OctopushOS in release mode:

```
cd OctospushOS/Scripts
./build_OctopushOS
```

Alternatively, in MacOSX it can also be built from XCode setting the scheme to Release mode.


## Licenses

Octopush is released under the **GPLv3** open source software license (see [LICENSE](https://github.com/ffont/octopush/blob/master/LICENSE) file) with the code being available at  [https://github.com/ffont/octopush](https://github.com/ffont/octopush). Octopush uses the following open source software libraries: 


* [juce](https://juce.com), available under GPLv3 license ([@724ae27](https://github.com/WeAreROLI/JUCE/tree/724ae27c71ef809b836df06713cf9e50bc14162b), v5.4.5)
* [tracktion_engine](https://github.com/Tracktion/tracktion_engine), available under GPLv3 license ([@c686909](https://github.com/Tracktion/tracktion_engine/tree/c686909a062a44171c0215cc8a0c1fbbcc320a95))
* [libusb](https://github.com/libusb/libusb), availavle under LGPLv2.1 ([@1734873](https://github.com/libusb/libusb/tree/17348731b48702cece1bc783b3764975e495840d))
* [push2-display-with-juce](https://github.com/Ableton/push2-display-with-juce), available under MIT  ([@3107788](https://github.com/Ableton/push2-display-with-juce/tree/310778820f0182254652af405002b9e5bcd2d548))
