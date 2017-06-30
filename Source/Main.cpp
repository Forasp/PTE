#include "../Include/Main.h"

int main(void)
{
    Initialize();

    while(m_Active)
    {
        Tick();
    }

    Destroy();

    return 0;
}

void Initialize(void)
{
    m_CurrentState = new char[1024];

	m_NumObjects = 0;

	m_NumFiles = 0;

	m_CurObject = -1;

	CountFiles();

	PopulateFileList();

	for(int i = 0; i < m_NumFiles; i++)
	{
		SetObjectCount(m_FileList[i]);
	}

    m_GameObjects = new Object*[m_NumObjects];

	for(int i = 0; i < m_NumFiles; i++)
	{
		PopulateObjects(m_FileList[i]);
	}

    m_Active = true;
}

void CountFiles(void)
{
	char *GameObjectConfigLine = new char[1024];

    std::ifstream GameObjectConfig;
    GameObjectConfig.open(FILE_LIST_LOCATION);

    while(GameObjectConfig.good())
    {
        GameObjectConfig.getline(GameObjectConfigLine, 1024);

        if(strcmp(GameObjectConfigLine, TYPE_FILENAME) == 0)
        {
            m_NumFiles++;
        }
        else if(strcmp(GameObjectConfigLine, TYPE_FILEEND) == 0)
        {
            break;
        }
    }

    GameObjectConfig.close();

    SAFE_ARRAY_DELETE(GameObjectConfigLine);
}

void PopulateFileList(void)
{
    char *GameObjectConfigLine = new char[1024];

    int CurObject = -1;

	m_FileList = new char*[m_NumFiles];

    std::ifstream GameObjectConfig;
    GameObjectConfig.open(FILE_LIST_LOCATION);

    while(GameObjectConfig.good())
    {
        GameObjectConfig.getline(GameObjectConfigLine, 1024);

        if(strcmp(GameObjectConfigLine, TYPE_FILENAME) == 0)
        {
			CurObject++;
            GameObjectConfig.getline(GameObjectConfigLine, 1024);
			m_FileList[CurObject] = new char[GET_CSTRING_SIZE(GameObjectConfigLine)];
			memcpy(m_FileList[CurObject],GameObjectConfigLine,GET_CSTRING_SIZE(GameObjectConfigLine));

        }
        else if(strcmp(GameObjectConfigLine, TYPE_FILEEND) == 0)
        {
            break;
        }
    }

    GameObjectConfig.close();

    SAFE_ARRAY_DELETE(GameObjectConfigLine);
}

void FindAndReplaceNewLines(char* _String)
{
    for(int i = 0; i < strlen(_String); i++)
    {
        if(_String[i] == '|')
        {
            _String[i] = '\n';
        }
    }
}

void Tick(void)
{
    char *InputString = new char[1024];
    std::cin >> InputString;

    for(long i = 0; i < m_NumObjects; i++)
    {
        bool SkipAction = false;

        if(m_GameObjects[i]->GetRequiredState())
        {
            SkipAction = (strcmp(m_CurrentState, m_GameObjects[i]->GetRequiredState()) == 0) ? false : true;
        }

        if((not SkipAction) && (m_GameObjects[i]->CheckTrigger(InputString)))
        {
            if(m_GameObjects[i]->GetResponse())
            {
                std::cout << m_GameObjects[i]->GetResponse() << "\n";
            }

            TakeAction(i);
			break;
        }
    }

    SAFE_ARRAY_DELETE(InputString);
}

void TakeAction(int _ObjectIndex)
{
    if(m_GameObjects[_ObjectIndex]->GetAction())
    {
        if(strcmp(m_GameObjects[_ObjectIndex]->GetAction(), TYPE_QUIT) == 0)
        {
            m_Active = false;
        }
        else if(strcmp(m_GameObjects[_ObjectIndex]->GetAction(), TYPE_ENTERSTATE) == 0)
        {
            EnterState(m_GameObjects[_ObjectIndex]->GetSubAction());
        }
    }
}

void EnterState(char* _State)
{
    SAFE_ARRAY_DELETE(m_CurrentState);
	size_t SizeOfCString = GET_CSTRING_SIZE(_State);

    m_CurrentState = new char[SizeOfCString];
    memcpy(m_CurrentState, _State, SizeOfCString);
}

void SetObjectCount(char* _File)
{
    char *GameObjectConfigLine = new char[1024];

    std::ifstream GameObjectConfig;
    GameObjectConfig.open(_File);
    while(not GameObjectConfig.eof())
    {
        GameObjectConfig.getline(GameObjectConfigLine, 1024);
        FindAndReplaceNewLines(GameObjectConfigLine);

        if(strcmp(GameObjectConfigLine, TYPE_OBJECTNAME) == 0)
        {
            m_NumObjects++;
        }
    }

    GameObjectConfig.close();

    SAFE_ARRAY_DELETE(GameObjectConfigLine);
}

void PopulateObjects(char* _File)
{
    char *GameObjectConfigLine = new char[1024];

    std::ifstream GameObjectConfig;
    GameObjectConfig.open(_File);

    while(not GameObjectConfig.eof())
    {
        GameObjectConfig.getline(GameObjectConfigLine, 1024);

        if(strcmp(GameObjectConfigLine, TYPE_OBJECT) == 0)
        {
            m_CurObject++;
            m_GameObjects[m_CurObject] = new Object();
        }
        else if(strcmp(GameObjectConfigLine, TYPE_OBJECTNAME) == 0)
        {
            GameObjectConfig.getline(GameObjectConfigLine, 1024);
            m_GameObjects[m_CurObject]->SetName(GameObjectConfigLine);
        }
        else if(strcmp(GameObjectConfigLine, TYPE_OBJECTDESC) == 0)
        {
            GameObjectConfig.getline(GameObjectConfigLine, 1024);
            m_GameObjects[m_CurObject]->SetDesc(GameObjectConfigLine);
        }
        else if(strcmp(GameObjectConfigLine, TYPE_OBJECTREQSTATE) == 0)
        {
            GameObjectConfig.getline(GameObjectConfigLine, 1024);
            m_GameObjects[m_CurObject]->SetRequiredState(GameObjectConfigLine);
        }
        else if(strcmp(GameObjectConfigLine, TYPE_OBJECTTRIGGER) == 0)
        {
            GameObjectConfig.getline(GameObjectConfigLine, 1024);
            m_GameObjects[m_CurObject]->SetTrigger(GameObjectConfigLine);
        }
        else if(strcmp(GameObjectConfigLine, TYPE_OBJECTRESPONSE) == 0)
        {
            GameObjectConfig.getline(GameObjectConfigLine, 1024);
            FindAndReplaceNewLines(GameObjectConfigLine);
            m_GameObjects[m_CurObject]->SetResponse(GameObjectConfigLine);
        }
        else if(strcmp(GameObjectConfigLine, TYPE_OBJECTACTION) == 0)
        {
            GameObjectConfig.getline(GameObjectConfigLine, 1024);
            m_GameObjects[m_CurObject]->SetAction(GameObjectConfigLine);

            if(strcmp(GameObjectConfigLine, TYPE_ENTERSTATE) == 0)
            {
                GameObjectConfig.getline(GameObjectConfigLine, 1024);
                m_GameObjects[m_CurObject]->SetSubAction(GameObjectConfigLine);
            }
        }
        else if(strcmp(GameObjectConfigLine, TYPE_FILEEND) == 0)
        {
            break;
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
