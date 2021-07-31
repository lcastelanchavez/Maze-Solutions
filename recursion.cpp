
#include <iostream>
using namespace std;

// Return true if there is a path from (sr,sc) to (er,ec)
// through the maze; return false otherwise

bool pathExists(char maze[][10], int sr, int sc, int er, int ec)
{
    if(sr == er && sc == ec )
        return true;
    
    maze[sr][sc] = '@';
    
    if(maze[sr+1][sc] == '.')       { //south
        if(pathExists(maze, sr+1, sc, er, ec))
            return true;
    }

    
    if(maze[sr-1][sc] == '.')  {          //north
        if(pathExists(maze, sr-1, sc, er, ec))
            return true;
    }
       
    
    if(maze[sr][sc+1] == '.')     {      //east
        if(pathExists(maze, sr, sc+1, er, ec))
            return true;
    }
       
    
    if(maze[sr][sc-1] == '.')     {     //west
        if(pathExists(maze, sr, sc-1, er, ec))
            return true;
    }
        
    
    return false;
}
         



int main() {
    char maze[10][10] = {
                   { 'X','X','X','X','X','X','X','X','X','X' },
                   { 'X','.','.','.','.','X','.','.','X','X' },
                   { 'X','.','X','X','.','X','X','.','.','X' },
                   { 'X','X','X','.','.','.','.','X','.','X' },
                   { 'X','.','X','X','X','.','X','X','X','X' },
                   { 'X','.','X','.','.','.','X','.','.','X' },
                   { 'X','.','.','.','X','.','X','.','.','X' },
                   { 'X','X','X','X','X','.','X','.','X','X' },
                   { 'X','.','.','.','.','.','.','.','.','X' },
                   { 'X','X','X','X','X','X','X','X','X','X' }
               };
           
               if (pathExists(maze, 3,5, 8,8))
                   cout << "Solvable!" << endl;
               else
                   cout << "Out of luck!" << endl;
    return 0;
}
