#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <queue>
#include <cstring>
#include "Graph.h"

using namespace std;

int main(int argc, char*argv[])
{
    Graph tour; //create a graph
    ifstream file;

    file.open("bestPlaces.txt");//open a file
    vector<string> cityList;

    if (file.is_open())
    {
        string line;
        string city;
        int linecounter = 0;

        while (getline (file,line))
        {
            stringstream citystream(line);

            if (linecounter == 0)
            {
                getline(citystream, city, ',');
                while(getline(citystream, city, ','))
                {
                    cityList.push_back(city);
                    tour.addVertex(city);
                }
            }
            else
            {
                string temp;
                int distValue;
                int numCounter = 0;
                getline(citystream, temp, ',');
                while(getline(citystream, temp, ','))
                {
                    distValue = stoi(temp);
                    if (distValue != 0 && distValue != -1)
                    {
                        tour.addEdge(cityList[linecounter-1], cityList[numCounter], distValue);
                    }
                    numCounter++;
                }
            }
            linecounter++;
        }
    }

    ifstream file2;
    file2.open()("landMarks.txt")
    List l;

    {
        if(file2.open())
        {
            string line;
            string line2;
            int cost;
            string landM;
            string city;
        }

        while(getline(file2,line))
        {
            int index = line.find(",");
            city = line.substr(0,index);
            line2 = line.substr(index+1, line.length());

            int index2 = line2,find(",");
            landM = line2.substr(0,index2);
            line3 = line2.substr(index2+1,line2.length());

            int index3 = line3.find(",");
            cost = stoi(line3.substr(0,index3));

            l.createLL(city,landM,cost);
        }
    }

    tour.assignDistricts();
    string input;

    while(true)
    {
        cout << "======Main Menu======" << endl;
        cout << "1. Print major cities" << endl;
        cout << "2. Connections of Cities" << endl;
        cout << "3. Things you can do with your budget" << endl;
        cout << "4. Landmarks " << endl;
        cout << "5. Landmarks to visit where you are" << endl;
        cout << "6. Quit" << endl;
        getline(cin,input);
        int choiceI = stoi(input);

        switch(choiceI)
        {
        case 1:
            {
                int g;
                for (int i=0;i<cityList.size()-1;i++)
                {
                    cout<<cityList[i]<<", ";
                    g=i;
                }
                cout<<cityList[g+1]<<endl;
                break;
            }
        case 2:
            {
                tour.displayEdges();
                break;
            }
        case 3:
            {
                string startingCity;
                cout << "Enter where you are:" << endl;
                cin.ignore(1,'\n');
                getline(cin, startingCity);
                string bu;
                cout << "Enter your budget:" << endl;
                getline(cin,bu);
                int b = stoi(bu);
                l.Budget(startingCity,b);
                break;
            }
        case 4:
            {
                string startingCity;
                cout << "Enter where you are:" << endl;
                cin.ignore(1, '\n');
                getline(cin, startingCity);
                bool found = false;
                for (int i=0; i < cityList.size(); i++)
                {
                    if (cityList[i] == startingCity)
                    {
                        found = true;
                    }
                }
                if (found == false)
                {
                    cout << "The city you entered is not in our database." << endl;
                }
                else
                {
                    l.poi(startingCity);
                }
                break;
            }
        case 5:
            {
                string startingCity;
                cout << "Enter where you are:" << endl;
                cin.ignore(1, '\n');
                getline(cin, startingCity);
                bool found = false;
                for (int i=0; i < cityList.size(); i++)
                {
                    if (cityList[i] == startingCity)
                    {
                        found = true;
                    }
                }
                if (found == false)
                {
                    cout << "The city you entered is not in our database." << endl;
                }
                else{
                l.popularLandmarks(startingCity);
            }
        case 6:
            {
                cout << "Goodbye!" << endl;
                false;
                break;

            }
        default:
            {
                cout << "Please choose a menu option" << endl;
            }

        }
    }




