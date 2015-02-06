#pragma once
#include <stddef.h>

template <typename T>
class Singleton
{
public:
	static T& Instance(){
		if (instance == NULL){
			instance = CreateInstance();
		}
		return *instance;
	}

	static void ResetInstance(){
		if (instance != NULL){
			delete instance;
			instance = NULL;
	}
}

protected:

	virtual ~Singleton(){
		if (instance != NULL){
			delete instance;
		}
	}

	inline explicit Singleton(){};

private:
	static T* CreateInstance(){
		instance = new T();
		return instance;
	}

	static T* instance;
};

template<typename T>
T* Singleton<T>::instance = NULL;