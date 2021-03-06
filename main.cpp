#include <iostream>
#include <queue>
#include <ctime>


class side
{
    
    char main_color;
    char colors [8];
    
public:
    
    void SetColors(char first, char second, char third, char forth, char fifth, char sixth, char seventh, char eighth)
    {
        colors[0] = first; colors[1] = second; colors[2] = third; colors[3] = forth; colors[4] = fifth; colors[5] = sixth; colors[6] = seventh; colors[7] = eighth;
    }
    
    void SetMain(char m)
    {
        main_color = m;
    }
    
    char* GetColors()
    {
        return colors;
    }
    
    bool solved()
    {
        for (int i = 0; i < 8; i++)
            if (colors[i] != main_color)
                return 0;
        return 1;
    }
    
};

class cube
{
    
    side sides [6];
    
public:
    
    bool solved()
    {
        for (int i = 0; i < 6; i++)
            if (!sides[i].solved())
                return 0;
        return 1;
    }
    
    void SetColors()
    {
        std::string colors [6] = {"WHITE ", "YELLOW", "GREEN ", "BLUE  ", "RED   ", "ORANGE"};
        char c [6] = {'w', 'y', 'g', 'b', 'r', 'o'};
        char first, second, third, forth, fifth, sixth, seventh, eighth;
        for (int i = 0; i < 6; i++)
        {
            std::cout << "input the " << colors[i] << " side: ";
            std::cin >> first >> second >> third >> forth >> fifth >> sixth >> seventh >> eighth;
            sides[i].SetColors(first, second, third, forth, fifth, sixth, seventh, eighth);
            sides[i].SetMain(c[i]);
        }
    }
    
    void RotateUp()
    {
        side up = sides[0];
        side front = sides[2];
        side back = sides[3];
        side right = sides[4];
        side left = sides[5];
        sides[0].SetColors(up.GetColors()[6], up.GetColors()[7], up.GetColors()[0], up.GetColors()[1], up.GetColors()[2], up.GetColors()[3], up.GetColors()[4], up.GetColors()[5]);
        sides[2].SetColors(right.GetColors()[0], right.GetColors()[1], right.GetColors()[2], front.GetColors()[3], front.GetColors()[4], front.GetColors()[5], front.GetColors()[6], front.GetColors()[7]);
        sides[3].SetColors(left.GetColors()[0], left.GetColors()[1], left.GetColors()[2], back.GetColors()[3], back.GetColors()[4], back.GetColors()[5], back.GetColors()[6], back.GetColors()[7]);
        sides[4].SetColors(back.GetColors()[0], back.GetColors()[1], back.GetColors()[2], right.GetColors()[3], right.GetColors()[4], right.GetColors()[5], right.GetColors()[6], right.GetColors()[7]);
        sides[5].SetColors(front.GetColors()[0], front.GetColors()[1], front.GetColors()[2], left.GetColors()[3], left.GetColors()[4], left.GetColors()[5], left.GetColors()[6], left.GetColors()[7]);
    }
    
    void RotateDown()
    {
        side down = sides[1];
        side front = sides[2];
        side back = sides[3];
        side right = sides[4];
        side left = sides[5];
        sides[1].SetColors(down.GetColors()[6], down.GetColors()[7], down.GetColors()[0], down.GetColors()[1], down.GetColors()[2], down.GetColors()[3], down.GetColors()[4], down.GetColors()[5]);
        sides[2].SetColors(front.GetColors()[0], front.GetColors()[1], front.GetColors()[2], front.GetColors()[3], left.GetColors()[4], left.GetColors()[5], left.GetColors()[6], front.GetColors()[7]);
        sides[3].SetColors(back.GetColors()[0], back.GetColors()[1], back.GetColors()[2], back.GetColors()[3], right.GetColors()[4], right.GetColors()[5], right.GetColors()[6], back.GetColors()[7]);
        sides[4].SetColors(right.GetColors()[0], right.GetColors()[1], right.GetColors()[2], right.GetColors()[3], front.GetColors()[4], front.GetColors()[5], front.GetColors()[6], right.GetColors()[7]);
        sides[5].SetColors(left.GetColors()[0], left.GetColors()[1], left.GetColors()[2], left.GetColors()[3], back.GetColors()[4], back.GetColors()[5], back.GetColors()[6], left.GetColors()[7]);
    }
    
