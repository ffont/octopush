#!/bin/bash

# Step 0) start docker samba (if not running already)

if docker ps | grep -q 'samba'; then 
    echo "- Docker samba container already running"; 
else
    echo "- Starting docker samba container (might ask for computer's password)"
    docker start samba && sudo ifconfig lo0 127.0.0.2 alias up
fi

# Step 1) Do cross-compilation
echo "- Cross-compiling project (using modified esdk-launch.py file)"
docker run --rm -it -v elkvolume:/workdir -v ${PWD}/../:/code/octopush -v ${PWD}/../../ELK/JUCE:/home/sdkuser/JUCE -v ${PWD}/../../VST_SDK/VST2_SDK:/code/VST2_SDK -v ${PWD}/custom-esdk-launch.py:/usr/bin/esdk-launch.py crops/extsdk-container


# Step 3) Copy compiled executable to board
#echo "- Copying executable to board (will ask for board's password, which is 'elk'. consider configuring ssh keys if asking password...)"
#scp ../OctopushOS/Builds/ELKAudioOS/build/OctopushOS.so mind@elk-pi.local:

# All done!
#echo ""
#echo "Done! now you can run the command in the board..."
