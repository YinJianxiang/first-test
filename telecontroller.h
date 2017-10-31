/*************************************************************************
    > File Name: telecontroller.h
    > Author: YinJianxiang
    > Mail: YinJianxiang123@gmail.com
    > Created Time: 2017年10月21日 星期六 22时01分15秒
 ************************************************************************/

#ifndef _TELECONTROLLER_H_
#define _TELECONTROLLER_H_

class Television;

class TeleController {
public:
	void VolumeUp(Television &tv);
	void VolumeDown(Television &tv);
	void ChanelUp(Television &tv);
	void ChanelDown(Television &tv);
};



#endif //_TELECONTROLLER_H_