    void RotateFront()
    {
        side up = sides[0];
        side down = sides[1];
        side front = sides[2];
        side right = sides[4];
        side left = sides[5];
        sides[0].SetColors(up.GetColors()[0], up.GetColors()[1], up.GetColors()[2], up.GetColors()[3], left.GetColors()[2], left.GetColors()[3], left.GetColors()[4], up.GetColors()[7]);
        sides[1].SetColors(right.GetColors()[6], right.GetColors()[7], right.GetColors()[0], down.GetColors()[3], down.GetColors()[4], down.GetColors()[5], down.GetColors()[6], down.GetColors()[7]);
        sides[2].SetColors(front.GetColors()[6], front.GetColors()[7], front.GetColors()[0], front.GetColors()[1], front.GetColors()[2], front.GetColors()[3], front.GetColors()[4], front.GetColors()[5]);
        sides[4].SetColors(up.GetColors()[6], right.GetColors()[1], right.GetColors()[2], right.GetColors()[3], right.GetColors()[4], right.GetColors()[5], up.GetColors()[4], up.GetColors()[5]);
        sides[5].SetColors(left.GetColors()[0], left.GetColors()[1], down.GetColors()[0], down.GetColors()[1], down.GetColors()[2], left.GetColors()[5], left.GetColors()[6], left.GetColors()[7]);
    }
    
    void RotateBack()
    {
        side up = sides[0];
        side down = sides[1];
        side back = sides[3];
        side right = sides[4];
        side left = sides[5];
        sides[0].SetColors(right.GetColors()[2], right.GetColors()[3], right.GetColors()[4], up.GetColors()[3], up.GetColors()[4], up.GetColors()[5], up.GetColors()[6], up.GetColors()[7]);
        sides[1].SetColors(down.GetColors()[0], down.GetColors()[1], down.GetColors()[2], down.GetColors()[3], left.GetColors()[6], left.GetColors()[7], left.GetColors()[0], down.GetColors()[7]);
        sides[3].SetColors(back.GetColors()[6], back.GetColors()[7], back.GetColors()[0], back.GetColors()[1], back.GetColors()[2], back.GetColors()[3], back.GetColors()[4], back.GetColors()[5]);
        sides[4].SetColors(right.GetColors()[0], right.GetColors()[1], down.GetColors()[4], down.GetColors()[5], down.GetColors()[6], right.GetColors()[5], right.GetColors()[6], right.GetColors()[7]);
        sides[5].SetColors(up.GetColors()[2], left.GetColors()[1], left.GetColors()[2], left.GetColors()[3], left.GetColors()[4], left.GetColors()[5], up.GetColors()[0], up.GetColors()[1]);
    }
    
    void RotateRight()
    {
        side up = sides[0];
        side down = sides[1];
        side front = sides[2];
        side back = sides[3];
        side right = sides[4];
        sides[0].SetColors(up.GetColors()[0], up.GetColors()[1], front.GetColors()[2], front.GetColors()[3], front.GetColors()[4], up.GetColors()[5], up.GetColors()[6], up.GetColors()[7]);
        sides[1].SetColors(down.GetColors()[0], down.GetColors()[1], back.GetColors()[6], back.GetColors()[7], back.GetColors()[0], down.GetColors()[5], down.GetColors()[6], down.GetColors()[7]);
        sides[2].SetColors(front.GetColors()[0], front.GetColors()[1], down.GetColors()[2], down.GetColors()[3], down.GetColors()[4], front.GetColors()[5], front.GetColors()[6], front.GetColors()[7]);
        sides[3].SetColors(up.GetColors()[4], back.GetColors()[1], back.GetColors()[2], back.GetColors()[3], back.GetColors()[4], back.GetColors()[5], up.GetColors()[2], up.GetColors()[3]);
        sides[4].SetColors(right.GetColors()[6], right.GetColors()[7], right.GetColors()[0], right.GetColors()[1], right.GetColors()[2], right.GetColors()[3], right.GetColors()[4], right.GetColors()[5]);
    }
    
