ssh movo_base@192.168.131.100
-> movo420

#activatre the base for autonomus nav

ros2 launch movobase_activation movobase_activation.launch.py 


# on agx orin


ros2 launch robot_bringup movo_xbox_controller.launch.py 



or 


 ros2 launch movobase_ctr slam_frommovobase.launch.py 
 
 or  
 
 ros2 launch movobase_ctr nav2_tryl.launch.py 




















 # -----------------------------------------------------------
    # 3. IMU Node (without remappings)
    # -----------------------------------------------------------
    imu_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(
                get_package_share_directory('tm_imu'),
                'launch',
                'imu.launch.py'
            )
        )
    )

 # -----------------------------------------------------------
    # 4. Static transform between base_link and imu_link
    # -----------------------------------------------------------
    static_tf_base_to_imu = Node(
        package='tf2_ros',
        executable='static_transform_publisher',
        name='base_to_imu_tf',
        arguments=[
            '0', '0', '0.6',      # x, y, z (IMU 60cm above base_link)
            '0', '0', '0', '1',   # qx, qy, qz, qw (no rotation)
            'base_link',          # parent frame
            'imu_link'            # child frame
        ]
    )
 ld.add_action(imu_launch)
    ld.add_action(static_tf_base_to_imu)
