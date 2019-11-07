<p align="center">
<img src="logo_main_colour.png" width="250" title="Octopush logo" />
</p>

## What is Octopush?

Well, this is just work in progress, don't make too many quesitons ;) I'm currently working on a technical solution to bring lo life some ideas I have in mind. Once I get to a solution I'm confirtable with, I'll update this file and provide more details.


## Building Octopush


### OctopushOS

OcotpushOS is a standard JUCE app and can be edited and built using standard JUCE workflows. For development, you'll also want to build Projucer so you can edit `OctopushOS.jucer` file. Even though you can use pre-built Projucer downloaded from JUCE website, here we provide a script to build a GPL-enabled version of Projucer.

#### Repository checkout

You need to checkout the code including submodules. This will download source code for all required 3rd party libraries (JUCE, etc.)

```
git clone --recurse-submodules git@github.com:ffont/octopush.git
```

#### Building Projucer

A utility script is provided to build Projucer in GPL mode. `cd` into the cloned repository and run the following:

```
cd OctospushOS/Scripts
./build_projucer_gpl
```

The generated executable will be placed in `OctopushOS/3rdParty/juce/extras/Projucer/Builds/MacOSX/build/Release/Projucer` (MacOSX) or `OctopushOS/3rdParty/juce/extras/Projucer/Builds/LinuxMakefile/build/Release/Projucer` (Linux) depending on the platform you're running it from.


#### Development build

To build OctopushOS during development you can do it from Xcode (MacOSX) or from the Makefile (Linux). You'll find these in the `OctopushOS/Builds/` folder.


#### Release build

A utility script is provided to build OctopushOS in release mode. `cd` into the cloned repository and run the following:

```
cd OctospushOS/Scripts
./build_octopushOS
```

The generated executable will be placed in `OctopushOS/Builds/MacOSX/build/Release/OctopushOS` (MacOSX) or `OctopushOS/Builds/LinuxMakefile/build/Release/OctopushOS ` (Linux) depending on the platform you're running it from.


## Licenses

Octopush is released under the **GPLv3** open source software license (see [LICENSE](https://github.com/ffont/octopush/blob/master/LICENSE) file) with the code being available at  [https://github.com/ffont/octopush](https://github.com/ffont/octopush). Octopush uses the following open source software libraries: 

* [juce](https://juce.com), available under GPLv3 license ([@724ae27](https://github.com/WeAreROLI/JUCE/tree/724ae27c71ef809b836df06713cf9e50bc14162b), v5.4.5)
* [tracktion_engine](https://github.com/Tracktion/tracktion_engine), available under GPLv3 license ([@c686909](https://github.com/Tracktion/tracktion_engine/tree/c686909a062a44171c0215cc8a0c1fbbcc320a95))
* [libusb](https://github.com/libusb/libusb), availavle under LGPLv2.1 ([@1734873](https://github.com/libusb/libusb/tree/17348731b48702cece1bc783b3764975e495840d))
* [push2-display-with-juce](https://github.com/Ableton/push2-display-with-juce), available under MIT  ([@3107788](https://github.com/Ableton/push2-display-with-juce/tree/310778820f0182254652af405002b9e5bcd2d548))
