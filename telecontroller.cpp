/*************************************************************************
    > File Name: telecontroller.cpp
    > Author: YinJianxiang
    > Mail: YinJianxiang123@gmail.com
    > Created Time: 2017年10月21日 星期六 22时08分18秒
 ************************************************************************/

#include "telecontroller.h"

TeleController::VolumeUp(Television &tv) {
	tv.volume_ += 1;
}

TeleController::VolumeDown() {
	tv.volume_ -= 1;
}

TeleController::ChanelUp() {
	tv.chanel_ += 1;
}

TeleController::ChanelDown() {
	tv.chanel_ -= 1;
}

