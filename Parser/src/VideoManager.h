/*
 * VideoManager.h
 *
 *  Created on: 2017. 3. 31.
 *      Author: choi.sungwoon
 */

#ifndef VIDEOMANAGER_H_
#define VIDEOMANAGER_H_

#include "Serializable.h"

class VideoProfile: public Serializable {
private:
	int att3;
	float att4;
	string att5;
public:
	VideoProfile() {
		this->att3 = 5;
		this->att4 = 2.3;
	}
	virtual ~VideoProfile() {}
	void write() {
		this->setValue(this->att3, "att30");
		this->setValue(this->att4, "att40");
		this->setValue(this->att5, "att50");
	}
	void read() {
		this->getValue(this->att3, "att30");
		this->getValue(this->att4, "att40");
		this->getValue(this->att5, "att50");
	}
};

class VideoManager: public Serializable {
private:
	int att1;
	VideoProfile videoProfile;
	float att2;

public:
	VideoManager() {
		this->att1 = 5;
		this->att2 = 2.3;
	}
	virtual ~VideoManager() {}

	void write() {
		this->setValue(this->att1, "att10");
		this->setValue(this->videoProfile, "videoProfile");
		this->setValue(this->att2, "att20");
	}
	void read() {
		this->getValue(att1, "att10");
		this->getValue(videoProfile, "videoProfile");
		this->getValue(att2, "att20");
	}
};


#endif /* VIDEOMANAGER_H_ */
