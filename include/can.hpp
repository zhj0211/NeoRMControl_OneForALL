#ifndef __CAN_INTERFACE__
#define __CAN_INTERFACE__

#include <linux/can.h>
#include <linux/can/raw.h>
#include <net/if.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#include <cstdint>
#include <cstdlib>
#include <functional>

#include "config.hpp"
#include "string"
#include "utils.hpp"

namespace Hardware
{
    class Can_interface
    {
       public:
        using CallbackType = std::function<void(const can_frame &)>;

        Can_interface();
        ~Can_interface();
        bool can_send(const can_frame &frame);
        bool can_dump();
        void init(const CallbackType &callback);

       private:
        sockaddr_can *addr;
        can_frame frame_r;
        ifreq *ifr;
        Types::debug_info_t *debug;
        int soket_id;
        bool init_flag;
        CallbackType callback_fun;

       public:
    };

}  // namespace Hardware

#endif
