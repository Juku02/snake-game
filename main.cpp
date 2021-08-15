#include <iostream>
#include <cstdlib>
#include <time.h>
#include <cstdio>
#include <unistd.h>

int X[10000], Y[10000];
//p - pole puste, w- na polu jest waz, j-na polu jest jedzenie

struct controls
{
    int width, height, speed = 5;
    int up, down, leftd, rightd, key;
    char direction = 'p'; // p-prawo, l-lewo,g-gora,d-dol
};

struct snake
{
    int snakeX, snakeY;
    char snake = 48;
    int lenght = 3;
};

struct food
{
    int foodX, foodY;
    char food = 35;
};

struct matrix
{
    char matrix[35][35];
    char pd = 46, pg = 46, lg = 46, ld = 46, poz = 95, pion = 124;
    int count = 0;
};

void toCorrect(int &x)
{
    std::cout << "Zly wymiar planszy. Wprowadz jeszcze raz" << std::endl;
    std::cin >> x;
    if (x < 5 || x > 35)
        x = 20;
}

void setControls(struct controls *con)
{
    std::cout << "Nacisnij klawisze ktorymi chcesz zagrac" << std::endl;

    std::cout << "GORA" << std::endl;
    con->up = getchar();
    if (con->leftd == 224)
        con->leftd += getchar();
    if (con->leftd == 0)
        con->leftd -= getchar();
    getchar();

    std::cout << "DOL" << std::endl;
    con->down = getchar();
    if (con->leftd == 224)
        con->leftd += getchar();
    if (con->leftd == 0)
        con->leftd -= getchar();
    getchar();

    std::cout << "LEWO" << std::endl;
    con->leftd = getchar();
    if (con->leftd == 224)
        con->leftd += getchar();
    if (con->leftd == 0)
        con->leftd -= getchar();
    getchar();

    std::cout << "PRAWO" << std::endl;
    con->rightd = getchar();
    if (con->rightd == 224)
        con->rightd += getchar();
    if (con->rightd == 0)
        con->rightd -= getchar();
    getchar();
}

void setOptions(struct controls *cont)
{
    std::cout << "Gra Snake" << std::endl;
    //wybor
    std::cout << "Podaj szerokosc planszy od 5 do 35" << std::endl;
    std::cin >> cont->width;
    if (cont->width < 5 || cont->width > 35)
        toCorrect(cont->width);

    std::cout << "Podaj wysokosc planszy od 5 do 35" << std::endl;
    std::cin >> cont->height;
    if (cont->height < 5 || cont->height > 35)
        toCorrect(cont->height);

    std::cout << "Podaj szybkosc od 1 do 10" << std::endl;
    std::cin >> cont->speed;
    if (cont->speed < 1)
        cont->speed = 1;
    if (cont->speed > 10)
        cont->speed = 10;
}

void initBoard(struct controls *co, struct matrix *ma)
{
    //Nadajemy wartoœci p dla wartoœci pole
    for (int i = 0; i < co->height; i++)
    {
        for (int j = 0; j < co->width; j++)
        {
            ma->matrix[j][i] = 'p';
        }
    }
}

void snakePossition(struct snake *s, struct controls *co, struct matrix *ma)
{

    srand(time(NULL));
    //losowanie pola dla weza
    s->snakeX = rand() % co->width;
    s->snakeY = rand() % co->height;

    ma->matrix[s->snakeX][s->snakeY] = 'w';
}

void foodPossition(struct matrix *mat, struct food *f, struct controls *co)
{
    //losowanie pola dla jedzenia
    do
    {
        f->foodX = rand() % co->width;
        f->foodY = rand() % co->height;
        
    } while (mat->matrix[f->foodX][f->foodY] != 'p');

    mat->matrix[f->foodX][f->foodY] = 'j';
}

void initGame(struct controls *control, struct matrix *mat, struct snake *s, struct food *f)
{
    setOptions(control);

    setControls(control);

    initBoard(control, mat);

    snakePossition(s, control, mat);

    foodPossition(mat, f, control);
}

