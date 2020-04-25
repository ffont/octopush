#!/bin/bash

echo "Sending to board!"
echo "****************"
scp ../OctopushOS/Builds/ELKAudioOS/build/OctopushOS.so mind@elk-pi.local:
scp ../sandobx/octopush_sushi_config.json mind@elk-pi.local:

