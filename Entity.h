#ifndef ENTITY_H
#define ENTITY_H


class Entity
{
    public:
        Entity();
        virtual void Draw();
        string getName();
    private:
        string name;
};

#endif // ENTITY_H
