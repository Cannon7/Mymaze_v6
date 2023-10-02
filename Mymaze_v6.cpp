#include <map>
#include <iostream>
#include <list>
#include <string>
#include <algorithm>
#include <fstream>
using namespace std;
//creates our solution list
    list<int> SolList = {};
    void Render()
    {
        //render will print out the maze from the mazedata2.txt file
        string data;
        ifstream Mazefile;
        int counter = 1;
        for (int col = 1; col <= 20; col++)
        {
            for (int row = 1; row <= 20; row++)
            {
                Mazefile.open("mazedata2.txt", ios::in);
                for (int i = 0; i < counter; i++)
                {
                    getline(Mazefile, data);
                }
                //prints a row of 20
                std::cout << data;
                counter += 1;
                Mazefile.close();
            }
            //next row
            std::cout << "\n";
        }
        Mazefile.close();
    }
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    bool FindInList(int square)
    {
        //bool that finds if an item is in a list
        list<int>::iterator iter;
        iter = find(SolList.begin(), SolList.end(), square);
        if (iter != SolList.end())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    string spaceget(int line)
    {
        //checks the data that populates the line#
        string data;
        ifstream Mazefile;
        Mazefile.open("mazedata2.txt", ios::in);
        for (int i = 0; i < line; i++)
        {
            getline(Mazefile, data);
        }
        Mazefile.close();
        return data;
    }
    bool Solver(int position, int end, int last)
    {
        //recursion mess that will check up, down, left, right
        //adds item to the list when it reaches the end
        if (spaceget((position + 20)) == "  ")
        {
            if ((position + 20) != last)
            {
                if (position = end)
                {
                    SolList.push_front(position);
                    return true;
                }
                last = position;
                position = position + 20;
                Solver(position, end, last);
            }
        }
        if (spaceget((position - 20)) == "  ")
        {
            if ((position - 20) != last)
            {
                if (position = end)
                {
                    SolList.push_front(position);
                    return true;
                }
                last = position;
                position = position - 20;
                Solver(position, end, last);
            }
        }
        if (spaceget((position + 1)) == "  ")
        {
            if ((position + 1) != last)
            {
                if (position = end)
                {
                    SolList.push_front(position);
                    return true;
                }
                last = position;
                position = position + 1;
                Solver(position, end, last);
            }
        }
        if (spaceget((position - 1)) == "  ")
        {
            if ((position - 1) != last)
            {
                if (position = end)
                {
                    SolList.push_front(position);
                    return true;
                }
                last = position;
                position = position - 1;
                Solver(position, end, last); 
            }
        }
    }
    void RenderSolution()
    {
        //prints out maze and presents a "O" that is thhhe recursions solution
        string data;
        ifstream Mazefile;
        int counter = 1;
        for (int col = 1; col <= 20; col++)
        {
            for (int row = 1; row <= 20; row++)
            {
                if (FindInList(counter))
                {
                    data = "O ";
                }
                else
                {
                    Mazefile.open("mazedata2.txt", ios::in);
                    for (int i = 0; i < counter; i++)
                    {
                        getline(Mazefile, data);

                    }
                }

                std::cout << data;
                counter += 1;
                Mazefile.close();
            }
            std::cout << "\n";
        }
        Mazefile.close();
    }
    void RunSol()
    {
        string datastart;
        ifstream Mazefile;
        int mazestart;
        int mazeend;
        int checker = 0;
        Mazefile.open("mazedata2.txt", ios::in);
        for (int i = 1; i <= 400; i++)
        {
            checker = checker + 1;
            getline(Mazefile, datastart);
            if (datastart == "S ")
            {
                mazestart = checker;
            }
            if (datastart == "E ")
            {
                mazeend = checker;
            }
        }
        Mazefile.close();
        bool palcehold = Solver(mazestart, mazeend, mazestart+10);
        RenderSolution(); 
    }

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
//prints normal maze
   Render();
//prints recursion solution
   RunSol();
}