    void RotateLeft()
    {
        side up = sides[0];
        side down = sides[1];
        side front = sides[2];
        side back = sides[3];
        side left = sides[5];
        sides[0].SetColors(back.GetColors()[4], up.GetColors()[1], up.GetColors()[2], up.GetColors()[3], up.GetColors()[4], up.GetColors()[5], back.GetColors()[2], back.GetColors()[3]);
        sides[1].SetColors(front.GetColors()[0], down.GetColors()[1], down.GetColors()[2], down.GetColors()[3], down.GetColors()[4], down.GetColors()[5], front.GetColors()[6], front.GetColors()[7]);
        sides[2].SetColors(up.GetColors()[0], front.GetColors()[1], front.GetColors()[2], front.GetColors()[3], front.GetColors()[4], front.GetColors()[5], up.GetColors()[6], up.GetColors()[7]);
        sides[3].SetColors(back.GetColors()[0], back.GetColors()[1], down.GetColors()[6], down.GetColors()[7], down.GetColors()[0], back.GetColors()[5], back.GetColors()[6], back.GetColors()[7]);
        sides[5].SetColors(left.GetColors()[6], left.GetColors()[7], left.GetColors()[0], left.GetColors()[1], left.GetColors()[2], left.GetColors()[3], left.GetColors()[4], left.GetColors()[5]);
    }
    
    void RotateUpDash()
    {
        side up = sides[0];
        side front = sides[2];
        side back = sides[3];
        side right = sides[4];
        side left = sides[5];
        sides[0].SetColors(up.GetColors()[2], up.GetColors()[3], up.GetColors()[4], up.GetColors()[5], up.GetColors()[6], up.GetColors()[7], up.GetColors()[0], up.GetColors()[1]);
        sides[2].SetColors(left.GetColors()[0], left.GetColors()[1], left.GetColors()[2], front.GetColors()[3], front.GetColors()[4], front.GetColors()[5], front.GetColors()[6], front.GetColors()[7]);
        sides[3].SetColors(right.GetColors()[0], right.GetColors()[1], right.GetColors()[2], back.GetColors()[3], back.GetColors()[4], back.GetColors()[5], back.GetColors()[6], back.GetColors()[7]);
        sides[4].SetColors(front.GetColors()[0], front.GetColors()[1], front.GetColors()[2], right.GetColors()[3], right.GetColors()[4], right.GetColors()[5], right.GetColors()[6], right.GetColors()[7]);
        sides[5].SetColors(back.GetColors()[0], back.GetColors()[1], back.GetColors()[2], left.GetColors()[3], left.GetColors()[4], left.GetColors()[5], left.GetColors()[6], left.GetColors()[7]);
    }
    
    void RotateDownDash()
    {
        side down = sides[1];
        side front = sides[2];
        side back = sides[3];
        side right = sides[4];
        side left = sides[5];
        sides[1].SetColors(down.GetColors()[2], down.GetColors()[3], down.GetColors()[4], down.GetColors()[5], down.GetColors()[6], down.GetColors()[7], down.GetColors()[0], down.GetColors()[1]);
        sides[2].SetColors(front.GetColors()[0], front.GetColors()[1], front.GetColors()[2], front.GetColors()[3], right.GetColors()[4], right.GetColors()[5], right.GetColors()[6], front.GetColors()[7]);
        sides[3].SetColors(back.GetColors()[0], back.GetColors()[1], back.GetColors()[2], back.GetColors()[3], left.GetColors()[4], left.GetColors()[5], left.GetColors()[6], back.GetColors()[7]);
        sides[4].SetColors(right.GetColors()[0], right.GetColors()[1], right.GetColors()[2], right.GetColors()[3], back.GetColors()[4], back.GetColors()[5], back.GetColors()[6], right.GetColors()[7]);
        sides[5].SetColors(left.GetColors()[0], left.GetColors()[1], left.GetColors()[2], left.GetColors()[3], front.GetColors()[4], front.GetColors()[5], front.GetColors()[6], left.GetColors()[7]);
    }
    
