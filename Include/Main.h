#ifndef INCLUDE_MAIN
#define INCLUDE_MAIN
#include "../Include/Object.h"
#include "../Include/GlobalDefines.h"
#include <string.h>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

char *m_CurrentState;
Object **m_GameObjects;
bool m_Active;
int m_NumObjects;

void TakeAction(int _ObjectIndex);

void EnterState(char* _State);

void SetObjectCount(void);

void PopulateObjects(void);

void FindAndReplaceNewLines(char* _String);

void Tick(void);

void Destroy(void);

void Initialize(void);

int main(void);

#endif
