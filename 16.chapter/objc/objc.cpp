// objc.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "OjbectCounter.h" 

template <typename T>
size_t ObjectCounter<T>::count = 0; 

class fake_float16 : public ObjectCounter<fake_float16> 
{
public:
  fake_float16() : v_(0) { }
  operator short() { return v_; } 

private:
  short v_; 
}; 


int _tmain(int argc, _TCHAR* argv[])
{
  fake_float16 f1, f2(f1), f3(f2); 
  printf("live = %d.\n", fake_float16::live()); 
	return 0;
}

