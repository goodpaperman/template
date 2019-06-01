// overload.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "overload.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 唯一的应用程序对象

CWinApp theApp;

using namespace std;

template <typename T>
int f(T)
{
  printf("int f(T) called\n"); 
  return 1; 
}

template <typename T>
int f(T*)
{
  printf("int f(T*) called\n"); 
  return 2; 
}

void demo()
{
  //printf("%d\n", f<int*>(0)); 
  //printf("%d\n", f<int>(0)); 

  int a = 0; 
  printf("%d\n", f<int*>(&a)); 
  printf("%d\n", f<int>(&a)); 

  printf("%d\n", f(a)); 
  printf("%d\n", f(&a)); 
}



//template <typename T1, typename T2>
//void f1(T1, T2)
//{
//  printf("void f1(T1, T2)\n"); 
//}
//
//template <typename T1, typename T2>
//void f1(T2, T1)
//{
//  printf("void f1(T2, T1)\n"); 
//}
//
//template <typename T>
//long f2(T)
//{
//  printf("long f2(T)\n"); 
//}
//
//template <typename T>
//char f2(T)
//{
//  printf("char f2(T)\n"); 
//}

template <typename T>
void t(T*, T const* = 0, ...)
{
  printf("void t(T*, T const* = 0, ...)\n"); 
}

template <typename T>
void t(T const*, T*, T* = 0)
{
  printf("void t(T const*, T*, T* = 0)\n"); 
}

template <typename T>
std::string r(T)
{
  return "Template"; 
}

std::string r(int&)
{
  return "NonTemplate"; 
}

extern void g(); 
extern void h(); 
void test()
{
  //f1('a', 'b'); 
  //f1<char, char>('a', 'b'); 
  //f2(1); 
  //f2<int>(1); 
  g(); 
  h(); 

  int *p = 0; 
  //t(p, p); 

  int x = 7; 
  printf("%s\n", r(x).c_str()); 
}

int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	int nRetCode = 0;

	// 初始化 MFC 并在失败时显示错误
	if (!AfxWinInit(::GetModuleHandle(NULL), NULL, ::GetCommandLine(), 0))
	{
		// TODO: 更改错误代码以符合您的需要
		_tprintf(_T("错误: MFC 初始化失败\n"));
		nRetCode = 1;
	}
	else
	{
		demo(); 
    test(); 
	}

	return nRetCode;
}
