
class hash_v3
{
  public:

    /* Variable declaration */
    int servo_position[20];
    float increment[20];
    unsigned long final_time;
    unsigned long partial_time;

    /* Method declaration */
    void init_hash();
    void initial_position();
    void move_servo(int time, int  servo_target[]);

    void say_hi(int count = 1, int speed = 1000);
    void hands_up(int count = 1, int speed = 1000);

    void forward(int steps = 1, int speed = 1000);
    void turn_right(int steps = 1, int speed = 1000);
    void turn_left(int steps = 1, int speed = 1000);
    void move_right(int count = 1, int speed = 1000);
    void move_left(int count = 1, int speed = 1000);
    void ball_kick_right(int count = 1, int speed = 1000);
    void ball_kick_left(int count = 1, int speed = 1000);
    void max_sit(int count = 1, int speed = 1000);
    void bow(int count = 1, int speed = 1000);
    void right_bow(int count = 1, int speed = 1000);
    void left_bow(int count = 1, int speed = 1000);
    void ape_move(int count = 1, int speed = 1000);
    void push_up(int count = 1, int speed = 1000);
    void clap(int count = 1, int speed = 1000);
    void right_leg_up(int count = 1, int speed = 1000);
    void left_leg_up(int count = 1, int speed = 1000);
    void hip_pose(int count = 1, int speed = 1000);
    void right_leg_balance(int count = 1, int speed = 3000);
    void left_leg_balance(int count = 1, int speed = 3000);
    void flying_action(int count = 3, int speed = 1000);
    void hand_sit_zigzak(int count = 3, int speed = 2000);
    void side_shake(int count = 3, int speed = 2000);
    void hip_shake(int count = 3, int speed = 1000);
    void bend_up(int count = 1, int speed = 1000);



};
