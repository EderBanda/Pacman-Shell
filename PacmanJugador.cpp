class Pacman{
    private:
        int x;
        int y;
    public:
        void pacman(int x , int y);
        void borrar_pacman(int x, int y);

        void setX(int X){
            x = X;
        }
        int getX(){
            return x;
        }

        void setY(int Y){
            y = Y;
        }
        int getY(){
            return y;
        }
};
