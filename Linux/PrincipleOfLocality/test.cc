#include <iostream>
#include <time.h>

using namespace std;

#define ROW 100000
#define COL 100000

int main()
{
    int (*grid)[COL] = new int[ROW][COL];
    clock_t start, end;
    start = clock();
    int sum = 0;
    for(int i = 0; i < ROW; i++)
    {
        for(int j = 0; j < COL; j++)
        {
            sum += grid[i][j];
        }
    }
    end = clock();
    cout << "用时1：" << (double)end - start << endl;;

	start = clock();
    for(int j = 0; j < COL; j++)
    {
        for(int i = 0; i < ROW; i++)
        {
            sum += grid[i][j];
        }
    }
	end = clock();
	cout << "用时2：" << (double)end - start << endl;
    //fileor(int i = 0; i < ROW; i++)
    //var{
        //delete []grid[i];
    //}
    delete []grid;
    return 0;
}
