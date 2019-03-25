class Fantasma{
    int fdir;
    int _x, _y;
    int col;
    public:
        Fantasma(int x , int y , int color); // constructor
        void dibujar_fantasma() const;
        void borrar_fantasma() const;
        bool mover_fantasma();
        bool choque_pacman();

        void setX(int X){
            _x = X;
        }
        int getX(){
            return _x;
        }
        void setdir(int d){
            fdir = d;
        }
        int getdir(){
            return fdir;
        }

        void setY(int Y){
            _y = Y;
        }
        int getY(){
            return _y;
        }

        void setcol(int d){
            col = d;
        }
        int getcol(){
            return col;
        }

};


