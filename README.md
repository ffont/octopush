<p align="center">
<img src="docs/logo_main_colour.png" width="250" title="Octopush logo" />
</p>

## What is Octopush?

Well, this is just work in progress, don't ask too many quesitons ;) I'm currently just working on a technical solution to bring lo life some ideas I have in mind. Once I get to an initial solution I'm confirtable with, I'll update this file and share more details.


## Building Octopush

### OctopushOS

OcotpushOS is a standard JUCE app and can be edited and built using standard JUCE workflows. For development, you'll also want to build Projucer so you can edit `OctopushOS.jucer` file. Even though you can use pre-built Projucer downloaded from JUCE website, here we provide a script to build a GPL-enabled version of Projucer.

#### Repository checkout

You need to checkout the code including submodules. This will download source code for all required 3rd party libraries (JUCE, etc.)

```
git clone https://github.com/ffont/octopush.git && cd octopush && git submodule update --init
```

#### Building Projucer

A utility script is provided to build Projucer in GPL mode. `cd` into the cloned repository and run the following:

```
cd scripts
./build_release_projucer_gpl
```

The generated executable will be placed in `OctopushOS/3rdParty/juce/extras/Projucer/Builds/MacOSX/build/Release/Projucer` (MacOSX) or `OctopushOS/3rdParty/juce/extras/Projucer/Builds/LinuxMakefile/build/Release/Projucer` (Linux) depending on the platform you're running it from.

If building from Linux, the following dependencies need to be installed:
```
# JUCE dependencies
apt-get install clang git ladspa-sdk freeglut3-dev g++ libasound2-dev libcurl4-openssl-dev libfreetype6-dev libjack-jackd2-dev libx11-dev libxcomposite-dev libxcursor-dev libxinerama-dev libxrandr-dev mesa-common-dev webkit2gtk-4.0 juce-tools

# push2-display-with-juce dependencies
apt-get install libusb-1.0-0-dev
```
This list of dependencies was taken from [this forum thread](https://forum.juce.com/t/list-of-juce-dependencies-under-linux/15121/31). It could be the case that some of these are actually not needed, I have not tested them individually.


#### Development build

To build OctopushOS during development you can use project files for Xcode (MacOSX) or the Makefile (Linux). You'll find these in the `OctopushOS/Builds/` folder. Alternatively you can use the provided utility script. `cd` into the cloned repository and run the following:

```
cd scripts
./build_debug_octopushOS
```

The generated executable will be placed in `OctopushOS/Builds/MacOSX/build/Debug/OctopushOS` (MacOSX) or `OctopushOS/Builds/LinuxMakefile/build/Debug/OctopushOS ` (Linux) depending on the platform you're running it from.


#### Release build

A utility script is provided to build OctopushOS in release mode. `cd` into the cloned repository and run the following:

```
cd scripts
./build_release_octopushOS
```

The generated executable will be placed in `OctopushOS/Builds/MacOSX/build/Release/OctopushOS` (MacOSX) or `OctopushOS/Builds/LinuxMakefile/build/Release/OctopushOS ` (Linux) depending on the platform you're running it from.


### Command line arguments

When running OctopushOS executable the following command line arguments can be used:

 * `-dfr #`: set the display frame rate in Hz (e.g. `-dfr 30`). Defaults to `60`.
 * `-sur #`: set the rate in Hz at which state object is updated (e.g. `-sur 5`). Defaults to `15`.
 * `-eur #`: set the maximum rate in Hz at which Push2 encoder recevied messages are processed (e.g. `-eur 10`). Messages received exceeding this rate are discared. This is because Push2 sends many messages when rotating encoders and it can collapse the app. Defaults to `15`.
 * `-sim show/hide`: set whether the Push2 simulator should be shown or not (e.g. `-sim show`). By default, the simulator will only be shown if app can't connect to Push2 and app is compiled in Debug mode.
 * `-pos`: sets whether OcotpushOS should autoplay right after the engine is loaded. By default this option is not set.
 * `-minimal`: will create an audio engine with only 1 track and no effects.


## Licenses

Octopush is released under the **GPLv3** open source software license (see [LICENSE](https://github.com/ffont/octopush/blob/master/LICENSE) file) with the code being available at  [https://github.com/ffont/octopush](https://github.com/ffont/octopush). Octopush uses the following open source software libraries: 

* [juce](https://juce.com), available under GPLv3 license ([@724ae27](https://github.com/WeAreROLI/JUCE/tree/724ae27c71ef809b836df06713cf9e50bc14162b), v5.4.5)
* [tracktion_engine](https://github.com/Tracktion/tracktion_engine), available under GPLv3 license ([@c686909](https://github.com/Tracktion/tracktion_engine/tree/c686909a062a44171c0215cc8a0c1fbbcc320a95))
* [libusb](https://github.com/libusb/libusb), availavle under LGPLv2.1 ([@1734873](https://github.com/libusb/libusb/tree/17348731b48702cece1bc783b3764975e495840d))
* [push2-display-with-juce](https://github.com/Ableton/push2-display-with-juce), available under MIT  ([@3107788](https://github.com/Ableton/push2-display-with-juce/tree/310778820f0182254652af405002b9e5bcd2d548))
