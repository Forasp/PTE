#include "../Include/Main.h"
#include <string.h>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

void TakeAction(char* _Action)
{
    if(strcmp(_Action, "QUIT") == 0)
    {
        m_Active = false;
    }
}

int GetObjectCount()
{
    int NumObjects = 0;
    char *GameObjectConfigLine = new char[1024];

    std::ifstream GameObjectConfig;
    GameObjectConfig.open("GameObjects.pte");
    while(!GameObjectConfig.eof())
    {
        GameObjectConfig.getline(GameObjectConfigLine, 1024);
        if(strcmp(GameObjectConfigLine, "Object") == 0)
        {
            NumObjects++;
        }
    }

    GameObjectConfig.close();

    return NumObjects;
}

int main(void)
{
    int NumObjects = GetObjectCount();
    int CurObject = -1;
    char *GameObjectConfigLine = new char[1024];
    m_Active = true;

    std::ifstream GameObjectConfig;
    GameObjectConfig.open("GameObjects.pte");
    m_GameObjects = new Object*[NumObjects];

    while(CurObject < NumObjects)
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
        }
        else if(strcmp(GameObjectConfigLine, "FILE_END") == 0)
        {
            CurObject++;
        }
    }

    GameObjectConfig.close();

    while(m_Active)
    {
        char *InputString = new char[1024];
        std::cin >> InputString;

        for(long i = 0; i < NumObjects; i++)
        {
            if(m_GameObjects[i]->CheckTrigger(InputString))
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

        delete[] InputString;
    }

    return 0;
}
