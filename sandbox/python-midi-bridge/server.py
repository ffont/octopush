import argparse
import math

from simpleOSC import initOSCClient, initOSCServer, setOSCHandler, startOSCServer, sendOSCMsg

import mido


push2_midi_out = None
push2_midi_in = None


def midi_to_push_handler(addr, tags, data, source):
    # Read OSC message received from OCTOPUSH and forward it to Push as a MIDI message
    msg_byes = [int(x) for x in data[0].split(',') if x] 
    msg = mido.Message.from_bytes(msg_byes)
    #print('From OCTOPUSH: {0}'.format(msg))
    push2_midi_out.send(msg)


def midi_from_push_handler(msg):
    # Read MIDI message received from Push and forward it to OCOTPUSH as OSC message
    midi_bytes = msg.bytes()
    sendOSCMsg(address="/frompush", data=midi_bytes)


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("--ip", default="127.0.0.1", help="The ip to listen and send to")
    parser.add_argument("--port_listen", type=int, default=9001, help="The port to listen on")
    parser.add_argument("--port_send", type=int, default=9002, help="The port to send messages to")
    args = parser.parse_args()

    # Configure connection to/from Push2 MIDI
    try:
        push2_midi_out = mido.open_output('Ableton Push 2:Ableton Push 2 MIDI 1 16:0')
        push2_midi_in = mido.open_input('Ableton Push 2:Ableton Push 2 MIDI 1 16:0')
        push2_midi_in.callback = midi_from_push_handler
        print("Listening for MIDI messages comming from push...")
    except OSError:
        print("Could not connect to Push2 MIDI ports")

    initOSCClient(ip=args.ip, port=args.port_send)

    # Configure OSC server to receive messages from OCTOPUSH
    initOSCServer(ip=args.ip, port=args.port_listen)
    setOSCHandler('/topush', midi_to_push_handler)
    startOSCServer()
    print("Listening OSC on {}".format(args.port_listen))
