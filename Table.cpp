//
//  Table.cpp
//  QueryLanguage
//
//  Created by Rohan Raja on 06/04/15.
//  Copyright (c) 2015 Rohan Raja. All rights reserved.
//

#include "Table.h"

using namespace std;

Table::Table()
{
    
    attrs.push_back(* new Attribute("id", 0));
    attrs.push_back(* new Attribute("name", 1));
    
    updateAttributes(attrs);
    
    vector<string> row;
    
    row.push_back("1");
    row.push_back("Rohan");
    tuples.push_back(row);
    
    row.clear();
    
    row.push_back("2");
    row.push_back("Sachin");
    tuples.push_back(row);
    
    row.clear();
    
    row.push_back("3");
    row.push_back("Tarin");
    tuples.push_back(row);
}

void Table::print()
{
    for (int i=0; i<attributes.size(); i++) {
        
        cout << attributes[i] << "\t" ;
    }
    cout << "\n";
    for (int i=0; i<attributes.size(); i++) {
        
        cout << "-" << "\t" ;
    }
    
    for(int j=0; j<tuples.size(); j++)
    {
        cout << "\n";
        
        for (int i=0; i<attributes.size(); i++) {
            
            cout << tuples[j][i] << "\t" ;
        }
    }
}

void Table::clear()
{
    tuples.clear();
    attributes.clear();
    
}


void Table::updateAttributes(vector<Attribute> pattrs)
{
    attrs = pattrs ;
    
    attributes.clear();
    for(int i=0; i<attrs.size(); i++)
    {
        attributes.push_back(attrs[i].name);
    }
}

int Table::getAttrIdx(string attr)
{
    for(int i=0; i<attributes.size(); i++)
    {
        if(attributes[i] == attr)
            return i;
    }
    
    return -1;
    
}

string Table::getCell(int row, Attribute attribute)
{
    return row<tuples.size() ? tuples[row][attribute.index] : "None";
}
