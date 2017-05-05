#include "../Include/Main.h"

int main(void)
{
    m_CurrentState = NULL;
    
    SetObjectCount();

    PopulateObjects();

    m_Active = true;

    while(m_Active)
    {
        Tick();
    }

    Destroy();

    return 0;
}

void Tick(void)
{
    char *InputString = new char[1024];
    std::cin >> InputString;

    for(long i = 0; i < m_NumObjects; i++)
    {
        bool SkipAction = false;
        
        if(m_GameObjects[i]->GetRequiredAction())
        {
            SkipAction = (strcmp(GameObjectConfigLine, m_GameObjects[i]->GetRequiredAction()) == 0) ? false : true;
        }
        
        if(!SkipAction && m_GameObjects[i]->CheckTrigger(InputString))
        {
            if(m_GameObjects[i]->GetResponse())
            {
                std::cout << m_GameObjects[i]->GetResponse() << "\n";
            }

            if(m_GameObjects[i]->GetAction())
            {
                TakeAction(m_GameObjects[i]->GetAction());
            }
        }
    }

    SAFE_ARRAY_DELETE(InputString);
}

void TakeAction(char* _Action)
{
    if(strcmp(_Action, "QUIT") == 0)
    {
        m_Active = false;
    }
    else if(strcmp(_Action, "ENTER_STATE") == 0)
    {
        EnterState(m_GameObjects[i]->GetSubAction());
    }
}

void EnterState(char* _State)
{
    SAFE_ARRAY_DELETE(m_CurrentState);
    m_CurrentState = new char[1024];
    memcpy(m_CurrentState, _State);
}

void SetObjectCount(void)
{
    m_NumObjects = 0;
    char *GameObjectConfigLine = new char[1024];

    std::ifstream GameObjectConfig;
    GameObjectConfig.open("GameObjects.pte");
    while(!GameObjectConfig.eof())
    {
        GameObjectConfig.getline(GameObjectConfigLine, 1024);

        if(strcmp(GameObjectConfigLine, "Object") == 0)
        {
            m_NumObjects++;
        }
    }

    GameObjectConfig.close();

    SAFE_ARRAY_DELETE(GameObjectConfigLine);
}

void PopulateObjects(void)
{
    char *GameObjectConfigLine = new char[1024];

    int CurObject = -1;

    m_GameObjects = new Object*[m_NumObjects];

    std::ifstream GameObjectConfig;
    GameObjectConfig.open("GameObjects.pte");

    while(CurObject < m_NumObjects)
    {
        GameObjectConfig.getline(GameObjectConfigLine, 1024);
        if(strcmp(GameObjectConfigLine, "Object") == 0)
        {
            CurObject++;
            m_GameObjects[CurObject] = new Object();
        }
        else if(strcmp(GameObjectConfigLine, "ObjectName") == 0)
        {
            GameObjectConfig.getline(GameObjectConfigLine, 1024);
            m_GameObjects[CurObject]->SetName(GameObjectConfigLine);
        }
        else if(strcmp(GameObjectConfigLine, "ObjectDescription") == 0)
        {
            GameObjectConfig.getline(GameObjectConfigLine, 1024);
            m_GameObjects[CurObject]->SetDesc(GameObjectConfigLine);
        }
        else if(strcmp(GameObjectConfigLine, "ObjectRequiredState") == 0)
        {
            GameObjectConfig.getline(GameObjectConfigLine, 1024);
            m_GameObjects[CurObject]->SetRequiredState(GameObjectConfigLine);
        }
        else if(strcmp(GameObjectConfigLine, "ObjectTrigger") == 0)
        {
            GameObjectConfig.getline(GameObjectConfigLine, 1024);
            m_GameObjects[CurObject]->SetTrigger(GameObjectConfigLine);
        }
        else if(strcmp(GameObjectConfigLine, "ObjectResponse") == 0)
        {
            GameObjectConfig.getline(GameObjectConfigLine, 1024);
            m_GameObjects[CurObject]->SetResponse(GameObjectConfigLine);
        }
        else if(strcmp(GameObjectConfigLine, "ObjectAction") == 0)
        {
            GameObjectConfig.getline(GameObjectConfigLine, 1024);
            m_GameObjects[CurObject]->SetAction(GameObjectConfigLine);
            
            if(strcmp(GameObjectConfigLine, "ENTER_STATE") == 0)
            {  
                GameObjectConfig.getline(GameObjectConfigLine, 1024);
                m_GameObjects[CurObject]->SetSubAction(GameObjectConfigLine);
            }
        }
        else if(strcmp(GameObjectConfigLine, "FILE_END") == 0)
        {
            CurObject++;
        }
    }

    GameObjectConfig.close();

    SAFE_ARRAY_DELETE(GameObjectConfigLine);
}

void Destroy(void)
{
    for(int i = 0; i < m_NumObjects; i++)
    {
        SAFE_DELETE(m_GameObjects[i]);
    }

    SAFE_ARRAY_DELETE(m_GameObjects);
}
