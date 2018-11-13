/*
 * Globals.h
 *
 *  Created on: 9 бреб„ 2018
 *      Author: OFIR
 */

#ifndef GLOBALS_H_
#define GLOBALS_H_

const int WIDTH = 800;
const int HEIGHT = 600;

inline float bounds(float value, float min, float max) {
if (value >= max) {
	return max;
}
if (value <= min) {
	return min;
} else {
	return value;
}
}

inline bool boundsBool(float value, float min, float max) {
if (value >= max) {
	return true;
}
if (value <= min) {
	return true;
} else {
	return false;
}
}

#endif /* GLOBALS_H_ */
