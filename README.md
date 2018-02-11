see3cam_10cug
=============

ROS driver for the e-consystems See3CAM_10CUG_M monochrome camera based on the 
[uvc_camera](https://github.com/ktossell/camera_umd/tree/master/uvc_camera) package.

This is a forked repo from the color only version of this camera to be used as a
stereo driver for two 10cug monochrome cameras in a stereo arrangement.

* Added brightness and exposure support (in the src/stereo.cpp file).
* Renamed the package to a unique name to avoid colliding with uvc_camera

This is a very dirty repo. It works, but it is build upon lots of layers of garbage. 
I use only one node, which is the uvc_stereo_node. I also use an external
hardware trigger to sync two 10cugs.
