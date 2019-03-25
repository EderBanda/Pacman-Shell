void comer(){
    mtx.lock();
    PlaySound(TEXT("Waka100.wav"), GetModuleHandle(NULL), SND_FILENAME | SND_ASYNC);
    mtx.unlock();
}

void death(){
    mtx.lock();
    PlaySound(TEXT("muerte.wav"), GetModuleHandle(NULL), SND_FILENAME | SND_ASYNC);
    mtx.unlock();
}

void start(){
    mtx.lock();
    PlaySound(TEXT("Inicio.wav"), NULL, SND_SYNC);
    mtx.unlock();
}

