#!/usr/bin/env python

import rospy
from std_msgs.msg import String

def talker():

    pub = rospy.Publisher('traffic_light_state', String, queue_size=10)
    rospy.init_node('chnage_state', anonymous=True)
    
    rate = rospy.Rate(10) # 10hz
    try:
        while not rospy.is_shutdown():
            msg=raw_input(rospy.get_namespace()+"enter state ")
            pub.publish(msg)
            rate.sleep()
    except KeyboardInterrupt:
        rospy.signal_shutdown(rospy.get_namespace()+" Stoped")


if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException:
        pass