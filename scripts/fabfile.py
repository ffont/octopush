import os

from fabric import task, Connection

host = 'mind@elk-pi.local'
remote_dir = '/home/mind/'

@task
def clean(ctx):

    # Remove all intermediate build files (for ELK build)
    os.system("rm -r ../OctopushOS/Builds/ELKAudioOS/build/")


@task
def send(ctx):

    # Copy compiled file and sushi configuration to board
    print('\nSending compiled OctopushOS and config files to board...')
    print('********************************************************\n')
    with Connection(host=host, connect_kwargs={'password': 'elk'}) as c:
        for local_file, destination_dir in [
            ("../sandbox/start.sh", remote_dir),
            ("../sandbox/octopush_sushi_config.json", remote_dir),
            ("../sandbox/python-midi-bridge/OSC.py", remote_dir),
            ("../sandbox/python-midi-bridge/simpleOSC.py", remote_dir),
            ("../sandbox/python-midi-bridge/requirements.txt", remote_dir),
            ("../sandbox/python-midi-bridge/server.py", remote_dir),
            ("../OctopushOS/Builds/ELKAudioOS/build/OctopushOS.so", remote_dir)
        ]:
            print('- Copying {0} to {1}'.format(local_file, destination_dir))
            c.put(local_file, destination_dir)

    print('\nAll done!')
    print('You can now run OctopushOS on the ELK board with the command:')
    print('./start.sh')
    print('\n')


@task
def compile(ctx):

    # Cross-compile OctopushOS
    print('Coss-compiling OctopushOS for ELK platform...')
    print('*********************************************\n')
    os.system("find ../OctopushOS/Builds/ELKAudioOS/build/intermediate/Release/ -type f \( \! -name 'include_*' \) -exec rm {} \;")
    os.system('docker run --rm -it -v elkvolume:/workdir -v ${PWD}/../:/code/octopush -v ${PWD}/../../ELK/JUCE:/home/sdkuser/JUCE -v ${PWD}/../../VST_SDK/VST2_SDK:/code/VST2_SDK -v ${PWD}/custom-esdk-launch.py:/usr/bin/esdk-launch.py crops/extsdk-container')

    print('\nAll done!')


@task
def deploy(ctx):
    compile(ctx)
    send(ctx)
