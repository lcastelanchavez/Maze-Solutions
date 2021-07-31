#include <iostream>
#include <stack>
using namespace std;


class Coord
        {
          public:
            Coord(int r, int c) : m_row(r), m_col(c) {}
            int r() const { return m_row; }
            int c() const { return m_col; }
          private:
            int m_row;
            int m_col;
        };

// Return true if there is a path from (sr,sc) to (er,ec)
// through the maze; return false otherwise


bool pathExists(char maze[][10], int sr, int sc, int er, int ec)
{
    stack<Coord> coordStack;
    coordStack.push(Coord(sr,sc));
    maze[sr][sc] = '@';
    
    while (!coordStack.empty())
    {
        Coord curr = coordStack.top();
        int curr_row = curr.r();
        int curr_col = curr.c();
        coordStack.pop();
        
        if (curr_row == er && curr_col == ec) //if current position at end of maze
        {
            return true;
        }
        
        if (maze[curr_row+1][curr_col] == '.') //moving south
        {
            Coord nextPos = Coord(curr_row+1,curr_col);
            coordStack.push(nextPos);
            maze[curr_row+1][curr_col] = '@';
        }
        
        if (maze[curr_row][curr_col-1] == '.') //moving west
        {
            Coord nextPos = Coord(curr_row,curr_col-1);
            coordStack.push(nextPos);
            maze[curr_row][curr_col-1] = '@';
        }
        
        if(maze[curr_row-1][curr_col] == '.') //moving North
        {
            Coord nextPos = Coord(curr_row-1,curr_col);
            coordStack.push(nextPos);
            maze[curr_row-1][curr_col] = '@';
        }
        
        if (maze[curr_row][curr_col+1] == '.') //moving East
        {
            Coord nextPos = Coord(curr_row,curr_col+1);
            coordStack.push(nextPos);
            maze[curr_row][curr_col+1] = '@';
        }
    }
    
    return false; //if cannot move anymore, return false so no path
}
          


int main() {
    stack<Coord> coordStack;     // declare a stack of Coords
            
    Coord a(5,6);
    coordStack.push(a);          // push the coordinate (5,6)
    coordStack.push(Coord(3,4)); // push the coordinate (3,4)
    //Coord b = coordStack.top();  // look at top item in the stack
    coordStack.pop();            // remove the top item from stack
    if (coordStack.empty())      // Is the stack empty?
        cout << "empty!" << endl;
    cout << coordStack.size() << endl;  // num of elements
    
    
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
