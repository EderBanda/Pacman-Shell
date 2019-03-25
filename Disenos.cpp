char PAC[9][60]={
    "       PPPPPPPPPP            A             CCCCCCCCCC   ",//56
    "       PPPPPPPPPPP          AAA          CCCCCCCCCCCCCC ",
    "       PPPP   PPPPP        AAAAA        CCCCCCCCCCCCC   ",
    "       PPPP   PPPPP       AAAAAAA       CCCCCCCCCC      ",
    "       PPPPPPPPPPP       AAAAAAAAA      CCCCCCCC        ",
    "       PPPPPP           AAAA   AAAA     CCCCCCCCCC      ",
    "       PPPPPP          AAAAAAAAAAAAA     CCCCCCCCCCCC   ",
    "       PPPPPP         AAAAAAAAAAAAAAA     CCCCCCCCCCCCC ",
    "       PPPPPP        AAAAAAAAAAAAAAAAA      CCCCCCCCC   "
};
char PACM[9][60]={
    "       OOOOOOOOOO            O             OOOOOOOOOO   ",//56
    "       OPPPPPPPPPO          OAO          OOCCCCCCCCCCOO ",
    "       OPPP   PPPPO        OAAAO        OCCCCCCCCCOOO   ",
    "       OPPP   PPPPO       OAAAAAO       OCCCCCCCOO      ",
    "       OPPPPOOOOOO       OAAAAAAAO      OCCCCCCO        ",
    "       OPOPPO           OAAA   AOAO     OCCCCCOCOO      ",
    "       OPOPPO          OAAAAAAAOOOAO     OCCCOOOCCOOO   ",
    "       OPPPPO         OAAAAAAAAAAAAAO     OOCCCCCCCCCOO ",
    "       OOOOOO        OOOOOOOOOOOOOOOOO      OOOOOOOOO   "
};
/*char C[9][17]={
    "    CCCCCCCCCC   ",
    "  CCCCCCCCCCCCCC ",
    " CCCCCCCCCCCCC   ",
    " CCCCCCCCCC      ",
    " CCCCCCCC        ",
    " CCCCCCCCCC      ",
    "  CCCCCCCCCCCC   ",
    "   CCCCCCCCCCCCC ",
    "     CCCCCCCCC   "
};/*
/*char A[9][19]={
    "         A         ",
    "        AAA        ",
    "       AAAAA       ",
    "      AAAAAAA      ",
    "     AAAAAAAAA     ",
    "    AAAA   AAAA    ",
    "   AAAAAAAAAAAAA   ",
    "  AAAAAAAAAAAAAAA  ",
    " AAAAAAAAAAAAAAAAA "
};*/
char MAN[9][60]={
    " MM              MM          A          NN          NNNNNN ",//59
    " MMMM          MMMM         AAA         NNNN        NNNNNN ",
    " MMMMMM      MMMMMM        AAAAA        NNNNNN      NNNNNN ",
    " MMMMMMMM  MMMMMMMM       AAAAAAA       NNNNNNNN    NNNNNN ",
    " MMMMMMMMMMMMMMMMMM      AAAAAAAAA      NNNNNNNNNN  NNNNNN ",
    " MMMMMMMMMMMMMMMMMM     AAAA   AAAA     NNNNNNNNNNNNNNNNNN ",
    " MMMMMMMMMMMMMMMMMM    AAAAAAAAAAAAA    NNNNNNNNNNNNNNNNNN ",
    " MMMMMMMMMMMMMMMMMM   AAAAAAAAAAAAAAA   NNNNNNNNNNNNNNNNNN ",
    " MMMMMMMMMMMMMMMMMM  AAAAAAAAAAAAAAAAA  NNNNNNNNNNNNNNNNNN "
};
char MANM[9][60]={
    " OO              OO          O          OO          OOOOOO ",//59
    " OMOO          OOMO         OAO         ONOO        ONNNNO ",
    " OMMMOO      OOMMMO        OAAAO        ONNNOO      ONNNNO ",
    " OMMMMMOO  OOMMMMMO       OAAAAAO       ONNNNNOO    ONNNNO ",
    " OMMMMMMMOOMMMMMMMO      OAAAAAAAO      ONNNNNNNOO  ONNNNO ",
    " OMMMMMMMMMMMMMMOMO     OAAA   AOAO     ONNNNNNNNNOONNNONO ",
    " OMMMMMMMMMMMMOOOMO    OAAAAAAAOOOAO    ONNNNNNNNNNNNOOONO ",
    " OMMMMMMMMMMMMMMMMO   OAAAAAAAAAAAAAO   ONNNNNNNNNNNNNNNNO ",
    " OOOOOOOOOOOOOOOOOO  OOOOOOOOOOOOOOOOO  OOOOOOOOOOOOOOOOOO "
};
/*char N[9][20]={
    " NN          NNNNNN ",
    " NNNN        NNNNNN ",
}*/

