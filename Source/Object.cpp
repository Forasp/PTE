#include "../Include/Object.h"
#include "../Include/GlobalDefines.h"
#include <stdio.h>
#include <string.h>

Object::Object(void)
{
    m_ObjectID              = NULL;
    m_ObjectName            = NULL;
    m_ObjectDesc            = NULL;
    m_ObjectTrigger         = NULL;
    m_ObjectResponse        = NULL;
    m_ObjectAction          = NULL;
    m_ObjectSubAction       = NULL;
    m_ObjectRequiredState   = NULL;
}

Object::Object(long _ObjectID,
               char *_ObjectName,
               char *_ObjectDesc)
{
    m_ObjectTrigger         = NULL;
    m_ObjectResponse        = NULL;
    m_ObjectAction          = NULL;
    m_ObjectSubAction       = NULL;
    m_ObjectRequiredState   = NULL;

    Initialize(_ObjectID, _ObjectName, _ObjectDesc);
}

Object::~Object(void)
{
    Destroy();
}

void Object::Initialize(long _ObjectID,
                        char *_ObjectName,
                        char *_ObjectDesc)
{
    SAFE_ARRAY_DELETE(m_ObjectName);
    SAFE_ARRAY_DELETE(m_ObjectDesc);
    m_ObjectName = new char[strlen(_ObjectName)];
    m_ObjectDesc = new char[strlen(_ObjectDesc)];
    memcpy(m_ObjectName, _ObjectName, strlen(_ObjectName));
    memcpy(m_ObjectDesc, _ObjectDesc, strlen(_ObjectDesc));
    m_ObjectID = _ObjectID;
}

void Object::Destroy(void)
{
    SAFE_ARRAY_DELETE(m_ObjectName);
    SAFE_ARRAY_DELETE(m_ObjectDesc);
    SAFE_ARRAY_DELETE(m_ObjectTrigger);
    SAFE_ARRAY_DELETE(m_ObjectResponse);
    SAFE_ARRAY_DELETE(m_ObjectAction);
}

bool Object::CheckTrigger(char *_Trigger)
{
    return(m_ObjectTrigger && (strcmp(_Trigger, m_ObjectTrigger) == 0));
}

void Object::SetName(char *_ObjectName)
{
    SAFE_ARRAY_DELETE(m_ObjectName);
	size_t SizeOfCString = GET_CSTRING_SIZE(_ObjectName);

    m_ObjectName = new char[SizeOfCString];
    memcpy(m_ObjectName, _ObjectName, SizeOfCString);
}

void Object::SetDesc(char *_ObjectDesc)
{
    SAFE_ARRAY_DELETE(m_ObjectDesc);
	size_t SizeOfCString = GET_CSTRING_SIZE(_ObjectDesc);

    m_ObjectDesc = new char[SizeOfCString];
    memcpy(m_ObjectDesc, _ObjectDesc, SizeOfCString);
}

void Object::SetTrigger(char *_ObjectTrigger)
{
    SAFE_ARRAY_DELETE(m_ObjectTrigger);
	size_t SizeOfCString = GET_CSTRING_SIZE(_ObjectTrigger);

    m_ObjectTrigger = new char[SizeOfCString];
    memcpy(m_ObjectTrigger, _ObjectTrigger, SizeOfCString);
}

void Object::SetResponse(char *_ObjectResponse)
{
    SAFE_ARRAY_DELETE(m_ObjectResponse);
	size_t SizeOfCString = GET_CSTRING_SIZE(_ObjectResponse);

    m_ObjectResponse = new char[SizeOfCString];
    memcpy(m_ObjectResponse, _ObjectResponse, SizeOfCString);
}

void Object::SetAction(char *_ObjectAction)
{
    SAFE_ARRAY_DELETE(m_ObjectAction);
	size_t SizeOfCString = GET_CSTRING_SIZE(_ObjectAction);

    m_ObjectAction = new char[SizeOfCString];
    memcpy(m_ObjectAction, _ObjectAction, SizeOfCString);
}

void Object::SetSubAction(char *_ObjectSubAction)
{
    SAFE_ARRAY_DELETE(m_ObjectSubAction);
	size_t SizeOfCString = GET_CSTRING_SIZE(_ObjectSubAction);

    m_ObjectSubAction = new char[SizeOfCString];
    memcpy(m_ObjectSubAction, _ObjectSubAction, SizeOfCString);
}

void Object::SetRequiredState(char *_ObjectRequiredState)
{
    SAFE_ARRAY_DELETE(m_ObjectRequiredState);
	size_t SizeOfCString = GET_CSTRING_SIZE(_ObjectRequiredState);

    m_ObjectRequiredState = new char[SizeOfCString];
    memcpy(m_ObjectRequiredState, _ObjectRequiredState, SizeOfCString);
}
