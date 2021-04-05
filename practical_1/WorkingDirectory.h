#ifndef RESOURCE_PATH_H
#define RESOURCE_PATH_H

#include <string>

#ifdef MACOS
#include "CoreFoundation/CoreFoundation.h"
#endif // MACOS

class WorkingDirectory {
public:
	WorkingDirectory();

	inline const std::string& Get() {
		return path;
	}

private:
	std::string path;
};


#endif // !RESOURCE_PATH_H