void imprimirPAC(){
    int i,j;
    for(i = 0; i < 9; i++){
        gotoxy(18,8+i);
        for(j = 0; j < 56; j++){
            if(PACM[i][j] == 'P'|| PACM[i][j] == 'A'|| PACM[i][j] == 'C'){
                setCColor(color[1]);
            }
            else if(PACM[i][j] == 'O'){
                setCColor(color[0]);
            }
            cout << PAC[i][j];
            Sleep(3);
        }
    }
}

void imprimirMAN(){
    int i,j;
    for(i = 0; i < 9; i++){
        gotoxy(18,20+i);
        for(j = 0; j < 59; j++){
            if(MANM[i][j] == 'M'|| MANM[i][j] == 'A'|| MANM[i][j] == 'N')
                setCColor(color[1]);
            if(MANM[i][j] =='O')
                setCColor(color[0]);
            cout << MAN[i][j];
            Sleep(3);
        }
    }
}

int imprimirMenu(){
    int opc, fx = 40, fy = 37;
    imprimirPAC();
    imprimirMAN();
    setCColor(color[6]);
    gotoxy(37,38);
    cout<<"PRESS ANY KEY TO START";
    getch();
    thread hilo(comer);
    hilo.detach();
    Sleep(100);
    gotoxy(37,38);
    cout<<"                      ";
    gotoxy(45,37);
    cout<<"JUGAR";
    gotoxy(44,38);
    cout<<"RECORDS";
    gotoxy(45,39);
    cout<<"SALIR";
    do{
        gotoxy(fx,fy);
        cout<<"---";
        Sleep(100);
        gotoxy(fx,fy);
        cout<<"-->";
        opc = getch();
        thread hilo(comer);
        hilo.detach();
        gotoxy(fx,fy);
        cout<<"   ";
        switch(opc){
            case ARRIBA:
                if(fy == 37)
                    fy = 39;
                else
                    fy--;
                break;
            case ABAJO:
                if(fy == 39)
                    fy = 37;
                else
                    fy++;
        }
    }while(opc != ENTER);
    switch(fy){
        case 37:
            return 1;
        case 38:
            return 2;
        case 39:
            return 3;
    }
}

