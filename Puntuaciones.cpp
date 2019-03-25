class Puntuaciones : public fstream {
  public:
   Puntuaciones() :   fstream("Scores.txt", ios::in | ios::out ) {
                      if(!good()) {
                            ofstream Puntuaciones("Scores.txt", ios::app);
                            int i;
                            for(i = 0; i < 10; i++){
                                Puntuaciones<<"XXXX          0"<<endl;
                            }
                            Puntuaciones.close();
                      }
   }
  ~Puntuaciones() {

  }
   void registrarPuntuacion(string name, int puntuacion);
   void obtenerScores();
};

void Puntuaciones::registrarPuntuacion(string name, int puntuacion){
    char score[' '], caracter, siguiente[' '], trash[' '];
    int i, j = 1, k, scoreInt;
    char scoresOr[9][' '];
    try{
        ifstream comparar("Scores.txt",ios::app);
        if(comparar == NULL){
            throw 0;
        }
        while(comparar.get(caracter)){
            if(!isalpha(caracter)){
                if(!isspace(caracter)){
                    score[0] = caracter;
                    i = 1;
                    while(comparar.get(caracter)){
                        if(isspace(caracter)){
                            break;
                        }
                        score[i++] = caracter;
                    }
                    scoreInt = atoi(score);
                    if(puntuacion > scoreInt){
                        k = 1;
                        ifstream original("Scores.txt",ios::app);
                        original.getline(scoresOr[0],128);
                        original.getline(scoresOr[1],128);
                        original.getline(scoresOr[2],128);
                        original.getline(scoresOr[3],128);
                        original.getline(scoresOr[4],128);
                        original.getline(scoresOr[5],128);
                        original.getline(scoresOr[6],128);
                        original.getline(scoresOr[7],128);
                        original.getline(scoresOr[8],128);
                        original.close();
                        ofstream scores("Scores.txt");
                        while(k < j){
                            scores << scoresOr[k-1] << endl;
                            k++;
                        }
                        scores << name << "          " << puntuacion << endl;
                        while(k < 10){
                            scores << scoresOr[k-1] << endl;
                            k++;
                        }
                        scores.close();
                        comparar.close();
                        break;
                    }
                    j++;
                }
            }
        }
    }
    catch(...){
        cout << "No se ha podido trabajar con el archivo de puntuaciones." << endl;
    }
}

void Puntuaciones::obtenerScores(){
    int i = 0;
    char sc[' '];
    try{
        ifstream scores("scores.txt",ios::app);
        if(scores == NULL){
            throw 0;
        }
        setCColor(color[1]);
        while(!scores.eof()){
            scores.getline(sc,128);
            gotoxy(30,17+2*i);
            i++;
            cout << sc << endl <<endl;
        }
    }
    catch(...){
        cout << "No se ha podido trabajar con el archivo de puntuaciones." << endl;
    }
}
