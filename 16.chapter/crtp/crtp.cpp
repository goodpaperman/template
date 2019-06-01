// crtp.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
//#include <atlbase.h> 

template <typename D>
class CuriousBase
{
public:
  void recurse()
  {
    //pD = (D*)this; 
    D* pD = (D*)this; 
    printf("CuriousBase::recurse\n"); 
    pD->recurse(); 
  }

  static void do_it()
  {
    printf("CuriousBase::do_it\n"); 
    D::do_it(); 
  }

  void main()
  {
    D* pD = (D*)this; 
    pD->prev_run(); 
    pD->run(); 
    pD->post_run(); 

    //prev_run(); 
    //run(); 
    //post_run(); 
  }

  void prev_run()
  {
    printf("CuriousBase::prev_run\n"); 
  }

  void run()
  {
    printf("CuriousBase::run\n"); 
  }

  void post_run()
  {
    printf("CuriousBase::post_run\n"); 
  }
}; 

class Curious : public CuriousBase<Curious>
{
public:
  void recurse()
  {
    printf("Curious::recurse\n"); 
  }

  static void do_it()
  {
    printf("Curious::do_it\n"); 
  }

  int run()
  {
    printf("Curious::run\n"); 
    return 0; 
  }
}; 

template <typename T>
class CuriousT : public CuriousBase<CuriousT<T> >
{
public:
  T prev_run()
  {
    printf("CuriousT<T>::prev_run\n"); 
    return T(); 
  }
}; 

template <template <typename> class D>
class CuriousBaseTT
{
public:
  void main()
  {
    D<int>* pD = (D<int>*)this; 
    pD->prev_run(); 
    pD->run(); 
    pD->post_run(); 
  }

  void prev_run()
  {
    printf("CuriousBaseTT::prev_run\n"); 
  }

  void run()
  {
    printf("CuriousBaseTT::run\n"); 
  }

  void post_run()
  {
    printf("CuriousBaseTT::post_run\n"); 
  }

private:
  D<int> *di; 
}; 

template <typename T>
class CuriousTT : public CuriousBaseTT<CuriousTT> 
{
public:
  int post_run()
  {
    printf("CuriousTT::post_run\n"); 
    return 0; 
  }
}; 

int _tmain(int argc, _TCHAR* argv[])
{
  Curious c; 
  c.recurse(); 
  Curious::do_it(); 
  c.do_it(); 

  c.main(); 

  CuriousT<float> ct; 
  ct.main(); 

  CuriousTT<char> ctt; 
  ctt.main(); 
	return 0;
}

