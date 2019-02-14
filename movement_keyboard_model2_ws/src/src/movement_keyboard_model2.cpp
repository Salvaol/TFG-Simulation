  #include "ros/ros.h"
  #include <gazebo_msgs/SetModelState.h>
  #include <signal.h>
  #include <termios.h>
  #include <stdio.h> 
 
  #define PI 3.14159265
  #define L1 104
  #define L2 104
  #define Lp 60
  
  #define KEYCODE_Xmas 0x43 
  #define KEYCODE_Xmenos 0x44
  #define KEYCODE_Ymas 0x41
  #define KEYCODE_Ymenos 0x42
  #define KEYCODE_Zmas 0x77
  #define KEYCODE_Zmenos 0x73
  #define KEYCODE_ZgiroMas 0x61
  #define KEYCODE_ZgiroMenos 0x64
  #define KEYCODE_YgiroMas 0x65
  #define KEYCODE_YgiroMenos 0x71  
  
struct termios cooked, raw; 

int cont = 0;

double retardo = 0.1;

gazebo_msgs::ModelState objeto;  

// As it says, it quits the raw mode
 
void quit(int sig)
{
  tcsetattr(0, TCSANOW, &cooked);
  ros::shutdown();
  exit(0);
}

void callback(const ros::TimerEvent&)
{
 
	ros::NodeHandle n;   	
  	
  	ros::Publisher object_pub_=n.advertise<gazebo_msgs::ModelState>("/gazebo/set_model_state", 1);

        std::string modelo_objeto;

        ros::NodeHandle nh("~");

        nh.param("modelo_objeto", modelo_objeto, std::string("my_UNEXMIN"));

	ros::Time anterior;

	if (::cont == 0)
        {
		anterior = ros::Time::now();
		
		::objeto.model_name = modelo_objeto;
  
		::objeto.reference_frame = "world";
											 
		::objeto.pose.orientation.w = 1;

		::objeto.twist.angular.x = 0;
		
		::objeto.twist.angular.y = 0;

		::objeto.twist.angular.z = 0;
	
		::cont = 1;

		object_pub_.publish(::objeto);		
		
	}
	
  char c;

  // get the console in raw mode                                                              
  tcgetattr(0, &cooked);
  memcpy(&raw, &cooked, sizeof(struct termios));
  raw.c_lflag &=~ (ICANON | ECHO);
  // Setting a new line, then end of file                         
  raw.c_cc[VEOL] = 1;
  raw.c_cc[VEOF] = 2;
  tcsetattr(0, TCSANOW, &raw);

  puts(""); 
  puts("#####################################################");
  puts("                   CONTROLES OBJETO");
  puts("#####################################################");
  puts("");  
  puts("Up arrow:_______________________ Move object +z axes");
  puts("Down arrow:_____________________ Move object -z axes");
  puts("Left arrow:_____________________ Move object -x axes"); 
  puts("Right arrow:____________________ Move object +x axes");
  puts("W key:__________________________ Move object +y axes");
  puts("S key:__________________________ Move object -y axes");
  puts("A key:__________________________ Tilt + x axis object");
  puts("D key:__________________________ Tilt - x axis object");
  puts("Q key:__________________________ Tilt + y axis object");
  puts("E key:__________________________ Tilt - y axis object");                               

        
    while (ros::ok())
    {
		
			
    // get the next event from the keyboard  
    if(read(0, &c, 1) < 0)
    {
      perror("read():");
      exit(-1);
    }
	
 
/** no tiene sentido utilizar velocidades con el teclado ya que debemos esperar al eventto de la tecla y no se actualiza la posicion correctamente en función de la velocdad(no son ciclos constntes)*/


      if (c == KEYCODE_Xmas)
      {
		if (ros::Time::now() > anterior + ros::Duration(::retardo))
		{
                    ::objeto.twist.linear.x = 0.1;
		    ::objeto.pose.position.x = ::objeto.pose.position.x + 0.1;
		    
			
			anterior = ros::Time::now();
		}		
      }
      if (c == KEYCODE_Xmenos)
      {
		if (ros::Time::now() > anterior + ros::Duration(::retardo))
		{
		        ::objeto.twist.linear.x = -0.1;
			::objeto.pose.position.x = ::objeto.pose.position.x - 0.1;

			anterior = ros::Time::now();
		}				
      }
      if (c == KEYCODE_Ymas)
      {
		if (ros::Time::now() > anterior + ros::Duration(::retardo)) {
		
			::objeto.twist.linear.z = 0.1;
			::objeto.pose.position.z = ::objeto.pose.position.z + 0.1;
			
			
			anterior = ros::Time::now();
		}					    
      }
      if (c == KEYCODE_Ymenos)
      {
		if (ros::Time::now() > anterior + ros::Duration(::retardo))
		{
			::objeto.twist.linear.z = -0.1;
			::objeto.pose.position.z = ::objeto.pose.position.z - 0.1;
			
			anterior = ros::Time::now();
		}						
      }
      if (c == KEYCODE_Zmas)
      {
		if (ros::Time::now() > anterior + ros::Duration(::retardo))
		{
			::objeto.twist.linear.y = 0.1;
			::objeto.pose.position.y = ::objeto.pose.position.y + 0.1;
			
			anterior = ros::Time::now();
		}					
      }
      if (c == KEYCODE_Zmenos)
      {
		if (ros::Time::now() > anterior + ros::Duration(::retardo))
		{
			::objeto.twist.linear.y = -0.1;
			::objeto.pose.position.y = ::objeto.pose.position.y - 0.1;
			
			anterior = ros::Time::now();
		}				
      }
      if (c == KEYCODE_ZgiroMas)
      {
		if (ros::Time::now() > anterior + ros::Duration(::retardo))
		{
			

			//::objeto.pose.orientation.w = 1;
			::objeto.twist.angular.z =0.1;

			::objeto.pose.orientation.z = ::objeto.pose.orientation.z + 0.1;
		
			

			//::objeto.pose.position.y = ::objeto.pose.position.y + 0.005;
			
			anterior = ros::Time::now();
		}	
      }
      if (c == KEYCODE_ZgiroMenos)
      {
		if (ros::Time::now() > anterior + ros::Duration(::retardo))

		{


			//::objeto.pose.orientation.w = 1;
			::objeto.twist.angular.z = -0.1;
			::objeto.pose.orientation.z = ::objeto.pose.orientation.z - 0.1;
			//::objeto.pose.position.y = ::objeto.pose.position.y - 0.005;

			
			anterior = ros::Time::now();
		}	
      }
      if (c == KEYCODE_YgiroMas)
      {
		if (ros::Time::now() > anterior + ros::Duration(::retardo))
		{

			::objeto.twist.angular.y = 0.1;
			::objeto.pose.orientation.y = ::objeto.pose.orientation.y + 0.1;
			//::objeto.pose.position.x = ::objeto.pose.position.x + 0.005;
			

			
//revisar el codigo del robot a ver si publica la orintacion o algo todo el rato; restar posicion para que se quede en el sitio.


			anterior = ros::Time::now();
		}	
      }
      if (c == KEYCODE_YgiroMenos)
      {
		if (ros::Time::now() > anterior + ros::Duration(::retardo))
		{


			::objeto.twist.angular.y = -0.1;
			::objeto.pose.orientation.y = ::objeto.pose.orientation.y - 0.1;
			//::objeto.pose.position.x = ::objeto.pose.position.x - 0.005;

			anterior = ros::Time::now();
		}	
      }
      
      object_pub_.publish(::objeto);

	}	
}
 
  int main(int argc, char **argv)
  {
 
	ros::init(argc, argv, "movement_keyboard_model2");   
 
	ros::NodeHandle n;
  	
  	ros::Publisher object_pub_=n.advertise<gazebo_msgs::ModelState>("/gazebo/set_model_state", 1);    	 	


	signal(SIGINT,quit); 
	
	ros::Timer timer = n.createTimer(ros::Duration(1), callback);
    
   	   
 
	ros::spin();  
 
        return 0;
  }

