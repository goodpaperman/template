// cntptr.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "CountingPtr.h" 

class ManagedType
{
private:

public:
  size_t ref_count; 
}; 

typedef CountingPtr<ManagedType
, MemberReferenceCount<ManagedType
, size_t
, &ManagedType::ref_count>
, StandardArrayPolicy> Ptr; 

CountingPtr<char> f1(CountingPtr<char> &cp1, CountingPtr<char> cp2)
{
  return cp2; 
}

CountingPtr<char>& f2(CountingPtr<char> &cp1, CountingPtr<char> cp2)
{
  return cp1; 
}

class Base
{
public:
}; 

class Derived : public Base
{
public:
}; 

int _tmain(int argc, _TCHAR* argv[])
{
  {
    CountingPtr<char> p1(new char('a')); 
    CountingPtr<char> p2(p1), p3 = p1, p4; 
    p4 = p3; 
    p3 = new char('d'); 
    p4 = p3; 

    *p4 = 'b'; 
    printf("content = '%s'.\n", p1.operator->()); 
    p1 = f1(p1, p3); 
    p3 = f2(p2, p4); 
  }

  printf("\n\n"); 

  {
    Ptr p1(new ManagedType[12]()); 
    Ptr p2(p1), p3 = p1, p4; 
    p4 = p3; 
    p3 = new ManagedType[3](); 
    p4 = p3; 
  }

  printf("\n\n"); 

  {
    int* pi = 0; 
    int const* pci = 0; 
    int *const pic = 0; 
    pci = pi; 
    pi = pic; 
    pci = pic; 
    //pic = pi; 
    //pi = pci; 

    CountingPtr<int> cpi(pi); 
    //CountingPtr<int> cpi(pci); 

    //CountingPtr<int const> cpci(pci); 
    //CountingPtr<int const> cpci(cpi); 
    //CountingPtr<int const> cpci(pic); 
    CountingPtr<int const> cpci(pi); 

    CountingPtr<int> const cpic(pi); 
    //CountingPtr<int> const cpic(pci); 
    //CountingPtr<int> const cpic(pic); 
    cpi = cpic; 
    //cpci = cpic; 
    //cpci = cpi; 
    //cpi = cpci; 
    //*cpi = 0; 
    //*cpci = 0;
  }

  printf("\n\n"); 

  {
    //CountingPtr<Base> pb(new Derived()); 
    CountingPtr<Derived> pd(new Derived()); 
    //CountingPtr<Base> pb(new Base()); 
    CountingPtr<Base> pb(pd), pb2; 
    //pd = pb; 
    pb2 = pd; 
  }

  printf("\n\n"); 

  {
    CountingPtr<int> pi(new int(4)); 
    CountingPtr<void> pv(pi), pv2; 
#ifdef BOOL_PTR
    pv2 = pi; 
    //pi = pv2;
#endif 
  }

  printf("\n\n"); 

  {
    //CountingPtr<int> pi(0); 
    CountingPtr<int> pi(new int(42)); 
    CountingPtr<int> pi2 = pi; 
#ifdef BOOL_PTR
    int x = pi + pi2; 
#elif VOID_PTR
    delete pi; 
#else 
    //int x = pi + pi2; 
    //delete pi; 
    //CountingPtr<int>::BoolConversionSupport a; 
    //a.*pi; 
#endif 

    if(pi)
    {
      printf("full\n"); 
    }
    else 
    {
      printf("empty\n"); 
    }
  }

  printf("\n\n"); 

  {
    float f = 3.21; 
    CountingPtr<float> pf(new float(1.23)); 
    //CountingPtr<float> pf2(new float(3.21)); 
    CountingPtr<float> pf2(pf); 
    if(pf2 == pf)
    //if(pf == &f) 
    //if(&f == pf2)
    {
      printf("equal\n"); 
    }
    else 
      printf("unequal\n"); 
  }

	return 0;
}