void drawBoard(struct controls *con, struct matrix *mat, struct snake *sk, struct food *fo)
{
    int i, j;
    //up frame
    std::cout << mat->lg;
    for (i = 0; i < con->width; i++)
    {
        std::cout << mat->poz << mat->poz;
    }
    std::cout << mat->pg;
    for (i = 0; i < con->height; i++)
    {
        std::cout << std::endl << mat->pion; //left frame
        for (j = 0; j < con->width; j++)
        {
            if (mat->matrix[j][i] == 'p')
                std::cout << "  ";
            if (mat->matrix[j][i] == 'w')
                std::cout << sk->snake << sk->snake;
            if (mat->matrix[j][i] == 'j')
                std::cout << fo->food << fo->food;
        }
        std::cout << mat->pion; //right frame
    }
    std::cout << std::endl;
    //down frame
    std::cout << mat->ld;
    for (i = 0; i < con->width; i++)
    {
        std::cout << mat->poz << mat->poz;
    }
    std::cout << mat->pd;
}

int main(int argc, char const *argv[])
{
    struct controls con;
    struct matrix ma;
    struct snake sk;
    struct food fo;

    initGame(&con, &ma, &sk, &fo);

    system("clear");
    //rysowanie planszy----------------------------
    drawBoard(&con, &ma, &sk, &fo);

    // for(;;)
    // {

    //     ma.count++;
    //     X[ma.count]=sk.snakeX;
    //     Y[ma.count]=sk.snakeY;

    //    sleep(1/con.speed);             //czekaj
    //     if(getchar())             //jesli zostanie nacisnięty jakis klawisz
    //     {
    //         con.key=getchar();
    //         if(con.key==224) con.key+=getchar();
    //         if(con.key==0) con.key-=getchar();

    //         if(con.key==con.up && (con.direction=='l' || con.direction=='p')) con.direction='g';
    //         if(con.key==con.down && (con.direction=='l' || con.direction=='p')) con.direction='d';
    //         if(con.key==con.leftd && (con.direction=='g' || con.direction=='d')) con.direction='l';
    //         if(con.key==con.rightd && (con.direction=='g' || con.direction=='d')) con.direction='p';

    //     }

    //     //poruszanie wezem
    //     if(con.direction=='d') sk.snakeY++;
    //     if(con.direction=='g') sk.snakeY--;
    //     if(con.direction=='l') sk.snakeX--;
    //     if(con.direction=='p') sk.snakeX++;

    //     //waz przechodzi przez sciany
    //     if(sk.snakeX==con.width) sk.snakeX=0;
    //     if(sk.snakeX==-1) sk.snakeX=con.width-1;
    //     if(sk.snakeY==con.height) sk.snakeY=0;
    //     if(sk.snakeY==-1) sk.snakeY=con.height-1;

        // //co jeśli uderzy w siebie
        // if(matrix[snakeX][snakeY]=='w')
        // {
        //     goToXY(0,height+4);
        //     cout<<endl<<"\aKONIEC GRY. Dlugosc weza wynosi: "<<lenght+1<<" .";
        //     cout<<endl<<"Nacisnij dwa razy dowolny przycisk by zakonczyc.";
        //     break;
        // }

        // //co się dzieje gdy zje
        // if(matrix[snakeX][snakeY]=='j')
        // {
        //     lenght++;
        //     do
        //     {
        //         foodX=rand()%width;
        //         foodY=rand()%height;

        //     }while(matrix[foodX][foodY]!='p');
        //         {
        //             matrix[foodX][foodY]='j';
        //             goToXY(foodX*2+1,foodY+1);
        //             cout<<food<<food;
        //         }
        // }
        // else //kasowanie ogona
        //    {
        //         matrix[historiaWspolzednejX[count-lenght]][historiaWspolzednejY[count-lenght]]='p';
        //         goToXY(historiaWspolzednejX[count-lenght]*2+1,historiaWspolzednejY[count-lenght]+1);
        //         cout<<"  ";
        //    }

        // matrix[snakeX][snakeY]='w';
        // goToXY(snakeX*2+1,snakeY+1);
        // cout<<snake<<snake;

    // } //koniec petli for(;;)

    // getchar();

    return 0;
}