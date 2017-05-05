#include "../Include/Object.h"
#include <stdio.h>
#include <string.h>

Object::Object(void)
{
    m_ObjectID       = NULL;
    m_ObjectName     = NULL;
    m_ObjectDesc     = NULL;
    m_ObjectTrigger  = NULL;;
    m_ObjectResponse = NULL;;
    m_ObjectAction   = NULL;;
}

Object::Object(long _ObjectID,
               char *_ObjectName,
               char *_ObjectDesc)
{
  Initialize(_ObjectID, _ObjectName, _ObjectDesc);
}

Object::~Object(void)
{

}

void Object::Initialize(long _ObjectID,
                        char *_ObjectName,
                        char *_ObjectDesc)
{
    m_ObjectName = new char[strlen(_ObjectName)];
    m_ObjectDesc = new char[strlen(_ObjectDesc)];
    memcpy(m_ObjectName, _ObjectName, strlen(_ObjectName));
    memcpy(m_ObjectDesc, _ObjectDesc, strlen(_ObjectDesc));
    m_ObjectID = _ObjectID;
}

void Object::Destroy(void)
{

}

void Object::Tick(void)
{
  //std::cout << "REMOVE";
}

bool Object::CheckTrigger(char *_Trigger)
{
  return(m_ObjectTrigger && (strcmp(_Trigger, m_ObjectTrigger) == 0));
}

void Object::SetName(char *_ObjectName)
{
    if(m_ObjectName)
    {
            delete[] m_ObjectName;
    }

    m_ObjectName = new char[strlen(_ObjectName)];
    memcpy(m_ObjectName, _ObjectName, strlen(_ObjectName));
}

void Object::SetDesc(char *_ObjectDesc)
{
    if(m_ObjectDesc)
    {
            delete[] m_ObjectDesc;
    }

    m_ObjectDesc = new char[strlen(_ObjectDesc)];
    memcpy(m_ObjectDesc, _ObjectDesc, strlen(_ObjectDesc));
}

void Object::SetTrigger(char *_ObjectTrigger)
{
    if(m_ObjectTrigger)
    {
            delete[] m_ObjectTrigger;
    }

    m_ObjectTrigger = new char[strlen(_ObjectTrigger)];
    memcpy(m_ObjectTrigger, _ObjectTrigger, strlen(_ObjectTrigger));
}

void Object::SetResponse(char *_ObjectResponse)
{
    if(m_ObjectResponse)
    {
            delete[] m_ObjectResponse;
    }

    m_ObjectResponse = new char[strlen(_ObjectResponse)];
    memcpy(m_ObjectResponse, _ObjectResponse, strlen(_ObjectResponse));
}

void Object::SetAction(char *_ObjectAction)
{
    if(m_ObjectAction)
    {
            delete[] m_ObjectAction;
    }

    m_ObjectAction = new char[strlen(_ObjectAction)];
    memcpy(m_ObjectAction, _ObjectAction, strlen(_ObjectAction));
}
