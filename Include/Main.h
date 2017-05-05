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

void TakeAction(char* _Action);

void EnterState(char* _State);

void SetObjectCount(void);

void PopulateObjects(void);

void Tick(void);

void Destroy(void);

int main(void);

#endif
