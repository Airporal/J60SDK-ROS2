colcon build --packages-up-to j60controller
source install/setup.bash
sudo ip link set can0 type can bitrate 1000000
sudo ip link set can0 up
