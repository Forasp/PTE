#ifndef INCLUDE_OBJECT
#define INCLUDE_OBJECT
#include <iostream>

class Object
{
public:
    Object(void);
    Object(long _ObjectID,
           char *_ObjectName,
           char *_ObjectDesc);
    ~Object(void);

    void Initialize(long _ObjectID,
                    char *_ObjectName,
                    char *_ObjectDesc);
    void Destroy(void);

    bool CheckTrigger(char *_Trigger);

    char *GetName(void){return m_ObjectName;}
    char *GetDesc(void){return m_ObjectDesc;}
    char *GetTrigger(void){return m_ObjectTrigger;}
    char *GetResponse(void){return m_ObjectResponse;}
    char *GetAction(void){return m_ObjectAction;}
    char *GetRequiredState(void){return m_ObjectRequiredState;}

    void SetName(char *_ObjectName);
    void SetDesc(char *_ObjectDesc);
    void SetTrigger(char *_ObjectTrigger);
    void SetResponse(char *_ObjectResponse);
    void SetAction(char *_ObjectAction);
    void SetRequiredState(char *_ObjectRequiredState);
    
    long GetID(void){return m_ObjectID;}

private:
    long m_ObjectID;

    char *m_ObjectName;
    char *m_ObjectDesc;
    char *m_ObjectTrigger;
    char *m_ObjectResponse;
    char *m_ObjectAction;
    char *m_ObjectRequiredState;
};

#endif