    void RotateFrontDash()
    {
        side up = sides[0];
        side down = sides[1];
        side front = sides[2];
        side right = sides[4];
        side left = sides[5];
        sides[0].SetColors(up.GetColors()[0], up.GetColors()[1], up.GetColors()[2], up.GetColors()[3], right.GetColors()[6], right.GetColors()[7], right.GetColors()[0], up.GetColors()[7]);
        sides[1].SetColors(left.GetColors()[2], left.GetColors()[3], left.GetColors()[4], down.GetColors()[3], down.GetColors()[4], down.GetColors()[5], down.GetColors()[6], down.GetColors()[7]);
        sides[2].SetColors(front.GetColors()[2], front.GetColors()[3], front.GetColors()[4], front.GetColors()[5], front.GetColors()[6], front.GetColors()[7], front.GetColors()[0], front.GetColors()[1]);
        sides[4].SetColors(down.GetColors()[2], right.GetColors()[1], right.GetColors()[2], right.GetColors()[3], right.GetColors()[4], right.GetColors()[5], down.GetColors()[0], down.GetColors()[1]);
        sides[5].SetColors(left.GetColors()[0], left.GetColors()[1], up.GetColors()[4], up.GetColors()[5], up.GetColors()[6], left.GetColors()[5], left.GetColors()[6], left.GetColors()[7]);
    }
    
    void RotateBackDash()
    {
        side up = sides[0];
        side down = sides[1];
        side back = sides[3];
        side right = sides[4];
        side left = sides[5];
        sides[0].SetColors(left.GetColors()[6], left.GetColors()[7], left.GetColors()[0], up.GetColors()[3], up.GetColors()[4], up.GetColors()[5], up.GetColors()[6], up.GetColors()[7]);
        sides[1].SetColors(down.GetColors()[0], down.GetColors()[1], down.GetColors()[2], down.GetColors()[3], right.GetColors()[2], right.GetColors()[3], right.GetColors()[4], down.GetColors()[7]);
        sides[3].SetColors(back.GetColors()[2], back.GetColors()[3], back.GetColors()[4], back.GetColors()[5], back.GetColors()[6], back.GetColors()[7], back.GetColors()[0], back.GetColors()[1]);
        sides[4].SetColors(right.GetColors()[0], right.GetColors()[1], up.GetColors()[0], up.GetColors()[1], up.GetColors()[2], right.GetColors()[5], right.GetColors()[6], right.GetColors()[7]);
        sides[5].SetColors(down.GetColors()[6], left.GetColors()[1], left.GetColors()[2], left.GetColors()[3], left.GetColors()[4], left.GetColors()[5], down.GetColors()[4], down.GetColors()[5]);
    }
    
    void RotateRightDash()
    {
        side up = sides[0];
        side down = sides[1];
        side front = sides[2];
        side back = sides[3];
        side right = sides[4];
        sides[0].SetColors(up.GetColors()[0], up.GetColors()[1], back.GetColors()[6], back.GetColors()[7], back.GetColors()[0], up.GetColors()[5], up.GetColors()[6], up.GetColors()[7]);
        sides[1].SetColors(down.GetColors()[0], down.GetColors()[1], front.GetColors()[2], front.GetColors()[3], front.GetColors()[4], down.GetColors()[5], down.GetColors()[6], down.GetColors()[7]);
        sides[2].SetColors(front.GetColors()[0], front.GetColors()[1], up.GetColors()[2], up.GetColors()[3], up.GetColors()[4], front.GetColors()[5], front.GetColors()[6], front.GetColors()[7]);
        sides[3].SetColors(down.GetColors()[4], back.GetColors()[1], back.GetColors()[2], back.GetColors()[3], back.GetColors()[4], back.GetColors()[5], down.GetColors()[2], down.GetColors()[3]);
        sides[4].SetColors(right.GetColors()[2], right.GetColors()[3], right.GetColors()[4], right.GetColors()[5], right.GetColors()[6], right.GetColors()[7], right.GetColors()[0], right.GetColors()[1]);
    }
    
