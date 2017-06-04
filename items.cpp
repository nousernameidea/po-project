#include "stdafx.h"
#include "items.h"

Item::Item() {}

Item::Item(string itemname, int attribute, int modif)
{
	this->ItemName = itemname;
	this->Attribute = attribute;
	this->modifier = modif;
}

string Item::get_item_Name()
{
	return this->ItemName;
}

int Item::get_Item_Attribute()
{
	return this->Attribute;
}

int Item::get_item_modifier()
{
	return this->modifier;
}
