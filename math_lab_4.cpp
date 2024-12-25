#include <iostream>
#include <vector>
#include <string>
#include <time.h>
using namespace std;


vector<string> funcSystem; //система функций
//vector<string> tabl; //таблица истинности в целом
vector<vector<bool>> polnota; //таблица - определение полноты

void pri(vector<string> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }
    cout << endl;
}
void pri(vector<vector<bool>> v)
{
    string a;
    a = to_string(v.size());
    for (int k = 0; k < a.length() - 1; k++)
        cout << " ";
    cout << "    T0  T1  T*  Tm  Tl";
    cout << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << "F" << i + 1;
        for (int k = 0; k < (a.length() - to_string(i+1).length()); k++)
            cout << " ";
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << "   ";
            if (v[i][j] == false)
                cout << "-";
            else
                cout << "+";
        }
        cout << endl;
    }
}
bool isLinear(string f)
{
    if (f.length() == 2)
        return true;

}
/*void tablFill()
{
    for (int a = 0; a < 2; a++)
    {
        for (int b = 0; b < 2; b++)
        {
            for (int c = 0; c < 2; c++)
            {
                string s = "";
                s = s + to_string(a) + to_string(b) + to_string(c);
                tabl.push_back(s);
            }
        }
    }
}*/
void polnPrep(int n)
{
    for (int i = 0; i < n; i++)
    {
        vector<bool> v;
        for (int j = 0; j < 5; j++)
        {
            v.push_back(false);
        }
        polnota.push_back(v);
    }
}
int main()
{
    int choice = 0;
    srand(time(0));
    system("chcp 1251 > null");
    //tablFill();
    int n = 0;
    while (n <= 0)
    {
        cout << "Число функций?" << endl;
        cin >> n;
    }
    polnPrep(n);
    system("cls");
    cout << "1. Случайным образом\n2. Вручную" << endl;
    while (choice != 1 && choice != 2)
    {
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            for (int i = 0; i < n; i++)
            {
                string f = "";
                int amoun = 0;
                int typ = rand() % 3;
                switch (typ)
                {
                case 0: //2
                {
                    amoun = 2;
                    break;
                }
                case 1: //4
                {
                    amoun = 4;
                    break;
                }
                case 2: //8
                {
                    amoun = 8;
                    break;
                }
                }
                for (int i = 0; i < amoun; i++)
                {
                    f += to_string(rand() % 2);
                }
                funcSystem.push_back(f);
            }
            break;
        }
        case 2:
        {
            system("cls");
            for (int i = 0; i < n; i++)
            {
                bool b = false;
                string f = "";
                while (f.length() != 2 && f.length() != 4 && f.length() != 8 || !b)
                {
                    b = true;
                    cout << "Новая фукнция:" << endl;
                    cin >> f;
                    int q = f.length();
                    if (q != 2 && q != 4 && q != 8)
                    {
                        b = false;
                        system("cls");
                        cout << "Неверная длина: должна быть 2, 4 или 8" << endl;
                    }
                    else
                    {
                        for (int j = 0; j < q; j++)
                        {
                            if (f[j] != '1' && f[j] != '0')
                            {
                                b = false;
                                system("cls");
                                cout << "Должны быть нули и единицы" << endl;
                            }
                        }
                    }
                }
                funcSystem.push_back(f);
            }
            break;
        }
        default:
        {
            system("cls");
            cout << "miss" << endl;
            break;
        }
        }
    }
    for (int i = 0; i < n; i++) //проверки для этих функций
    {
        string func = funcSystem[i];
        int l = func.length();
        //T0
        if (func[0] == '0')
            polnota[i][0] = true;
        //T1
        if (func[l - 1] == '1')
            polnota[i][1] = true;
        //T*
        bool star = true;
        for (int j = 0; j < l / 2; j++)
        {
            if (func[j] == func[l - j - 1])
            {
                star = false;
            }
        }
        if (star)
            polnota[i][2] = true;
        //Tm
        vector<bool> monot;
        switch (l)
        {
        case 2:
        {
            monot.push_back(func[0] == '1' && func[1] == '0');
            break;
        }
        case 4:
        {
            monot.push_back(func[0] == '1' && func[1] == '0');
            monot.push_back(func[0] == '1' && func[2] == '0');
            monot.push_back(func[2] == '1' && func[3] == '0');
            monot.push_back(func[1] == '1' && func[3] == '0');
            break;
        }
        case 8:
        {
            monot.push_back(func[0] == '1' && func[4] == '0');
            monot.push_back(func[0] == '1' && func[2] == '0');
            monot.push_back(func[0] == '1' && func[1] == '0');
            monot.push_back(func[4] == '1' && func[5] == '0');
            monot.push_back(func[4] == '1' && func[6] == '0');
            monot.push_back(func[2] == '1' && func[6] == '0');
            monot.push_back(func[2] == '1' && func[3] == '0');
            monot.push_back(func[1] == '1' && func[5] == '0');
            monot.push_back(func[1] == '1' && func[3] == '0');
            monot.push_back(func[3] == '1' && func[7] == '0');
            monot.push_back(func[5] == '1' && func[7] == '0');
            monot.push_back(func[6] == '1' && func[7] == '0');
            break;
        }
        }
        int q = 0;
        for (int j = 0; j < monot.size(); j++)
        {
            if (monot[j] == true)
                q++;
        }
        if (q == 0)
            polnota[i][3] = true;
        //Tl
        vector<char> linear;
        linear.clear();
        switch (l)
        {
        case 2:
        {
            polnota[i][4] = true;
            break;
        }
        case 4:
        {
            int q0 = 0;
            linear.push_back(func[0]);
            //x
            if (func[0] == func[2])
                linear.push_back('0');
            else
                linear.push_back('1');
            //y
            if (func[0] == func[1])
                linear.push_back('0');
            else
                linear.push_back('1');
            //xy
            for (int j = 0; j < 3; j++)
            {
                if (linear[j] == '0')
                    q0++;
            }
            char ltemp;
            if (q0%2 == 0) //то слева будет 1
                ltemp = '1';
            else //иначе 0
                ltemp = '0';
            if (ltemp == func[3])
                linear.push_back('0');
            else
                linear.push_back('1');
            if (linear[3] == '0')
                polnota[i][4] = true;
            break;
        }
        case 8:
        {
            char ltemp;
            int q0 = 0;
            linear.push_back(func[0]);
            //x
            if (func[0] == func[4])
                linear.push_back('0');
            else
                linear.push_back('1');
            //y
            if (func[0] == func[2])
                linear.push_back('0');
            else
                linear.push_back('1');
            //z
            if (func[0] == func[1])
                linear.push_back('0');
            else
                linear.push_back('1');
            //xy
            if (linear[0] == '0')
                q0++;
            if (linear[1] == '0')
                q0++;
            if (linear[2] == '0')
                q0++;
            if (q0%2==0)
                ltemp = '1';
            else
                ltemp = '0';
            if (ltemp == func[6])
                linear.push_back('0');
            else
                linear.push_back('1');
            //xz
            q0 = 0;
            if (linear[0] == '0')
                q0++;
            if (linear[1] == '0')
                q0++;
            if (linear[3] == '0')
                q0++;
            if (q0%2==0)
                ltemp = '1';
            else
                ltemp = '0';
            if (ltemp == func[5])
                linear.push_back('0');
            else
                linear.push_back('1');
            //yz
            q0 = 0;
            if (linear[0] == '0')
                q0++;
            if (linear[2] == '0')
                q0++;
            if (linear[3] == '0')
                q0++;
            if (q0%2 == 0)
                ltemp = '1';
            else
                ltemp = '0';
            if (ltemp == func[3])
                linear.push_back('0');
            else
                linear.push_back('1');
            //xyz
            q0 = 0;
            if (linear[0] == '0')
                q0++;
            if (linear[1] == '0')
                q0++;
            if (linear[2] == '0')
                q0++;
            if (linear[3] == '0')
                q0++;
            if (linear[4] == '0')
                q0++;
            if (linear[5] == '0')
                q0++;
            if (linear[6] == '0')
                q0++;
            if (q0 % 2 == 1)
                ltemp = '0';
            else
                ltemp = '1';
            if (ltemp == func[7])
                linear.push_back('0');
            else
                linear.push_back('1');
            //подсчёт тех, в которых более одной
            q0 = 0;
            polnota[i][4] = true;
            for (int j = 4; j < 8; j++)
            {
                if (linear[j] == '1')
                    polnota[i][4] = false;
            }
            break;
        }
        }
    }
    pri(polnota);
    cout << endl;
    pri(funcSystem);
    bool p = true;
    for (int i = 0; i < 5; i++)
    {
        int q = 0;
        for (int j = 0; j < polnota.size(); j++)
        {
            
            if (polnota[j][i] == true)
                q++;
            if (q == polnota.size())
                p = false;
        }
    }
    if (p)
        cout << "Система является полной" << endl;
    else
        cout << "Система не является полной" << endl;
    return 0;
}