#ifndef READ_JOYSTICK_H
#define READ_JOYSTICK_H

struct joystick1
{

  unsigned short x_value;
  unsigned short y_value;
};

struct joystick2
{
  unsigned short x_value;
  unsigned short y_value;
};

struct joystick3
{
  unsigned short x_value;
  unsigned short y_value;
};

typedef struct joystick1 JOYSTICK1;
typedef struct joystick2 JOYSTICK2;
typedef struct joystick3 JOYSTICK3;

#endif

