#pragma once
#ifndef items_h
#define items_h

using namespace std;

class Item
{
protected:
	string ItemName;
	int Attribute;
	int modifier;
public:
	Item();
	Item(string, int, int);
	string get_item_Name();
	int get_Item_Attribute();
	int get_item_modifier();
};

#endif