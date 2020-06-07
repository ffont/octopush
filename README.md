<p align="center">
<img src="docs/logo_main_colour.png" width="250" title="Octopush logo" />
</p>

## What is Octopush?

Octopush is a work in progrees project to make an **open source stand alone music sequencer and sampler** based on the low-latency real-time **ELK AudioOS** for **Rapsberry Pi**, and using **Abelton's Push2** as a hardware interface. Basically, I want to build by own hardware sampler+sequencer using a Raspberry Pi, a Push2, and reusing existing nice software.

Octopush is a long term project that I'll probably never finish. Hopefully I'll reach to an interesting point someday, and I'll certainly have fun in the way. Or maybe I'll find people who wants to help and we'll make something nice together.

The name "Octopush" comes from the inspiration for this project, which was [this Youtube video](https://www.youtube.com/watch?v=K4VwDtPFDdI) of a jam with an **Octatrack**. Then I thought "I need something like this", but I saw lots of MIDI limitations in it, and then I said "I need to make my own". I have a **Push2**, so I thought that I'd write some software to connect to it and make the instrument. I guess by now the origin of the name is evident, *Octatrack + Push ~= Octopush*. Also by that time I just finished reading [this amazing book about octopuses](https://en.wikipedia.org/wiki/Other_Minds:_The_Octopus,_the_Sea,_and_the_Deep_Origins_of_Consciousness), so it all kind of made sense. 

The current status of the project is that I'm working on a sort of technical solution/proof of concept that connects all the pieces of software and hardware that I want to use. I have made some software that does basic loop playing and step sequencing, and connects to Push2 to use it as the UI nicely. This works fine running on my desktop macOS computer. It also runs fine on the Raspberry Pi. I'm in the process of porting this to the ELK platform to be able to get low-latency multi-channel audio IO when running in the Pi. I almost have it working, but there are still some issues here and there that need fixes. More details below...


## How does Octopush work?

OcotpushOS is implemented as a JUCE audio plug-in and can be edited and built using standard JUCE workflows. It uses the [Trakction Engine](https://github.com/Tracktion/tracktion_engine) to do all the hard audio processing tasks. The plugin runs on the [ELK Audio Os](https://elk.audio) platform (with a Raspberry Pi and the ELK development board, with 8 audio inputs and 8 audio outptus). Ableton Push2 is connected to the Raspberry Pi via USB, and Octopush connects to it to use it as the hardware interface.



## Building Octopush for desktop computers (macOS and linux)


**NOTE**: these steps have been recently tested on macOS and should work well. For linux I have not tested them for a while but I also think it should be working fine.


### Repository checkout

You need to checkout the code including submodules. This will download source code for all required 3rd party libraries (JUCE, etc.)

```
git clone https://github.com/ffont/octopush.git && cd octopush && git submodule update --init
```

### Building Projucer

For development, you'll want to build Projucer so you can edit `OctopushOS.jucer` file. Even though you can use pre-built Projucer downloaded from JUCE website, here we provide a script to build a GPL-enabled version of Projucer. `cd` into the cloned repository and run the following:

```
cd scripts
./build_release_projucer_gpl
```

This builds the audio plugin in several formats as well as astandalone executable. which will be placed in `OctopushOS/3rdParty/juce/extras/Projucer/Builds/MacOSX/build/Release/Projucer` (MacOSX) or `OctopushOS/3rdParty/juce/extras/Projucer/Builds/LinuxMakefile/build/Release/Projucer` (Linux) depending on the platform you're running it from. Plugin version will be palced next to the executables.

If building from Linux, the following dependencies need to be installed:
```
# JUCE dependencies
apt-get install clang git ladspa-sdk freeglut3-dev g++ libasound2-dev libcurl4-openssl-dev libfreetype6-dev libjack-jackd2-dev libx11-dev libxcomposite-dev libxcursor-dev libxinerama-dev libxrandr-dev mesa-common-dev webkit2gtk-4.0 juce-tools

# push2-display-with-juce dependencies
apt-get install libusb-1.0-0-dev
```
This list of dependencies was taken from [this forum thread](https://forum.juce.com/t/list-of-juce-dependencies-under-linux/15121/31). It could be the case that some of these are actually not needed, I have not tested them individually.


**NOTE**: OctopushOS is configured to be built in different plugin formats including legacy VST2. To do that you'll need to place the legacy VST2 framework files. VST2 builds require to have the VST2 sdk properly installed in a folder specified i the projucer file. I enable VST2 target because I need to build Octopush as a plugin for linux when running in Raspberry Pi, and the version I use of JUCE does not support VST3 plugin builds for linux. If you don't want to build VST2, just untick the VST2 option from the jucer file using Projucer.


### Development build

To build OctopushOS during development you can use project files for Xcode (MacOSX) or the Makefile (Linux). You'll find these in the `OctopushOS/Builds/` folder. Alternatively you can use the provided utility script. `cd` into the cloned repository and run the following:

```
cd scripts
./build_debug_octopushOS
```

The generated executable (for the santadalone version) will be placed in `OctopushOS/Builds/MacOSX/build/Debug/OctopushOS` (MacOSX) or `OctopushOS/Builds/LinuxMakefile/build/Debug/OctopushOS ` (Linux) depending on the platform you're running it from. Plugin version will be palced next to the executables.


### Release build

A utility script is provided to build OctopushOS in release mode. `cd` into the cloned repository and run the following:

```
cd scripts
./build_release_octopushOS
```

The generated executable (for the santadalone version) will be placed in `OctopushOS/Builds/MacOSX/build/Release/OctopushOS` (MacOSX) or `OctopushOS/Builds/LinuxMakefile/build/Release/OctopushOS ` (Linux) depending on the platform you're running it from. Plugin version will be palced next to the executables.


## Building Octopush for the ELK platform

TODO


## Licenses

Octopush is released under the **GPLv3** open source software license (see [LICENSE](https://github.com/ffont/octopush/blob/master/LICENSE) file) with the code being available at  [https://github.com/ffont/octopush](https://github.com/ffont/octopush). Octopush uses the following open source software libraries: 

* [juce](https://juce.com), available under GPLv3 license ([@26c9468](https://github.com/WeAreROLI/JUCE/tree/26c9468dc53ee76b836125e397ec4b7fa6417452), v5.4.5)
* [tracktion_engine](https://github.com/Tracktion/tracktion_engine), available under GPLv3 license ([@381e322](https://github.com/Tracktion/tracktion_engine/tree/381e3220571419d726be759f305576bba2df46cc))
* [libusb](https://github.com/libusb/libusb), availavle under LGPLv2.1 ([@1734873](https://github.com/libusb/libusb/tree/17348731b48702cece1bc783b3764975e495840d))
* [push2-display-with-juce](https://github.com/Ableton/push2-display-with-juce), available under MIT  ([@3107788](https://github.com/Ableton/push2-display-with-juce/tree/310778820f0182254652af405002b9e5bcd2d548))
