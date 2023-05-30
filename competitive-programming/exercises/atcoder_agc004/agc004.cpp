#include <bits/stdc++.h>

using namespace std;

int main()
{
    /*
     ===| matx |===
     -   All columns from first row
     -   No columns from last row
     -   Just column odd

     ===| maty |===
     -  The rest of matx.
    */

    int rows, cols;
    char charFromSampleMatrix;

    cin >> rows >> cols;

    char matx[500][500];
    char maty[500][500];

    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            if (r == 0 || (c % 2 != 0 && r != rows - 1))
            {
                matx[r][c] = '#';
                maty[r][c] = '.';
            }
            else
            {
                matx[r][c] = '.';
                maty[r][c] = '#';
            }

            cin >> charFromSampleMatrix;

            if (charFromSampleMatrix == '#')
            {
                if (matx[r][c] == '#')
                {
                    maty[r][c] = '#';
                }
                else
                {
                    matx[r][c] = '#';
                }
            }
            cout << matx[r][c];
        }
        cout << endl;
    }

    cout << endl;

    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            cout << maty[r][c];
        }
        cout << endl;
    }
}

// =================== Explaning code:

/*
    [ 100% Accepted ]
    This code works because have many possibilities for each case.

    The main idea for solution was watched on this video https://youtu.be/eTlDbJlqLTc,

    The main idea is to use the concept of Greedy Algorithms to paint the two matrices in a way that they initially have no intersection, but can be easily combined.
    It is like:

    Matrix X
    #####
    .#.#.
    .#.#.
    .....

    Matrix Y
    .....
    #.#.#
    #.#.#
    #####

    After that is easy to make intersections.

    My test case for this code:

    - Input

    5 5
    .....
    .#.#.
    .....
    .#.#.
    .....

    - Output

    #####
    .#.#.
    .#.#.
    .#.#.
    .....

    .....
    #####
    #.#.#
    #####
*/