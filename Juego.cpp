int dir = 0;
int x = 39, y = 22;
int anteriorpx, anteriorpy;
char tecla;

long int puntos = -5, pts=-5;
int vidas = 3;

void Pacman::pacman(int x , int y){
    setCColor(color[1]);
    gotoxy(x,y);
    if(dir == 2){
        printf("%c",60);
    }
    else if(dir == 3){
        printf("%c",62);
    }
    else if(dir == 0){
        printf("%c",86);
    }
    else {
        printf("%c",94);
    }
}

void Pacman::borrar_pacman(int x, int y){
    gotoxy(x,y); printf(" ");
    if(mapa[y][x] == '_'){
            mapa[y][x] = ' ';
            puntos += 5;
            pts += 5;
            std::thread h(comer);
            h.detach();
    }
}

void teclear(){
    if(kbhit()){
        tecla = getch();
        switch(tecla){
            case ARRIBA:
                dir = 0;
                break;
            case ABAJO:
                dir = 1;
                break;
            case DERECHA:
                dir = 2;
                break;
            case IZQUIERDA:
                dir = 3;
                break;
      }
   }
}

Fantasma::Fantasma(int x , int y, int color){
    _x = x;
    _y = y;
    col = color;
    fdir = rand()%4;
}

void Fantasma::dibujar_fantasma() const{
     setCColor(color[col]);
     gotoxy(_x,_y);
     printf("%c",244);
}

void Fantasma::borrar_fantasma() const{
     gotoxy(_x,_y);
     printf(" ");
}

bool Fantasma::choque_pacman(){
    if(y == _y && x == _x || (fdir == 0 && dir == 1 || fdir == 1 && dir == 0
    ||fdir == 2 && dir == 3 || fdir == 3 && dir == 2 )&&(_y == anteriorpy && _x == anteriorpx)){
        x = 39;
        y = 22;
        dir = 4;
        vidas--;
        return true;
     }
     return false;
}

bool Fantasma::mover_fantasma(){
    borrar_fantasma();
    if(choque_pacman()){
        return true;
    }
    else{
        int bolx = _x, boly = _y;

        if(mapa[_y][_x] == '|'){
            fdir = rand()%4;
        }
        if(mapa[_y][_x] == '*'){
            fdir = 0;
        }
        if(fdir == 2){
            if(mapa[_y][_x+1] != 'X' && mapa[_y][_x+1] != 'A' && mapa[_y][_x+1] != 'Y' &&
            mapa[_y][_x+1] != 'B' && mapa[_y][_x+1] != 'C' && mapa[_y][_x+1] != 'D'){
                _x++;
            }
            else {
                fdir = rand()%4;
            }
        }
        if(fdir == 3){
            if(mapa[_y][_x-1] != 'X' && mapa[_y][_x-1] != 'A' && mapa[_y][_x-1] != 'Y' &&
            mapa[_y][_x-1] != 'B' && mapa[_y][_x-1] != 'C' && mapa[_y][_x-1] != 'D'){
                _x--;
            }
            else{
                fdir = rand()%4;
            }
        }
        if(fdir == 0){
            if(mapa[_y-1][_x] != 'X' && mapa[_y-1][_x] != 'A' && mapa[_y-1][_x] != 'Y' &&
            mapa[_y-1][_x] != 'B' && mapa[_y-1][_x] != 'C' && mapa[_y-1][_x] != 'D'){
                _y--;
            }
            else {
                fdir = rand()%4;
            }
        }
        if(fdir == 1){
            if(mapa[_y+1][_x] != 'X' && mapa[_y+1][_x] != 'A' && mapa[_y+1][_x] != 'Y' &&
            mapa[_y+1][_x] != 'B' && mapa[_y+1][_x] != 'C' && mapa[_y+1][_x] != 'D'){
                _y++;
            }
            else{
                fdir = rand()%4;
            }
        }
        if(mapa[boly][bolx] == '_') {
            setCColor(color[1]);
            gotoxy(bolx,boly);
            printf("%c",250);
        }
        if(_x <= 17){
            _x = 61;
        }
        else if(_x >= 62){
            _x = 18;
        }
        dibujar_fantasma();
        return false;
    }
}


void marcador(int nivel){

   gotoxy(5,4);
   printf("PUNTOS");
   gotoxy(5,6);
   printf("    ");
   setCColor(color[6]);
   gotoxy(5,6);
   printf("%ld",puntos);

   setCColor(color[1]);
   gotoxy(5,8);
   printf("NIVEL");

   gotoxy(5,10);
   printf("    ");

   setCColor(color[6]);
   gotoxy(5,10);
   printf("%d",nivel);

   setCColor(color[1]);
   gotoxy(5,25);
   printf("VIDAS");

   for(int i = 0 ; i <= vidas ; i++){
       gotoxy(5,i+27);
       printf(" ");
   }
   for(int i = 0 ; i < vidas ; i++){
       gotoxy(5,i+27);
       printf("%c",2);
   }
   setCColor(color[2]);
   gotoxy(70,27);
   printf("%c",169);
}

