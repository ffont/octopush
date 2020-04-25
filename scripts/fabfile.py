import os

from fabric import task, Connection

host = 'mind@elk-pi.local'
remote_dir = '/home/mind/'


@task
def deploy(ctx):

    # Cross-compile OctopushOS
    print('Coss-compiling OctopushOS for ELK platform...')
    print('*********************************************\n')
    os.system("find ../OctopushOS/Builds/ELKAudioOS/build/intermediate/Release/ -type f \( \! -name 'include_*' \) -exec rm {} \;")
    os.system('docker run --rm -it -v elkvolume:/workdir -v ${PWD}/../:/code/octopush -v ${PWD}/../../ELK/JUCE:/home/sdkuser/JUCE -v ${PWD}/../../VST_SDK/VST2_SDK:/code/VST2_SDK -v ${PWD}/custom-esdk-launch.py:/usr/bin/esdk-launch.py crops/extsdk-container')

    # Copy compiled file and sushi configuration to board
    print('\nSending compiled OctopushOS and config files to board...')
    print('********************************************************\n')
    with Connection(host=host, connect_kwargs={'password': 'elk'}) as c:
        for local_file, destination_dir in [
            ("../sandbox/octopush_sushi_config.json", remote_dir),
            ("../OctopushOS/Builds/ELKAudioOS/build/OctopushOS.so", remote_dir)
        ]:
            print('- Copying {0} to {1}'.format(local_file, destination_dir))
            c.put(local_file, destination_dir)


    print('\nAll done!')
    print('You can now run OctopushELK on the ELK board with the command:')
    print('sushi -r -c /home/mind/octopush_sushi_config.json')
    print('\n')