string obtenerNombre(){
    bool ban = false;
    char c1, c2, c3, c4, enter;
    string nombre = "\0";
    gotoxy(22,30);
    cout << "Ingrese su nombre :" << endl;
    gotoxy(15,32);
    cout << "Ingrese cada letra y confirmela con ENTER" << endl;
    do{
        ban = true;
        gotoxy(30,31);
        cout << "[ ] [ ] [ ] [ ]" << endl;
        gotoxy(31,31);
        c1 = getch();
        if(isalpha(c1)){
            gotoxy(30,31);
            cout << "[" << c1 << "] [ ] [ ] [ ]" << endl;
            gotoxy(31,31);
            enter = getch();
            if(enter = ENTER){
                ban = false;
            }
        }
    }while(ban);
    do{
        ban = true;
        gotoxy(30,31);
        cout << "[" << c1 << "] [ ] [ ] [ ]" << endl;
        gotoxy(35,31);
        c2 = getch();
        if(isalpha(c2)){
            gotoxy(30,31);
            cout << "[" << c1 << "] [" << c2 << "] [ ] [ ]" << endl;
            gotoxy(35,31);
            enter = getch();
            if(enter = ENTER){
                ban = false;
            }
        }
    }while(ban);
     do{
        ban = true;
        gotoxy(30,31);
        cout << "[" << c1 << "] [" << c2 << "] [ ] [ ]" << endl;
        gotoxy(39,31);
        c3 = getch();
        if(isalpha(c2)){
            gotoxy(30,31);
            cout << "[" << c1 << "] [" << c2 << "] [" << c3 << "] [ ]" << endl;
            gotoxy(39,31);
            enter = getch();
            if(enter = ENTER){
                ban = false;
            }
        }
    }while(ban);
    do{
        ban = true;
        gotoxy(30,31);
        cout << "[" << c1 << "] [" << c2 << "] [" << c3 << "] [ ]" << endl;
        gotoxy(43,31);
        c4 = getch();
        if(isalpha(c2)){
            gotoxy(30,31);
            cout << "[" << c1 << "] [" << c2 << "] [" << c3 << "] [" << c4 << "]" << endl;
            gotoxy(43,31);
            enter = getch();
            if(enter = ENTER){
                ban = false;
            }
        }
    }while(ban);
    nombre += c1;
    nombre += c2;
    nombre += c3;
    nombre += c4;
    cout << endl << endl;
    system("pause");
    return nombre;
}
char high[6][75] = {
    "               HHHH   HHHH  IIII     GGGGGGGGGGGG     HHHH   HHHH",
    "               HHHH   HHHH  IIII   GGGGGG             HHHH   HHHH",
    "               HHHHHHHHHHH  IIII   GGGGG              HHHHHHHHHHH",
    "               HHHHHHHHHHH  IIII   GGGGG   GGGGGGGGG  HHHHHHHHHHH",
    "               HHHH   HHHH  IIII   GGGGGG    GGGGG    HHHH   HHHH",
    "               HHHH   HHHH  IIII     GGGGGGGGGGGG     HHHH   HHHH"
};

char scores[6][80]={
"     SSSSSSS        CCCCCC     OOOOOO    RRRRRRRR   EEEEEEEE     SSSSSSS ",
"   SSSS           CCCCCCCCC  OOOOOO  OO  RRR  RRRR  EEE        SSSS      ",
"     SSSS        CCCCCCCC    OOOOO   OO  RRR  RRRR  EEEEEEEE     SSSS    ",
"       SSSS      CCCCC       OOO     OO  RRRRRRR    EEEEEEEE       SSSS  ",
"         SSSS    CCCCCCCC    OOOOO   OO  RRR  RRR   EEE              SSSS",
"    SSSSSSSSS      CCCCCCCC    OOOOOO    RRR   RRR  EEEEEEEE    SSSSSSSSS"
};
void disenoScores(){
    int i, j;
    cout << endl << endl;
    setCColor(color[2]);
    for(i = 0; i < 6; i++){
        for(j = 0; j < 65; j++){
            cout << high[i][j];
        }
        cout << endl;
    }
    cout << endl;
    setCColor(color[2]);
    for(i = 0; i < 6; i++){
        for(j = 0; j < 76; j++){
            cout << scores[i][j];
        }
        cout << endl;
    }

    setCColor(color[0]);
    gotoxy(1,1);printf("%c",201);
    for(i=2;i<77;i++){
        gotoxy(i,1);printf("%c",205);
    }
    gotoxy(77,1);printf("%c",187);
    for(i=2;i<40;i++){
        gotoxy(77,i);printf("%c",186);
    }
    gotoxy(77,40);printf("%c",188);
    for(i=76;i>1;i--){
        gotoxy(i,40);printf("%c",205);
    }
    gotoxy(1,40);printf("%c",200);
    for(i=39;i>1;i--){
        gotoxy(1,i);printf("%c",186);
    }

}
