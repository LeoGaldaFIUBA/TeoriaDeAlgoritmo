#ifndef PUNTO_H
#define PUNTO_H

class Punto {
private:
    int x;
    int y;
public:
    Punto();
    virtual ~Punto();
    void setY(int y);
    int getY() const;
    void setX(int x);
    int getX() const;
    bool distinto(Punto otroPunto);

};

#endif /* PUNTO_H */

