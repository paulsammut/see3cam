#include <boost/thread.hpp>

#include <ros/ros.h>
#include <ros/time.h>

#include "uvc_cam/uvc_cam.h"
#include "sensor_msgs/Image.h"
#include "sensor_msgs/image_encodings.h"
#include "sensor_msgs/CameraInfo.h"
#include "camera_info_manager/camera_info_manager.h"
#include "image_transport/image_transport.h"

#include "std_msgs/Float64.h"

namespace uvc_camera {

class StereoCamera {
  public:
    StereoCamera(ros::NodeHandle comm_nh, ros::NodeHandle param_nh);
    void onInit();
    void sendInfo(ros::Time time);
    void feedImages();
    ~StereoCamera();

  private:
    ros::NodeHandle node, pnode;
    image_transport::ImageTransport it;
    bool ok;

    uvc_cam::Cam *cam_left, *cam_right;
    int width, height, fps, skip_frames, frames_to_skip;
    std::string left_device, right_device, frame;
    bool rotate_left, rotate_right;

    camera_info_manager::CameraInfoManager left_info_mgr, right_info_mgr;

    image_transport::Publisher left_pub, right_pub;
    ros::Publisher left_info_pub, right_info_pub;

    /**
     * @brief Left exposure subscriber
     */
    ros::Subscriber exposure_left_sub;

    /**
     * @brief Right exposure subscriber
     */
    ros::Subscriber exposure_right_sub;

    boost::thread image_thread;

    /**
     * @brief Sets the exposure for the left camera
     *
     * @param call_exposure_msg
     */
    void callBackExposureLeft (std_msgs::Float64 call_exposure_msg);

    /**
     * @brief Sets the exposure for the right camera
     *
     * @param call_exposure_msg
     */
    void callBackExposureRight (std_msgs::Float64 call_exposure_msg);

    /**
     * @brief Left brightness subscriber
     */
    ros::Subscriber brightness_left_sub;

    /**
     * @brief Right brightness subscriber
     */
    ros::Subscriber brightness_right_sub;
	void callBackBrightnessLeft (std_msgs::Float64 call_brightness_msg);
	void callBackBrightnessRight (std_msgs::Float64 call_brightness_msg);
};

};

