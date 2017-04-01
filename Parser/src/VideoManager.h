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

public:
	VideoProfile(string key): Serializable(key) {
		this->att3 = 5;
		this->att4 = 2.3;
	}
	virtual ~VideoProfile() {}
	void write() {
		cout << this->getKey() << endl;
		cout << BEGIN << endl;
		cout << "att3 " << this->att3 << endl;
		cout << "att4 " << this->att4 << endl;
		cout << END << endl;
	}
	void read() {
		att3 = this->getInt("att3");
		att4 = this->getFloat("att4");
	}
};

class VideoManager: public Serializable {
private:
	int att1;
	VideoProfile videoProfile;
	float att2;

public:
	VideoManager(string key): Serializable(key), videoProfile("videoProfile") {
		this->att1 = 5;
		this->att2 = 2.3;
	}
	virtual ~VideoManager() {}

	void write() {
		cout << this->getKey() << endl;
		cout << BEGIN << endl;
		cout << "att1 " << this->att1 << endl;
		videoProfile.write();
		cout << "att2 " << this->att2 << endl;
		cout << END << endl;
	}

	void read() {
		this->att1 = this->getInt("att1");
		this->videoProfile << this->getStructure("videoProfile");
		this->att2 = this->getFloat("att2");
	}
};


#endif /* VIDEOMANAGER_H_ */
