// namedarg.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <typeinfo> 

class shmem_access
{
public:
  void access() 
  {
    printf("access by share memory.\n"); 
  }
}; 

class file_access
{
public:
  void access()
  {
    printf("access by file read/write.\n"); 
  }
}; 

class rbt_index
{
public:
  void find()
  {
    printf("find by red/black tree index.\n"); 
  }
}; 

class lite_index
{
public:
  void find()
  {
    printf("find by lite index.\n"); 
  }
}; 

class gather_write
{
public:
  void write()
  {
    printf("gather write.\n"); 
  }
}; 

class scatter_write
{
public:
  void write()
  {
    printf("scatter_write.\n"); 
  }
}; 

class sequential_write
{
public:
  void write()
  {
    printf("sequential write.\n"); 
  }
};

class default_policies
{
public:
  typedef shmem_access access_policy; 
  typedef rbt_index index_policy; 
  typedef sequential_write write_policy; 
}; 

class default_policy_args : virtual public default_policies
{
public:

};

template <typename P>
class access_policy_is : virtual public default_policies
{
public:
  typedef P access_policy; 
}; 

template <typename P>
class index_policy_is : virtual public default_policies
{
public:
  typedef P index_policy; 
}; 

template <typename P>
class write_policy_is : virtual public default_policies
{
public:
  typedef P write_policy; 
}; 

template <typename B, int D>
class discriminator : public B
{
}; 

template <typename access_setter
, typename index_setter
, typename write_setter>
class policy_selector : public discriminator<access_setter, 1>
  , public discriminator<index_setter, 2> 
  , public discriminator<write_setter, 3>
{
}; 


template <typename access_setter = default_policy_args
, typename index_setter = default_policy_args
, typename write_setter = default_policy_args>
class data
{
public:
  typedef policy_selector<access_setter, index_setter, write_setter> policies; 

  void write()
  {
    policies::access_policy ap; 
    policies::index_policy ip; 
    policies::write_policy wp; 

    printf("data type: %s.\n", typeid(data).name()); 
    printf("selector type: %s.\n", typeid(policies).name()); 
    ap.access(); 
    ip.find(); 
    wp.write(); 
    printf("\n"); 
  }
}; 

int _tmain(int argc, _TCHAR* argv[])
{
  data<> d; 
  d.write(); 

  data<access_policy_is<file_access> > d2; 
  d2.write(); 

  data<index_policy_is<lite_index> > d3; 
  d3.write(); 

  data<write_policy_is<gather_write> > d4; 
  d4.write(); 

  data<write_policy_is<scatter_write>, index_policy_is<lite_index>, access_policy_is<file_access> > d5; 
  d5.write(); 

  //data<access_policy_is<file_access>, access_policy_is<shmem_access> > d6; 
  //d6.write(); 
	return 0;
}

