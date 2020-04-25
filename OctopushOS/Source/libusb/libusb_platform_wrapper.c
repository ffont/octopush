// Copyright (c) 2017 Ableton AG, Berlin
//
// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the "Software"),
// to deal in the Software without restriction, including without limitation
// the rights to use, copy, modify, merge, publish, distribute, sublicense,
// and/or sell copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
// THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.

#ifdef _WIN32

# include "core.c"
# include "descriptor.c"
# include "hotplug.c"
# include "io.c"
# include "strerror.c"
# include "sync.c"

# include "os/poll_windows.c"
# include "os/threads_windows.c"
# include "os/windows_winusb.c"
# include "os/windows_nt_common.c"

#elif defined(__APPLE__)

# include "core.c"
# include "descriptor.c"
# include "hotplug.c"
# include "io.c"
# include "strerror.c"
# include "sync.c"

# include "os/darwin_usb.c"
# include "os/poll_posix.c"
# include "os/threads_posix.c"

#else

// MODIFIED from original Ableton provided code, we also build the library
// on linux platforms instead of linking to the system library

# include "core.c"
# include "descriptor.c"
# include "hotplug.c"
# include "io.c"
# include "strerror.c"
# include "sync.c"

# include "os/poll_posix.c"
# include "os/threads_posix.c"
# include "os/linux_usbfs.h"
# include "os/linux_usbfs.c"
# include "os/linux_udev.c"
# include "os/linux_netlink.c"
 
#endif