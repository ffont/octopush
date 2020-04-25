#!/bin/bash

echo "Cross-compiling OctopushOS for ELK!"
echo "***********************************"
docker run --rm -it -v elkvolume:/workdir -v ${PWD}/../:/code/octopush -v ${PWD}/../../ELK/JUCE:/home/sdkuser/JUCE -v ${PWD}/../../VST_SDK/VST2_SDK:/code/VST2_SDK -v ${PWD}/custom-esdk-launch.py:/usr/bin/esdk-launch.py crops/extsdk-container
