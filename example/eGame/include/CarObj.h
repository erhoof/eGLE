//
// Created by erhoof on 17.01.2021.
//

#ifndef EGAME_CAROBJ_H
#define EGAME_CAROBJ_H

namespace eGLE
{
    class Node;
}

namespace eGame
{
    class CarObj {
public:
    CarObj(eGLE::Node *parent);
    ~CarObj();

    void update();
    void input();

    eGLE::Node *m_car_Node;

private:

    eGLE::Node *m_carBottom_Node;
    eGLE::Node *m_carTop_Node;
    eGLE::Node *m_carGlass_Node;
    eGLE::Node *m_carFront_Node;
    eGLE::Node *m_carBack_Node;
    eGLE::Node *m_carRoof_Node;

    // Wheels
    eGLE::Node *m_wheel_FL;
    eGLE::Node *m_wheel_FR;
    eGLE::Node *m_wheel_BL;
    eGLE::Node *m_wheel_BR;
};

}

#endif //EGAME_CAROBJ_H
