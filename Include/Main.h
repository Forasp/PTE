#ifndef INCLUDE_MAIN
#define INCLUDE_MAIN
#include "../Include/Object.h"
#define NULL 0

Object** m_GameObjects;
bool m_Active;
int m_NumObjects;

#include "../Include/Main.h"
#include <string.h>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

void TakeAction(char* _Action);

void SetObjectCount(void);

void PopulateObjects(void);

void Tick(void);

void Destroy(void);

int main(void);

#endif
