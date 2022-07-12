/*
 * main.cpp

 *
 *  Created on: 2018/01/17
 *      Author: yoneken
 */
#include <mainpp.h>
#include <main.h>
#include <ros.h>
#include <std_msgs/String.h>
#include <stdio.h>
ros::NodeHandle nh;

std_msgs::String str_msg;
ros::Publisher chatter("chatter", &str_msg);
char hello[] = "Hello world!";

void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart){
  nh.getHardware()->flush();
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){
  nh.getHardware()->reset_rbuf();
}

void setup(void)
{
  nh.initNode();
  nh.advertise(chatter);
}
uint32_t count;
void loop(void)
{
  count++;
  HAL_GPIO_TogglePin(GPIOB, LD1_Pin|LD3_Pin|LD2_Pin);
  char s_temp[30];
  sprintf(s_temp, "%s,  count = %d (s)", hello, count);
  str_msg.data= s_temp;
  chatter.publish(&str_msg);
  nh.spinOnce();

  HAL_Delay(100);
}

