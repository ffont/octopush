/* =========================================================================================

   This is an auto-generated file: Any edits you make may be overwritten!

*/

#pragma once

namespace BinaryData
{
    extern const char*   _31655_wav;
    const int            _31655_wavSize = 163022;

    extern const char*   _262218__jputman__simpleloop_wav;
    const int            _262218__jputman__simpleloop_wavSize = 2120698;

    extern const char*   _418621__realdavidfloat__basslinec120bpm_wav;
    const int            _418621__realdavidfloat__basslinec120bpm_wavSize = 1412930;

    extern const char*   _418743__realdavidfloat__hihatloop120bpm0102_wav;
    const int            _418743__realdavidfloat__hihatloop120bpm0102_wavSize = 1412824;

    extern const char*   clap_wav;
    const int            clap_wavSize = 57452;

    extern const char*   hihat_wav;
    const int            hihat_wavSize = 194252;

    extern const char*   kick_wav;
    const int            kick_wavSize = 132136;

    extern const char*   snare_aiff;
    const int            snare_aiffSize = 30888;

    extern const char*   startup_img_png;
    const int            startup_img_pngSize = 11969;

    extern const char*   tambourine_wav;
    const int            tambourine_wavSize = 1058444;

    // Number of elements in the namedResourceList and originalFileNames arrays.
    const int namedResourceListSize = 10;

    // Points to the start of a list of resource names.
    extern const char* namedResourceList[];

    // Points to the start of a list of resource filenames.
    extern const char* originalFilenames[];

    // If you provide the name of one of the binary resource variables above, this function will
    // return the corresponding data and its size (or a null pointer if the name isn't found).
    const char* getNamedResource (const char* resourceNameUTF8, int& dataSizeInBytes);

    // If you provide the name of one of the binary resource variables above, this function will
    // return the corresponding original, non-mangled filename (or a null pointer if the name isn't found).
    const char* getNamedResourceOriginalFilename (const char* resourceNameUTF8);
}