int juego(){
    Pacman pacman;
    int nivel = 0, retornar;
    while(vidas>0){
        nivel++;

        system("cls");
        system("pause");
        construir_mapa();
        system("cls");

        x = 39;
        y = 22;
        Fantasma A(41,14,2);
        Fantasma B(43,14,3);
        Fantasma C(40,14,4);
        Fantasma D(39,14,5);

        std::thread m(start);
        m.detach();

        pintar_mapa();
        pacman.pacman(x,y);

        pts = 0;
        while(vidas > 0 && pts < 1950){
            marcador(nivel);
            pacman.borrar_pacman(x,y);
            anteriorpx = x; anteriorpy = y;

            teclear();

            if(dir == 0 && mapa[y-1][x] != 'X' && mapa[y-1][x] != 'A' && mapa[y-1][x] != 'Y' &&
            mapa[y-1][x] != 'B' && mapa[y-1][x] != 'C' && mapa[y-1][x] != 'D'){
                y--;
            }
            else if(dir == 1 && mapa[y+1][x] != 'X' && mapa[y+1][x] != 'A' && mapa[y+1][x] != 'Y' &&
            mapa[y+1][x] != 'B' && mapa[y+1][x] != 'C' && mapa[y+1][x] != 'D'){
                y++;
            }

            pacman.pacman(x,y);
            Sleep(55);
            pacman.borrar_pacman(x,y);

            if(B.choque_pacman() || C.choque_pacman() || D.choque_pacman() || A.choque_pacman()){
                if(vidas > 0){
                    std::thread muerte(death);
                    muerte.join();
                    Sleep(2500);
                    A.borrar_fantasma();
                    A.setX(41);
                    A.setY(14);
                    A.setcol(2);
                    A.dibujar_fantasma();
                    B.borrar_fantasma();
                    B.setX(43);
                    B.setY(14);
                    B.setcol(3);
                    B.dibujar_fantasma();
                    C.borrar_fantasma();
                    C.setX(40);
                    C.setY(14);
                    C.setcol(4);
                    C.dibujar_fantasma();
                    D.borrar_fantasma();
                    D.setX(39);
                    D.setY(14);
                    D.setcol(5);
                    D.dibujar_fantasma();
                    std::thread m(start);
                    if(m.joinable()){
                        m.join();
                    }
                }
            }

            anteriorpx = x; anteriorpy = y;
            teclear();

            if(dir == 2 && mapa[y][x+1] != 'X' && mapa[y][x+1] != 'A' && mapa[y][x+1] != 'Y' &&
            mapa[y][x+1] != 'B' && mapa[y][x+1] != 'C' && mapa[y][x+1] != 'D'){
                x++;
            }
            else if(dir == 3 && mapa[y][x-1] != 'X' && mapa[y][x-1] != 'A' && mapa[y][x-1] != 'Y' &&
            mapa[y][x-1] != 'B' && mapa[y][x-1] != 'C' && mapa[y][x-1] != 'D'){
                x--;
            }
            if(A.mover_fantasma() || B.mover_fantasma() || C.mover_fantasma() || D.mover_fantasma()){
                if(vidas > 0){
                    std::thread muerte(death);
                    muerte.join();
                    Sleep(2500);
                    A.borrar_fantasma();
                    A.setX(41);
                    A.setY(14);
                    A.setcol(2);
                    A.dibujar_fantasma();
                    B.borrar_fantasma();
                    B.setX(43);
                    B.setY(14);
                    B.setcol(3);
                    B.dibujar_fantasma();
                    C.borrar_fantasma();
                    C.setX(40);
                    C.setY(14);
                    C.setcol(4);
                    C.dibujar_fantasma();
                    D.borrar_fantasma();
                    D.setX(39);
                    D.setY(14);
                    D.setcol(5);
                    D.dibujar_fantasma();
                    std::thread m(start);
                    if(m.joinable()){
                        m.join();
                    }
                }
            }
            pacman.pacman(x,y);
            Sleep(55);

            if(x < 17) {
                pacman.borrar_pacman(x,y);
                x = 61;
            }
            else if(x > 62){
                pacman.borrar_pacman(x,y);
                x = 18;
            }
        }
        for(int i = 0 ; i <= vidas ; i++){
            gotoxy(5, i+27);
            printf(" ");
        }
    }
    std::thread muerte(death);
    muerte.detach();
    retornar = puntos;
    vidas = 3;
    puntos = 0;
    pts = 0;
    system("pause>NULL");
    return retornar;
}
