#ifndef __RECEIVER_H_
#define __RECEIVER_H_
#include "Console.h"

class Receiver {
public:
	void Load();
	void Close() const;
	void Save() const;
	void SaveAs() const;
	bool imageIsSaved() const;
	void Help() const;
	void Exit() const;
	void Grayscale();
	void Monochrome();
	void Negative();
	void Rotate();
	void Collage();
};

#endif
