#ifndef INCLUDE_MAIN
#define INCLUDE_MAIN
#include "../Include/Object.h"
#include "../Include/GlobalDefines.h"
#include <string.h>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#define FILE_LIST_LOCATION	"Objects/FileList.pte"
#define TYPE_FILENAME		"FILE_NAME"
#define TYPE_FILEEND		"FILE_END"
#define TYPE_ENTERSTATE		"ENTER_STATE"
#define TYPE_QUIT			"QUIT"
#define TYPE_OBJECT			"Object"
#define TYPE_OBJECTNAME		"ObjectName"
#define TYPE_OBJECTDESC		"ObjectDescription"
#define TYPE_OBJECTREQSTATE	"ObjectRequiredState"
#define TYPE_OBJECTTRIGGER	"ObjectTrigger"
#define TYPE_OBJECTRESPONSE	"ObjectResponse"
#define TYPE_OBJECTACTION	"ObjectAction"

char *m_CurrentState;
char **m_FileList;
Object **m_GameObjects;
bool m_Active;
int m_NumObjects;
int m_NumFiles;
int m_CurObject;

void TakeAction(int _ObjectIndex);

void EnterState(char* _State);

void SetObjectCount(char* _File);

void PopulateObjects(char* _File);

void PopulateFileList(void);

void CountFiles(void);

void FindAndReplaceNewLines(char* _String);

void Tick(void);

void Destroy(void);

void Initialize(void);

int main(void);

#endif