    void RotateLeftDash()
    {
        side up = sides[0];
        side down = sides[1];
        side front = sides[2];
        side back = sides[3];
        side left = sides[5];
        sides[0].SetColors(front.GetColors()[0], up.GetColors()[1], up.GetColors()[2], up.GetColors()[3], up.GetColors()[4], up.GetColors()[5], front.GetColors()[6], front.GetColors()[7]);
        sides[1].SetColors(back.GetColors()[4], down.GetColors()[1], down.GetColors()[2], down.GetColors()[3], down.GetColors()[4], down.GetColors()[5], back.GetColors()[2], back.GetColors()[3]);
        sides[2].SetColors(down.GetColors()[0], front.GetColors()[1], front.GetColors()[2], front.GetColors()[3], front.GetColors()[4], front.GetColors()[5], down.GetColors()[6], down.GetColors()[7]);
        sides[3].SetColors(back.GetColors()[0], back.GetColors()[1], up.GetColors()[6], up.GetColors()[7], up.GetColors()[0], back.GetColors()[5], back.GetColors()[6], back.GetColors()[7]);
        sides[5].SetColors(left.GetColors()[2], left.GetColors()[3], left.GetColors()[4], left.GetColors()[5], left.GetColors()[6], left.GetColors()[7], left.GetColors()[0], left.GetColors()[1]);
    }
    
};

std::string FindTheWay(cube c)
{
    std::queue<std::pair<cube, std::pair<int, std::string>>> q;
    q.push({c, {100, ""}});
    while (1)
    {
        if (q.front().first.solved())
            return q.front().second.second;
        
        cube tmp;
        
        if (q.front().second.first != 6)
        {
            tmp = q.front().first;
            tmp.RotateUp();
            q.push({tmp, {0, q.front().second.second + "U "}});
        }
        
        if (q.front().second.first != 7)
        {
            tmp = q.front().first;
            tmp.RotateDown();
            q.push({tmp, {1, q.front().second.second + "D "}});
        }
        
        if (q.front().second.first != 8)
        {
            tmp = q.front().first;
            tmp.RotateFront();
            q.push({tmp, {2, q.front().second.second + "F "}});
        }
        
        if (q.front().second.first != 9)
        {
            tmp = q.front().first;
            tmp.RotateBack();
            q.push({tmp, {3, q.front().second.second + "B "}});
        }
        
        if (q.front().second.first != 10)
        {
            tmp = q.front().first;
            tmp.RotateRight();
            q.push({tmp, {4, q.front().second.second + "R "}});
        }
        
        if (q.front().second.first != 11)
        {
            tmp = q.front().first;
            tmp.RotateLeft();
            q.push({tmp, {5, q.front().second.second + "L "}});
        }
        
        if (q.front().second.first != 0 and q.front().second.first != 6)
        {
            tmp = q.front().first;
            tmp.RotateUpDash();
            q.push({tmp, {6, q.front().second.second + "U' "}});
        }
        
        if (q.front().second.first != 1 and q.front().second.first != 7)
        {
            tmp = q.front().first;
            tmp.RotateDownDash();
            q.push({tmp, {7, q.front().second.second + "D' "}});
        }
        
        if (q.front().second.first != 2 and q.front().second.first != 8)
        {
            tmp = q.front().first;
            tmp.RotateFrontDash();
            q.push({tmp, {8, q.front().second.second + "F' "}});
        }
        
        if (q.front().second.first != 3 and q.front().second.first != 9)
        {
            tmp = q.front().first;
            tmp.RotateBackDash();
            q.push({tmp, {9, q.front().second.second + "B' "}});
        }
        
        if (q.front().second.first != 4 and q.front().second.first != 10)
        {
            tmp = q.front().first;
            tmp.RotateRightDash();
            q.push({tmp, {10, q.front().second.second + "R' "}});
        }
        
        if (q.front().second.first != 5 and q.front().second.first != 11)
        {
            tmp = q.front().first;
            tmp.RotateLeftDash();
            q.push({tmp, {11, q.front().second.second + "L' "}});
        }
        
        q.pop();
    }
}

int main()
{
    cube c;
    c.SetColors();
    long start = time(0);
    std::cout << std::endl << "The solution algorithm is: " << FindTheWay(c) << std::endl;
    long end = time(0);
    std::cout << "Needed time: " << end - start  << " seconds" << std::endl;
}
