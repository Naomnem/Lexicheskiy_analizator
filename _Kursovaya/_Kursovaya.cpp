#include <iostream>
#include <fstream>
#include <queue>
#include "Scanner.h"
#include "Analizer.h"
using namespace std;

string readFile(string fileName)
{
    string result;
    ifstream file;
    file.open(fileName);
    while (!file.eof())
    {
        string tmp;
        getline(file, tmp);
        result += tmp + '\n';
    }
    return result;
}

void printTokens(list<Token*> tokens)
{
    cout << "Tokens" << endl << "----------------------------" << endl;
    for (Token* token : tokens)
    {
        cout << token << endl;
        cout << "----------------------------" << endl;
    }
}

void printTableOfNames(TableOfNames* tableOfNames)
{
    cout << "TableOfNames" << endl << "----------------------------------" << endl;
    queue<FieldOFView*> fields;
    fields.push(tableOfNames->getGlobalScale());
    int num = 0;
    while (!fields.empty())
    {
        FieldOFView* field = fields.front();
        fields.pop();
        std::map<std::string, IdentifierInfo*> identifiers = field->getIdentifiers();

        if (identifiers.size() > 0)
            std::cout << "InverstmentLevel: " << field->getInverstmentLevel() << std::endl;
        for (auto identifier : identifiers)
        {
            std::cout << identifier.first << "\t"
                << identifier.second << std::endl;
        }

        for (FieldOFView* child : field->getChilds())
        {
            fields.push(child);
        }
    }
}

int main()
{
    string fileSting = readFile("test.txt");
    Analizer* analizer = new Analizer(fileSting.c_str(), fileSting.length());
    Token* token = nullptr;
    try
    {
        analizer->Scan();
    }
    catch (BaseException* exception)
    {
        cout << exception;
        return -1;
    }
    catch (...)
    {
        cout << "Unknown Exception";
        return -1;
    }
    printTokens(analizer->getTokens());
    printTableOfNames(analizer->getTableOfNames());

}

