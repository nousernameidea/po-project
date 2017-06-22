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
		
	/// <summary>
	/// Initializes a new instance of the <see cref="Item"/> class.
	/// </summary>
	/// <param name="">Item name.</param>
	/// <param name="">Attribute boosted by the item.</param>
	/// <param name="">Boost value of the item.</param>
	Item(string, int, int);
	
	/// <summary>
	/// Returns the name of the item.
	/// </summary>
	/// <returns></returns>
	string get_item_Name();
	
	/// <summary>
	/// Returns attribute boosted by the item.
	/// </summary>
	/// <returns></returns>
	int get_Item_Attribute();
		
	/// <summary>
	/// Returns boost value of the item.
	/// </summary>
	/// <returns></returns>
	int get_item_modifier();
};

#endif