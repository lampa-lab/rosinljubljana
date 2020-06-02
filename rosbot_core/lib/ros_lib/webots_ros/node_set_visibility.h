#ifndef _ROS_SERVICE_node_set_visibility_h
#define _ROS_SERVICE_node_set_visibility_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace webots_ros
{

static const char NODE_SET_VISIBILITY[] = "webots_ros/node_set_visibility";

  class node_set_visibilityRequest : public ros::Msg
  {
    public:
      typedef uint64_t _node_type;
      _node_type node;
      typedef uint64_t _from_type;
      _from_type from;
      typedef uint8_t _visible_type;
      _visible_type visible;

    node_set_visibilityRequest():
      node(0),
      from(0),
      visible(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->node >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->node >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->node >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->node >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (this->node >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (this->node >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (this->node >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (this->node >> (8 * 7)) & 0xFF;
      offset += sizeof(this->node);
      *(outbuffer + offset + 0) = (this->from >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->from >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->from >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->from >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (this->from >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (this->from >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (this->from >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (this->from >> (8 * 7)) & 0xFF;
      offset += sizeof(this->from);
      *(outbuffer + offset + 0) = (this->visible >> (8 * 0)) & 0xFF;
      offset += sizeof(this->visible);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->node =  ((uint64_t) (*(inbuffer + offset)));
      this->node |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->node |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->node |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->node |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      this->node |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      this->node |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      this->node |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      offset += sizeof(this->node);
      this->from =  ((uint64_t) (*(inbuffer + offset)));
      this->from |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->from |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->from |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->from |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      this->from |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      this->from |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      this->from |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      offset += sizeof(this->from);
      this->visible =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->visible);
     return offset;
    }

    const char * getType(){ return NODE_SET_VISIBILITY; };
    const char * getMD5(){ return "66754c396b86bd9c8375b973a4e698ec"; };

  };

  class node_set_visibilityResponse : public ros::Msg
  {
    public:
      typedef int8_t _success_type;
      _success_type success;

    node_set_visibilityResponse():
      success(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_success;
      u_success.real = this->success;
      *(outbuffer + offset + 0) = (u_success.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->success);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_success;
      u_success.base = 0;
      u_success.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->success = u_success.real;
      offset += sizeof(this->success);
     return offset;
    }

    const char * getType(){ return NODE_SET_VISIBILITY; };
    const char * getMD5(){ return "0b13460cb14006d3852674b4c614f25f"; };

  };

  class node_set_visibility {
    public:
    typedef node_set_visibilityRequest Request;
    typedef node_set_visibilityResponse Response;
  };

}
#endif
