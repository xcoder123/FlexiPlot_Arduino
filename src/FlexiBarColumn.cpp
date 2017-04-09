#include "FlexiBarColumn.h"

FlexiBarColumn::FlexiBarColumn(char * column_name)
{
  strcpy(this->column_name, column_name);
}

char * FlexiBarColumn::getName()
{
  return column_name;
}

FlexiBarColumn::~FlexiBarColumn()
{
  delete [] this->column_name;
}

